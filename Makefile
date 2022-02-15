main: main.c
	gcc -L -Wall -Werror -o main main.c
clean:
	rm main
run:
	./main