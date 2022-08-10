#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int hash(int val1, int val2){
    return (val1 < 0) ? (val2 - (abs(val1) % val2)) % val2 : (val1 % val2);
}

// template <typename T>
class Bucket{//<T> {
    public:
        Bucket();
        std::vector<int> get();
        void update(int key);
        void remove(int key);
        bool contains(int key);
        int getIndex(int key, int size);
        void print();
    private: 
         std::vector<int> bucket;
};

//template <typename T>
Bucket::Bucket(void){
    std::vector<int> bucket;// = new std:vector<T>();// = new std::vector<T>();
    // cout << "Bucket is being created" << endl;
}

//template <typename T>
std::vector<int> Bucket::get(){
    return this->bucket;
}

//template <typename T>
void Bucket::update(int key){
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

//template <typename T>
void Bucket::remove(int key){
    if(this->bucket.size()==0){
        return;
    }

    for(int i = 0; i < this->bucket.size(); i++){
        if(key==this->bucket.at(i)){
            this->bucket.erase(std::next(this->bucket.begin(),i));
        }
    }
}

//template <typename T>
bool Bucket::contains(int key){
    for(int i=0; i < this->bucket.size(); i++){
        if(this->bucket.at(i)==key){
            return true;
        }
    }

    return false;
}

//template <typename T>
int Bucket::getIndex(int key, int size){
    if(this->contains(key)){
        return (int(key) < 0) ? size - (abs(int(key) % size)) % size : int(key) % size;
    }
    else{
        return -1;
    }
}

//template <typename T>
void Bucket::print(){
    for (int t: this->bucket)
        cout << t << ' ';
    cout << endl;
}

//template < class Bucket >
class HashSet {
    public:
        HashSet();
        void add(int key);
        void remove(int key);
        bool contains(int key);
        void print();

        int getSize(){
            return key_space;
        }
    private:
        int key_space;
        std::vector< Bucket > hash_table;
};

// template <typename T>
HashSet::HashSet(void){
    key_space = 2096;
    hash_table = std::vector<Bucket>(key_space);
    // cout << "HashSet is being created" << endl;
}

// template <typename T>
void HashSet::add(int key){
    int hash_key = ::hash(key, key_space);
    hash_table.at(hash_key).update(key);
    // cout << to_string(key) << " was added." << endl;
}

// template <typename T>
void HashSet::remove(int key){
    int hash_key = ::hash(key, key_space);
    this->hash_table.at(hash_key).remove(key);
}

// template <typename T>
bool HashSet::contains(int key){
    int hash_key = ::hash(key, key_space);
    
    return hash_table.at(hash_key).contains(key);
}

//template <typename T>
void HashSet::print(){
    std::vector<string> temp = std::vector<string>(hash_table.size());

    for(int i = 0; i < hash_table.size(); i++){
        if(hash_table[i].get().size()!=0){
            for(int j = 0; j<hash_table[i].get().size(); j++){
                temp[i] += to_string(hash_table[i].get().at(j)) + ", ";
            }
        }
    }
            
    for(int i = 0; i < hash_table.size(); i++)
    {
        if(hash_table[i].get().size()!=0){
            cout << "[" << i << ", [" << temp[i].substr(0,temp[i].length()-2) << "]]" << endl;
        }
    }
}

int main(){
    // cout << "Hello World" << endl;

    Bucket buck;
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
    HashSet obj;
    obj.add(2);
    obj.add(2098);
    obj.add(3);
    obj.print();
    obj.remove(2);
    obj.print();
    cout << obj.contains(2098) << endl;
    cout << obj.contains(2) << endl;
}