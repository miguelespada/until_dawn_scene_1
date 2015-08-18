//
//  temperature.cpp
//  until_dawn_screen_2
//
//  Created by miguel on 16/07/15.
//
//

#include "body.h"

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
    drawIcon(assets->icon_heart, icon_alpha + angle, w/3.4);
    drawIcon(assets->icon_hand, icon_alpha + angle * 2, w/3.4);
    drawIcon(assets->icon_pressure, icon_alpha + angle * 3, w/3.4);
    drawIcon(assets->icon_optical, icon_alpha + angle * 4, w/3.4);
    drawIcon(assets->icon_termal, icon_alpha + angle * 5, w/3.4);
    
    drawCircle(w/6);
    ofPopMatrix();
    
    
    assets->logos.draw(0, 0, w, h);
    assets->lineas.draw(0, 0, w, h);
    assets->degradado.draw(0, 0, w, h);
    
    
}

void Body::setMale(bool s){
    if(s)
        video = Assets::getInstance()->male_loop;
    else
        video = Assets::getInstance()->female_loop;
}

void Body::drawIcon(ofImage icon, float alpha, int radious){
    int w = icon.getWidth() * assets->getScale();
    int h = icon.getHeight() * assets->getScale();
    
    float y = sin(alpha) * radious;
    float x = cos(alpha) * radious;
    
    icon.draw(x, y, w, h);
    
    string msg = "PRESIÓN ARTERIAL";
    assets->setFont(16);
    ofTrueTypeFont font = assets->font;
    
    font.drawString(msg, x + w / 2 - font.stringWidth(msg) / 2, y + h + font.getSize() * 1.8);

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
