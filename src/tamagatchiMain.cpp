#include <GameTypes.h>
#include <Pet.h>

using json = nlohmann::json;
using namespace std;


//Initalizes all variables from local storage in the case battery dies.

//Use DS1374 for SiT1532
class GameInstruct{
    public:
    int deviceInitialization(Pet *pet){
        //Read the PetData.json file
        ifstream file("TamagatchiAssets/PetData.json");
        json data = json::parse(file);
        file.close();

        //Check if dead, if true, prompt info
        if(data["FirstStart?"] == 0){
            promptInfo(pet);
        } else if(data["life"] == DEAD){
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


void updateGraphics(PetType petType, Life life){
    //if awake/idle state, do idle animation
    //if sleeping, do sleeping animatoin

}




//Main Tamagatchi running program
void setup(){
    //Initialize game and load data
    GameInstruct game;
    Pet userPet;
    game.deviceInitialization(&userPet);

    



}

void loop(){


}