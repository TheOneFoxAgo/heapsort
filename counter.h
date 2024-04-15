#ifndef COUNTER_H
#define COUNTER_H

struct Counter {
  int data;
  Counter(int data) : data(data) {}
  Counter &operator=(int lhs);
  static unsigned long long comparisons;
  static unsigned long long swaps;
  bool operator<(const Counter &other) const;
  friend void swap(Counter &lhs, Counter &rhs);
};

#endif
