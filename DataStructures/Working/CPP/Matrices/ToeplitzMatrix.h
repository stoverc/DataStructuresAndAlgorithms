#ifndef ToeplitzMatrix_H
#define ToeplitzMatrix_H

//======================================================
//      PRE-DEFINE CLASS
//======================================================
template <typename T>
class ToeplitzMatrix;

//======================================================
//      FRIEND FUNCTIONS
//======================================================


//======================================================
//      CLASS DEF
//======================================================
template <typename T>
class ToeplitzMatrix
{
    private:
        T* A;
        int n;

    public:
        ToeplitzMatrix(int n);
        ~ToeplitzMatrix();
        void Set(int i, int j, T x);
        T Get(int i, int j);

        void ShortPrint();
        void FullPrint();
};

#endif