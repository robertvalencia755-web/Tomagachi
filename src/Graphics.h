#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <GameTypes.h>

class Graphics{
    public:
        void idleLoop(PetType petType);
        void playSound(PetType petType);
        void eating(PetType petType);
        void drinking(PetType petType);

    private:
        //Idle Animations
        void dogIdle();
        void catIdle();
        void hamsterIdle();
        void bunnyIdle();
        void birdIdle();

        //Sound Animations
        void dogSound();
        void catSound();
        void hamsterSound();
        void bunnySound();
        void birdSound();

        //Eating Animations
        void dogEating();
        void catEating();
        void hamsterEating();
        void bunnyEating();
        void birdEating();

        //Drinking Animations
        void dogDrinking();
        void catDrinking();
        void hamsterDrinking();
        void bunnyDrinking();
        void birdDrinking();

};

#endif