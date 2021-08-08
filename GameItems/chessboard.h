#ifndef CHESSBOARD_H
#define CHESSBOARD_H
//System include
#include <array>

//GameItems include
#include "chessfigure.h"

//Interfaces include
#include "Interfaces/IFigureManager.h"
#include "Interfaces/IGameManager.h"

namespace gameitems {
//todo: Когда появится интерфейс доступа визуального менеджера, добавить наследование от него
//!Класс игрового поля.
class ChessBoard : public interfaces::IFigureManager, public interfaces::IGameManager
{
private:
    //!Количество клеток на поле
    static constexpr std::size_t NUMB_OF_SQUARE = 64;

    //!Массив, который эмитирует шахматную доску
     std::array<ChessFigure*, NUMB_OF_SQUARE> chess_board;
public:
     ChessBoard();

     //!Структура шахматного поля
    struct SquareOnBoard{
        //!Перечисление буквенной составляющей шахматного поля
        enum class literal : std::size_t{
            A = 0,
            B,
            C,
            D,
            E,
            F,
            G,
            H
        };

        //!Цифровая составляющая шахматного поля
        unsigned short number;
    };

    //IFigureManager.h:
    //!TODO: НИКИТА добавь описание!!!
    virtual  gameitems::ChessFigure *available_move(gameitems::unitchess_board units) override;

    //IGameManager.h
    //!Метод выставления фигур на cтартовую позицию.
    virtual void start_position() override;

    //!Метод перемещения фигуры по доске
    ///todo: подумать над параметрами, которые будут передаваться в данный метод
    virtual void move() override;

};
} // namespace gameitems


#endif // CHESSBOARD_H
