//
//  temperature.cpp
//  until_dawn_screen_2
//
//  Created by miguel on 16/07/15.
//
//

#include "body.h"
#include "ofxTrueTypeFontUC.h"

Body::Body(){
    assets = Assets::getInstance();
}

void Body::update(){
    if(!video.isPlaying())
        video.play();
    video.update();
    icon_alpha += 0.004;
}

void Body::draw(){
    int w, h;
    
    if(ofGetWindowWidth() < ofGetWindowHeight()){
        w = ofGetWindowWidth();
        h = ofGetWindowHeight();
    }
    else{
        h = ofGetWindowWidth();
        w = ofGetWindowHeight();
    }
    
    video.draw(0, 0, w, h);
    
    
    ofPushMatrix();
    ofTranslate(w/2, h/4);
    float angle = TWO_PI / 5.0;
    
    drawIcon(1, "RITMO CARDÍACO",  "70 BPM",assets->icon_heart, assets->red, icon_alpha + angle, w/3.4);
    drawIcon(2, "CONDUCTIVIDAD GALVÁNICA", "4.55 V", assets->icon_hand, assets->blue, icon_alpha + angle * 2, w/3.4);
    drawIcon(3, "PRESIÓN ARTERIAL", "STABLE", assets->icon_pressure, assets->yellow, icon_alpha + angle * 3, w/3.4);
    drawIcon(4, "OPTICAL FLOW", "135 mm/s", assets->icon_optical, assets->green, icon_alpha + angle * 4, w/3.4);
    drawIcon(5, "TEMPERATURA", "37.5 ºC", assets->icon_termal, assets->orange, icon_alpha + angle * 5, w/3.4);
    
        ofPushMatrix();
        ofTranslate(0, h/24);
        drawCircle(w/6);
        ofPopMatrix();
        
    ofPopMatrix();
    
    
    ofTrueTypeFont *font = assets->getFont(12);
    float scale = assets->getScale();
    
    ofEnableSmoothing();
    
    drawTableHeader();
    drawTableRow(1, 1613);
    drawTableRow(2, 1672);
    drawTableRow(3, 1727);
    drawTableRow(4, 1783);

    ofDisableSmoothing();
    
    assets->logos.draw(0, 0, w, h);
    assets->lineas.draw(0, 0, w, h);
    assets->degradado.draw(0, 10, w, h);
    
    
}

void Body::setMale(bool s){
    if(s)
        video = Assets::getInstance()->male_loop;
    else
        video = Assets::getInstance()->female_loop;
}

void Body::drawIcon(int n, string label, string value, ofImage icon, ofColor color, float alpha, int radius){
    int w = icon.getWidth() * assets->getScale();
    int h = icon.getHeight() * assets->getScale();
    
    float y = sin(alpha) * radius;
    float x = cos(alpha) * radius;
    
    icon.draw(x, y, w, h);
    
    ofTrueTypeFont *font = assets->getFont(12);
    
    int text_y =  y + h + font->getSize() * 1.8;
    int text_x = x + w / 2 - font->stringWidth(label)/2;
    
    font->drawString(label, text_x, text_y);
    ofSetColor(color);
    string msg = ofToString(n);
    font->drawString(msg, text_x - font->stringWidth(msg) * 1.5 , text_y);
    ofSetColor(255);
    
    font = assets->getFont(17);
    
    text_x =  x + w / 2 - font->stringWidth(value) / 2;
    font->drawString(value, text_x, text_y + font->getSize() * 1.4);
}

void Body::drawCircle(float r){
    ofEnableSmoothing();
    ofSetColor(255);
    ofPath p = ofPath();
    p.setCircleResolution(200);
    p.setFilled(false);
    p.setStrokeColor(255);
    p.moveTo(r, 0);
    ofRotate(- ofRadToDeg(icon_alpha), 0, 0, 1);
    p.arc(0, 0, r, r, 0, 180 );
    p.setStrokeWidth(1.5);
    p.draw();
    ofDisableSmoothing();
}

void Body::drawTableHeader(){
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


void Body::drawTableRow(int r, int y){
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