//
//  assets.cpp
//  until_dawn_screen_2
//
//  Created by miguel on 16/07/15.
//
//

#include "assets.h"
Assets::Assets(){
}

Assets* Assets::instance = 0;

Assets* Assets::getInstance(){
    if (instance == 0){
        instance = new Assets();
        instance->load();
    }
    return instance;
};


void Assets::load(){
    
    string filename = "male_loop.mov";
    male_loop.loadMovie(filename);
    ofLogNotice() << "Loading: " << filename;
    
    filename = "female_loop.mov";
    female_loop.loadMovie(filename);
    ofLogNotice() << "Loading: " << filename;
    
    for(int i = 0; i < 5; i ++){
        string filename = "glitch_" + ofToString(i) + ".mov";
        glitches[i].loadMovie(filename);
        ofLogNotice() << "Loading: " << filename ;
    }
    
    for(int i = 0; i < 5; i ++){
        string filename = "closeup_" + ofToString(i) + ".mov";
        closeups[i].loadMovie(filename);
        ofLogNotice() << "Loading: " << filename ;
    }
}

float Assets::getScale(){
    return W / 1920.0;
}
