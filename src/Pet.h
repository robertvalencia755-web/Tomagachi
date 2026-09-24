#ifndef PET_H
#define PET_H


class Pet{
    private:
        std::string petName;
        PetType petType;
        PetState petState;

        std::map<Attribute, int> attribute {
            {Hunger, MAX},
            {Thirst, MAX},
            {Energy, MAX},
            {Cleanliness, MAX}
        };

        std::map<Attribute, int> daysSince {
            {Hunger, 0},
            {Thirst, 0},
            {Energy, 0},
            {Cleanliness, 0}
        };

    public:
        void assignData(string name, PetType petType, PetState petState, std::map<Attribute, int> attribute, std::map<Attribute, int> daysSince);

        void feedPet(int foodVal);

        void hydratePet(int drinkVal);

        void sleepPet(int energyVal);

        void cleanPet();

        int getDaysSince(Attribute condition);

        void increaseDay();

        void resetDaysSince(Attribute condition);

};



#endif