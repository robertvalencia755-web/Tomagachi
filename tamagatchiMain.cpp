#include <iostream>
#include <fstream>
#include <map>
#include <stdio.h>
#include <Dependency/json.hpp>

using namespace std;
using json = nlohmann::json;


////Game Values and Attributes
const int MAX = 100;
const int DEATHDAY = 7;
const string userName = " ";

enum Life {Alive, Sickly, Dead};
enum Attribute {Hunger, Thirst, Energy, Cleanliness};
enum PetType {Dog, Cat, Rat, Bunny, Crow};

//map of days that stats can remain 0 before death
map<Attribute, int> DEATHDAY{
    {Hunger, 7},
    {Thirst, 3},
    {Energy, 10},
    {Cleanliness, 8}
};


//// Identifies Pet attributes and methods
class Pet{
    private:
        // Energy, Hunger, Thirst, Cleanliness attributes
        string petName;
        PetType petType;
        Life life = Alive;


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

        

    public:

        void assignData(string name, PetType petType, Life life, map<Attribute, int> attribute, map<Attribute, int> daysSince){
            this->petName = name;
            this->petType = petType;
            this->life = life;
            this->attribute = attribute;
            this->daysSince = daysSince;
        }

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


//Initalizes all variables from local storage in the case battery dies.
//Use DS1374 for SiT1532
class gameIntruct{
    int deviceInitialization(Pet *pet){
        //Read the PetData.json file
        ifstream file("PetData.json");
        json data;
        data = json::parse(file);
        file.close();

        //Check if dead, if true, prompt info
        if(data["userName"] == " "){
            promptInfo(pet);
        } else if(data["life"] == Dead){
            //Death Prompt
        }else {
            //Assign *pet pointer object with necessary variables
            pet->assignData(data["petName"], data["petType"], data["life"], data["attribute"], data["daysSince"]);
        }
        
    }

    //For first initialization, assign user and pet names / type
    void promptInfo(Pet *pet){
        //Prompt user for names from arduino interface
    }

    void deathPrompt(Pet *pet){
        //Show death screen 
    }
};



//Main Tamagatchi running program
int main(){
    //Create pet object
    //

}