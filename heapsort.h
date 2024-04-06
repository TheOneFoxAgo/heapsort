#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <algorithm>
#include <iostream>
#include <iterator>

namespace heapsortImpl {
template <class Iterator> Iterator parent(Iterator begin, Iterator current) {
  return begin + (current - begin - 1) / 2;
}
template <class Iterator> Iterator leftChild(Iterator begin, Iterator current) {
  return begin + (current - begin) * 2 + 1;
}
template <class Iterator>
Iterator rightChild(Iterator begin, Iterator current) {
  return begin + (current - begin) * 2 + 2;
}
template <class Iterator> void lift(Iterator begin, Iterator current) {
  auto currentParent = parent(begin, current);
  while (*currentParent < *current) {
    std::iter_swap(currentParent, current);
    current = currentParent;
    currentParent = parent(begin, currentParent);
  }
}
template <class Iterator> void makeHeap(Iterator begin, Iterator end) {
  for (auto current = begin; current != end; ++current) {
    auto left = leftChild(begin, current);
    if (left >= end) {
      break;
    }
    auto right = rightChild(begin, current);
    if (right >= end) {
      lift(begin, left);
      break;
    } else {
      auto max = (*right > *left) ? right : left;
      lift(begin, max);
    }
  }
}
template <class Iterator> void heapify(Iterator begin, Iterator end) {
  auto head = begin;
  while (true) {
    auto left = leftChild(begin, head);
    if (left >= end) {
      break;
    }
    auto right = rightChild(begin, head);
    if (right >= end) {
      if (*head < *left) {
        std::iter_swap(head, left);
        head = left;
      }
      break;
    }
    auto max = (*right > *left) ? right : left;
    if (*head < *max) {
      std::iter_swap(head, max);
      head = max;
      continue;
    }
    break;
  }
}
} // namespace heapsortImpl

template <class Iterator> void heapsort(Iterator begin, Iterator end) {
  using namespace heapsortImpl;
  makeHeap(begin, end);
  for (auto i = begin; i != end; ++i) {
    std::cout << *i << ' ';
  }
  std::cout << '\n';
  for (auto current = end - 1; current != begin; --current) {
    std::iter_swap(current, begin);
    heapify(begin, current);
  }
}

#endif
