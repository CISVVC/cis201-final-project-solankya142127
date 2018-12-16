#
all: main


main : main.cpp
	@g++ -std=c++11 -o main *.cpp 

run : main
	@echo "Running the program:"
	@./main

edit:
	@vim main.cpp

debug:
	@gdb ./main

clean :
	@rm main
