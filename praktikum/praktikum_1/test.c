#include "fraction.c"

int main() {
  FRACTION f1, f2, f3;
  ReadFRACTION(&f1);
  ReadFRACTION(&f2);
  printf("\n");
  WriteFRACTION(f1);
  printf("\n");
  WriteFRACTION(f2);
  printf("\n");

  f3 = SubtractFRACTION(f1, f2);
  WriteFRACTION(f3);

  return 0;
}