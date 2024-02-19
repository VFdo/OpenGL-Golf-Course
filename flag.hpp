//
//  flag.hpp
//  Golf_Course
//
//  Created by Vidu Fernando on 2024-02-17.
//

#define GL_SILENCE_DEPRECATION

#include <stdio.h>
#include <GLUT/glut.h>

GLfloat flagBlack[] = {0.0, 0.0, 0.0, 1.0};
GLfloat flagWhite[] = {1.0, 1.0, 1.0, 1.0};
GLfloat flagDiffiuse[] = {0.2, 0.2, 0.2, 1.0};


void drawTriangle() {
    glMaterialfv(GL_FRONT, GL_AMBIENT, flagWhite);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, flagDiffiuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, flagWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 20);
    
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.8f, 0.0f);
    glVertex3f(0.8f, 0.4f, 0.0f);
    glEnd();
}

void drawFlag(){
    glPushMatrix();
    drawTriangle();
    glTranslatef(0.0f, 0.75f, 0.0f);
    glRotatef(95, 1.0, 0.0, 0.0);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, flagBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, flagDiffiuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, flagBlack);
    glMaterialf(GL_FRONT, GL_SHININESS, 20);
    glColor3f(0.0, 0.0, 0.0);
    drawCylinder(1.0f, 0.05f);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, flagWhite);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, flagDiffiuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, flagWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 20);
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0f, 0.0f, 1.0f);
    drawCylinder(1.0f, 0.05f);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, flagBlack);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, flagDiffiuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, flagBlack);
    glMaterialf(GL_FRONT, GL_SHININESS, 20);
    glTranslatef(0.0f, 0.0f, 1.0f);
    glColor3f(0.0, 0.0, 0.0);
    drawCylinder(1.0f, 0.05f);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, flagWhite);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, flagDiffiuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, flagWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 20);
    glTranslatef(0.0f, 0.0f, 1.0f);
    glColor3f(1.0, 1.0, 1.0);
    drawCylinder(1.0f, 0.05f);
    glPopMatrix();
    
}
