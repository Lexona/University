
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data>, virtual protected Vector<Data> {

private:

protected:

  // ...

  struct NodeVec : virtual MutableBinaryTree<Data>::MutableNode { 
  
  friend class BinaryTreeVec<Data>;

  private:

  protected:

  public:

    BinaryTreeVec<Data> *bt = nullptr;
    ulong index;

    //constructors
    NodeVec() {
      bt = nullptr;
      index = 0;
    };

    NodeVec(const Data&, ulong, BinaryTreeVec<Data>*);
    NodeVec(Data&&, ulong, BinaryTreeVec<Data>*);

    //Destructor
    inline virtual ~NodeVec() = default;

    //copy assignement
    inline NodeVec& operator=(const NodeVec& nv) {
      bt = nv.bt;
      index = nv.index;
      return *this;
    }

    //move assignement
    inline NodeVec& operator=(NodeVec&& nv) {
      std::swap(bt, nv.bt);
      std::swap(index, nv.index);
      return *this;
    }

    //Specific member functions
    inline virtual const Data& Element() const noexcept override {
      return bt->elem[index];
    }

    inline virtual Data& Element() noexcept override {
      return bt->elem[index];
    }

    inline virtual bool IsLeaf() const noexcept override {
      return (!(HasLeftChild() && HasRightChild()));
    };

    virtual bool HasLeftChild() const noexcept override;
    virtual bool HasRightChild() const noexcept override;

    virtual const NodeVec& LeftChild() const override;
    virtual NodeVec& LeftChild() override;

    virtual const NodeVec& RightChild() const override;
    virtual NodeVec& RightChild() override;

  };

    using Container::size;
    using Vector<Data>::elem;
    NodeVec *nodes = nullptr;

public:

  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const TraversableContainer<Data>&); // A binary tree obtained from a TraversableContainer
  BinaryTreeVec(MappableContainer<Data>&&); // A binary tree obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeVec() {
    delete[] nodes;
    nodes = nullptr;
  };

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec&);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BinaryTreeVec& btv) const noexcept {
    return Vector<Data>::operator==(btv);
  };

  inline bool operator!=(const BinaryTreeVec& btv) const noexcept {
    return !(operator==(btv));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  const NodeVec& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  NodeVec& Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override {
    Vector<Data>::Clear();
    delete[] nodes;
    nodes = nullptr;
  }; // Override ClearableContainer member

  /* ************************************************************************ */

  using typename TraversableContainer<Data>::TraverseFun;
  using typename MappableContainer<Data>::MapFun;

  // Specific member function (inherited from BreadthTraversableContainer)

  inline void BreadthTraverse(TraverseFun fun) const override {
    return Vector<Data>::PreOrderTraverse(fun);
  }; // Override BreadthTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  inline void BreadthMap(MapFun fun) override {
    return Vector<Data>::PreOrderMap(fun);
  }; // Override BreadthMappableContainer member


  // gestione del Diamond Problem

  void PreOrderTraverse(TraverseFun fun) const override {
    BinaryTree<Data>::PreOrderTraverse(fun);
  };

  void PostOrderTraverse(TraverseFun fun) const override {
    BinaryTree<Data>::PostOrderTraverse(fun);
  };

  void InOrderTraverse(TraverseFun fun) const override {
    BinaryTree<Data>::InOrderTraverse(fun);
  };

  void PreOrderMap(MapFun fun) override {
    MutableBinaryTree<Data>::PreOrderMap(fun);
  }

  void PostOrderMap(MapFun fun) override {
    MutableBinaryTree<Data>::PostOrderMap(fun);
  };

  void InOrderMap(MapFun fun) override {
    MutableBinaryTree<Data>::InOrderMap(fun);
  }

  void Traverse (TraverseFun fun) const override {
    BinaryTree<Data>::Traverse(fun); 
  }

  void Map (MapFun fun) override {
    MutableBinaryTree<Data>::Map(fun); 
  }


protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
