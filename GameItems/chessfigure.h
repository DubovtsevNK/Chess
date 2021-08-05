#ifndef CHESSFIGURE_H
#define CHESSFIGURE_H
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
private:

public:
    ColorFigure figure_color;

    TypeFigure figure_type;

    ChessFigure()= delete;
    explicit ChessFigure(ColorFigure _color,TypeFigure _type) : figure_color(_color), figure_type(_type){}
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
