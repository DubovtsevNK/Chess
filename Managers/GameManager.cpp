#include "GameManager.h"
namespace managers {

std::list<interfaces::IGraphicsMove::SquareOnBoard> GameManager::available_moves
                            (interfaces::IGraphicsMove::SquareOnBoard chosen_square){
    return move_request(chosen_square, i_move_request);
}

bool GameManager::select_move(interfaces::IGraphicsMove::SquareOnBoard chosen_square)
{
    return figure_move(chosen_square_on_board, chosen_square);
}

std::list<interfaces::IGraphicsMove::SquareOnBoard> GameManager::move_request(interfaces::IGraphicsMove::SquareOnBoard chosen_square, interfaces::IMoveRequest &figure_manager)
{
    chosen_square_on_board = chosen_square;

    return figure_manager.move_request(chosen_square);
}

bool GameManager::figure_move(interfaces::IGraphicsMove::SquareOnBoard first_square, interfaces::IGraphicsMove::SquareOnBoard second_square)
{

}

} // namespace managers

