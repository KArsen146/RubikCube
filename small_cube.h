//
// CreRGBed by Арсений Карпов on 22.05.2020.
//

#ifndef PROGA8_RUBIK_S_CUBE_SMALL_CUBE_H
#define PROGA8_RUBIK_S_CUBE_SMALL_CUBE_H
#include <iostream>
#include <vector>
#include <glut.h>
class small_cube {
public:
    unsigned int _color[6];
    double size;
    small_cube() :size(0.0)
    {
        for (int i = 0; i < 6; i++)
            _color[i] = 0;
    }

    void XOY()
    {
        unsigned int tmp = _color[5];
        _color[5] = _color[3];
        _color[3] = _color[0];
        _color[0] = _color[1];
        _color[1] = tmp;
    }

    void XOZ()
    {
        unsigned int tmp = _color[0];
        _color[0] = _color[2];
        _color[2] = _color[5];
        _color[5] = _color[4];
        _color[4] = tmp;
    }


    void YOZ()
    {
        unsigned int tmp = _color[1];
        _color[1] = _color[4];
        _color[4] = _color[3];
        _color[3] = _color[2];
        _color[2] = tmp;
    }
    unsigned char *RGB(unsigned int a)
    {
        unsigned char _rgb[3];
        _rgb[0] = _color[a] >> 16;
        _rgb[1] = _color[a] >> 8;
        _rgb[2] = _color[a];
        return _rgb;
    }
    void draw(double x, double y, double z)
    {
        glPushMatrix();
        glTranslated(x, y, z);
        glBegin(GL_QUADS);
        glColor3ubv(RGB(4));
        glNormal3f(0, 0, 1);
        glVertex3f(size, size, size);
        glVertex3f(0, size, size);
        glVertex3f(0, 0, size);
        glVertex3f(size, 0, size);
        glColor3ubv(RGB(3));
        glNormal3f(-1, 0, 0);
        glVertex3f(0, size, size);
        glVertex3f(0, size, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, size);
        glColor3ubv(RGB(0));
        glNormal3f(0, -1, 0);
        glVertex3f(size, 0, size);
        glVertex3f(0, 0, size);
        glVertex3f(0, 0, 0);
        glVertex3f(size, 0, 0);
        glColor3ubv(RGB(1));
        glNormal3f(1, 0, 0);
        glVertex3f(size, size, 0);
        glVertex3f(size, size, size);
        glVertex3f(size, 0, size);
        glVertex3f(size, 0, 0);
        glColor3ubv(RGB(5));
        glNormal3f(0, 1, 0);
        glVertex3f(size, size, 0);
        glVertex3f(0, size, 0);
        glVertex3f(0, size, size);
        glVertex3f(size, size, size);
        glColor3ubv(RGB(2));
        glNormal3f(0, 0, -1);
        glVertex3f(size, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, size, 0);
        glVertex3f(size, size, 0);
        glEnd();
        glPopMatrix();
    }

    void draw()
    {
        draw(0.0, 0.0, 0.0);
    }

    void set(int ind, unsigned int color)
    {
        _color[ind] = color;
    }
};

#endif //PROGA8_RUBIK_S_CUBE_SMALL_CUBE_H
