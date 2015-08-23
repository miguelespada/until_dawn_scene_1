//
//  CloseupModule.h
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#ifndef until_dawn_screen_1_CloseupModule_h
#define until_dawn_screen_1_CloseupModule_h

#include "assets.h"

class CloseupModule
{
    
protected:
    ofVideoPlayer video;
    Assets *assets;
    
public:
    virtual void draw() {};
    void init();
    void drawMovie();
    void initMovie();
    void update();
    bool isDone();
};


#endif
