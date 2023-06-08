import java.util.*;

public class HashSet<T> {
    Integer key_space;
    ArrayList<Bucket> hash_table;

    public class Bucket {
        public List<T> bucket;
        
        public Bucket(){
            bucket = new ArrayList<T>();
        }

        public void update(T key){
            Boolean found=false;

            for(int i = 0; i < this.bucket.size(); i++){
                if(key==this.bucket.get(i)){
                    this.bucket.add(i,key);
                    found=true;
                    break;
                }
            }
                    
            if(found==false){
                this.bucket.add(key);
            }
        }

        public Boolean contains(T key){
            for(int i=0; i<this.bucket.size(); i++){
                if(this.bucket.get(i)==key){
                    return true;
                }
            }

            return false;
        }

        public void remove(T key){
            for(int i = 0; i < this.bucket.size(); i++){
                if(key==this.bucket.get(i)){
                    this.bucket.remove(i);
                }
            }
        }

        public List<T> get(){
            return this.bucket;
        }

        public Integer getIndex(T key, Integer size){
            if(this.contains(key)){
                return ((Integer) key < 0) ? (size - (Math.abs((Integer)key) % size)) % size : ((Integer)key % size);
            }
            else{
                return -1;
            }
        }
    }

    public HashSet(){
        this.key_space = 2096;
        this.hash_table = new ArrayList<Bucket>();

        for(int i = 0; i < this.key_space; i++){
            this.hash_table.add(i,new Bucket());
        }
    }

    public void add(T key){
        int hash_key = ((Integer) key < 0) ? (this.key_space - (Math.abs((Integer)key) % this.key_space)) % this.key_space : ((Integer)key % this.key_space);
        this.hash_table.get(hash_key).update(key);
    }

    public void remove(T key){
        int hash_key = ((Integer) key < 0) ? (this.key_space - (Math.abs((Integer)key) % this.key_space)) % this.key_space : ((Integer)key % this.key_space);
        this.hash_table.get(hash_key).remove(key);
    }
    
    public Boolean contains(T key){
        int hash_key = ((Integer) key < 0) ? (this.key_space - (Math.abs((Integer)key) % this.key_space)) % this.key_space : ((Integer)key % this.key_space);
        return this.hash_table.get(hash_key).contains(key);
    }

    public Integer hash(Integer val1, Integer val2){
        return (val1 < 0) ? (val2 - (Math.abs(val1) % val2)) % val2 : (val1 % val2);
    }

    public void print(){
        List<Bucket> arr = new ArrayList<Bucket>();
        List<Integer> ind = new ArrayList<Integer>();
        Boolean empty = true;

        for(Bucket buck : this.hash_table) {
            if(buck.bucket.size()>0){
                empty = false;
                arr.add(buck);
                ind.add(hash((Integer)buck.get().get(0),this.key_space));
            }         
        }

        if(empty==true){
            System.out.println(Collections.<String>emptyList());
            return;
        }
        else{
            for(int i = 0; i < arr.size(); i++) {
                System.out.println("["+ind.get(i)+","+arr.get(i).get()+"]");
            }

            System.out.println("\n");
        }
    }

    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");

        HashSet<Integer> obj = new HashSet<Integer>();
        obj.print();
    
        obj.add(2);
        obj.add(2098);
        obj.add(13);
        obj.add(31);
        obj.add(-1);
        obj.print();
    
        obj.remove(31);
        obj.print();
    
        System.out.println(obj.contains(13));
        System.out.println(obj.contains(31));
        
        obj.print();

        obj.add(2098);
        obj.print();
        obj.add(2);
        obj.print();
    }
}
