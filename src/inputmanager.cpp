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
            SDL_Keycode temp = event.key.keysym.sym;
            if(events.find(temp) != events.end())
                for(size_t i = 0; i < events[temp].size();i++)
                {
                    events[temp][i]();
                }
        }
    }
}
void InputManager::Register(SDL_Keycode key, std::function<void()> callback)
{
    events[key].push_back(callback);
}