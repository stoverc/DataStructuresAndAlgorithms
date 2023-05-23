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

        void Read(){
            std::cout << "Enter non-zero elements: " << std::endl;

            for(int i = 0; i < numElts; i++){
                std::cin >> ele[i].i >> ele[i].j >> ele[i].x;
            }
        }

        void Display(){
            int k = 0;

            for(int i = 0; i < m; i++){
                std::cout << "[";

                for(int j = 0; j < n; j++){
                    if(i == ele[k].i && j == ele[k].j){
                        if(j != n-1){
                            std::cout << ele[k++].x << " ";
                        }
                        else std::cout << ele[k++].x << "]";
                    }
                    else {
                        if(j != n-1){
                            std::cout << "0 ";
                        }
                        else std::cout << "0]";
                    }
                }

                std::cout << std::endl;
            }
        }
};

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
    s1.Read();
    s1.Display();

    return 0;
}