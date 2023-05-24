#ifndef Element_H
#define Element_H

//======================================================
//      PRE-DEFINE CLASS
//======================================================
template <typename T>
class Element;

//======================================================
//      FRIEND FUNCTIONS
//======================================================

//======================================================
//      CLASS DEF
//======================================================
template <typename T>
class Element{
    public:
        int i;
        int j;
        T x;
};

#endif