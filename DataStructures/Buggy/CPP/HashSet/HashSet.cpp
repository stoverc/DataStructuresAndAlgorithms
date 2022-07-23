#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>

using namespace std;

template <typename T>
class Bucket {
    public:
        Bucket();
        std::vector<T> get();
        void update(T key);
        void remove(T key);
        bool contains(T key);
        int getIndex(T key, int size);
        void print();
    private: 
         std::vector<T> bucket;
};

template <typename T>
Bucket<T>::Bucket(void){
    std::vector<T> bucket;// = new std:vector<T>();// = new std::vector<T>();
    cout << "Bucket is being created" << endl;
}

template <typename T>
std::vector<T> Bucket<T>::get(){
    return this->bucket;
}

template <typename T>
void Bucket<T>::update(T key){
    bool found=false;

    if(this->bucket.size()==0){
        this->bucket.insert(this->bucket.begin(),key);
        return;
    }

    for(int i = 0; i < this->bucket.size(); i++){
        if(key==this->bucket.at(i)){
            (this->bucket).insert(std::next(this->bucket.begin(),i),key);
            found=true;
            break;
        }
    }
            
    if(found==false){
        (this->bucket).push_back(key);
    }
}

template <typename T>
void Bucket<T>::remove(T key){
    if(this->bucket.size()==0){
        return;
    }

    for(int i = 0; i < this->bucket.size(); i++){
        if(key==this->bucket.at(i)){
            this->bucket.erase(std::next(this->bucket.begin(),i));
        }
    }
}

template <typename T>
bool Bucket<T>::contains(T key){
    for(int i=0; i < this->bucket.size(); i++){
        if(this->bucket.at(i)==key){
            return true;
        }
    }

    return false;
}

template <typename T>
int Bucket<T>::getIndex(T key, int size){
    if(this->contains(key)){
        return (int(key) < 0) ? size - (abs(int(key) % size)) % size : int(key) % size;
    }
    else{
        return -1;
    }
}

template <typename T>
void Bucket<T>::print(){
    for (T t: this->bucket)
        cout << t << ' ';
    cout << endl;
}

template <typename T>
class HashSet {
    public:
        HashSet();
        void add(T key);
        void remove(T key);
        bool contains(T key);
        int hash(int val1, int val2);
        void print();
    private:
        int key_space;
        std::vector< Bucket<T> > hash_table;
};

template <typename T>
HashSet<T>::HashSet(void){
    this->key_space = 2096;
    std::vector< Bucket<int> > hash_table (this->key_space);

    cout << "HashSet is being created" << endl;
}

template <typename T>
void HashSet<T>::add(T key){
    int hash_key = (int(key) < 0) ? this->key_space - (abs(int(key) % this->key_space)) % this->key_space : (int(key) % this->key_space);
    this->hash_table.at(hash_key).update(key);

    cout << to_string(key) << " was added." << endl;
}

template <typename T>
void HashSet<T>::remove(T key){
    int hash_key = (int (key) < 0) ? (this->key_space - abs(int(key) % this->key_space)) % this->key_space : (int(key) % this->key_space);
    this->hash_table.at(hash_key).remove(key);
}

int main(){
    // cout << "Hello World" << endl;

    Bucket<int> buck;
    buck.update(3);
    //buck.print();
    buck.update(25);
    buck.update(3);
    buck.remove(4);
    buck.print();
    buck.update(2098);

    // Print out the vector
    std::cout << "{ ";
    for (int n : buck.get()) {
        std::cout << n << ", ";
    }
    std::cout << "}; \n";

    (buck.contains(3)) ? cout << "True" << endl : cout << "False" << endl;
    (buck.contains(4)) ? cout << "True" << endl : cout << "False" << endl;

    cout << buck.getIndex(2098,2096) << endl;

    //buck.print();
    //HashSet<int> obj;
    //obj.add(2);

    // std::vector<int> test;
    // test.insert(test.begin(),200);
    // test.insert(std::next(test.begin(),2),100);
    
    // for (int t: test)
    //     std::cout << t << ' ';
}