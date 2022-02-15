main: main.c
	gcc -Wall -Werror -L -o main main.c
clean:
	rm main
run:
	./main