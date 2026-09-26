#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <GameTypes.h>

class Graphics{
    public:
        //Loading Methods
        void loadPetType(PetType petType);
        void setState(PetState petState);

        //Menu Methods
        void drawAttributes();
        void drawActions();
        ActionSelect changeSelect(ButtonPressed pressed, ActionSelect currentSelected);
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

        

        std::map<Animation, std::vector<Bitmap>> animationSet{
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

        void idleAnimation();
        void idleRandomAnimation();
        void soundAnimation();
        void eatingAnimation();
        void drinkingAnimation();
        void cleaningAnimation();



};

#endif