/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by const reference.
*/
#if false
void someMemberFunction(const Axe& axe);
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




#include <iostream>
#include "LeakedObjectDetector.h"
/*
 copied UDT 1:
 */
struct CoffeeMachine
{
    std::string brandName {"Krups"};
    float waterReservoirCapacity {2839.06f};
    int waterTubes {2};
    int numDripHoles {12};
    float wattsOfHeatingElement {1200.0f};
    CoffeeMachine();
    ~CoffeeMachine();

    struct Settings
    {
        int brewStrength {4};
        int numCupsToBrew {2};
        int minutesUntilShutOff {15};
        float waterHardnessSetting {2.5f};
        float waterFlowSpeed {0.8f};
        Settings();
        ~Settings();

        void setTimer(int brewStart = 0, int minutesUntilShutOff = 20);
        void setBrewStrength(int brewStrength);
        bool flashDescalingIndicator(int waterHardness, int numCyclesMade);
        void brewing(int numOrder, int cupsBrewed);
        void printTimeTilShutOff();
        JUCE_LEAK_DETECTOR(Settings)
    };

    void heatWater(float tempInCelsius = 93.4f);
    void dripWater(int dripInterval = 2);
    void maintainHeat(float timeToMaintain = 5.5f, float tempInCelsius = 85.0f);

    Settings brewSettings;
    JUCE_LEAK_DETECTOR(CoffeeMachine)
};

struct CoffeeMachineWrapper
{
    CoffeeMachineWrapper(CoffeeMachine* ptr) : ptrToCoffeeMachine(ptr) {}
    ~CoffeeMachineWrapper()
    {
        delete ptrToCoffeeMachine;
    }

    CoffeeMachine* ptrToCoffeeMachine = nullptr;
};

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

void CoffeeMachine::Settings::printTimeTilShutOff()
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

/*
 copied UDT 2:
 */
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
        std::string contentA{"home appliances"};
        std::string contentB {"t-shirts"};
        int numItems {3500};
        CargoContent();
        ~CargoContent();

        bool contentIsFlammable(std::string category, int igniteLevel = 1); 
        bool contentIsToxic(std::string toxicityType, int classRating = 4); 
        float numItemsPerContainer(float singleItemSize, float containerSize = 38.5f);
        JUCE_LEAK_DETECTOR(CargoContent) 
    };

    void transportGoods(std::string contentTypeA, std::string contentTypeB, int amountOfContainers);
    void handleGoods(int amountOfContainers, bool shipIsEmpty = true);
    void burnFuel(float consumptionPerKm, float travelDistance, bool shipIsLoaded = true);
    bool readyForDeparture(int containersLoaded, int containersToLoad); 
    void printCaptainName();

    CargoContent nextCargoLoad;
    JUCE_LEAK_DETECTOR(CargoShip) 
};

struct CargoshipWrapper
{
    CargoshipWrapper(CargoShip* ptr) : ptrToCargoShip(ptr) {}
    ~CargoshipWrapper()
    {
        delete ptrToCargoShip;
    }

    CargoShip* ptrToCargoShip = nullptr;
};

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

bool CargoShip::CargoContent::contentIsFlammable(std::string category, int igniteLevel)
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

bool CargoShip::CargoContent::contentIsToxic(std::string toxicityType, int classRating)
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

void CargoShip::burnFuel(float consumptionPerKm, float travelDistance, bool shipIsLoaded)
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

void CargoShip::printCaptainName()
{
    std::cout << "Captain " << this->captainName << " will lead this ship" << std::endl;
}
/*
 copied UDT 3:
 */
struct Computer
{
    double storageInGb {500.0};
    float processorSpeed {3.5f};
    float displaySize {13.0f};
    int displayBrightness {80};
    std::string manufacturer {"Apple"};
    Computer();
    ~Computer();

    void storeData(int numFiles, int fileSize, std::string fileName = "unknown");
    void processData(float amountToProcess, float timeToProcess = 0.02f);
    void displayData(std::string fileName = "unknown", bool fullscreen = false);
    void changeDisplayBrightness(int newBrightVal);
    void printDisplayBrightness();
    JUCE_LEAK_DETECTOR(Computer) 
};

struct ComputerWrapper
{
    ComputerWrapper(Computer* ptr) : ptrToComputer(ptr) {}
    ~ComputerWrapper()
    {
        delete ptrToComputer;
    }

    Computer* ptrToComputer = nullptr;
};

Computer::Computer()
{
    std::cout << "Computer being constructed!" << std::endl;
}

Computer::~Computer()
{
    std::cout << "Computer destroyed" << std::endl;
}

void Computer::storeData(int numFiles, int fileSize, std::string fileName)
{
    std::string database = "added " + fileName + " to database";
    storageInGb -= numFiles * fileSize;
    std::cout << "Computer::storeData() " << database << std::endl;
}

void Computer::processData(float amountToProcess, float timeToProcess)
{
    processorSpeed = amountToProcess * timeToProcess;
    std::cout << "Computer::processData() speed: " << processorSpeed << std::endl;
}

void Computer::displayData(std::string fileName, bool fullscreen)
{
    if (!fullscreen)
        displaySize *= 0.5f;

    std::string displayText = "file contains: " + fileName;    
    std::cout << "Computer::displayData(): " << displayText << std::endl;
}

void Computer::changeDisplayBrightness(int newBrightVal)
{
    if(newBrightVal > displayBrightness)
    {
        for(; displayBrightness < newBrightVal; ++displayBrightness)
        {
            std::cout << "increasing brightness: " << displayBrightness << std::endl;
        }
    }
    else
    {
        for(; displayBrightness > newBrightVal; --displayBrightness)
        {
            std::cout << "decreasing brightness: " << displayBrightness << std::endl;
        }
    }  
}

void Computer::printDisplayBrightness()
{
    std::cout << "display brightness is now at: " << this->displayBrightness << '%' << std::endl;
}

/*
 new UDT 4:
 with 2 member functions
 */
struct CoffeeShop
{
    CoffeeShop();
    ~CoffeeShop();

    CoffeeMachine coffeeMachine1;
    Computer pc;

    void prepareOrder(int cupsOrdered, int brewStrength, std::string customerName);
    void cleanMachine(int cyclesMade);
    void printOrderedStrength();
    JUCE_LEAK_DETECTOR(CoffeeShop) 
};

struct CoffeeshopWrapper
{
    CoffeeshopWrapper(CoffeeShop* ptr) : ptrToCoffeeShop(ptr) {}
    ~CoffeeshopWrapper()
    {
        delete ptrToCoffeeShop;
    }

    CoffeeShop* ptrToCoffeeShop = nullptr;
};

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

void CoffeeShop::printOrderedStrength()
{
    std::cout << "ordered brew strength: " << this->coffeeMachine1.brewSettings.brewStrength << std::endl;
}

/*
 new UDT 5:
 with 2 member functions
 */
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

struct TransportTrackingWrapper
{
    TransportTrackingWrapper(TransportTracking* ptr) : ptrToTransportTracking(ptr) {}
    ~TransportTrackingWrapper()
    {
        delete ptrToTransportTracking;
    }

    TransportTracking* ptrToTransportTracking = nullptr;
};

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
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    CoffeeMachineWrapper nespresso(new CoffeeMachine());
    CoffeeMachine::Settings coffeeSettings;

    nespresso.ptrToCoffeeMachine->heatWater(95.0f);
    nespresso.ptrToCoffeeMachine->dripWater(4);

    coffeeSettings.setBrewStrength(3);
    coffeeSettings.setTimer(7, 8);
    coffeeSettings.flashDescalingIndicator(3, 101);
    coffeeSettings.brewing(3, 1);
    std::cout << "machine will shut down in: " << coffeeSettings.minutesUntilShutOff << " minutes" << std::endl;
    coffeeSettings.printTimeTilShutOff();
    std::cout << "-------------------" << std::endl;

    CargoshipWrapper ship(new CargoShip());
    CargoShip::CargoContent amazonItems;
    
    ship.ptrToCargoShip->transportGoods("fridges", " washmachines", 250);
    ship.ptrToCargoShip->burnFuel(80.5f, 800.0f, true);
    ship.ptrToCargoShip->readyForDeparture(0, 5);

    amazonItems.contentIsFlammable("liquids", 3);
    amazonItems.contentIsToxic("corrosive", 2);
    std::cout << "Captain " << ship.ptrToCargoShip->captainName << " will lead this ship" << std::endl;
    ship.ptrToCargoShip->printCaptainName();
    std::cout << "-------------------" << std::endl;
   
    //Computer macBook;
    ComputerWrapper macBook(new Computer());
    macBook.ptrToComputer->storeData(5, 64, "invoices");
    macBook.ptrToComputer->processData(20.0f, 0.05f);
    macBook.ptrToComputer->displayData("new message", false);
    macBook.ptrToComputer->changeDisplayBrightness(84);
    std::cout << "display brightness is now at: " << macBook.ptrToComputer->displayBrightness << '%' << std::endl;
    macBook.ptrToComputer->printDisplayBrightness();
    std::cout << "-------------------" << std::endl;

    CoffeeshopWrapper luigisCafe(new CoffeeShop());
    luigisCafe.ptrToCoffeeShop->cleanMachine(45);
    luigisCafe.ptrToCoffeeShop->prepareOrder(2, 5, "Tom Miller");
    std::cout << "ordered brew strength: " << luigisCafe.ptrToCoffeeShop->coffeeMachine1.brewSettings.brewStrength << std::endl;
    luigisCafe.ptrToCoffeeShop->printOrderedStrength();
    std::cout << "-------------------" << std::endl;

    TransportTrackingWrapper trackingOrder(new TransportTracking());
    trackingOrder.ptrToTransportTracking->transportStatus(1,3);
    trackingOrder.ptrToTransportTracking->displayTransportItems();
    std::cout << "-------------------" << std::endl;

    std::cout << "good to go!" << std::endl;
    
}
