
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>, virtual public Vector<Data>{

private:

protected:

  ulong index = 0;
  using Vector<Data>::size;
  using Vector<Data>::elem;

public:

  // Default constructor
  StackVec() : Vector<Data>(1){};

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const TraversableContainer<Data>& trav) : Vector<Data>(trav), index(size) {}; // A stack obtained from a TraversableContainer
  StackVec(MappableContainer<Data>&& map) : Vector<Data>(std::move(map)), index(size) {}; // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec& sVec) : Vector<Data>(sVec), index(sVec.index) {};

  // Move constructor
  StackVec(StackVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec& operator=(const StackVec&);

  // Move assignment
  StackVec& operator=(StackVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec&) const noexcept;
  inline bool operator!=(const StackVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  const Data& Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data& Top() override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data&) override; // Override Stack member (copy of the value)
  void Push(Data&&) noexcept override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override; // Override Container member

  inline ulong Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions
  void Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
