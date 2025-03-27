all:
	g++ main.cpp program.cpp taskList.cpp task.cpp -o main
	./main
testTask:
	g++ testTask.cpp task.cpp -o main
	./main
testList:
	g++ testList.cpp taskList.cpp task.cpp -o main
	./main