// Copyright 2022 Paschal Ojatabu
#pragma once
#ifndef CelestialBody_h
#define CelestialBody_h
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory> // NOLINT
#include <string> // NOLINT
#include<iostream>   // NOLINT
#include <stdlib.h> // NOLINT

class CelestialBody : public sf::Drawable{
 public:
    CelestialBody();
    double getX();
    double getY();
    double getyVelocity();
    double getMass();
    double getxVelocity();
    std::string getImage();
    int getParticles();
    double getRadius();
    double getxForce();
    double getyForce();
    double getxAce();
    double getyAce();
    double getwindowY();
    double getwindowX();

    void setWindowsize(double x, double y);
    void setxForce(double F);
    void setyForce(double F);
    void setxAce(double Ace);
    void setyAce(double Ace);
    void setParticles(int num);
    void setRadius(double r);
    void setImage(std::string images);
    void setxVelocity(double xVelocity);
    void setX(double x);
    void setY(double y);
    void setyVelocity(double v);
    void setMass(double m);
    void draw_planet(sf::RenderTarget& target, sf::RenderStates states); // NOLINT
CelestialBody(double xPosition , double yPosition,
double xVelocity, double yVelocity, double mass, std::string filename);
friend std::istream &operator>>(std::istream &intput, CelestialBody &M);
friend std::ostream &operator<<(std::ostream &output, CelestialBody &M);

 private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const {// NOLINT
    sf::Texture planet_texture = this->planet_texture;
    sf::Sprite nimage;
    double xpos, ypos;
    CelestialBody m;
    xpos = (radius + X) * (500 / (2*radius));
    ypos = (radius - Y) * (500 / (2*radius));
    m.setWindowsize(xpos, ypos);
    if (!planet_texture.loadFromFile(image)) {
       exit(1);
    }
    nimage.setTexture(planet_texture);
    nimage.setPosition(m.getwindowX(), m.getwindowY());
    target.draw(nimage, states);
    }
    sf::Sprite planet_sprite;
    sf::Texture planet_texture;
    // sf::Image uImage;
    std::string image;
    double X;
    double Y;
    double yVelocity;
    double mass;
    double xVelocity;
    double radius;
    int  particles;
    double xForce;
    double yForce;
    double xAce;
    double yAce;
    double windowposX;
    double windowposY;
};
#endif
