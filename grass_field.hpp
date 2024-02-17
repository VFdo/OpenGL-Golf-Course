//
//  grass_field.hpp
//  2d_house
//
//  Created by Vidu Fernando on 2024-02-17.
//

//#ifndef grass_field_hpp
//#define grass_field_hpp

#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <GLUT/glut.h>
#include <math.h>
#include <iostream>

//#endif /* grass_field_hpp */

void drawOval(int numVertices, float width, float height) {
    glRotatef(90, 1.0, 0.0, 0.0);

    glEnable(GL_TEXTURE_2D);
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
