#ifndef Array_H
#define Array_H

template <typename T>
class Array
{
    private:
        T* A;
        int size;
        int length;

    public:
        Array(T* arr, int arrsize, int arrlength);
        T* GetArray();
        int GetSize();
        int GetLength();

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
        void SortedInsert(T x);
        bool IsSorted();
        void PosNegSwap();
};

#endif