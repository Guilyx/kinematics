#ifndef UTIL_H
#define UTIL_H

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct {
     float posX, posY;
} Position;

float lawofCosines(float a, float b, float c);
float radToDeg(float rad);
float distance(Position* pos);

#endif /* UTIL_H */