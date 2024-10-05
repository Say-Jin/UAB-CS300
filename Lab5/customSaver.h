#ifndef customSaver_h
#define customSaver_h

#include "screenSaver.h"
#include <vector>

using namespace std;

class CustomSaver : public ScreenSaver {
    private:
        float someFloat;
        sf::Vector2f someVector;
        float someOtherFloat;

    public:
        CustomSaver();
        CustomSaver(float someFloat, sf::Vector2f someVector, float someOtherFloat);

        void setSomeFloat(float f);
        void setSomeVector(sf::Vector2f v);
        void setSomeOtherFloat(float o);

        float getSomeFloat();
        sf::Vector2f getSomeVector();
        float getSomeOtherFloat();

        void update(float deltaTime, int screenWidth, int screenHeight) override;
};

#endif