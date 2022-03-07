#pragma once
#include "LeakedObjectDetector.h"

struct CargoShip
{
    int deckSize;
    float fuelTankSize;
    int numOfCargoContainers;
    std::string shipName;
    std::string captainName;
    CargoShip();
    ~CargoShip();

    struct CargoContent
    {
        std::string contentA {"home appliances"};
        std::string contentB {"t-shirts"};
        int numItems {3500};
        CargoContent();
        ~CargoContent();

        bool contentIsFlammable(const std::string category, const int igniteLevel = 1); 
        bool contentIsToxic(const std::string toxicityType, const int classRating = 4); 
        float numItemsPerContainer(float singleItemSize, float containerSize = 38.5f);
        JUCE_LEAK_DETECTOR(CargoContent) 
    };

    void transportGoods(std::string contentTypeA, std::string contentTypeB, int amountOfContainers);
    void handleGoods(int amountOfContainers, bool shipIsEmpty = true);
    void burnFuel(const float consumptionPerKm, float travelDistance, bool shipIsLoaded = true);
    bool readyForDeparture(int containersLoaded, int containersToLoad); 
    void printCaptainName() const;

    CargoContent nextCargoLoad;
    JUCE_LEAK_DETECTOR(CargoShip) 
};
