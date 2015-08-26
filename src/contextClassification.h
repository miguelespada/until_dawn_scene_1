//
//  contextClassification.h
//  until_dawn_screen_1
//
//  Created by miguel on 25/08/15.
//
//

#ifndef __until_dawn_screen_1__contextClassification__
#define __until_dawn_screen_1__contextClassification__

#include <State.h>
#include "fullTable.h"

class contextClassification: public State
{
    FullTable table;
    
    App *app;
    
public:
    contextClassification(App *a);
    ~contextClassification(){};
    std::string toString() { return "contextClassification"; }
    void update();
    void draw();
    void next();
    
    
};


#endif /* defined(__until_dawn_screen_1__contextClassification__) */
