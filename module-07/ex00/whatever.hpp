#include <iostream>

//will receive any type of "x" and "y" and swap each other
template <typename T>
void swap(T& x, T& y) {
  T tmp;

  tmp = x;
  x = y;
  y = tmp;
}
//will receive any type of "x" and "y" and return the smallest
template <typename T>
const T& min(const T& x, const T& y) {
  return (x < y ? x : y);
}
//will receive any type of "x" and "y" and return the greatest
template <typename T>
//return as const T& because we receive as const T&
const T& max(const T& x, const T& y) {
  return (x > y ? x : y);
}
