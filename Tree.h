//
// Created by resolution on 09.05.18.
//

#ifndef TICTAC18_NODE_H
#define TICTAC18_NODE_H

#include "defines.h"
#include"Player.h"
#include"state.h"
#include "List.h"
#include "Last_Move.h"




//template <typename type>
class Tree
{
    // lista wskaźników do synów ? LISTA SYNÓW POPROSTU.
    Tree* father=0;
    Tree* root=0;
public:
   // int alfa = -10;
  //  int beta = 10; // optymalnia nan |Legacy variable;
    int value = 0; // to są szansę na wygraną MAX

    int winner=0;
    static int in_row;
    List <Tree*> sons;

    Player min;
    Player max;
    State board;
    Last_Move last_move;
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
                    {
                        newTree->board.graphBoard[i][j] = 1;
                        newTree->last_move.n=i;
                        newTree->last_move.m=j;
                        newTree->last_move.exist=true;
                        newTree->last_move.isCircle=false;

                    }
                    if(max.nowPlaying)
                    {
                        newTree->board.graphBoard[i][j] = 2;
                        newTree->last_move.n=i;
                        newTree->last_move.m=j;
                        newTree->last_move.exist=true;
                        newTree->last_move.isCircle=true;
                    }
                    if(i==1 && j==1 && current_depth==7)
                    newTree->board.display(3,3);


                    if(int winnerr = newTree->board.check_for_winner(n,m,i,j,in_row))
                    {
                        newTree->winner = winnerr;
                        if(winnerr==MIN)
                        {
                            newTree->value=-1;
                        }
                        if(winnerr==MAX)
                        {
                            newTree->value=1;
                        }

                    }

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




        if(winner)
            return true;



        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m; ++k) // może moge te if'y wyciągnąć z pętli ? chyba tak.
            {

                if(depth%2)
                {
                    min.nowPlaying = true;

                }
                else
                {
                    max.nowPlaying = true;
                }
                if(min.playerId==MIN)
                {
                    min.isHooman=true;
                }
                if(max.playerId==MAX)
                {
                    max.isHooman=true;
                }




                Tree *newTree = AddIfPossible(n,m,sons.nextIndex);

                if(newTree)
                {
                    newTree->current_depth=depth+1;
                }

                if(newTree && newTree->winner)
                {
                    continue;
                }



                if(depth<max_depth && newTree)
                    newTree->TreeInit(n,m,depth+1, max_depth);
            }
        }

        return true;
    }

    /*
     * version 0.1
     * funkcja do przypadku w którym, mamy juz zainicjalizowane drzewo,
     * po ruchu przeciwnika potrzebujemy dopełnić do 4-rech przewidzianych ruchów
     *
     * Najpierw dokopujemy się rekurencyjnie do liścia i robimy Treeinit, potem do nastepnego i znów Treeinit
     */

    bool Continue_Foresight(int n, int m, int max_depth)
    {
        long long int nm= n*m;




        for (int j = 1; j < sons.nextIndex; ++j)
        {
            if(this->isFather())
            {
                sons.get(j)->Continue_Foresight(n,m,max_depth);
            }
            else
            {

            }
        }

        if(!this->isFather())
        {
            TreeInit(n,m,current_depth,max_depth);          // JUST A TEST IF
        }

        return true;

    }

    bool doForesight(int n, int m, int difficulty)
    {
      int  max_depth= current_depth + difficulty; // do potwierdzenia. W reszcie też.

        if(!this->isFather())
        {
            if(winner)
            {
                cout << "Dude, U can't foresight here" << endl;
                return false;
            }
            TreeInit(n, m, this->current_depth, max_depth);

        }
        Continue_Foresight(n,m,max_depth);
        //minimax outside

    }


    bool init(int n, int m, int chosen, int difficulty, int choosed_in_row)
    {
        min.playerId=chosen;
        max.playerId=chosen;
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
        this->in_row=choosed_in_row;


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

    /*
     * Returns the node with certain move made by hooman.
     */

    Tree* hooman_move(int n, int m, int n_of_move, int m_of_move)
    {
        n_of_move--;
        m_of_move--;

        if(board.graphBoard[n_of_move][m_of_move])
        {
            cout <<"this space is already taken !" << endl;
            return 0;
        }
        if(n_of_move>n | n_of_move < 0 | m_of_move >m |m_of_move < 0)
        {
            cout << " There is no space in there !" << endl;
            return 0;
        }

        for (int i=1; i<sons.nextIndex; ++i) // czy 1 to właściwy pomysł ?
        {
            if (sons.get(i)->last_move.n == n_of_move && sons.get(i)->last_move.m == m_of_move) {
                return sons.get(i);
            }
        }

            cout << "I found nothing " << endl;
            return 0;







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
 *
 *
 *
 */