
#include "TransportTracking.h"

TransportTracking::TransportTracking()
{
    std::cout << "TransportTracking being constructed" << std::endl;
}

TransportTracking::~TransportTracking()
{
    std::cout << "TransportTracking destroyed" << std::endl;
}

void TransportTracking::transportStatus(int loaded, int toLoad)
{
    if(transport.readyForDeparture(loaded, toLoad))
    {
        computer.storeData(1, 24, "registered transport");
        std::cout << "tracking status: Delivery is on its way" << std::endl;
    }
    else
    {
        std::cout << "tracking status: transport still in process..." << std::endl;
    }  
}

void TransportTracking::displayTransportItems()
{
    computer.displayData(transport.nextCargoLoad.contentA, true);
}
