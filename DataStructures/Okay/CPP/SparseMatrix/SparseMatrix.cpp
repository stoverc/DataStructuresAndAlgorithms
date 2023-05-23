#include <iostream>

class Element{
    public:
        int i;
        int j;
        int x;
};

class SparseMatrix{
    private:
        int m;
        int n;
        int numElts;
        struct Element *ele;

    public:
        SparseMatrix(int m, int n, int numElts){
            this -> m = m;
            this -> n = n;
            this -> numElts = numElts;

            ele = new Element[this -> numElts];
        }

        ~SparseMatrix(){
            delete [] ele;
        }

        SparseMatrix operator+(SparseMatrix &s);

        friend std::istream & operator>>(std::istream &is, SparseMatrix &s);
        friend std::ostream & operator<<(std::ostream &os, SparseMatrix &s);
};

SparseMatrix SparseMatrix::operator+(SparseMatrix &s){
    struct SparseMatrix *sum;

    if(m != s.m || n != s.n){
        std::cout << "Dimensions do not match!" << std::endl;
    }

    sum = new SparseMatrix(m,n,numElts+s.numElts);

    int i = 0, j = 0, k = 0;

    while(i < numElts && j < s.numElts){
        if(ele[i].i < s.ele[j].i){
            sum -> ele[k++] = ele[i++];
        }
        else if (ele[i].i > s.ele[j].i){
            sum -> ele[k++] = s.ele[j++];
        }
        else{
            if(ele[i].j < s.ele[j].j){
                sum -> ele[k++] = ele[i++];
            }
            else if(ele[i].j > s.ele[j].j){
                sum -> ele[k++] = s.ele[j++];
            }
            else{
                sum -> ele[k] = ele[i];
                sum -> ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }
    }

    for(; i < numElts; i++){
        sum -> ele[k++] = ele[i];
    }

    for(; j < s.numElts; j++){
        sum -> ele[k++] = s.ele[j];
    }

    sum -> numElts = k;

    return *sum;
}


std::istream & operator>>(std::istream &is, SparseMatrix &s){
    std::cout << "Enter non-zero elements: " << std::endl;

    for(int i = 0; i < s.numElts; i++){
        std::cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }

    return is;
}

std::ostream & operator<<(std::ostream &os, SparseMatrix &s){
    int k = 0;

    for(int i = 0; i < s.m; i++){
        std::cout << "[";

        for(int j = 0; j < s.n; j++){
            if(i == s.ele[k].i && j == s.ele[k].j){
                if(j != s.n-1){
                    std::cout << s.ele[k++].x << " ";
                }
                else std::cout << s.ele[k++].x << "]";
            }
            else {
                if(j != s.n-1){
                    std::cout << "0 ";
                }
                else std::cout << "0]";
            }
        }

        std::cout << std::endl;
    }

    return os;
}

int main(){
    // SparseMatrix s1(5,5,5);
    // std::cin >> s1;
    // std::cout << s1;

    SparseMatrix s2(5,5,5);
    SparseMatrix s3(5,5,5);

    std::cin >> s2;
    std::cin >> s3;

    std::cout << "First matrix: " << std::endl;
    std::cout << s2;

    std::cout << "Second matrix: " << std::endl;
    std::cout << s3;

    SparseMatrix sum = s2+s3;
    std::cout << "Their sum: " << std::endl;
    std::cout << sum;

    return 0;
}