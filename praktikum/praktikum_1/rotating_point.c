#include "rotating_point.h"
// #include "complex.c"
// #include "point.c"
#include <math.h>
#include <stdio.h>

COMPLEX PowerCOMPLEX(COMPLEX C, int p) {
  int i;
  float initImag, initReal, tempReal;
  initReal = Real(C);
  initImag = Imag(C);

  for (i = 2; i <= p; i++) {
    tempReal = Real(C);
    Real(C) = Real(C) * initReal - Imag(C) * initImag;
    Imag(C) = Imag(C) * initReal + tempReal * initImag;
  }
  return C;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n) {
  int i;
  float distance;
  float tempX;
  COMPLEX newC;

  if (n == 0) {
    if (P->X * P->X + P->Y * P->Y > 1) {
      printf("Titik keluar dari lingkaran pada iterasi ke 0");
    } else {
      printf("Titik tetap berada di dalam lingkaran setelah 0 iterasi");
    }
    return;
  }

  i = 0;
  do {
    newC = PowerCOMPLEX(C, i + 1);
    tempX = P->X;
    P->X = P->X * Real(newC) - P->Y * Imag(newC);
    P->Y = tempX * Imag(newC) + P->Y * Real(newC);
    distance = P->X * P->X + P->Y * P->Y;
    i++;

    if (distance > 1) {
      printf("Titik keluar dari lingkaran pada iterasi ke %i", i);
      return;
    }
  } while (i < n);

  printf("Titik tetap berada di dalam lingkaran setelah %i iterasi", n);
}

// int main() {
//   POINT P;
//   COMPLEX C;

//   P.X = 0.5;
//   P.Y = 0.5;

//   C.Re = 1.5;
//   C.Im = 0.5;

//   TransformPointByComplexPower(&P, C, 2);

//   return 0;
// }