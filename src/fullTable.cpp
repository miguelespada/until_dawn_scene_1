//
//  fullTable.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 25/08/15.
//
//

#include "fullTable.h"


FullTable::FullTable(){
    assets = Assets::getInstance();
    
    users.open("http://192.168.1.42:3000/all.json");
    user.open("http://192.168.1.42:3000/last.json");
}

void FullTable::drawTable(){
    
    ofPushMatrix();
    
    ofTranslate(0, 85 + 230);
    int N = users.size();
    if (N > 20)
        N = 20;
    
    for(int i = 0; i < N; i ++){
        table.drawTableRow(i + 1, i * 55, users[i]);
        if(users[i]["name"] == user["name"])
            ofLine(60, i*55, 70, i*55);
    }
    
    ofPopMatrix();
    
}

void FullTable::drawTableInContext(){
    
    
    int idx;
    for(int i = 0; i < users.size(); i ++){
        if(users[i]["name"] == user["name"])
            idx = i;
    }
    
    int a = idx - 9;
    if(a < 0) a = 0;
    
    int z = idx + 10;
    if (z > users.size()) z = users.size();
    
    ofPushMatrix();
    
    ofTranslate(0, 85 + 230);
    for(int i = a; i < z; i ++){
        int y =  (i + a) * 55;
        table.drawTableRow(i + 1, y, users[i]);
        if(users[i]["name"] == user["name"])
            ofLine(60, y, 70, y);
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
    for(int i = 0; i < 21; i ++){
        white.setBrightness(ofMap(i, 0, 20, 255, 100));
        ofSetColor(white);
        ofLine(90, i * 55, 990, i * 55);
    }
    ofPopMatrix();
}