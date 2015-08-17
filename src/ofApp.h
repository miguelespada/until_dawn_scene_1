#pragma once

#include "ofMain.h"
#include "assets.h"
#include "App.h"


class ofApp : public ofBaseApp{

	public:
    
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
    
        Assets *assets;
    
        bool keyIsDown[255];
    
        bool bRotated = true;
        void setRotation();
    
        App app;

    };
