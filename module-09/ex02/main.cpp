#include "PmergeMe.hpp"

int main(int argc, char** argv) {
  try {
    std::vector<int> vector;
    std::deque<int> deque;

    fillContainers(argv, argc, vector, deque);
    printVector(vector, "before");

    clock_t start_time = clock();
    mergeSort(vector, 0, vector.size() - 1, 16);
    clock_t end_time = clock();
    double duration = (end_time - start_time) * 1000000.0 / CLOCKS_PER_SEC;

    printVector(vector, "after");
    std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << duration << " us" << std::endl;

    start_time = clock();
    mergeSort(deque, 0, deque.size() - 1, 16);
    end_time = clock();
    duration = (end_time - start_time) * 1000000.0 / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << deque.size() << " elements with std::deque : " << duration << " us" << std::endl;

  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  return (0);
}