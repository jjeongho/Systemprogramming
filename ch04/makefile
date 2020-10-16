main.o : main.c ./lib/libtest.a 
	gcc -rdynamic main.c -o run -ldl
add.o : add.c 
	gcc -c ./lib/add.o 
subtract.o : subtract.c 
	gcc -c ./lib/subtract.o 
multiply.o : multiply.c 
	gcc -c ./lib/multiply.o 
divide.o : divide.c 
	gcc -c ./lib/divide.o

