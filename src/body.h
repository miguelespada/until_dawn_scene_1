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
#include "assets.h"

class Body
{
    ofVideoPlayer video;
    Assets *assets;
    float icon_alpha;
    
public:
    Body();
    void draw();
    void update();
    void setMale(bool s);
    void drawIcon(ofImage icon, float alpha, int radious);
    void drawCircle(float r);
};

#endif /* defined(__until_dawn_screen_2__temperature__) */
