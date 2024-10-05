#include "customSaver.h"
#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

using namespace std;

CustomSaver::CustomSaver() {
    someFloat = 0.f;
    someVector = sf::Vector2f(0.0f, 0.0f);
    someOtherFloat = 0.f;
}

CustomSaver::CustomSaver(float someFloat, sf::Vector2f someVector, float someOtherFloat) 
: ScreenSaver(50.0f, velocity, sf::Color::Blue), someFloat(someFloat), someOtherFloat(someOtherFloat) {
    velocity = someVector;
}

void CustomSaver::setSomeFloat(float s) {
    someFloat = s;
}

void CustomSaver::setSomeVector(sf::Vector2f v) {
    someVector = v;
}

void CustomSaver::setSomeOtherFloat(float f) {
    someOtherFloat = f;
}

float CustomSaver::getSomeFloat() {
    return someFloat;
}

sf::Vector2f CustomSaver::getSomeVector() {
    return someVector;
}

float CustomSaver::getSomeOtherFloat() {
    return someOtherFloat;
}

void CustomSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    getShape().move(velocity * deltaTime);
    checkWallCollision(screenWidth, screenHeight);
    static float timeElapsed = 0;
    timeElapsed += deltaTime;

    float newSize =sin(timeElapsed * someOtherFloat) * someFloat + 50;
    getShape().setRadius(newSize);
}