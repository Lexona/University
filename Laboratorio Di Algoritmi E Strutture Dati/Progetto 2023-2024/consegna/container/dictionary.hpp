
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  DictionaryContainer& operator = (const DictionaryContainer& val) = delete;

  // Move assignment
  DictionaryContainer& operator = (DictionaryContainer&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const DictionaryContainer& val) const noexcept = delete;
  bool operator != (const DictionaryContainer& val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Insert(const Data&) = 0; // Copy of the value
  virtual bool Insert(Data&&) = 0; // Move of the value
  virtual bool Remove(const Data&) = 0;

  bool InsertAll(const TraversableContainer<Data>&); // Copy of the value; From TraversableContainer; True if all are inserted
  bool InsertAll(MappableContainer<Data>&&); // Move of the value; From MappableContainer; True if all are inserted
  bool RemoveAll(const TraversableContainer<Data>&); // From TraversableContainer; True if all are removed

  bool InsertSome(const TraversableContainer<Data>&); // Copy of the value; From TraversableContainer; True if some is inserted
  bool InsertSome(MappableContainer<Data>&&); // Move of the value; From MappableContainer; True if some is inserted
  bool RemoveSome(const TraversableContainer<Data>&); // From TraversableContainer; True if some is removed

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
