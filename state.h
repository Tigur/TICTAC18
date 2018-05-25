//
// Created by resolution on 18.05.18.
//



#ifndef TICTAC18_STATE_H
#define TICTAC18_STATE_H

#include "Player.h"
#include "defines.h"
#include<iostream>
#include "miscFunc.h"
using namespace std;

//template <typename type>
class State
{

public:
    int **graphBoard;

   bool makeMV(int n, int m, Player player)
    {
        if(graphBoard[n][m])
        {
            cout << "field occupied !" << endl;
            return false;
        }
        if(player.playerId==MAX)
        {
            graphBoard[n][m]=MAX;
            return true;
        }
        if(player.playerId==MIN)
        {
            graphBoard[n][m]=MIN;
            return true;
        }

        cout << "NO PLAYER FOUND" << endl;

        return false;
    }
    bool init(int n, int m)
    {
        graphBoard= new int*[n];
        for(int i = 0; i <= n; ++i)
            graphBoard[i]=new int[m];

        FillWithZeros(n,m,graphBoard);


    }

};




#endif //TICTAC18_STATE_H
