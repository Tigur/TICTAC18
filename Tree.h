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

    bool add()
    {
        Tree *newTree= new Tree; // THIS to make working
        sons.add(newTree);
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

        board.graphBoard= new int[n][m];

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