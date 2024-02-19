//
//  golf_ball.hpp
//  Golf_Course
//
//  Created by Vidu Fernando on 2024-02-17.
//

#include <stdio.h>
#include <GLUT/glut.h>


GLfloat ballWhite[] = {1.0, 1.0, 1.0, 1.0};
GLfloat ballDiffuse[] = {0.2, 0.2, 0.2, 1.0};

void drawBall(float size) {
    glMaterialfv(GL_FRONT, GL_AMBIENT, ballWhite);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, ballDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, ballWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 200);
    glEnable(GL_TEXTURE_2D);
    
    glColor3f(1.0, 1.0, 1.0);
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    gluSphere(quad, size, 32, 32);
    gluDeleteQuadric(quad);

    glDisable(GL_TEXTURE_2D);
    
}
