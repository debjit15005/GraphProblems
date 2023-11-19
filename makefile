# make run FILE=<filename.txt> to run template
CFLAGS = -g -Wall -Wextra
CPPFLAGS = -g
LDFLAGS = -g
FILE?=testcase_1.txt
compile: template.c
	gcc template.c -o m

run: clean compile
	./m $(FILE)
debug_compile: template.c 
	gcc -g -o m template.c
	
debug: clean debug_compile
	gdb ./m $(FILE)
clean: 
	rm -f m