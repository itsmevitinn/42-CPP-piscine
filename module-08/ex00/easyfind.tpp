const char* ValueNotFound::what() const throw() {
  return ("Value not found in container!");
}

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator index = std::find(container.begin(), container.end(), value);

  if (index == container.end())
    throw ValueNotFound();
  return (index);
}
