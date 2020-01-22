// ----------------------------------------------------------------------
// Author: 
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

  // large addition
  Decimal z = Decimal("99999999999999999999", 5);
  z = z + Decimal("00001", 5);
  assert(z == Decimal("100000000000000000000", 5));
  
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
  
  // ...
  // TODO: add your own tests, considering the various cases
  // ...

}

