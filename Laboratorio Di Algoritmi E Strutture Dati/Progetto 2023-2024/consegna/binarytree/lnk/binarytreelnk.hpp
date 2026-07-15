
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public MutableBinaryTree<Data> {

private:

protected:
  using Container::size;

  struct NodeLnk : virtual MutableBinaryTree<Data>::MutableNode { // Must extend MutableNode

  friend class BinaryTreeLnk<Data>;

  private:

  protected:

  public:

    Data element{};
    NodeLnk *LChild = nullptr;
    NodeLnk *RChild = nullptr;

    //Constructors

    NodeLnk() = default;

    NodeLnk(const Data& data) : element(data){};
    NodeLnk(Data&& data) noexcept : element(std::move(data)){};

    NodeLnk(const NodeLnk&);
    NodeLnk(NodeLnk&&) noexcept;

    //Destructors

    virtual ~NodeLnk();

    //Assignements

    NodeLnk& operator=(const NodeLnk&);
    NodeLnk& operator=(NodeLnk&&) noexcept;

    //Specific member functions

    virtual inline const Data& Element() const noexcept override {
      return element;
    };

    virtual inline Data& Element() noexcept override {
      return element;
    };

    virtual inline bool IsLeaf() const noexcept override {
      return (!(HasLeftChild() || HasRightChild()));
    };

    virtual inline bool HasLeftChild() const noexcept override {
      return (LChild == nullptr ? false : true);
    };

    virtual inline bool HasRightChild() const noexcept override {
      return (RChild == nullptr ? false : true);
    };

    virtual inline const NodeLnk& LeftChild() const override {
      if (IsLeaf()) {
        throw std::out_of_range("Non ha figlio sinistro.");
      } 

      return *LChild;
    };

    virtual inline NodeLnk& LeftChild() override {
      if (IsLeaf()) {
        throw std::out_of_range("Non ha figlio sinistro.");
      } 

      return *LChild;
    };

    virtual inline NodeLnk& RightChild() override {
      if (IsLeaf()) {
        throw std::out_of_range("Non ha figlio sinistro.");
      } 

      return *RChild;
    };

    virtual inline const NodeLnk& RightChild() const override {
      if (IsLeaf()) {
        throw std::out_of_range("Non ha figlio sinistro.");
      } 

      return *RChild;
    };

  };

  NodeLnk *root = nullptr;

public:

  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const TraversableContainer<Data>&); // A binary tree obtained from a TraversableContainer
  BinaryTreeLnk(MappableContainer<Data>&&); // A binary tree obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeLnk() {
    delete root;
  }

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk& operator=(const BinaryTreeLnk&);

  // Move assignment
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BinaryTreeLnk& btl) const noexcept {
    return BinaryTree<Data>::operator==(btl);
  };

  inline bool operator!=(const BinaryTreeLnk& btl) const noexcept {
    return !(operator==(btl));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  inline const NodeLnk& Root() const override {
    if (this->Empty()) {
      throw std::length_error("L'albero è vuoto.");
    }

    return *root;
  }; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  inline NodeLnk& Root() override {
    if (this->Empty()) {
      throw std::length_error("L'albero è vuoto.");
    }

    return *root;
  }; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override {
    if (root != nullptr) {
      delete root;
      root = nullptr;
    }
    size = 0;
  }; // Override ClearableContainer member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
