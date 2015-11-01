#include "PlanetBuilder.h"

using irr::scene::ISceneNode;
using irr::scene::ISceneNodeAnimator;

#include "Path.h"

PlanetBuilder& PlanetBuilder::radius(float radius) {
	planet.radius = radius;
	return *this;
}

PlanetBuilder& PlanetBuilder::position(vector3df position) {
	planet.position = position;
	return *this;
}

PlanetBuilder& PlanetBuilder::texture(const string& texture) {
	planet.texture = currentPath() + "/textures/" + texture;
	return *this;
}

PlanetBuilder& PlanetBuilder::lighting(bool lighting) {
	planet.lighting = lighting;
	return *this;
}

PlanetBuilder& PlanetBuilder::flySpeed(float flySpeed) {
	planet.flySpeed = flySpeed;
	return *this;
}

Planet PlanetBuilder::build(ISceneManager* sceneManager, IVideoDriver* driver) {
	planet.node = sceneManager->addSphereSceneNode(planet.radius, 32, 0, 0, planet.position);
	planet.node->setMaterialTexture(0, driver->getTexture(planet.texture.c_str()));
	planet.node->setMaterialFlag(irr::video::EMF_LIGHTING, planet.lighting);
	planet.node->getMaterial(0).Shininess = 5.0f; // set size of specular highlight

	ISceneNodeAnimator* rotationAnim = sceneManager->createRotationAnimator(vector3df(0.01, 0.15, 0.01));
	if(rotationAnim) {
		planet.node->addAnimator(rotationAnim);
			rotationAnim->drop();
		}

	ISceneNodeAnimator* circleFlyAnim = sceneManager->createFlyCircleAnimator(vector3df(0, 0, 0), planet.position.X, planet.flySpeed);
	if(circleFlyAnim) {
	    planet.node->addAnimator(circleFlyAnim);
	    circleFlyAnim->drop();
	}

	return planet;
}

