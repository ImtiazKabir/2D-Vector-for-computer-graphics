#ifndef COMP_VECTOR_2_F
#define COMP_VECTOR_2_F

#include <stdbool.h>

typedef struct {
  double x;
  double y;
} Vector;

Vector *Vector_Create(void);
Vector *Vector_CreateXY(double x, double y);
Vector *Vector_CreateRT(double r, double theta);
Vector *Vector_ZERO(void);
Vector *Vector_UNIT(void);

void Vector_Destroy(Vector *vec);

void Vector_Add(Vector *result, Vector *a, Vector *b);
void Vector_AddD(Vector *result, double ax, double ay, double bx, double by);
void Vector_Sub(Vector *result, Vector *a, Vector *b);
void Vector_SubD(Vector *result, double ax, double ay, double bx, double by);
void Vector_Mult(Vector *result, Vector *a, double factor);
void Vector_Div(Vector *result, Vector *vec, double factor);
void Vector_Negate(Vector *result, Vector *vec);

double Vector_Mag(Vector *vec);
double Vector_SqMag(Vector *vec);
void Vector_Normal(Vector *result, Vector *vec);
void Vector_SetMag(Vector *result, Vector *vec, double mag);
double Vector_Dir(Vector *vec);

double Vector_Dot(Vector *a, Vector *b);
double Vector_Cross(Vector *a, Vector *b);

double Vector_Dist(Vector *a, Vector *b);
double Vector_SqDist(Vector *a, Vector *b);
double Vector_AngleTo(Vector *from, Vector *to);
double Vector_AngleToD(double fromX, double fromY, double toX, double toY);

void Vector_Copy(Vector *result, Vector *vec);
void Vector_Ortho(Vector *result, Vector *vec);

void Vector_Truncate(Vector *result, Vector *vec, double limit);
void Vector_Rotate(Vector *result, Vector *vec, double angle);
void Vector_Lerp(Vector *result, Vector *vec, Vector *target, double strength);

double Vector_ProjectionV(Vector *vec, Vector *line);
double Vector_ProjectionA(Vector *vec, double angle);
double Vector_PerpProjection(Vector *vec, Vector *line);

void Vector_ComponentV(Vector *result, Vector *vec, Vector *line);
void Vector_ComponentA(Vector *result, Vector *vec, double angle);
void Vector_PerpComponent(Vector *result, Vector *vec, Vector *line);

bool Vector_Equal(Vector *a, Vector *b);
double Vector_Compare(Vector *a, Vector *b);
double Vector_SqCompare(Vector *a, Vector *b);

void Vector_Bound(Vector *result, Vector *vec, Vector *bound);
void Vector_BoundD(Vector *result,Vector *vec, double boundX, double boundY);

#endif /* COMP_VECTOR_2_F */
