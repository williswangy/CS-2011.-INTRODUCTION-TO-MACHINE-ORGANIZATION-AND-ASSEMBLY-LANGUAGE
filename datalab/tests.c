/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
int test_oddBits(void) {
  int result = 0;
  int i;
  for (i = 1; i < 32; i+=2)
    result |= 1<<i;
  return result;
}
int test_isTmin(int x) {
    return x == 0x80000000;
}
int test_bitXor(int x, int y)
{
  return x^y;
}
int test_conditional(int x, int y, int z)
{
  return x?y:z;
}
int test_greatestBitPos(int x) {
    unsigned mask = 1<<31;
    if (x == 0)
 return 0;
    while (!(mask & x)) {
 mask = mask >> 1;
    }
    return mask;
}
int test_divpwr2(int x, int n)
{
    int p2n = 1<<n;
    return x/p2n;
}
int test_isNonNegative(int x) {
  return x >= 0;
}
int test_satMul2(int x)
{
  if ((x+x)/2 != x)
    return x < 0 ? 0x80000000 : 0x7FFFFFFF;
  else
    return 2*x;
}
int test_isLess(int x, int y)
{
  return x < y;
}
int test_isAsciiDigit(int x) {
  return (0x30 <= x) && (x <= 0x39);
}
int test_trueThreeFourths(int x)
{
  return (int) (((long long int) x * 3)/4);
}
int test_ilog2(int x) {
  int mask, result;
  /* find the leftmost bit */
  result = 31;
  mask = 1 << result;
  while (!(x & mask)) {
    result--;
    mask = 1 << result;
  }
  return result;
}
unsigned test_float_neg(unsigned uf) {
    float f = u2f(uf);
    float nf = -f;
    if (isnan(f))
 return uf;
    else
 return f2u(nf);
}
unsigned test_float_i2f(int x) {
  float f = (float) x;
  return f2u(f);
}
unsigned test_float_twice(unsigned uf) {
  float f = u2f(uf);
  float tf = 2*f;
  if (isnan(f))
    return uf;
  else
    return f2u(tf);
}
