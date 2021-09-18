#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define _USE_MATH_DEFINES
#include <math.h>

Vector *Vector_Create(void) {
  Vector *vec = (Vector *) malloc(sizeof(Vector));
  if (!vec) {
    fprintf(stderr, "Failed to allocate memory");
  }
  return vec;
}

Vector *Vector_CreateXY(double x, double y) {
  Vector *vec = (Vector *) malloc(sizeof(Vector));
  if (!vec) {
    fprintf(stderr, "Failed to allocate memory");
  }
  vec->x = x;
  vec->y = y;
  return vec;
}

Vector *Vector_CreateRT(double r, double theta) {
  Vector *vec = (Vector *) malloc(sizeof(Vector));
  if (!vec)
    fprintf(stderr, "Failed to allocate memory");
  vec->x = r * cos(theta);
  vec->y = r * sin(theta);
  return vec;
}

Vector *Vector_ZERO(void) {
  Vector *vec = (Vector *) malloc(sizeof(Vector));
  if (!vec) {
    fprintf(stderr, "Failed to allocate memory");
  }
  vec->x = 0;
  vec->y = 0;
  return vec;
}

Vector *Vector_UNIT(void) {
  Vector *vec = (Vector *) malloc(sizeof(Vector));
  if (!vec) {
    fprintf(stderr, "Failed to allocate memory");
  }
  double theta = (2 *  M_PI *  rand()) / RAND_MAX;
  vec->x = cos(theta);
  vec->y = sin(theta);
  return vec;
}

void Vector_Destroy(Vector *vec) {
  free(vec);
}

void Vector_Add(Vector *result, Vector *a, Vector *b) {
  result->x = a->x + b->x;
  result->y = a->y + b->y;
}

void Vector_AddD(Vector *result, double ax, double ay, double bx, double  by) {
  result->x = ax + bx;
  result->y = ay + by;
}

void Vector_Sub(Vector *result, Vector *a, Vector *b) {
  result->x = a->x - b->x;
  result->y = a->y - b->y;
}

void Vector_SubD(Vector *result, double ax, double ay, double bx, double  by) {
  result->x = ax - bx;
  result->y = ay - by;
}

void Vector_Mult(Vector *result, Vector *vec, double factor) {
  result->x = vec->x * factor;
  result->y = vec->y * factor;
}


void Vector_Div(Vector *result, Vector *vec, double factor) {
  result->x = vec->x / factor;
  result->y = vec->y / factor;
}


void Vector_Negate(Vector *result, Vector *vec) {
  result->x = - vec->x;
  result->y = - vec->y;
}

double Vector_Mag(Vector *vec) {
  return  hypot(vec->x, vec->y);
}

double Vector_SqMag(Vector *vec) {
  return vec->x*vec->x + vec->y*vec->y;
}

void Vector_Normal(Vector *result, Vector *vec) {
  double mag =  hypot(vec->x, vec->y);
  result->x = vec->x / mag;
  result->y = vec->y / mag;
}

void Vector_SetMag(Vector *result, Vector *vec, double mag) {
  double pMag =  hypot(vec->x, vec->y);
  result->x = vec->x * mag / pMag;
  result->y = vec->y * mag / pMag;
}

double Vector_Dir(Vector *vec) {
  return  atan2(vec->y, vec->x);
}

double Vector_Dot(Vector *a, Vector *b) {
  return a->x * b->x + a->y * b->y;
}

double Vector_Cross(Vector *a, Vector *b) {
  return a->x * b->y - a->y * b->x;
}

double Vector_Dist(Vector *a, Vector *b) {
  return  hypot(a->x - b->x, a->y - b->y);
}

double Vector_SqDist(Vector *a, Vector *b) {
  double x = a->x - b->x;
  double y = a->y - b->y;
  return x*x + y*y;
}

double Vector_AngleTo(Vector *from, Vector *to) {
  double crossProduct = from->x * to->y - from->y * to->x;
  double dotProduct = from->x * to->x + from->y * to->y;
  return  atan2(crossProduct, dotProduct);
}

double Vector_AngleToD(double fromX, double fromY, double toX, double toY) {
  double crossProduct = fromX * toY - fromY * toX;
  double dotProduct = fromX * toX + fromY * toY;
  return  atan2(crossProduct, dotProduct);
}

void Vector_Copy(Vector *result, Vector *vec) {
  result->x = vec->x;
  result->y = vec->y;
}

void Vector_Ortho(Vector *result, Vector *vec) {
  double x = vec->y;
  double y = -vec->x;
  result->x = x;
  result->y = y;
}


void Vector_Truncate(Vector *result, Vector *vec, double limit) {
  result->x = vec->x;
  result->y = vec->y;
  if (result->x*result->x + result->y*result->y > limit * limit) {
    double factor = limit/ hypot(vec->x, vec->y);
    result->x *= factor;
    result->y *= factor;
  }
}

void Vector_Rotate(Vector *result, Vector *vec, double angle) {
  double cs =  cos(angle);
  double sn =  sin(angle);
  double x = vec->x*cs - vec->y*sn;
  double y = vec->x*sn + vec->y*cs;
  result->x = x;
  result->y = y;
}

void Vector_Lerp(Vector *result, Vector *vec, Vector *target, double strength) {
  if (strength < 0) strength = 0;
  else if (strength > 1) strength = 1;
  result->x = vec->x + (target->x - vec->x) * strength;
  result->y = vec->y + (target->y - vec->y) * strength;
}

double Vector_ProjectionV(Vector *vec, Vector *line) {
  return (vec->x*line->x+vec->y*line->y) /  hypot(line->x, line->y);
}

double Vector_ProjectionA(Vector *vec, double angle) {
  return  hypot(vec->x, vec->y) *  cos(angle);
}

double Vector_PerpProjection(Vector *vec, Vector *line) {
  return  fabs(vec->x * line->y - vec->y * line->x) /  hypot(line->x, line->y);
}

void Vector_ComponentV(Vector *result, Vector *vec, Vector *line) {
  double mag = (vec->x*line->x+vec->y*line->y) /  hypot(line->x, line->y);
  result->x = mag * line->x;
  result->y = mag * line->y;
}

void Vector_ComponentA(Vector *result, Vector *vec, double angle) {
  double r =  hypot(vec->x, vec->y) *  cos(angle);
  double theta =  atan2(vec->y, vec->x) + angle;
  result->x = r *  cos(theta);
  result->y = r *  sin(theta);
}

void Vector_PerpComponent(Vector *result, Vector *vec, Vector *line) {
  double mag = (vec->x*line->x+vec->y*line->y) /  hypot(line->x, line->y);
  result->x = vec->x - mag * line->x;
  result->y = vec->y - mag * line->y;
}

bool Vector_Equal(Vector *a, Vector *b) {
  return a->x == b->x && a->y == b->y;
}

double Vector_Compare(Vector *a, Vector *b) {
  return  hypot(a->x, a->y) -  hypot(b->x, b->y);
}

double Vector_SqCompare(Vector *a, Vector *b) {
  return a->x*a->x + a->y*a->y - b->x*b->x - b->y*b->y;
}

void Vector_Bound(Vector *result, Vector *vec, Vector *bound) {
  if (vec->x < bound->x || vec->x > bound->x) result->x = bound->x;
  else result->x = vec->x;
  if (vec->y < bound->y || vec->y > bound->y) result->y = bound->y;
  else result->y = vec->y;
}


void Vector_BoundD(Vector *result, Vector *vec, double boundX, double boundY) {
  if (vec->x < boundX || vec->x > boundX) result->x = boundX;
  else result->x = vec->x;
  if (vec->y < boundY || vec->y > boundY) result->y = boundY;
  else result->y = vec->y;
}

