//
//  Closeup.h
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#ifndef __until_dawn_screen_1__Closeup__
#define __until_dawn_screen_1__Closeup__

#include <State.h>
#include <Closeup.h>
#include <CloseupModule.h>

class Closeup: public State
{
    
public:
    Closeup(App *g);
    ~Closeup(){};
    std::string toString() { return "Closeup"; }
    void update();
    void draw();
    void next();
    
    CloseupModule *closeup;
};


#endif /* defined(__until_dawn_screen_1__Closeup__) */
