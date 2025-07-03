// Copyright 2022 Paschal Ojatabu
#include "Universe.h"
#include "CelestialBody.h"
#include <vector>
#include <memory>
#include<math.h>  // NOLINT
#include<iostream>// NOLINT




Universe::Universe() {}

void Universe::add_planet(Universe& u) {
    std::cin >> u.particles >> u.radius;
    for (int i = 0; i < u.particles; i++) {
        u.planet.push_back(std::make_unique<CelestialBody>());
    }
    for (auto& iterator : u.planet) {
        iterator->setParticles(u.particles);
        iterator->setRadius(u.radius);
        std::cin >> *iterator;
    }
}
void Universe::drawStats() {
    std::cout << particles << std::endl;
    std::cout << radius << std::endl;
        for (auto& num2 : planet) {
          std::cout << *num2;
        }
}
void Universe::step(double seconds) {
    double G = 6.67e-11;
    double xpos, ypos;
    double xVelocity, yVelocity, xA , yA;
    double xD, yD, R, F;
    double power;
    for (auto& num : planet) {
        double xF = 0.0, yF = 0.0;
        xD = 0.0;
        yD = 0.0;
        R = 0.0;
        F = 0.0;
        for (auto& num2 : planet) {
            if (num2 == num) {
                continue;
            }
            xD = num2->getX() - num->getX();
            yD = num2->getY() - num->getY();
            R = sqrt(pow(xD, 2)  + pow(yD, 2));
            power = pow(R, 2);
            F = (G* (num->getMass()) *(num2->getMass()))/power;
            xF = xF+ F*(xD/R);
            yF = yF+  F*(yD/R);
            num->setxForce(xF);
            num->setyForce(yF);
        }
        xA =  num->getxForce()/ num->getMass();
        yA = num->getyForce() / num->getMass();
        xVelocity = (num->getxVelocity() + (xA * seconds));
        yVelocity = (num->getyVelocity() + (yA* seconds));
        xpos = num->getX() + (xVelocity* seconds);
        ypos = num->getY() + (yVelocity * seconds);
        // num->setWindowsize(xpos, ypos);
        num->setxVelocity(xVelocity);
        num->setyVelocity(yVelocity);
        num->setxAce(xA);
        num->setyAce(yA);
        num->setX(xpos);
        num->setY(ypos);
    }
}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states)const {// NOLINT
    for (auto& iterator : planet) {
        iterator->draw_planet(target, states);
    }
}
