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
#include "body.h"


class Assets{
public:
    static Assets* getInstance();
    void load();
    
    ofImage fondo;
    ofImage fondo_full;
    ofTrueTypeFont		font_32;
    ofTrueTypeFont		font_30;
    ofTrueTypeFont		font_28;
    ofTrueTypeFont		font_20;
    ofTrueTypeFont		font_14;
    ofTrueTypeFont		font_12;
    ofTrueTypeFont		font_10;
    
    Body body;
    
    int x, y;
    
private:
    static Assets* instance;
    
    Assets();
};


#endif /* defined(__until_dawn_screen_2__assets__) */
