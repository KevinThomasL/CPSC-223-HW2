// ----------------------------------------------------------------------
// Author: Kevin Lunden
// Assignment: 2
// ----------------------------------------------------------------------

#include "decimal.h"
using namespace std;

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


// binary addition operator
Decimal Decimal::operator+(const Decimal& rhs) const
{
 Decimal tmp = Decimal();
 int hold = 0;
 int bigger;
 int newDec;

 if (size() >= rhs.size())
  bigger = size();
 if (size() < rhs.size())
  bigger = rhs.size();

 Decimal tmp1 = *this;
 Decimal tmp2 = rhs;

 //put zeroes in front to match smaller decimal
 if ((tmp1.size() - tmp1.point_loc) > (tmp2.size() - tmp2.point_loc))
 {
  int frontZ = ((tmp1.size() - tmp1.point_loc) - (tmp2.size() - tmp2.point_loc)); 
  for (int i = 0; i < frontZ; ++i)
   tmp2.digits.insert(tmp2.digits.begin(), 0);
 }
 if ((tmp1.size() - tmp1.point_loc) < (tmp2.size() - tmp2.point_loc))
 {
  int frontZ = ((tmp2.size() - tmp2.point_loc) - (tmp1.size() - tmp1.point_loc));
  for (int i = 0; i < frontZ; ++i)
   tmp1.digits.insert(tmp1.digits.begin(), 0);
 }

 //put zeroes in back to match smaller decimal
 if ((tmp1.size()-(tmp1.size()-tmp1.point_loc)) > (tmp2.size()-(tmp2.size()-tmp2.point_loc)))
 {
  int backZ = ((tmp1.size()-(tmp1.size()-tmp1.point_loc)) - (tmp2.size()-(tmp2.size()-tmp2.point_loc)));
  for (int i = 0; i < backZ; ++i)
  {
   tmp2.digits.push_back(0);
   tmp2.point_loc += 1;
  }
 }
 if ((tmp1.size()-(tmp1.size()-tmp1.point_loc)) < (tmp2.size()-(tmp2.size()-tmp2.point_loc)))
 {
  int backZ = ((tmp2.size()-(tmp2.size()-tmp2.point_loc)) - (tmp1.size()-(tmp1.size()-tmp1.point_loc)));
  for (int i = 0; i < backZ; ++i)
  {
   tmp1.digits.push_back(0);
   tmp1.point_loc += 1;
  }
 } 

 for (int i = bigger; i >= 0; --i)
 {
  bool flag = false;
  if (!(tmp2.digits[i]))
  {
   newDec = tmp1.digits[i] + hold;
   flag = true;
  }
  if (!(tmp1.digits[i]))
  {
   newDec = tmp2.digits[i] + hold;
   flag = true;
  }
  if (flag == false) 
   newDec = tmp1.digits[i] + tmp2.digits[i] + hold;
  hold = 0;
  if (newDec >= 10)
  {
   newDec = newDec - 10;
   hold = 1;
  }
  tmp.digits.insert(tmp.digits.begin(), newDec);
 }
 if (hold == 1)
  tmp.digits.insert(tmp.digits.begin(), 1);

 tmp.reduce_zeros();

 if ((tmp1.size()-(tmp1.size()-tmp1.point_loc)) >= (tmp2.size()-(tmp2.size()-tmp2.point_loc)))
  tmp.point_loc = tmp1.point_loc;
 if ((tmp1.size()-(tmp1.size()-tmp1.point_loc)) < (tmp2.size()-(tmp2.size()-tmp2.point_loc)))
  tmp.point_loc = tmp2.point_loc;

 return tmp;
}

// prefix increment operator
Decimal& Decimal::operator++()
{
 int num = digits[digits.size() - 1];
 digits.pop_back();
 digits.push_back(++num);
 return *this;
}

// postfix increment operator
Decimal Decimal::operator++(int)
{
 Decimal tmp = *this;
 int num = digits[digits.size() - 1];
 digits.pop_back();
 digits.push_back(++num);
 return tmp;
}	


// six relational comparison operators
bool Decimal::operator<(const Decimal& rhs) const
{
 if ((size() - point_loc) < (rhs.size() - rhs.point_loc))
  return true;
 if ((size() - point_loc) > (rhs.size() - rhs.point_loc))
  return false;
 else
 {
  if (size() > rhs.size())
  {
   for (int i = 0; i < size(); ++i)
   {
    if (!(rhs.digits[i]))
    {
     if (digits[i] > 0)
      return false;
     if (digits[i] < 0)
      return true;
    }     
    if (digits[i] < rhs.digits[i])
     return true;
    if (digits[i] > rhs.digits[i])
     return false;
   }
  }
  else
  {
   for (int i = 0; i < rhs.size(); ++i)
   {
    if (!(digits[i]))
    {
     if (digits[i] > 0)
      return false;
     if (digits[i] < 0)
      return true;
    }
    if (digits[i] < rhs.digits[i])
     return true;
    if (digits[i] > rhs.digits[i])
     return false;
   }
  }
 return false;
 }
}

bool Decimal::operator==(const Decimal& rhs) const
{
 if (*this < rhs)
  return false;
 if (rhs < *this)
  return false;
 return true;
}

bool Decimal::operator>(const Decimal& rhs) const
{
 if (((*this < rhs) == false) && ((*this == rhs) == false))
  return true;
 return false;
}

bool Decimal::operator<=(const Decimal& rhs) const
{
 if (((*this < rhs) == true) || ((*this == rhs) == true))
  return true;
 return false;
}

bool Decimal::operator>=(const Decimal& rhs) const
{
 if (((*this < rhs) == false) || ((*this == rhs) == true))
  return true;
 return false;
}

bool Decimal::operator!=(const Decimal& rhs) const
{
 if ((*this == rhs) == false)
  return true;
 return false;
}

ostream& operator<<(std::ostream& out, const Decimal& val)
{
 for (int i = 0; i < val.size(); ++i)
 {
  if (i == (val.size() - val.point_loc))
   {
    out << "."; 
   }
  out << val.digits[i];
 }
 return out;
}

