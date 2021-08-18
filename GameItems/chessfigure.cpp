#include "chessfigure.h"
namespace gameitems {

std::tuple<ChessFigure::ColorFigure, ChessFigure::TypeFigure, bool> const ChessFigure::get_figure ()
{
    return std::make_tuple(figure_color, figure_type, is_moved);
}

} // namespace gameitems

