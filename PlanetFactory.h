#pragma once

#include <irrlicht/irrlicht.h>
using irr::video::IVideoDriver;

using irr::core::vector3df;
using irr::scene::ISceneNode;
using irr::scene::ISceneManager;
using irr::scene::ISceneNodeAnimator;
using irr::video::IVideoDriver;

#include "Planet.h"

class PlanetFactory {
private:
	ISceneManager* sceneManager;
	IVideoDriver* driver;
public:
	PlanetFactory(ISceneManager* sceneManager, IVideoDriver* driver) : sceneManager(sceneManager), driver(driver) {}

	Planet create(PlanetId planetId);
};

