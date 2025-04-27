import os
import subprocess
import sys
import tkinter as tk
from tkinter import filedialog, scrolledtext, ttk
from tkinter import font as tkfont
import re
from pathlib import Path
import threading
import sys, ctypes
if sys.platform.startswith("win"):
    ctypes.windll.shcore.SetProcessDpiAwareness(1)

class GlowingButton(tk.Canvas):
    def __init__(self, parent, text, command=None, width=120, height=40,
                 bg_color="#1E1E1E", glow_color="#4f78cc", **kwargs):
        super().__init__(parent, width=width, height=height,
                         bg=bg_color, highlightthickness=0, **kwargs)
        self.bg_color   = bg_color
        self.glow_color = glow_color
        self.command    = command
        self.width      = width
        self.height     = height

        def hex2rgb(h): return tuple(int(h[i:i+2],16) for i in (1,3,5))
        self._bg_rgb   = hex2rgb(self.bg_color)
        self._glow_rgb = hex2rgb(self.glow_color)

        self.create_rectangle(0, 0, width-1, height-1,
                              fill=self.bg_color,
                              outline=self.glow_color,
                              width=2, tags="button")
        self.create_text(width//2, height//2,
                         text=text, fill="white",
                         font=("Arial", 12, "bold"),
                         tags="text")

        self.bind("<Enter>", self.on_enter)
        self.bind("<Leave>", self.on_leave)
        self.bind("<Button-1>", self.on_click)

        self.glow_active    = True
        self.glow_value     = 0.2
        self.glow_direction = 1
        self.animate_glow()

    def animate_glow(self):
        if not self.glow_active: 
            return

        self.glow_value += 0.05 * self.glow_direction
        if   self.glow_value >= 1.0: self.glow_direction = -1
        elif self.glow_value <= 0.2: self.glow_direction =  1

        r0,g0,b0 = self._bg_rgb
        r1,g1,b1 = self._glow_rgb
        r = int(r0 + (r1-r0)*self.glow_value)
        g = int(g0 + (g1-g0)*self.glow_value)
        b = int(b0 + (b1-b0)*self.glow_value)
        glow_hex = f"#{r:02x}{g:02x}{b:02x}"

        self.itemconfig("button", outline=glow_hex)

        self.after(50, self.animate_glow)

    def on_enter(self, event):
        self.itemconfig("button", fill="#2A2A2A")

    def on_leave(self, event):
        self.itemconfig("button", fill=self.bg_color)

    def on_click(self, event):
        if self.command:
            self.command()


class MelCodeRunnerApp:
    def __init__(self, root):
        self.root = root
        self.root.title("MEL Code Runner")
        self.root.configure(bg="#1E1E1E")
        self.root.geometry("1200x800")
        
        self.bg_color = "#1E1E1E"
        self.text_bg = "#252526"
        self.button_bg = "#333333"
        self.highlight_color = "#4f78cc"
        self.text_color = "#D4D4D4"
        
        self.code_font = tkfont.Font(family="Consolas", size=14)
        self.tabs_font = tkfont.Font(family="Consolas", size=10)
        
        self.create_main_layout()
        
        self.current_file = None
        self.output_dir = os.path.join(os.getcwd(), "output")
        os.makedirs(self.output_dir, exist_ok=True)
        
        # Syntax highlighting for MEL files
        self.keyword_patterns = [
            r'\b(if|else|while|for|switch|return|break|continue|do)\b',
        ]
        self.datatype_patterns = [
            r'\b(int|float|char|string|bool|void)\b',
        ]

        self.symbol_table = "" #

        self.status_var = tk.StringVar()
        self.status_var.set("Ready")
        self.status_label = tk.Label(self.root, textvariable=self.status_var, 
                                     bg=self.bg_color, fg=self.text_color, anchor="w")
        self.status_label.pack(fill=tk.X, padx=10, pady=5)
    
    def create_main_layout(self):
        top_frame = tk.Frame(self.root, bg=self.bg_color)
        top_frame.pack(fill=tk.X, padx=10, pady=10)
        
        self.upload_button = GlowingButton(top_frame, "Upload Code", command=self.upload_file, 
                                          width=150, height=40, bg_color=self.bg_color, glow_color="#4f78cc")
        self.upload_button.pack(side=tk.LEFT, padx=10)
        
        self.run_button = GlowingButton(top_frame, "Run Code", command=self.run_code, 
                                       width=150, height=40, bg_color=self.bg_color, glow_color="#78cc4f")
        self.run_button.pack(side=tk.LEFT, padx=10)
        
        self.file_path_var = tk.StringVar()
        self.file_path_var.set("No file selected")
        file_path_label = tk.Label(top_frame, textvariable=self.file_path_var, 
                                   bg=self.bg_color, fg=self.text_color, anchor="w")
        file_path_label.pack(side=tk.LEFT, padx=10, fill=tk.X, expand=True)
        
        self.main_paned = ttk.PanedWindow(self.root, orient=tk.HORIZONTAL)
        self.main_paned.pack(fill=tk.BOTH, expand=True, padx=10, pady=(0, 10))
        
        code_frame = tk.Frame(self.main_paned, bg=self.bg_color)
        self.main_paned.add(code_frame, weight=1)
        
        code_header = tk.Label(code_frame, text="Code Editor", bg=self.bg_color, fg=self.text_color, font=("Arial", 12, "bold"))
        code_header.pack(fill=tk.X, padx=5, pady=5)
        
        self.code_text = scrolledtext.ScrolledText(code_frame, wrap=tk.NONE, bg=self.text_bg, fg=self.text_color, 
                                                  insertbackground=self.text_color, font=self.code_font)
        self.code_text.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        

        # self.output_paned = ttk.PanedWindow(self.main_paned, orient=tk.VERTICAL)
        # self.main_paned.add(self.output_paned, weight=1)
        
        # quads_frame = tk.Frame(self.output_paned, bg=self.bg_color)
        # self.output_paned.add(quads_frame, weight=1)

        notebook = ttk.Notebook(self.main_paned)
        notebook.pack(fill=tk.BOTH, expand=True)
        self.main_paned.add(notebook, weight=1)
        
        # 1) Quads tab
        quads_frame = tk.Frame(notebook, bg=self.bg_color)
        notebook.add(quads_frame, text="Quads")

        quads_header_frame = tk.Frame(quads_frame, bg=self.bg_color)
        quads_header_frame.pack(fill=tk.X)
        
        quads_header = tk.Label(quads_header_frame, text="Quads Output", bg=self.bg_color, fg=self.text_color, font=("Arial", 12, "bold"))
        quads_header.pack(side=tk.LEFT, padx=5, pady=5)

        
        self.quads_text = scrolledtext.ScrolledText(quads_frame, wrap=tk.NONE, bg=self.text_bg, fg=self.text_color, font=self.tabs_font)
        self.quads_text.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # 2) Errors tab
        errors_frame = tk.Frame(notebook, bg=self.bg_color)
        notebook.add(errors_frame, text="Errors")
        errors_header = tk.Label(errors_frame, text="Errors",
                                 bg=self.bg_color, fg=self.text_color,
                                 font=("Arial",12,"bold"))
        errors_header.pack(fill=tk.X, padx=5, pady=5)
        self.errors_text = scrolledtext.ScrolledText(
            errors_frame, wrap=tk.NONE,
            bg=self.text_bg, fg=self.text_color,
            font=self.tabs_font)
        self.errors_text.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)

        # 3) Symbol Table tab
        symbols_frame = tk.Frame(notebook, bg=self.bg_color)
        notebook.add(symbols_frame, text="Symbols")
        symbols_header = tk.Label(symbols_frame, text="Symbol Table",
                                  bg=self.bg_color, fg=self.text_color,
                                  font=("Arial",12,"bold"))
        symbols_header.pack(fill=tk.X, padx=5, pady=5)
        self.symbols_text = scrolledtext.ScrolledText(
            symbols_frame, wrap=tk.NONE,
            bg=self.text_bg, fg=self.text_color,
            font=self.tabs_font)
        self.symbols_text.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)




        # errors_frame = tk.Frame(self.output_paned, bg=self.bg_color)
        # self.output_paned.add(errors_frame, weight=1)
        
        # errors_header = tk.Label(errors_frame, text="Errors", bg=self.bg_color, fg=self.text_color, font=("Arial", 12, "bold"))
        # errors_header.pack(fill=tk.X, padx=5, pady=5)
        
        # self.errors_text = scrolledtext.ScrolledText(errors_frame, wrap=tk.NONE, bg=self.text_bg, fg=self.text_color, font=self.code_font)
        # self.errors_text.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        self.root.update()
        self.main_paned.sashpos(0, self.root.winfo_width() // 2)
        #self.output_paned.sashpos(0, self.root.winfo_height() // 2)

        font_size_var = tk.IntVar(value=self.code_font.cget("size"))
        spin = tk.Spinbox(
            top_frame,
            from_=6, to=40,
            width=4,
            textvariable=font_size_var,
            command=lambda: self._adjust_font(int(font_size_var.get()) - self.code_font.cget("size")),
            bg=self.button_bg, fg=self.text_color,
            highlightthickness=0,
            relief="flat"
        )
        spin.pack(side=tk.LEFT, padx=(5, 0))

    def _adjust_font(self, step):
        new_size = max(6, self.code_font.cget("size") + step)
        self.code_font.configure(size=new_size)
        self.tabs_font.configure(size=new_size - 4)
        self.highlight_syntax()
    
    def upload_file(self):
        file_path = filedialog.askopenfilename(
            filetypes=[("MEL Files", "*.mel"), ("All Files", "*.*")]
        )
        if file_path:
            self.current_file = file_path
            self.file_path_var.set(f"File: {os.path.basename(file_path)}")
            self.load_file_content(file_path)
    
    def load_file_content(self, file_path):
        try:
            with open(file_path, 'r') as file:
                content = file.read()
                
            self.code_text.delete(1.0, tk.END)
            self.code_text.insert(tk.END, content)
            
            self.highlight_syntax()
            
            self.status_var.set(f"Loaded file: {os.path.basename(file_path)}")
            
            self.quads_text.delete(1.0, tk.END)
            self.errors_text.delete(1.0, tk.END)
            
        except Exception as e:
            self.status_var.set(f"Error loading file: {str(e)}")
    
    def highlight_syntax(self):
        for tag in self.code_text.tag_names():
            if tag.startswith("keyword"):
                self.code_text.tag_delete(tag)
        
        self.code_text.tag_configure("keyword", foreground="#569CD6")
        self.code_text.tag_configure("function", foreground="#DCDCAA")
        self.code_text.tag_configure("string", foreground="#CE9178")
        self.code_text.tag_configure("comment", foreground="#6A9955")
        
        content = self.code_text.get(1.0, tk.END)
        
        # Highlight keywords
        for i, pattern in enumerate(self.keyword_patterns):
            tag_name = f"keyword{i}"
            self.code_text.tag_configure(tag_name, foreground="#a53fd1", font=(self.code_font.cget("family"), self.code_font.cget("size"), "bold"))
            
            matches = re.finditer(pattern, content)
            for match in matches:
                start_pos = f"1.0+{match.start()}c"
                end_pos = f"1.0+{match.end()}c"
                self.code_text.tag_add(tag_name, start_pos, end_pos)
                
        # Highlight data types
        for i, pattern in enumerate(self.datatype_patterns):
            tag_name = f"datatype{i}"
            self.code_text.tag_configure(tag_name, foreground="#3251c9", font=(self.code_font.cget("family"), self.code_font.cget("size"), "bold"))
            
            matches = re.finditer(pattern, content)
            for match in matches:
                start_pos = f"1.0+{match.start()}c"
                end_pos = f"1.0+{match.end()}c"
                self.code_text.tag_add(tag_name, start_pos, end_pos)
        
        string_pattern = r'"[^"]*"'
        char_pattern = r"'[^']'"
        string_or_char_pattern = f"({string_pattern}|{char_pattern})"
        matches = re.finditer(string_or_char_pattern, content)
        for match in matches:
            start_pos = f"1.0+{match.start()}c"
            end_pos = f"1.0+{match.end()}c"
            self.code_text.tag_add("string", start_pos, end_pos)
        
        comment_pattern = r'//.*$'
        matches = re.finditer(comment_pattern, content, re.MULTILINE)
        for match in matches:
            start_pos = f"1.0+{match.start()}c"
            end_pos = f"1.0+{match.end()}c"
            self.code_text.tag_add("comment", start_pos, end_pos)
    
    def run_code(self):
        
        temp_file = os.path.join(self.output_dir, "temp.mel")
        with open(temp_file, 'w') as file:
            file.write(self.code_text.get(1.0, tk.END))
        
        self.status_var.set("Running code...")
        
        threading.Thread(target=self.execute_code, args=(temp_file,), daemon=True).start()
    
    def execute_code(self, temp_file):
        try:
            os.makedirs(self.output_dir, exist_ok=True)

            quad_path  = os.path.join(self.output_dir, "quad.txt")
            error_path = os.path.join(self.output_dir, "errors.txt")
            symbol_path = os.path.join(self.output_dir, "symbol_table.txt")
            compiler   = os.path.abspath(os.path.join("..", "mylang.exe"))


            cmd = [compiler, temp_file, "-q", quad_path, "-e", error_path]

            proc = subprocess.run(cmd,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE,
                                text=True)

            if not os.path.exists(quad_path):
                with open(quad_path, "w") as qf:
                    qf.write(proc.stdout)
            if not os.path.exists(error_path):
                with open(error_path, "w") as ef:
                    ef.write(proc.stderr)

            if not os.path.exists(symbol_path):
                with open(symbol_path, "w") as ef:
                    ef.write(proc.stderr)

            status_msg = f"Finished (exit {proc.returncode})"
            if proc.returncode != 0:
                status_msg += "  see Errors pane"

            self.load_output_files(quad_path, error_path, symbol_path)
            self.root.after(0, lambda: self.status_var.set(status_msg))

        except Exception as e:
            self.root.after(0, lambda e=e: self.status_var.set(f"Error running code: {str(e)}"))


    
    def generate_sample_output(self, quads_file, errors_file, symbol_path):
        try:
            if os.path.exists(quads_file):
                with open(quads_file, 'r') as f:
                    quads_content = f.read()
            else:
                quads_content = "Quads file not found."

            if os.path.exists(errors_file):
                with open(errors_file, 'r') as f:
                    errors_content = f.read()
            else:
                errors_content = "Errors file not found."
            
            if os.path.exists(symbol_path):
                with open(symbol_path) as f:
                    symb_content = f.read()
            else:
                symb_content = "Symbol table not found."

            self.load_output_files(quads_file, errors_file, symbol_path)

        except Exception as e:
            self.status_var.set(f"Error loading output files: {str(e)}")
    
    def load_output_files(self, quads_file, errors_file, symbol_path):
        try:
            with open(quads_file, 'r') as f:
                quads_content = f.read()
            
            with open(errors_file, 'r') as f:
                errors_content = f.read()
                
            with open(symbol_path, 'r') as f:
                symb_content = f.read()

            self.root.after(0, lambda: self.update_output_text(quads_content, errors_content, symb_content))
            
        except Exception as e:
            self.root.after(0, lambda: self.status_var.set(f"Error loading output files: {str(e)}"))
    
    def update_output_text(self, quads_content, errors_content, symbol_path):
        """Update the output text areas"""
        self.quads_text.delete(1.0, tk.END)
        self.quads_text.insert(tk.END, quads_content)
        
        self.errors_text.delete(1.0, tk.END)
        self.errors_text.insert(tk.END, errors_content)

        self.symbols_text .delete(1.0, tk.END)
        self.symbols_text .insert(tk.END, symbol_path)

        # Highlight error lines
        self.highlight_error_lines(errors_content)
    
    def highlight_error_lines(self, errors_content):
        """Highlight source lines mentioned in Errors pane."""

        for tag in ("error_line", "warning_line"):
            self.code_text.tag_remove(tag, "1.0", tk.END)

        self.code_text.tag_configure("error_line",   background="#5A1E1E")  # red-ish
        self.code_text.tag_configure("warning_line", background="#5A4E1E")  # amber

        # 2.  regex heeeheeeeeeeee
        patt = re.compile(r"\[\s*line\s+(\d+)\s*]?\s*(error|warning)?",
                        flags=re.IGNORECASE)

        first_hit = None
        for m in patt.finditer(errors_content):
            line_no  = int(m.group(1))
            sev      = (m.group(2) or "").lower()      # "error", "warning"
            tag_name = "warning_line" if sev == "warning" else "error_line"

            start = f"{line_no}.0"
            end   = f"{line_no}.end"
            try:
                self.code_text.tag_add(tag_name, start, end)
                if first_hit is None:
                    first_hit = start        
            except tk.TclError:
                # compiler reported a line beyond EOF - just ignore man
                pass

        if first_hit:
            self.code_text.see(first_hit)
    
    def getReady(self):
        # highlight syntax with each keystroke
        app.code_text.bind("<KeyRelease>", lambda e: app.highlight_syntax())
        app.code_text.focus_set()
        # when the user adds '{' we add a '}' on the same line after it and make the cursor between them
        def auto_close_brace(event):
            if event.char == "{":
                line = app.code_text.get("insert linestart", "insert lineend")
                if not line.strip().endswith("}"):
                    app.code_text.insert(tk.INSERT, "}")
                    app.code_text.mark_set(tk.INSERT, f"{tk.INSERT} - 1 chars")
                    app.code_text.see(tk.INSERT)
                    return "break"
            if event.char == "(":
                line = app.code_text.get("insert linestart", "insert lineend")
                if not line.strip().endswith(")"):
                    app.code_text.insert(tk.INSERT, ")")
                    app.code_text.mark_set(tk.INSERT, f"{tk.INSERT} - 1 chars")
                    app.code_text.see(tk.INSERT)
                    return "break"
            return None
        app.code_text.bind("<KeyRelease>", auto_close_brace, add="+")

if __name__ == "__main__":
    root = tk.Tk()
    root.tk.call('tk', 'scaling', 1.5)
    style = ttk.Style()
    style.theme_use('default')
    style.configure('TPanedwindow', background='#1E1E1E')
    style.configure('Sash', background='#333333', sashthickness=4)
    
    
    app = MelCodeRunnerApp(root)
    app.getReady()
    root.mainloop()