
struct CoffeeMachine;
struct CargoShip;
struct Computer;
struct CoffeeShop;
struct TransportTracking;

struct CoffeeMachineWrapper
{
    CoffeeMachineWrapper(CoffeeMachine* ptr);
    ~CoffeeMachineWrapper();
    CoffeeMachine* ptrToCoffeeMachine = nullptr;
};

struct CargoshipWrapper
{
    CargoshipWrapper(CargoShip* ptr);
    ~CargoshipWrapper();
    CargoShip* ptrToCargoShip = nullptr;
};

struct ComputerWrapper
{
    ComputerWrapper(Computer* ptr);
    ~ComputerWrapper();
    Computer* ptrToComputer = nullptr;
};

struct CoffeeshopWrapper
{
    CoffeeshopWrapper(CoffeeShop* ptr);
    ~CoffeeshopWrapper();
    CoffeeShop* ptrToCoffeeShop = nullptr;
};

struct TransportTrackingWrapper
{
    TransportTrackingWrapper(TransportTracking* ptr);
    ~TransportTrackingWrapper();
    TransportTracking* ptrToTransportTracking = nullptr;
};
