#include <SFML/Audio.hpp>

void renderSoundDirection()
{
    sf::SoundBuffer direct;
    direct.loadFromFile("sound/direction.wav");
    sf::Sound soundDir;
    soundDir.setBuffer(direct);
    soundDir.play();
}
