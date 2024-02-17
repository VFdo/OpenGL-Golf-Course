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

//#endif /* grass_field_hpp */

void drawOval(int numVertices, float width, float height, GLfloat grassTextureId) {
    glBegin(GL_TRIANGLE_FAN);
    glBindTexture(GL_TEXTURE_2D, grassTextureId);
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
}
