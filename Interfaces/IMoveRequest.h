#ifndef IMOVEREQUEST_H
#define IMOVEREQUEST_H

namespace interfaces {
class IMoveRequest{

public:
    IMoveRequest(){}
    ~IMoveRequest(){}
    void virtual move_request() = 0;
	int temp;

};


}



#endif // IMOVEREQUEST_H
