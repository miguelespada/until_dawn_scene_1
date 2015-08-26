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
#include "table.h"
#include "App.h"


class Body
{
    ofVideoPlayer video;
    Assets *assets;
    float icon_alpha;
    Table table;
    
    App *app;
    
public:
    Body(App *a);
    ~Body();
    void draw();
    void update();
    void setMale(bool s);
    void drawIcons(int w, int h);
    void drawIcon(int n, string label, string value, ofImage icon, ofColor color, float alpha, int radius);
};

#endif /* defined(__until_dawn_screen_2__temperature__) */
