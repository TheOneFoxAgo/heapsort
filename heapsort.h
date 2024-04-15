#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <functional>
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
template <class Iterator,
          class Comparator = std::less<typename Iterator::value_type>>
void lift(Iterator begin, Iterator current, Comparator comp = {}) {
  auto currentParent = parent(begin, current);
  while (comp(*currentParent, *current)) {
    std::iter_swap(currentParent, current);
    current = currentParent;
    currentParent = parent(begin, currentParent);
  }
}
template <class Iterator,
          class Comparator = std::less<typename Iterator::value_type>>
void makeHeap(Iterator begin, Iterator end, Comparator comp = {}) {
  for (auto current = begin; current != end; ++current) {
    auto left = leftChild(begin, end, current);
    if (left == end) {
      break;
    }
    auto right = rightChild(begin, end, current);
    if (right == end) {
      lift(begin, left, comp);
      break;
    } else {
      if (comp(*left, *right)) {
        std::swap(left, right);
      }
      lift(begin, left, comp);
      lift(begin, right, comp);
    }
  }
}
template <class Iterator,
          class Comparator = std::less<typename Iterator::value_type>>
void heapify(Iterator begin, Iterator end, Comparator comp = {}) {
  auto head = begin;
  while (true) {
    auto left = leftChild(begin, end, head);
    if (left == end) {
      break;
    }
    auto right = rightChild(begin, end, head);
    if (right == end) {
      if (comp(*head, *left)) {
        std::iter_swap(head, left);
        head = left;
      }
      break;
    }
    auto max = (comp(*left, *right)) ? right : left;
    if (comp(*head, *max)) {
      std::iter_swap(head, max);
      head = max;
    } else {
      break;
    }
  }
}
} // namespace detail

template <class Iterator,
          class Comparator = std::less<typename Iterator::value_type>>
void heapsort(Iterator begin, Iterator end, Comparator comp = {}) {
  using namespace detail;
  makeHeap(begin, end, comp);
  for (auto current = end - 1; current != begin; --current) {
    std::iter_swap(current, begin);
    heapify(begin, current, comp);
  }
}

#endif
