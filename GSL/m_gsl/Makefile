libmgsl: matrix.o gsl_esover.o
	ar rvs libmgsl.a $^
	-rm *.o 
matrix.o: matrix.c matrix.h
	$(CC) -c matrix.c 
gsl_esover.o: gsl_esover.c gsl_esover.h matrix.h
	$(CC) -c gsl_esover.c -lgsl -lgslcblas -lm 
.PHONY: clean

clean:
	-rm *.o libmgsl.a
 
