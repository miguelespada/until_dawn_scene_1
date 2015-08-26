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
    
    switch (app->getCurrentModule()) {
        case 0:
            heart = new Heart();
            break;
        case 1:
            pressure = new  Pressure();
            break;
        case 2:
            termal = new Termal();
            break;
        case 3:
            galvanic = new  Galvanic();
            break;
        case 4:
            optical = new  Optical();
            break;
        default:
            heart = new Heart();
            break;
    }
    
    timer = ofGetElapsedTimef();
};

void Closeup::draw(){
    Assets *assets = Assets::getInstance();
    switch (app->getCurrentModule()) {
        case 0:
            heart->draw(user);
            break;
        case 1:
            pressure->draw(user);
            break;
        case 2:
            termal->draw(user);
            break;
        case 3:
            galvanic->draw(user);
            break;
        case 4:
            optical->draw(user);
            break;
        default:
            heart->draw(user);
            break;
    }
    
    
    table.drawTable();
    
    table.drawUserStress(user);
    
    assets->logos.draw(0, 0);
    assets->lineas.draw(0, 0);
    assets->degradado.draw(0, 10);
};

void Closeup::update(){
    
    
    switch (app->getCurrentModule()) {
        case 0:
            heart->update();
            break;
        case 1:
            pressure->update();
            break;
        case 2:
            termal->update();
            break;
        case 3:
            galvanic->update();
            break;
        case 4:
            optical->update();
            break;
        default:
            heart->update();
            break;
    }
    
    user = app->data;
    if( ofGetElapsedTimef() > timer + 5)
        next();
    
    
}

void Closeup::next(){
    cout << "next-" << endl;
    clear();
    
    app->setCurrentState(new postGlitch(app));
    delete this;
};

void Closeup::clear(){
    switch (app->getCurrentModule()) {
        case 0:
            heart->clear();
            delete heart;
            break;
        case 1:
            pressure->clear();
            delete pressure;
            break;
        case 2:
            termal->clear();
            delete termal;
            break;
        case 3:
            galvanic->clear();
            delete galvanic;
            break;
        case 4:
            optical->clear();
            delete optical;
            break;
        default:
            heart->clear();
            delete heart;
            break;
    }

};
