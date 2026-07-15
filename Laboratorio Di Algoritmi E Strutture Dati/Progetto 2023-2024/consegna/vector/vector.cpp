
namespace lasd {

    typedef unsigned long int ulong;

/* ************************************************************************** */

// ----------- VECTOR  -----------

// ----------- CONSTRUCTORS -----------

template <typename Data>
Vector<Data>::Vector(const ulong newSize) {
    size = newSize;
    elem = new Data[size]{};
}

template <typename Data>
Vector<Data>::Vector(const TraversableContainer<Data>& trav) : Vector(trav.Size()) {
    ulong i = 0;

    trav.Traverse(
        [this, &i] (const Data& data) {
            elem[i++] = data;
        }
    );
}

template <typename Data>
Vector<Data>::Vector(MappableContainer<Data>&& map) : Vector(map.Size()) {
    ulong i = 0;

    map.Map(
        [this, &i] (Data& data) {
            elem[i++] = std::move(data);
        }
    );
}

// ----------- COPY CONSTRUCTOR -----------

template <typename Data>
Vector<Data>::Vector(const Vector<Data>& vec) {
    size = vec.size;
    elem = new Data[size];
    std::copy(vec.elem, vec.elem + size, elem);
}

// ----------- MOVE CONSTRUCTOR -----------

template <typename Data>
Vector<Data>::Vector(Vector<Data>&& vec) noexcept {
    std::swap(size, vec.size);
    std::swap(elem, vec.elem);
}

// ----------- COPY ASSIGNEMENT -----------

template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vec) {
    Vector<Data> *tmpvec = new Vector<Data>(vec);
    std::swap(*tmpvec, *this);
    delete tmpvec;
    return *this;
}

// ----------- MOVE ASSIGNEMENT -----------

template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vec) noexcept {
    std::swap(size, vec.size);
    std::swap(elem, vec.elem);
    return *this; 
}

// ----------- COMPARISON OPERATORS -----------

template <typename Data>
bool Vector<Data>::operator == (const Vector<Data>& vec) const noexcept {
    if (size == vec.size) {
        for (ulong i = 0; i < size; i++) {
            if (elem[i] != vec.elem[i]) {
                return false;
            }
        }
        return true;
    }
    return false; 
}

template <typename Data>
inline bool Vector<Data>::operator != (const Vector& vec) const noexcept {
    return !(*this == vec);
}

// ----------- CLEAR -----------

template <typename Data>
void Vector<Data>::Clear() {
    delete[] elem;
    elem = nullptr;
    size = 0;
} 

// ----------- RESIZE -----------

template <typename Data>
void Vector<Data>::Resize(const ulong newSize) {
    if (newSize == 0) {
        Clear();
    } else if (size != newSize) {
        Data *tmpElem = new Data[newSize] {};
        ulong minSize = (size < newSize) ? size : newSize;

        for (ulong i = 0; i < minSize; i++) {
            std::swap(elem[i], tmpElem[i]);
        }

        std::swap(elem, tmpElem);
        size = newSize;
        delete[] tmpElem;
    }
}

// ----------- SPECIFIC MEMBER FUNCITONS -----------

template <typename Data>
const Data& Vector<Data>::operator[](const ulong index) const {
    if (index < size) {
        return elem[index];
    } else {
        throw std::out_of_range(("Indice " + std::to_string(index) + " al di fuori dei limiti (dimensione: " + std::to_string(size) + ")"));
    }
}

template <typename Data>
Data& Vector<Data>::operator[](const ulong index) {
    if (index < size) {
        return elem[index];
    } else {
        throw std::out_of_range("Indice " + std::to_string(index) + " al di fuori dei limiti (dimensione: " + std::to_string(size) + ")");
    }
}

template <typename Data>
const Data& Vector<Data>::Front() const {
    if (size != 0) {
        return elem[0];
    } else {
        throw std::length_error("Stai provando ad accedere a un vettore vuoto!");
    }
}

template <typename Data>
Data& Vector<Data>::Front() {
    if (size != 0) {
        return elem[0];
    } else {
        throw std::length_error("Stai provando ad accedere a un vettore vuoto!");
    }
}

template <typename Data>
const Data& Vector<Data>::Back() const {
    if (size != 0) {
        return elem[size - 1];
    } else {
        throw std::length_error("Stai provando ad accedere a un vettore vuoto!");
    }
}

template <typename Data>
Data& Vector<Data>::Back() {
    if (size != 0) {
        return elem[size - 1];
    } else {
        throw std::length_error("Stai provando ad accedere a un vettore vuoto!");
    }
}

// ----------- SORTABLE VECTOR  -----------

// ----------- COSTRUCTORS  -----------

template <typename Data>
SortableVector<Data>::SortableVector(const ulong newSize) noexcept {
    size = newSize;
    elem = new Data[size]{};
}

template <typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data>& trav) noexcept : SortableVector(trav.Size()) {
    ulong i = 0;

    trav.Traverse(
        [this, &i] (const Data& data) {
            elem[i++] = data;
        }
    );
}

template <typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data>&& map) noexcept : SortableVector(map.Size()) {
    ulong i = 0;

    map.Map(
        [this, &i] (Data& data) {
            elem[i++] = std::move(data);
        }
    );
}

// ----------- COPY CONSTRUCTOR -----------

template <typename Data>
SortableVector<Data>::SortableVector(const SortableVector& sortVec) {
    size = sortVec.size;
    elem = new Data[size];
    std::copy(sortVec.elem, sortVec.elem + size, elem);
}

// ----------- MOVE CONSTRUCTOR -----------

template <typename Data>
SortableVector<Data>::SortableVector(SortableVector<Data>&& sortVec) noexcept {
    std::swap(size, sortVec.size);
    std::swap(elem, sortVec.elem);
}

// ----------- COPY ASSIGNEMENT -----------

template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data>& sortVec) {
    SortableVector<Data> *tmpvec = new SortableVector<Data>(sortVec); //viene creato un nuovo oggetto Vector<Data> utilizzando il costruttore di copia per copiare tutti gli elementi del vettore vec. L'oggetto temporaneo tmpvec viene quindi inizializzato con questo nuovo vettore.
    std::swap(*tmpvec, *this);
    delete tmpvec;
    return *this;
}

// ----------- MOVE ASSIGNEMENT -----------

template <typename Data>
SortableVector<Data>& SortableVector<Data>::operator=(SortableVector<Data>&& sortVec) noexcept {
    std::swap(size, sortVec.size);
    std::swap(elem, sortVec.elem);
    return *this;
}

/* ************************************************************************** */

}
