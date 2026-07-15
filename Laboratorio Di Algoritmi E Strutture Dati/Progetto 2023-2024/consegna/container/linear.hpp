
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data>{

private:

protected:

  using Container::size;

public:

  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer& operator = (const LinearContainer& val) = delete;

  // Move assignment
  LinearContainer& operator = (LinearContainer&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator == (const LinearContainer& val) const;
  inline bool operator != (const LinearContainer& val) const;

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& operator[](ulong) const = 0; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  virtual Data& operator[](ulong) = 0; // (mutable version; concrete function must throw std::out_of_range when out of range)

  virtual inline const Data& Front() const; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual inline Data& Front(); // (mutable version; concrete function must throw std::length_error when empty)

  virtual inline const Data& Back() const;  // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual inline Data& Back(); // (mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void Traverse(TraverseFun) const override; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  virtual void PreOrderTraverse(TraverseFun) const override; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  virtual void PostOrderTraverse(TraverseFun) const override; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  virtual void Map(MapFun) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  virtual inline void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  virtual inline void PostOrderMap(MapFun) override; // Override PostOrderMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer : virtual public LinearContainer<Data> {

private:

protected:

  using Container::size;
  using LinearContainer<Data>::operator[];

public:

  // Destructor
  virtual ~SortableLinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  SortableLinearContainer& operator = (const SortableLinearContainer& val) = delete;

  // Move assignment
  SortableLinearContainer& operator = (SortableLinearContainer&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator == (const SortableLinearContainer& val) const;
  inline bool operator != (const SortableLinearContainer& val) const;

  /* ************************************************************************ */

  // Specific member function

  virtual void Sort() noexcept;

protected:

  // Auxiliary member functions
  void QuickSort(ulong, ulong) noexcept;
  ulong Partition(ulong, ulong) noexcept;
};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
