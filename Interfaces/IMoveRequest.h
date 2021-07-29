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


} // namespace interfaces



#endif // IMOVEREQUEST_H
