
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer : virtual public TraversableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~MappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer& operator = (const MappableContainer& val) = delete;

  // Move assignment
  MappableContainer& operator = (MappableContainer&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const MappableContainer& val) const noexcept = delete;
  bool operator != (const MappableContainer& val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using MapFun = std::function<void(Data &)>;

  virtual void Map(MapFun) = 0;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PreOrderTraversableContainer<Data>{

private:

protected:

public:

  // Destructor
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderMappableContainer& operator = (const PreOrderMappableContainer& val) = delete;

  // Move assignment
  PreOrderMappableContainer& operator = (PreOrderMappableContainer&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const PreOrderMappableContainer& val) const noexcept = delete;
  bool operator != (const PreOrderMappableContainer& val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  using typename MappableContainer<Data>::MapFun;

  inline virtual void PreOrderMap(MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  inline virtual void Map(MapFun) override;
};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual public MappableContainer<Data>, virtual public PostOrderTraversableContainer<Data>{

private:

protected:

public:

  // Destructor
  virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderMappableContainer& operator = (const PostOrderMappableContainer& val) = delete;

  // Move assignment
  PostOrderMappableContainer& operator = (PostOrderMappableContainer&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const PostOrderMappableContainer& val) const noexcept = delete;
  bool operator != (const PostOrderMappableContainer& val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  inline virtual void PostOrderMap(MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  inline virtual void Map(MapFun) override;

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer : virtual public MappableContainer<Data>, virtual public InOrderTraversableContainer<Data>{

private:

protected:

public:

  // Destructor
  virtual ~InOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  InOrderMappableContainer& operator = (const InOrderMappableContainer& val) = delete;

  // Move assignment
  InOrderMappableContainer& operator = (InOrderMappableContainer&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const InOrderMappableContainer& val) const noexcept = delete;
  bool operator != (const InOrderMappableContainer& val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  inline virtual void InOrderMap(MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  inline virtual void Map(MapFun) override; 

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer : virtual public MappableContainer<Data>, virtual public BreadthTraversableContainer<Data>{

private:

protected:

public:

  // Destructor
  virtual ~BreadthMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  BreadthMappableContainer& operator = (const BreadthMappableContainer& val) = delete;

  // Move assignment
  BreadthMappableContainer& operator = (BreadthMappableContainer&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const BreadthMappableContainer& val) const noexcept = delete;
  bool operator != (const BreadthMappableContainer& val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  inline virtual void BreadthMap(MapFun) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  inline virtual void Map(MapFun) override; // Override MappableContainer member

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
