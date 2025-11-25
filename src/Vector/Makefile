main:
	gcc main.c -o out -Wall -Werror -Wpedantic
	./out

pre:
	gcc -E main.c -o out.i

clean:
	rm *.i 
	rm out
	rm out.c
