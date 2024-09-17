
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

  typedef unsigned long int ulong;

/* ************************************************************************** */

class Container {

private:

protected:

  ulong size = 0;

  /* ************************************************************************ */

public:

  // Destructor
  virtual ~Container() = default; 

  /* ************************************************************************ */

  // Copy assignment
  Container& operator= (const Container& val) = delete;

  // Move assignment
  Container& operator= (Container&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Container& val) const noexcept = delete;
  bool operator!=(const Container& val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions
  virtual inline bool Empty() const noexcept {
    return (size == 0);
  }

  virtual inline ulong Size() const noexcept {
    return size;
  }

};

/* ************************************************************************** */

class ClearableContainer : public virtual Container {

private:

protected:

public:

  // Destructor
  virtual ~ClearableContainer() = default; 

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer& operator=(const ClearableContainer& val) = delete;

  // Move assignment
  ClearableContainer& operator=(ClearableContainer&&) noexcept = delete; 

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ClearableContainer& val) const noexcept = delete;
  bool operator!=(const ClearableContainer& val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions
  virtual void Clear() = 0;
};

/* ************************************************************************** */

class ResizableContainer : public virtual ClearableContainer{

private:

protected:

public:

  // Destructor
  virtual ~ResizableContainer() = default; 

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer& operator = (const ResizableContainer& val) = delete;

  // Move assignment
  ResizableContainer& operator = (ResizableContainer&& val) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const ResizableContainer& val) const noexcept = delete;
  bool operator != (const ResizableContainer& val) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual void Resize(const ulong new_size) = 0; 

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual inline void Clear() override {
    Resize(0);
  }

};

/* ************************************************************************** */

}

#endif
