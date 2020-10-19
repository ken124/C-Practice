#include <stdio.h>

//C doesn't have booleans built in, so we have to simulate them with ints

int main(int argc, char const *argv[]) {
  //int true = 1;
  //int false = 0;

  //maybe atom has booleans already part of c
  //Atom sees true as 1 and false as 0, but there isnt a boolean data type...
  int x,y;

  x = true;
  y = (x == false);

  printf("Value of x: %d\n", x);
  printf("Value of y: %d\n", y);
  return 0;
}
