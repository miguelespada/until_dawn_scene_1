#include "App.h"
#include "Assets.h"
#include "Loop.h"
#include "preGlitch.h"

Loop::Loop(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
    body = new Body(app);
    
    timer = ofGetElapsedTimef();
};

void Loop::draw(){
    body->setMale(app->isMale());
    body->draw();
    
    
};

void Loop::update(){
    body->update();
    
    if( ofGetElapsedTimef() > timer + 7)
        next();
}

void Loop::next(){
    
    app->setCurrentState(new preGlitch(app));
    delete body;
    delete this;
};


void Loop::clear(){
    delete body;
};