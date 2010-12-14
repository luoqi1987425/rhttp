main:main.o mod_register.o
	gcc -o main main.o mod_register.o

main.o:main.c     
	gcc -c main.c
	
mod_register.o:core/mod_register/core.c
	gcc -c -o mod_register.o core/mod_register/core.c
	
clean:
	rm main main.o mod_register.o