#include <iostream>

#include"defines.h"
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

  //  if(game.init(6,6,MIN, EASY)) // jakaś pętla nieskończona jest.
      //  cout << "PRAWDA" << endl;

 //cout <<    game.sons.get(1)->sons.get(1)->max.nowPlaying << endl;


/*
 * Tu rozpoczynamy main :
 * Najpierw pętla wyłączająca program
 * pętla przerywająca grę z jakiegoś powodu
 *
 */

    Tree *orientation_pointer=NULL;
    int board_size=0;
    int difficulty=0;
    int choose_your_sign=0;
    int game_mode=0;
    int signal=0; // for checking the player will

    int answer_menu=0;


    while(signal!=EXIT)
    {
        /*
         * tutaj będzie MENU
         */

        cout << "define the board_size " << endl;

        cin >> board_size;


        cout << "\n Do you want to : \n 1. play vs cpu \n 2. play vs human \n 3. watch cpu vs cpu match" << endl;


        cin >> answer_menu;




        switch(answer_menu)
        {
            case 1:


                cout << "Set the difficulty (1. EASY | 2. MEDIUM | 3. HARD) and chose your sign (1. CROSS | 2. CIRCLE) with two digits ex. 1 2" << endl;

                cin >> difficulty;
                cin >> choose_your_sign;

                game_mode=choose_your_sign;
                break;

            case 2:
                game_mode=TWO_PLAYERS;
                break;

            case 3:
                game_mode=NO_PLAYERS;
                break;

            default:
                cerr << " NO SUCH OPTION" << endl;
                break;

        }

        game.init(board_size,board_size,game_mode,difficulty);
        orientation_pointer=&game;





    }





    return 0;

}



/*
 * Ogólny layout programu :
 * 1. inicjalizujemy grę. ( mamy graczy, mamy planszę, pierwszą warstwę możliwych ruchów, )
 * 2. puszczamy grę.
 * 3. gracze wymieniają ruchy, AI przewiduje sytuacje, sprawdzamy wygrane
 * 4. gra się kończy, gdy któryś z graczy będzie miał odpowiednią ilość swoich znaków w rzędzie
 *
 *
 */