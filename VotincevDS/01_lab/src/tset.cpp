// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);
static TSet FAKE_SET(1);

TSet::TSet(int mp) : BitField(mp)
{
    MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
    MaxPower = s.MaxPower;
    BitField = s.BitField;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf)
{
    MaxPower = bf.GetLength();

}

TSet::operator TBitField()
{
    return TBitField(BitField);
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
    return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    BitField.ClrBit(Elem);
}

// теоретико-множественные операции

const TSet& TSet::operator=(const TSet &s) // присваивание
{

    MaxPower = s.MaxPower;
    BitField = s.BitField;
    return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    if ((MaxPower == s.MaxPower) && (BitField == s.BitField)) {
        return 1;
    }
    return 0;
    
}

int TSet::operator!=(const TSet &s) const // сравнение
{
    if ((MaxPower != s.MaxPower) || (BitField != s.BitField)) {
        return 1;
    }
    return 0;

}

TSet TSet::operator+(const TSet &s) // объединение
{
    /*if (MaxPower != s.MaxPower) {
        throw "err";
    }*/

    TSet answ((BitField | s.BitField).GetLength());
    answ.BitField = BitField | s.BitField;
    return answ;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    /*if (Elem < 0 || Elem > MaxPower) {
        throw "err";
    }*/

    TSet answ(MaxPower);
    answ.BitField = BitField;
    answ.BitField.SetBit(Elem);
    return answ;
    
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    /*if (Elem < 0 || Elem > MaxPower) {
        throw "err";
    }*/

    TSet answ(MaxPower);
    answ.BitField = BitField;
    answ.BitField.ClrBit(Elem);
    return answ;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    /*if (MaxPower != s.MaxPower) {
        throw "err";
    }*/

    TSet answ(max(MaxPower,s.MaxPower));
    answ.BitField = BitField & s.BitField;
    return answ;
    
}

TSet TSet::operator~(void) // дополнение
{  
    TSet answ(MaxPower);
    answ.BitField = ~BitField;
    return answ;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
    istr >> s.MaxPower;
    s = TSet(s.MaxPower);
    for (int i = 0; i < s.MaxPower; i++) {
        TELEM number;
        istr >> number;
        s.BitField.SetBit(number);
    }
    return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{   

   
    for (int i = 0; i < s.MaxPower; i++) {
        if (s.BitField.GetBit(i)) {
            ostr << i << ' ';
        }
    }
    return ostr;
}
