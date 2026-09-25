#ifndef GAMETYPE_H
#define GAMETYPE_H
#include <iostream>
#include <fstream>
#include <map>
#include <stdio.h>
#include <json.hpp>
#include <Arduino.h>
using json = nlohmann::json;
using namespace std;

////Game Values and Attributes
const int MAX = 100;

enum PetState {AWAKE, SLEEPING, EATING, DEAD};
enum Attribute {Hunger, Thirst, Energy, Cleanliness};
enum PetType {DOG, CAT, HAMSTER, BIRD};
enum Animation {IdleAnimation, IdleRandomAnimation, SoundAnimation, EatingAnimation, DrinkingAnimation, SleepingAnimation, CleaningAnimation, AttributeIcons, OptionIcons, OptionSelect, Muted, UnMuted};
enum ButtonPressed {LEFT, MIDDLE, RIGHT, NONE};


//map of days that stats can remain 0 before death
const std::map<Attribute, int> DEATHDAY{
    {Hunger, 5},
    {Thirst, 3},
    {Energy, 8},
    {Cleanliness, 8}
};

string userName = " ";

//Hardware Connections
ButtonPressed pressed = NONE;
const int LEFT_BUTTON = 20;
const int MIDDLE_BUTTON = 21;
const int RIGHT_BUTTON = 22;
const int SPEAKER_PIN = 10;
const int DISPLAY_PIN = 10;

#endif