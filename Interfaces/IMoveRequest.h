#ifndef IMOVEREQUEST_H
#define IMOVEREQUEST_H
#include "IFigureManager.h"
#include "IGraphicsMove.h"
#include<list>

namespace interfaces {
//<! Интерфейс отвечающий за движения фигур по полю
//<! Ему все равно какого цвета фигура он просто проверяет возможные варианты хода
class IMoveRequest{

public:
    IMoveRequest(){}
    ~IMoveRequest(){}

    //todo: Необходимо убрать из интерфейса указатель на доску.
    //      Указатель на поле должен хранится как поле класса, иначе в классе диспетчера игры надо знать
    //      указатель на поле, для вызова этого метода.
    //      В метод интерфейса необходимо передавать только номер клетки, а всю бизнесс логику:
    //      с каким полем общаться и доступные ходы, должен решать уже диспетчер фигуры.
    // TODO: Не получится без указателя потому что по нему у меня происходит общение с доской
    // Для получения значений о ячейки поля.Либо в конструктор наследуемого класса передавать указатель на доску
    // без ьуказателя никак
    virtual std::list<interfaces::IGraphicsMove::SquareOnBoard> move_request(/*IFigureManager * board,*/interfaces::IGraphicsMove::SquareOnBoard units) = 0;//<! files, ranks временные переменные пока не будет клетки
	int temp;

};


} // namespace interfaces



#endif // IMOVEREQUEST_H
