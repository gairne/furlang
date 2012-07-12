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
#include "opcodes.h"

#define DEBUG
#define DEBUG_PRINTSTACK

void printstack(int *, int);

#define MAX_LINE 1000
#define STACK_SIZE 1000

//int readChunk(FILE *, char*);
//int readOpcode(char *);
//int readOperand(char *);
int readinst(int *, int *, FILE *);

opcodeHandler lookupTable[N_OPCODES] = {iadd, ldl, isub, imul, idiv, print};

int main(int argc, char** argv) {
  FILE *fp;
  char *buffer = malloc(MAX_LINE * sizeof(char));
  int stack[STACK_SIZE];
  int stackOffset = 0;

  if (buffer == NULL) {
    printf("Could not allocate buffer");
    return -1;
  }

  if (!(fp = fopen(argv[1], "r+"))) {
    printf("Could not open file");
    return -1;
  }

  int opcode;
  int operand;
  while (readinst(&opcode, &operand, fp)) {//readChunk(fp, buffer)) {
#ifdef DEBUG
    printf("Instruction:\n");
#endif
    //opcode = readOpcode(buffer);
#ifdef DEBUG
    printf("  Opcode = %u\n", opcode);
#endif
    //operand = readOperand(buffer);
#ifdef DEBUG
    printf("  Operand = %u\n", operand);
#endif
    (*lookupTable[opcode])(&stack, &stackOffset, operand);
#ifdef DEBUG_PRINTSTACK
    printf("New stack ptr: 0x%x+%u=0x%x (%u) \n", stack, stackOffset, stack+stackOffset, *(stack+stackOffset));
    printstack(&stack, stackOffset);
#endif
  }

  fclose(fp);
}

int readinst(int *a, int *b, FILE *numfile){
    unsigned char nums[3];
    int x = fread(nums,sizeof(char),2,numfile);
    
    *a = (int) nums[0];
    *b = (int) nums[1];
    return x;
}
/*
int readOpcode(char *buffer) {
  int op = 0;
  char s = *buffer;
#ifdef DEBUGB
    printf("Buffer =  %c\n", s);
#endif
  while(s >= '0' && s <= '9') {
    op = op * 10 + (s - '0');
    buffer++;
    s = *buffer;
#ifdef DEBUGB
    printf("Buffer =  %c\n", s);
#endif
  }
  return op;
}

int readOperand(char *buffer) {
  int oper = 0;
  char s = *buffer;
#ifdef DEBUGB
  printf("Buffer =  %c\n", s);
#endif
  while(s >= '0' && s <= '9') {
    buffer++;
    s = *buffer;
#ifdef DEBUGB
    printf("Buffer =  %c\n", s);
#endif
  }
  buffer++;
  s = *buffer;
  while(s >= '0' && s <= '9') {
    oper = oper * 10 + (s - '0');
    buffer++;
    s = *buffer;
#ifdef DEBUGB
    printf("Buffer =  %c\n", s);
#endif
  }
  return oper;
}

int readChunk(FILE *fp, char* buffer) {
  return fgets(buffer, MAX_LINE, fp) != NULL;
  //TODO: Fail if couldn't read in whole line.
  //TODO: Instead read in a whole block and process.
}*/

void printstack(int *stack, int soffset) {
  int i;
  for (i = 0; i <= soffset; i++) {
    printf("0x%x: %u\n", (stack+i), *(stack+i));
  }
}
