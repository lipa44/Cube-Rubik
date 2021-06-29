#include "Cube/RubikCube.h"
#include "Cube/VisualFunctions.h"
#include "Other/GLUTMenu.h"

extern RubikCube Cube; // Do not delete, it uses in headers

int main(int argc, char *argv[]) {
    srand(time(NULL));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(480, 800);
    glutInitWindowPosition(1, 1);
    glutCreateWindow("Rubik's Cube");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(5, timer, 0);
    glutSpecialFunc(specialKeys);
    createGLUTMenus();
    glutMainLoop();

    return 0;
}