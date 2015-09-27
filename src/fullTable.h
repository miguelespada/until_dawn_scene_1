//
//  fullTable.h
//  until_dawn_screen_1
//
//  Created by miguel on 25/08/15.
//
//

#ifndef __until_dawn_screen_1__fullTable__
#define __until_dawn_screen_1__fullTable__

#include "ofMain.h"
#include "table.h"
#include "ofxJSON.h"


class FullTable
{
    Assets *assets;
    Table table;
public:
    FullTable();
    void drawTable(int n);
    void drawLines();
    ofxJSONElement users;
    ofxJSONElement lastClassified;
};

#endif /* defined(__until_dawn_screen_1__fullTable__) */
