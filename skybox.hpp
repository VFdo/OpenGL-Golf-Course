//
//  skybox.hpp
//  Golf_Course
//
//  Created by Vidu Fernando on 2024-02-18.
//


#define GL_SILENCE_DEPRECATION

//#include <windows.h> //Optional
//#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <GLUT/glut.h>

void drawSquare(float size) {
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_POLYGON);
    glTexCoord2d(1.0, 1.0);glVertex3d(0.0, 0.0, 0.0);
    glTexCoord2d(0.0, 1.0);glVertex3d(size, 0.0, 0.0);
    glTexCoord2d(0.0, 0.0);glVertex3d(size, -size, 0.0);
    glTexCoord2d(1.0, 0.0);glVertex3d(0.0, -size, 0.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void drawSquareUp(float size) {
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);glVertex3d(0.0, 0.0, 0.0);
    glTexCoord2d(0.0, 1.0);glVertex3d(size, 0.0, 0.0);
    glTexCoord2d(1.0, 1.0);glVertex3d(size, -size, 0.0);
    glTexCoord2d(1.0, 0.0);glVertex3d(0.0, -size, 0.0);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}
