//
//  flag.hpp
//  2d_house
//
//  Created by Vidu Fernando on 2024-02-17.
//

//#ifndef flag_hpp
//#define flag_hpp

//#include "golf_cart.hpp"


#define GL_SILENCE_DEPRECATION

#include <stdio.h>
#include <GLUT/glut.h>

//#endif /* flag_hpp */

void drawTriangle() {
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
    glRotatef(90, 1.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    drawCylinder(1.0f, 0.05f);
    
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0f, 0.0f, 1.0f);
    drawCylinder(1.0f, 0.05f);
    
    glTranslatef(0.0f, 0.0f, 1.0f);
    glColor3f(0.0, 0.0, 0.0);
    drawCylinder(1.0f, 0.05f);
    
    glTranslatef(0.0f, 0.0f, 1.0f);
    glColor3f(1.0, 1.0, 1.0);
    drawCylinder(1.0f, 0.05f);
    glPopMatrix();
}
