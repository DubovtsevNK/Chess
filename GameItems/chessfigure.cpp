#include "chessfigure.h"
namespace gameitems {

std::tuple<ChessFigure::ColorFigure, ChessFigure::TypeFigure> const ChessFigure::get_figure ()
{
    return std::make_tuple(figure_color, figure_type);
}

} // namespace gameitems

