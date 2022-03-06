#pragma once
#include "LeakedObjectDetector.h"

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
