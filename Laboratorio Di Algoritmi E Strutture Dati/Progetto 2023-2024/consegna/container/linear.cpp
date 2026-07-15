
#include <stdexcept>
namespace lasd {

/* ************************************************************************** */

// ------------- LINEAR CONTAINER -------------

// ------------- COMPARISON OPERATORS -------------
template <typename Data>
inline bool LinearContainer<Data>::operator== (const LinearContainer& val) const {
    if (size != val.size)
        return false;
    
    for (ulong i = 0; i < size; i++) {
        if (operator[](i) != val[i])
            return false;
    }

    return true;
}

template <typename Data>
inline bool LinearContainer<Data>::operator != (const LinearContainer& val) const {
    return !(operator==(val));
}

// ------------- SPECIFIC MEMEBR FUNCTION ------------- 

template <typename Data>
inline const Data& LinearContainer<Data>::Front() const {
    if (!Container::Empty()) {
        return operator[](0);
    }

    else throw std::length_error ("Error: Empty-Container!");
}

template <typename Data>
inline Data& LinearContainer<Data>::Front() {
    if (!Container::Empty()) {
        return operator[](0);
    }

    else throw std::length_error ("Error: Empty-Container!");
}

template <typename Data>
inline const Data& LinearContainer<Data>::Back() const {
    if (!Container::Empty()) {
        return operator[](size - 1);
    }

    else throw std::length_error ("Error: Empty-Container!");
}

template <typename Data>
inline Data& LinearContainer<Data>::Back() {
    if (!Container::Empty()) {
        return operator[](size - 1);
    }

    else throw std::length_error ("Error: Empty-Container!");
}

// ------------- TRAVERSE ------------- 

template <typename Data>
void LinearContainer<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun);
}

// ------------- PRE-ORDER TRAVERSE ------------- 

template <typename Data>
void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const {
    for (ulong i = 0; i < size; i++) {
        fun(operator[](i));
    }
}

// ------------- POST-ORDER TRAVERSE ------------- 

template <typename Data>
void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const {
    ulong i = size;

    while (i > 0) {
        fun(operator[](--i));
    }
}

// ------------- MAP ------------- 

template <typename Data>
void LinearContainer<Data>::Map(MapFun fun) {
    PreOrderMap(fun);
}

// ------------- PRE-ORDER MAP ------------- 

template <typename Data>
inline void LinearContainer<Data>::PreOrderMap(MapFun fun) {
    for (ulong i = 0; i < size; i++) {
        fun(operator[](i));
    }
}

// ------------- POST-ORDER MAP ------------- 

template <typename Data>
inline void LinearContainer<Data>::PostOrderMap(MapFun fun) {
    for (ulong i = size - 1; i > 0; i--) {
        fun(operator[](i));
    }
}

// ------------- SORTABLE CONTAINER -------------

// ------------- COMPARISON OPERATORS -------------

template <typename Data>
inline bool SortableLinearContainer<Data>::operator == (const SortableLinearContainer& val) const {
    if (size != val.size)
        return false;
    
    for (ulong i = 0; i < size; i++) {
        if (operator[](i) != val[i])
            return false;
    }

    return true;
}

template <typename Data>
inline bool SortableLinearContainer<Data>::operator != (const SortableLinearContainer& val) const {
    return !(operator==(val));
}

// ------------- SPECIFIC MEMEBR FUNCTION ------------- 

template <typename Data>
void SortableLinearContainer<Data>::Sort() noexcept {
    if (!Container::Empty())
        QuickSort(0, size-1);
}

// ------------- AUXILIARY MEMEBR FUNCTIONS ------------- 

template <typename Data>
void SortableLinearContainer<Data>::QuickSort(ulong p, ulong r) noexcept {
    if (p < r) {
        ulong q = Partition(p,r);
        QuickSort(p,q);
        QuickSort(q+1,r);
    }
}

template <typename Data>
ulong SortableLinearContainer<Data>::Partition(ulong p, ulong r) noexcept {
    Data x = operator[](p);
    ulong i = p-1;
    ulong j = r+1;

    do {
        do {
            j--;
        } while(x < operator[](j));

        do {
            i++;
        } while(x > operator[](i));

        if (i < j) {
            std::swap(operator[](i), operator[](j));
        }
    } while (i < j);

    return j;
}


/* ************************************************************************** */

}
