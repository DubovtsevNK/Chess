#ifndef FIGUREMANAGER_H
#define FIGUREMANAGER_H
#include "Interfaces/IMoveRequest.h"
#include "Interfaces/IFigureManager.h"
#include "GameItems/chessfigure.h"

#include "Interfaces/IGraphicsMove.h"


#include <vector>


enum class direction
{
    NORTH, // север
    NORTHEAST,// северо-восток
    EAST,// восток
    SOUTHEAST,// юго-восток
    SOUTH,// юг
    SOUTHWEST,// юго-запад
    WEST,// запад
    NORTHWEST// северо-запад
};

// TODO подскажи куда это лучше сунуть. Не уверен что это нужно писать в класс

namespace managers {
class Figuremanager : public interfaces::IMoveRequest
{
public:
    interfaces::IFigureManager *Board2;//<!указатель н адоску с которой работаем

    Figuremanager(interfaces::IFigureManager *_Board) : Board2(_Board){}
    ~Figuremanager(){}

    std::list<interfaces::IGraphicsMove::SquareOnBoard> move_request(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units) override;
    bool cheak(interfaces::IGraphicsMove::SquareOnBoard &units);//<! Функция для Проверки Шаха Королю

protected:
    // Движение фигур
    std::list<interfaces::IGraphicsMove::SquareOnBoard> movePawn(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units,gameitems::ChessFigure* figure); //<!  Функция выполняющая хход пешки
    std::list<interfaces::IGraphicsMove::SquareOnBoard> moveKnight(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units,gameitems::ChessFigure* figure);
    std::list<interfaces::IGraphicsMove::SquareOnBoard> moveBishop(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units,gameitems::ChessFigure* figure);
    std::list<interfaces::IGraphicsMove::SquareOnBoard> moveQueen(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units,gameitems::ChessFigure* figure);
    std::list<interfaces::IGraphicsMove::SquareOnBoard> moveKing(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units,gameitems::ChessFigure* figure);
    std::list<interfaces::IGraphicsMove::SquareOnBoard> moveRook(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units,gameitems::ChessFigure* figure);

    // Движение в различные стороны

   interfaces::IGraphicsMove::SquareOnBoard unitsBoard (const interfaces::IGraphicsMove::SquareOnBoard *units, const unsigned int count, direction dir);




};
} // namespace managers

#endif // FIGUREMANAGER_H
