
#include <iostream>
#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine()
{
    std::cout << "CoffeeMachine being constructed!" << std::endl;
}

CoffeeMachine::~CoffeeMachine()
{
    std::cout << "CoffeeMachine destroyed" << std::endl;
}

CoffeeMachine::Settings::Settings()
{
    std::cout << "CoffeeMachine::Settings being constructed!" << std::endl;
}

CoffeeMachine::Settings::~Settings()
{
    std::cout << "CoffeeMachine::Settings destroyed" << std::endl;
}

void CoffeeMachine::Settings::setTimer(int startTime, int shutOffTime)
{
    minutesUntilShutOff = (shutOffTime - startTime) * 10;
    std::cout << "CoffeeMachine::Settings::setTimer(): " << minutesUntilShutOff << std::endl;
}

void CoffeeMachine::Settings::setBrewStrength(int newBrewStrength)
{
    brewStrength = newBrewStrength;
    waterFlowSpeed = brewStrength * 0.2f;
    std::cout << "CoffeeMachine::Settings::setBrewStrength() Waterflow speed is now: " << waterFlowSpeed << std::endl;
}

bool CoffeeMachine::Settings::flashDescalingIndicator(int waterHardness, int numCyclesMade)
{
    if (numCyclesMade * waterHardness > 100)
    {
        std::cout << "CoffeeMachine::Settings::flashDescalingIndicator(): Time to descale machine" << std::endl;
        return true;
    }
    std::cout << "CoffeeMachine::Settings::flashDescalingIndicator(): No need for descaling yet" << std::endl;
    return false;
}

void CoffeeMachine::Settings::brewing(int numOrder, int cupsBrewed)
{
    for (;cupsBrewed < numOrder; ++cupsBrewed)
    {
        std::cout << "cups brewed: " << cupsBrewed << std::endl;
    }
    std::cout << "cups brewed: " << cupsBrewed << " -> Order is ready!" << std::endl;
}

void CoffeeMachine::Settings::printTimeTilShutOff() const
{
    std::cout << "machine will shut down in: " << this->minutesUntilShutOff << " minutes" << std::endl;
}

void CoffeeMachine::heatWater(float heatTemp)
{
    wattsOfHeatingElement /= heatTemp * 90;
    std::cout << "CoffeeMachine::Settings::flashDescalingIndicator(): " << wattsOfHeatingElement << std::endl;
}

void CoffeeMachine::dripWater(int dripPerSec)
{
    brewSettings.waterFlowSpeed += dripPerSec * numDripHoles;
    std::cout << "CoffeeMachine::dripWater(): " << brewSettings.waterFlowSpeed << std::endl;
}

void CoffeeMachine::maintainHeat(float timeToMaintain, float tempInCelsius)
{
    wattsOfHeatingElement = tempInCelsius * timeToMaintain;
    std::cout << "CoffeeMachine::maintainHeat() powerConsumption: " << wattsOfHeatingElement << std::endl;
}
