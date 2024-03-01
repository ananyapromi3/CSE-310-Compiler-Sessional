yacc -d -o y.tab.cpp 2005079.y
echo 'Generated the parser Cpp file as well the header file'
g++ -w -c -o y.o y.tab.cpp
echo 'Generated the parser object file'
flex -o lex.yy.cpp 2005079.l
echo 'Generated the scanner Cpp file'
g++ -w -c -o l.o lex.yy.cpp
echo 'Generated the scanner object file'
g++ y.o l.o -o test.exe
echo 'All ready, running'
./test.exe input.c