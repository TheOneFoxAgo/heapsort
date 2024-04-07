#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iterator>

namespace detail {
template <class Iterator> Iterator parent(Iterator begin, Iterator current) {
  return begin + (current - begin - 1) / 2;
}
template <class Iterator>
Iterator leftChild(Iterator begin, Iterator end, Iterator current) {
  auto diff = (current - begin) * 2 + 1;
  return diff < end - begin ? begin + diff : end;
}
template <class Iterator>
Iterator rightChild(Iterator begin, Iterator end, Iterator current) {
  auto diff = (current - begin) * 2 + 2;
  return diff < end - begin ? begin + diff : end;
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
    auto left = leftChild(begin, end, current);
    if (left >= end) {
      break;
    }
    auto right = rightChild(begin, end, current);
    if (right >= end) {
      lift(begin, left);
      break;
    } else {
      if (*right > *left) {
        std::swap(left, right);
      }
      lift(begin, left);
      lift(begin, right);
    }
  }
}
template <class Iterator> void heapify(Iterator begin, Iterator end) {
  auto head = begin;
  while (true) {
    auto left = leftChild(begin, end, head);
    if (left == end) {
      break;
    }
    auto right = rightChild(begin, end, head);
    if (right == end) {
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
    } else {
      break;
    }
  }
}
} // namespace detail

template <class Iterator> void heapsort(Iterator begin, Iterator end) {
  using namespace detail;
  makeHeap(begin, end);
  for (auto current = end - 1; current != begin; --current) {
    std::iter_swap(current, begin);
    heapify(begin, current);
  }
}

#endif
