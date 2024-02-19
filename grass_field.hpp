//
//  grass_field.hpp
//  Golf_Course
//
//  Created by Vidu Fernando on 2024-02-17.
//


#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <GLUT/glut.h>
#include <math.h>
#include <iostream>

GLfloat grass[] = {0.44, 0.66, 0.17, 1.0};
GLfloat grassLight[] = {0.66, 0.85, 0.11, 1.0};
GLfloat sand[] = {1.0, 0.9, 0.7, 1.0};

void drawOval(int numVertices, float width, float height) {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);
    glRotatef(90, 1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    
    // Center vertex
    glTexCoord2f(0.5f, 0.5f);
    glVertex2f(0.0f, 0.0f);
    
    for (int i = 0; i <= numVertices; ++i) {
        float angle = 2.0f * M_PI * i / numVertices;
        float x = width * cos(angle);
        float y = height * sin(angle);
        glTexCoord2f((x + width) / (2 * width), (y + height) / (2 * height));
        glVertex2f(x, y);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
}

//void drawOval2(int numVertices, float width, float height) {
//    glTranslatef(0.0f, 0.1f, 0.0f);
//    glRotatef(90, 1.0, 0.0, 0.0);
//
//    glColor3f(1.0, 0.9, 0.7);
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex2f(0.0f, 0.0f);
//
//    for (int i = 0; i <= numVertices; ++i) {
//        float angle = 2.0f * M_PI * i / numVertices;
//        float x = width * cos(angle);
//        float y = height * sin(angle);
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
