#include "App.h"
#include "Assets.h"
#include "Loop.h"
#include "preGlitch.h"

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

void Loop::push(){
};

void Loop::next(){
    
    app->setCurrentState(new preGlitch(app));
    delete this;
};

void Loop::jump(){
};