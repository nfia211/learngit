main:main.cpp createOJinput.o Execute.o Judge.o
	g++ main.cpp createOJinput.o Execute.o Judge.o -o main

createOJinput.o:createOJinput.cpp
	gcc -c createOJinput.cpp

 Execute.o: Execute.cpp
	gcc -c  Execute.cpp

Judge.o:Judge.cpp
	gcc -c Judge.cpp

clean:
	rm *.o main