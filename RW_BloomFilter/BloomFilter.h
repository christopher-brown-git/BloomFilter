#include<functional>
#include<string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <pthread.h>

#define BITSET_SIZE 1024
#define NUM_HASH_FXNS 3
#define LENGTH 5

using namespace std;

template <typename T>
class BloomFilter{
  
 public:
  int m;
  int k;
  hash<T> hash_fxn;
  int bit_arr_size;
  pthread_rwlock_t* lock_arr;
  bitset<BITSET_SIZE>* bit_arr;
  
 public:
  BloomFilter();

  BloomFilter(int m, int k, hash<T> hash_fxn);

  virtual void insert(T obj);

  virtual bool query(T obj);
  
  int total_bits_allocated();

  int bits_user_asked_for();

  void serialize();

  void* deserialize();
};


struct wbuf {
    char** buf;
    uint32_t* offset;
    uint32_t*  size;
};
