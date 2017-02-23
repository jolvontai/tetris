#include "inputmanager.h"

InputManager::InputManager()
{

}
InputManager::~InputManager()
{

}
void InputManager::PollInput()
{
    SDL_Event event;
    while(SDL_PollEvent( &event ))
    {
        if(event.type == SDL_KEYDOWN)
        {
            std::cout << "key pressed " << event.key.keysym.sym;
            if(events.find(event.key.keysym.sym) != events.end())
                (*events[event.key.keysym.sym])();
        }
    }
}
void InputManager::Register(SDL_Keycode key, callback function)
{
    this->events[key] = function;
}