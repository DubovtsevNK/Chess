#ifndef FIGUREMANAGER_H
#define FIGUREMANAGER_H
#include "Interfaces/IMoveRequest.h"
#include "Interfaces/IFigureManager.h"

namespace managers {
class Figuremanager : public interfaces::IMoveRequest
{
public:
    Figuremanager();



    void move_request(interfaces::IFigureManager *) override;
};
} // namespace managers
#endif // FIGUREMANAGER_H
