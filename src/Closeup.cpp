//
//  Closeup.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#include "Closeup.h"
#include "App.h"
#include "Assets.h"
#include "postGlitch.h"
#include "heart.h"
#include "optical.h"
#include "termal.h"
#include "galvanic.h"
#include "pressure.h"
#include "CloseupModule.h"

Closeup::Closeup(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    
//    switch (1) {
    switch (app->getCurrentModule()) {

        case 0:
            closeup = new Heart();
            break;
        case 1:
            closeup = new Optical();
            break;
        case 2:
            closeup = new Termal();
            break;
        case 3:
            closeup = new Galvanic();
            break;
        case 4:
            closeup = new Pressure();
            break;
        default:
            break;
    }
    
    timer = ofGetElapsedTimef();
};

void Closeup::draw(){
    Assets *assets = Assets::getInstance();
    
    closeup->draw(user);
    
    table.drawTable();
    
    table.drawUserStress(user);
    
    assets->logos.draw(0, 0);
    assets->lineas.draw(0, 0);
    assets->degradado.draw(0, 10);
};

void Closeup::update(){
    
    closeup->update();
    
    user = app->data;
    if( ofGetElapsedTimef() > timer + 5)
        next();

}

void Closeup::next(){
    clear();
    
    app->setCurrentState(new postGlitch(app));
    delete this;
};

void Closeup::clear(){
    closeup->clear();

};
