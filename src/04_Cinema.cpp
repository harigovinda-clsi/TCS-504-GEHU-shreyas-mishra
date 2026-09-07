#pragma once
#include <string>
#include <vector>
#include "03_Screen.cpp"

class Cinema {
private:
    std::string name;
    std::vector<Screen> screens; // OOP Concept: Composition (Cinema owns Screens)

public:
    explicit Cinema(std::string name) : name(name) {}

    void addScreen(const Screen& screen) {
        screens.push_back(screen);
    }

    std::string getName() const { return name; }
    const std::vector<Screen>& getScreens() const { return screens; }
};
