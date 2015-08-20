//
//  heart.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "heart.h"

Heart::Heart(){
    CloseupModule::init();
    video = assets->closeups[1];
    initMovie();
}


void Heart::update(){
    CloseupModule::update();
}

void Heart::draw(){
    
    drawMovie();
    
    table.drawTable();
    
    assets->wireframe_heart.draw(0, 0, w, h);
    assets->logos.draw(0, 0, w, h);
    assets->lineas.draw(0, 0, w, h);
    assets->degradado.draw(0, 10, w, h);
}
