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
Tree* minimax(Tree* Node_of_move, int alfa, int beta, Tree *Where_to_move)
{
    /*
     * Where_to_move jest zmieniany wewnątrz funkcji na best_move, żeby wskazać na następny ruch z punktu widzenia komputera.
     */

    alfa = -10;
    beta = 10;
    Tree *potential_move=NULL;
    Tree *best_move=NULL;

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
            potential_move = minimax(Node_of_move->sons.get(i));
            int Minmax_result = potential_move->value;

            if(Node_of_move->max.nowPlaying )
            {
                if(Node_of_move->value<Minmax_result)
                {
                    Node_of_move->value = Minmax_result;
                    alfa=Minmax_result;
                    best_move=potential_move;
                }
            }
            if(Node_of_move->min.nowPlaying )
            {
                if(Node_of_move->value>Minmax_result)
                {
                    Node_of_move->value = Minmax_result;
                    beta=Minmax_result;
                    best_move=potential_move;


                }
            }

        }
        else  // If it IS a leaf
        {
            if(Node_of_move->min.nowPlaying)
            {
                if(Node_of_move->sons.get(i)->value < Node_of_move->value)
                {
                    Node_of_move->value = Node_of_move->sons.get(i)->value;
                    best_move=Node_of_move->sons.get(i);
                }


            }

            if(Node_of_move->min.nowPlaying)
            {
                if(Node_of_move->sons.get(i)->value >  Node_of_move->value)
                {
                    Node_of_move->value = Node_of_move->sons.get(i)->value;
                    best_move=Node_of_move->sons.get(i);
                }

            }
        }
    }
    Where_to_move=best_move;
    return Node_of_move;
}
/*
 * za każdym razzem, kiedy aktualizuję value, to aktualizuję wskaźnik na następny ruch. Zrobione.
 * Ale teraz muszę wymyślić sposób, żeby w dość intuicyjny sposób wyrzucać best_move na zewnątrz funkcji.
 * Jak będzie next move, to tzeba będzie zrobić funkcję do poruszania się w tym kierunku. I "wyjątki", gdy gracz to człowiek i sam podejmuje decyzje.
 *
 */







#endif //TICTAC18_MINIMAX_H
