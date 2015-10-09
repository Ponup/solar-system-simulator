#pragma once

#include <irrlicht/irrlicht.h>

using namespace irr;

using namespace core;
using namespace scene;
using irr::IEventReceiver;
using irr::core::vector3df;

class CustomEventReceiver : public IEventReceiver
{
public:
    struct SMouseState {
        core::position2di Position;
        bool LeftButtonDown;
        SMouseState() : LeftButtonDown(false) { }
    } MouseState;

    virtual bool OnEvent(const SEvent& event) {
        if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
            switch(event.MouseInput.Event) {
            case EMIE_LMOUSE_PRESSED_DOWN:
                MouseState.LeftButtonDown = true;
                break;

            case EMIE_LMOUSE_LEFT_UP:
                MouseState.LeftButtonDown = false;
                break;

            case EMIE_MOUSE_MOVED:
                MouseState.Position.X = event.MouseInput.X;
                MouseState.Position.Y = event.MouseInput.Y;
                break;

            default:
                break;
            }
        }
        return false;
    }

    const SMouseState & GetMouseState(void) const {
        return MouseState;
    }

    CustomEventReceiver() {}
};


