#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <GameTypes.h>

class Graphics{
    public:
        void idleLoop(PetType petType);
        void playSound(PetType petType);
        void eating(PetType petType);
        void drinking(PetType petType);
        void promptPetType();
        void promptPetName();

        void loadPetType(PetType petType);
        void setState(PetState petState);

    private:
        //Determine whether dirty or clean sprite is used
        PetState currState;
        bool MUTED = false;



        //Idle Animations
        void dogIdle();
        void catIdle();
        void hamsterIdle();
        void birdIdle();

        //Random Idle Event Animations
        void dogRandIdle();
        void catRandIdle();
        void hamsterRandIdle();
        void birdRandIdle();

        //Sound Animations
        void dogSound();
        void catSound();
        void hamsterSound();
        void birdSound();

        //Eating Animations
        void dogEating();
        void catEating();
        void hamsterEating();
        void birdEating();

        //Drinking Animations
        void dogDrinking();
        void catDrinking();
        void hamsterDrinking();
        void birdDrinking();

        //Sleeping Animations
        void dogSleeping();
        void catSleeping();
        void hamsterSleeping();
        void birdSleeping();

        //Cleaning Animations
        void dogCleaning();
        void catCleaning();
        void hamsterCleaning();
        void birdCleaning();



};

#endif