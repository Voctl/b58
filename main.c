#include <stdio.h>
#include <stdlib.h>

enum {
  ADD,
  PUSH,
  HALT,
  PRINT,
  SUB,
};

int main(void) {
  int program[] = {
    PUSH, 5,
    PUSH, 2,
    ADD,
    PRINT,
    HALT,
  };

  int stack[256];
  int ip = 0;
  int sp = 0;
  int a, b;

  while (1) {

    int op = program[ip++]; // instructions

    switch (op){

    case PUSH : {
      stack[sp++] = program[ip++];
      break;
    }
    case ADD: {
      a = stack[--sp];
      b = stack[--sp];
      stack[++sp] = a + b;
      break;
    }
    case SUB:{
      a = stack[--sp];
      b = stack[--sp];
      stack[++sp] = b - a;
      break;
    }
    case PRINT: {
      printf("%d\n", stack[sp]);
    }
    case HALT: {
      return 0;
    }
    default :
      return 1;
    }
  }
}
