#ifndef CHESSFIGURE_H
#define CHESSFIGURE_H
#include <tuple>
namespace gameitems {
//!Класс шахматной фигуры.
class ChessFigure
{
public:
    enum class ColorFigure
    {
        WHITE ,
        BLACK
    };

    enum class TypeFigure
    {
        PAWN = 1,
        KNIGHT = 3,
        BISHOP = -3,
        ROOK = 5,
        QUEEN = 9,
        KING = 10
    };

    ColorFigure const figure_color;

    TypeFigure const figure_type;

    bool is_moved; //<Признак того, что фигура совершала движение в игре.

    ChessFigure()= delete;

    explicit ChessFigure(ColorFigure _color,TypeFigure _type) : figure_color(_color), figure_type(_type), is_moved(false){}

    std::tuple <ColorFigure , TypeFigure, bool> const get_figure ();

    virtual ~ChessFigure(){}

};


struct unitchess_board
//! Прототип ячейки шахматного поля !!!! Сделать enum потом
{
    int  files;
    int ranks;

};
} // namespace gameitems

#endif // CHESSFIGURE_H
