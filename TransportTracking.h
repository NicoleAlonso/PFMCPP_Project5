#pragma once
#include "LeakedObjectDetector.h"
#include "CargoShip.h"
#include "Computer.h"

struct TransportTracking
{
    TransportTracking();
    ~TransportTracking();

    CargoShip transport;
    Computer computer;

    void transportStatus(int loaded, int toLoad);
    void displayTransportItems();
    JUCE_LEAK_DETECTOR(TransportTracking) 
};
