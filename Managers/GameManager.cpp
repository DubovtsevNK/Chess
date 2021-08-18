#include "GameManager.h"
namespace managers {

std::list<interfaces::IGraphicsMove::SquareOnBoard> GameManager::available_moves
                            (interfaces::IGraphicsMove::SquareOnBoard chosen_square){
    return move_request(chosen_square, i_move_request);
}

bool GameManager::select_move(interfaces::IGraphicsMove::SquareOnBoard _chosen_square)
{
    gameitems::SquareOnBoard chosen_square_on_board, chosen_square;
    return figure_move(chosen_square_on_board, chosen_square);
}

std::list<interfaces::IGraphicsMove::SquareOnBoard> GameManager::move_request(interfaces::IGraphicsMove::SquareOnBoard _chosen_square, interfaces::IMoveRequest &figure_manager)
{
    //todo: решить проблему с клетками!!!
    gameitems::SquareOnBoard chosen_square;
    chosen_square_on_board = chosen_square;

    return figure_manager.move_request(_chosen_square);
}

bool GameManager::figure_move(gameitems::SquareOnBoard first_square, gameitems::SquareOnBoard second_square)
{
    i_game_manager.move(first_square, second_square);
}

} // namespace managers

