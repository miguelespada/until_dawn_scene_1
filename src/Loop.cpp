#include "App.h"
#include "Assets.h"
#include "Loop.h"
#include "preGlitch.h"
#include "preIndex.h"

Loop::Loop(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
};

void Loop::draw(){
    body.setMale(app->isMale());
    body.draw();
};

void Loop::update(){
    body.update();

}

void Loop::next(){
    
    app->setCurrentState(new preGlitch(app));
    delete this;
};


void Loop::end(){
    app->setCurrentState(new preIndex(app));
    delete this;
};