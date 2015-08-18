//
//  assets.h
//  until_dawn_screen_2
//
//  Created by miguel on 16/07/15.
//
//

#ifndef __until_dawn_screen_2__assets__
#define __until_dawn_screen_2__assets__

#include "ofMain.h"

#define SCALE 2
#define W 1920/SCALE
#define H 1080/SCALE


class Assets{
public:
    static Assets* getInstance();
    void load();
    
    float getScale();
    
    ofVideoPlayer male_loop;
    ofVideoPlayer female_loop;
    ofVideoPlayer glitches[5];
    ofVideoPlayer closeups[5];
    
    ofImage lineas;
    ofImage logos;
    ofImage degradado;
    ofImage ellipse;
    ofImage icon_heart;
    ofImage icon_pressure;
    ofImage icon_optical;
    ofImage icon_hand;
    ofImage icon_termal;
    
    
    ofTrueTypeFont		font;
    
    void setFont(float size);
    
private:
    static Assets* instance;
    Assets();
};


#endif /* defined(__until_dawn_screen_2__assets__) */
