TARGET: exe

tree.o: binary_tree.c
	gcc -g -c -I . binary_tree.c -o tree.o

libtree.a: tree.o
	ar rs libtree.a tree.o

main.o: main.c
	gcc -g -c -I . main.c -o main.o

exe: libtree.a main.o
	gcc main.o -o exe -L . libtree.a

clean:
	rm tree.o
	rm main.o
	rm libtree.a
	rm exe
