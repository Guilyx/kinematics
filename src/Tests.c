#include "Tests.h"

void testAccuracy(float *r1, float *r2, float *angle1, float *angle2, Position *posEnd, float *invAngle1, float *invAngle2) {
    float accuracyAngle1 = 0, accuracyAngle2 = 0;
    int angle1Valid = 0, angle2Valid = 0;

    int nbTest;
    printf("How many tests do you want to run ?");
    scanf("%d", &nbTest);

    for (float i = 0 ; i < nbTest ; i++) {
        
        *r1 = (float)rand()/(float)(RAND_MAX/100);
        *r2 = (float)rand()/(float)(RAND_MAX/100);
        *angle1 = ((float)rand()/(float)(RAND_MAX/(4*M_PI))) - (2*M_PI);
        *angle2 = ((float)rand()/(float)(RAND_MAX/(4*M_PI))) - (2*M_PI);
        forwardKin(r1, r2, angle1, angle2, posEnd);
        float Angle1toDeg = radToDeg(*angle1);
        float Angle2toDeg = radToDeg(*angle2);
        inverseKin(posEnd, r1, r2, invAngle1, invAngle2);
        float invAngle1toDeg = radToDeg(*invAngle1);
        float invAngle2toDeg = radToDeg(*invAngle2);

        printf("\n Angular position of joint 1 in degres = %f \n", radToDeg(*angle1));
        printf("Angle position of joint 1 (degres) = %f \n", invAngle1toDeg);
        printf("\n Angular position of joint 2 in degres = %f \n", radToDeg(*angle2));
        printf("Angle position of joint 2 (degres) = %f \n", invAngle2toDeg);

        if ((invAngle1toDeg < (Angle1toDeg + .1*Angle1toDeg)) && (invAngle1toDeg > (Angle1toDeg - .1*Angle1toDeg))) {
            angle1Valid++;
        }

        if ((invAngle2toDeg < (Angle2toDeg + .1*Angle2toDeg)) && (invAngle2toDeg > (Angle2toDeg - .1*Angle2toDeg))) {
            angle2Valid++;
        }
    }
    accuracyAngle1 = angle1Valid/(float)nbTest;
    accuracyAngle2 = angle2Valid/(float)nbTest;

    printf("\n%d values accepted for angle 1 on %d values = %f percent(s)\n", angle1Valid, nbTest, accuracyAngle1);
    printf("%d values accepted for angle 2 on %d values = %f percent(s)\n", angle2Valid, nbTest, accuracyAngle2);
}