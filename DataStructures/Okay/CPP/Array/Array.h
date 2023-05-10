#ifndef Array_H
#define Array_H

template <typename T>
class Array
{
    T* A;
    int size;
    int length;

    private:

    public:
        Array(T* arr, int arrsize, int arrlength);
        void Display();
        void Append(T x);
        void Insert(T x, int ind);
        void Delete(int ind);
};

#endif