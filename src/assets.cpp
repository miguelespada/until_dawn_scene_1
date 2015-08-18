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
    
    filename = "lineas.png";
    lineas.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
    
    filename = "logos.png";
    logos.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
    
    filename = "degradado.png";
    degradado.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
    
    filename = "ellipse.png";
    ellipse.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
    
    
    filename = "icon_termal.png";
    icon_termal.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
    
    filename = "icon_optical.png";
    icon_optical.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
    
    filename = "icon_pressure.png";
    icon_pressure.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
    
    filename = "icon_hand.png";
    icon_hand.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
    
    filename = "icon_heart.png";
    icon_heart.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
    

    
}

float Assets::getScale(){
    return W / 1920.0;
}

void Assets::setFont(float size){
    font.loadFont("Akkurat-Mono.ttf", size * getScale());
    font.setLetterSpacing(1.1);
    font.setEncoding(OF_ENCODING_ISO_8859_15);
}
