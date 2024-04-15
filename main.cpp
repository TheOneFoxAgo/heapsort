#include "counter.h"
#include "heapsort.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>

const int STEP = 10'000;
const int LIMIT = 1'000'000;
const int RUNS = 5;

template <class T> std::chrono::microseconds test(std::vector<T> &data) {
  auto start = std::chrono::high_resolution_clock::now();
  heapsort(data.begin(), data.end());
  auto finish = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
}

int main(int argc, char **argv) {
  if (argc != 3) {
    return -1;
  }
  char caseType = *argv[1];
  std::vector<Counter> data;
  std::ofstream out(argv[2]);
  if (out.fail()) {
    return -1;
  }
  // out << "#Size\tTime\tComparisons\tSwaps\n";
  for (int i = STEP; i <= LIMIT; i += STEP) {
    auto time = 0;
    auto comparisons = 0;
    auto swaps = 0;
    for (int n = 0; n < RUNS; n++) {
      data.clear();
      for (int j = 0; j < i; j++) {
        data.push_back(std::rand());
      }
      switch (std::tolower(caseType)) {
      case 'a':
        // do nothing, the data is already shuffled
        break;
      case 'b':
        std::sort(data.rbegin(), data.rend());
        break;
      case 'w':
        std::sort(data.begin(), data.end());
        break;
      default:
        return -1;
      }
      Counter::comparisons = 0;
      Counter::swaps = 0;
      time += test(data).count();
      comparisons += Counter::comparisons;
      swaps += Counter::swaps;
    }
    out << i << ' ' << time / RUNS << ' ' << comparisons / RUNS << ' '
        << swaps / RUNS << '\n';
  }
}
