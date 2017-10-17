#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>

#include <math.h>

#include <IL/il.h>


int main() {

  unsigned int images[ 2 ];

  ilInit();

  ilGenImages(2, images);
  ilBindImage(images[ 0 ]);
  ilLoadImage("in.jpg");

  int width, height, bpp, format, line;

  width = ilGetInteger(IL_IMAGE_WIDTH);
  height = ilGetInteger(IL_IMAGE_HEIGHT); 
  bpp = ilGetInteger(IL_IMAGE_BYTES_PER_PIXEL);
  format = ilGetInteger(IL_IMAGE_FORMAT);

  // Récupération des données de l'image
  unsigned char* data = ilGetData();

  unsigned char * out = (unsigned char*)malloc( width*height );
  
  unsigned int i, j, p, c;
  p=0;
  struct timeval start, stop;

  gettimeofday(&start, 0);

  for( j = 0 ; j < height ; ++j )
  {
    for( i = 0 ; i < width ; ++i, p+=3 )
    {
      c = (data[p] * 307 + data[p + 1] * 604 + data[p + 2] * 113) >> 10;
      out[ ( height -1 - j ) * width + i ] = c;
    }
  }

  gettimeofday(&stop, 0);

  printf("time %li\n", (stop.tv_sec*1000000+stop.tv_usec) - (start.tv_sec*1000000+start.tv_usec));

  //Placement des données dans l'image de sortie.

  ilBindImage( images[ 1 ] );
  ilTexImage( width, height, 1, 1, IL_LUMINANCE, IL_UNSIGNED_BYTE, out );

  // Sauvegarde de l'image

  ilEnable(IL_FILE_OVERWRITE);

  ilSaveImage("out.jpg");
  
  ilDeleteImages(2, images); 

  free( out );

}
