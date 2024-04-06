#include "heapsort.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

const int STEP = 500;
const int LIMIT = 100'000;

std::chrono::microseconds test(std::vector<int> &data) {
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
  std::vector<int> data;
  std::ofstream out(argv[2]);
  if (out.fail()) {
    return -1;
  }
  auto rng = std::default_random_engine();
  for (int i = STEP; i <= LIMIT; i += STEP) {
    for (int j = i - STEP; j < i; j++) {
      data.push_back(j);
    }
    switch (caseType) {
    case 'a':
      std::shuffle(data.begin(), data.end(), rng);
      break;
    case 'b':
      std::reverse(data.begin(), data.end());
      break;
    case 'w':
      // worst case is sorted data, so we are doing nothing.
      break;
    default:
      return -1;
    }
    out << i << ' ' << test(data).count() << '\n';
  }
}
