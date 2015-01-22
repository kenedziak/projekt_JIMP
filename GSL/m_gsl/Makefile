libmgsl: matrix.o gsl_esolver.o
	ar rvs libmgsl.a $^
	-rm *.o 
matrix.o: matrix.c matrix.h
	$(CC) -c matrix.c 
gsl_esolver.o: gsl_esolver.c gsl_esolver.h matrix.h
	$(CC) -c gsl_esolver.c -lgsl -lgslcblas -lm 
.PHONY: clean

clean:
	-rm *.o libmgsl.a
 
