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

    struct Order
    {    
        Order();
        ~Order();
        std::string customerName {"new customer"};
        int brewStrength {3};
        int numCups {1};
        std::string drinkName {"Flat White"};
        JUCE_LEAK_DETECTOR(Order)
    };

    struct Customer
    {
        Customer();
        ~Customer();
        Order getPreferredOrder();
    };
    
    void prepareOrder(int cupsOrdered, int brewStrength, std::string customerName);
    void prepareCustomerOrder(const Order& order);
    void cleanMachine(int cyclesMade);
    void printOrderedStrength() const;
    JUCE_LEAK_DETECTOR(CoffeeShop) 
};
