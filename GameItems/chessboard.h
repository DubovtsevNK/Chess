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
class ChessBoard : public interfaces::IFigureManager, public interfaces::IGameManager
{


private:
    //!Количество клеток на поле
    static constexpr std::size_t NUMB_OF_SQUARE = 64;

    //!Массив, который эмитирует шахматную доску
     std::array<ChessFigure*, NUMB_OF_SQUARE> chess_board;
public:
     ChessBoard();

    struct SquareOnBoard{
        unsigned short literal;
        unsigned short number;
    };
};
} // namespace gameitems


#endif // CHESSBOARD_H
