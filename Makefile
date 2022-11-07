CC:=gcc -Wall -pthread
obj:=pi eval a.out

pi: thread.o main.c
	$(CC) -g thread.o main.c -o pi -lm -fsanitize=thread
	./pi

test:
	valgrind --leak-check=full --show-leak-kinds=all -s ./pi 

sanitizer: thread.o main.c
	$(CC) -g thread.o main.c -o pi -lm -fsanitize=thread 
	./pi

eval:
	$(CC) eval.c -o eval -lm

clean:
	rm -f *.o $(obj)
