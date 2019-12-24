#include "Util.h"

float lawofCosines(float a, float b, float c) {
    float C = acos((pow(a, 2) + pow(b, 2) + pow(c, 2))/(2*a*b));
    return C;
}

float radToDeg(float rad) {
    return(rad*180/M_PI);
}

float distance(Position* pos) {
    return(sqrt(pow(pos->posX, 2) + pow(pos->posY, 2)));
}