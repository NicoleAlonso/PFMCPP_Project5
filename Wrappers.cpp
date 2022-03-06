#include "Wrappers.h"
#include "CoffeeMachine.h"
#include "CargoShip.h"
#include "Computer.h"
#include "CoffeeShop.h"
#include "TransportTracking.h"


CoffeeMachineWrapper::CoffeeMachineWrapper(CoffeeMachine* ptr) : ptrToCoffeeMachine(ptr) {}

CoffeeMachineWrapper::~CoffeeMachineWrapper()
{
    delete ptrToCoffeeMachine;
}

CargoshipWrapper::CargoshipWrapper(CargoShip* ptr) : ptrToCargoShip(ptr) {}
CargoshipWrapper::~CargoshipWrapper()
{
    delete ptrToCargoShip;
}

ComputerWrapper::ComputerWrapper(Computer* ptr) : ptrToComputer(ptr) {}
ComputerWrapper::~ComputerWrapper()
{
    delete ptrToComputer;
}

CoffeeshopWrapper::CoffeeshopWrapper(CoffeeShop* ptr) : ptrToCoffeeShop(ptr) {}
CoffeeshopWrapper::~CoffeeshopWrapper()
{
    delete ptrToCoffeeShop;
}

TransportTrackingWrapper::TransportTrackingWrapper(TransportTracking* ptr) : ptrToTransportTracking(ptr) {}
TransportTrackingWrapper::~TransportTrackingWrapper()
{
    delete ptrToTransportTracking;
}
