#include "complex.h"

#include <stdio.h>

boolean IsCOMPLEXValid(float Re, float Im) {
  return !isnan(Re) && !isnan(Im) && !isinf(Re) && !isinf(Im);
}

void CreateComplex(COMPLEX *C, float Re, float Im) {
  Real(*C) = Re;
  Imag(*C) = Im;
}

void BacaCOMPLEX(COMPLEX *C) {
  float Re, Im;
  scanf("%f %f", &Re, &Im);
  CreateComplex(C, Re, Im);
}

void TulisCOMPLEX(COMPLEX C) {
  if (C.Im >= 0) {
    printf("%.2f+%.2fi\n", C.Re, C.Im);
  } else {
    printf("%.2f%.2fi\n", C.Re, C.Im);
  }
}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2) {
  COMPLEX complex;
  CreateComplex(&complex, C1.Re + C2.Re, C1.Im + C2.Im);
  return complex;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2) {
  COMPLEX complex;
  CreateComplex(&complex, C1.Re - C2.Re, C1.Im - C2.Im);
  return complex;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2) {
  COMPLEX complex;
  CreateComplex(&complex, C1.Re * C2.Re - C1.Im * C2.Im,
                C1.Re * C2.Im + C1.Im * C2.Re);
  return complex;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2) {
  COMPLEX complex;
  if (C2.Re * C2.Re + C2.Im * C2.Im == 0) {
    CreateComplex(&complex, 0, 0);
    return complex;
  }
  CreateComplex(
      &complex,
      (C1.Re * C2.Re + C1.Im * C2.Im) / (C2.Re * C2.Re + C2.Im * C2.Im),
      (C1.Im * C2.Re - C1.Re * C2.Im) / (C2.Re * C2.Re + C2.Im * C2.Im));
  return complex;
}

float AbsCOMPLEX(COMPLEX C) { return sqrt(C.Re * C.Re + C.Im * C.Im); }

COMPLEX ConjugateCOMPLEX(COMPLEX C) {
  COMPLEX complex;
  CreateComplex(&complex, C.Re, -C.Im);
  return complex;
}

boolean CEQ(COMPLEX C1, COMPLEX C2) { return C1.Re == C2.Re && C1.Im == C2.Im; }

boolean CNEQ(COMPLEX C1, COMPLEX C2) {
  return !(C1.Re == C2.Re && C1.Im == C2.Im);
}
