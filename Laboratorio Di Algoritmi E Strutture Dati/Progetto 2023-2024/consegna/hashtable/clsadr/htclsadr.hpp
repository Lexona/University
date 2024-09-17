
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../bst/bst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr : virtual public HashTable<Data> {

private:

protected:
  using Container::size;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::tableSize;
  BST<Data> *table = nullptr;

public:

  using DictionaryContainer<Data>::InsertAll;
  using DictionaryContainer<Data>::InsertSome;
  using DictionaryContainer<Data>::RemoveAll;
  using DictionaryContainer<Data>::RemoveSome;

  // Default constructor
  HashTableClsAdr() {
    table = new BST<Data>[tableSize]{};
  };

  /* ************************************************************************ */

  // Specific constructors
  HashTableClsAdr(const ulong); // A hash table of a given size
  HashTableClsAdr(const TraversableContainer<Data>&); // A hash table obtained from a TraversableContainer
  HashTableClsAdr(const ulong, const TraversableContainer<Data>&); // A hash table of a given size obtained from a TraversableContainer
  HashTableClsAdr(MappableContainer<Data>&&) noexcept; // A hash table obtained from a MappableContainer
  HashTableClsAdr(const ulong, MappableContainer<Data>&&) noexcept; // A hash table of a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableClsAdr(const HashTableClsAdr&);

  // Move constructor
  HashTableClsAdr(HashTableClsAdr&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~HashTableClsAdr() {
    delete[] table;
  };

  /* ************************************************************************ */

  // Copy assignment
  HashTableClsAdr& operator=(const HashTableClsAdr&);

  // Move assignment
  HashTableClsAdr& operator=(HashTableClsAdr&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableClsAdr&) const noexcept;
  bool operator!=(const HashTableClsAdr& hash) const noexcept {
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

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
