#ifndef GAMETYPE_H
#define GAMETYPE_H
#include <iostream>
#include <fstream>
#include <map>
#include <stdio.h>
#include <json.hpp>
#include <Arduino.h>

////Game Values and Attributes
const int MAX = 100;

enum PetState {AWAKE, SLEEPING, EATING, DEAD};
enum Attribute {Hunger, Thirst, Energy, Cleanliness};
enum PetType {Dog, Cat, Hamster, Bird};

//map of days that stats can remain 0 before death
const std::map<Attribute, int> DEATHDAY{
    {Hunger, 5},
    {Thirst, 3},
    {Energy, 8},
    {Cleanliness, 8}
};

const string userName = " ";


#endif