#ifndef IGAMEMANAGER_H
#define IGAMEMANAGER_H

namespace interfaces {

//!Абстрактный базовый класс для доступа к шахматной доске.
class IGameManager
{
public:

    //!Метод выставления фигур на cтартовую позицию.
    virtual void start_position() = 0;

    //!Метод перемещения фигуры по доске
    ///todo: подумать над параметрами, которые будут передаваться в данный метод
    virtual void move() = 0 ;
};
} // namespace interfaces
#endif // IGAMEMANAGER_H
