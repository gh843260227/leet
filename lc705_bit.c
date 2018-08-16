#define SIZE (1000001/8)
typedef struct {
    unsigned char * hash;
} MyHashSet;

/** Initialize your data structure here. */
MyHashSet* myHashSetCreate() {
    MyHashSet* H = (MyHashSet*)malloc(sizeof(MyHashSet));
    H->hash = (int*)malloc(sizeof(unsigned char)* SIZE);
    memset(H->hash,0,sizeof(unsigned char)* SIZE);
    return H;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int pos = key / 8;
    int t = key % 8;
    obj->hash[pos] |= 1 << t ;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int pos = key / 8;
    int t = key%8;
    obj->hash[pos] &= ~(1 << t) ;
}

/** Returns true if this set did not already contain the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int pos = key / 8;
    int t = key%8;
    return obj->hash[pos] & (1 << t) ;
   
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->hash);
    free(obj);
}
