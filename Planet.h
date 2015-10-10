#pragma once

#include <string>
using std::string;

#include <irrlicht/irrlicht.h>
using irr::core::vector3df;
using irr::scene::ISceneNode;

enum class PlanetId {
	Sun,
	Mercury,
	Venus,
	Earth,
	Moon,
	Mars,
	Jupiter,
	Saturn,
	Uranus,
	Neptune,
	Pluto
};

class Planet {
public:
	float radius, flySpeed;
	vector3df position;
	string texture;
	bool lighting;

	ISceneNode* node;

	Planet() : flySpeed(.001f), lighting(true) {}
	~Planet() {
		if(node != nullptr) {
			// @todo after fixing memory ownership on node  node->drop();
		}
	}
};

