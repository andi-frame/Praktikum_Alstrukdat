#include <stdio.h>
#include <math.h>
#include "circle.h"

boolean IsCIRCLEValid(float X, float Y, float R){
    if (R <= 0){
        return false;
    }
    return !isnan(X) && !isnan(Y) && !isnan(R) && !isinf(X) && !isinf(Y) && !isinf(R);
}

void CreateCIRCLE(CIRCLE *C, float X, float Y, float R){
    Center(*C).X = X;
    Center(*C).Y = Y;
    Radius(*C) = R;
}


void ReadCIRCLE(CIRCLE *C){
    float X, Y, R;
    do{
        scanf("%f %f %f", &X, &Y, &R);
        if(!IsCIRCLEValid(X, Y, R)){
            printf("CIRCLE tidak valid\n");
        }
    } while (!IsCIRCLEValid(X, Y, R));

    CreateCIRCLE(C, X, Y, R);
}

void WriteCIRCLE(CIRCLE C){
    printf("P(%.2f,%.2f) r=%.2f", C.CENTER.X, C.CENTER.Y, C.R);
}

float Circumference(CIRCLE C){
    return 2*3.14*C.R;
}

float Area(CIRCLE C){
    return 3.14*C.R*C.R;
}

boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P){
    float distance = sqrt((C.CENTER.X - P.X)*(C.CENTER.X - P.X) + (C.CENTER.Y - P.Y)*(C.CENTER.Y - P.Y));
    if (distance < C.R){
        return true;
    } else {
        return false;
    }
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P){
    float distance = sqrt((C.CENTER.X - P.X)*(C.CENTER.X - P.X) + (C.CENTER.Y - P.Y)*(C.CENTER.Y - P.Y));
    if ((distance <= C.R + 0.00001) && (distance >= C.R - 0.00001)){
        return true;
    } else {
        return false;
    }
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2){
    float distance = sqrt((C1.CENTER.X - C2.CENTER.X)*(C1.CENTER.X - C2.CENTER.X) + (C1.CENTER.Y - C2.CENTER.Y)*(C1.CENTER.Y - C2.CENTER.Y));
    float sumR = C1.R + C2.R;
    if (C1.R < C2.R){
        if (distance + C1.R < C2.R) {
            return true;
        } else {
            return false;
        }
    } else if (C2.R < C1.R){
        if (distance + C2.R < C1.R) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2){
    float distance = sqrt((C1.CENTER.X - C2.CENTER.X)*(C1.CENTER.X - C2.CENTER.X) + (C1.CENTER.Y - C2.CENTER.Y)*(C1.CENTER.Y - C2.CENTER.Y));
    float sumR = C1.R + C2.R;
    if ((distance <= sumR + 0.00001) && (distance >= sumR - 0.00001)){
        return true;
    } else {
        return false;
    }
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2){
    float distance = sqrt((C1.CENTER.X - C2.CENTER.X)*(C1.CENTER.X - C2.CENTER.X) + (C1.CENTER.Y - C2.CENTER.Y)*(C1.CENTER.Y - C2.CENTER.Y));
    float sumR = C1.R + C2.R;
    if (distance < sumR){
        return true;
    } else {
        return false;
    }
}