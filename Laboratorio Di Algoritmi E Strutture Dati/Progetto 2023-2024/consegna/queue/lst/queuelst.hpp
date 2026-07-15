
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : virtual public Queue<Data>, virtual public List<Data>{

private:

protected:

public:

  // Default constructor
  inline QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  QueueLst(const TraversableContainer<Data>& trav) : List<Data>(trav) {}; // A stack obtained from a TraversableContainer
  QueueLst(MappableContainer<Data>&& map) : List<Data>(std::move(map)) {}; // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  inline QueueLst(const QueueLst& que) : List<Data>(que) {};

  // Move constructor
  inline QueueLst(QueueLst&& que) : List<Data>(std::move(que)){};

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  inline QueueLst& operator=(const QueueLst&);

  // Move assignment
  inline QueueLst& operator=(QueueLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const QueueLst&) const noexcept;
  inline bool operator!=(const QueueLst& ) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  inline const Data& Head() const override; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  inline Data& Head() override; // Override Queue member (mutable version; must throw std::length_error when empty)
  inline void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  inline Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  inline void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  inline void Enqueue(Data&&) override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
