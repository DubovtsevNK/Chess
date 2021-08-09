#include "figuremanager.h"

namespace managers {
Figuremanager::Figuremanager()
{

}

std::vector<interfaces::IGraphicsMove::SquareOnBoard> Figuremanager::move_request(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units)
{
    gameitems::ChessFigure* tmpFigure;
    tmpFigure = Board->available_move(units);
    if(tmpFigure == nullptr)
        //return /* ошибка */;
    switch (tmpFigure->figure_type)
    {
    case gameitems::ChessFigure::TypeFigure::PAWN :
        void movePawn(interfaces::IFigureManager *Board, gameitems::unitchess_board units);
        break;

    }
}

void Figuremanager::movePawn(interfaces::IFigureManager *Board,interfaces::IGraphicsMove::SquareOnBoard units ) //<! files, ranks временные переменные пока не будет клетки
{
    std::vector<gameitems::unitchess_board> vectorVariantMove;
    /* Необходимо сделать методы для работы с клеткой
        движение в перед / назад
        права / лева
        по диагонали во се стороны
  */
    Board->available_move(units);  //<! Опрос на клетку вперед
    Board->available_move(units);  //<! Опрос на 2 клетку вперед
    Board->available_move(units);  //<! Опрос на диагонали
    Board->available_move(units);  //<! Опрос на клетку вперед
}
} // namespace managers
