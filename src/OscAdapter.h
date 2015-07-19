//
//  OscAdapter.h
//  carrousel
//
//  Created by miguel on 14/10/14.
//
//

#ifndef __carrousel__OscAdapter__
#define __carrousel__OscAdapter__

#include "ofMain.h"
#include "ofxOsc.h"
#include "assets.h"



class OscAdapter{
    ofxOscReceiver *receiver;
    Assets *assets;
public:
    OscAdapter();
    bool bOnline;
    void update(ofEventArgs &args);
};



#endif /* defined(__carrousel__OscAdapter__) */
