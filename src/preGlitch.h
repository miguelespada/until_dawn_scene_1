//
//  Glitch.h
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#ifndef __until_dawn_screen_1__Glitch__
#define __until_dawn_screen_1__Glitch__

#include <State.h>

class preGlitch: public State
{
    ofVideoPlayer video;
    
public:
    preGlitch(App *g);
    std::string toString() { return "preGlitch"; }
    void update();
    void draw();
    void next();
    void push();
    void jump();
    
    
};


#endif /* defined(__until_dawn_screen_1__Glitch__) */
