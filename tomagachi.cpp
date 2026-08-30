#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;



////Game Values and Attributes
const int MAX = 100;
const int DEATHDAY = 7;

enum Life {Alive, Sickly, Dead};
enum Attribute {Hunger, Thirst, Energy, Cleanliness};


//// Identifies Pet attributes and methods
class Pet{
    private:
        // Energy, Hunger, Thirst, Cleanliness attributes
        string name;
        string petType;

        map<Attribute, int> attribute{
            {Hunger, MAX},
            {Thirst, MAX},
            {Energy, MAX},
            {Cleanliness, MAX}
        };

        ////If a condititon has been at 0 for longer than 7 days, 
        //Days Since: Energy, Fed, Drank, Cleaned
        map<Attribute, int> daysSince{
            {Hunger, 0},
            {Thirst, 0},
            {Energy, MAX},
            {Cleanliness, 0}
        };

        Life life = Life::Alive;

    public:
        int feedPet(int foodVal){
            attribute[Hunger] += foodVal;
            if (attribute[Hunger] > MAX){attribute[Hunger] = MAX;}
        }

        int hydratePet(int drinkVal){
            attribute[Thirst] += drinkVal;
            if (attribute[Thirst] > MAX){attribute[Thirst] = MAX;}
        }

        int playPet(int energyVal){
            attribute[Energy] += energyVal;
            if (attribute[Energy] > MAX){attribute[Energy] = MAX;}
        }

        int cleanPet(){
            attribute[Cleanliness] = MAX;
        }

        int getDaysSince(Attribute condition){
            return daysSince[condition];
        }

        void increaseDay(){
            daysSince[Hunger]++;
            daysSince[Thirst]++;
            daysSince[Energy]++;
            daysSince[Cleanliness]++;
        }

        void resetDaysSince(Attribute condition){
            daysSince[condition] = 0;
        }

};


int main(){

}