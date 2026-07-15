
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TraversableContainer : virtual public TestableContainer<Data>{

private:

protected:

public:

  // Destructor
  virtual ~TraversableContainer() = default; 

  /* ************************************************************************ */

  // Copy assignment
  TraversableContainer& operator= (const TraversableContainer &val) = delete;

  // Move assignment
  TraversableContainer& operator= (TraversableContainer &&val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const TraversableContainer &val) const noexcept = delete;
  bool operator != (const TraversableContainer &val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  using TraverseFun = std::function<void(const Data &)>; //è un puntatore a funzione

  virtual void Traverse(TraverseFun) const = 0; 

  template <typename Accumulator>
  using FoldFun = std::function<Accumulator(const Data &, const Accumulator &)>; //è un puntatore a funzione

  template <typename Accumulator>
  inline Accumulator Fold(FoldFun<Accumulator>, Accumulator) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  inline bool Exists(const Data&) const noexcept override; 

};

/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer : virtual public TraversableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~PreOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderTraversableContainer& operator = (const PreOrderTraversableContainer &val) = delete;

  // Move assignment
  PreOrderTraversableContainer& operator = (PreOrderTraversableContainer &&val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const PreOrderTraversableContainer &val) const noexcept = delete;
  bool operator != (const PreOrderTraversableContainer &val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void PreOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  inline Accumulator PreOrderFold(FoldFun<Accumulator>, Accumulator) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  virtual void Traverse(TraverseFun) const override;

};

/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer : virtual public TraversableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~PostOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderTraversableContainer& operator = (const PostOrderTraversableContainer& val) = delete;

  // Move assignment
  PostOrderTraversableContainer& operator = (PostOrderTraversableContainer&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const PostOrderTraversableContainer& val) const noexcept = delete;
  bool operator != (const PostOrderTraversableContainer& val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void PostOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  inline Accumulator PostOrderFold(FoldFun<Accumulator>, Accumulator) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  virtual void Traverse(TraverseFun) const override; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class InOrderTraversableContainer : virtual public TraversableContainer<Data>{

private:

protected:

public:

  // Destructor
  virtual ~InOrderTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  InOrderTraversableContainer& operator = (const InOrderTraversableContainer& val) = delete;

  // Move assignment
  InOrderTraversableContainer& operator = (InOrderTraversableContainer&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const InOrderTraversableContainer& val) const noexcept = delete;
  bool operator != (const InOrderTraversableContainer& val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void InOrderTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  inline Accumulator InOrderFold(FoldFun<Accumulator>, Accumulator) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  virtual void Traverse(TraverseFun) const override; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthTraversableContainer : virtual public TraversableContainer<Data>{

private:

protected:

public:

  // Destructor
  virtual ~BreadthTraversableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  BreadthTraversableContainer& operator = (const BreadthTraversableContainer& val) = delete;

  // Move assignment
  BreadthTraversableContainer& operator = (BreadthTraversableContainer&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const BreadthTraversableContainer& val) const noexcept = delete;
  bool operator != (const BreadthTraversableContainer& val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename TraversableContainer<Data>::TraverseFun;

  virtual void BreadthTraverse(TraverseFun) const = 0;

  template <typename Accumulator>
  using FoldFun = typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  inline Accumulator BreadthFold(FoldFun<Accumulator>, Accumulator) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  virtual void Traverse(TraverseFun) const override; // Override TraversableContainer member

};

/* ************************************************************************** */

}

#include "traversable.cpp"

#endif
