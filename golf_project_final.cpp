//
//  golf_project_final.cpp
//  Golf_Course
//
//  Created by Vidu Fernando on 2024-02-16.
//

#include "golf_project_final.hpp"
#include "golf_cart.hpp"
#include "grass_field.hpp"
#include "golf_ball.hpp"
#include "flag.hpp"
#include "skybox.hpp"

#define GL_SILENCE_DEPRECATION

//#include <windows.h> //Optional
////#include <GL/glut.h>
#include <GLUT/glut.h>
#include <math.h>
#include <SOIL2/SOIL2.h>
#include <stdio.h>
#include <iostream>

float sceZ = 0;
float sceX = 0;
float sceY = 0;
float sceR = 0;
float camX = 0;
float camY = 2;
float camZ = 5;
float cartX = -60.0f;
float cartZ = 0.0f;
float cartR = 0.0f;
bool animateBall = false;
float ballX = 2.0f;
float ballY = 1.0f;
float ballZ = 1.0f;
float ballHeight = 10.0f;
float ballSpeed = 1.0f;

int animationFactor = 0;

GLfloat skyBoxSize = 150;

GLfloat ballTextureId;
GLfloat sandTextureId;
GLfloat grassTextureId;
GLfloat grassTexture2Id;
GLfloat grassTexture3Id;
GLfloat leftTextureId;
GLfloat rightTextureId;
GLfloat backTextureId;
GLfloat frontTextureId;
GLfloat upTextureId;
GLfloat downTextureId;

#define IMAGE_ROWS 64
#define IMAGE_COLS 64

GLubyte imageData[IMAGE_ROWS][IMAGE_COLS][3];

GLubyte image;

float width;
float height;

void loadGrassTexture(){
    grassTextureId = SOIL_load_OGL_texture(
        "/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/grass_texture.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!grassTextureId) {
        printf("Grass texture loading failed: %s\n", SOIL_last_result());
    }
}

void loadGrassTexture2(){
    grassTexture2Id = SOIL_load_OGL_texture("/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/grass_texture2.jpeg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!grassTextureId) {
        printf("Grass texture2 loading failed: %s\n", SOIL_last_result());
    }
}

void loadGrassTexture3(){
    grassTexture3Id = SOIL_load_OGL_texture("/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/grass_texture3.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!grassTextureId) {
        printf("Grass texture3 loading failed: %s\n", SOIL_last_result());
    }
}

void loadBallTexture() {
    ballTextureId = SOIL_load_OGL_texture(
        "/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/golf_texture.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!ballTextureId) {
        printf("Ball texture loading failed: %s\n", SOIL_last_result());
    }
}

void loadSandTexture(){
    sandTextureId = SOIL_load_OGL_texture(
        "/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/sand_texture.jpg",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!sandTextureId) {
        printf("Sand texture loading failed: %s\n", SOIL_last_result());
    }
}

void loadTextureLeft(){
    leftTextureId = SOIL_load_OGL_texture(
        "/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/left.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!leftTextureId) {
        printf("Left texture loading failed: %s\n", SOIL_last_result());
    }
}

void loadTextureRight(){
    rightTextureId = SOIL_load_OGL_texture(
        "/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/right.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!rightTextureId) {
        printf("Right texture loading failed: %s\n", SOIL_last_result());
    }
}

void loadTextureBack(){
    backTextureId = SOIL_load_OGL_texture(
        "/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/back.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!backTextureId) {
        printf("Back texture loading failed: %s\n", SOIL_last_result());
    }
}

void loadTextureFront(){
    frontTextureId = SOIL_load_OGL_texture(
        "/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/front.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!frontTextureId) {
        printf("Front texture loading failed: %s\n", SOIL_last_result());
    }
}

void loadTextureUp(){
    upTextureId = SOIL_load_OGL_texture(
        "/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/up.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!upTextureId) {
        printf("Front texture loading failed: %s\n", SOIL_last_result());
    }
}

void setLighting() {
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    
    GLfloat ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    GLfloat L0pos[] = { 0, 5, 5, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, L0pos);

    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specular);

    GLfloat L1pos[] = { 0, 5, -15, 0.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, L1pos);
}

void init() {
    glClearColor(0.34f, 0.79f, 0.9f, 1.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glShadeModel(GL_SMOOTH);

    loadBallTexture();
    loadSandTexture();
    loadGrassTexture();
    loadGrassTexture2();
    loadGrassTexture3();
    loadTextureLeft();
    loadTextureRight();
    loadTextureBack();
    loadTextureFront();
    loadTextureUp();
    setLighting();
}

void drawAxes() {
    glBegin(GL_LINES);
    glLineWidth(1.5);
//  x-axis
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-20, 0, 0);
    glVertex3f(20, 0, 0);
//  y-axis
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, -20, 0);
    glVertex3f(0, 20, 0);
//  z-axis
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, -20);
    glVertex3f(0, 0, 20);
    glEnd();
}

void drawGrid() {
    GLfloat ext = 20.0f;
    GLfloat step = 1.0f;
    GLfloat yGrid = -0.4f;
    GLint line;
    glBegin(GL_LINES);
    for (line = -ext; line <= ext; line += step) {
        glVertex3f(line, yGrid, ext);
        glVertex3f(line, yGrid, -ext);
        glVertex3f(ext, yGrid, line);
        glVertex3f(-ext, yGrid, line);
    }
    glEnd();
}

void updateBallPosition() {
    if (animateBall) {
        ballY = ballHeight * sin(ballX);
        ballX += ballSpeed;
        
        if (ballX >= M_PI) {
            animateBall = false;
            ballY = 0.0f;
            ballX = 70.0f;
            ballZ = 58.0f;
        }
    }
}

void drawStickBody(){
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(2.0f, 0.0f);
    glVertex2f(3.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    gluLookAt(0.0 + camX, 0.0 + camY, 0.0 + camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glTranslatef(sceX, sceY, sceZ);
    glRotatef(sceR*5, 0.0, 1.0, 0.0);
    
    
//    ************ SKYBOX ************
    glPushMatrix();
    glTranslated(0.0, 0.0, 40.0);
// front
    glPushMatrix();
    glTranslatef(skyBoxSize/2, skyBoxSize, -skyBoxSize/2);
    glRotatef(-180, 0.0, 1.0, 0.0);
    glBindTexture(GL_TEXTURE_2D, frontTextureId);
    drawSquare(skyBoxSize);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

////    right
    glPushMatrix();
    glRotatef(-90, 0.0, 1.0, 0.0);
    glTranslatef(-skyBoxSize/2, skyBoxSize, skyBoxSize/2);
    glBindTexture(GL_TEXTURE_2D, rightTextureId);
    drawSquare(skyBoxSize);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

//    left
    glPushMatrix();
    glRotatef(90, 0.0, 1.0, 0.0);
    glTranslatef(-skyBoxSize/2, skyBoxSize, skyBoxSize/2);
    glBindTexture(GL_TEXTURE_2D, leftTextureId);
    drawSquare(skyBoxSize);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

//    back
    glPushMatrix();
    glTranslatef(-skyBoxSize/2, skyBoxSize, skyBoxSize/2);
    glBindTexture(GL_TEXTURE_2D, backTextureId);
    drawSquare(skyBoxSize);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
    
//    up
    glPushMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(-skyBoxSize/2, skyBoxSize/2, -skyBoxSize);
    glBindTexture(GL_TEXTURE_2D, upTextureId);
    drawSquareUp(skyBoxSize);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
    
////    down
//    glPushMatrix();
//    glRotatef(90, 1.0, 0.0, 0.0);
//    glTranslatef(-skyBoxSize/2, skyBoxSize/2, skyBoxSize);
//    glBindTexture(GL_TEXTURE_2D, upTextureId);
//    drawSquareUp(skyBoxSize);
//    glBindTexture(GL_TEXTURE_2D, 0);
//    glPopMatrix();
    
    glPopMatrix();

//    ***********************************
    
//    grass path box
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, grass);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cartDiffiuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, grass);
    glMaterialf(GL_FRONT, GL_SHININESS, 50);
    
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslated(-80.0f, 120.0f, 0.3f);
    glBindTexture(GL_TEXTURE_2D, grassTexture3Id);
    drawSquare(200);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
    
//    dark grass patch 1
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, grass);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cartDiffiuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, grass);
    glMaterialf(GL_FRONT, GL_SHININESS, 50);

    glBindTexture(GL_TEXTURE_2D, grassTexture2Id);
    drawOval(50, 85, 65);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

//    dark grass patch 2
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, grass);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cartDiffiuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, grass);
    glMaterialf(GL_FRONT, GL_SHININESS, 50);

    glBindTexture(GL_TEXTURE_2D, grassTexture2Id);
    glTranslatef(65.0f, 0.0f, 60.0f);
    drawOval(50, 60, 50);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

//    light grass patch 1
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, grassLight);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cartDiffiuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, grassLight);
    glMaterialf(GL_FRONT, GL_SHININESS, 5);

    glBindTexture(GL_TEXTURE_2D, grassTextureId);
    glTranslatef(15.0f, 0.1f, -10.0f);
    drawOval(30, 60.0f, 50.0f);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

//    light grass patch 2
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, grassLight);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cartDiffiuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, grassLight);
    glMaterialf(GL_FRONT, GL_SHININESS, 5);

    glBindTexture(GL_TEXTURE_2D, grassTextureId);
    glTranslatef(70.0f, 0.1f, 55.0f);
    drawOval(30, 50.0f, 40.0f);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

//    sand patch
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, sand);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cartDiffiuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, sand);
    glMaterialf(GL_FRONT, GL_SHININESS, 10);

    glBindTexture(GL_TEXTURE_2D, sandTextureId);
    glTranslatef(40.0f, 0.2f, -40.0f);
    drawOval(15, 11, 4);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

//    flag
    glPushMatrix();
    glTranslatef(70.0f, 16.0f, 58.0f);
    glScalef(5.0f, 5.0f, 5.0f);
    drawFlag();
    glPopMatrix();

//    golf cart
    glPushMatrix();
    glTranslatef(cartX, 4.0f, cartZ);
    glRotatef(cartR*5, 0.0, 1.0, 0.0);
    glScalef(0.8f, 0.8f, 0.8f);
    drawCart(8);
    glPopMatrix();

//    golf ball
    glPushMatrix();
//    glTranslatef(2.0f, 1.0f, 1.0f);
    glTranslatef(ballX, ballY, ballZ);
    glBindTexture(GL_TEXTURE_2D, ballTextureId);
    drawBall(1.0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();

//    golf stick
    GLfloat stickBody[] = {0.22, 0.23, 0.27, 1.0};
    GLfloat stick[] = {0.53, 0.54, 0.54, 1.0};
    GLfloat stickDiffuse[] = {0.2, 0.2, 0.2, 1.0};

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, stickBody);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, stickDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, stickBody);
    glMaterialf(GL_FRONT, GL_SHININESS, 200);

    glColor3f(0.22, 0.23, 0.27);
    drawStickBody();
    glTranslatef(2.5, 10.0f, -0.2);
    glRotatef(90, 1.0, 0.0, 0.0);

    glMaterialfv(GL_FRONT, GL_AMBIENT, stick);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, stickDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, stick);
    glMaterialf(GL_FRONT, GL_SHININESS, 200);
    glColor3f(0.53, 0.54, 0.54);
    drawCylinder(10.0f, 0.3f);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
    animationFactor += 5;
}

void keyboardSpecial(int key, int x, int y) {
    if (key == GLUT_KEY_UP)
            camY += 1;
    if (key == GLUT_KEY_DOWN)
            camY -= 1;
    if (key == GLUT_KEY_RIGHT)
            camX += 1;
    if (key == GLUT_KEY_LEFT)
            camX -= 1;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'z')
        sceZ++;
    if (key == 'Z')
        sceZ--;
    if (key == 'x')
        sceX++;
    if (key == 'X')
        sceX--;
    if (key == 'y')
        sceY++;
    if (key == 'Y')
        sceY--;
    if (key == 'r')
        sceR++;
    if (key == 'R')
        sceR--;
    
    if (key == 'w')
        cartX++;
    if (key == 's')
        cartX--;
    if (key == 'a')
        cartR++;
    if (key == 'd')
        cartR--;
    if(key == 'q'){
        cartX = -60;
        cartR = 0;
        ballX = 2.0f;
        ballY = 1.0f;
        ballZ =1.0f;
    }
    if (key == 'p') {
            animateBall = true;
        }
    
    glutPostRedisplay();
}

void Timer(int x) {
    updateBallPosition();
    glutPostRedisplay();
    glutTimerFunc(60, Timer, 0);
}

void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    define the perspective projection frustum
//    (FOV_in_vertical, aspect_ratio, z-distance to the near plane from the camera position, z-distance to far plane from the camera position)
    gluPerspective(120.0, aspect_ratio, 1.0, 700.0);

}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(2000, 2000);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("Project output");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecial);
    glutTimerFunc(60.0, Timer, 1);
    init();
    glutMainLoop();
    return 0;
}
