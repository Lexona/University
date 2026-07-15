
namespace lasd {

/* ************************************************************************** */

// -------------- SPECIFIC CONSTRUCTORS --------------

template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data>& trav) : Vector<Data>(trav), tail(size) {
    Vector<Data>::Resize(size*2);
}

template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data>&& map) : Vector<Data>(std::move(map)), tail(size) {
    Vector<Data>::Resize(size*2);
}


// -------------- MOVE CONSTRUCTOR --------------

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& que) noexcept : Vector<Data>(std::move(que)){
    std::swap(head, que.head);
    std::swap(tail, que.tail);
}

// -------------- COPY ASSIGNMENT --------------

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& que) {
    Vector<Data>::operator=(que);
    head = que.head;
    tail = que.tail;
    return *this;
}

// -------------- MOVE ASSIGNMENT --------------

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& que) noexcept {
    Vector<Data>::operator=(std::move(que));
    std::swap(head, que.head);
    std::swap(tail, que.tail);
    return *this;
}

// -------------- COMPARISON OPERATORS --------------

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& qVec) const noexcept {
    if (Size() == qVec.Size()) {
        for (ulong idx1 = head, idx2 = qVec.head; idx1 < tail; ++idx1 %= size, ++idx2 %= qVec.size) {
            if (elem[idx1] != qVec.elem[idx2]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

template <typename Data>
inline bool QueueVec<Data>::operator!=(const QueueVec& qVec) const noexcept {
    return !(*this == qVec);
}

// -------------- SPECIFIC MEMBER FUNCTIONS --------------

template <typename Data>
Data& QueueVec<Data>::Head() {
    if (head != tail) {
        return elem[head];
    } else {
        throw std::length_error("Stai provando a fare l'accesso a una coda vuota!");
    }
}

template <typename Data>
const Data& QueueVec<Data>::Head() const {
    if (head != tail) {
        return elem[head];
    } else {
        throw std::length_error("Stai provando a fare l'accesso a una coda vuota!");
    }
}

template <typename Data>
void QueueVec<Data>::Dequeue() {
    if (head != tail) {
        Reduce();
        ++head %= size;
    } else {
        throw std::length_error("Stai provando a fare l'accesso a una coda vuota!");
    }
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    if (head != tail) {
        Reduce();
        Data data(std::move(elem[head]));
        ++head %= size;
        return data;
    } else {
        throw std::length_error("Stai provando a fare l'accesso a una coda vuota!");
    }
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& data) {
    Expand();
    elem[tail++] = data;
    tail %= size;
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& data) {
    Expand();
    elem[tail++] = std::move(data);
    tail %= size;
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM CONTAINER) --------------

template <typename Data>
inline bool QueueVec<Data>::Empty() const noexcept {
    return (head == tail);
}

template <typename Data>
inline ulong QueueVec<Data>::Size() const noexcept {
    return (((size+tail) - head) % size);
}

// -------------- SPECIFIC MEMBER FUNCTIONS (FROM CLEARABLE CONTAINER) --------------

template <typename Data>
void QueueVec<Data>::Clear() {
    head = tail = 0;
    Vector<Data>::Resize(4);
}

// -------------- AUXILIARY FUNCTIONS --------------

template <typename Data>
void QueueVec<Data>::Expand() {
    ulong num = Size();
    if (num + 1 == size) {
        Resize(size * 2, num);
    }
}

template <typename Data>
void QueueVec<Data>::Reduce() {
    ulong num = Size();
    if (num+1 == size/4) {
        Resize(size/2, num);
    }
}

template <typename Data>
void QueueVec<Data>::Resize(ulong newSize, ulong num) {
    Data *tmpElements = new Data[newSize];
    ulong max = (num == newSize) ? num : newSize; //sbagliato, dovrebbe essere >=

    for (ulong idx1 = head, idx2 = 0; idx2 < max; ++idx1 %= size, ++idx2) {
        std::swap(elem[idx1], tmpElements[idx2]);
    }

    std::swap(elem, tmpElements);
    delete[] tmpElements;
    head = 0;
    tail = num;
    size = newSize;
}


/* ************************************************************************** */

}
