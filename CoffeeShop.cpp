#include <iostream>
#include "CoffeeShop.h"

CoffeeShop::CoffeeShop()
{
    std::cout << "CoffeeShop being constructed" << std::endl;
}

CoffeeShop::~CoffeeShop()
{
    std::cout << "CoffeeShop destroyed" << std::endl;
}

void CoffeeShop::cleanMachine(int cyclesMade)
{
    if(coffeeMachine1.brewSettings.flashDescalingIndicator(3, cyclesMade))
    {
        std::cout << "starting descaling program for " << coffeeMachine1.brandName << " machine 1 ..." << std::endl;
        std::cout << "resetting cycle counter... program finished!" << std::endl;
    }
}

void CoffeeShop::prepareOrder(int cupsOrdered, int orderedStrength, std::string customerName)
{
    pc.storeData(1, 12, customerName);
    coffeeMachine1.brewSettings.brewStrength = orderedStrength;
    coffeeMachine1.brewSettings.brewing(cupsOrdered, 0);
}

void CoffeeShop::printOrderedStrength() const
{
    std::cout << "ordered brew strength: " << this->coffeeMachine1.brewSettings.brewStrength << std::endl;
}
