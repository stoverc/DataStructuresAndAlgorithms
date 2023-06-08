#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int hash(int val1, int val2){
    return (val1 < 0) ? (val2 - (abs(val1) % val2)) % val2 : (val1 % val2);
}

template <typename T>
class Bucket{//<T> {
    public:
        Bucket<T>();
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
    std::vector<T> bucket;
}

template <typename T>
std::vector<T> Bucket<T>::get(){
    return bucket;
}

template <typename T>
void Bucket<T>::update(T key){
    bool found=false;

    if(bucket.size()==0){
        bucket.insert(bucket.begin(),key);
        return;
    }

    for(int i = 0; i < bucket.size(); i++){
        if(key==bucket.at(i)){
            (bucket).insert(std::next(bucket.begin(),i),key);
            found=true;
            break;
        }
    }
            
    if(found==false){
        (bucket).push_back(key);
    }
}

template <typename T>
void Bucket<T>::remove(T key){
    if(bucket.size()==0){
        return;
    }

    for(int i = 0; i < bucket.size(); i++){
        if(key==bucket.at(i)){
            bucket.erase(std::next(bucket.begin(),i));
        }
    }
}

template <typename T>
bool Bucket<T>::contains(T key){
    for(int i=0; i < bucket.size(); i++){
        if(bucket.at(i)==key){
            return true;
        }
    }

    return false;
}

template <typename T>
int Bucket<T>::getIndex(T key, int size){
    if(contains(key)){
        return (int(key) < 0) ? size - (abs(int(key) % size)) % size : int(key) % size;
    }
    else{
        return -1;
    }
}

template <typename T>
void Bucket<T>::print(){
    for (int t: bucket)
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
        void print();

        int getSize(){
            return key_space;
        }
    private:
        int key_space;
        std::vector< Bucket<T> > hash_table;
};

template <typename T>
HashSet<T>::HashSet(void){
    key_space = 2096;
    hash_table = std::vector< Bucket<T> >(key_space);
}

template <typename T>
void HashSet<T>::add(T key){
    int hash_key = ::hash(key, key_space);
    hash_table.at(hash_key).update(key);
}

template <typename T>
void HashSet<T>::remove(T key){
    int hash_key = ::hash(key, key_space);
    hash_table.at(hash_key).remove(key);
}

template <typename T>
bool HashSet<T>::contains(T key){
    int hash_key = ::hash(key, key_space);
    
    return hash_table.at(hash_key).contains(key);
}

template <typename T>
void HashSet<T>::print(){
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
    HashSet<int> obj;
    obj.add(2);
    obj.add(2098);
    obj.add(3);
    obj.print();
    obj.remove(2);
    obj.print();
    cout << obj.contains(2098) << endl;
    cout << obj.contains(2) << endl;
}