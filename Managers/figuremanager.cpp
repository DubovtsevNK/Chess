#include "figuremanager.h"

namespace managers {
Figuremanager::Figuremanager()
{

}

std::list<interfaces::IGraphicsMove::SquareOnBoard> Figuremanager::move_request(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units)
{
    std::list<interfaces::IGraphicsMove::SquareOnBoard> variantMove;
    gameitems::ChessFigure* tmpFigure;
    tmpFigure = Board->available_move(units);

    if(tmpFigure == nullptr)
        //return /* ошибка */;
        switch (tmpFigure->figure_type)
        {
        case gameitems::ChessFigure::TypeFigure::PAWN :
            return movePawn(Board, units,tmpFigure);

        case gameitems::ChessFigure::TypeFigure::KNIGHT:
            return moveKnight(Board,units,tmpFigure);

        case gameitems::ChessFigure::TypeFigure::BISHOP:
            return moveBishop(Board,units,tmpFigure);

        case gameitems::ChessFigure::TypeFigure::QUEEN:
            return moveQueen(Board,units,tmpFigure);

        case gameitems::ChessFigure::TypeFigure::ROOK:
            return moveRook(Board,units,tmpFigure);

        case gameitems::ChessFigure::TypeFigure::KING:
            return moveKing(Board,units,tmpFigure);

        default:
            return  std::list<interfaces::IGraphicsMove::SquareOnBoard>(0);
        }
    return  std::list<interfaces::IGraphicsMove::SquareOnBoard>(0);
}
//!Пешка сложная фигура т.к ходит вперёд а бъёт по диагонали, поэтому ее функционал хода будет единственным
//!Функция нужена  для обоих цветов фигурт т.к эта фигура двигается только в одном направление.
//! Но плодить 2 функции не вижу смысла
std::list<interfaces::IGraphicsMove::SquareOnBoard> Figuremanager::movePawn(interfaces::IFigureManager *Board,
                                                                            interfaces::IGraphicsMove::SquareOnBoard units , gameitems::ChessFigure *figure)
{
    std::list<interfaces::IGraphicsMove::SquareOnBoard> listVariantMove;//<! Лист который будем возврашать
    gameitems::ChessFigure  *variantMove; //<! переменная для отслеживания поняля
    uint8_t number = 0;                       //<! Переменная что бы понимать насколько двигать пешку вперед, тоесть это ее первый ход или нет
    if(figure->figure_color == gameitems::ChessFigure::ColorFigure::WHITE)  //<! Условие для логики движения в зависимости от цвета фигуры
    {
        if(units.literal == 2)                                              //<! Проверка на то первый ход или нет
            number = 2;
        else
            number = 1;
        for (int counter = 1; counter<number+1; counter++ )                //<! Цикл для проверки движения вперед
        {

            variantMove = Board->available_move(unitsBoard(&units,counter,direction::NORTH));  //<! Опрос на клетку вперед
            if(variantMove == nullptr) listVariantMove.push_back(unitsBoard(&units,counter,direction::NORTH));
        }
        variantMove = Board->available_move(unitsBoard(&units,1,direction::NORTHEAST));  //<! Опрос на клетку по диагонале вправо
        if(variantMove != nullptr and variantMove->figure_color!=figure->figure_color) listVariantMove.push_back(unitsBoard(&units,1,direction::NORTHEAST)); //<! Если клетка не пустая и не союзная фигура то занести в вектор вариант хода
        variantMove = Board->available_move(unitsBoard(&units,1,direction::NORTHWEST));  //<! Опрос на клетку по диагонале влево
        if(variantMove != nullptr and variantMove->figure_color!=figure->figure_color) listVariantMove.push_back(unitsBoard(&units,1,direction::NORTHWEST));//<! Если клетка не пустая и не союзная фигура то занести в вектор вариант хода
    }
    else if(figure->figure_color == gameitems::ChessFigure::ColorFigure::BLACK) //<! ТО же самое что и для белой фигуры только в другую сторону
    {
        if(units.literal == 7)
            number = 2;
        else
            number = 1;
        for (int counter = 1; counter<number+1; counter++ )
        {

            variantMove = Board->available_move(unitsBoard(&units,counter,direction::SOUTH));
            if(variantMove == nullptr) listVariantMove.push_back(unitsBoard(&units,counter,direction::SOUTH));
        }
        variantMove = Board->available_move(unitsBoard(&units,1,direction::SOUTHEAST));
        if(variantMove != nullptr and variantMove->figure_color!=figure->figure_color) listVariantMove.push_back(unitsBoard(&units,1,direction::SOUTHEAST));
        variantMove = Board->available_move(unitsBoard(&units,1,direction::SOUTHWEST));
        if(variantMove != nullptr and variantMove->figure_color!=figure->figure_color) listVariantMove.push_back(unitsBoard(&units,1,direction::SOUTHWEST));
    }


    return listVariantMove;



}

std::list<interfaces::IGraphicsMove::SquareOnBoard> Figuremanager::moveKnight(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units, gameitems::ChessFigure *figure)
{
    std::list<interfaces::IGraphicsMove::SquareOnBoard> listVariantMove;//<! Лист который будем возврашать
    gameitems::ChessFigure  *variantMove; //<! переменная для отслеживания понля
    std::array<direction,4> arDirection {                    //<! Массив для прохода по всем направлениям
        direction::NORTH,
                direction::SOUTH,
                direction::EAST,
                direction::WEST};

    for(auto itDirectio : arDirection)//<! Проход по всем направлениям
    {
        uint8_t count = 1;           //<! Счетчик продвижения
        do
        {

            variantMove = Board->available_move(unitsBoard(&units,count++,itDirectio)); //<! Получение  что находится на клетки
            listVariantMove.push_back(unitsBoard(&units,count++,itDirectio));

        }
        while(variantMove==nullptr);
        if(variantMove->figure_color != figure->figure_color)  listVariantMove.push_back(unitsBoard(&units,count++,itDirectio)); //<! Если на клетке находится противник то добвляем этот вариант в лист
    }
    return listVariantMove;
}

std::list<interfaces::IGraphicsMove::SquareOnBoard> Figuremanager::moveBishop(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units, gameitems::ChessFigure *figure)
{
    std::list<interfaces::IGraphicsMove::SquareOnBoard> listVariantMove;//<! Лист который будем возврашать
    gameitems::ChessFigure  *variantMove; //<! переменная для отслеживания понля
    std::array<direction,4> arDirection {direction::NORTHEAST, //<! Массив для прохода по всем направлениям
                direction::NORTHWEST,
                direction::SOUTHEAST,
                direction::SOUTHWEST};

    for(auto itDirectio : arDirection)//<! Проход по всем направлениям
    {
        uint8_t count = 1;           //<! Счетчик продвижения
        do
        {

            variantMove = Board->available_move(unitsBoard(&units,count++,itDirectio)); //<! Получение  что находится на клетки
            listVariantMove.push_back(unitsBoard(&units,count++,itDirectio));

        }
        while(variantMove==nullptr);
        if(variantMove->figure_color != figure->figure_color)  listVariantMove.push_back(unitsBoard(&units,count++,itDirectio)); //<! Если на клетке находится противник то добвляем этот вариант в лист
    }
    return listVariantMove;
}

std::list<interfaces::IGraphicsMove::SquareOnBoard> Figuremanager::moveQueen(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units, gameitems::ChessFigure *figure)
{
    std::list<interfaces::IGraphicsMove::SquareOnBoard> listVariantMove;//<! Лист который будем возврашать
    gameitems::ChessFigure  *variantMove; //<! переменная для отслеживания понля
    std::array<direction,8> arDirection {direction::NORTHEAST, //<! Массив для прохода по всем направлениям
                direction::NORTHWEST,
                direction::SOUTHEAST,
                direction::SOUTHWEST,
                direction::EAST, //<! Массив для прохода по всем направлениям
                direction::NORTH,
                direction::SOUTH,
                direction::WEST};

    for(auto itDirectio : arDirection)//<! Проход по всем направлениям
    {
        uint8_t count = 1;           //<! Счетчик продвижения
        do
        {

            variantMove = Board->available_move(unitsBoard(&units,count++,itDirectio)); //<! Получение  что находится на клетки
            listVariantMove.push_back(unitsBoard(&units,count++,itDirectio));

        }
        while(variantMove==nullptr);
        if(variantMove->figure_color != figure->figure_color)  listVariantMove.push_back(unitsBoard(&units,count++,itDirectio)); //<! Если на клетке находится противник то добвляем этот вариант в лист
    }
    return listVariantMove;
}

std::list<interfaces::IGraphicsMove::SquareOnBoard> Figuremanager::moveKing(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units, gameitems::ChessFigure *figure)
{
    std::list<interfaces::IGraphicsMove::SquareOnBoard> listVariantMove;//<! Лист который будем возврашать
    gameitems::ChessFigure  *variantMove; //<! переменная для отслеживания понля
    std::array<direction,8> arDirection {direction::NORTHEAST, //<! Массив для прохода по всем направлениям
                direction::NORTHWEST,
                direction::SOUTHEAST,
                direction::SOUTHWEST,
                direction::EAST, //<! Массив для прохода по всем направлениям
                direction::NORTH,
                direction::SOUTH,
                direction::WEST};

    for(auto itDirectio : arDirection)//<! Проход по всем направлениям
    {
        uint8_t count = 1;           //<! Счетчик продвижения


        variantMove = Board->available_move(unitsBoard(&units,count++,itDirectio)); //<! Получение  что находится на клетки
        if (variantMove==nullptr/*and тут необходима функция на проверку не под боем ли поле*/)     listVariantMove.push_back(unitsBoard(&units,count++,itDirectio));
        else if(variantMove->figure_color != figure->figure_color/*and тут необходима функция на проверку не под боем ли поле*/)  listVariantMove.push_back(unitsBoard(&units,count++,itDirectio)); //<! Если на клетке находится противник то добвляем этот вариант в лист
    }
    return listVariantMove;
}

//!Для коня буду все в ручную писать т.к. эта функция будет исользоваться единожды и конь один ходит по странному
std::list<interfaces::IGraphicsMove::SquareOnBoard> Figuremanager::moveRook(interfaces::IFigureManager *Board, interfaces::IGraphicsMove::SquareOnBoard units, gameitems::ChessFigure *figure)
{
    std::list<interfaces::IGraphicsMove::SquareOnBoard> listVariantMove;//<! Лист который будем возврашать
    gameitems::ChessFigure  *variantMove; //<! переменная для отслеживания понля

    interfaces::IGraphicsMove::SquareOnBoard tmpSquare = unitsBoard(&units,2,direction::NORTH); //<! Двигаемся на 2 клетки вперед
    variantMove = Board->available_move(unitsBoard(&tmpSquare,1,direction::EAST));              //<! Проверям с права на 1
    if(variantMove == nullptr or variantMove->figure_color != figure->figure_color) listVariantMove.push_back(unitsBoard(&tmpSquare,1,direction::EAST)); //<! Есди свободна или там враг добавляем
    variantMove = Board->available_move(unitsBoard(&tmpSquare,1,direction::WEST));              //<! Проверям с лева на 1 поле
    if(variantMove == nullptr or variantMove->figure_color != figure->figure_color) listVariantMove.push_back(unitsBoard(&tmpSquare,1,direction::EAST)); //<! Есди свободна или там враг добавляем

    tmpSquare = unitsBoard(&units,2,direction::SOUTH);                                          //<! По аналогии выше
    variantMove = Board->available_move(unitsBoard(&tmpSquare,1,direction::EAST));
    if(variantMove == nullptr or variantMove->figure_color != figure->figure_color) listVariantMove.push_back(unitsBoard(&tmpSquare,1,direction::EAST));
    variantMove = Board->available_move(unitsBoard(&tmpSquare,1,direction::WEST));
    if(variantMove == nullptr or variantMove->figure_color != figure->figure_color) listVariantMove.push_back(unitsBoard(&tmpSquare,1,direction::EAST));

    tmpSquare = unitsBoard(&units,2,direction::EAST);
    variantMove = Board->available_move(unitsBoard(&tmpSquare,1,direction::NORTH));
    if(variantMove == nullptr or variantMove->figure_color != figure->figure_color) listVariantMove.push_back(unitsBoard(&tmpSquare,1,direction::EAST));
    variantMove = Board->available_move(unitsBoard(&tmpSquare,1,direction::SOUTH));
    if(variantMove == nullptr or variantMove->figure_color != figure->figure_color) listVariantMove.push_back(unitsBoard(&tmpSquare,1,direction::EAST));

    tmpSquare = unitsBoard(&units,2,direction::WEST);
    variantMove = Board->available_move(unitsBoard(&tmpSquare,1,direction::NORTH));
    if(variantMove == nullptr or variantMove->figure_color != figure->figure_color) listVariantMove.push_back(unitsBoard(&tmpSquare,1,direction::EAST));
    variantMove = Board->available_move(unitsBoard(&tmpSquare,1,direction::SOUTH));
    if(variantMove == nullptr or variantMove->figure_color != figure->figure_color) listVariantMove.push_back(unitsBoard(&tmpSquare,1,direction::EAST));

    return listVariantMove ;


}



interfaces::IGraphicsMove::SquareOnBoard Figuremanager::unitsBoard(const interfaces::IGraphicsMove::SquareOnBoard  *units, const unsigned int count, direction dir)
{
    interfaces::IGraphicsMove::SquareOnBoard tmp =*units ;

    switch (dir)
    {
    case direction::NORTH :
        tmp.number+=count;
        return tmp;
    case direction::NORTHEAST :
        tmp.number+=count;
        tmp.literal+=count;
        return tmp;
    case direction::EAST :
        tmp.literal+=count;
        return tmp;
    case direction::SOUTHEAST :
        tmp.number-=count;
        tmp.literal+=count;
        return tmp;
    case direction::SOUTH :
        tmp.literal-=count;
        return tmp;
    case direction::SOUTHWEST :
        tmp.number-=count;
        tmp.literal-=count;
        return tmp;
    case direction::WEST :
        tmp.number-=count;
        return tmp;
    case direction::NORTHWEST :
        tmp.number+=count;
        tmp.literal-=count;
        return tmp;
    default:
        return tmp;
    }

}
} // namespace managers
