#include "counter.h"
#include <utility>
bool Counter::operator<(const Counter &other) const {
  ++comparisons;
  return data < other.data;
}
Counter &Counter::operator=(int lhs) {
  data = lhs;
  return *this;
}
void swap(Counter &lhs, Counter &rhs) {
  ++Counter::swaps;
  std::swap(lhs.data, rhs.data);
}
unsigned long long Counter::comparisons = 0;
unsigned long long Counter::swaps = 0;
