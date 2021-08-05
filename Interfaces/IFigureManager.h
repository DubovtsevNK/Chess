#ifndef IFIGUREMANAGER_H
#define IFIGUREMANAGER_H
#include "GameItems/chessfigure.h"
namespace interfaces {
class IFigureManager{

public:
    IFigureManager(){}
    ~IFigureManager(){}
   virtual  gameitems::ChessFigure *available_move(gameitems::unitchess_board units) = 0;//<! files, ranks временные переменные пока не будет клетки

	int temp;

};
} // namespace interfaces


#endif // IFIGUREMANAGER_H
