#ifndef FIGUREMANAGER_H
#define FIGUREMANAGER_H
#include "Interfaces/IMoveRequest.h"
#include "Interfaces/IFigureManager.h"
#include "GameItems/chessfigure.h"

#include "Interfaces/IGraphicsMove.h"


#include <vector>

namespace managers {
class Figuremanager : public interfaces::IMoveRequest
{
public:
    Figuremanager();
    ~Figuremanager(){}

    std::vector<interfaces::IGraphicsMove::SquareOnBoard> move_request(interfaces::IFigureManager *Board, gameitems::unitchess_board units) override;
private:
    void movePawn(interfaces::IFigureManager *Board,gameitems::unitchess_board units); //<!  Функция выполняющая хход пешки


};
} // namespace managers
#endif // FIGUREMANAGER_H
