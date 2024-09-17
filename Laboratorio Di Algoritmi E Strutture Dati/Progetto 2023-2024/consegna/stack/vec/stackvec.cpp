
namespace lasd {

/* ************************************************************************** */

// ----------------- MOVE CONSTRUCTOR -----------------

template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& sVec) noexcept {
    std::swap(index, sVec.index);
}


// ----------------- COPY ASSIGNMENT -----------------

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& sVec) {
    Vector<Data>::operator=(sVec);
    index = sVec.index;
    return *this;
}

// ----------------- MOVE ASSIGNMENT -----------------

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& sVec) noexcept {
    Vector<Data>::operator=(std::move(sVec));
    std::swap(index, sVec.index);
    return *this;
}

// ----------------- COMPARISON OPERATORS -----------------

template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& sVec) const noexcept {
    if (index == sVec.index) { //controlliamo il numero di elementi effettivi presenti nello stack
        for (ulong i = 0; i < index; i++) {
            if (elem[i] != sVec.elem[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

template <typename Data>
inline bool StackVec<Data>::operator!=(const StackVec<Data>& sVec) const noexcept {
    return !(*this == sVec);
}

// ----------------- SPECIFIC MEMBER FUNCTIONS (FROM STACK) -----------------

template <typename Data>
Data& StackVec<Data>::Top() {
    if (index != 0) {
        return elem[index - 1];
    } else {
        throw std::length_error("Stai provando a fare accesso a uno stack vuoto!");
    }
}

template <typename Data>
const Data& StackVec<Data>::Top() const {
    if (index != 0) {
        return elem[index - 1];
    } else {
        throw std::length_error("Stai provando a fare accesso a uno stack vuoto!");
    }
}

template <typename Data>
void StackVec<Data>::Pop() {
    if (index != 0) {
        Reduce();
        --index;
    } else {
        throw std::length_error("Stai provando a fare accesso a uno stack vuoto!");
    }
}

template <typename Data>
Data StackVec<Data>::TopNPop() {
    if (index != 0) {
        Reduce();
        return std::move(elem[--index]);
    } else {
        throw std::length_error("Stai provando a fare accesso a uno stack vuoto!");
    }
}

template <typename Data>
void StackVec<Data>::Push(const Data& data) {
    Expand();
    elem[index++] = data;
}

template <typename Data>
void StackVec<Data>::Push(Data&& data) noexcept {
    Expand();
    elem[index++] = std::move(data);
}


// ----------------- SPECIFIC MEMBER FUNCTIONS (FROM CONTAINER) -----------------

template <typename Data>
inline bool StackVec<Data>::Empty() const noexcept {
    return (index == 0);
}

template <typename Data>
inline ulong StackVec<Data>::Size() const noexcept {
    return index;
}

// ----------------- SPECIFIC MEMBER FUNCTIONS (FROM CLEARABLE CONTAINER) -----------------

template <typename Data>
void StackVec<Data>::Clear() {
    index = 0;
    Vector<Data>::Resize(1);
}

// ----------------- AUXILIARY FUNCTIONS -----------------

template <typename Data>
void StackVec<Data>::Expand() {
    if (index == size) {
        Vector<Data>::Resize(size*2);
    }
}

template <typename Data>
void StackVec<Data>::Reduce() {
    if (index == size/4) {
        Vector<Data>::Resize(size/2);
    }
}


/* ************************************************************************** */

}
