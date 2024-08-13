#include <windows.h>
#include "sounds.h"

// move sound
void move_sound(void){
PlaySound("sounds\\Pop Bubble Sound Effect 2022.wav", NULL, SND_FILENAME | SND_ASYNC);
    Sleep(700); // Sleep for 5 seconds to allow the sound to play
}

/************************************************************************/

// select sound
void select_sound(void){
PlaySound("sounds\\Menu Game Button Click Sound Effect.wav", NULL, SND_FILENAME | SND_ASYNC);
    Sleep(1100); // Sleep for 5 seconds to allow the sound to play
}

/************************************************************************/

// error sound
void error_sound(void){
PlaySound("sounds\\Error   Sound Effects (No Copyright).wav", NULL, SND_FILENAME | SND_ASYNC);
    Sleep(900); // Sleep for 5 seconds to allow the sound to play
}

/************************************************************************/

// call start ring sound
void start_call_sound(void){
PlaySound("sounds\\Cell Phone Calling Ring (Copyright Free).wav", NULL, SND_FILENAME | SND_ASYNC);
    Sleep(4000); // Sleep for 5 seconds to allow the sound to play
}

/************************************************************************/
// call ring sound
void call_sound(void){
PlaySound("sounds\\Cell Phone Calling Ring2 (Copyright Free).wav", NULL, SND_FILENAME | SND_ASYNC);
    Sleep(3000); // Sleep for 5 seconds to allow the sound to play
}

/************************************************************************/
// call end sound
void call_end_sound(void){
PlaySound("C:\\Users\\Abdo\\Desktop\\school_data_base\\sounds\\end call sound effect.wav", NULL, SND_FILENAME | SND_ASYNC);
    Sleep(1500); // Sleep for 5 seconds to allow the sound to play
}
