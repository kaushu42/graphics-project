#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <vector>
#include "containers.h"
#define PI 3.14159
#define PI180 PI/180
float angleZ = 0, angleX = 0, angleY = 0;
char title[] = "3D Shapes with animation";

//Matrices for rotation along each axis
Matrix44f matZ, matX, matY;
Matrix44f matIdentity(1, 0, 0, 0,
  0, 1, 0, 0,
  0, 0, 1, 0,
  0, 0, 0, 1);
Matrix44f mat = matIdentity;

//The vertices for the object
float vertices[][3] = {{0.5f, 2, 0.5f},{0, 0, 0}, {1, 0, 0}, {0, 0, 1},
                      {1, 0, 1}};

//Vector to hold all vectors
std::vector<Vec3f> v;

//Draw a point
void point(float x, float y){
  glBegin(GL_POINTS);
    glVertex2f(x, y);
  glEnd();
}
//Draw a line
void line(float x, float y, float x1, float y1){
  glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x1, y1);
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
  glColor3f(0, 0, 1);
  auto t = mat * v[0];//TOP
  auto s = mat * v[1];///000
  line(t.x, t.y, s.x, s.y);
  s = mat * v[2];
  line(t.x, t.y, s.x, s.y);
  s = mat * v[3];
  line(t.x, t.y, s.x, s.y);
  s = mat * v[4]; //101
  line(t.x, t.y, s.x, s.y);
  t = mat * v[3];
  line(t.x, t.y, s.x, s.y);
  t = mat * v[2];//100
  line(t.x, t.y, s.x, s.y);
  s = mat * v[1];//000
  line(t.x, t.y, s.x, s.y);
  t = mat * v[3];//100
  line(t.x, t.y, s.x, s.y);
  glFlush();
 glutSwapBuffers();
}

void keyPress(unsigned char key, int x, int y){
  if(key == 'a'){
    angleZ += 5;
    mat = matZ;
  }else if(key == 'd'){
    angleZ -= 5;
    mat = matZ;
  }else if(key == 's'){
    angleX -= 5;
    mat = matX;
  }else if(key == 'w'){
    angleX += 5;
    mat = matX;
  }else if(key == 'q'){
    angleY += 5;
    mat = matY;
  }else if(key == 'e'){
    angleY -= 5;
    mat = matY;
  }else if(key == 27){
    exit(0);
  }
  if(angleX > 360) angleX = 0;
  if(angleX < 0) angleX = 360;
  if(angleZ > 360) angleZ = 0;
  if(angleZ < 0) angleX = 360;
  if(angleY > 360) angleY = 0;
  if(angleY < 0) angleY = 360;
  //Matrix for rotation along X
  matX = Matrix44f(1, 0, 0, 0,
              0, cos(PI180 * angleX), sin(PI180 * angleX), 0,
              0, -sin(PI180 * angleX), cos(PI180 * angleX), 0,
              0, 0, 0, 1);
  //Matrix for rotation along Y
  matY = Matrix44f(cos(PI180 * angleY), 0, -sin(PI180 * angleX), 0,
              0, 1, 0, 0,
              sin(PI180 * angleX), 0, cos(PI180 * angleX), 0,
              0, 0, 0, 1);
  //Matrix for rotation along Z
  matZ = Matrix44f(cos(PI180 * angleZ), sin(PI180 * angleZ), 0, 0,
              -sin(PI180 * angleZ), cos(PI180 * angleZ), 0, 0,
              0, 0, 1, 0,
              0, 0, 0, 1);
  glutPostRedisplay();
}
int main(int argc, char** argv) {
  //Push all the vertices to a vector of Vec3f
  for (size_t i = 0; i < 8; i++) {
    Vec3f j(vertices[i][0], vertices[i][1], vertices[i][2]);
    v.push_back(j);
  }
  //Initialize OpenGL and GLUT
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
  glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
  glEnable(GL_MULTISAMPLE);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(50, 50);
  glutCreateWindow(title);
  glutDisplayFunc(display);
  //Handle the keypress using this function
  glutKeyboardFunc(keyPress);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
  glClearDepth(1.0f);
  //glOrtho sets the range of coordinates shown on the screen
  //For example, here x, y, z all range from -5 to +5
  //Format is glOrtho(-x, +x, -y, +y, -z, +z)
  glOrtho(-5, 5, -5, 5, -5, 5);
  glutMainLoop();
  return 0;
}
