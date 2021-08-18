#ifndef IGAMEMANAGER_H
#define IGAMEMANAGER_H
#include <list>

#include "GameItems/squareonboard.h"

namespace interfaces {

//!Абстрактный базовый класс для доступа к шахматной доске.
class IGameManager
{
public:

    //!Метод выставления фигур на cтартовую позицию.
    virtual void start_position() = 0;

    /*!Метод перемещения фигуры по доске
     *В качестве входных параметров: клетка откуда перемещаемся и клетка куда перемещаемся.
     *В качестве выходных параметров возращаем флаг успешности передвижения фигуры
     */
    virtual bool move(gameitems::SquareOnBoard first_square, gameitems::SquareOnBoard second_square) = 0 ;
};
} // namespace interfaces
#endif // IGAMEMANAGER_H
