//
//  heart.h
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#ifndef __optical__
#define __optical__

#include "ofMain.h"
#include "CloseupModule.h"

class Optical : public CloseupModule
{
public:
    Optical();
    void draw();
    void update();
};

#endif /* defined(__until_dawn_screen_1__heart__) */
