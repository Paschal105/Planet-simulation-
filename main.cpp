// Copyright 2022 Paschal Ojatabu
/**
 * Name : paschal Ojatabu 
 * subject : Comp iv 
 * hours: 3 days 
 * intructor: Dr Daly 
 * IDe : vscode 
 * system: windows 
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include "CelestialBody.h"
#include "Universe.h"
#include <memory>
#include<string>
#include<iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



int main(int argc, char* argv[]) {
    sf::Image background;
    Universe solarSystem;
    // CelestialBody body;
    char *Ti;
    char *change_t;
    double T;
    double num = 0;
    int n = 0;
    double t;
    Ti = argv[1];
    change_t = argv[2];
    T = atof(Ti);
    t = atof(change_t);
    solarSystem.add_planet(solarSystem);
    if (!background.loadFromFile("starfield.jpg")) {
        return -1;
    }
    sf::RenderWindow window(sf::VideoMode(500, 500), "Solar system");
    sf::Texture backTexture;
    backTexture.loadFromImage(background);
    sf::Sprite backSprite;
    backSprite.setTexture(backTexture);
    window.setFramerateLimit(40);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
         window.draw(backSprite);
        if (num < T) {
            if (n < 5) {
            solarSystem.drawStats();
            std::cout << std::endl;
        }
        solarSystem.step(t);
        window.draw(solarSystem);
        num += t;
        n+= 1;
       }
        window.display();
    }

    return 0;
}
