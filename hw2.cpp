// ----------------------------------------------------------------------
// Author: Kevin Lunden 
// Assignment: 2
//
// Basic driver for testing the Decimal class implementation using
// assert statements. This file only partially tests the Decimal class
// and should be extended (see TODO below) with your own test cases.
// ----------------------------------------------------------------------


#include <iostream>
#include <cassert>
#include "decimal.h"

using namespace std;


int main(int argc, char** argv)
{	
  // poorly formed decimal values
  Decimal zero = Decimal();
  assert(Decimal("", 0) == zero);
  assert(Decimal("123", 4) == zero);

  // increment
  Decimal one = Decimal("1", 0);
  assert(++Decimal() == one);
  assert(Decimal()++ == zero);

  // basic addition
  Decimal x = Decimal("12345", 1);
  Decimal y = Decimal("67890", 3);
  assert(x + y == Decimal("1302390", 3));

/*
  // large addition
  Decimal z = Decimal("99999999999999999999", 5);
  z = z + Decimal("00001", 5);
  cout << z << endl;
  assert(z == Decimal("100000000000000000000", 5));
*/

  // test same values
  Decimal pi_1("314159", 5);
  Decimal pi_2("3141590", 6);
  assert(pi_1 == pi_2);
  assert(!(pi_1 != pi_2));
  assert(!(pi_1 < pi_2));
  assert(!(pi_1 > pi_2));
  assert(pi_1 <= pi_2);
  assert(pi_1 >= pi_2);

  // test printing
  cout << "should be 1: " << Decimal("1",0) << endl;
  cout << "should be 43: " << Decimal("430", 1) << endl;
  cout << "should be 1.75: " << Decimal("01750", 3) << endl;

  //my first custom test
  Decimal test1("12345", 4);
  Decimal test2("12345", 4);
  assert (test1 == test2);
  assert(!(test1 != test2));
  assert(!(test1 < test2));
  assert(!(test1 > test2));
  assert(test1 <= test2);
  assert(test1 >= test2);

  //custom test2
  cout << "should be .00001: " << Decimal("00001", 5) << endl;

  //custom test3
  Decimal a = Decimal("11", 1);
  Decimal b = Decimal("12", 1);
  cout << a + b << endl;
  assert(a + b == Decimal("23", 1));

  //custom test4
  Decimal c = Decimal("0012", 2);
  Decimal d = Decimal("0023", 2);
  assert(c + d == Decimal("0035", 2));

  //custom test5
  Decimal k = Decimal("02346", 2);
  Decimal l = Decimal("234600", 3);
  assert(k + l == Decimal("25806", 2));
}
