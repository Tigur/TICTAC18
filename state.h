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

    int check_for_winner(int n, int m, int n_of_move, int m_of_move, int row)
    {
        row=row-1; // tak będę potrzebował, a nie chce mi się latać po całej funkcji narazie. !!!!!!!!!!!!!!!!!!!!!
        int prev_val=5;
        int sign_counter=0;
        for(int i=0;i<n;++i) //
        {
            if(graphBoard[i][m_of_move]==prev_val && graphBoard[i][m_of_move]!=0)
            {
                sign_counter++;
            }
            else
            {
                sign_counter=0;
            }

            prev_val=graphBoard[i][m_of_move];
        }

        if(sign_counter>=row)
            return prev_val;

        sign_counter=0;
        prev_val=0;

        for(int j=0;j<m;++j)
        {
            if(graphBoard[n_of_move][j]==prev_val && graphBoard[n_of_move][j]!=0)
            {
                sign_counter++;
            }
            else
            {
                sign_counter=0;
            }

            prev_val=graphBoard[n_of_move][j];

        }
        if(sign_counter>=row)
            return prev_val;

        sign_counter=0;
        prev_val=0;
        int i=n_of_move,j=m_of_move;

        while(i<n && j<m)
        {
            if(graphBoard[i][j]==prev_val && graphBoard[i][j]!=0)
            {
                sign_counter++;
            }
            else
            {
                sign_counter=0;
            }

            prev_val=graphBoard[i][j];

            ++i; ++j;
        }

        if(sign_counter>=row)
            return prev_val;

        sign_counter=0;
        prev_val=0;
        i=n_of_move; j=m_of_move;

        while(i>0 && j>0)
        {
            if(graphBoard[i][j]==prev_val && graphBoard[i][j]!=0)
            {
                sign_counter++;
            }
            else
            {
                sign_counter=0;
            }

            prev_val=graphBoard[i][j];

            --i; --j;
        }

        if(sign_counter>=row)
            return prev_val;

        sign_counter=0;
        prev_val=0;
        i=n_of_move; j=m_of_move;

        while(i<n && j>0)
        {
            if(graphBoard[i][j]==prev_val && graphBoard[i][j]!=0)
            {
                sign_counter++;
            }
            else
            {
                sign_counter=0;
            }

            prev_val=graphBoard[i][j];

            ++i; --j;
        }

        if(sign_counter>=row)
            return prev_val;

        sign_counter=0;
        prev_val=0;
        i=n_of_move; j=m_of_move;

        while(i>0 && j<m)
        {
            if(graphBoard[i][j]==prev_val && graphBoard[i][j]!=0)
            {
                sign_counter++;
            }
            else
            {
                sign_counter=0;
            }

            prev_val=graphBoard[i][j];

            --i; ++j;
        }

        if(sign_counter>=row)
            return prev_val;

        return 0;

    }


};




#endif //TICTAC18_STATE_H
