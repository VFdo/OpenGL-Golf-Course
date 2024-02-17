//
//  golf_project_final.cpp
//  2d_house
//
//  Created by Vidu Fernando on 2024-02-16.
//

#include "golf_project_final.hpp"
#include "golf_cart.hpp"

#define GL_SILENCE_DEPRECATION

//#include <windows.h> //Optional
////#include <GL/glut.h>
#include <GLUT/glut.h>
#include <math.h>
#include <SOIL2/SOIL2.h>

float sceZ = 0;
float sceX = 0;
float sceY = 0;
float sceR = 0;
float camX = 0;
float camY = 2;
float camZ = 5;

int animationFactor = 0;
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
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    loadTexture();
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

//void drawCubeMesh(float cubeSize, int width, int length){
//    for (int i = 0; i < length; i++) {
//        for (int j = 0; j < width; j++) {
//            glPushMatrix();
//            glTranslatef(i * cubeSize, j * cubeSize, 0.0f);
//            glutSolidCube(cubeSize);
//            glPopMatrix();
//        }
//    }
//}
//
//void drawCylinder(float height, float r) {
//    GLUquadric* quad = gluNewQuadric();
//    gluCylinder(quad, r, r, height, 32, 32);
//    gluDeleteQuadric(quad);
//}
//
//void drawSeatPlatform(int floorWidth){
//    glPushMatrix();
//    glScaled(1.5, 1.5, 1.5);
//    glRotatef(270, 1.0, 0.0, 0.0);
//    
//    glColor3f(0.8, 0.8, 0.8);
//    drawCubeMesh(0.5f, floorWidth, 15);
//    
//    glColor3f(0.4, 0.6, 0.8);
//    glTranslatef(0.3f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, floorWidth, 5);
//    
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, floorWidth, 5);
//    
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, floorWidth, 5);
//    
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, floorWidth, 5);
//    
////    seat
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    glColor3f(0.8, 0.8, 0.8);
//    drawCubeMesh(0.5f, floorWidth, 5);
//    
////    back floor
//    glTranslatef(-2.5f, 0.0f, -2.5f);
////    glColor3f(0.4, 0.6, 0.8);
//    drawCubeMesh(0.5f, floorWidth, 5);
//    
//    glColor3f(0.4, 0.6, 0.8);
//    glPopMatrix();
//}
//
//void drawTire() {
//    GLUquadric* quad = gluNewQuadric();
//    gluQuadricTexture(quad, GL_TRUE);
//
//    glBindTexture(GL_TEXTURE_2D, textureID);
//    glColor3f(0.0, 0.0, 0.0);
//    glutSolidTorus(0.7, 2.0, 30, 30);
//    
//    glPushMatrix();
//    glScaled(0.5, 0.5, 0.5);
//    glColor3f(0.2, 0.2, 0.2);
//    glutSolidTorus(0.7, 2.0, 30, 30);
//    glPopMatrix();
//    gluDeleteQuadric(quad);
//    
//}
//
//void addWheels(){
//    glPushMatrix();
//    glColor3f(0.0, 0.0, 0.0);
////    back wheel front-view
//    glTranslatef(-1.5f, -2.0f, 1.0f);
//    drawTire();
//    glPopMatrix();
//    
////    front wheel front-view
//    glPushMatrix();
//    glTranslatef(12.0f, -2.0f, 0.3f);
//    drawTire();
//    glPopMatrix();
//    
////    back wheel
//    glPushMatrix();
//    glTranslatef(-1.5f, -2.0f, -6.0f);
//    drawTire();
//    glPopMatrix();
//    
////    front wheel
//    glPushMatrix();
//    glTranslatef(12.0f, -2.0f, -5.5f);
//    drawTire();
//    glPopMatrix();
//    
//}
//
//void drawCartBackFront(){
//    glPushMatrix();
//    glScaled(1.5, 1.5, 1.5);
//    glRotatef(270, 1.0, 0.0, 0.0);
//    
//    glTranslatef(-2.5f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, 1, 6);
//    
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, 1, 6);
//    
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, 1, 6);
//    
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, 1, 6);
//    glPopMatrix();
//}
//
//void drawCartBackRear(){
//    glPushMatrix();
//    glScaled(1.5, 1.5, 1.5);
//    glRotatef(270, 1.0, 0.0, 0.0);
//    
//    glTranslatef(-2.5f, 3.5f, 0.5f);
//    drawCubeMesh(0.5f, 1, 6);
//    
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, 1, 6);
//
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, 1, 6);
//
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, 1, 6);
//    glPopMatrix();
//}
//
//void drawFrontBox(float floorWidth){
//    glPushMatrix();
//    glScaled(1.5, 1.5, 1.5);
//    glRotatef(270, 1.0, 0.0, 0.0);
//    
//    glColor3f(0.4, 0.6, 0.8);
//    glTranslatef(7.5f, 0.0f, 0.0f);
//    drawCubeMesh(0.5f, floorWidth, 5);
//    
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, floorWidth, 5);
//    
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, floorWidth, 5);
//    
//    glTranslatef(0.0f, 0.0f, 0.5f);
//    drawCubeMesh(0.5f, floorWidth, 5);
//    
////    steering wheel
//    glRotatef(-45, 0.0, 1.0, 0.0);
//    glColor3f(0.0, 0.0, 0.0);
//    drawCylinder(5.0f, 0.07f);
//    
//    glScalef(0.5, 0.5, 0.5);
//    glTranslatef(0.0f, 0.0f, 10.0f);
//    glutWireTorus(0.3, 2.0, 30, 30);
//    
////    front roof support rod
//    glRotatef(20, 0.0, 1.0, 0.0);
//    glTranslatef(6.0f, 4.0f, -13.0f);
//    drawCylinder(21.0f, 0.3f);
//    
////    back roof support rod (rear)
//    glRotatef(-150, 0.0, 1.0, 0.0);
//    glTranslatef(24.0f, 3.0f, -16.5f);
//    drawCylinder(15.0f, 0.3f);
//    
////    back roof support rod (front)
//    glTranslatef(0.0f, -6.5f, 0.0f);
//    drawCylinder(15.0f, 0.3f);
//    glPopMatrix();
//}
//
//void drawRoof(float floorWidth){
//    glPushMatrix();
//    glScaled(1.5, 1.5, 1.5);
//    glRotatef(270, 1.0, 0.0, 0.0);
//    glTranslatef(-2.0f, 0.0f, 10.0f);
//    glColor3f(0.4, 0.6, 0.8);
//    drawCubeMesh(0.5f, floorWidth, 15);
//    glPopMatrix();
//}
//
//void drawCart(int floorWidth){
//    drawSeatPlatform(floorWidth);
//    drawCartBackFront();
//    drawCartBackRear();
//    drawFrontBox(floorWidth);
//    drawRoof(floorWidth);
//    addWheels();
//}

// *****************************************//




void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
//    camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
    gluLookAt(0.0 + camX, 0.0 + camY, 0.0 + camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//  move the whole scene
    glTranslatef(sceX, sceY, sceZ);
    glRotatef(sceR*5, 0.0, 1.0, 0.0);
//    drawGrid();
//    drawAxes();
    
    drawCart(8);
    
    
    
    
    
    
    
    
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
