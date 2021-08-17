#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
//system include:

//progect include:
#include "Interfaces/IGraphicsMove.h"
#include "Interfaces/IMoveRequest.h"
#include "Interfaces/IGameManager.h"



namespace managers {
//!Класс диспетчера игры.
//!Класс должен обеспечивать переход ходов между игроками, движение фигур и т.д.
//!Так же класс обеспечивает связь с классом реализующим графическую логику.
class GameManager : public interfaces::IGraphicsMove
{
public:
    GameManager( interfaces::IMoveRequest *_move_req, interfaces::IGameManager *_game_mang)
        :   game_stage(GameManager::PartOfGame::START_OF_GAME),
            i_move_request(_move_req),
            i_game_manager(_game_mang){};

    //!Метод запроса вариантов хода для фигуры.
    //!В качестве входного параметра необходимо передавать клетку на запрос ходов для которой делаем.
    //!В качестве возращаемых параметров необходимо получать вектор с доступными для хода клетками.
    virtual std::list<SquareOnBoard> available_move(SquareOnBoard chosen_square) override;

    //!Метод выбора хода из представленных ранее
    //!В качестве входного параметра необходимо передавать клетку на которую переместим фигуру.
    //!Функция возвращает 1(true) после успешного перемещения фигуры.
    virtual bool select_move(SquareOnBoard chosen_square) override;

    //!Метод запроса к менеджеру фигуры, о возможных ходах для выбранной фигуры.
    //!В качестве входных параметров необходимо передавать: - клетку на запрос ходов для которой делаем.
    //!                                                     - ссылку на класс, который будет реализовывать логику интерфейса
    //!В качестве возращаемых параметров необходимо получать вектор с доступными для хода клетками.
    std::list<SquareOnBoard> move_request(SquareOnBoard chosen_square, interfaces::IMoveRequest& figure_manager);


private:
    //! Класс перечесление с возможными отрезками игры.
    //! Ход белых, черных, начало игры, конец игры.
    enum class PartOfGame : unsigned short{
        WHITE_MOVE = 0,
        BLACK_MOVE = 1,
        START_OF_GAME = 2,
        END_OF_GAME = 3
    };

    //!Переменная указывающая стадию игры
    PartOfGame game_stage;

    //!Указатель на интерфейс запроса возможных ходов.
    interfaces::IMoveRequest *i_move_request;

    //!Указатель на интерфейс связи менеджера игры с доской.
    interfaces::IGameManager *i_game_manager;

    //!Переменная, которая будет перезаписываться после каждого запроса на возможных ход методом move_request
    SquareOnBoard chosen_square_on_board;

    //!Метод передвижения фигуры
    //!Не имеем права его вызывать из любой части кода, кроме этого класса.
    //!В качестве входных параметров: клетка откуда перемещаемся и клетка куда перемещаемся.
    //!В качестве выходных параметров возращаем флаг успешности передвижения фигуры
    bool figure_move(SquareOnBoard first_square, SquareOnBoard second_square);


};
} // namespace managers


#endif // GAMEMANAGER_H
