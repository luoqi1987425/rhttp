main:main.o mod_bootstrap.o mod_register.o mod_bootstrap_listen.o
	gcc -o main main.o mod_register.o mod_bootstrap.o mod_bootstrap_listen.o

main.o:main.c     
	gcc -c main.c

mod_bootstrap.o:core/mod_bootstrap/core.c
	gcc -c -o mod_bootstrap.o core/mod_bootstrap/core.c

mod_bootstrap_listen.o:core/mod_bootstrap/listen.c
	gcc -c -o mod_bootstrap_listen.o core/mod_bootstrap/listen.c
	
mod_register.o:core/mod_register/core.c
	gcc -c -o mod_register.o core/mod_register/core.c
	
clean:
	rm main main.o mod_register.o mod_bootstrap.o mod_bootstrap_listen.o
