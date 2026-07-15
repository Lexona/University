
namespace lasd {

/* ************************************************************************** */

// ------------- BINARY SEARCH TREE -------------

// ------------- CONSTRUCTORS -------------

template <typename Data>
BST<Data>::BST(const TraversableContainer<Data>& bst) {
    bst.Traverse(
        [this](const Data& data) {
            Insert(data);
        }
    );
}

template <typename Data>
BST<Data>::BST(MappableContainer<Data>&& bst) noexcept {
    bst.Map(
        [this] (Data& data) {
            Insert(std::move(data));
        }
    );
}

// ------------- ASSIGNEMENT -------------

template <typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& bst) {
    BinaryTreeLnk<Data>::operator=(bst);
    return *this;
}

template <typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& bst) noexcept {
    BinaryTreeLnk<Data>::operator=(std::move(bst));
    return *this;
}

// ------------- COMPARISON OPERATOR -------------

template <typename Data>
bool BST<Data>::operator==(const BST<Data>& bst) const noexcept {
    if (size == bst.Size()) {
        BTInOrderIterator<Data> iterThis(*this);
        BTInOrderIterator<Data> iterBst(bst);

        for (; !iterThis.Terminated(); ++iterThis, ++iterBst) {
            if ((*iterThis) != (*iterBst)) {
                return false;
            }
        }

        return true;
    }

    return false;
}

// ------------- SPECIFIC MEMBER FUNCTIONS -------------

template <typename Data>
const Data& BST<Data>::Min() const {
    if (root != nullptr) {
        return FindPointerToMin(root)->element;
    } else {
        throw std::length_error("L'albero è vuoto.");
    }
}

template <typename Data>
Data BST<Data>::MinNRemove() {
    if (root != nullptr) {
        return DataNDelete(DetachMin(root));
    } else {
        throw std::length_error("L'albero è vuoto.");
    }
}

template <typename Data>
void BST<Data>::RemoveMin() {
    if (root != nullptr) {
        delete DetachMin(root);
    } else {
        throw std::length_error("L'albero è vuoto.");
    }
}

template <typename Data>
const Data& BST<Data>::Max() const {
    if (root != nullptr) {
        return FindPointerToMax(root)->element;
    } else {
        throw std::length_error("L'albero è vuoto.");
    }    
}

template <typename Data>
Data BST<Data>::MaxNRemove() {
    if (root != nullptr) {
        return DataNDelete(DetachMax(root));
    } else {
        throw std::length_error("L'albero è vuoto.");
    }
}

template <typename Data>
void BST<Data>::RemoveMax() {
    if (root != nullptr) {
        delete DetachMax(root);
    } else {
        throw std::length_error("L'albero è vuoto.");
    }
}

template <typename Data>
const Data& BST<Data>::Predecessor(const Data& data) const {
    NodeLnk* const* predecessor =& FindPointerToPredecessor(root, data);
    if (predecessor != nullptr) {
        return (*predecessor)->element;
    } else {
        throw std::length_error("Predecessore non trovato.");
    }
}

template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& data) {
    NodeLnk** predecessor =& FindPointerToPredecessor(root, data);
    if (predecessor != nullptr) {
        return DataNDelete(Detach(*predecessor));
    } else {
        throw std::length_error("Predecessore non trovato.");
    }
}

template <typename Data>
void BST<Data>::RemovePredecessor(const Data& data) {
    NodeLnk** predecessor =& FindPointerToPredecessor(root, data);
    if (predecessor != nullptr) {
        delete Detach(*predecessor);
    } else {
        throw std::length_error("Predecessore non trovato.");
    }
}

template <typename Data>
const Data& BST<Data>::Successor(const Data& data) const {
    NodeLnk* const* successor =& FindPointerToSuccessor(root, data);
    if (successor != nullptr) {
        return (*successor)->element;
    } else {
        throw std::length_error("Successore non trovato.");
    }
}

template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& data) {
    NodeLnk** successor =& FindPointerToSuccessor(root, data);
    if (successor != nullptr) {
        return DataNDelete(Detach(*successor));
    } else {
        throw std::length_error("Successore non trovato.");
    }
}

template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& data) {
    NodeLnk** successor =& FindPointerToSuccessor(root, data);
    if (successor != nullptr) {
        delete Detach(successor);
    } else {
        throw std::length_error("Successore non trovato.");
    }
}

// ------------- SPECIFIC MEMBER FUNCTIONS (FROM BINARY TREE) -------------

template <typename Data>
const typename BinaryTreeLnk<Data>::NodeLnk& BST<Data>::Root() const {
    if (this->Empty()) {
        throw std::length_error("L'albero è vuoto.");
    }
    
    return *root;
}

// ------------- SPECIFIC MEMBER FUNCTIONS (FROM DICTIONARY CONTAINER) -------------

template <typename Data>
bool BST<Data>::Insert(const Data& data) {
    NodeLnk *& puntatore = FindPointerTo(root, data);
    if (puntatore == nullptr) {
        puntatore = new NodeLnk(data);
        size++;
        return true;
    }

    return false;
}

template <typename Data>
bool BST<Data>::Insert(Data&& data) {
    NodeLnk *& puntatore = FindPointerTo(root, data);
    if (puntatore == nullptr) {
        puntatore = new NodeLnk(std::move(data));
        size++;
        return true;
    }
    
    return false;
}

template <typename Data>
bool BST<Data>::Remove(const Data& data) {
    NodeLnk *& puntatore = FindPointerTo(root, data);
    if (puntatore != nullptr) {
        delete Detach(puntatore);
        return true;
    } else {
        return false;
    }
}

// ------------- SPECIFIC MEMBER FUNCTIONS (FROM TESTABLE CONTAINER) -------------

template <typename Data>
bool BST<Data>::Exists(const Data& data) const noexcept {
    return (FindPointerTo(root, data) != nullptr);
}

// ------------- SPECIFIC MEMBER FUNCTIONS (FROM CLEARABLE CONTAINER) -------------

template <typename Data>
void BST<Data>::Clear() noexcept {
    BinaryTreeLnk<Data>::Clear();
}

// ------------- AUXILIARY FUNCTIONS -------------

template <typename Data>
Data BST<Data>::DataNDelete(NodeLnk* node) {
    Data value;
    std::swap(value, node->element);
    delete node;
    return value;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& node) noexcept {
    if (node != nullptr) {
        if (node->LChild == nullptr) {
            return Skip2Right(node);
        } else if (node->RChild == nullptr) {
            return Skip2Left(node);
        } else {
            NodeLnk *max = DetachMax(node->LChild);
            std::swap(node->element, max->element);
            return max;
        }
    }
    return nullptr;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& node) noexcept {
    return Skip2Right(FindPointerToMin(node));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& node) noexcept {
    return Skip2Left(FindPointerToMax(node));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk*& node) noexcept {
    NodeLnk *new_LChild = nullptr;

    if (node != nullptr) {
        std::swap(new_LChild, node->LChild);
        std::swap(new_LChild, node);
        size--;
    }
    
    return new_LChild;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& node) noexcept {
    NodeLnk *new_RChild = nullptr;

    if (node != nullptr) {
        std::swap(new_RChild, node->RChild);
        std::swap(new_RChild, node);
        size--;
    }
    
    return new_RChild;
}

template <typename Data>
typename BST<Data>::NodeLnk* const&  BST<Data>::FindPointerToMin(NodeLnk* const& node) const noexcept {
    NodeLnk* const* puntatore = &node;
    NodeLnk* current = node;

    if (current != nullptr) {
        while(current->LChild != nullptr) {
            puntatore =& current->LChild;
            current = current->LChild;
        }
    }

    return *puntatore;
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(NodeLnk* const& node) const noexcept {
    NodeLnk* const* puntatore = &node;
    NodeLnk* current = node;

    if (current != nullptr) {
        while(current->RChild != nullptr) {
            puntatore =& current->RChild;
            current = current->RChild;
        }
    }

    return *puntatore;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& node) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(node));
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& node) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMax(node));
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(NodeLnk* const& node, Data data) const noexcept {
    NodeLnk* const* puntatore = &node;
    NodeLnk *current = node;

    while (current != nullptr) {
        if (data > current->element) {
            puntatore = &current->RChild;
            current = current->RChild;
        } else if (data < current->element) {
            puntatore = &current->LChild;
            current = current->LChild;
        } else {
            break;
        }
    }

    return *puntatore;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& node, Data data) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(node, data));
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(NodeLnk* const& node, Data data) const noexcept {
    NodeLnk* const* predecessor = nullptr;
    NodeLnk* const* current = &node;

    while ((*current) != nullptr && (*current)->element != data) {
        if ((*current)->element > data) {
            current = &(*current)->LChild;
        } else if ((*current)->element < data) {
            predecessor = current;
            current = &(*current)->RChild;
        }
    }

    if ((*current) != nullptr && (*current)->LChild != nullptr) {
        predecessor = &FindPointerToMax((*current)->LChild);
    }

    return *predecessor;
}

template <typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(NodeLnk* const& node, Data data) const noexcept {
    NodeLnk* const* successor = nullptr;
    NodeLnk* const* current = &node;

    while ((*current) != nullptr && (*current)->element != data) {
        if ((*current)->element < data) {
            current = &(*current)->RChild;
        } else if ((*current)->element > data) {
            successor = current;
            current = &(*current)->LChild;
        }
    }

    if ((*current) != nullptr && (*current)->RChild != nullptr) {
        successor = &FindPointerToMin((*current)->RChild);
    }

    return *successor;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(NodeLnk*& node, Data data) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(node, data));
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(NodeLnk*& node, Data data) noexcept {
    return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(node, data));
}

/* ************************************************************************** */

}

