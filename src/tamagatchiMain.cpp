#include <GameTypes.h>
#include <Pet.h>

//Use DS1374 for SiT1532
class GameInstruct{
    public:
    //Initialized data from storage
    int deviceInitialization(Pet *pet){
        //Initialize pins
        pinMode(LEFT, INPUT_PULLUP);
        pinMode(MIDDLE, INPUT_PULLUP);
        pinMode(RIGHT, INPUT_PULLUP);


        //Read the PetData.json file
        ifstream file("TamagatchiData/PetData.json");
        json data = json::parse(file);
        file.close();

        //Check if dead, if true, prompt info
        if(data["FirstStart?"] == 0){
            promptInfo(pet);
        } else if(data["life"] == DEAD){
            //Death Prompt
        }else {
            //Assign *pet pointer object with necessary variables
            pet->assignData(data["petName"], data["petType"], data["petState"], data["attribute"], data["daysSince"]);
        }
        
    }


    //Check the input from user
    void checkInput(){
        if (digitalRead(LEFT_BUTTON) == LOW){
            pressed = LEFT;
        } else if (digitalRead(MIDDLE_BUTTON) == LOW){
            pressed = MIDDLE;
        } else if (digitalRead(RIGHT_BUTTON) == LOW){
            pressed = RIGHT;
        } else {
            pressed = NONE;
        }
    }

    //Update the graphics, for animations
    void updateGraphics(){

    }
    //For first initialization, assign user and pet names / type
    void promptInfo(Pet *pet){
        //Prompt user for names from arduino interface
    }

    void deathPrompt(Pet *pet){
        //Show death screen 
    }

};


void updateGraphics(PetType petType, PetState petState){
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
    game.checkInput();

}