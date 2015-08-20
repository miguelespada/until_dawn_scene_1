//
//  preIndex.h
//  until_dawn_screen_1
//
//  Created by miguel on 19/08/15.
//
//

#ifndef __until_dawn_screen_1__preIndex__
#define __until_dawn_screen_1__preIndex__

#include <State.h>

class preIndex: public State
{
    
public:
    preIndex(App *g);
    ~preIndex(){};
    std::string toString() { return "preIndex"; }
    void update();
    void draw();
    void next();
    
    float alpha;
    int dots;
};

#endif /* defined(__until_dawn_screen_1__preIndex__) */
