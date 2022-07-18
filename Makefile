all: compile run

compile: test.c
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=3 get_next_line.c -o test

run: test
	echo "-----------------"
	./test
	echo "-----------------"

clean:
	rm -f test