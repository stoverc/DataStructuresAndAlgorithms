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

        friend std::istream & operator>>(std::istream &is, SparseMatrix &s);
        friend std::ostream & operator<<(std::ostream &os, SparseMatrix &s);
};

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
    //struct SparseMatrix s1, s2, *s3;

    //Create(&s);
    //Display(s);

    // Create(&s1);
    // Create(&s2);
    // s3 = Add(&s1,&s2);
    // std::cout << "First matrix:" << std::endl;
    // Display(s1);
    // std::cout << "Second matrix:" << std::endl;
    // Display(s2);
    // std::cout << "Their sum:" << std::endl;
    // Display(*s3);

    SparseMatrix s1(5,5,5);
    std::cin >> s1;
    std::cout << s1;

    return 0;
}