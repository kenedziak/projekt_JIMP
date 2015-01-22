#include "points.h"
#include <stdlib.h>

static int
realloc_pts_failed (points_t * pts, int size)
{
 pts->y=realloc(pts->y, size * sizeof *pts->y);
 pts->x=realloc (pts->x, size * sizeof *pts->x);
 if(pts->x != NULL && pts->y !=NULL){
    return 0;
}
else return 1;
}
int
read_pts_failed (FILE * inf, points_t * pts)
{ 
  int size;
  double x, y;
  if (pts->n == 0) {
    pts->x = malloc (100 * sizeof *pts->x);
    if (pts->x == NULL)
      return 1;
    pts->y = malloc (100 * sizeof *pts->y);
    if (pts->y == NULL) {
      free (pts->x);
      return 1;
    }
    size = 100;
  }
  else
    size = pts->n;

  while (fscanf (inf, "%lf %lf", &x, &y) == 2) {
    pts->x[pts->n] = x;
    pts->y[pts->n] = y;
    pts->n++;
    if (!feof (inf) && pts->n == size) {
      if (realloc_pts_failed (pts, 2 * size))
        return 1;
      else{
        size *= 2;
      }
    }
  }
  
    if (pts->n != size){ 
      
      size=pts->n;
      if(realloc_pts_failed(pts, size))
      return 1;
    }
   
  return 0;
}

void free_points(points_t * pts){
    free(pts->x);
    free(pts->y);
    
}