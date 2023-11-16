FILE?=testcase_1.txt
compile: template.c
	gcc template.c -o m

run: compile
	./m $(FILE)
clean: 
	rm -f m