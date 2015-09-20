//
//  classification.h
//  until_dawn_screen_1
//
//  Created by miguel on 25/08/15.
//
//

#ifndef __until_dawn_screen_1__classification__
#define __until_dawn_screen_1__classification__

#include <State.h>
#include "fullTable.h"

class Classification: public State
{
    FullTable table;
    App *app;
    int row;
    
public:
    Classification(App *a);
    ~Classification(){};
    std::string toString() { return "Classification"; }
    void update();
    void draw();
    void next();
    
};

#endif /* defined(__until_dawn_screen_1__classification__) */
