#ifndef POINTS_H
#define POINTS_H

#include <stdio.h>

typedef struct {
		int n;
		double *x;
		double *y;
} points_t;

int read_pts_failed ( FILE* inf, points_t *pts);
void free_points(points_t * pts);

#endif
