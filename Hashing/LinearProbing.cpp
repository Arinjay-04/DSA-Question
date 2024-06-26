#include <iostream>
#include <vector>
#include <string>

using namespace std;

// class HashTable {
// private:
//     vector<string> keys;
//     vector<string> values;
//     int size;

//     int hash_function(string key) {
//         int hash = 0;
//         for (char c : key) {
//             hash += c;
//         }
//         return hash % size;
//     }

// public:
//     HashTable(int table_size) {
//         size = table_size;
//         keys.resize(size);
//         values.resize(size);
//     }

//     void insert(string key, string value, bool with_replacement = true) {
//         int index = hash_function(key);
//         int original_index = index;

//         while (!keys[index].empty()) {
//             if (keys[index] == key) {
//                 if (with_replacement) {
//                     values[index] = value;
//                 }
//                 return;
//             }
//             index = (index + 1) % size;
//             if (index == original_index) {
//                 throw runtime_error("Hashtable is full");
//             }
//         }
//         keys[index] = key;
//         values[index] = value;
//     }

//     string search(string key) {
//         int index = hash_function(key);
//         int original_index = index;

//         while (!keys[index].empty()) {
//             if (keys[index] == key) {
//                 return values[index];
//             }
//             index = (index + 1) % size;
//             if (index == original_index) {
//                 break;
//             }
//         }
//         return "Key not found";
//     }
// };

// int main() {
//     HashTable hash_table_with_replacement(100);
//     HashTable hash_table_without_replacement(100);

//     // Insertion
//     hash_table_with_replacement.insert("Alice", "123456");
//     hash_table_with_replacement.insert("Bob", "789012");

//     hash_table_without_replacement.insert("Alice", "123456", false);
//     hash_table_without_replacement.insert("Bob", "789012", false);

//     // Searching
//     cout << "With Replacement:" << endl;
//     cout << "Alice's number: " << hash_table_with_replacement.search("Alice") << endl;
//     cout << "Bob's number: " << hash_table_with_replacement.search("Bob") << endl;

//     cout << "\nWithout Replacement:" << endl;
//     cout << "Alice's number: " << hash_table_without_replacement.search("Alice") << endl;
//     cout << "Bob's number: " << hash_table_without_replacement.search("Bob") << endl;

//     return 0;
// }



class HashTable{

    private:
    int size;
    int hash[10];
    int hash_function(int key){
        
        return  size%10;
    }

    public:
      
      HashTable(int size) : size(size) {
    for (int i = 0; i < 10; i++) {
        hash[i] = 0;
    }
}


      void insert(int key){
        int index = hash_function(key);
        int orig = index;

        while(hash[index] != 0){
             if(hash[index] == key){
                  return;
             }
             index = (index+1)%10;

             if(index == orig){
                throw runtime_error("Hash table is full");
             }

        }

        hash[index] = key;
      }

      void search(int key){
         int index = hash_function(key);
        int orig = index;
        
        while(hash[index] != 0){
             if(hash[index] == key){
                  cout<<"key found"<<endl;
                  return;
             }
             index = (index+1)%10;

             if(index == orig){
                break;
             }

        }

        cout<<"key is not present"<<endl;

      }

};


int main(){
 
    HashTable hash(6);

    hash.insert(10);
    hash.insert(25);
    hash.insert(7);
    hash.insert(15);
    hash.insert(20);
    hash.insert(13);
    hash.search(20);
    return 0;
}