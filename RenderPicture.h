#include <SFML/Graphics.hpp>
#include <time.h>
#include "RenderSound.h"

constexpr int TILESIZE = 128,
              WIDTH = 4*TILESIZE,
              HEIGHT = 4*TILESIZE;
void RenderPic()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH-16, HEIGHT-16), "2048 Game");

    //render picture
    sf::Texture tblank, t2, t4, t8, t16, t32, t64, t128, t256, t512, t1024, t2048, t4096, t8192;
    tblank.loadFromFile("images/blank.png");
    t2.loadFromFile("images/2.png");
    t4.loadFromFile("images/4.png");
    t8.loadFromFile("images/8.png");
    t16.loadFromFile("images/16.png");
    t32.loadFromFile("images/32.png");
    t64.loadFromFile("images/64.png");
    t128.loadFromFile("images/128.png");
    t256.loadFromFile("images/256.png");
    t512.loadFromFile("images/512.png");
    t1024.loadFromFile("images/1024.png");
    t2048.loadFromFile("images/2048.png");

    sf::Sprite sprite_blank(tblank);
    sf::Sprite sprite_2(t2);
    sf::Sprite sprite_4(t4);
    sf::Sprite sprite_8(t8);
    sf::Sprite sprite_16(t16);
    sf::Sprite sprite_32(t32);
    sf::Sprite sprite_64(t64);
    sf::Sprite sprite_128(t128);
    sf::Sprite sprite_256(t256);
    sf::Sprite sprite_512(t512);
    sf::Sprite sprite_1024(t1024);
    sf::Sprite sprite_2048(t2048);

    placeNewTile();
    placeNewTile();

    while (window.isOpen())
    {
        renderSoundLoop();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed && !g_win)
            {
                if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
                    shift(Direction::Left);
                else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
                    shift(Direction::Right);
                else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
                    shift(Direction::Up);
                else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
                    shift(Direction::Down);
            }
            else if (event.type == sf::Event::Closed)
                window.close();
        }

        //kiem tra neu nguoi choi da thang game
        if (!g_win)
            for (int i=0; i<N; i++)
                for (int j=0; j<M; j++)
                    if (MAP[i][j] == 2049)
                    {
                        g_win = 1;
                        break;
                    }

        //printf
        window.clear();
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
            {
                if (MAP[i][j] == 0)
                {
                    sprite_blank.setPosition(j*TILESIZE, i*TILESIZE);
                    window.draw(sprite_blank);
                }
                else if (MAP[i][j] == 2)
                {
                    sprite_2.setPosition(j*TILESIZE, i*TILESIZE);
                    window.draw(sprite_2);
                }
                else if (MAP[i][j] == 4)
                {
                    sprite_4.setPosition(j*TILESIZE, i*TILESIZE);
                    window.draw(sprite_4);
                }
                else if (MAP[i][j] == 8)
                {
                    sprite_8.setPosition(j*TILESIZE, i*TILESIZE);
                    window.draw(sprite_8);
                }
                else if (MAP[i][j] == 16)
                {
                    sprite_16.setPosition(j*TILESIZE, i*TILESIZE);
                    window.draw(sprite_16);
                }
                else if (MAP[i][j] == 32)
                {
                    sprite_32.setPosition(j*TILESIZE, i*TILESIZE);
                    window.draw(sprite_32);
                }
                else if (MAP[i][j] == 64)
                {
                    sprite_64.setPosition(j*TILESIZE, i*TILESIZE);
                    window.draw(sprite_64);
                }
                else if (MAP[i][j] == 128)
                {
                    sprite_128.setPosition(j*TILESIZE, i*TILESIZE);
                    window.draw(sprite_128);
                }
                else if (MAP[i][j] == 256)
                {
                    sprite_256.setPosition(j*TILESIZE, i*TILESIZE);
                    window.draw(sprite_256);
                }
                else if (MAP[i][j] == 512)
                {
                    sprite_512.setPosition(j*TILESIZE, i*TILESIZE);
                    window.draw(sprite_512);
                }
                else if (MAP[i][j] == 1024)
                {
                    sprite_1024.setPosition(j*TILESIZE, i*TILESIZE);
                    window.draw(sprite_1024);
                }
                else if (MAP[i][j] == 2048)
                {
                    sprite_2048.setPosition(j*TILESIZE, i*TILESIZE);
                    window.draw(sprite_2048);
                }
            }
        window.display();
    }
}

