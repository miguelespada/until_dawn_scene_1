//
//  temperature.h
//  until_dawn_screen_2
//
//  Created by miguel on 16/07/15.
//
//

#ifndef __until_dawn_screen_2__body__
#define __until_dawn_screen_2__body__

#include "ofMain.h"

class Body
{
    ofVideoPlayer video;
public:
    Body();
    void draw();
    void update();
    void setMale(bool s);
};

#endif /* defined(__until_dawn_screen_2__temperature__) */
