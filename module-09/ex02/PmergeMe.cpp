#include "PmergeMe.hpp"

void fillContainers(char** argv, int argc, std::vector<int>& vector, std::deque<int>& deque) {
  int number = 1;
  if (argc <= 2)
    throw std::invalid_argument("You must send at least 2 numbers!");
  while (argv[number]) {
    int value = atoi(argv[number]);
    if (value < 0)
      throw std::invalid_argument("You must sent only positive numbers!");
    deque.push_back(atoi(argv[number]));
    vector.push_back(atoi(argv[number]));
    number++;
  }
}

// vector functions
void printVector(const std::vector<int>& vector, std::string type) {
  if (type == "before") {
    std::cout << "Before: ";
  } else {
    std::cout << "After: ";
  }
  for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

void mergeSort(std::vector<int>& vector, int left, int right, int threshold) {
  if (right - left > threshold) {
    int middle = (left + right) / 2;
    mergeSort(vector, left, middle, threshold);
    mergeSort(vector, middle + 1, right, threshold);
    merge(vector, left, middle, right);
  } else {
    insertionSort(vector, left, right);
  }
}

void insertionSort(std::vector<int>& vector, int left, int right) {
  for (int i = left; i <= right; i++) {
    double tmp = vector[i];
    int j = i;
    while ((j > left) && (vector[j - 1] > tmp)) {
      vector[j] = vector[j - 1];
      j--;
    }
    vector[j] = tmp;
  }
}

void merge(std::vector<int>& vector, int left, int middle, int right) {
  int size_left = middle - left + 1;
  int size_right = right - middle;

  std::vector<int> leftArr(size_left);
  std::vector<int> rightArr(size_right);
  std::copy(vector.begin() + left, vector.begin() + middle + 1, leftArr.begin());
  std::copy(vector.begin() + middle + 1, vector.begin() + right + 1, rightArr.begin());

  int i = 0;
  int j = 0;
  int k = left;
  while (i < size_left && j < size_right) {
    if (leftArr[i] <= rightArr[j]) {
      vector[k] = leftArr[i];
      ++i;
    } else {
      vector[k] = rightArr[j];
      ++j;
    }
    ++k;
  }
  while (i < size_left)
    vector[k++] = leftArr[i++];
  while (i < size_right)
    vector[k++] = rightArr[j++];
}

// deque functions
void mergeSort(std::deque<int>& deque, int left, int right, int threshold) {
  if (right - left > threshold) {
    int middle = (left + right) / 2;
    mergeSort(deque, left, middle, threshold);
    mergeSort(deque, middle + 1, right, threshold);
    merge(deque, left, middle, right);
  } else {
    insertionSort(deque, left, right);
  }
}

void insertionSort(std::deque<int>& deque, int left, int right) {
  for (int i = left; i <= right; i++) {
    double tmp = deque[i];
    int j = i;
    while ((j > left) && (deque[j - 1] > tmp)) {
      deque[j] = deque[j - 1];
      j--;
    }
    deque[j] = tmp;
  }
}

void merge(std::deque<int>& deque, int left, int middle, int right) {
  int size_left = middle - left + 1;
  int size_right = right - middle;

  std::deque<int> leftArr(size_left);
  std::deque<int> rightArr(size_right);
  std::copy(deque.begin() + left, deque.begin() + middle + 1, leftArr.begin());
  std::copy(deque.begin() + middle + 1, deque.begin() + right + 1, rightArr.begin());

  int i = 0;
  int j = 0;
  int k = left;
  while (i < size_left && j < size_right) {
    if (leftArr[i] <= rightArr[j]) {
      deque[k] = leftArr[i];
      ++i;
    } else {
      deque[k] = rightArr[j];
      ++j;
    }
    ++k;
  }
  while (i < size_left)
    deque[k++] = leftArr[i++];
  while (i < size_right)
    deque[k++] = rightArr[j++];
}