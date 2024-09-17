
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data>{

private:

  enum Flag {
    empt,
    dirty,
    valid
  };

protected:

  using Container::size;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::tableSize;

  Data *table = nullptr;
  Flag *tableFlag = nullptr;

public:

  using DictionaryContainer<Data>::InsertAll;
  using DictionaryContainer<Data>::InsertSome;
  using DictionaryContainer<Data>::RemoveAll;
  using DictionaryContainer<Data>::RemoveSome;

  // Default constructor
  HashTableOpnAdr() {
    table = new Data[tableSize]{};
    tableFlag = new Flag[tableSize]{};
  };

  /* ************************************************************************ */

  // Specific constructors
  HashTableOpnAdr(const ulong); // A hash table of a given size
  HashTableOpnAdr(const TraversableContainer<Data>&); // A hash table obtained from a TraversableContainer
  HashTableOpnAdr(const ulong, const TraversableContainer<Data>&); // A hash table of a given size obtained from a TraversableContainer
  HashTableOpnAdr(MappableContainer<Data>&&) noexcept; // A hash table obtained from a MappableContainer
  HashTableOpnAdr(const ulong, MappableContainer<Data>&&) noexcept; // A hash table of a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr&);

  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~HashTableOpnAdr() {
    delete[] table;
    delete[] tableFlag;
  };

  /* ************************************************************************ */

  // Copy assignment
  HashTableOpnAdr& operator=(const HashTableOpnAdr&);

  // Move assignment
  HashTableOpnAdr& operator=(HashTableOpnAdr&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableOpnAdr&) const noexcept;
  bool operator!=(const HashTableOpnAdr& hash) const noexcept {
    return !(operator==(hash));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  virtual bool Insert(const Data&) override; // Override DictionaryContainer member (Copy of the value)
  virtual bool Insert(Data&&) override; // Override DictionaryContainer member (Move of the value)
  virtual bool Remove(const Data&) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  virtual void Resize(const ulong) override; // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  virtual void Clear() override; // Override Container member

protected:

  // Auxiliary member functions

  ulong HashKey(const Data&, ulong&) const noexcept;
  bool Find(ulong&, ulong&, const Data&) const noexcept;
  ulong FindEmpty(const Data&, ulong&) const noexcept;
  bool Remove(ulong&, const Data&) noexcept;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
