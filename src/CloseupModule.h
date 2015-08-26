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
#include "ofxJSON.h"

class CloseupModule
{
 
protected:
    ofVideoPlayer video;
    Assets *assets;
    
public:
    virtual ~CloseupModule(){
        video.stop();
    }
    virtual void draw(ofxJSONElement user)=0;
   
    void init();
    void drawMovie();
    void initMovie();
    void update();
    void clear();
    
};


#endif
