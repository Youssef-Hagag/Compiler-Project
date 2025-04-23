bison -d parser.y
flex lexer.l    
g++ -Wno-register -o mylang parser.tab.c lex.yy.c value.cpp symbol.cpp
./mylang.exe
read -p "Press any key to continue..."
echo "Build completed! Run ./mylang to start."
