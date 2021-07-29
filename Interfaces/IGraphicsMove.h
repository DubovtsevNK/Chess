#ifndef IGRAPHICSMOVE_H
#define IGRAPHICSMOVE_H
namespace interfaces {
//!Абстрактный класс взаимодействия графической логики с менеджером игры.
class IGraphicsMove{
    //!Метод запроса вариантов хода для фигуры.
     virtual void available_move() = 0;

    //!Метод выбора хода из представленных ранее
    virtual void select_move() = 0;
};
}

#endif // IGRAPHICSMOVE_H
