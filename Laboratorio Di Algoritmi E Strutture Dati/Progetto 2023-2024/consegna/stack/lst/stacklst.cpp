
namespace lasd {

/* ************************************************************************** */

// ------------- COPY ASSIGNMENT -------------

template <typename Data>
inline StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& sList) {
    List<Data>::operator=(sList);
    return *this;
}

// ------------- MOVE ASSIGNMENT -------------

template <typename Data>
inline StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& sList) noexcept {
    List<Data>::operator=(std::move(sList));
    return *this;
}

// ------------- COMPARISON OPERATORS -------------

template <typename Data>
inline bool StackLst<Data>::operator==(const StackLst<Data>& sList) const noexcept {
    return List<Data>::operator==(sList);
}

template <typename Data>
inline bool StackLst<Data>::operator!=(const StackLst<Data>& sList) const noexcept {
    return List<Data>::operator!=(sList);
}

// ------------- SPECIFIC MEMBER FUNCTIONS (INHERITED FROM STACK) -------------

template <typename Data>
inline const Data& StackLst<Data>::Top() const {
    return List<Data>::Front();
}

template <typename Data>
inline Data& StackLst<Data>::Top() {
    return List<Data>::Front();
}

template <typename Data>
inline void StackLst<Data>::Pop() {
    return List<Data>::RemoveFromFront();
}

template <typename Data>
inline Data StackLst<Data>::TopNPop() {
    return List<Data>::FrontNRemove();
}

template <typename Data>
inline void StackLst<Data>::Push(const Data& data) {
    return List<Data>::InsertAtFront(data);
}

template <typename Data>
inline void StackLst<Data>::Push(Data&& data) noexcept {
    return List<Data>::InsertAtFront(data);
}

/* ************************************************************************** */

}
