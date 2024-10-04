#include "point.h"
#include <stdio.h>

void CreatePoint(POINT *P, float X, float Y) {
  Absis(*P) = X;
  Ordinat(*P) = Y;
}

void BacaPOINT(POINT *P) {
  float X, Y;
  scanf("%f %f", &X, &Y);
  CreatePoint(P, X, Y);
}

void TulisPOINT(POINT P) { printf("(%.2f,%.2f)", P.X, P.Y); }

boolean EQ(POINT P1, POINT P2) { return P1.X == P2.X && P1.Y == P2.Y; }

boolean NEQ(POINT P1, POINT P2) { return !(P1.X == P2.X && P1.Y == P2.Y); }

boolean IsOrigin(POINT P) { return P.X == 0.0 && P.Y == 0.0; }

boolean IsOnSbX(POINT P) { return P.Y == 0; }

boolean IsOnSbY(POINT P) { return P.X == 0; }

int Kuadran(POINT P) {
  if (P.X > 0 && P.Y > 0) {
    return 1;
  }
  if (P.X < 0 && P.Y > 0) {
    return 2;
  }
  if (P.X < 0 && P.Y < 0) {
    return 3;
  }
  if (P.X > 0 && P.Y < 0) {
    return 4;
  }
}

POINT NextX(POINT P) {
  POINT point;
  CreatePoint(&point, P.X + 1, P.Y);
  return point;
}

POINT NextY(POINT P) {
  POINT point;
  CreatePoint(&point, P.X, P.Y + 1);
  return point;
}

POINT PlusDelta(POINT P, float deltaX, float deltaY) {
  POINT point;
  CreatePoint(&point, P.X + deltaX, P.Y + deltaY);
  return point;
}

POINT MirrorOf(POINT P, boolean SbX) {
  POINT point;
  if (SbX) {
    CreatePoint(&point, P.X, -P.Y);
  } else {
    CreatePoint(&point, -P.X, P.Y);
  }
  return point;
}

float Jarak0(POINT P) { return sqrt(P.X * P.X + P.Y * P.Y); }

float Panjang(POINT P1, POINT P2) {
  return sqrt((P1.X - P2.X) * (P1.X - P2.X) + (P1.Y - P2.Y) * (P1.Y - P2.Y));
}

void Geser(POINT *P, float deltaX, float deltaY) {
  CreatePoint(P, Absis(*P) + deltaX, Ordinat(*P) + deltaY);
}

void GeserKeSbX(POINT *P) { CreatePoint(P, Absis(*P), 0); }

void GeserKeSbY(POINT *P) { CreatePoint(P, 0, Ordinat(*P)); }

void Mirror(POINT *P, boolean SbX) {
  if (SbX) {
    CreatePoint(P, Absis(*P), -Ordinat(*P));
  } else {
    CreatePoint(P, -Absis(*P), Ordinat(*P));
  }
}

void Putar(POINT *P, float Sudut) {
  float rad =
      Sudut * 3.14159265358979323846 / 180.0;
  float x = Absis(*P) * cos(rad) + Ordinat(*P) * sin(rad);
  float y = -Absis(*P) * sin(rad) + Ordinat(*P) * cos(rad);
  CreatePoint(P, x, y);
}

void PersamaanLinearDuaVariabel(POINT P1, POINT P2) {
  float a = (P2.Y - P1.Y) / (P2.X - P1.X);
  float b = P1.Y - a * P1.X;
  // y = ax + b
  printf("(%.2f,%.2f)", a, b);
}