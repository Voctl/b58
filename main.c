#include <stdio.h>
#include <stdlib.h>
enum { ADD, PUSH, HALT, PRINT, SUB }; int main(void) { int program[] = { PUSH, 5, PUSH, 2, ADD, PRINT, HALT }; int stack[256]; int ip = 0, sp = 0, a, b; while (1) { int op = program[ip++]; if (op == PUSH) stack[sp++] = program[ip++]; else if (op == ADD) { a = stack[--sp]; b = stack[--sp]; stack[++sp] = a + b; } else if (op == SUB) { a = stack[--sp]; b = stack[--sp]; stack[++sp] = b - a; } else if (op == PRINT) { printf("%d\n", stack[sp]); return 0; } else if (op == HALT) return 0; else return 1; } }
