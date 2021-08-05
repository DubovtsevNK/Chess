#ifndef CHESSFIGURE_H
#define CHESSFIGURE_H
namespace gameitems {
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
    ColorFigure figure_color;

    TypeFigure figure_type;
public:
    ChessFigure()= delete;
    ChessFigure(ColorFigure _color,TypeFigure _type) : figure_color(_color), figure_type(_type){}
    ~ChessFigure(){}

};
} // namespace gameitems

#endif // CHESSFIGURE_H
