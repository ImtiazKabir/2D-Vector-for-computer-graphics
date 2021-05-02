#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"


int main() {

  Vector *a = Vector_CreateXY(3, 2);
  Vector *b = Vector_CreateXY(-1, 1);
  Vector_Sub(a, Vector_Add(a, a, b), b);
  printf("%f %f\n", a->x, a->y);

  Vector_Destroy(a);
  Vector_Destroy(b);

  return 0;
}


