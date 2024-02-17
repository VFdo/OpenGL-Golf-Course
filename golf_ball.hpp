//
//  golf_ball.hpp
//  2d_house
//
//  Created by Vidu Fernando on 2024-02-17.
//

//#ifndef golf_ball_hpp
//#define golf_ball_hpp

#include <stdio.h>
#include <GLUT/glut.h>


//#endif /* golf_ball_hpp */

void drawBall(float size) {
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);
    
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    gluSphere(quad, size, 32, 32);

    gluDeleteQuadric(quad);

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
