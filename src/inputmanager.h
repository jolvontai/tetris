#ifndef INPM
#define INPM
#include<SDL2/SDL.h>
#include<map>
#include<iostream>
#include<functional>
#include<vector>

class InputManager {
    public:
    
        InputManager();
        ~InputManager();
        void PollInput();
        void Register(SDL_Keycode key, std::function<void()> callback);
    private:
        std::map<SDL_Keycode,std::vector<std::function<void()>>> events;
    
    
};












#endif