
namespace lasd {

/* ************************************************************************** */

// -------------- NODELNK --------------

// -------------- CONSTRUCTORS --------------

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk& nl) {
    element = nl.element;
    LChild = (nl.LChild != nullptr) ? new NodeLnk(*nl.LChild) : nullptr;
    RChild = (nl.RChild != nullptr) ? new NodeLnk(*nl.RChild) : nullptr;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk&& nl) noexcept {
    std::swap(element, nl->element);
    std::swap(LChild, nl->LChild);
    std::swap(RChild, nl->RChild);
}

// -------------- DESTRUCTOR --------------

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    if (LChild != nullptr) {
        delete LChild;
        LChild = nullptr;
    }

    if (RChild != nullptr) {
        delete RChild;
        RChild = nullptr;
    }
}

// -------------- ASSIGNEMETS --------------

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& nl) {
    element = nl->element;
    return *this;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& nl) noexcept {
    std::swap(element, nl->element);
    return *this;
}

// -------------- BINARY TREE LNK --------------

// -------------- CONSTRUCTORS --------------

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& btl) {
    size = btl.Size();
    QueueVec<NodeLnk**> queue;
    queue.Enqueue(&root);

    btl.Traverse(
        [&queue] (const Data& data) {
            NodeLnk *&current = *queue.HeadNDequeue();
            current = new NodeLnk(data);
            queue.Enqueue(&current->LChild);
            queue.Enqueue(&current->RChild);
        }
    );
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& btl) {
    size = btl.Size();
    QueueVec<NodeLnk**> queue;
    queue.Enqueue(&root);

    btl.Map(
        [&queue] (Data& data) {
            NodeLnk *&current = *queue.HeadNDequeue();
            current = new NodeLnk(std::move(data));
            queue.Enqueue(&current->LChild);
            queue.Enqueue(&current->RChild);
        }
    );
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& btl) {
    if (btl.root != nullptr) {
        root = new NodeLnk(*btl.root);
        size = btl.Size();
    }
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& btl) noexcept {
    std::swap(root, btl.root);
    std::swap(size, btl.size);
}

// -------------- ASSIGNEMENTS --------------

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& btl) {
    Clear();

    if (btl.root != nullptr) {
        root = new NodeLnk(*btl.root);
        size = btl.Size();
    }

    return *this;
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& btl) noexcept {
    std::swap(root, btl.root);
    std::swap(size, btl.size);
    return *this;
}

/* ************************************************************************** */

}
