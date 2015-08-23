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
    
    filename = "icon_user.png";
    icon_user.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
    
    
    filename = "wireframe_heart.png";
    wireframe_heart.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
    
    for(int i = 0; i < 64; i++)
        fonts[i] = NULL;
    
}


ofTrueTypeFont *Assets::getFont(int size){
    if(fonts[size] == NULL){
        fonts[size] = new ofTrueTypeFont();
        fonts[size]->loadFont("Akkurat-Mono.ttf", size, true, true, true);
        fonts[size]->setLetterSpacing(1.1);
        fonts[size]->setSpaceSize(0.3);
        
        ofLogNotice() << "Loading: " << "Akkurat-Mono.ttf " << size;
    }
    return fonts[size];
}

