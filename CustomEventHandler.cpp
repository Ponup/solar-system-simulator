#include "CustomEventHandler.h"

bool CustomEventReceiver::OnEvent(const SEvent& event) {
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
            }
        }
        return false;
}

const SMouseState& CustomEventReceiver::GetMouseState(void) const {
	return MouseState;
}

