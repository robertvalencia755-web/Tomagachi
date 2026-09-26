#include <Graphics.h>

//This will load the animationData from the PetAnimations.json for the pet bitmaps
void Graphics::loadPetType(PetType petType){
    ifstream file("TamagatchiData/PetAnimations.json");
    json data = json::parse(file);
    file.close();

    json animationData;

    switch (petType){
        case DOG:
            animationData = data["Dog"];
        case CAT:
            animationData = data["Cat"];

        case HAMSTER:
            animationData = data["Hamster"];
        
        case BIRD:
            animationData = data["Bird"];
    }
}

//Set the state for graphic animations
void Graphics::setState(PetState petState){
    this->petState = petState;
}

//Menu Options
void Graphics::drawAttributes(){
    u8g2.drawXBMP(
        -3, -1,
        menuSet[AttributeMenu].width,
        menuSet[AttributeMenu].height,
        menuSet[AttributeMenu].data
    );
    
}

void Graphics::drawActions(){
    u8g2.drawXBM(
        110, 0,
        menuSet[ActionMenu].width,
        menuSet[ActionMenu].height,
        menuSet[ActionMenu].data
    );
}

ActionSelect Graphics::changeSelect(ButtonPressed pressed, ActionSelect currentSelection){
    int y = currentSelection;
    switch (pressed){
        case LEFT:
            if (y > 3){
                y -= 12;
            }
            break;

        case RIGHT:
            if (y < 51){
                y += 12;
            }
            break;
    }

    u8g2.drawFrame(115, y, 10, 10);
}

void Graphics::changeMuteIcon(){
    if (MUTED){
        unMute();
    } else {
        mute();
    }
}



void Graphics::mute(){
    u8g2.drawXBM(
        116, 52,
        menuSet[Muted].width,
        menuSet[Muted].height,
        menuSet[Muted].data
    );
}
void Graphics::unMute(){
    u8g2.drawXBM(
        116, 52,
        menuSet[UnMuted].width,
        menuSet[UnMuted].height,
        menuSet[UnMuted].data
    );
}

