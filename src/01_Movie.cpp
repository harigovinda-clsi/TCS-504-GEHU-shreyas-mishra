#pragma once
#include <string>

// OOP Concept: Encapsulation (Private metadata with public getters)
class Movie {
private:
    std::string title;
    std::string language;
    int durationMinutes;

public:
    Movie(std::string title, std::string language, int durationMinutes)
        : title(title), language(language), durationMinutes(durationMinutes) {}

    std::string getTitle() const { return title; }
    std::string getLanguage() const { return language; }
    int getDuration() const { return durationMinutes; }
};
