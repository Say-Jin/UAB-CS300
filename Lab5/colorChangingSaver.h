#ifndef colorChangingSaver_h
#define colorChangingSaver_h

#include "classicSaver.h"
#include <vector>

using namespace std;

class ColorChangingSaver : public ClassicSaver {
    private:
        float colorSpeed;

    public:
        ColorChangingSaver();
        ColorChangingSaver(float radius, sf::Vector2f velocity, float colorSpeed);

        void setColorSpeed(float c);
        
        float getColorSpeed();

        void update(float deltaTime, int screenWidth, int screenHeight) override;
};

#endif