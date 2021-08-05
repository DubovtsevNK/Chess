#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
//system include:

//progect include:
#include "Interfaces/IGraphicsMove.h"

namespace managers {
//!Класс диспетчера игры.
//!Класс должен обеспечивать переход ходов между игроками, движение фигур и т.д.
//!Так же класс обеспечивает связь с классом реализующим графическую логику.
class GameManager : public interfaces::IGraphicsMove
{
public:
    GameManager();

    virtual void available_move() override;

    virtual void select_move() override;

private:
    enum class PartOfGame : unsigned short{
        WHITE_MOVE = 0,
        BLACK_MOVE = 1,
        START_OF_GAME = 2,
        END_OF_GAME = 3
    };
    PartOfGame game_stage; //<Переменная указывающая стадию игры
};
} // namespace managers


#endif // GAMEMANAGER_H
