#ifndef COMP_VECTOR_2_F
#define COMP_VECTOR_2_F

typedef struct {
  float x;
  float y;
} Vector;

Vector *Vector_Create();
Vector *Vector_CreateXY(float x, float y);
Vector *Vector_CreateRT(float r, float theta);
Vector *Vector_ZERO();
Vector *Vector_UNIT();

void Vector_Destroy(Vector *vec);

Vector *Vector_Add(Vector *result, Vector *a, Vector *b);
Vector *Vector_AddF(Vector *result, float ax, float ay, float bx, float by);
Vector *Vector_Sub(Vector *result, Vector *a, Vector *b);
Vector *Vector_SubF(Vector *result, float ax, float ay, float bx, float by);
Vector *Vector_Mult(Vector *result, Vector *a, float factor);
Vector *Vector_Div(Vector *result, Vector *vec, float factor);
Vector *Vector_Negate(Vector *result, Vector *vec);

float Vector_Mag(Vector *vec);
float Vector_SqMag(Vector *vec);
Vector *Vector_Normal(Vector *result, Vector *vec);
Vector *Vector_SetMag(Vector *result, Vector *vec, float mag);
float Vector_Dir(Vector *vec);

float Vector_Dot(Vector *a, Vector *b);
float Vector_Cross(Vector *a, Vector *b);

float Vector_Dist(Vector *a, Vector *b);
float Vector_SqDist(Vector *a, Vector *b);
float Vector_AngleTo(Vector *from, Vector *to);
float Vector_AngleToF(float fromX, float fromY, float toX, float toY);

Vector *Vector_Copy(Vector *result, Vector *vec);
Vector *Vector_Ortho(Vector *result, Vector *vec);

Vector *Vector_Truncate(Vector *result, Vector *vec, float limit);
Vector *Vector_Rotate(Vector *result, Vector *vec, float angle);
Vector *Vector_Lerp(Vector *result, Vector *vec, Vector *target, float strength);

float Vector_ProjectionV(Vector *vec, Vector *line);
float Vector_ProjectionA(Vector *vec, float angle);
float Vector_PerpProjection(Vector *vec, Vector *line);

Vector *Vector_ComponentV(Vector *result, Vector *vec, Vector *line);
Vector *Vector_ComponentA(Vector *result, Vector *vec, float angle);
Vector *Vector_PerpComponent(Vector *result, Vector *vec, Vector *line);

int Vector_Equal(Vector *a, Vector *b);
float Vector_Compare(Vector *a, Vector *b);
float Vector_SqCompare(Vector *a, Vector *b);

Vector *Vector_Bound(Vector *result, Vector *vec, Vector *bound);
Vector *Vector_BoundF(Vector *result, Vector *vec, float boundX, float boundY);

#endif

