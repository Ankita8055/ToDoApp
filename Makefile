#all: hello

#hello: main.o task.o todolist.o
#	g++ main.o task.o todolist.o -o hello
	
	
#task.o: task.cpp
#	g++ -c task.cpp
	
#todolist.o: todolist.cpp
#	g++ -c todolist.cpp
	
#main.o: main.cpp
#	g++ -c main.cpp
	
#clean:
#	rm -rf *o hello

$(CC) = gcc
final:
	$(CC) main.cpp task.cpp todolist.cpp -o final
clean:
	rm *.o final
