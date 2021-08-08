#include "GameManager.h"
namespace managers {

std::vector<interfaces::IGraphicsMove::SquareOnBoard> GameManager::available_move
                            (interfaces::IGraphicsMove::SquareOnBoard chosen_square){

}

bool GameManager::select_move(interfaces::IGraphicsMove::SquareOnBoard chosen_square)
{
    return figure_move(chosen_square_on_board, chosen_square);
}

std::vector<interfaces::IGraphicsMove::SquareOnBoard> GameManager::move_request(interfaces::IGraphicsMove::SquareOnBoard chosen_square, interfaces::IMoveRequest &figure_manager)
{
    interfaces::IFigureManager *tmp_board = nullptr; //< Временная переменная с якобы указателем на доску.
    gameitems::unitchess_board tmp_unit; //< Временная переменная с якобы указателем на клетку, после того, как добавится поле и структура клетки общепринятая, в метод будем передавать chosen_square.

    chosen_square_on_board = chosen_square;

    return figure_manager.move_request(tmp_board, tmp_unit);
}

bool GameManager::figure_move(interfaces::IGraphicsMove::SquareOnBoard first_square, interfaces::IGraphicsMove::SquareOnBoard second_square)
{

}

} // namespace managers

