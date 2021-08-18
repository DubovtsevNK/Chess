#include "chessboard.h"

namespace gameitems {
ChessBoard::ChessBoard()
{
    chess_board.fill(nullptr);
}

ChessFigure *ChessBoard::available_move(interfaces::IGraphicsMove::SquareOnBoard units)
{

}

void ChessBoard::start_position()
{

}

bool ChessBoard::move(gameitems::SquareOnBoard first_square, gameitems::SquareOnBoard second_square)
{
    //todo: через семантику перемещения std:move необходимо передвинуть фигуру.
    //      перед этим необходимо проверить, наличие вражеской фигуры, необходимо вызвоть метод боя фигуры,
    //      который занесет побитую фигуру в вектор битых фигур, а вместо неё запишет nullptr.
    // TODO ну так ремарочка не забывай что семантика перемещения "удаляет" данные у того кто передает значения
    // TODO2 ну тоже ремарочка функция std::move не выполняет семантику перемещения а конвертирует lvaliu на rvaliu
}
} // namespace gameitems
