#include "KVpair.h"
#include <assert.h>
#include <string>

using namespace std;

// Dictionary implemented with a hash table
template <typename Key, typename E>
class hashdict
{
private:
  KVpair<Key, E> *HT;
  int M;
  int currcnt;
  Key EMPTYKEY;
  Key TOMBSTONE;

  int h(int x) const { return x % M; }

  int h(const string &x) const
  {
    int sum = 0;
    for (size_t i = 1; i <= x.length(); i++)
    {
      sum += (int)x[i - 1] * i;
    }
    sum *= 19;
    return sum % M;
  }

  int p(Key K, int i) const { return ((i * i) + (23 * i)); }

  int hashInsert(const Key &k, const E &e)
  {
    int home;
    int pos = home = h(k);
    int firstTombstone = -1;

    if (EMPTYKEY == (HT[pos]).key())
    {
      KVpair<Key, E> temp(k, e);
      HT[pos] = temp;
      return pos;
    }
    else if (TOMBSTONE == (HT[pos]).key())
    {
      firstTombstone = pos;
    }
    else if (k == (HT[pos]).key())
    {
      return -1;
    }

    for (int i = 1; i <= 19; i++)
    {
      pos = (home + p(k, i)) % M;
      if (EMPTYKEY == (HT[pos]).key())
      {
        if (firstTombstone != -1)
        {
          pos = firstTombstone;
        }
        KVpair<Key, E> temp(k, e);
        HT[pos] = temp;
        return pos;
      }
      if (TOMBSTONE == (HT[pos]).key())
      {
        if (firstTombstone == -1)
        {
          firstTombstone = pos;
        }
      }
      else if (k == (HT[pos]).key())
      {
        return -1;
      }
    }

    if (firstTombstone != -1)
    {
      KVpair<Key, E> temp(k, e);
      HT[firstTombstone] = temp;
      return firstTombstone;
    }

    return -1;
  }

  E hashSearch(const Key &k) const
  {
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

  int hashDelete(const Key &k)
  {
    int home;
    int pos = home = h(k);

    if (k == (HT[pos]).key())
    {
      (HT[pos]).setKey(TOMBSTONE);
      return pos;
    }

    if (EMPTYKEY == (HT[pos]).key())
    {
      return -1;
    }

    for (int i = 1; i <= 19; i++)
    {
      pos = (home + p(k, i)) % M;
      if (EMPTYKEY == (HT[pos]).key())
      {
        return -1;
      }
      if (k == (HT[pos]).key())
      {
        (HT[pos]).setKey(TOMBSTONE);
        return pos;
      }
    }
    return -1;
  }

public:
  hashdict(int sz, Key k)
  {
    M = sz;
    EMPTYKEY = k;
    TOMBSTONE = "######";
    currcnt = 0;
    HT = new KVpair<Key, E>[sz];
    for (int i{}; i < M; i++)
    {
      (HT[i]).setKey(EMPTYKEY);
    }
  }

  ~hashdict() { delete[] HT; }

  E find(const Key &k) const { return hashSearch(k); }

  int size() { return currcnt; }

  int insert(const Key &k, const E &it)
  {
    if (currcnt >= M)
      return -1;
    int result = hashInsert(k, it);
    if (result != -1)
      currcnt++;
    return result;
  }

  int remove(const Key &k)
  {
    if(currcnt == 0) return -1;
    int keyPosition = hashDelete(k);
    if (keyPosition != -1)
      currcnt--;
    return keyPosition;
  }
};
