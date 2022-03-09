#include <iostream>
#include "Computer.h"

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

void Computer::printDisplayBrightness() const
{
    std::cout << "display brightness is now at: " << this->displayBrightness << '%' << std::endl;
}
