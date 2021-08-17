#include "GameManager.h"
namespace managers {

std::list<interfaces::IGraphicsMove::SquareOnBoard> GameManager::available_move
                            (interfaces::IGraphicsMove::SquareOnBoard chosen_square){
    //move_request(chosen_square, nullptr);
}

bool GameManager::select_move(interfaces::IGraphicsMove::SquareOnBoard chosen_square)
{
    return figure_move(chosen_square_on_board, chosen_square);
}

std::list<interfaces::IGraphicsMove::SquareOnBoard> GameManager::move_request(interfaces::IGraphicsMove::SquareOnBoard chosen_square, interfaces::IMoveRequest &figure_manager)
{
    gameitems::unitchess_board tmp_unit; //< Временная переменная с якобы указателем на клетку, после того, как добавится поле и структура клетки общепринятая, в метод будем передавать chosen_square.

    chosen_square_on_board = chosen_square;

    return figure_manager.move_request(chosen_square);
}

bool GameManager::figure_move(interfaces::IGraphicsMove::SquareOnBoard first_square, interfaces::IGraphicsMove::SquareOnBoard second_square)
{

}

} // namespace managers

