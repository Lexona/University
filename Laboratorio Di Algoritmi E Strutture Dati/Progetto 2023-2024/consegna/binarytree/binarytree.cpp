
namespace lasd {

/* ************************************************************************** */

// -------------- BINARY TREE --------------

// -------------- COMPARISON OPERATOR --------------

template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& bt) const noexcept {
    if (size != bt.size) {
        return false;
    }

    BTPreOrderIterator i(*this);
    BTPreOrderIterator j(bt);

    //scorro entrambi gli alberi per vedere se gli elementi sono gli stessi
    while (!(i.Terminated())) {
        if ((*i) != (*j)) {
            return false;
        }
        ++i;
        ++j;
    }

    return true;
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM TRAVEERSABLE CONTAINER) --------------

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun) const {
    if (!(this->Empty())) {
        PreOrderTraverse(fun, &this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun) const {
    if (!(this->Empty())) {
        PostOrderTraverse(fun, &this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun) const {
    if (!(this->Empty())) {
        InOrderTraverse(fun, &this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun) const {
    if (!(this->Empty())) {
        BreadthTraverse(fun, &this->Root());
    }
}

// -------------- AUXILIARY FUNCTIONS --------------

template <typename Data>
void BinaryTree<Data>::PreOrderTraverse(TraverseFun fun, const Node* node) const {
    fun(node->Element());

    if (node->HasLeftChild()) {
        PreOrderTraverse(fun, &node->LeftChild());
    }

    if (node->HasRightChild()) {
        PreOrderTraverse(fun, &node->RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::PostOrderTraverse(TraverseFun fun, const Node* node) const {
    if (node->HasLeftChild()) {
        PostOrderTraverse(fun, &node->LeftChild());
    }

    if (node->HasRightChild()) {
        PostOrderTraverse(fun, &node->RightChild());
    }

    fun(node->Element());
}

template <typename Data>
void BinaryTree<Data>::InOrderTraverse(TraverseFun fun, const Node* node) const {
    if (node->HasLeftChild()) {
        InOrderTraverse(fun, &node->LeftChild());
    }

    fun(node->Element());

    if (node->HasRightChild()) {
        InOrderTraverse(fun, &node->RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::BreadthTraverse(TraverseFun fun, const Node* node) const {
    lasd::QueueVec<const BinaryTree<Data>::Node*> queue;

    if (node != nullptr) {
        queue.Enqueue(node);
    }

    while (!queue.Empty()) {
        const BinaryTree<Data>::Node *current = queue.HeadNDequeue();
        fun(current->Element());

        if (current->HasLeftChild()) {
            queue.Enqueue(&current->LeftChild());
        }

        if (current->HasRightChild()) {
            queue.Enqueue(&current->RightChild());
        }
    }
}

// -------------- MUTABLE BINARY TREE --------------

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM MAPPABLE CONTAINER) --------------


template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun) {
    if (!(this->Empty())) {
        PreOrderMap(fun, &this->Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun) {
    if (!(this->Empty())) {
        PostOrderMap(fun, &this->Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun) {
    if (!(this->Empty())) {
        InOrderMap(fun, &this->Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun) {
    if (!(this->Empty())) {
        BreadthMap(fun, &this->Root());
    }
}

// -------------- AUXILIARY FUNCTIONS --------------

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MapFun fun, MutableNode* node) {
    fun(node->Element());

    if (node->HasLeftChild()) {
        PreOrderMap(fun, &node->LeftChild());
    }

    if (node->HasRightChild()) {
        PreOrderMap(fun, &node->RightChild());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MapFun fun, MutableNode* node) {
    if (node->HasLeftChild()) {
        PostOrderMap(fun, &node->LeftChild());
    }

    if (node->HasRightChild()) {
        PostOrderMap(fun, &node->RightChild());
    }

    fun(node->Element());
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MapFun fun, MutableNode* node) {
    if (node->HasLeftChild()) {
        InOrderMap(fun, &node->LeftChild());
    }

    fun(node->Element());

    if (node->HasRightChild()) {
        InOrderMap(fun, &node->RightChild());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MapFun fun, MutableNode* node) {
    lasd::QueueVec<MutableBinaryTree<Data>::MutableNode*> queue;

    if (node != nullptr) {
        queue.Enqueue(node); 
    }

    while (!queue.Empty()) {
        MutableBinaryTree<Data>::MutableNode *currentNode = queue.HeadNDequeue();
        fun(currentNode->Element());

        if (currentNode->HasLeftChild()) {
            queue.Enqueue(&currentNode->LeftChild());
        }

        if (currentNode->HasRightChild()) {
            queue.Enqueue(&currentNode->RightChild());
        }
    }
}

// -------------- PRE ORDER ITERATOR --------------

// -------------- CONSTRUCTORS --------------

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& bt) {
    if (!bt.Empty()) {
        root = &bt.Root();
        current = root;
    }
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& bt) : stack(bt.stack) {
    root = bt.root;
    current = bt.current;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& bt) noexcept : stack(std::move(bt.stack)) {
    std::swap(root, bt.root);
    std::swap(current, bt.current);
}

// -------------- ASSIGNEMENTS --------------

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator<Data>& bt) {
    root = bt.root;
    stack = bt.stack;
    current = bt.current;
    return *this;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& bt) noexcept {
    std::swap(root, bt.root);
    std::swap(stack, bt.stack);
    std::swap(current, bt.current);
    return *this;
}

// -------------- COMPARISON OPERATORS --------------

template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& bt) const noexcept {
    return ((current == bt.current) && (stack == bt.stack));
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM ITERATOR) --------------

template <typename Data>
const Data& BTPreOrderIterator<Data>::operator*() const {
    if (Terminated()) {
        throw std::out_of_range("L'iteratore è terminato");
    } else {
        return current->Element();
    }
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if (!Terminated()) {
        if (current->HasLeftChild()) {
            if (current->HasRightChild()) {
                stack.Push(&current->RightChild());
            }

            current =&(current->LeftChild());

        } else if (current->HasRightChild()) {
            current =&(current->RightChild());

        } else if (!stack.Empty()) {
            current = stack.TopNPop();
        } else {
            current = nullptr;
        }
    } else {
        throw std::out_of_range("L'iteratore è terminato");
    }

    return *this;
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM RESETTABLE ITERATOR) --------------

template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    stack.Clear();
    current = root;
}

// -------------- PRE ORDER MUTABLE ITERATOR --------------

// -------------- ASSIGNEMENTS --------------

template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator<Data>& bt) {
    this->root = bt.root;
    this->stack = bt.stack;
    this->current = bt.current;
    return *this;
}

template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator<Data>&& bt) noexcept {
    this->root = std::move(bt.root);
    this->stack = std::move(bt.stack);
    this->current = std::move(bt.current);
    return *this;
}

// -------------- POST ORDER ITERATOR --------------

template <typename Data>
const typename BinaryTree<Data>::Node* BTPostOrderIterator<Data>::DeepestLeftLeaf(const typename BinaryTree<Data>::Node* current) {
    if (current != nullptr) {
        while (current->HasLeftChild()) {
            stack.Push(current);
            current = &(current->LeftChild());
        }

        if (current->HasRightChild()) {
            stack.Push(current);
            current = &(current->RightChild());
            current = DeepestLeftLeaf(current);
        }
    }

    return current;
}

// -------------- CONSTRUCTORS --------------

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& bt) {
    if (bt.Empty()) {
        root = nullptr;
    } else {
        root = &bt.Root();
    }

    current = DeepestLeftLeaf(root);
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& bt) {
    stack = bt.stack;
    root = bt.root;
    current = bt.current;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& bt) noexcept : stack(std::move(bt.stack)) {
    std::swap(root, bt.root);
    std::swap(current, bt.current);
}

// -------------- ASSIGNEMENTS --------------

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator<Data>& bt) {
    stack = bt.stack;
    root = bt.root;
    current = bt.current;
    return *this;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& bt) noexcept {
    std::swap(stack, bt.stack);
    std::swap(root, bt.root);
    std::swap(current, bt.current);
    return *this;
}

// -------------- COMPARISON OPERATOR --------------

template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& bt) const noexcept {
    return ((current == bt.current) && (stack == bt.stack));
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM ITERATOR) --------------

template <typename Data>
const Data& BTPostOrderIterator<Data>::operator*() const {
    if (Terminated()) {
        throw std::out_of_range("L'iteratore è terminato");
    } else {
        return current->Element();
    }
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM FORWARD ITERATOR) --------------

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if (!Terminated()) {
        if (!(stack.Empty())) {
            if (stack.Top()->HasRightChild() && !(&(stack.Top()->RightChild()) == current)) {
                current = &(stack.Top()->RightChild());
                current = DeepestLeftLeaf(current);
            } else {
                current = stack.TopNPop();
            }
        } else {
            current = nullptr;
        }
    } else {
        throw std::out_of_range("L'iteratore è terminato");
    }

    return *this;
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM RESETTABLE ITERATOR) --------------

template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    stack.Clear();
    current = DeepestLeftLeaf(root);
}

// -------------- POST ORDER MUTABLE ITERATOR --------------

// -------------- ASSIGNEMENTS --------------

template <typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator<Data>& bt) {
    this->root = bt.root;
    this->stack = bt.stack;
    this->current = bt.current;
    return *this;
}

template <typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator<Data>&& bt) noexcept {
    std::swap(this->root, bt.root);
    std::swap(this->stack, bt.stack);
    std::swap(this->current, bt.current);
    return *this;
}

// -------------- IN ORDER ITERATOR --------------

template <typename Data>
const typename BinaryTree<Data>::Node* BTInOrderIterator<Data>::MostLeftNode(const typename BinaryTree<Data>::Node* currentNode) {
    while ((currentNode != nullptr) && (currentNode->HasLeftChild())) {
        stack.Push(currentNode);
        currentNode = &currentNode->LeftChild();
    }
    return currentNode;
}

// -------------- CONSTRUCTORS --------------

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& bt) {
    if (bt.Empty()) {
        root = nullptr;
    } else {
        root = &bt.Root();
    }

    current = MostLeftNode(root);
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& bt) {
    stack = bt.stack;
    root = bt.root;
    current = bt.current;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& bt) noexcept : stack(std::move(bt.stack)) {
    std::swap(root, bt.root);
    std::swap(current, bt.current);
}

// -------------- ASSIGNEMENTS --------------

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator<Data>& bt) {
    stack = bt.stack;
    root = bt.root;
    current = bt.current;
    
    return *this;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& bt) noexcept {
    std::swap(stack, bt.stack);
    std::swap(root, bt.root);
    std::swap(current, bt.current);
    return *this;
}

// -------------- COMPARISON OPERATOR --------------

template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& bt) const noexcept {
    return ((current == bt.current) && (stack == bt.stack));
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM ITERATOR) --------------

template <typename Data>
const Data& BTInOrderIterator<Data>::operator*() const {
    if (Terminated()) {
        throw std::out_of_range("L'iteratore è terminato.");
    } else {
        return current->Element();
    }
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM FORWARD ITERATOR) --------------

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if (!Terminated()) {
        if ((stack.Empty()) && !(current->HasRightChild())) {
            current = nullptr;
        } else {
            if (current->HasRightChild()) {
                current = MostLeftNode(&current->RightChild());
            } else {
                current = stack.TopNPop();
            }
        }
    } else {
        throw std::out_of_range("L'operatore è terminato.");
    }
    return *this;
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM RESETTABLE ITERATOR) --------------

template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    stack.Clear();
    current = MostLeftNode(root);
}

// -------------- IN ORDER MUTABLE ITERATOR --------------

// -------------- ASSIGNEMENTS --------------

template <typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator<Data>& bt) {
    this->root = bt.root;
    this->stack = bt.stack;
    this->current = bt.current;
    return *this;
}

template <typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator<Data>&& bt) noexcept {
    std::swap(this->root, bt.root);
    std::swap(this->stack, bt.stack);
    std::swap(this->current, bt.current);
    return *this;
}

// -------------- BREADTH ITERATOR --------------

// -------------- CONSTRUCTORS --------------

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& bt) {
    if (bt.Empty()) {
        root = nullptr;
    } else {
        root = &bt.Root();
    }

    current = root;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& bt) {
    queue = bt.queue;
    root = current = bt.root;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& bt) noexcept : queue(std::move(bt.queue)){
    std::swap(root, bt.root);
    std::swap(current, bt.current);
}

// -------------- ASSIGNEMENTS --------------

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& bt) {
    queue = bt.queue;
    root = bt.root;
    current = bt.current;
    return *this;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& bt) noexcept {
    std::swap(queue, bt.queue);
    std::swap(root, bt.root);
    std::swap(current, bt.current);
    return *this;
}

// -------------- COMPARISON OPERATOR --------------

template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& bt) const noexcept {
    return ((current == bt.current) && (queue == bt.queue));
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM ITERATOR) --------------

template <typename Data>
const Data& BTBreadthIterator<Data>::operator*() const {
    if (Terminated()) {
        throw std::out_of_range("L'iteratore è terminato.");
    } else {
        return current->Element();
    }
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM FARWARD ITERATOR) --------------

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if (!Terminated()) { 
        if (current != nullptr) { //ridondante
            if (current->HasLeftChild()) queue.Enqueue(&(current->LeftChild()));
            if (current->HasRightChild()) queue.Enqueue(&(current->RightChild()));
        
            if (!queue.Empty()) {
                current = queue.HeadNDequeue();
            } else {
                current = nullptr;
            }
        }
    } else {
        throw std::out_of_range("L'iteratore è terminato.");
    }

    return *this;
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM RESETTABLE ITERATOR) --------------

template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    queue.Clear();
    current = root;
}

// -------------- BREADTH MUTABLE ITERATOR --------------

// -------------- ASSIGNEMENTS --------------

template <typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator<Data>& bt) {
    this->root = bt.root;
    this->queue = bt.queue;
    this->current = bt.current;
    return *this;
}

template <typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator<Data>&& bt) noexcept {
    std::swap(this->root, bt.root);
    std::swap(this->queue, bt.queue);
    std::swap(this->current, bt.current);
    return *this;
}

/* ************************************************************************** */

}
