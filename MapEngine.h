#include <iostream>
#include <SFML/Graphics.hpp>

constexpr int N = 4, M = 4;
bool g_win = false;
int MAP[N][M];

//sinh vi tri con trong
sf::Vector2i genPos()
{
    sf::Vector2i v;
    while(1)
    {
        v.x = rand()%N;
        v.y = rand()%N;
        if (MAP[v.y][v.x] == 0)
            break;
    }
    return v;
}

//sinh gia tri ngau nhien 2 hoac 4
int genNewTile()
{
    int t = rand()%2;
    if (t==0)
        return 2;
    else
        return 4;
}

//sinh o moi (vi tri + gia tri )
void placeNewTile()
{
    sf::Vector2i p = genPos();
    MAP[p.y][p.x] = genNewTile();
}

void coutMap()
{
     for (int a=0; a<N; a++)
        {
            for (int b=0; b<M; b++)
                std::cout << MAP[a][b] << " ";
            std::cout << "\n";
        }
    std::cout << "\n";
}
