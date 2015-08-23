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
    
    assets->wireframe_heart.draw(0, 0);
    assets->logos.draw(0, 0);
    assets->lineas.draw(0, 0);
    assets->degradado.draw(0, 10);
}
