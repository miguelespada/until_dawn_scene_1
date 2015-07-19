//
//  OscAdapter.cpp
//  carrousel
//
//  Created by miguel on 14/10/14.
//
//

#include "OscAdapter.h"

OscAdapter::OscAdapter(){
    int localPort = 8000;
    receiver = new ofxOscReceiver;
    receiver->setup(localPort);
    ofLogNotice() << "listening for osc messages on port " << localPort;
    bOnline = false;
    
    ofAddListener(ofEvents().update, this, &OscAdapter::update);
    assets = Assets::getInstance();
}

void OscAdapter::update(ofEventArgs &args){
}
