#include "test.h"

int quaranteDeux()
{
  return 42;
}

int fact(int n)
{
  return n <= 1 ? 1 : n * fact( n-1 );
}
