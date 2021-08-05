#include "figuremanager.h"

namespace managers {
Figuremanager::Figuremanager()
{

}

void Figuremanager::move_request(interfaces::IFigureManager * Interface)
{
    Interface->available_move();
}
} // namespace managers
