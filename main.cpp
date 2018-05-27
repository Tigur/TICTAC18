#include <iostream>

#include"Tree.h"
#include"List.h"
#include"miscFunc.h"
using namespace std;

int main()
{
List <Tree*> L ;
Tree  game;

   // game.add();
   // game.board.init(10,10);


  //  show(10,10,game.board.graphBoard);

    //game.add();
    if(game.init(10,15,MIN))
        cout << "PRAWDA" << endl;

 cout <<    game.sons.get(1)->sons.get(1)->max.nowPlaying << endl;
    return 0;

}