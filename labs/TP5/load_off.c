#include <GL/glut.h>

#include <stdio.h>
#include <math.h>


unsigned int nbpoints, nbtriangles;

float* points; // liste des points du modèle
unsigned int* indices; // indices des points pour dessiner le modèle

float angle; // angle de rotation du modèle entre chaque image

float scale; // coefficient pour la mise à l'échelle du modèle
float x, y, z; // coordonnées du centre du modèle

/*
float max(float a, float b) {
  return a > b ? a : b;
}
*/

void displayFunc() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  glTranslatef(0, 0, -1); // translation pour placer le modèle devant le point de vue

  glScalef(scale, scale, scale); // mise à l'échelle du modèle
  glRotatef(angle, 0, 1, 0); // rotation du modèle

  glTranslatef(-x, -y, -z); // translation pour mettre le centre du modèle en (0, 0, 0)

  glDrawElements(GL_TRIANGLES, 3*nbtriangles, GL_UNSIGNED_INT, indices);

  glutSwapBuffers();

}


void loadMesh() {

  /**
  * Lecture du fichier .off et remplissage des tableaux de points et d'indices
  * 1. Lire les 3 premiers caractères "OFF".
  * 2. Lire les 3 unsigned int contenant le nombre de points, le nombre de faces, etc.
  * 3. Allouer les tableaux points et indices avec malloc.
  * 4. Remplir les tableaux.
  * 5. Fermer le fichier.
  * 6. Ca marche !!!
  */


  /**
  * Fin de la lecture et fermeture du fichier.
  */
  
  /**
   * calcul de la boîte englobante du modèle
   */

  float xmin, xmax, ymin, ymax, zmin, zmax;
  float dx, dy, dz;

  xmin = xmax = points[0];
  ymin = ymax = points[1];
  zmin = zmax = points[2];
  for(unsigned int i = 1 ; i < nbpoints ; ++i) {
    if(xmin > points[i*3]) xmin = points[i*3];
    if(xmax < points[i*3]) xmax = points[i*3];
    if(ymin > points[i*3+1]) ymin = points[i*3+1];
    if(ymax < points[i*3+1]) ymax = points[i*3+1];
    if(zmin > points[i*3+2]) zmin = points[i*3+2];
    if(zmax < points[i*3+2]) zmax = points[i*3+2];
  }

  // calcul du centre de la boîte englobante

  x = (xmax + xmin)/2.0f;
  y = (ymax + ymin)/2.0f;
  z = (zmax + zmin)/2.0f;

  // calcul des dimensions de la boîte englobante

  dx = xmax - xmin;
  dy = ymax - ymin;
  dz = zmax - zmin;

  // calcul du coefficient de mise à l'échelle

  scale = 1.0f/fmax(dx, fmax(dy, dz));

  printf("%f %f %f %f %f %f\n", xmin, xmax, ymin, ymax, zmin, zmax);
  printf("%f %f %f\n", x, y, z);

}


void idleFunc() {

  angle = angle>=360 ? 0 : angle + 0.05;

  glutPostRedisplay();

}


int main(int argc, char* argv[]) {

  glutInit(&argc, argv);

  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);

  // initialisation de l'affichage pour un buffer de couleurs RGBA + un buffer de profondeur + un double buffer
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

  glutCreateWindow("GLWindow");

  glutDisplayFunc(displayFunc);
  glutIdleFunc(idleFunc);

  loadMesh(); // chargement du modèle

  // définition de la projection, ici une perspective
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  gluPerspective(100, 1, 0.1, 200);

  glMatrixMode(GL_MODELVIEW);

  // activation du vertex array
  glEnableClientState(GL_VERTEX_ARRAY);

  // définition du vertex array
  glVertexPointer(3, GL_FLOAT, 3*sizeof(float), points);

  // mode fil de fer
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // activation du test de profondeur
  glEnable(GL_DEPTH_TEST);
  
  glutMainLoop();

  return 0;

}
