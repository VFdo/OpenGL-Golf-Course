//
//  golf_project_final.cpp
//  2d_house
//
//  Created by Vidu Fernando on 2024-02-16.
//

#include "golf_project_final.hpp"
#include "golf_cart.hpp"
#include "grass_field.hpp"
#include "golf_ball.hpp"
#include "flag.hpp"

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

int animationFactor = 0;

GLfloat grassTextureId;
GLfloat ballTextureId;
GLfloat sandTextureId;


GLuint textureID;

#define IMAGE_ROWS 64      // Texture image rows and columns
#define IMAGE_COLS 64

GLubyte imageData[IMAGE_ROWS][IMAGE_COLS][3];

GLubyte image;

float width;
float height;

void loadTexture() {
    textureID = SOIL_load_OGL_texture(
        "/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/2d_house/2d_house/barbers_pole_texture.jpg",  // Replace with the path to your texture file
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!textureID) {
        printf("Texture loading failed: %s\n", SOIL_last_result());
    }
}

void loadGrassTexture(){
    grassTextureId = SOIL_load_OGL_texture(
                                           "/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/grass_texture2.jpeg",
//        "/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/grass_texture.jpg",  // Replace with the path to your texture file
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!grassTextureId) {
        printf("Grass texture loading failed: %s\n", SOIL_last_result());
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
        "/Users/vidufernando/Documents/me/Y3/CS308/graphics_lab/project/sand_texture.jpg",  // Replace with the path to your texture file
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y
    );

    if (!sandTextureId) {
        printf("Sand texture loading failed: %s\n", SOIL_last_result());
    }
}

//void loadTextureDataFromImage() {
//    image = SOIL_load_image("gizapyamid_texture.jpg", &width, &height, 0, SOIL_LOAD_RGB);
//
//    if (image == NULL) {
//        printf("Error : %s", SOIL_last_result());
//    }
//}
//
//void loadTextures() {
//    loadTextureImageData();   // Load pattern into image data array
//    glGenTextures(1, &textureID);
//    glBindTexture(GL_TEXTURE_2D, textureID);
//    glTexImage2D(GL_TEXTURE_2D, 0, 3, IMAGE_COLS, IMAGE_ROWS, 0, GL_RGB,
//        GL_UNSIGNED_BYTE, imageData);  // Create texture from image data
//    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//}

void init() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClearDepth(1.0);
//    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
//    loadTexture();
    loadBallTexture();
    loadSandTexture();
    loadGrassTexture();
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

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
//    camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
    gluLookAt(0.0 + camX, 0.0 + camY, 0.0 + camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//  move the whole scene
    glTranslatef(sceX, sceY, sceZ);
    glRotatef(sceR*5, 0.0, 1.0, 0.0);
    
//    ****** COMPLETED ******
//    drawGrid();
//    drawAxes();
//    drawCart(8);
//    glPushMatrix();
    
//    glPopMatrix();
//    drawBall(5.0, ballTextureId);
//    drawFlag();
//    **********************
        
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, grassTextureId);
    drawOval(30, 50.0f, 40.0f);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
    
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, sandTextureId);
    glTranslatef(0.0f, 0.2f, 0.0f);
    drawOval(50, 10, 5);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, 16.0f, 3.0f);
    glScalef(5.0f, 5.0f, 5.0f);
    drawFlag();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    drawCart(8);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 5.0f);
    glBindTexture(GL_TEXTURE_2D, ballTextureId);
    drawBall(1.0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
    
    glColor3f(1.0, 1.0, 1.0);

    
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
    glutPostRedisplay();
}

void Timer(int x) {
    glutPostRedisplay();
    glutTimerFunc(60, Timer, 1);
}

void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    define the perspective projection frustum
//    (FOV_in_vertical, aspect_ratio, z-distance to the near plane from the camera position, z-distance to far plane from the camera position)
    gluPerspective(120.0, aspect_ratio, 1.0, 100.0);

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(1000, 1000);
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
