#include <iostream>
#include "MapEngine.h"
#include "RenderSoundDirection.h"

enum class Direction
{
    Left,
    Right,
    Up,
    Down,
};

void shift(Direction d)
{
    bool didShift = 0;
    if (d == Direction::Up)//huong len
    {
        renderSoundDirection();
        for (int j=0; j<M; j++) //duyet tung hang
        {
            for (int i=0; i<N-1; i++)
                // tim nhung o co gia tri bang 0 va xoa
                if (MAP[i][j] == 0)
                {
                    bool change = 0;
                    for (int k=i; k<N-1; k++)
                    // dich len tren
                    {
                        MAP[k][j] = MAP[k+1][j];
                        if (MAP[k][j] != 0)
                        {
                            didShift = 1;
                            change = 1;
                        }
                    }
                    MAP[N-1][j] = 0;
                    if (change) i--; // neu co gia tri thay doi, duyet lai vi tri chinh xac
                }
            for (int i=0; i<N-1; i++)
                // gop nhung o co cung gia tri
                if (MAP[i][j] == MAP[i+1][j] && MAP[i][j] != 0)
                {
                    didShift = 1;
                    for (int k=i; k<N-1; k++)
                        MAP[k][j] = MAP[k+1][j];
                    MAP[N-1][j] = 0;
                    MAP[i][j] *= 2;
                }
        }
    }
    else if (d == Direction::Left)
    {
        renderSoundDirection();
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<M-1; j++)
                // tim nhung o co gia tri bang 0 va xoa
                if (MAP[i][j] == 0)
                {
                    bool change = 0;
                    for (int k=j; k<M-1; k++) // di chuyen cac o
                    {
                        MAP[i][k] = MAP[i][k+1];
                        if (MAP[i][k] != 0)
                        {
                            didShift = 1;
                            change = 1;
                        }
                    }
                    MAP[i][M-1] = 0;
                    if (change) j--; // neu co gia tri thay doi, duyet lai vi tri chinh xac
                }
            for (int j=0; j<N-1; j++) // gop o cung gia tri
                if (MAP[i][j] == MAP[i][j+1] && MAP[i][j] != 0)
                {
                    didShift = 1;
                    for (int k=j; k<M-1; k++)
                        MAP[i][k] = MAP[i][k+1];
                    MAP[i][M-1] = 0;
                    MAP[i][j] *= 2;
                }
        }
    }
    else if (d == Direction::Down)
    {
        renderSoundDirection();
        for (int j=0; j<M; j++)
        {
            for (int i=N-1; i>=0; i--) // tim nhung o co gia tri bang 0 va xoa
                if (MAP[i][j] == 0)
                {
                    bool change = 0;
                    for (int k=i; k>0; k--) // dich chuyen o xuong duoi
                    {
                        MAP[k][j] = MAP[k-1][j];
                        if (MAP[k][j] != 0)
                        {
                            didShift = 1;
                            change = 1;
                        }
                    }
                    MAP[0][j] = 0;
                    if (change) i++; // neu co gia tri thay doi, duyet lai vi tri chinh xac
                }
            for (int i=N-1; i>0; i--) // gop o co cung gia tri
                if (MAP[i][j] == MAP[i-1][j] && MAP[i][j] != 0)
                {
                    didShift = 1;
                    for (int k=i; k>=0; k--)
                        MAP[k][j] = MAP[k-1][j];
                    MAP[0][j] = 0;
                    MAP[i][j] *= 2;
                }
        }
    }
    else if (d == Direction::Right)
    {
        renderSoundDirection();
        for (int i=0; i<N; i++)
        {
            for (int j=M-1; j>=0; j--)
                if (MAP[i][j] == 0)
                {
                    bool change = 0;
                    for (int k=j; k>0; k--)
                    {
                        MAP[i][k] = MAP[i][k-1];
                        if (MAP[i][k] != 0)
                        {
                            didShift = 1;
                            change = 1;
                        }
                    }
                    MAP[i][0] = 0;
                    if (change) j++;
                }
            for (int j=M-1; j>0; j--)
                if (MAP[i][j] == MAP[i][j-1] && MAP[i][j] != 0)
                {
                    didShift = 1;
                    for (int k=j; k>0; k--)
                        MAP[i][k] = MAP[i][k-1];
                    MAP[i][0] = 0;
                    MAP[i][j] *= 2;
                }
        }
    }
    if (didShift)
        placeNewTile();
}
