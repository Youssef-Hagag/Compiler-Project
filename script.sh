bison -d parser.y
flex lexer.l    
g++ -Wno-register -o mylang parser.tab.c lex.yy.c value.cpp symbol.cpp
./mylang.exe test.mel
read -p "Press any key to continue..."
