//
//  classification.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 25/08/15.
//
//

#include "classification.h"

#include "App.h"
#include "Assets.h"
#include "Loop.h"

Classification::Classification(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    timer = ofGetElapsedTimef();
    row = 0;
};

void Classification::draw(){
    Assets *assets = Assets::getInstance();
    
    table.drawTable(row);
    table.drawLines();
    
    assets->logos.draw(0, 0);
    assets->degradado.draw(0, 10);
    
};

void Classification::update(){
    if( ofGetElapsedTimef() > timer + 8){
        row ++;
        timer = ofGetElapsedTimef();
    }
}

void Classification::next(){
    app->setCurrentState(new Loop(app));
    delete this;
};