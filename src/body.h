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
    void update(ofEventArgs &args);
    void drawVideo();
public:
    Body();
    void draw(int x, int y);
};

#endif /* defined(__until_dawn_screen_2__temperature__) */
