aprox_gsl.out: main.o splines.o points.o matrix.o aproksymator_na_bazie_gsl.o m_gsl/libmgsl.a 
	$(CC) -Wall aproksymator_na_bazie_gsl.o main.o matrix.o splines.o points.o  -o aprox_gsl.out  -L ./m_gsl/ -lmgsl -lgsl -lgslcblas -lm
	-rm *.o
main.o: main.c
	$(CC) -c main.c
splines.o: splines.c
	$(CC) -c splines.c
points.o: points.c
	$(CC) -c points.c
matrix.o: m_gsl/matrix.c
	$(CC) -c m_gsl/matrix.c
aproksymator_na_bazie_gsl.o: aproksymator_na_bazie.c
	$(CC) -c aproksymator_na_bazie.c -o aproksymator_na_bazie_gsl.o 	
intrp_gsl.out: main.o splines.o points.o interpolator.o matrix.o m_gsl/libmgsl.a
	$(CC) -o intrp  main.o splines.o points.o interpolator.o matrix.o  -lgsl -lgslcblas -lm -o interp_gsl -L ./m_gsl/ -lmgsl -lmgsl -lgsl -lgslcblas -lm
prosta: main.o splines.o points.o prosta.o
	$(CC) -o prosta  main.o splines.o points.o prosta.o     


interpolator.o: makespl.h points.h m_gsl/gsl_esover.h
	$(CC) -c interpolator.c

	
.PHONY: clean

clean:
	-rm *.o aprox_gsl.out interp_gsl.out prosta

	
