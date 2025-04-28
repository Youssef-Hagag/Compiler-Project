bison -d parser.y
flex lexer.l    
g++ -Wno-register -o mellow parser.tab.c lex.yy.c value.cpp symbol.cpp quadruples.cpp
./mellow.exe input.mel
read -p "Press any key to continue..."
