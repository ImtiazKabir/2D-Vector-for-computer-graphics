#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

Vector *Vector_Create() {
  Vector *vec = (Vector *) malloc(sizeof(Vector));
  if (!vec)
    fprintf(stderr, "Failed to allocate memory");
  return vec;
}

Vector *Vector_CreateXY(float x, float y) {
  Vector *vec = (Vector *) malloc(sizeof(Vector));
  if (!vec)
    fprintf(stderr, "Failed to allocate memory");
  vec->x = x;
  vec->y = y;
  return vec;
}

Vector *Vector_CreateRT(float r, float theta) {
  Vector *vec = (Vector *) malloc(sizeof(Vector));
  if (!vec)
    fprintf(stderr, "Failed to allocate memory");
  vec->x = r * (float) cos(theta);
  vec->y = r * (float) sin(theta);
  return vec;
}

Vector *Vector_ZERO() {
  Vector *vec = (Vector *) malloc(sizeof(Vector));
  if (!vec)
    fprintf(stderr, "Failed to allocate memory");
  vec->x = 0;
  vec->y = 0;
  return vec;
}

Vector *Vector_UNIT() {
  Vector *vec = (Vector *) malloc(sizeof(Vector));
  if (!vec)
    fprintf(stderr, "Failed to allocate memory");
  float theta = (2 * (float) M_PI * (float) rand()) / RAND_MAX;
  vec->x = (float) cos(theta);
  vec->y = (float) sin(theta);
  return vec;
}

void Vector_Destroy(Vector *vec) {
  free(vec);
}

Vector *Vector_Add(Vector *result, Vector *a, Vector *b) {
  result->x = a->x + b->x;
  result->y = a->y + b->y;
  return result;
}

Vector *Vector_AddF(Vector *result, float ax, float ay, float bx, float  by) {
  result->x = ax + bx;
  result->y = ay + by;
  return result;
}

Vector *Vector_Sub(Vector *result, Vector *a, Vector *b) {
  result->x = a->x - b->x;
  result->y = a->y - b->y;
  return result;
}

Vector *Vector_SubF(Vector *result, float ax, float ay, float bx, float  by) {
  result->x = ax - bx;
  result->y = ay - by;
  return result;
}

Vector *Vector_Mult(Vector *result, Vector *vec, float factor) {
  result->x = vec->x * factor;
  result->y = vec->y * factor;
  return result;
}


Vector *Vector_Div(Vector *result, Vector *vec, float factor) {
  result->x = vec->x / factor;
  result->y = vec->y / factor;
  return result;
}


Vector *Vector_Negate(Vector *result, Vector *vec) {
  result->x = - vec->x;
  result->y = - vec->y;
  return result;
}

float Vector_Mag(Vector *vec) {
  return (float) hypot(vec->x, vec->y);
}

float Vector_SqMag(Vector *vec) {
  return vec->x*vec->x + vec->y*vec->y;
}

Vector *Vector_Normal(Vector *result, Vector *vec) {
  float mag = (float) hypot(vec->x, vec->y);
  result->x = vec->x / mag;
  result->y = vec->y / mag;
  return result;
}

Vector *Vector_SetMag(Vector *result, Vector *vec, float mag) {
  float pMag = (float) hypot(vec->x, vec->y);
  result->x = vec->x * mag / pMag;
  result->y = vec->y * mag / pMag;
  return result;
}

float Vector_Dir(Vector *vec) {
  return (float) atan2(vec->y, vec->x);
}

float Vector_Dot(Vector *a, Vector *b) {
  return a->x * b->x + a->y * b->y;
}

float Vector_Cross(Vector *a, Vector *b) {
  return a->x * b->y - a->y * b->x;
}

float Vector_Dist(Vector *a, Vector *b) {
  return (float) hypot(a->x - b->x, a->y - b->y);
}

float Vector_SqDist(Vector *a, Vector *b) {
  float x = a->x - b->x;
  float y = a->y - b->y;
  return x*x + y*y;
}

float Vector_AngleTo(Vector *from, Vector *to) {
  float crossProduct = from->x * to->y - from->y * to->x;
  float dotProduct = from->x * to->x + from->y * to->y;
  return (float) atan2(crossProduct, dotProduct);
}

float Vector_AngleToF(float fromX, float fromY, float toX, float toY) {
  float crossProduct = fromX * toY - fromY * toX;
  float dotProduct = fromX * toX + fromY * toY;
  return (float) atan2(crossProduct, dotProduct);
}

Vector *Vector_Copy(Vector *result, Vector *vec) {
  result->x = vec->x;
  result->y = vec->y;
  return result;
}

Vector *Vector_Ortho(Vector *result, Vector *vec) {
  float x = vec->y;
  float y = -vec->x;
  result->x = x;
  result->y = y;
  return result;
}


Vector *Vector_Truncate(Vector *result, Vector *vec, float limit) {
  result->x = vec->x;
  result->y = vec->y;
  if (result->x*result->x + result->y*result->y > limit * limit) {
    float factor = limit/(float) hypot(vec->x, vec->y);
    result->x *= factor;
    result->y *= factor;
  }
  return result;
}

Vector *Vector_Rotate(Vector *result, Vector *vec, float angle) {
  float cs = (float) cos(angle);
  float sn = (float) sin(angle);
  float x = vec->x*cs - vec->y*sn;
  float y = vec->x*sn + vec->y*cs;
  result->x = x;
  result->y = y;
  return result;
}

Vector *Vector_Lerp(Vector *result, Vector *vec, Vector *target, float strength) {
  if (strength < 0) strength = 0;
  else if (strength > 1) strength = 1;
  result->x = vec->x + (target->x - vec->x) * strength;
  result->y = vec->y + (target->y - vec->y) * strength;
  return result;
}

float Vector_ProjectionV(Vector *vec, Vector *line) {
  return (vec->x*line->x+vec->y*line->y) / (float) hypot(line->x, line->y);
}

float Vector_ProjectionA(Vector *vec, float angle) {
  return (float) hypot(vec->x, vec->y) * (float) cos(angle);
}

float Vector_PerpProjection(Vector *vec, Vector *line) {
  return (float) fabs(vec->x * line->y - vec->y * line->x) / (float) hypot(line->x, line->y);
}

Vector *Vector_ComponentV(Vector *result, Vector *vec, Vector *line) {
  float mag = (vec->x*line->x+vec->y*line->y) / (float) hypot(line->x, line->y);
  result->x = mag * line->x;
  result->y = mag * line->y;
  return result;
}

Vector *Vector_ComponentA(Vector *result, Vector *vec, float angle) {
  float r = (float) hypot(vec->x, vec->y) * (float) cos(angle);
  float theta = (float) atan2(vec->y, vec->x) + angle;
  result->x = r * (float) cos(theta);
  result->y = r * (float) sin(theta);
  return result;
}

Vector *Vector_PerpComponent(Vector *result, Vector *vec, Vector *line) {
  float mag = (vec->x*line->x+vec->y*line->y) / (float) hypot(line->x, line->y);
  result->x = vec->x - mag * line->x;
  result->y = vec->y - mag * line->y;
  return result;
}

int Vector_Equal(Vector *a, Vector *b) {
  return a->x == b->x && a->y == b->y;
}

float Vector_Compare(Vector *a, Vector *b) {
  return (float) hypot(a->x, a->y) - (float) hypot(b->x, b->y);
}

float Vector_SqCompare(Vector *a, Vector *b) {
  return a->x*a->x + a->y*a->y - b->x*b->x - b->y*b->y;
}

Vector *Vector_Bound(Vector *result, Vector *vec, Vector *bound) {
  if (vec->x < bound->x || vec->x > bound->x) result->x = bound->x;
  else result->x = vec->x;
  if (vec->y < bound->y || vec->y > bound->y) result->y = bound->y;
  else result->y = vec->y;
  return result;
}


Vector *Vector_BoundF(Vector *result, Vector *vec, float boundX, float boundY) {
  if (vec->x < boundX || vec->x > boundX) result->x = boundX;
  else result->x = vec->x;
  if (vec->y < boundY || vec->y > boundY) result->y = boundY;
  else result->y = vec->y;
  return result;
}

