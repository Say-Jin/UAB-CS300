#ifndef classicSaver_h
#define classicSaver_h

#include "screenSaver.h"
#include <vector>

using namespace std;

class ClassicSaver : public ScreenSaver {
    private:
        float radius;
        sf::Vector2f velocity;
        sf::Color color;

    public:
        ClassicSaver();
        ClassicSaver(float radius, sf::Vector2f velocity, sf::Color color);

        void setRadius(float r);
        void setVelocity(sf::Vector2f v);
        void setColor(sf::Color c);

        float getRadius();
        sf::Vector2f getVelocity();
        sf::Color getColor();

        void update(float deltaTime, int screenWidth, int screenHeight) override;

        ~ClassicSaver() {}
};

#endif