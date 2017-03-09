#pragma once

#include"engine.h"
#include<functional>
class If
{
    public:
        static void SetEngine(Engine& engin)
        {
            If::engine = &engin;
        }
        static Engine* GetEngine()
        {
            return engine;
        }
        static void Register(SDL_Keycode key, std::function<void()> func)
        {
           If::engine->inputManager.Register(key, func);
        }
    private:
        static Engine* engine;
};