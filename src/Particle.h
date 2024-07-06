#include <SFML/Graphics.hpp>
#include <Thor/Math/Random.hpp>

class Particle
{
public:
	Particle (sf::Texture);
	void Update (sf::Time deltaTime);
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect rect;

	float time;
	float frameDuration;

	int nrFrames;
	int currentFrame;
	bool toDestroy;


};