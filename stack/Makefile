TARGET: exe

stack.o: stack.c
	gcc -c -I . stack.c -o stack.o

application.o: application.c
	gcc -c -I . application.c -o application.o

libstack.a: stack.o
	ar rs libstack.a stack.o

exe: application.o libstack.a
	gcc application.o -o exe -L . libstack.a

clean:
	rm stack.o
	rm application.o
	rm libstack.a
	rm exe