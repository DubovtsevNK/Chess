#include "chessboard.h"

namespace gameitems {
ChessBoard::ChessBoard()
{
    chess_board.fill(nullptr);
}

ChessFigure *ChessBoard::available_move(unitchess_board units)
{

}

void ChessBoard::start_position()
{

}

void ChessBoard::move()
{
    //todo: через семантику перемещения std:move необходимо передвинуть фигуру.
    //      перед этим необходимо проверить, наличие вражеской фигуры, необходимо вызвоть метод боя фигуры,
    //      который занесет побитую фигуру в вектор битых фигур, а вместо неё запишет nullptr.
}
} // namespace gameitems
