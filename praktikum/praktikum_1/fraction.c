#include <stdio.h>
#include "fraction.h"

boolean IsFRACTIONValid(int N, int D){
    if (D == 0) {
        return false;
    } else {
        return true;
    }
}

void CreateFRACTION(FRACTION *F, int N, int R){
    Numerator(*F) = N;
    Denominator(*F) = R;
}

void ReadFRACTION(FRACTION *F){
    int N, R;
    do{
        scanf("%d %d", &N, &R);
        if(!IsFRACTIONValid(N, R)){
            printf("FRACTION tidak valid\n");
        }
    } while (!IsFRACTIONValid(N, R));

    CreateFRACTION(F, N, R);
}

void WriteFRACTION(FRACTION F){
    printf("%d/%d", F.N, F.D);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2){
    FRACTION frac;
    int newN = F1.N*F2.D + F2.N*F1.D;
    int newD = F1.D * F2.D;
    int gcdNum = gcd(newN, newD);
    newN /= gcdNum;
    newD /= gcdNum;
    frac.N = newN;
    frac.D = newD;
    return frac;   
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2){
    FRACTION frac;
    int newN = F1.N*F2.D - F2.N*F1.D;
    int newD = F1.D * F2.D;
    int gcdNum = gcd(newN, newD);
    newN /= gcdNum;
    newD /= gcdNum;
    frac.N = newN;
    frac.D = newD;
    return frac;   
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2){
    FRACTION frac;
    int newN = F1.N*F2.N;
    int newD = F1.D*F2.D;
    int gcdNum = gcd(newN, newD);
    newN /= gcdNum;
    newD /= gcdNum;
    frac.N = newN;
    frac.D = newD;
    return frac;
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2){
    FRACTION frac;
    int newN = F1.N*F2.D;
    int newD = F1.D*F2.N;
    int gcdNum = gcd(newN, newD);
    newN /= gcdNum;
    newD /= gcdNum;
    frac.N = newN;
    frac.D = newD;
    return frac;
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1){
    FRACTION frac;
    int newN = F1.N*n;
    int newD = F1.D;
    int gcdNum = gcd(newN, newD);
    newN /= gcdNum;
    newD /= gcdNum;
    frac.N = newN;
    frac.D = newD;
    return frac;
}

FRACTION SimplifyFRACTION(FRACTION F){
   FRACTION frac;
    int newN = F.N;
    int newD = F.D;
    int gcdNum = gcd(newN, newD);

    if(newN < 0 && newD < 0){
        newN = -newN;
        newD = -newD;
    }else if(newD < 0 && newN > 0){
        newN = -newN;
        newD = -newD;
    }
    
    newN /= gcdNum;
    newD /= gcdNum;
    frac.N = newN;
    frac.D = newD;
    return frac;
}

float ToDecimal(FRACTION F){
    float decimal = F.N / F.D;
    return decimal;
}