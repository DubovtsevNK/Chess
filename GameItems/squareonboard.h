#ifndef SQUAREONBOARD_H
#define SQUAREONBOARD_H
//System include
#include <array>
namespace gameitems {
//!Структура шахматного поля
struct SquareOnBoard{
   //!Перечисление буквенной составляющей шахматного поля
   enum class literal : std::size_t{
       A = 0,
       B,
       C,
       D,
       E,
       F,
       G,
       H
   } Literal;

   //!Цифровая составляющая шахматного поля
   unsigned short Number;

   //Перегрузка операторов сравнения,что бы иметь возможность сравнивать поля
   friend bool operator == (const SquareOnBoard &S1,const SquareOnBoard &S2)
   {
       if((S1.Literal == S2.Literal) and (S1.Number == S2.Number)) return true;
       else return false;
   };
   friend bool operator != (const SquareOnBoard &S1,const SquareOnBoard &S2)
   {
       if((S1.Literal != S2.Literal) or (S1.Number != S2.Number)) return true;
       else return false;
   };
};

} // namespace gameitems


#endif // SQUAREONBOARD_H
