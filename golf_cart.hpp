//
//  golf_cart.hpp
//  2d_house
//
//  Created by Vidu Fernando on 2024-02-17.
//

//#ifndef golf_cart_hpp
//#define golf_cart_hpp
#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <GLUT/glut.h>
#include <math.h>
//#endif /* golf_cart_hpp */

void drawCubeMesh(float cubeSize, int width, int length){
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            glPushMatrix();
            glTranslatef(i * cubeSize, j * cubeSize, 0.0f);
            glutSolidCube(cubeSize);
            glPopMatrix();
        }
    }
}

void drawCylinder(float height, float r) {
    GLUquadric* quad = gluNewQuadric();
    gluCylinder(quad, r, r, height, 32, 32);
    gluDeleteQuadric(quad);
}

void drawSeatPlatform(int floorWidth){
    glPushMatrix();
    glScaled(1.5, 1.5, 1.5);
    glRotatef(270, 1.0, 0.0, 0.0);
    
    glColor3f(0.8, 0.8, 0.8);
    drawCubeMesh(0.5f, floorWidth, 15);
    
    glColor3f(0.4, 0.6, 0.8);
    glTranslatef(0.3f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, floorWidth, 5);
    
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, floorWidth, 5);
    
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, floorWidth, 5);
    
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, floorWidth, 5);
    
//    seat
    glTranslatef(0.0f, 0.0f, 0.5f);
    glColor3f(0.8, 0.8, 0.8);
    drawCubeMesh(0.5f, floorWidth, 5);
    
//    back floor
    glTranslatef(-2.5f, 0.0f, -2.5f);
//    glColor3f(0.4, 0.6, 0.8);
    drawCubeMesh(0.5f, floorWidth, 5);
    
    glColor3f(0.4, 0.6, 0.8);
    glPopMatrix();
}

void drawTire() {
    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);

//    glBindTexture(GL_TEXTURE_2D, textureID);
    glColor3f(0.0, 0.0, 0.0);
    glutSolidTorus(0.7, 2.0, 30, 30);
    
    glPushMatrix();
    glScaled(0.5, 0.5, 0.5);
    glColor3f(0.2, 0.2, 0.2);
    glutSolidTorus(0.7, 2.0, 30, 30);
    glPopMatrix();
    gluDeleteQuadric(quad);
    
}

void addWheels(){
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
//    back wheel front-view
    glTranslatef(-1.5f, -2.0f, 1.0f);
    drawTire();
    glPopMatrix();
    
//    front wheel front-view
    glPushMatrix();
    glTranslatef(12.0f, -2.0f, 0.3f);
    drawTire();
    glPopMatrix();
    
//    back wheel
    glPushMatrix();
    glTranslatef(-1.5f, -2.0f, -6.0f);
    drawTire();
    glPopMatrix();
    
//    front wheel
    glPushMatrix();
    glTranslatef(12.0f, -2.0f, -5.5f);
    drawTire();
    glPopMatrix();
    
}

void drawCartBackFront(){
    glPushMatrix();
    glScaled(1.5, 1.5, 1.5);
    glRotatef(270, 1.0, 0.0, 0.0);
    
    glTranslatef(-2.5f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, 1, 6);
    
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, 1, 6);
    
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, 1, 6);
    
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, 1, 6);
    glPopMatrix();
}

void drawCartBackRear(){
    glPushMatrix();
    glScaled(1.5, 1.5, 1.5);
    glRotatef(270, 1.0, 0.0, 0.0);
    
    glTranslatef(-2.5f, 3.5f, 0.5f);
    drawCubeMesh(0.5f, 1, 6);
    
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, 1, 6);

    glTranslatef(0.0f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, 1, 6);

    glTranslatef(0.0f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, 1, 6);
    glPopMatrix();
}

void drawFrontBox(float floorWidth){
    glPushMatrix();
    glScaled(1.5, 1.5, 1.5);
    glRotatef(270, 1.0, 0.0, 0.0);
    
    glColor3f(0.4, 0.6, 0.8);
    glTranslatef(7.5f, 0.0f, 0.0f);
    drawCubeMesh(0.5f, floorWidth, 5);
    
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, floorWidth, 5);
    
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, floorWidth, 5);
    
    glTranslatef(0.0f, 0.0f, 0.5f);
    drawCubeMesh(0.5f, floorWidth, 5);
    
//    steering wheel
    glRotatef(-45, 0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    drawCylinder(5.0f, 0.07f);
    
    glScalef(0.5, 0.5, 0.5);
    glTranslatef(0.0f, 0.0f, 10.0f);
    glutWireTorus(0.3, 2.0, 30, 30);
    
//    front roof support rod
    glRotatef(20, 0.0, 1.0, 0.0);
    glTranslatef(6.0f, 4.0f, -13.0f);
    drawCylinder(21.0f, 0.3f);
    
//    back roof support rod (rear)
    glRotatef(-150, 0.0, 1.0, 0.0);
    glTranslatef(24.0f, 3.0f, -16.5f);
    drawCylinder(15.0f, 0.3f);
    
//    back roof support rod (front)
    glTranslatef(0.0f, -6.5f, 0.0f);
    drawCylinder(15.0f, 0.3f);
    glPopMatrix();
}

void drawRoof(float floorWidth){
    glPushMatrix();
    glScaled(1.5, 1.5, 1.5);
    glRotatef(270, 1.0, 0.0, 0.0);
    glTranslatef(-2.0f, 0.0f, 10.0f);
    glColor3f(0.4, 0.6, 0.8);
    drawCubeMesh(0.5f, floorWidth, 15);
    glPopMatrix();
}

void drawCart(int floorWidth){
    drawSeatPlatform(floorWidth);
    drawCartBackFront();
    drawCartBackRear();
    drawFrontBox(floorWidth);
    drawRoof(floorWidth);
    addWheels();
}
