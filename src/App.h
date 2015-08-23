#ifndef App_App_h
#define App_App_h

#include "ofMain.h"
#include "State.h"
#include "CloseupModule.h"
#include "ofxJSON.h"

class App
{
    
public:
    App();    
    class State *current_state;
    
    void setCurrentState(State *s);
    void keyPressed(ofKeyEventArgs& eventArgs);
    void update(ofEventArgs &args);
    
    void update();
    void next();
    void jump();
    void draw();
    void cancel();
    
    bool bMale = true;
    bool isMale();
    
    
    int getCurrentModule();
    void incCurrentModule();
    int moduleIndex;
    
    
    ofxJSONElement data;
};

#endif
