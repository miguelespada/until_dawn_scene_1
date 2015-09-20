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
#include "standby.h"
#include "index.h"
#include "calculandoIndex.h"


App::App(){
    // Register events and actions
    ofAddListener(ofEvents().keyPressed, this, &App::keyPressed);
    ofAddListener(ofEvents().update, this, &App::update);
    data.open("http://192.168.1.42:3000/last.json");
    
    receiver = new ofxOscReceiver;
    receiver->setup(12341);
    
    moduleIndex = 0;
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
    }
    
    while(receiver->hasWaitingMessages()){
        ofxOscMessage m;
        
        receiver->getNextMessage(&m);
        
        if(m.getAddress() == "/standby"){
            current_state->clear();
            setCurrentState(new Standby(this));
        }
        
        if(m.getAddress() == "/next"){
            current_state->next();
        }
        
        if(m.getAddress() == "/index"){
            current_state->clear();
            setCurrentState(new Standby(this));
        }
        
        if(m.getAddress() == "/calculandoIndex"){
            current_state->clear();
            setCurrentState(new calculandoIndex(this));
        }
        
        if(m.getAddress() == "/save"){
            bSave = bool(m.getArgAsInt32(0));
            save();
        }
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

void App::save(){
    ofLogNotice() << "Saving ---> " << bSave;
    dir = "images/" + data["_id"]["$oid"].asString();
    if(bSave && !ofDirectory::doesDirectoryExist(dir)){
        ofDirectory::createDirectory(dir, true);
        ofLogNotice() << "Creating directory: " << dir << endl;
    }
}

