//
//  table.h
//  until_dawn_screen_1
//
//  Created by miguel on 19/08/15.
//
//

#ifndef __until_dawn_screen_1__table__
#define __until_dawn_screen_1__table__

#include "ofMain.h"
#include "assets.h"
#include "ofxJSON.h"


class Table
{
    Assets *assets;
    
    ofxJSONElement top;
    
public:
    Table();
    void drawTable();
    void drawTableHeader();
    void drawTableRow(int r, int y, ofxJSONElement top);
    string computeIndice(ofxJSONElement top);
    void drawUserStress(ofxJSONElement top);
    
    ofColor computeIndiceColor(ofxJSONElement top);
};

#endif /* defined(__until_dawn_screen_1__table__) */
