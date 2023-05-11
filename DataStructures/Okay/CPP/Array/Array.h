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
        void Insert(int ind, T x);
        void Delete(int ind);
        int LinearSearch(T x);
        int BinarySearch(T x);
        T Get(int ind);
        void Set(int ind, T x);
        T Sum();
        float Avg();
        T Max();
        T Min();
        void Reverse();
        void LeftShift();
        void LeftRotate();
        void RightShift();
        void RightRotate();
};

#endif