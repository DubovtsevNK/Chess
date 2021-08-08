#include "GameManager.h"
namespace managers {

std::vector<interfaces::IGraphicsMove::SquareOnBoard> GameManager::available_move
                            (interfaces::IGraphicsMove::SquareOnBoard chosen_square){

}

bool GameManager::select_move(interfaces::IGraphicsMove::SquareOnBoard chosen_square)
{
    return 1;
}

std::vector<interfaces::IGraphicsMove::SquareOnBoard> GameManager::move_request(interfaces::IGraphicsMove::SquareOnBoard chosen_square, interfaces::IMoveRequest &figure_manager)
{
    interfaces::IFigureManager *tmp_board = nullptr; //< Временная переменная с якобы указателем на доску.
    gameitems::unitchess_board tmp_unit; //< Временная переменная с якобы указателем на клетку.
    return figure_manager.move_request(tmp_board, tmp_unit);
}

} // namespace managers

