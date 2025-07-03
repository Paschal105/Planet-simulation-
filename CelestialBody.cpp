// Copyright 2022 Paschal Ojatabu
#include <memory>
#include <string>
#include "CelestialBody.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Universe.h"
CelestialBody::CelestialBody() {
    X = 0.0000e+00;
    Y = 0.0000e+00;
    yVelocity = 0.0000e+00;
    mass = 0.0000e+00;
    xVelocity = 0.0000e+00;
}
double CelestialBody::getX() {
    return X;
}
double CelestialBody::getY() {
    return Y;
}
std::string CelestialBody::getImage() {
    return image;
}
double CelestialBody::getyVelocity() {
    return yVelocity;
}
double CelestialBody::getxVelocity() {
    return xVelocity;
}
double CelestialBody:: getxForce() {
    return xForce;
}
double CelestialBody::getyForce() {
    return yForce;
}
double CelestialBody:: getxAce() {
    return xAce;
}
double CelestialBody:: getyAce() {
    return yAce;
}
void CelestialBody::draw_planet(sf::RenderTarget& target, sf::RenderStates states) { // NOLINT
    draw(target, states);
}
double CelestialBody::getMass() {
    return mass;
}
double CelestialBody::getwindowX() {
    return windowposX;
}
double CelestialBody::getwindowY() {
    return windowposY;
}
void CelestialBody::setxForce(double F) {
    this->xForce = F;
}
void CelestialBody::setyForce(double F) {
    this->yForce = F;
}
void CelestialBody::setxAce(double Ace) {
    this->xAce = Ace;
}
void CelestialBody::setyAce(double Ace) {
    this->yAce = Ace;
}
void CelestialBody::setX(double x) {
    this->X = x;
}
void CelestialBody::setY(double y) {
    this->Y = y;
}
void CelestialBody::setxVelocity(double xVelocity) {
    this->xVelocity = xVelocity;
}
void CelestialBody::setyVelocity(double v) {
    this->yVelocity = v;
}
void CelestialBody::setMass(double m) {
    this->mass = m;
}
void CelestialBody::setImage(std::string images) {
    this->image = images;
}
int CelestialBody::getParticles() {
    return particles;
}
double CelestialBody::getRadius() {
    return radius;
}
void CelestialBody::setParticles(int num) {
    particles = num;
}
void CelestialBody::setRadius(double r) {
    radius =  r;
}
void CelestialBody::setWindowsize(double x, double y) {
    windowposX = x;
    windowposY = y;
}

CelestialBody::CelestialBody(double xPosition , double yPosition,
double xVelocity, double yVelocity, double mass, std::string filename) {
    setImage(filename);
    setX(xPosition);
    setY(yPosition);
    setxVelocity(xVelocity);
    setyVelocity(yVelocity);
    setMass(mass);
    if (!planet_texture.loadFromFile(image)) {
       exit(1);
    }
    planet_sprite.setTexture(planet_texture);
    planet_sprite.setPosition(windowposX, windowposY);
}
std::ostream &operator<<(std::ostream &output, CelestialBody &M) {
    output << M.X << " " << M.Y << " " << M.xVelocity
    << " " << M.yVelocity << " " << M.mass << " " << M.image << std::endl;
    return output;
}
std::istream &operator>>(std::istream &input, CelestialBody &M) {
    input>> M.X >> M.Y>> M.xVelocity >> M.yVelocity >> M.mass >> M.image;
    M.windowposX = (M.radius + M.X) * (500 / (2*M.radius));
    M.windowposY = (M.radius - M.Y) * (500 / (2*M.radius));
    return input;
}
