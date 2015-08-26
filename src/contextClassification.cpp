//
//  contextClassification.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 25/08/15.
//
//

#include "contextClassification.h"
#include "classification.h"

#include "App.h"
#include "Assets.h"
#include "Loop.h"

contextClassification::contextClassification(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    timer = ofGetElapsedTimef();
};

void contextClassification::draw(){
    Assets *assets = Assets::getInstance();
    
    
    table.drawTableInContext();
    
    table.drawLines();
    
    assets->logos.draw(0, 0);
    assets->degradado.draw(0, 10);
    
};

void contextClassification::update(){
    if( ofGetElapsedTimef() > timer + 2){
        app->setCurrentState(new Classification(app));
        delete this;
    }
}

void contextClassification::next(){
    
    app->setCurrentState(new Loop(app));
    delete this;
};