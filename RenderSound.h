#include <SFML/Audio.hpp>

void renderSoundLoop()
{
    sf::SoundBuffer loop;
    loop.loadFromFile("sound/loop.wav");
    sf::Sound soundLoop;
    soundLoop.setBuffer(loop);
    soundLoop.play();
}

void renderSoundWin()
{
    sf::SoundBuffer win;
    win.loadFromFile("sound/winner.wav");
    sf::Sound soundWin;
    soundWin.setBuffer(win);
    soundWin.play();
}

