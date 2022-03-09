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

CoffeeShop::Order::Order()
{
    std::cout << "CoffeeShop::Order being constructed" << std::endl;
}

CoffeeShop::Order::~Order()
{
    std::cout << "CoffeeShop::Order destroyed" << std::endl;
}

CoffeeShop::Customer::Customer(std::string n, std::string d) : name(n), drink(d)
{
    std::cout << "CoffeeShop::Customer being constructed" << std::endl;
}

CoffeeShop::Customer::~Customer()
{
    std::cout << "CoffeeShop::Customer destroyed" << std::endl;
}

CoffeeShop::Order CoffeeShop::Customer::getPreferredOrder()
{
    CoffeeShop::Order customOrder;
    customOrder.customerName = name;
    customOrder.drinkName = drink;
    customOrder.numCups = 2;
    customOrder.brewStrength = 4;
    std::cout << "creating drink: " << customOrder.drinkName << " for " << customOrder.customerName << std::endl;
    return customOrder;
}

void CoffeeShop::prepareCustomerOrder(const Order& order)
{
    prepareOrder(order.numCups, order.brewStrength, order.customerName);
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
