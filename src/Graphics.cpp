#include <Graphics.h>

void Graphics::loadPetType(PetType petType){
    ifstream file("TamagatchiData/PetData.json");
    json data = json::parse(file);
    file.close();
}