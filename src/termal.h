//
//  heart.h
//  until_dawn_screen_1
//
//  Created by miguel on 17/08/15.
//
//

#ifndef __termal__
#define __termal__

#include "ofMain.h"
#include "CloseupModule.h"

class Termal : public CloseupModule
{
public:
    Termal();
    void draw(ofxJSONElement user);
    void update();
    int value;
};

#endif /* defined(__until_dawn_screen_1__heart__) */
