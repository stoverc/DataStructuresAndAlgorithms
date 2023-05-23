#include <iostream>

struct Element{
    int i;
    int j;
    int x;
};

struct SparseMatrix{
    int m;
    int n;
    int numElts;
    struct Element *ele;
};

void Create(struct SparseMatrix *s){
    int x, y;

    std::cout << "Enter dimensions: ";
    std::cin >> s -> m >> s -> n;
    std::cout << "Number of non-zero elements? ";
    std::cin >> s -> numElts;

    s->ele = new struct Element[s->numElts];

    std::cout << "Enter non-zero elements: " << std::endl;

    for(int i = 0; i < s -> numElts; i++){
        std::cin >> s -> ele[i].i >> s -> ele[i].j >> s -> ele[i].x;
    }
}

void Display(struct SparseMatrix s){
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
}

int main(){
    struct SparseMatrix s;

    Create(&s);
    Display(s);

    return 0;
}