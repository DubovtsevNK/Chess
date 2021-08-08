#ifndef IGRAPHICSMOVE_H
#define IGRAPHICSMOVE_H
#include <vector>

namespace interfaces {
//!Абстрактный класс взаимодействия графической логики с менеджером игры.
class IGraphicsMove{
    public:
    //!Временая структура поля на доске
    struct SquareOnBoard{
        unsigned short literal;
        unsigned short number;
    };

    //!Метод запроса вариантов хода для фигуры.
    //!В качестве входного параметра необходимо передавать клетку на запрос ходов для которой делаем.
    //!В качестве возрращаемых параметров необходимо получать вектор с доступными для хода клетками.
     virtual std::vector<SquareOnBoard> available_move(SquareOnBoard chosen_square) = 0;

    //!Метод выбора хода из представленных ранее
    //!В качестве входного параметра необходимо передавать клетку на которую переместим фигуру.
    //!Функция возвращает 1 после успешного перемещения фигуры.
    virtual bool select_move(SquareOnBoard chosen_square) = 0;
};
}

#endif // IGRAPHICSMOVE_H
