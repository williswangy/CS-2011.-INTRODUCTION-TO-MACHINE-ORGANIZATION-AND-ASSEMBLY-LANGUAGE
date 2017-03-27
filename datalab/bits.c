/* 
 * CS:APP Data Lab 
 * 
 * <Yuan Wang, 686033752, userId: williswy>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
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
/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {

	int myAns = 0xAA;
	int word = myAns | myAns << 8;
	return word | word << 16;
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {

	/*Tmin 10000000 00000000 00000000 00000000
	 *Tmin? -> x & Tmin
	 */	
	return !(x+x)&!!(x);

}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	
	//De Morgan's law -> or
	return ~(x & y) & ~(~x & ~y);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	/*
	 *if x != 0, mask = 0x00000000, so y&~mask == y and z&mask == 0
	 *if x == 0, mask = 0xffffffff, so y&~mask = y&0 = 0;z&mask = z
	 */
	int mask = ~!x+1;
	return (y & ~mask) | (z & mask);
}
/* 
 * greatestBitPos - return a mask that marks the position of the
 *               most significant 1 bit. If x == 0, return 0
 *   Example: greatestBitPos(96) = 0x40
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 70
 *   Rating: 4 
 */
int greatestBitPos(int x) {
    /*
     *x < 0, x = 11.. after shifting
     *x = 0, x = 00.. after shifting
     *x > 0, x=  0001111..1 after shifting
     *">>" -> 1,2,4,8,16 -> "|"
     */
    x = x | x >> 1;
    x = x | x >> 2;
    x = x | x >> 4;
    x = x | x >> 8;
    x = x | x >> 16;
    x = x & ((~x >> 1) ^ (1 << 31));
    return x;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    /*if x >= 0 -> x / 2^n
     *if x < 0, x -> (x + 2^n - 1)-> (x + 2^n - 1) / 2^n
     *if x >= 0, then ans = 0, if x < 0, ans = 2^n - 1 
     */
    int ans = ((1 << n) + ~0) & (x >> 31);
    return ((x + ans) >> n);
}


/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
		
	return !((x>>0x1F) & 0x01);
}

/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
	/*
 	 * Overflow: positive -> negitive, negitive -> positive
 	 * Tmax = ~Tmin(1...0, 1...1) -> xor with all 1 or all 0 -> Opposite
 	 */
   
    int  Tmin = 0x1 << 31;
    int  sign = x >> 31;//all 1 or all 0
    int   x_2;	// x * 2
    int   big;	// too big?
    int   sat;
    
    x_2 = x + x;
    big = (x^x_2) >> 31; //xor -> sign change -> all 1, Otherwise -> all 0
    			 //Tmax -> (x >= 0); Tmin -> (x < 0)
    sat = big & (sign ^ ~Tmin);//negitive -> mask for Tmax; positive-> mask for Tmin
    return (sat) | (~big & x_2);//return sat -> (x > max)
    return 2;
  
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */


int isLess(int x, int y) {
    /*
     * not_y = ~y
     * x-y: x+(~y+1)
     * ~y&x : x<0, y>0 return 1
     * ~y|x : x>0, y<0 return 0
     * x-y|(~x+y+1)) : x=y, x-y and y-x both equals 0, return 0
     */
	int not_y = ~y;
	return ((((x + not_y +1) & (x ^ not_y)) | (x & not_y) ) >> 0x1F) & 1;
  
}
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	//x_comp = ~x
	//d1 -> lower bound 
	//d2 -> upper bound
	int x_comp = ~x;
	int d1 = 0x30 + x_comp;//sign bit 0
	int d2 = 0x3A + x_comp;//sign bit 1
	return !(~(d1>>31) | (d2 >> 31));
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{
    int y = x & 0x3;
    x = x >> 2;
    return ( x<< 1 )+ x + ( ( y + y + y + ( (x >> 0x1F) & 0x3 )) >> 2 );
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	//find left-most 1
	//binary search
	int bitsNumber = 0;
	bitsNumber = (!!(x>>16)) << 4;//if > 16
	bitsNumber = bitsNumber+((!!(x>>(bitsNumber+8)))<<3);//if >bitsNumber + 8
	bitsNumber = bitsNumber+((!!(x>>(bitsNumber+4)))<<2);//if >bitsNumber + 4
	bitsNumber = bitsNumber+((!!(x>>(bitsNumber+2)))<<1);//if >bitsNumber + 2
	bitsNumber = bitsNumber+(!!(x>>(bitsNumber+1)));
	
	return bitsNumber;
}

/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	unsigned result = uf ^ 0x80000000; //change signed bit -> uf
	unsigned tmp = uf & 0x7FFFFFFF; // change signed bit -> uf -> 0
	if (tmp > 0x7F800000) // If -> NaN, return argument,
			      //ieee standard: 1 bit signed bit, 8 bits exponent, 23 bits mantissa	
		result = uf;
	return result;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	unsigned shiftLeft = 0;
	unsigned afterShift, tmp, flag;
	unsigned absX = x;
	unsigned sign = 0;
	if (x == 0) // when x == 0
		return 0;
	if (x < 0) { // x < 0
		sign = 0x80000000;
		absX = -x;
	}
	afterShift = absX;
	while(1) {
		tmp = afterShift;
		afterShift<<= 1;
		shiftLeft++;
		if(tmp & 0x80000000) break;
	}
	if ((afterShift & 0x01FF) > 0x0100)
		flag =1;
	else if ((afterShift & 0x03FF) == 0x0300)
		flag =1;
	else
		flag =0;
	return sign + (afterShift>>9) + ((159 - shiftLeft)<<23) + flag;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	//IEEE Standard
	//0x7F800000 -> exponent 
	//0x007FFFFF -> mantissa 
	//0x80000000 -> negative	
	unsigned f = uf;
	if (( f & 0x7F800000 ) == 0) {
		f = (( f & 0x007FFFFF ) << 1 ) | (0x80000000 & f);
	} else if((f & 0x7F800000) != 0x7F800000) {
			f = f + 0x00800000;
	}
	return f;
}
