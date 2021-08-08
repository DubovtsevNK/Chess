#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
//system include:

//progect include:
#include "Interfaces/IGraphicsMove.h"
#include "Interfaces/IMoveRequest.h"
#include "Interfaces/IFigureManager.h"

namespace managers {
//!Класс диспетчера игры.
//!Класс должен обеспечивать переход ходов между игроками, движение фигур и т.д.
//!Так же класс обеспечивает связь с классом реализующим графическую логику.
class GameManager : public interfaces::IGraphicsMove
{
public:
    GameManager() : game_stage(GameManager::PartOfGame::START_OF_GAME){};

    //!Метод запроса вариантов хода для фигуры.
    //!В качестве входного параметра необходимо передавать клетку на запрос ходов для которой делаем.
    //!В качестве возращаемых параметров необходимо получать вектор с доступными для хода клетками.
    virtual std::vector<SquareOnBoard> available_move(SquareOnBoard chosen_square) override;

    //!Метод выбора хода из представленных ранее
    //!В качестве входного параметра необходимо передавать клетку на которую переместим фигуру.
    //!Функция возвращает 1 после успешного перемещения фигуры.
    virtual bool select_move(SquareOnBoard chosen_square) override;

    //!Метод запроса к менеджеру фигуры, о возможных ходах для выбранной фигуры.
    //!В качестве входных параметров необходимо передавать: - клетку на запрос ходов для которой делаем.
    //!                                                     - ссылку на класс, который будет реализовывать логику интерфейса
    //!В качестве возращаемых параметров необходимо получать вектор с доступными для хода клетками.
    std::vector<SquareOnBoard> move_request(SquareOnBoard chosen_square, interfaces::IMoveRequest& figure_manager);


private:
    //! Класс перечесление с возможными отрезками игры.
    //! Ход белых, черных, начало игры, конец игры.
    enum class PartOfGame : unsigned short{
        WHITE_MOVE = 0,
        BLACK_MOVE = 1,
        START_OF_GAME = 2,
        END_OF_GAME = 3
    };

    //!Переменная, которая будет перезаписываться после каждого запроса на возможных ход методом move_request
    SquareOnBoard chosen_square_on_board;

    //!Метод передвижения фигуры
    //!Не имеем права его вызывать из любой части кода, ркоме этого класса.
    //!В качестве входных параметров:
    //!В качестве выходных параметров возращаем флаг успешности передвижения фигуры
    bool figure_move();

    //!Переменная указывающая стадию игры
    PartOfGame game_stage;
};
} // namespace managers


#endif // GAMEMANAGER_H
