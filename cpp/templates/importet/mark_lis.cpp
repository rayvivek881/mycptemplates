#include<bits/stdc++.h>
using namespace std;

template<typename T>
int mark_lis(vector<T> & a) {
  int n = a.size(), cnt = 0;
  if (n == 0) {
    return 0;
  }
  vector<T> tail;
  vector<int> tail_idx, parent(n, -1);
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(tail.begin(), tail.end(), a[i]);
    int p = it - tail.begin();

    if (it == tail.end()) {
      tail.push_back(a[i]);
      tail_idx.push_back(i);
    } else {
      *it = a[i], tail_idx[p] = i;
    }
    if (p > 0) parent[i] = tail_idx[p - 1];
  }
  for (int i = tail_idx.back(); i != -1; i = parent[i]) {
    a[i] = -1, cnt += 1;
  }
  return cnt;
}
