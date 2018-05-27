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
public:
    List <Tree*> sons;

    Player min;
    Player max;
    State board;





    void assignState(int n, int m, State prevState, State *SonState, int sonIndex )
    {
        int counterOfFree=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if((prevState.graphBoard[n][m]==0)) // idk if it works
                    counterOfFree++;
                    if(sonIndex==counterOfFree)
                    {
                        if(min.nowPlaying)
                            SonState->graphBoard[n][m] =2;
                        if(max.nowPlaying)
                            SonState->graphBoard[n][m]=1;
                    }
            }
        }
    }
    Tree* add()
    {
        Tree *newTree= new Tree; // THIS to make working
        sons.add(newTree);
        newTree->father=this;

        // Initialize the table.
        // copy the tables m n
        // add next move ( bierzemy index syna na liście i na podstawie tego zaznaczamy jego ruch) ( Nowa funkcja do tego w board)

        return newTree;
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
                board.init(n,m);

                if(depth%2)
                    min.nowPlaying=true;
                else
                    max.nowPlaying=true;

                if()
                Tree *newTree=add();
                if(depth<nm ) // trzeba to zmienić - nie mogę w init opierać sie na board. Mogę liczbowo zainicjalizować drzewo. W na każdej głębokości -1 liczba syn  ow
                    newTree->TreeInit(m,n,depth+1);
            }
        }


        // }

        return true;
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


      //  board.init(n,m);
/*
        board.graphBoard= new int*[n];
        for(int i = 0; i <= n; ++i)
            board.graphBoard[i]=new int[m];
*/
        // init the game tree
        TreeInit(n,m,0);




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