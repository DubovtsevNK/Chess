#ifndef IMOVEREQUEST_H
#define IMOVEREQUEST_H
#include "IFigureManager.h"
#include "IGraphicsMove.h"

namespace interfaces {
class IMoveRequest{

public:
    IMoveRequest(){}
    ~IMoveRequest(){}

    //todo: Необходимо убрать из интерфейса указатель на доску.
    //      Указатель на поле должен хранится как поле класса, иначе в классе диспетчера игры надо знать
    //      указатель на поле, для вызова этого метода.
    //      В метод интерфейса необходимо передавать только номер клетки, а всю бизнесс логику:
    //      с каким полем общаться и доступные ходы, должен решать уже диспетчер фигуры.
    virtual std::vector<interfaces::IGraphicsMove::SquareOnBoard> move_request(IFigureManager * board,gameitems::unitchess_board units) = 0;//<! files, ranks временные переменные пока не будет клетки
	int temp;

};


} // namespace interfaces



#endif // IMOVEREQUEST_H
