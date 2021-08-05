#ifndef IMOVEREQUEST_H
#define IMOVEREQUEST_H
#include "IFigureManager.h"

namespace interfaces {
class IMoveRequest{

public:
    IMoveRequest(){}
    ~IMoveRequest(){}
    void virtual move_request(IFigureManager * board,gameitems::unitchess_board units) = 0;//<! files, ranks временные переменные пока не будет клетки
	int temp;

};


} // namespace interfaces



#endif // IMOVEREQUEST_H
