//
//  fullTable.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 25/08/15.
//
//

#include "fullTable.h"
#define ROWS 20

FullTable::FullTable(){
    assets = Assets::getInstance();
    
    users.open("http://192.168.1.42:3000/all.json");
    
    lastClassified.open("http://192.168.1.42:3000/lastClassified.json");
    
}

void FullTable::drawTable(int n){
    
    n = (n % ((users.size() / ROWS) + 1) ) + 1;    
    ofPushMatrix();
    
    ofTranslate(0, 85 + 230);
    int N = users.size();
    if (N > ROWS * n)
        N = ROWS * n;
    int a = ROWS * (n - 1);
    
    for(int i = a; i < N; i ++){
        table.drawTableRow(i + 1, (i - a) * 55, users[i]);
        if(users[i]["name"] == lastClassified["name"])
            ofLine(60, (i - a) * 55, 70, (i - a) * 55);
    }
    
    ofPopMatrix();
    
}


void FullTable::drawLines(){
    ofPushMatrix();
    ofTranslate(0, -1300);
    table.drawTableHeader();
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofTranslate(0, 230);
    ofColor white = ofColor(255);
    for(int i = 0; i < ROWS + 2; i ++){
        white.setBrightness(ofMap(i, 0, 20, 255, 100));
        ofSetColor(white);
        ofLine(90, i * 55, 990, i * 55);
    }
    ofPopMatrix();
}
