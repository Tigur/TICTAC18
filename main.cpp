#include <iostream>

#include"Tree.h"
#include"List.h"
#include"miscFunc.h"
using namespace std;

int main()
{
List <Tree*> L ;
Tree  game, gamee, gama;
/*
   // game.add();
    gamee.board.init(10,10);
    gama.board.init(10,10);
    gamee.board.graphBoard[0][0]=1;
    gamee.board.graphBoard[1][0]=1;
    gamee.board.graphBoard[0][1]=1;
    gamee.board.graphBoard[0][2]=1;
    gamee.board.graphBoard[0][3]=1;

    //show(10,10,gamee.board.graphBoard);
    copy_table_twoD(gama.board.graphBoard, gamee.board.graphBoard,10,10);
    show(10,10,gama.board.graphBoard);


  //  show(10,10,game.board.graphBoard);

    //game.add();

    */

    if(game.init(5,5,MIN)) // jakaś pętla nieskończona jest.
        cout << "PRAWDA" << endl;

 cout <<    game.sons.get(1)->sons.get(1)->max.nowPlaying << endl;
    return 0;

}


/*
 * Ogólny leyout programu :
 * 1. inicjalizujemy grę. ( mamy graczy, mamy planszę, pierwszą warstwę możliwych ruchów, )
 * 2. puszczamy grę.
 * 3. gracze wymieniają ruchy, AI przewiduje sytuacje, sprawdzamy wygrane
 * 4. gra się kończy, gdy któryś z graczy będzie miał odpowiednią ilość swoich znaków w rzędzie
 *
 *
 */