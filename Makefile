FLAGS := -Wall -Wextra -Wpedantic -g

run:
	gcc src/*.c $(FLAGS) -o out.exe
	./out.exe

clean:
	rm -r *.exe