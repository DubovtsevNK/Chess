#ifndef CHESSFIGURE_H
#define CHESSFIGURE_H
namespace gameitems {


struct ChessFigure
{
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

};
} // namespace gameitems



#endif // CHESSFIGURE_H
