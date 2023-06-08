#ifndef SymmetricMatrix_H
#define SymmetricMatrix_H

//======================================================
//      PRE-DEFINE CLASS
//======================================================
template <typename T>
class SymmetricMatrix;

//======================================================
//      FRIEND FUNCTIONS
//======================================================


//======================================================
//      CLASS DEF
//======================================================
template <typename T>
class SymmetricMatrix
{
    private:
        T* A;
        int n;

    public:
        SymmetricMatrix(int n);
        ~SymmetricMatrix();
        void Set(int i, int j, T x);
        T Get(int i, int j);

        void ShortPrint();
        void FullPrint();
};

#endif