g++ -Iinclude -c src\main.cpp
g++ main.o -o main -Llib -lsfml-graphics -lsfml-window -lsfml-system
del main.o
move main.exe bin\windows
cd bin\windows
main
cd ..\..
