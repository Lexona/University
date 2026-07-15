
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  ulong operator()(const Data&) const noexcept; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer, virtual public DictionaryContainer<Data>{

private:

  // ...

protected:
  using Container::size;

  ulong a = 3;
  ulong b = 5;

  ulong prime = 1069;
  ulong tableSize = 16;

  std::default_random_engine seme = std::default_random_engine(std::random_device{}());
  std::uniform_int_distribution<ulong> semeA = std::uniform_int_distribution<ulong>(1, prime);
  std::uniform_int_distribution<ulong> semeB = std::uniform_int_distribution<ulong>(0, prime);

  //Constructor
  HashTable() {
    a = (semeA(seme)*2) + 1;
    b = std::pow(2, std::ceil(log2(semeB(seme))));
  }

  //Copy constructor
  HashTable(const HashTable&);

  //Move constructor
  HashTable(HashTable&&) noexcept;

public:

  // Destructor
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTable& operator=(const HashTable&); // Copy assignment of abstract types should not be possible.

  // Move assignment
  HashTable& operator=(HashTable&&) noexcept; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTable&) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.
  bool operator!=(const HashTable& hash) const noexcept {
    return !(operator==(hash));
  }; // Comparison of abstract hashtable is possible but not required.

protected:

  // Auxiliary member functions

  ulong HashKey(ulong) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
