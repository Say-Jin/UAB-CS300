#include "classicSaver.h"
#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

using namespace std;

ClassicSaver::ClassicSaver() {
    radius = 0.f;
    velocity = sf::Vector2f(0.0f, 0.0f);
    color = sf::Color::Blue;
}

ClassicSaver::ClassicSaver(float radius, sf::Vector2f velocity, sf::Color color) 
: ScreenSaver(radius, velocity, color) {}

void ClassicSaver::setRadius(float r) {
    radius = r;
}

void ClassicSaver::setVelocity(sf::Vector2f v) {
    velocity = v;
}

void ClassicSaver::setColor(sf::Color c) {
    color = c;
}

float ClassicSaver::getRadius() {
    return radius;
}

sf::Vector2f ClassicSaver::getVelocity() {
    return velocity;
}

sf::Color ClassicSaver::getColor() {
    return color;
}

void ClassicSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    getShape().move(velocity * deltaTime);

    checkWallCollision(screenWidth, screenHeight);
}