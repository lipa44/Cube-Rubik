#ifndef visualCube_h
#define visualCube_h

#include "CubeSettings.h"

// Colors
unsigned int colors[6] = {green, blue, yellow, white, orange, red};

class VisualCube {
private:
    unsigned char RGBColor[3];

public:
    //  Six cube's planes - six colors
    int color[6];
    // Size of edge
    GLfloat visualSize;

    void rotateORb() {
        int temp = color[5];
        color[5] = color[3];
        color[3] = color[4];
        color[4] = color[2];
        color[2] = temp;
    }

    void rotateRR() {
        int temp = color[5];
        color[5] = color[3];
        color[3] = color[4];
        color[4] = color[2];
        color[2] = temp;
    }

    void rotateGR() {
        int temp = color[2];
        color[2] = color[1];
        color[1] = color[3];
        color[3] = color[0];
        color[0] = temp;
    }

    void rotateGD() {
        int temp = color[0];
        color[0] = color[4];
        color[4] = color[1];
        color[1] = color[5];
        color[5] = temp;
    }

    void rotateGU() {
        int temp = color[0];
        color[0] = color[4];
        color[4] = color[1];
        color[1] = color[5];
        color[5] = temp;
    }

    void setColor(int i, int color) { this->color[i] = color; }

    // Change from 0xFF0000 to RGB - dividing color[i] into 3 components (R, G, B)
    unsigned char *getRGB(int i) {
        RGBColor[0] = color[i] >> 16;
        RGBColor[1] = color[i] >> 8;
        RGBColor[2] = color[i];
        return RGBColor;
    }

    /*** Rendering Cube ***/
    // Set colors and normal vectors
    void draw() {
        glPushMatrix();
        glBegin(GL_QUADS);

        // Top
        glColor3ubv(getRGB(0));
        glNormal3f(0, 0, 1);
        glVertex3f(visualSize, visualSize, visualSize);
        glVertex3f(0, visualSize, visualSize);
        glVertex3f(0, 0, visualSize);
        glVertex3f(visualSize, 0, visualSize);

        // Bottom
        glColor3ubv(getRGB(1));
        glNormal3f(0, 0, -1);
        glVertex3f(visualSize, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, visualSize, 0);
        glVertex3f(visualSize, visualSize, 0);

        // Front
        glColor3ubv(getRGB(2));
        glNormal3f(0, -1, 0);
        glVertex3f(visualSize, 0, visualSize);
        glVertex3f(0, 0, visualSize);
        glVertex3f(0, 0, 0);
        glVertex3f(visualSize, 0, 0);

        // Back
        glColor3ubv(getRGB(3));
        glNormal3f(0, 1, 0);
        glVertex3f(visualSize, visualSize, 0);
        glVertex3f(0, visualSize, 0);
        glVertex3f(0, visualSize, visualSize);
        glVertex3f(visualSize, visualSize, visualSize);

        // Left
        glColor3ubv(getRGB(4));
        glNormal3f(-1, 0, 0);
        glVertex3f(0, visualSize, visualSize);
        glVertex3f(0, visualSize, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, visualSize);

        // Right
        glColor3ubv(getRGB(5));
        glNormal3f(1, 0, 0);
        glVertex3f(visualSize, visualSize, 0);
        glVertex3f(visualSize, visualSize, visualSize);
        glVertex3f(visualSize, 0, visualSize);
        glVertex3f(visualSize, 0, 0);

        glEnd();
        glPopMatrix();
    }

    // Rendering Cube with offset by (x, y, z)
    void draw(double x, double y, double z) {
        glPushMatrix();
        glTranslated(x, y, z);
        draw();
        glPopMatrix();
    }

};

#endif /* visualCube_h */