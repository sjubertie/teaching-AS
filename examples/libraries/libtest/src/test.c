#include <test.h>

unsigned int fact( unsigned int n )
{
  return n < 2 ? 1 : n * fact( n - 1 );
}

unsigned int fois2( unsigned int n ) {
  return n * 2;
}
