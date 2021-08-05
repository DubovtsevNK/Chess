#ifndef CHESSFIGURE_H
#define CHESSFIGURE_H
namespace gameitems {
class ChessFigure
{
private:
    enum class ColorFigure
    {
        WHITE ,
        BLACK
    }color;

    enum class TypeFigure
    {
        PAWN = 1,
        KNIGHT = 3,
        BISHOP = -3,
        ROOK = 5,
        QUEEN = 9,
        KING = 10
    }type;
public:
    ChessFigure()= delete;
    ChessFigure(ColorFigure _color,TypeFigure _type) : color(_color), type(_type){}
    ~ChessFigure(){}

};
} // namespace gameitems

#endif // CHESSFIGURE_H
