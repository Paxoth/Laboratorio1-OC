all: logaritmo

logaritmo:  
	gcc -pg -O0 -std=c99 iteracion0.c -o logaritmo0

clean:
	rm -rf *o logaritmo0

run:	
	./logaritmo0 -n 10 -i 10000000

time:
	gprof ./logaritmo0 gmon.out
