#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <GameTypes.h>

Animation animation;
class Graphics{
    public:
        //Loading Methods
        void loadPetType(PetType petType);
        void setState(PetState petState);

        //Menu Methods
        void drawAttributes();
        void drawActions();
        void changeSelect(ButtonPressed pressed, int currentSelected);
        void changeMuteIcon();


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
        PetState petState;

        

        std::map<Animation, Bitmap> animationSet{
            //The actual pet animations
            {IdleAnimation, {}},
            {IdleRandomAnimation, {}},
            {SoundAnimation, {}},
            {EatingAnimation, {}},
            {DrinkingAnimation, {}},
            {SleepingAnimation, {}},
            {CleaningAnimation, {}},
        };

        std::map<Animation, Bitmap> menuSet{
            {AttributeMenu, {image_Attribute_Menu_bits, 27, 36}},
            {ActionMenu, {image_Actions_Menu_bits, 19, 64}},
            {Muted, {image_Mute_On_bits, 8, 8}},
            {UnMuted, {image_Mute_Off_bits, 8, 8}}
        };
        
        void mute();
        void unMute();

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