
namespace lasd {

/* ************************************************************************** */

// ------------ COPY ASSIGNMENT ------------

template <typename Data>
inline QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& qList) {
    List<Data>::operator=(qList);
    return *this;
}

// ------------ MOVE ASSIGNMENT ------------

template <typename Data>
inline QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& qList) noexcept {
    List<Data>::operator=(std::move(qList));
    return *this;
}



// ------------ COMPARISON OPERATORS ------------

template <typename Data>
inline bool QueueLst<Data>::operator==(const QueueLst<Data>& qList) const noexcept {
    return List<Data>::operator==(qList);
}

template <typename Data>
inline bool QueueLst<Data>::operator!=(const QueueLst<Data>& qList) const noexcept {
    return List<Data>::operator!=(qList);
}


// ------------ SPECIFIC MEMBER FUNCTIONS (FROM QUEUE) ------------

template <typename Data>
inline const Data& QueueLst<Data>::Head() const {
    return List<Data>::Front();
}

template <typename Data>
inline Data& QueueLst<Data>::Head() {
    return List<Data>::Front();
}

template <typename Data>
inline void QueueLst<Data>::Dequeue() {
    return List<Data>::RemoveFromFront();
}

template <typename Data>
inline Data QueueLst<Data>::HeadNDequeue() {
    return List<Data>::FrontNRemove();
}

template <typename Data>
inline void QueueLst<Data>::Enqueue(const Data& data) {
    return List<Data>::InsertAtBack(data);
}

template <typename Data>
inline void QueueLst<Data>::Enqueue(Data&& data) {
    return List<Data>::InsertAtBack(std::move(data));
}


/* ************************************************************************** */

}
