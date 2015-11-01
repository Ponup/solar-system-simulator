#pragma once

#include <irrlicht/irrlicht.h>

using namespace irr;
using irr::IEventReceiver;

using namespace core;
using irr::core::vector3df;

using namespace scene;

struct SMouseState {
	core::position2di Position;
	bool LeftButtonDown;
	
	SMouseState() : LeftButtonDown(false) { }
};

class CustomEventReceiver : public IEventReceiver
{
private:
	struct SMouseState MouseState;
public:    
	CustomEventReceiver() {}

	virtual bool OnEvent(const SEvent& event);

	const SMouseState& GetMouseState(void) const;
};

