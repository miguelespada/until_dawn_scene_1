//
//  App.cpp
//  App
//
//  Created by miguel on 12/10/14.
//
//

#include "App.h"
#include "heart.h"
#include "optical.h"
#include "ofxJSON.h"


App::App(){
    // Register events and actions
    ofAddListener(ofEvents().keyPressed, this, &App::keyPressed);
    ofAddListener(ofEvents().update, this, &App::update);
    moduleIndex = 0;
    data.open("http://192.168.1.42:3000/last.json");
}

void App::setCurrentState(State *s){
    current_state = s;
}

void App::next(){
    current_state->next();
}

void App::jump(){
    current_state->jump();
}

void App::cancel(){
    current_state->cancel();
}

void App::draw(){
    ofPushStyle();
    ofPushMatrix();
    current_state->draw();
    ofPopMatrix();
    ofPopStyle();
}

void App::update(){
    current_state->update();
    ofSendMessage("[Info] " + current_state->toString());
    
    if(ofGetFrameNum() % 15 == 0){
        data.open("http://192.168.1.42:3000/last.json");
        bMale = data["male"].asBool();
        
        if(data["active"].asBool())
            current_state->init();
        else
            current_state->end();
    }
}

void App::update(ofEventArgs &args){
    update();
}


void App::keyPressed (ofKeyEventArgs& eventArgs){
    ofxJSONElement response;
    switch (eventArgs.key) {
        case 'n':
            next();
            break;
        case 'c':
            cancel();
            break;
        default:
            break;
    }
}

bool App::isMale(){
    return bMale;
}



int App::getCurrentModule(){
    return moduleIndex;
}

void App::incCurrentModule(){
    moduleIndex = (moduleIndex + 1) % 5;
}
