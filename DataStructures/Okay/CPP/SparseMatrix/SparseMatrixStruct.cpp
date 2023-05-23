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

struct SparseMatrix * Add(struct SparseMatrix *s1, struct SparseMatrix *s2){
    struct SparseMatrix *sum;

    if(s1 -> m != s2 -> m || s1 -> n != s2 -> n){
        std::cout << "Dimensions do not match!" << std::endl;
        //return -1;
    }

    sum = new SparseMatrix;

    sum -> m = s1 -> m;
    sum -> n = s1 -> n;
    sum -> ele = new Element[s1 -> numElts + s2 -> numElts]; //this is the max size; may not need all this space

    int i = 0, j = 0, k = 0;

    while(i < s1 -> numElts && j < s2 -> numElts){
        if(s1 -> ele[i].i < s2 -> ele[j].i){
            sum -> ele[k++] = s1 -> ele[i++];
        }
        else if (s1 -> ele[i].i > s2 -> ele[j].i){
            sum -> ele[k++] = s2 -> ele[j++];
        }
        else{
            if(s1 -> ele[i].j < s2 -> ele[j].j){
                sum -> ele[k++] = s1 -> ele[i++];
            }
            else if(s1 -> ele[i].j > s2 -> ele[j].j){
                sum -> ele[k++] = s2 -> ele[j++];
            }
            else{
                sum -> ele[k] = s1 -> ele[i];
                sum -> ele[k++].x = s1 -> ele[i++].x + s2 -> ele[j++].x;
            }
        }
    }

    for(; i < s1 -> numElts; i++){
        sum -> ele[k++] = s1 -> ele[i];
    }

    for(; j < s2 -> numElts; j++){
        sum -> ele[k++] = s2 -> ele[j];
    }

    sum -> numElts = k;

    return sum;
}

int main(){
    struct SparseMatrix s1, s2, *s3;

    //Create(&s);
    //Display(s);

    Create(&s1);
    Create(&s2);
    s3 = Add(&s1,&s2);
    std::cout << "First matrix:" << std::endl;
    Display(s1);
    std::cout << "Second matrix:" << std::endl;
    Display(s2);
    std::cout << "Their sum:" << std::endl;
    Display(*s3);

    return 0;
}