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

/**
 * WARNING: Programs run on the interpreter should be compiled by a compiler with the same BYTECODE_VERSION.
 * Undefined behaviour if this warning is not heeded.
 */
#define BYTECODE_VERSION 1
#define N_OPCODES 6

typedef void (*opcodeHandler)(int *, int *, int);

void iadd(int *, int *, int);  //0
void isub(int *, int *, int);  //2
void imul(int *, int *, int);  //3
void idiv(int *, int *, int);  //4
void ldl(int *, int *, int);   //1
void print(int *, int *, int); //5

