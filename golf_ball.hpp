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

void drawBall(float size, GLfloat ballTextureId) {
    glRotatef(90, 1.0, 0.0, 0.0);
    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);

    glBindTexture(GL_TEXTURE_2D, ballTextureId);
                                                                     
    gluSphere(quad, size, 32, 32);

    gluDeleteQuadric(quad);
}
