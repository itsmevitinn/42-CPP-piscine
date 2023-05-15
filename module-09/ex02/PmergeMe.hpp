#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <stdexcept>
#include <vector>

void fillContainers(char** argv, int argc, std::vector<int>& vector, std::deque<int>& deque);
// vector functions
void printVector(const std::vector<int>& vector, std::string type);
void mergeSort(std::vector<int>& vector, int left, int right, int threshold);
void insertionSort(std::vector<int>& vector, int left, int right);
void merge(std::vector<int>& vector, int left, int middle, int right);

// deque functions
void mergeSort(std::deque<int>& deque, int left, int right, int threshold);
void insertionSort(std::deque<int>& deque, int left, int right);
void merge(std::deque<int>& deque, int left, int middle, int right);

#endif
