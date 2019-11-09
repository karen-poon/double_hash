#include <iostream> 
using namespace std; 

#define TABLE_SIZE 11 

int curr_size = 0; 

int hash1(int key) { 
    return (key % TABLE_SIZE); //h1 = k % 11
} 

int hash2(int key) { 
    return ((3*key % 4) + 1);  //h2 = (3k % 4 + 1)
} 

int* createHash() {
    int *hashTable = new int[TABLE_SIZE]; 
    curr_size = 0; 
    for (int i=0; i<TABLE_SIZE; i++) 
        hashTable[i] = -1;
    return hashTable;
}

void insertHash(int *hashTable, int key) {
    if (curr_size == TABLE_SIZE) //cheeck if it's full
        return; 

    int index = hash1(key); 
  
    // if there is a collision
    if (hashTable[index] != -1) { 
        int index2 = hash2(key); 
        int i = 1; 
        while (1) { 
            int newIndex = (index + i * index2) % TABLE_SIZE; 

            //when no more collision
            if (hashTable[newIndex] == -1) { 
                hashTable[newIndex] = key; 
                break; 
            } 
            i++; 
        } 
    } 
    else
        hashTable[index] = key; 
    curr_size++; 
} 

// a function that prints the whole hash table 
void printHash(int *hashTable) { 
    for (int i = 0; i < TABLE_SIZE; i++) { 
        if (hashTable[i] != -1) 
            cout << i << " --- " << hashTable[i] << endl; 
        else
            cout << i << endl; 
    } 
} 

int main() 
{ 
    int a[] = {8, 19, 30, 12, 14, 13, 44};  //keys to be inserted into hash table
    int n = sizeof(a)/sizeof(a[0]);  //size of a
  
    // inserting keys into hash
    int *hashTable = createHash(); 
    for (int i = 0; i < n; i++) 
        insertHash(hashTable, a[i]); 
  
    // print result
    printHash(hashTable); 
    return 0; 
} 