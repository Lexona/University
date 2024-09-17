
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>, virtual public List<Data> {

private:

protected:

public:

  // Default constructor
  inline StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const TraversableContainer<Data>& trav) : List<Data>(trav) {}; // A stack obtained from a TraversableContainer
  StackLst(MappableContainer<Data>&& map) : List<Data>(std::move(map)) {}; // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  inline StackLst(const StackLst& sList) : List<Data>(sList) {};

  // Move constructor
  inline StackLst(StackLst&& sList) : List<Data>(std::move(sList)) {};

  /* ************************************************************************ */

  // Destructor
  virtual ~StackLst()= default;

  /* ************************************************************************ */

  // Copy assignment
  inline StackLst& operator=(const StackLst&);

  // Move assignment
  inline StackLst& operator=(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const StackLst&) const noexcept;
  inline bool operator!=(const StackLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  inline const Data& Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  inline Data& Top() override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  inline void Pop() override; // Override Stack member (must throw std::length_error when empty)
  inline Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  inline void Push(const Data&) override; // Override Stack member (copy of the value)
  inline void Push(Data&&) noexcept override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
