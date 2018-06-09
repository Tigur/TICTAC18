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
    Tree* root=0;
public:
    int alfa = 0;
    int beta = 0; // optymalnia nan |Legacy variable;
    int value = 0; // to są szansę na wygraną MAX

    List <Tree*> sons;

    Player min;
    Player max;
    State board;
    int current_depth=0;



/*
 *
 * Tworzy nowego syna drzewa, uzywa listy.
 */



    Tree* add()
    {
        Tree *newTree= new Tree; // THIS to make working
        sons.add(newTree);
        newTree->father=this;




        return newTree;
    }


    Tree* AddIfPossible(int n, int m,  int sonIndex )
    {
        int counterOfFree=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if((board.graphBoard[i][j]==0)) // idk if it works
                    counterOfFree++;
                if(sonIndex==counterOfFree)
                {
                    Tree *newTree = add();
                    newTree->board.init(n,m);
                    copy_table_twoD(newTree->board.graphBoard, board.graphBoard, n, m);


                    if(min.nowPlaying)
                        newTree->board.graphBoard[i][j] =2;
                    if(max.nowPlaying)
                        newTree->board.graphBoard[i][j]=1;



                    return newTree;
                }
            }
        }
        return 0;
    }

    /*
     * version 0.2
     * Przewiduje następne "depth" ruchów i podejmuje decyzję. ( minimax ? )
     * Może dodawać w tym celu nowe ruchy do mapy (board)
     * jeżeli ruchy istnieją, to przewiduje tylko tyle ile jest potrzebne do osiągnięcia depth.
     * sprawdza, czy sons.exist == true, jeżeli tak, to schodzi do pierwszego syna i sprawdza ponownie, aż dojdzie do depth lub braku synow.
     * W tym momencie tworzy kolejną warstwę, na podstawie depth. Po czym zapuszcza minimax'a
     *
     *
     */


    bool TreeInit(int n, int m, int depth, int max_depth)
    {
        long long int nm= n*m;
        int move_num=0;




        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k)
            {


                if(depth%2)
                    min.nowPlaying=true;
                else
                    max.nowPlaying=true;

                Tree *newTree = AddIfPossible(n,m,sons.nextIndex);



                if(depth<max_depth && newTree)
                    newTree->TreeInit(n,m,depth+1, max_depth);
            }
        }

        return true;
    }

    bool doForesight(int n, int m, int max_depth)
    {
        TreeInit(n,m,this->current_depth,max_depth);
        //minimax outside

    }


    bool init(int n, int m, int chosen, int difficulty)
    {
        min.playerId=MIN;
        max.playerId=MAX;
        if (chosen==MIN)
        {
            min.isHooman=true;
            max.isHooman=false;
        }
        if(chosen==MAX)
        {
            max.isHooman=true;
            min.isHooman=false;
        }
        if(chosen==TWO_PLAYERS)
        {
            min.isHooman=true;
            max.isHooman=true;
        }
        if (chosen==NO_PLAYERS)
        {
            min.isHooman=false;
            max.isHooman=false;
        }


        board.init(n,m);
        max.nowPlaying=true;
/*
        board.graphBoard= new int*[n];
        for(int i = 0; i <= n; ++i)
            board.graphBoard[i]=new int[m];
*/
        // init the game tree
        TreeInit(n,m,0,difficulty);




        return true;

    }

    bool isFather()
    {
        if(this->sons.exist())
            return true;
        else
            return false;
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