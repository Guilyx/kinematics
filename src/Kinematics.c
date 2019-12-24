#include "Kinematics.h"

void configure(float* r1, float* r2, float *angle1, float *angle2) {
    printf("\nEnter size of link 1 : ");
    scanf("%f", r1);
    printf("\nEnter size of link 2 : ");
    scanf("%f", r2);

    printf("\nEnter angular position of joint 1 : ");
    scanf("%f", angle1);
    printf("\nEnter angular position of joint 2 : ");
    scanf("%f", angle2);
}

void printPosition(Position* pos) {
    printf("Pos X = %f \n", pos->posX);
    printf("Pos Y = %f \n", pos->posY);
}

void forwardKin(float* r1, float* r2, float* angle1, float* angle2, Position* endEffector) {
    endEffector->posX = (*r1) * cos(*angle1) + (*r2) * cos(*angle1 + *angle2);
    endEffector->posY = (*r1) * sin(*angle1) + (*r2) * sin(*angle1 + *angle2);
}

void inverseKin(Position* pos, float* r1, float* r2, float* invAngle1, float* invAngle2) {
    float dist = distance(pos);
    *invAngle1 = atan2(pos->posY, pos->posX); // Angle between X-axis and imaginary line
    *invAngle2 = acos((pow(*r1, 2) - pow(*r2, 2) + pow(dist, 2))/(2*(*r1)*dist));

    //*invAngle1 = tempAngle1 + tempAngle2;
    //*invAngle2 = acos((pow(*r1, 2) + pow(*r2, 2) - pow(distance, 2))/(2*(*r1)*(*r2)));
}