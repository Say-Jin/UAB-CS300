#include "colorChangingSaver.h"
#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

using namespace std;

ColorChangingSaver::ColorChangingSaver() {
    float radius = 0.f;
    sf::Vector2f velocity = sf::Vector2f(0.0f, 0.0f);
    colorSpeed = 0.f;

}

ColorChangingSaver::ColorChangingSaver(float radius, sf::Vector2f velocity, float colorSpeed) 
: ClassicSaver(radius, velocity, sf::Color::White), colorSpeed(colorSpeed) {}

void ColorChangingSaver::setColorSpeed(float c) {
    colorSpeed = c;
}

float ColorChangingSaver::getColorSpeed() {
    return colorSpeed;
}

void ColorChangingSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    ClassicSaver::update(deltaTime, screenWidth, screenHeight);
    static float timeElapsed = 0;
    timeElapsed += deltaTime;

    sf::Uint8 red = static_cast<sf::Uint8>((std::sin(colorSpeed * timeElapsed) + 1) * 127);
    sf::Uint8 green = static_cast<sf::Uint8>((std::sin(colorSpeed * timeElapsed + 2) + 1) * 127);
    sf::Uint8 blue = static_cast<sf::Uint8>((std::sin(colorSpeed * timeElapsed + 4) + 1) * 127);
    getShape().setFillColor(sf::Color(red, green, blue));
}