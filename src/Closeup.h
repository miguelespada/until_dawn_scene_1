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
#include <heart.h>
#include <galvanic.h>
#include <termal.h>
#include <optical.h>
#include <pressure.h>
#include "ofxJSON.h"
#include "table.h"


class Closeup: public State
{
    Table table;
    
public:
    Closeup(App *g);
    ~Closeup(){
        
    };
    std::string toString() { return "Closeup"; }
    void update();
    void draw();
    void next();
    void clear();
    
    
    Heart *heart = NULL;
    Galvanic *galvanic = NULL;
    Optical *optical = NULL ;
    Pressure *pressure = NULL;
    
    ofxJSONElement user;
};


#endif /* defined(__until_dawn_screen_1__Closeup__) */
