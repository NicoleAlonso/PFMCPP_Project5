#include "CargoShip.h"

CargoShip::CargoShip() : 
deckSize(12000), 
fuelTankSize(1.7f), 
numOfCargoContainers(1875),
shipName("Neptuno"),
captainName("James Cook") 
{
    std::cout << "CargoShip being constructed!" << std::endl;
}

CargoShip::~CargoShip() 
{
    std::cout << "CargoShip destroyed" << std::endl;
}

CargoShip::CargoContent::CargoContent()
{
    std::cout << "CargoShip::CargoContent being constructed!" << std::endl;
}

CargoShip::CargoContent::~CargoContent() 
{
    std::cout << "CargoShip::CargoContent destroyed" << std::endl;
}

bool CargoShip::CargoContent::contentIsFlammable(const std::string& category, const int& igniteLevel)
{
    if(igniteLevel > 2 && category == "liquids")
    {   
        std::cout << "CargoContent::contentIsFlammable(): contains flammable liquids!" << std::endl;
        return true;
    }
    else if(igniteLevel > 3 && category == "solids")
    {
        std::cout << "CargoContent::contentIsFlammable(): contains flammable solids!" << std::endl;
        return true;
    }
    std::cout << "CargoContent::contentIsFlammable(): Content is not flammable" << std::endl;
    return false;
}

bool CargoShip::CargoContent::contentIsToxic(const std::string& toxicityType, const int& classRating)
{
    if(classRating > 4 && toxicityType == "biohazard")
    {
         std::cout << "CargoContent::contentIsToxic(): Content classified as biohazard!" << std::endl;
        return true;
    }
    else if(classRating > 5 && toxicityType == "corrosive")
    {
         std::cout << "CargoContent::contentIsToxic(): Content classified as corrosive!" << std::endl;
        return true;
    }
    std::cout << "CargoContent::contentIsToxic(): Content is not toxic" << std::endl;
    return false;
}

float CargoShip::CargoContent::numItemsPerContainer(float singleItemSize, float containerSize)
{
    
    std::cout << "CargoContent::numItemsPerContainer(): total items "<< numItems << std::endl;
    return (containerSize/singleItemSize) * numItems;
}

void CargoShip::transportGoods(std::string contentTypeA, std::string contentTypeB, int amountOfContainers)
{
    nextCargoLoad.contentA = contentTypeA;
    nextCargoLoad.contentB = contentTypeB;
    numOfCargoContainers = amountOfContainers;
    std::cout << "CargoContent::transportGoods() type of goods: "<< contentTypeA << ',' << contentTypeB << std::endl;
}

void CargoShip::handleGoods(int numContainersToLoad, bool shipIsEmpty)
{
    
    if(shipIsEmpty)
    {
       numContainersToLoad = deckSize / numOfCargoContainers; // ship loads amount that fits on deck size
    }
    else
    {
        numContainersToLoad *= -1 ; // means ship unloads the amount of containers
    }
    std::cout << "CargoContent::handleGoods() amount to load/unload: "<< numContainersToLoad << std::endl;
}

void CargoShip::burnFuel(const float consumptionPerKm, float travelDistance, bool shipIsLoaded)
{
    float fuelBurned;
    
    if(!shipIsLoaded)
    {
        fuelBurned = (consumptionPerKm * 0.8f) * travelDistance;
    }
     
    fuelBurned = consumptionPerKm * travelDistance;
    std::cout << "CargoContent::burnFuel() Ship "<< shipName << " consumed " << fuelBurned << " gallons" << std::endl;
}

bool CargoShip::readyForDeparture(int containersLoaded, int containersToLoad)
{
    numOfCargoContainers = containersToLoad;
    while(containersLoaded < numOfCargoContainers)
    {
        ++containersLoaded;
        std::cout << "loading containers: " << containersLoaded << std::endl;
        if(containersLoaded == numOfCargoContainers)
        {
            std::cout << "ship is ready for departure" << std::endl;
            return true;
        }
    }
    return false;
}

void CargoShip::printCaptainName() const
{
    std::cout << "Captain " << this->captainName << " will lead this ship" << std::endl;
}
