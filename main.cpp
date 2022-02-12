/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */
#include <iostream>
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
    };

    void heatWater(float tempInCelsius = 93.4f);
    void dripWater(int dripInterval = 2);
    void maintainHeat(float timeToMaintain = 5.5f, float tempInCelsius = 85.0f);

    Settings brewSettings;
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
    };

    void transportGoods(std::string contentTypeA, std::string contentTypeB, int amountOfContainers);
    void handleGoods(int amountOfContainers, bool shipIsEmpty = true);
    void burnFuel(float consumptionPerKm, float travelDistance, bool shipIsLoaded = true);
    bool readyForDeparture(int containersLoaded, int containersToLoad); 

    CargoContent nextCargoLoad;
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
    std::string database = "added " + fileName;
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
/*
 new UDT 4:
 with 2 member functions
 */
struct CoffeeShop
{
    CoffeeShop();
    ~CoffeeShop();

    CoffeeMachine coffeeMachine1;

    void prepareOrder(int cupsOrdered, int brewStrength);
    void cleanMachine(int cyclesMade);

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
    else
        return;
}

void CoffeeShop::prepareOrder(int cupsOrdered, int orderedStrength)
{
    coffeeMachine1.brewSettings.brewStrength = orderedStrength;
    coffeeMachine1.brewSettings.brewing(cupsOrdered, 0);
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
        std::cout << "tracking status: transport still in process..." << std::endl;
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

#include <iostream>
int main()
{
    CoffeeMachine nespressoMachine;
    CoffeeMachine::Settings coffeeSettings;

    nespressoMachine.heatWater(95.0f);
    nespressoMachine.dripWater(4);

    coffeeSettings.setBrewStrength(3);
    coffeeSettings.setTimer(7, 8);
    coffeeSettings.flashDescalingIndicator(3, 101);
    coffeeSettings.brewing(3, 1);
    std::cout << "machine will shut down in: " << coffeeSettings.minutesUntilShutOff << " minutes" << std::endl;
    std::cout << "-------------------" << std::endl;

    CargoShip ship;
    CargoShip::CargoContent amazonItems;
    
    ship.transportGoods("fridges", " washmachines", 250);
    ship.burnFuel(80.5f, 800.0f, true);
    ship.readyForDeparture(0, 5);

    amazonItems.contentIsFlammable("liquids", 3);
    amazonItems.contentIsToxic("corrosive", 2);
    std::cout << "Captain " << ship.captainName << " will lead this ship" << std::endl;
    std::cout << "-------------------" << std::endl;
   
    Computer macBook;
    macBook.storeData(5, 64, "invoices");
    macBook.processData(20.0f, 0.05f);
    macBook.displayData("new message", false);
    macBook.changeDisplayBrightness(84);
    std::cout << "display brightness is now at: " << macBook.displayBrightness << '%' << std::endl;
    std::cout << "-------------------" << std::endl;

    CoffeeShop LuigisCafe;
    LuigisCafe.cleanMachine(45);
    LuigisCafe.prepareOrder(2, 4);
    std::cout << "-------------------" << std::endl;

    TransportTracking trackingOrder;
    trackingOrder.transportStatus(1,3);
    trackingOrder.displayTransportItems();
    std::cout << "-------------------" << std::endl;

    std::cout << "good to go!" << std::endl;
}
