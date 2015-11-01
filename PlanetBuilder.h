#pragma once

#include <irrlicht/irrlicht.h>
using irr::core::vector3df;
using irr::scene::ISceneManager;
using irr::video::IVideoDriver;

#include "Planet.h"

class PlanetBuilder {
private:
	Planet planet;

public:
	PlanetBuilder() {}

	PlanetBuilder& radius(float radius);

	PlanetBuilder& position(vector3df position);

	PlanetBuilder& texture(const string& texture);

	PlanetBuilder& lighting(bool lighting);

	PlanetBuilder& flySpeed(float flySpeed);

	Planet build(ISceneManager* sceneManager, IVideoDriver* driver);
};

