
#ifndef __heart__
#define __heart__
#include "ofMain.h"
#include "CloseupModule.h"
class Heart : public CloseupModule
{
public:
    Heart();
    void draw(ofxJSONElement user);
    void update();
    
};

#endif /* defined(__until_dawn_screen_1__heart__) */
