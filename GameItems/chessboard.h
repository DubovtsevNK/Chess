#ifndef CHESSBOARD_H
#define CHESSBOARD_H
//System include
#include <array>

//GameItems include
#include "chessfigure.h"
#include "squareonboard.h"

//Interfaces include
#include "Interfaces/IFigureManager.h"
#include "Interfaces/IGameManager.h"
#include "Interfaces/IGraphicsMove.h"


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

    //IFigureManager.h:
    //!TODO: НИКИТА добавь описание!!!
    virtual  gameitems::ChessFigure *available_move(interfaces::IGraphicsMove::SquareOnBoard units) override;

    //IGameManager.h
    //!Метод выставления фигур на cтартовую позицию.
    virtual void start_position() override;

    //!Метод перемещения фигуры по доске
    virtual bool move(gameitems::SquareOnBoard first_square, gameitems::SquareOnBoard second_square) override;


};
} // namespace gameitems


#endif // CHESSBOARD_H
