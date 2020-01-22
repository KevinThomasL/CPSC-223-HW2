// ----------------------------------------------------------------------
// Author:
// Assignment: 2
// ----------------------------------------------------------------------

#include "decimal.h"


// default value is "0."
Decimal::Decimal() : point_loc(0)
{
  digits.push_back(0);
}


Decimal::Decimal(std::string val, int point_location)
  : point_loc(point_location)
{
  int n = int(val.size());
  // invalid cases: bad point location, empty string
  if (point_loc > n || n == 0) {
    // set to default value "0."
    point_loc = 0;
    digits.push_back(0);
    return;
  }
  // parse string
  for (int i = 0; i < n; ++i) {
    char c = val[i];
    if (std::isdigit(c))
      digits.push_back(c - '0');
    else {
      // invalid character found
      digits.clear();
      point_loc = 0;
      digits.push_back(0);
      return;
    }
  }
  reduce_zeros();
}


// TODO: Finish remaining Decimal functions ... 
