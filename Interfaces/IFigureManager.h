#ifndef IFIGUREMANAGER_H
#define IFIGUREMANAGER_H

namespace interfaces {
class IFigureManager{

public:
    IFigureManager(){}
    ~IFigureManager(){}
    void virtual available_move() = 0;

};
} // namespace interfaces


#endif // IFIGUREMANAGER_H
