
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
// #include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
// #include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree :
virtual public PreOrderTraversableContainer<Data>,
virtual public PostOrderTraversableContainer<Data>,
virtual public InOrderTraversableContainer<Data>,
virtual public BreadthTraversableContainer<Data> {

private:

protected:
  using Container::size;

public:

  struct Node {

  protected:

    // Comparison operators
    inline bool operator==(const Node& node) const noexcept {
      return (Element() == node.Element());
    }; // Comparison of abstract types is possible, but is not visible.
    
    
    inline bool operator!=(const Node& node) const noexcept {
      return !(operator==(node));
    }; // Comparison of abstract types is possible, but is not visible.

  public:

    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    Node& operator=(const Node&) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    Node& operator=(Node&&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ********************************************************************** */

    // Specific member functions

    virtual const Data& Element() const noexcept = 0; // Immutable access to the element (concrete function should not throw exceptions)

    virtual bool IsLeaf() const noexcept {
      return ((!HasLeftChild()) && (!HasRightChild()));
    }; // (concrete function should not throw exceptions)


    virtual bool HasLeftChild() const noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept = 0; // (concrete function should not throw exceptions)

    virtual const Node& LeftChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual const Node& RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree& operator=(const BinaryTree&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  BinaryTree& operator=(BinaryTree&&) noexcept = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree& bt) const noexcept {
    return !(operator==(bt));
  }; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Node& Root() const = 0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  virtual inline void Traverse(TraverseFun fun) const override {
    PreOrderTraverse(fun);
  } // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  virtual void PreOrderTraverse(TraverseFun) const override; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  virtual void PostOrderTraverse(TraverseFun) const override; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderTraversableContainer)

  virtual void InOrderTraverse(TraverseFun) const override; // Override InOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  virtual void BreadthTraverse(TraverseFun) const override; // Override BreadthTraversableContainer member

protected:

  // Auxiliary functions

  virtual void PreOrderTraverse(TraverseFun, const Node*) const;
  virtual void PostOrderTraverse(TraverseFun, const Node*) const;
  virtual void InOrderTraverse(TraverseFun, const Node*) const;
  virtual void BreadthTraverse(TraverseFun, const Node*) const;
};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree : virtual public ClearableContainer,
  virtual public BinaryTree<Data>,
  virtual public PreOrderMappableContainer<Data>,
  virtual public PostOrderMappableContainer<Data>,
  virtual public InOrderMappableContainer<Data>,
  virtual public BreadthMappableContainer<Data> {

private:

protected:

public:

  struct MutableNode : virtual public BinaryTree<Data>::Node {

    friend class MutableBinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~MutableNode() = default;

    /* ********************************************************************** */

    // Copy assignment
    MutableNode& operator=(const MutableNode&) = delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    MutableNode& operator=(MutableNode&&) noexcept = delete; // Move assignment of abstract types is not possible.

    /* ********************************************************************** */

    // Specific member functions

    virtual Data& Element() noexcept = 0; // Mutable access to the element (concrete function should not throw exceptions)

    virtual MutableNode& LeftChild() = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual MutableNode& RightChild() = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  virtual ~MutableBinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableBinaryTree& operator=(const MutableBinaryTree&) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  MutableBinaryTree& operator=(MutableBinaryTree&&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual MutableNode& Root() = 0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  virtual void Map(MapFun fun) override {
    PreOrderMap(fun);
  }; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  virtual void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  virtual void PostOrderMap(MapFun) override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  virtual void InOrderMap(MapFun) override; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  virtual void BreadthMap(MapFun) override; // Override BreadthMappableContainer member

protected:

  // Auxiliary functions

  virtual void PreOrderMap(MapFun, MutableNode*);
  virtual void PostOrderMap(MapFun, MutableNode*);
  virtual void InOrderMap(MapFun, MutableNode*);
  virtual void BreadthMap(MapFun, MutableNode*);

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>{             

private:

protected:

  const typename BinaryTree<Data>::Node* root = nullptr;
  const typename BinaryTree<Data>::Node* current = nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stack;

public:

  // Specific constructors
  BTPreOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderIterator(const BTPreOrderIterator&);

  // Move constructor
  BTPreOrderIterator(BTPreOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPreOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderIterator& operator=(const BTPreOrderIterator&);

  // Move assignment
  BTPreOrderIterator& operator=(BTPreOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPreOrderIterator&) const noexcept;
  
  inline bool operator!=(const BTPreOrderIterator& bt) const noexcept {
    return !(operator==(bt));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPreOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPreOrderIterator<Data>{

private:

protected:

public:

  // Specific constructors
  BTPreOrderMutableIterator(MutableBinaryTree<Data> mbt) : BTPreOrderIterator<Data>(mbt){;}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator& mbt) : BTPreOrderIterator<Data>(mbt) {;};

  // Move constructor
  BTPreOrderMutableIterator(BTPreOrderMutableIterator&& mbt) noexcept : BTPreOrderIterator<Data>(std::move(mbt)) {;};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPreOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderMutableIterator& operator=(const BTPreOrderMutableIterator&);

  // Move assignment
  BTPreOrderMutableIterator& operator=(BTPreOrderMutableIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTPreOrderMutableIterator& mbt) const noexcept {
    return BTPreOrderIterator<Data>::operator==(mbt);
  };
  
  inline bool operator!=(const BTPreOrderMutableIterator& mbt) const noexcept {
    return BTPreOrderIterator<Data>::operator!=(mbt);
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override {
    if(this->current != nullptr) {
      return const_cast<Data&>((this->current)->Element());
    } else {
      throw std::out_of_range("Errore!");
    }
  } // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data> {

private:

protected:

  const typename BinaryTree<Data>::Node* root = nullptr;
  const typename BinaryTree<Data>::Node* current = nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stack;

  const typename BinaryTree<Data>::Node* DeepestLeftLeaf(const typename BinaryTree<Data>::Node*);

public:

  // Specific constructors
  BTPostOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderIterator(const BTPostOrderIterator&);

  // Move constructor
  BTPostOrderIterator(BTPostOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPostOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderIterator& operator=(const BTPostOrderIterator&);

  // Move assignment
  BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderIterator&) const noexcept;
  inline bool operator!=(const BTPostOrderIterator& bt) const noexcept {
    return !(operator==(bt));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPostOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTPostOrderIterator<Data>{

private:

protected:

public:

  // Specific constructors
  BTPostOrderMutableIterator(MutableBinaryTree<Data>& mbt) : BTPostOrderIterator<Data>(mbt){;}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderMutableIterator(const BTPostOrderMutableIterator& mbt) : BTPostOrderIterator<Data>(mbt){;};

  // Move constructor
  BTPostOrderMutableIterator(BTPostOrderMutableIterator&& mbt) noexcept : BTPostOrderIterator<Data>(std::move(mbt)){;};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTPostOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderMutableIterator& operator=(const BTPostOrderMutableIterator&);

  // Move assignment
  BTPostOrderMutableIterator& operator=(BTPostOrderMutableIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTPostOrderMutableIterator& mbt) const noexcept {
    return BTPostOrderIterator<Data>::operator==(mbt);
  };

  inline bool operator!=(const BTPostOrderMutableIterator& mbt) const noexcept {
    return !(operator==(mbt));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override {
    if(this->current != nullptr) {
      return const_cast<Data&>((this->current)->Element());
    } else {
      throw std::out_of_range("Errore!");
    }
  } // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data> {

private:

protected:
  const typename BinaryTree<Data>::Node* current = nullptr;
  const typename BinaryTree<Data>::Node* root = nullptr;
  StackVec<const typename BinaryTree<Data>::Node*> stack;

  const typename BinaryTree<Data>::Node* MostLeftNode(const typename BinaryTree<Data>::Node*);

public:

  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderIterator(const BTInOrderIterator&);

  // Move constructor
  BTInOrderIterator(BTInOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderIterator& operator=(const BTInOrderIterator&);

  // Move assignment
  BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderIterator&) const noexcept;
  inline bool operator!=(const BTInOrderIterator& bt) const noexcept {
    return !(operator==(bt));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const override; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTInOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator : virtual public MutableIterator<Data>, virtual public BTInOrderIterator<Data>{

private:

protected:

public:

  // Specific constructors
  BTInOrderMutableIterator(MutableBinaryTree<Data> mbt) : BTInOrderIterator<Data>(mbt){;}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderMutableIterator(const BTInOrderMutableIterator& mbt) : BTInOrderIterator<Data>(mbt){;};

  // Move constructor
  BTInOrderMutableIterator(BTInOrderMutableIterator&& mbt) noexcept : BTInOrderIterator<Data>(std::move(mbt)){;};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTInOrderMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderMutableIterator& operator=(const BTInOrderMutableIterator&);

  // Move assignment
  BTInOrderMutableIterator& operator=(BTInOrderMutableIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTInOrderMutableIterator& mbt)  const noexcept {
    return BTInOrderIterator<Data>::operator==(mbt);
  };

  inline bool operator!=(const BTInOrderMutableIterator& mbt) const noexcept {
    return !(operator==(mbt));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override {
    if(this->current != nullptr) {
      return const_cast<Data&>((this->current)->Element());
    } else {
      throw std::out_of_range("Errore!");
    }
  } // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>, virtual public ResettableIterator<Data>{

private:

protected:
  const typename BinaryTree<Data>::Node* current = nullptr;
  const typename BinaryTree<Data>::Node* root = nullptr;

  QueueVec<const typename BinaryTree<Data>::Node*> queue;

public:

  // Specific constructors
  BTBreadthIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthIterator(const BTBreadthIterator&);

  // Move constructor
  BTBreadthIterator(BTBreadthIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BTBreadthIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthIterator& operator=(const BTBreadthIterator&);

  // Move assignment
  BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTBreadthIterator&) const noexcept;

  inline bool operator!=(const BTBreadthIterator& bt) const noexcept {
    return !(operator==(bt));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTBreadthIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : virtual public MutableIterator<Data>, virtual public BTBreadthIterator<Data>{

private:

protected:

public:

  // Specific constructors
  BTBreadthMutableIterator(MutableBinaryTree<Data>& mbt) : BTBreadthIterator<Data>(mbt){;}; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthMutableIterator(const BTBreadthMutableIterator& mbt) : BTBreadthIterator<Data>(mbt){;};

  // Move constructor
  BTBreadthMutableIterator(BTBreadthMutableIterator&& mbt) noexcept : BTBreadthIterator<Data>(std::move(mbt)){;};

  /* ************************************************************************ */

  // Destructor
  virtual ~BTBreadthMutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthMutableIterator& operator=(const BTBreadthMutableIterator&);

  // Move assignment
  BTBreadthMutableIterator& operator=(BTBreadthMutableIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BTBreadthMutableIterator& mbt) const noexcept  {
    return BTBreadthIterator<Data>::operator==(mbt);
  };

  inline bool operator!=(const BTBreadthMutableIterator& mbt) const noexcept {
    return !(operator==(mbt));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  Data& operator*() override {
    if(this->current != nullptr) {
      return const_cast<Data&>((this->current)->Element());
    }  else {
      throw std::out_of_range("Errore!");
    }
  } // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
