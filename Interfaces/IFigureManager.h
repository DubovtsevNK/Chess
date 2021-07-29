#ifndef IFIGUREMANAGER_H
#define IFIGUREMANAGER_H

namespace Interface {
class IFigureManager{

public:
    IFigureManager(){}
    ~IFigureManager(){}
    void virtual available_move() = 0;

};
}


#endif // IFIGUREMANAGER_H
