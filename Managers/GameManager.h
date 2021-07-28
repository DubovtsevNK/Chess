#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
//system include:

//progect include:
#include "Interfaces/IAvailableMove.h"

namespace managers {
//!Класс диспетчера игры.
//!Класс должен обеспечивать переход ходов между игроками, движение фигур и т.д.
class GameManager : public interfaces::IAvailableMove
{
public:
    GameManager();

    virtual void available_move() override;
private:
};
} // namespace managers


#endif // GAMEMANAGER_H
