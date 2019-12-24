#include "Tests.h"

int main() {
    srand(time(NULL));
    
    Position endEffectorPos;
    // endEffectorPos = (Position*) malloc (sizeof(Position));
    float r1, r2, angle1, angle2, invAngle1, invAngle2;

    //r1 = r2 = angle1 = angle2 = (float*) malloc (sizeof(float));

    /*configure(&r1, &r2, &angle1, &angle2);
    forwardKin(&r1, &r2, &angle1, &angle2, &endEffectorPos);
    printPosition(&endEffectorPos);
    printf("\n\n");
    inverseKin(&endEffectorPos, &r1, &r2, &invAngle1, &invAngle2);
    float invAngleDeg1 = radToDeg(invAngle1);
    float invAngleDeg2 = radToDeg(invAngle2);
    printf("Angle position of joint 1 (degres) = %f \n", invAngleDeg1);
    printf("Angle position of joint 2 (degres) = %f \n", invAngleDeg2);*/

    testAccuracy(&r1, &r2, &angle1, &angle2, &endEffectorPos, &invAngle1, &invAngle2);
}