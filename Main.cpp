#include <irrlicht/irrlicht.h>
#include <SFML/Audio.hpp>

#include <vector>
using std::vector;

#include <math.h>

#include "Planet.h"
#include "PlanetBuilder.h"
#include "CustomEventHandler.h"
#include "PlanetFactory.h"
#include "Path.h"

using irr::video::SColor;
using irr::gui::IGUIEnvironment;

int main(int argc, char** argv) {
	CustomEventReceiver receiver;
	IrrlichtDevice *device = createDevice( video::EDT_OPENGL, dimension2d<u32>(800, 600), 16, false, false, false, &receiver);
	if (!device) {
		return EXIT_FAILURE;
    }
	device->setWindowCaption(L"Solar System Simulator");
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* sceneManager = device->getSceneManager();
	scene::ISceneCollisionManager* collisionManager= sceneManager->getSceneCollisionManager();
	IGUIEnvironment* guiEnv = device->getGUIEnvironment();
	guiEnv->addStaticText(L"Click on a planet to attach the camera to it", rect<s32>(10,10,260,22), false);

	sf::SoundBuffer buffer;
	sf::Sound sound;
	if (buffer.loadFromFile(currentPath() + "/sounds/burning.wav")) {
		sf::Listener::setPosition(0, 0, 0);

		sound.setBuffer(buffer);
		sound.setPosition(0, 0, 0);
		sound.setLoop(true);
		sound.play();
	}

	const char* spaceTexturePath = ( currentPath() + "/textures/space.jpg" ).c_str();
	video::ITexture* space = driver->getTexture(spaceTexturePath);
	scene::ISceneNode* skybox = sceneManager->addSkyBoxSceneNode(space, space, space, space, space, space);

	sceneManager->addLightSceneNode(0, vector3df(0, 0, -50),  video::SColorf(1.0f, 1.0f, 1.0f), 50.0f, 1001);

	PlanetFactory planetFactory(sceneManager, driver);
	Planet sun = planetFactory.create(PlanetId::Sun);
	Planet earth = planetFactory.create(PlanetId::Earth);
	Planet pluto = planetFactory.create(PlanetId::Pluto);
	Planet jupiter = planetFactory.create(PlanetId::Jupiter);
	Planet uranus = planetFactory.create(PlanetId::Uranus);
	Planet neptune = planetFactory.create(PlanetId::Neptune);

	vector<Planet> planets = { sun, planetFactory.create(PlanetId::Mercury) };
	planets.push_back(planetFactory.create(PlanetId::Venus));
	planets.push_back(earth);
	planets.push_back(planetFactory.create(PlanetId::Mars));
	planets.push_back(jupiter);
	planets.push_back(planetFactory.create(PlanetId::Saturn));
	planets.push_back(uranus);
	planets.push_back(neptune);
	planets.push_back(pluto);

	ICameraSceneNode* camera = sceneManager->addCameraSceneNode(0, vector3df(0,0,40), vector3df(0,0,0));
	rect<s32> mainCameraViewPortRect(0, 0, 800, 600);

	ICameraSceneNode* topViewCamera = sceneManager->addCameraSceneNode(0, vector3df(0,50,0), vector3df(0,0,0));
	
	sceneManager->setAmbientLight(video::SColorf(255.0,255.0,255.0));

	ISceneNode* selectedNode = sun.node;
	while(device->run()) {

		if(receiver.GetMouseState().LeftButtonDown) {
			position2di mousepos = receiver.GetMouseState().Position;
			line3df ray = sceneManager->getSceneCollisionManager()->getRayFromScreenCoordinates( mousepos, camera);

			vector3df intersection;
			triangle3df tri;

            for(Planet& planet : planets) {
				ITriangleSelector* wselector = sceneManager->createTriangleSelectorFromBoundingBox(planet.node);
				if (collisionManager->getCollisionPoint(ray, wselector, intersection, tri, planet.node)) {
					selectedNode = planet.node;
				}
				wselector->drop();
			}
		}

		camera->setTarget(selectedNode->getAbsolutePosition());

		skybox->setVisible(true);		
        
		driver->setViewPort(mainCameraViewPortRect);
		driver->beginScene(true, true, SColor(255,100,101,140));
		sceneManager->setActiveCamera(camera);
		sceneManager->drawAll();
		guiEnv->drawAll();

		driver->setViewPort(rect<s32>(0, 380, 200, 600));
		driver->draw2DRectangle(SColor(100,0,0,190), mainCameraViewPortRect);
		skybox->setVisible(false);		
		sceneManager->setActiveCamera(topViewCamera);
		sceneManager->drawAll();
		
		driver->endScene();
	}
	device->drop();

	return EXIT_SUCCESS;
}


