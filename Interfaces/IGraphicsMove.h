#ifndef IGRAPHICSMOVE_H
#define IGRAPHICSMOVE_H
#include <vector>
#include <list>
namespace interfaces {
//!Абстрактный класс взаимодействия графической логики с менеджером игры.
class IGraphicsMove{
    public:
    //!Временая структура поля на доске
    //! ТУДУ ну что за названия почему не горизонталь и вертикаль??
    struct SquareOnBoard{
        unsigned short literal;
        unsigned short number;
        //Пере грузка операторов сравнения,что бы иметь возможность сравнивать поля
        friend bool operator == (const SquareOnBoard &S1,const SquareOnBoard &S2)
        {
            if((S1.literal == S2.literal) and (S1.number == S2.number)) return true;
            else return false;
        };
        friend bool operator != (const SquareOnBoard &S1,const SquareOnBoard &S2)
        {
            if((S1.literal != S2.literal) or (S1.number != S2.number)) return true;
            else return false;
        };
    };

    //!Метод запроса вариантов хода для фигуры.
    //!В качестве входного параметра необходимо передавать клетку на запрос ходов для которой делаем.
    //!В качестве возрращаемых параметров необходимо получать вектор с доступными для хода клетками.
     virtual std::list<SquareOnBoard> available_moves(SquareOnBoard chosen_square) = 0;

    //!Метод выбора хода из представленных ранее
    //!В качестве входного параметра необходимо передавать клетку на которую переместим фигуру.
    //!Функция возвращает 1 после успешного перемещения фигуры.
    virtual bool select_move(SquareOnBoard chosen_square) = 0;
};
}

#endif // IGRAPHICSMOVE_H
