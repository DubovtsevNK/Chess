#ifndef IMOVEREQUEST_H
#define IMOVEREQUEST_H
#include "IFigureManager.h"

namespace interfaces {
class IMoveRequest{

public:
    IMoveRequest(){}
    ~IMoveRequest(){}
    void virtual move_request(IFigureManager *) = 0;
	int temp;

};


} // namespace interfaces



#endif // IMOVEREQUEST_H
