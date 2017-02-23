#ifndef INPM
#define INPM
#include<SDL2/SDL.h>
#include<map>
#include<iostream>
typedef void (*callback)();

class InputManager {
    public:
    
        InputManager();
        ~InputManager();
        void PollInput();
        void Register(SDL_Keycode key, callback func);
    private:
        std::map<SDL_Keycode,callback> events;
    
    
};












#endif