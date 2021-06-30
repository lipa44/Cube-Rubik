#ifndef visualSettings_h
#define visualSettings_h

#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#define GLEW_STATIC

static int AMOUNT_OF_TESTS = 10000; // For SolveCubeArray in RubikCube.h

ifstream inputStream("input.txt");
ofstream outputStream("output.txt");

enum cubeColors {
    yellow = 0xFFD700,
    blue = 0x0000FF,
    green = 0x32CD32,
    red = 0xFF0000,
    orange = 0xFF8C00,
    white = 0xFFFFFF
};

const int ROTATE_SPEED_STEP = 10, ROTATE_START_VALUE = 30;
GLfloat CUBE_SIZE = 12;

// Projection of the angle of rotation  on the axis
int xRot = 25, yRot = -45;

// Translation by Z axis
GLfloat translateZ = -35;

#endif /* visualSettings_h */