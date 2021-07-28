#ifndef IAVAILABLEMOVE_H
#define IAVAILABLEMOVE_H
namespace interfaces {
//!Абстрактный базовый класс обращения к менеджеру игры, при необходимости узнать возможные ходы для фигур.
class IAvailableMove{
public:
    ///todo:подумать над параметрами и возвращаемым значением.
    virtual void available_move() = 0;
};
}

#endif // IAVAILABLEMOVE_H
