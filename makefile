all: compile

compile:
	gcc -o date date.c
	gcc -o mkdir manual_mkdir.c
	gcc -o rm manual_remove.c
	gcc -o cat manual_cat.c
	gcc -o ls manual_ls.c

	gcc -o myshell manual_shell.c

remove:
	rm -f date mkdir rm cat ls myshell
