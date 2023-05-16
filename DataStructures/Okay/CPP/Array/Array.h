#ifndef Array_H
#define Array_H

template <typename T>
class Array;

template <typename T>
Array<T>* Union(Array<T> *arr1, Array<T> *arr2);

template <typename T>
Array<T>* Intersection(Array<T> *arr1, Array<T> *arr2);

template <typename T>
Array<T>* Complement(Array<T> *arr1, Array<T> *arr2);

template <typename T>
class Array
{
    private:
        T* A;
        int size;
        int length;

    public:
        Array();
        Array(int arrsize);
        Array(int arrsize, int arrlength);
        Array(T* arr, int arrsize, int arrlength);
        T* GetArray();
        int GetSize();
        int GetLength();
        void SetArray(int ind, T x);
        void SetSize(int arrsize);
        void SetLength(int arrlength);

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
        Array<T>* Union(Array<T> *arr2);
        Array<T>* Intersection(Array<T> *arr2);
        Array<T>* Complement(Array<T> *arr2);

        //======================================================
        //      FRIEND FUNCTIONS
        //======================================================
        template<T> friend Array<T>* Union(Array<T> *arr1, Array<T> *arr2);
        template<T> friend Array<T>* Intersection(Array<T> *arr1, Array<T> *arr2);
        template<T> friend Array<T>* Complement(Array<T> *arr1, Array<T> *arr2);

};

#endif