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
        //~Array();
        void Display();
        void Append(T x);
        void Insert(T x, int ind);
        void Delete(int ind);
        int LinearSearch(T x);
        int BinarySearch(T x);
        T Get(int ind);
        void Set(T x, int ind);
        T Sum();
        float Avg();
        T Max();
        T Min();
};

#endif