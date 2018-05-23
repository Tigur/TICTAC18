//
// Created by resolution on 09.05.18.
//

#ifndef TICTAC18_NODE_H
#define TICTAC18_NODE_H

#include "defines.h"
#include"Player.h"
#include"state.h"
#include "List.h"




//template <typename type>
class Tree
{
    // lista wskaźników do synów ? LISTA SYNÓW POPROSTU.
    Tree* father=0;
    int alfa = 0;
    int beta = 0; // optymalnia nan
    int value = 0; // to są szansę na wygraną MAX
    List <Tree*> sons;

    Player min;
    Player max;
    State board;
public:

    Tree* add()
    {
        Tree *newTree= new Tree; // THIS to make working
        sons.add(newTree);

        return newTree;
    }

    bool init(int n, int m, int chosen)
    {
        min.playerId=MIN;
        max.playerId=MAX;
        if (chosen==MIN)
        {
            min.isHooman=true;
        }
        if(chosen==MAX)
        {
            max.isHooman=true;
        }

        board.graphBoard= new int*[n];
        for(int i = 0; i < n; ++i)
            board.graphBoard[i]=new int[m];

        // init the game tree

       long long int nm= n*m;
        int move_num=0;

        while (move_num!=nm)
        {

            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < m; ++k)
                {

                }
            }


        }



        return true;

    }
    bool TreeInit(int n, int m, int depth)
    {
        long long int nm= n*m;
        int move_num=0;

       // while (move_num!=nm)
       // {

            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < m; ++k)
                {
                    if(depth<nm && this->board.graphBoard[n][m]>0)
                    this->add()->TreeInit(m,n,depth+1);
                }
            }


       // }

        return true;
    }

  //  bool add ()

};


#endif //TICTAC18_NODE_H


/*
 * Klasy do zrobienia :
 * State of the game
 *
 *  PLAYER ( Też w TREE "GAME" )
 */