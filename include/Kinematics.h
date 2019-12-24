#ifndef KINEMATIC_H
#define KINEMATIC_H

#include "Util.h"


void printPosition(Position* pos);
void configure(float* r1, float* r2, float* angle1, float* angle2);
void inverseKin(Position *pos, float* r1, float* r2, float* invAngle1, float* invAngle2);
void forwardKin(float* r1, float* r2, float* angle1, float* angle2, Position* endEffector);


#endif /* KINEMATIC_H */