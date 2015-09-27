//
//  temperature.cpp
//  until_dawn_screen_2
//
//  Created by miguel on 16/07/15.
//
//

#include "body.h"

Body::Body(App *a){
    assets = Assets::getInstance();
    icon_alpha = 0;
    app = a;
}

Body::~Body(){
    video.stop();
}

void Body::update(){
    if(!video.isPlaying())
        video.play();
    video.update();
    icon_alpha += 0.004;
}

void Body::draw(){
    
    if(video.isLoaded())
        video.draw(0, 0);
    assets->rejilla.draw(0, -400);
    
    drawIcons(1080, 1920);
    
    table.drawTable();
    
    
    table.drawUserStress(app->data);
    
    assets->logos.draw(0, 0);
    assets->lineas.draw(0, 0);
    assets->degradado.draw(0, 10);
    
    
}

void Body::drawIcons(int w, int h){
    ofPushMatrix();
    ofTranslate(w/2, h/4);
    
    float angle = TWO_PI / 5.0;
    
    
    float value;
    string msg;
    
    value = app->data["heartRate"][app->data["heartRate"].size() - 1].asFloat();
    msg = ofToString(value) + " BPM";
    
    
    drawIcon(1, "RITMO CARDÍACO",  msg, assets->icon_heart, assets->red, icon_alpha + angle, w/3.4);
    
    
    value = app->data["galvanicVoltage"][app->data["galvanicVoltage"].size() - 1].asFloat();
    msg = ofToString(value) + "(%) S/m";
    
    
    drawIcon(2, "CONDUCTIVIDAD GALVÁNICA", msg, assets->icon_hand, assets->blue, icon_alpha + angle * 2, w/3.4);
    
    
    value = app->data["stress"][app->data["stress"].size() - 1].asFloat();
    msg = ofToString(int(value)) + " %";
    
    
    drawIcon(3, "STRESS", msg, assets->icon_pressure, assets->yellow, icon_alpha + angle * 3, w/3.4);
    
    
    value = app->data["flow"][app->data["flow"].size() - 1].asFloat();
    msg = ofToString(value * 100) + " mm/s";
    
    drawIcon(4, "OPTICAL FLOW", msg, assets->icon_optical, assets->green, icon_alpha + angle * 4, w/3.4);
    
    value = app->data["temp"][app->data["temp"].size() - 1].asFloat();
    msg = ofToString(value/100) + " ºC";
    drawIcon(5, "TEMPERATURA", msg, assets->icon_termal, assets->orange, icon_alpha + angle * 5, w/3.4);
    
    ofPushMatrix();
    ofTranslate(0, h/24);
    ofPopMatrix();
    
    ofPopMatrix();
}

void Body::setMale(bool s){
    if(s)
        video = Assets::getInstance()->male_loop;
    else
        video = Assets::getInstance()->female_loop;
}

void Body::drawIcon(int n, string label, string value, ofImage icon, ofColor color, float alpha, int radius){
    int w = icon.getWidth();
    int h = icon.getHeight();
    
    float y = sin(alpha) * radius;
    float x = cos(alpha) * radius;
    
    icon.draw(x, y, w, h);
    
    ofTrueTypeFont *font = assets->getFont(12);
    
    int text_y =  y + h + font->getSize() * 1.8;
    int text_x = x + w / 2 - font->stringWidth(label)/2;
    
    font->drawStringAsShapes(label, text_x, text_y);
    ofSetColor(color);
    string msg = ofToString(n);
    font->drawStringAsShapes(msg, text_x - font->stringWidth(msg) * 1.5 , text_y);
    ofSetColor(255);
    
    font = assets->getFont(17);
    
    text_x =  x + w / 2 - font->stringWidth(value) / 2;
    font->drawStringAsShapes(value, text_x, text_y + font->getSize() * 1.4);
}
