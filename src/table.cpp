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
}

void Table::drawTable(){
    ofEnableSmoothing();
    
    drawTableHeader();
    drawTableRow(1, 1613);
    drawTableRow(2, 1672);
    drawTableRow(3, 1727);
    drawTableRow(4, 1783);
    
    ofDisableSmoothing();
}

void Table::drawTableHeader(){
    ofTrueTypeFont *font = assets->getFont(12);
    float scale = assets->getScale();
    
    string msg = "RANK";
    font->drawString(msg, 85 * scale, 1556 * scale + font->stringHeight(msg) / 2);
    
    msg = "SUJETO";
    font->drawString(msg, 164 * scale, 1556 * scale + font->stringHeight(msg) / 2);
    
    msg = "ÍNDICE UNTIL DAWN";
    font->drawString(msg, 767 * scale, 1556 * scale + font->stringHeight(msg) / 2);
    
    for(int i = 0; i < 5; i ++){
        msg = ofToString(i + 1);
        font->drawString(msg, (412 + i * 70) * scale - font->stringWidth(msg)/2, 1556 * scale + font->stringHeight(msg) / 2);
    }
    
    
    int ww = assets->icon_user.getWidth() * assets->getScale();
    int hh = assets->icon_user.getHeight() * assets->getScale();
    
    assets->icon_user.draw(142 * scale, 1556 * scale - hh/2, ww, hh);
}


void Table::drawTableRow(int r, int y){
    ofTrueTypeFont *font = assets->getFont(12);
    float scale = assets->getScale();
    
    string msg = ofToString(r);
    font->drawString(msg, 85 * scale, y * scale + font->stringHeight(msg) / 2);
    
    msg = "MIGUEL V. ESPADA";
    font->drawString(msg, 164 * scale, y * scale + font->stringHeight(msg) / 2);
    
    
    for(int i = 0; i < 5; i ++){
        msg = ofToString("100%");
        font->drawString(msg, (412 + i * 70) * scale - font->stringWidth(msg)/2, y * scale + font->stringHeight(msg) / 2);
    }
    
    msg = "99%";
    font->drawString(msg, 830 * scale, y * scale + font->stringHeight(msg) / 2);
    
    ofSetColor(assets->red);
    msg = "PÁNICO";
    font->drawString(msg, 875 * scale, y * scale + font->stringHeight(msg) / 2);
    
    ofSetColor(255);
    
    
    for(int i = 0; i < 5; i ++){
        ofSetColor(assets->red);
        ofRect((771 + i * 10) * scale , y * scale - 12 * scale, 6 * scale, 22 * scale);
        ofSetColor(255);
        ofNoFill();
        ofRect((771 + i * 10) * scale , y * scale - 12 * scale, 6 * scale, 22 * scale);
    }
    
    
    int ww = assets->icon_user.getWidth() * assets->getScale();
    int hh = assets->icon_user.getHeight() * assets->getScale();
    
    assets->icon_user.draw(142 * scale, y * scale - hh/2, ww, hh);
}