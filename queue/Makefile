TARGET: exe

stack.o: queue.c
	gcc -c -I . queue.c -o queue.o

application.o: application.c
	gcc -c -I . application.c -o application.o

libqueue.a: queue.o
	ar rs libqueue.a queue.o

exe: application.o libqueue.a
	gcc application.o -o exe -L . libqueue.a

clean:
	rm queue.o
	rm application.o
	rm libqueue.a
	rm exe