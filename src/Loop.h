#ifndef __loop_state__
#define __loop_state__

#include <State.h>
#include "body.h"

class Loop: public State
{
public:
    ~Loop(){};
    Loop(App *g);
    std::string toString() { return "Loop"; }
    void update();
    void draw();
    void next();    
    Body *body;
    void clear();
};

#endif
