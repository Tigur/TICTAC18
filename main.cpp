#include <iostream>

#include"defines.h"
#include"Tree.h"
#include"List.h"
#include"miscFunc.h"
#include "minimax.h"

/*
 * sprawdzę to dla wprowadzania danych. hooman vs cpu
 */



using namespace std;

//bool Player::isHooman=0;
int Player::playerId=0;
int Tree::in_row=0;

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



   // game.init(3,3,1,EASY,3);
  //  cout << "poszło ! " << endl;



    Tree *orientation_pointer=NULL;
    Tree *next_move=NULL;
    int board_size=0;
    int difficulty=0;
    int choose_your_sign=0;
    int game_mode=0;
    int signal=0; // for checking the player will
    int in_row=0;

    int answer_menu=0;


    while(signal!=EXIT)
    {
        /*
         * tutaj będzie MENU
         */

        cout << "define the board_size " << endl;

     //   cin >> board_size;
        board_size=3;


        cout << "\n Do you want to : \n 1. play vs cpu \n 2. play vs human \n 3. watch cpu vs cpu match" << endl;


       // cin >> answer_menu;
        answer_menu=1;




        switch(answer_menu)
        {
            case 1:


                cout << "Set the difficulty (1. EASY | 2. MEDIUM | 3. HARD) and choose your sign (1. CROSS | 2. CIRCLE) with two digits ex. 1 2\n also choose row amount " << endl;

               // cin >> difficulty;
               // difficulty=difficulty+3;
              //  cin >> choose_your_sign;
               // cin >> in_row;

                difficulty=4;
                choose_your_sign=1;
                in_row=3;

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

        game.init(board_size,board_size,game_mode,difficulty,in_row); // TU INIT
        orientation_pointer=&game;

      game.board.display(board_size,board_size);

        cout << "INIIIIT POSZED" << endl;

        while(orientation_pointer->isFather())
        {



            /*
             * Tutaj jest wymiana ruchów do momentu gdy, ktoś wygra.
             */

            if(orientation_pointer->max.nowPlaying)
            {

                if (orientation_pointer->max.isHooman)
                {
                    /*
                     * funkcja dla ludzi
                     */

                    int n_of_move=0;
                    int m_of_move=0;

                    cout << "Tell me your move hooman : (Pick width num and height num like this: 1 2 ) " << endl;
                    cin >> n_of_move;
                    cin >> m_of_move;

                    next_move=orientation_pointer->hooman_move(board_size,board_size,n_of_move,m_of_move);

                    while (!next_move)
                    {
                        cout << "Try again" << endl;
                        cin >> n_of_move;
                        cin >> m_of_move;
                        next_move=orientation_pointer->hooman_move(board_size,board_size,n_of_move,m_of_move);
                    }
                    orientation_pointer=next_move;

                }
                else
                {
                    orientation_pointer->doForesight(board_size,board_size,difficulty);
                    minimax(orientation_pointer,-10,10, next_move);
                    orientation_pointer=next_move;


                }

                orientation_pointer->board.display(board_size,board_size);
            }

           else if(orientation_pointer->min.nowPlaying)
            {

                if (orientation_pointer->min.isHooman)
                {
                    /*
                     * funkcja do wybierania ruchu ?
                     *
                     * tutaj jeszcze wyświetlanie na nowo planszy... I plansza
                     */
                    int n_of_move=0;
                    int m_of_move=0;

                    cout << "Tell me your move hooman : (Pick width num and height num like this: 1 2 ) " << endl;
                    cin >> n_of_move;
                    cin >> m_of_move;



                    next_move=orientation_pointer->hooman_move(board_size,board_size,n_of_move,m_of_move);

                    while (!next_move)
                    {
                        cout << "Try again" << endl;
                        cin >> n_of_move;
                        cin >> m_of_move;
                        next_move=orientation_pointer->hooman_move(board_size,board_size,n_of_move,m_of_move);
                    }
                    orientation_pointer=next_move;
                }
                else
                {
                    orientation_pointer->doForesight(board_size,board_size,difficulty);
                    minimax(orientation_pointer,-10,10, next_move);
                    orientation_pointer=next_move;
                }

                orientation_pointer->board.display(board_size,board_size);


            }
        }




        if(orientation_pointer->value==MAX_WINS)
        {
            cout << "Circle WINS ! " << endl;

        }
        if(orientation_pointer->value==MIN_WINS)
        {
            cout << " Cross WINS ! " << endl;
        }
        if(orientation_pointer->value==TIE)
        {
            cout << " It's a TIE ! " << endl;
        }





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

/*
 * DO zrobienia :
 * Wymiana ruchów.
 * Zainicjalizowanie wartości w liściach chyba zrobione.
 *
 * Wielkie niewiadome :
 * Czy algorytm minimax działa ? Robimy standardową grę 3x3 i na niej testuję wszystko. :P
 * Czyli musimy miec do tego narzędzia do poruszania się. 
 *
 *
 */