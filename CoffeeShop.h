#pragma once
#include "LeakedObjectDetector.h"
#include "CoffeeMachine.h"
#include "Computer.h"

struct CoffeeShop
{
    CoffeeShop();
    ~CoffeeShop();

    CoffeeMachine coffeeMachine1;
    Computer pc;

    void prepareOrder(int cupsOrdered, int brewStrength, std::string customerName);
    void cleanMachine(int cyclesMade);
    void printOrderedStrength() const;
    JUCE_LEAK_DETECTOR(CoffeeShop) 
};
