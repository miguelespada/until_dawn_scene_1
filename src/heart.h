
#ifndef __heart__
#define __heart__
#include "ofMain.h"
#include "CloseupModule.h"
#include "table.h"

class Heart : public CloseupModule
{
    Table table;
public:
    Heart();
    void draw();
    void update();
};

#endif /* defined(__until_dawn_screen_1__heart__) */
