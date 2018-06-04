//
// Created by resolution on 29.05.18.
//
#include "Tree.h"
#include "List.h"


#ifndef TICTAC18_MINIMAX_H
#define TICTAC18_MINIMAX_H
/*
 * funkcja przechodzi całe dostępne drzewo ze zdefioniowanymi wartościami
 * Na wyjściu może być wskaźnik do następnego ruchu, albo numer syna. Jeszcze się zobaczy
 *
 * W jaki sposób poruszam się po drzewie ?
 * funkcja rekurencyjna, która będzie sprawdzać synów z punktu widzenia ojca.
 *
 * leć po drzewie, jezeli Twoi synowie to liście, to weź wartości i zapisz w sobie najlepszą.
 * 
 *
 */
bool minimax(Tree* Node_of_move, int alfa, int beta)
{
    /*
     *
     */

    alfa = -10;
    beta = 10;

    for(int i=1;i<Node_of_move->sons.nextIndex;i++)
    {

        // if pruning
        if (Node_of_move->max.nowPlaying)
        {
           if(Node_of_move->value > beta)
           {
               break;     // prune
           }
        }

        if (Node_of_move->min.nowPlaying)
        {
            if(Node_of_move->value < alfa)
            {
                break;     // prune
            }
        }


        if(Node_of_move->sons.get(i).isFather()) // If it's not a leaf
        {
            int Minmax_result = minimax(Node_of_move->sons.get(i));

            if(Node_of_move->max.nowPlaying )
            {
                if(Node_of_move->value<Minmax_result)
                {
                    Node_of_move->value = Minmax_result;
                    alfa=Minmax_result;
                }
            }
            if(Node_of_move->min.nowPlaying )
            {
                if(Node_of_move->value>Minmax_result)
                {
                    Node_of_move->value = Minmax_result;
                    beta=Minmax_result;
                }
            }

        }
        else  // If it IS a leaf
        {
            if(Node_of_move->min.nowPlaying)
            {
                if(Node_of_move->sons.get(i)->value < Node_of_move->value)
                    Node_of_move->value=Node_of_move->sons.get(i)->value;


            }

            if(Node_of_move->min.nowPlaying)
            {
                if(Node_of_move->sons.get(i)->value >  Node_of_move->value)
                    Node_of_move->value=Node_of_move->sons.get(i)->value;
            }
        }
    }
    return Node_of_move->value;
}







#endif //TICTAC18_MINIMAX_H
