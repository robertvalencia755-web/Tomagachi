#include <Pet.h>

using namespace std;


//// Identifies Pet attributes and methods


void Pet::assignData(string name, PetType petType, PetState petState, std::map<Attribute, int> attribute, std::map<Attribute, int> daysSince){
    this->petName = name;
    this->petType = petType;
    this->petState = petState;
    this->attribute = attribute;
    this->daysSince = daysSince;
}

void Pet::feedPet(int foodVal){
    attribute[Hunger] += foodVal;
    if (attribute[Hunger] > MAX){attribute[Hunger] = MAX;}
}

void Pet::hydratePet(int drinkVal){
    attribute[Thirst] += drinkVal;
    if (attribute[Thirst] > MAX){attribute[Thirst] = MAX;}
}

void Pet::sleepPet(int energyVal){
    attribute[Energy] += energyVal;
    if (attribute[Energy] > MAX){attribute[Energy] = MAX;}
}

void Pet::cleanPet(){
    attribute[Cleanliness] = MAX;
}

int Pet::getDaysSince(Attribute condition){
    return daysSince[condition];
}

void Pet::increaseDay(){
    daysSince[Hunger]++;
    daysSince[Thirst]++;
    daysSince[Energy]++;
    daysSince[Cleanliness]++;
}

void Pet::resetDaysSince(Attribute condition){
    daysSince[condition] = 0;
}
