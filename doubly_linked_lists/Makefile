TARGET: staticexe

dll/dll.o: dll/dll.c
	gcc -c -I dll dll/dll.c -o dll/dll.o

dll/dll_util.o: dll/dll_util.c
	gcc -c -I dll dll/dll_util.c -o dll/dll_util.o

dll/libdll.a: dll/dll.o dll/dll_util.o
	ar rs dll/libdll.a dll/dll.o dll/dll_util.o

application.o: application.c
	gcc -c -I dll application.c -o application.o

staticexe: application.o dll/libdll.a
	gcc application.o -o staticexe -L dll dll/libdll.a

clean:
	rm dll/dll.o
	rm dll/dll_util.o
	rm dll/libdll.a
	rm application.o
	rm staticexe

