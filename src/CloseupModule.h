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
    int w, h;
    Assets *assets;
    
public:
    virtual void draw() {};
    
    void drawMovie(){
        video.draw(0, 0, w, h);
    }
    
    void initMovie(){        
        video.setLoopState(OF_LOOP_NONE);
    }
    
    void update() {
        
        if(!video.isPlaying())
            video.play();
        video.update();
    };
    
    bool isDone() {
        return video.getIsMovieDone();
    };
};


#endif
