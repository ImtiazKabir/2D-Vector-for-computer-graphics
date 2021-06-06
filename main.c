#include <stdio.h>
#include "vector.h"

#define _USE_MATH_DEFINES
#include <math.h>


int main() {

  Vector *a = Vector_CreateXY(3, 2);

  Vector_Rotate(a, a, 3.1415/2);
  printf("%f %f\n", a->x, a->y);

  Vector_Destroy(a);

  return 0;
}


