#include <iostream>
#include <map>

using namespace std;
//Pet Interface;
//Each pet has a the following attributes:
//  lifeStatus(Healthy, Sickly, Dead), conditionsList(Hungry, Dirty, Thirsty, Bored), 


//Game Values
const int MAX = 100;
const int DEATHDAY = 7;


enum Life {Alive, Sickly, Dead};
enum Attribute {Energy, Hunger, Thirst, Cleanliness};

class Pet{
    private:
        // Energy, Hunger, Thirst, Cleanliness attributes
        map<Attribute, int> attribute{
            {Energy, MAX},
            {Hunger, MAX},
            {Thirst, MAX},
            {Cleanliness, MAX}
        };

        ////If a condititon has been at 0 for longer than 7 days, 
        //Days Since: Energy, Fed, Drank, Cleaned
        map<Attribute, int> daysSince{
            {Energy, 0},
            {Hunger, 0},
            {Thirst, 0},
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
            if (attribute[Cleanliness] > MAX){attribute[Cleanliness] = MAX;}
        }

        int getDaysSince(Attribute condition){
            return daysSince[condition];
        }
        int resetDaysSince(Attribute condition){
            daysSince[condition] = 0;
            return 1;
        }

};




int main(){

}