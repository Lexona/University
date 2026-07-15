
namespace lasd {

/* ************************************************************************** */

// ------------------ NODE VEC ------------------

// ------------------ CONSTRUCTORS ------------------

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& data, ulong i, BinaryTreeVec<Data> *bt) {
    this->bt = bt;
    this->index = i;
    bt->elem[i] = data;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& data, ulong i, BinaryTreeVec<Data> *bt) {
    std::swap(this->bt, bt);
    std::swap(this->index, i);
    std::swap(this->elem[i], data);
}

// ------------------ SPECIFIC MEMEBR FUNCTIONS ------------------

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    if (index*2+1 < bt->size) {
        return true;
    }

    return false;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    if (index*2+2 < bt->size) {
        return true;
    }

    return false;
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if (HasLeftChild()) {
        return (bt->nodes[index*2+1]);
    } else {
        throw std::out_of_range("Figlio sinistro non trovato.");
    }
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if (HasLeftChild()) {
        return (bt->nodes[index*2+1]);
    } else {
        throw std::out_of_range("Figlio sinistro non trovato.");
    }
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if (HasRightChild()) {
        return (bt->nodes[index*2+2]);
    } else {
        throw std::out_of_range("Figlio destro non trovato.");
    }
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if (HasRightChild()) {
        return (bt->nodes[index*2+2]);
    } else {
        throw std::out_of_range("Figlio destro non trovato.");
    }
}

// ------------------ BINARY TREE ------------------

// ------------------ SPECIFIC CONSTRUCTORS ------------------

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& btv) {
    this->Resize(btv.Size());
    nodes = new NodeVec[btv.Size()];
    ulong i = 0;

    btv.Traverse(
        [this, &i] (const Data& data) {
            this->nodes[i].index = i;
            elem[i] = data;
            this->nodes[i].bt = this;
            i++;
        }
    );
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& btv) {
    this->Resize(btv.Size());
    nodes = new NodeVec[btv.Size()];
    ulong i = 0;

    btv.Map(
        [this, &i] (Data& data) {
            this->nodes[i].index = i;
            elem[i] = std::move(data);
            this->nodes[i].bt = this;
            i++;
        }
    );
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& btv) {
    this->Resize(btv.Size());
    nodes = new NodeVec[btv.Size()];

    std::copy(btv.elem, btv.elem + size, elem);
    std::copy(btv.nodes, btv.nodes + size, nodes);

    for (ulong i = 0; i < btv.Size(); i++) {
        nodes[i].bt = this;
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& btv) noexcept {
    std::swap(this->size, btv.size);
    std::swap(elem, btv.elem);
    std::swap(nodes, btv.nodes);

    for (ulong i = 0; i < size; i++) {
        nodes[i].bt = this;
    }
}

// ------------------ ASSIGNEMENTS ------------------

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& btv) {
    this->Clear();
    this->Resize(btv.Size());
    nodes = new NodeVec[btv.Size()];

    std::copy(btv.elem, btv.elem + size, elem);
    std::copy(btv.nodes, btv.nodes + size, nodes);

    for (ulong i = 0; i < btv.Size(); i++) {
        nodes[i].bt = this;
    }

    return *this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& btv) noexcept {
    std::swap(this->size, btv.size);
    std::swap(elem, btv.elem);
    std::swap(nodes, btv.nodes);

    for (ulong i = 0; i < size; i++) {
        nodes[i].bt = this;
    }

    for (ulong i = 0; i < btv.size; i++) {
        btv.nodes[i].bt = &btv;
    }

    return *this;
}

// ------------------ SPECIFIC MEMEBR FUNCTIONS (FROM BINARY TREE) ------------------

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const {
    if (!this->Empty()) {
        return nodes[0];
    } else {
        throw std::length_error("L'albero è vuoto.");
    }
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() {
    if (!this->Empty()) {
        return nodes[0];
    } else {
        throw std::length_error("L'albero è vuoto.");
    }
}




/* ************************************************************************** */

}
