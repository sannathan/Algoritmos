#include "Dictionary.h"
#include "KVpair.h"
#include <assert.h>

// Dictionary implemented with a hash table
template <typename Key, typename E> class hashdict : public Dictionary<Key, E> {
private:
  KVpair<Key, E> *HT;
  int M;
  int currcnt;
  Key EMPTYKEY;

  int p(Key K, int i) const {}
  int h(int x) const { return x % M; }
  int h(char *x) const {
    int i, sum;
    for (sum = 0, i = 0; x[i] != '\0'; i++)
      sum += (int)x[i];
    return sum % M;
  }

  void hashInsert(const Key &k, const E &e) {
    int home;
    int pos = home = h(k);
    for (int i = 1; EMPTYKEY != (HT[pos]).key(); i++) {
      pos = (home + p(k, i)) % M;
      Assert(k != (HT[pos]).key() && "Duplicates not allowed");
    }
    KVpair<Key, E> temp(k, e);
    HT[pos] = temp;
  }

  E hashSearch(const Key &k) const {
    int home;
    int pos = home = h(k);
    for (int i = 1; (k != (HT[pos]).key()) && (EMPTYKEY != (HT[pos]).key());
         i++)
      pos = (home + p(k, i)) % M;
    if (k == (HT[pos]).key())
      return (HT[pos]).value();
    else
      return NULL;
  }

public:
  hashdict(int sz, Key k) {
    M = sz;
    EMPTYKEY = k;
    currcnt = 0;
    HT = new KVpair<Key, E>[sz];
    for (int i{}; i < M; i++) {
      (HT[i]).setKey(EMPTYKEY);
    }
  }

  ~hashdict() { delete HT; }
  E find(const Key &k) const { return hashSearch(k); }
  int size() { return currcnt; }
  void insert(const Key &k, const E &it) {
    assert(currcnt < M && "Hash table is full");
    hashInsert(k, it);
    currcnt++;
  }
};
