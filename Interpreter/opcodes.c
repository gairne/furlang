/*
 * Copyright 2012  Matthew Mole <code@gairne.co.uk>, Peter Sandy <pudabudigada@gmail.com>
 * 
 * This file is part of Furlang.
 * 
 * Furlang is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Furlang is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with Furlang.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>

void iadd(int *stack, int *spointer, int operand) {
  int value1 = *(stack+*spointer);
  (*spointer)--;
  int value2 = *(stack+*spointer);
  *(stack+*spointer) = value1 + value2;
#ifdef DEBUG
  printf("Adding %u %u\n", value1, value2);
  printf("StackPTR = %x\n", (stack+*spointer));
#endif
}

void isub(int *stack, int *spointer, int operand) {
  int value1 = *(stack+*spointer);
  (*spointer)--;
  int value2 = *(stack+*spointer);
  *(stack+*spointer) = value2 - value1;
#ifdef DEBUG
  printf("Subtracting %u from %u\n", value1, value2);
  printf("StackPTR = %x\n", (stack+*spointer));
#endif
}

void imul(int *stack, int *spointer, int operand) {
  int value1 = *(stack+*spointer);
  (*spointer)--;
  int value2 = *(stack+*spointer);
  *(stack+*spointer) = value1 * value2;
#ifdef DEBUGI
  printf("Multiplying %u to %u\n", value1, value2);
  printf("StackPTR = %x\n", (stack+*spointer));
#endif
}

void idiv(int *stack, int *spointer, int operand) {
  int value1 = *(stack+*spointer);
  (*spointer)--;
  int value2 = *(stack+*spointer);
  *(stack+*spointer) = value2 / value1;
#ifdef DEBUG
  printf("Dividing %u by %u\n", value2, value1);
  printf("StackPTR = %x\n", (stack+*spointer));
#endif
}

void ldl(int *stack, int *spointer, int operand) {
  (*spointer)++;
  *(stack+*spointer) = operand;
#ifdef DEBUG
  printf("StackPTR = %x\n", (stack+*spointer));
#endif
}

void print(int *stack, int *spointer, int operand) {
  printf("%u\n", *(stack+*spointer));
#ifdef DEBUG
  printf("StackPTR = %x\n", (stack+*spointer));
#endif
}
