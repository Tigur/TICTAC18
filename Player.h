//
// Created by resolution on 19.05.18.
//

#ifndef TICTAC18_PLAYER_H
#define TICTAC18_PLAYER_H

#include"defines.h"

//template <typename type>
class Player
{

public:
     bool isHooman ; // can't be static
    static int playerId; // MIN OR MAX
    bool nowPlaying=0;
};
#endif //TICTAC18_PLAYER_H
