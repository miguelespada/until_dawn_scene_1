//
//  table.cpp
//  until_dawn_screen_1
//
//  Created by miguel on 19/08/15.
//
//

#include "table.h"

Table::Table(){
    assets = Assets::getInstance();
    
    top.open("http://192.168.1.42:3000/top.json");
}

void Table::drawTable(){
    if(ofGetFrameNum() % 30 == 0)
        top.open("http://192.168.1.42:3000/top.json");
    
    
    drawTableHeader();
    drawTableRow(1, 1613);
    drawTableRow(2, 1672);
    drawTableRow(3, 1727);
    drawTableRow(4, 1783);
    
}

void Table::drawTableHeader(){
    
 
    
    ofTrueTypeFont *font = assets->getFont(12);
    
    string msg = "RANK";
    font->drawStringAsShapes(msg, 85 , 1556 + font->stringHeight(msg) / 2);
    
    msg = "SUJETO";
    font->drawStringAsShapes(msg, 164 , 1556 + font->stringHeight(msg) / 2);
    
    msg = "ÍNDICE UNTIL DAWN";
    font->drawStringAsShapes(msg, 767 , 1556  + font->stringHeight(msg) / 2);
    
    msg = "STRESS";
    font->drawStringAsShapes(msg, 400 , 1556  + font->stringHeight(msg) / 2);
    
    
    assets->icon_user.draw(142 , 1556  - assets->icon_user.getHeight()/2);
}


void Table::drawTableRow(int r, int y){
    ofTrueTypeFont *font = assets->getFont(12);
    
    string msg = ofToString(r);
    font->drawStringAsShapes(msg, 85 , y  + font->stringHeight(msg) / 2);
    
    msg = top[r - 1]["name"].asString();
    
    font->drawStringAsShapes(msg, 164 , y  + font->stringHeight(msg) / 2);
    
    ofPushMatrix();
    ofTranslate(400, y + 7);
    ofScale(0.25, 1);
    ofxJSONElement stress = top[r - 1]["stress"];
    for(int i = 0; i < stress.size(); i++){
        float v = stress[i].asFloat() / 5;
        ofLine(i, 0, i, -v);
    }
    ofPopMatrix();
    
    msg = top[r - 1]["indice"].asString() + "%";
    font->drawStringAsShapes(msg, 830 , y  + font->stringHeight(msg) / 2);
    
    ofSetColor(assets->red);
    msg = "PÁNICO";
    font->drawStringAsShapes(msg, 875 , y  + font->stringHeight(msg) / 2);
    
    ofSetColor(255);
    
    
    for(int i = 0; i < 5; i ++){
        
        if(top[r - 1]["indice"].asInt() >= i * 20)
            ofSetColor(assets->red);
        else
            ofNoFill();
        
        ofRect((771 + i * 10)  , y  - 12 , 6 , 22 );
        ofSetColor(255);
        ofNoFill();
        ofRect((771 + i * 10)  , y  - 12 , 6 , 22 );
        ofFill();
    }
    
    
    int ww = assets->icon_user.getWidth();
    int hh = assets->icon_user.getHeight();
    
    assets->icon_user.draw(142 , y  - hh/2, ww, hh);
}