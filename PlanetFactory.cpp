#include "PlanetFactory.h"

#include "PlanetBuilder.h"

Planet PlanetFactory::create(PlanetId planetId) {
	Planet planet;

	switch(planetId) {
		case PlanetId::Sun:
			planet = PlanetBuilder()
				.radius(10.f)
				.position(vector3df(0, 0, 0))
				.texture("sunmap.jpg")
				.lighting(false)
				.build(sceneManager, driver);
			break;

		case PlanetId::Mercury:
			planet = PlanetBuilder()
				.radius(1.f)
				.position(vector3df(5.f, 0, 0))
				.texture("mercurymap.jpg")
				.build(sceneManager, driver);
			break;

		case PlanetId::Venus:
			planet = PlanetBuilder()
				.radius(3.f)
				.position(vector3df(10.f, 0, 0))
				.flySpeed(.002f)
				.texture("venusmap.jpg")
				.build(sceneManager, driver);
			break;

		case PlanetId::Earth:
			planet = PlanetBuilder()
				.radius(3.3f)
				.position(vector3df(13.f, 0, 0))
				.flySpeed(.0019f)
				.texture("earthmap1k.jpg")
				.build(sceneManager, driver);
			break;

		case PlanetId::Mars:
			planet = PlanetBuilder()
				.radius(3.4f)
				.position(vector3df(16.f, 0, 0))
				.texture("mars_1k_color.jpg")
				.build(sceneManager, driver);
			break;

		case PlanetId::Jupiter:
			planet = PlanetBuilder()
				.radius(5.f)
				.position(vector3df(20.f, 0, 0))
				.texture("jupitermap.jpg")
				.build(sceneManager, driver);
			break;

		case PlanetId::Saturn:
			planet = PlanetBuilder()
				.radius(4.f)
				.position(vector3df(24.f, 0, 0))
				.flySpeed(.0017f)
				.texture("saturnmap.jpg")
				.build(sceneManager, driver);
			break;

		case PlanetId::Uranus:
			planet = PlanetBuilder()
				.radius(1.9f)
				.position(vector3df(26.f, 0, 0))
				.flySpeed(.002f)
				.texture("uranusmap.jpg")
				.build(sceneManager, driver);
			break;

		case PlanetId::Neptune:
			planet = PlanetBuilder()
				.radius(3.3f)
				.position(vector3df(28.f, 0, 0))
				.flySpeed(.0012f)
				.texture("neptunemap.jpg")
				.build(sceneManager, driver);
			break;

		case PlanetId::Pluto:
			planet = PlanetBuilder()
				.radius(1.f)
				.position(vector3df(33.f, 0, 0))
				.texture("plutomap1k.jpg")
				.build(sceneManager, driver);
			break;

		default:
			break;
	}
	return planet;
}

