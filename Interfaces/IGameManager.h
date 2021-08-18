#ifndef IGAMEMANAGER_H
#define IGAMEMANAGER_H
#include "GameItems/squareonboard.h"

namespace interfaces {

//!Абстрактный базовый класс для доступа к шахматной доске.
class IGameManager
{
public:

    //!Метод выставления фигур на cтартовую позицию.
    virtual void start_position() = 0;

    //!Метод передвижения фигуры
    //!Не имеем права его вызывать из любой части кода, кроме этого класса.
    //!В качестве входных параметров: клетка откуда перемещаемся и клетка куда перемещаемся.
    //!В качестве выходных параметров возращаем флаг успешности передвижения фигуры
//    bool figure_move(SquareOnBoard first_square, SquareOnBoard second_square);

    //!Метод перемещения фигуры по доске
    ///todo: подумать над параметрами, которые будут передаваться в данный метод
    ///      Решить проблему с клеткой, а именно вынести её в отдельную структуру!
    virtual bool move(gameitems::SquareOnBoard first_square, gameitems::SquareOnBoard second_square) = 0 ;
};
} // namespace interfaces
#endif // IGAMEMANAGER_H
