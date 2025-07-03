// Copyright 2022 Paschal Ojatabu
#pragma once
#ifndef Universe_h
#define Universe_h
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CelestialBody.h"
#include <memory> // NOLINT
#include <vector> // NOLINT
#include<iostream> // NOLINT


class Universe : public sf::Drawable {
 public:
    Universe();
    void add_planet(Universe& u);// NOLINT
    void step(double seconds);
    void drawStats();
 private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;// NOLINT
    std::vector<std::unique_ptr<CelestialBody>> planet;
    int particles;
    double radius;
    double T;
    double deltaT;
};
#endif
