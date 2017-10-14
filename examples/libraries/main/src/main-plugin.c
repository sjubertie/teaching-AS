#include <test.h>

#include <stdio.h>

#include <dlfcn.h>


int main()
{
  unsigned int (*fact)( unsigned int );
  char * err;
  void * handle = dlopen( "libtest.so", RTLD_LAZY );
  if( handle )
  {
    fact = dlsym( handle, "fact" );
    if( !(err = dlerror() ) )
    {
      printf( "fact( %u ) = %u\n", 5, fact( 5 ) );
    }
    else
    {
      printf( "Error: %s\n", err );
    }	 
  }
  else
  {
    puts( "Error: unable to open libtest.so." );
  }
  
  return 0;
}
