#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <GameTypes.h>
template <typename T>

Animation animation;
class Graphics{
    public:
        //Loading Methods
        void loadPetType(PetType petType);
        void setState(PetState petState);

        //PetAnimationMethods
        void idleLoop();
        void playSound();
        void eating();
        void drinking();

        //PromptingMethods (Primarilly for pet creation)
        void promptPetType();
        void promptPetName();



    private:
        //Determine whether dirty or clean sprite is used
        PetState currState;
        bool MUTED = false;
        std::map<Animation, T[]> animationSet{
            //The actual pet animations
            {IdleAnimation, []},
            {IdleRandomAnimation, []},
            {SoundAnimation, []},
            {EatingAnimation, []},
            {DrinkingAnimation, []},
            {SleepingAnimation, []},
            {CleaningAnimation, []},
            
            //Menu icons
            {AttributeIcons, []},
            {OptionIcons, []},
            {OptionSelect, []},
            {Muted, []},
            {UnMuted, []}
            
        };

      



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