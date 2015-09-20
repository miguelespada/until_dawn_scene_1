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
#define WW 1920/SCALE
#define HH 1080/SCALE


class Assets{
public:
    static Assets* getInstance();
    void load();
    
    
    ofVideoPlayer male_loop;
    ofVideoPlayer female_loop;
    ofVideoPlayer glitches[5];
    ofVideoPlayer closeups[5];
    ofVideoPlayer indices[5];
    ofVideoPlayer calculando;
    
    ofImage lineas;
    ofImage logos;
    ofImage degradado;
    ofImage icon_heart;
    ofImage icon_pressure;
    ofImage icon_optical;
    ofImage icon_hand;
    ofImage icon_termal;
    ofImage icon_user;
    ofImage rejilla;
    
    
    ofImage wireframe_heart;
    ofImage wireframe_pressure;
    ofImage wireframe_temperature;
    ofImage wireframe_optical;
    ofImage wireframe_galvanic;
    
    ofImage tabla;
    
    
    ofColor red = ofColor(231, 57, 51);
    ofColor blue = ofColor(0, 116, 188);
    ofColor yellow = ofColor(254, 223, 82);
    ofColor green = ofColor(94, 172, 77);
    ofColor orange = ofColor(243, 144, 69);
    
    ofTrueTypeFont		*fonts[64];
    ofTrueTypeFont      *getFont(int size);
    void stopVideos();
    
private:
    static Assets* instance;
    Assets();
    

};


#endif /* defined(__until_dawn_screen_2__assets__) */
