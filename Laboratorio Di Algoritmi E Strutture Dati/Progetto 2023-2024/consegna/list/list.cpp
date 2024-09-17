
namespace lasd {

/* ************************************************************************** */

// ---------- NODE ----------

// ---------- SPECIFIC CONSTRUCTOR ----------

template <typename Data>
List<Data>::Node::Node(Data&& data) noexcept {
    std::swap(element, data);
}

// ---------- MOVE CONSTRUCTOR ----------

template <typename Data>
List<Data>::Node::Node(Node&& node) noexcept {
    std::swap(element, node.element);
    std::swap(next, node.next);
}

// ---------- DISTRUCTOR ----------

template <typename Data>
List<Data>::Node::~Node() {
    delete next;
}

// ---------- COMPARISON OPERATORS ----------

template <typename Data>
bool List<Data>::Node::operator == (const Node& node) const noexcept {
    return (element == node.element) \
        && ((next == nullptr && node.next == nullptr) || ((next != nullptr && node.next != nullptr) && ((*next) == (*node.next))));
}

template <typename Data>
bool List<Data>::Node::operator != (const Node& node) const noexcept {
    return !(*this == node);
}

// ---------- CLONE ----------

template <typename Data>
typename List<Data>::Node* List<Data>::Node::Clone (Node* tail) {
    if (next == nullptr) {
        return tail;
    } else {
        Node *node = new Node(element);
        node->next = next->Clone(tail);
        return node;
    }
}

// ---------- LIST ----------

// ---------- SPECIFIC CONSTRUCTOR ----------

template <typename Data>
List<Data>::List(const TraversableContainer<Data>& trav) {
    trav.Traverse(
        [this] (const Data& data) {
            InsertAtBack(data);
        }
    );
}

template <typename Data>
List<Data>::List(MappableContainer<Data>&& map) {
    map.Map(
        [this] (Data& data) {
            InsertAtBack(std::move(data));
        }
    );
}

// ---------- COPY CONSTRUCTOR ----------

template <typename Data>
List<Data>::List(const List<Data>& list) {
    if (list.tail != nullptr) {
        tail = new Node(*list.tail);
        head = list.head->Clone(tail);
        size = list.size;
    }
}

// ---------- MOVE CONSTRUCTOR ----------

template <typename Data>
List<Data>::List(List<Data>&& list) noexcept {
    std::swap(head, list.head);
    std::swap(tail, list.tail);
    std::swap(size, list.size);
}

// ---------- DESTRUCTOR ----------

template <typename Data>
List<Data>::~List() {
    delete head;
}

// ---------- COPY ASSIGNMENT ----------

template <typename Data>
List<Data>& List<Data>::operator=(const List<Data>& list) {
    if (size <= list.size) {
        if (tail == nullptr) {
            List<Data> *tmpList = new List<Data>(list);
            std::swap(*tmpList, *this);
            delete tmpList;
        } else {
            Node *oldCur = list.head;
            for (Node *newCur = head; newCur != nullptr; newCur = newCur->next, oldCur = oldCur->next) {
                newCur->element = oldCur->element;
            }

            if (oldCur != nullptr) {
                Node *newTail = new Node(*list.tail);
                tail->next = oldCur->Clone(newTail);
                tail = newTail;
            }
        }
    } else {
        if (list.tail == nullptr) {
            delete head;
            head = tail = nullptr;
        } else {
            Node *newCur = head;
            for (Node *oldCur = list.head; oldCur != nullptr; oldCur = oldCur->next, tail = newCur, newCur = newCur->next) {
                newCur->element = oldCur->element;
            }
            delete newCur;
            tail->next = nullptr;
        }
    }
    size = list.size;
    return *this;
}

// ---------- MOVE ASSIGNMENT ----------

template <typename Data>
List<Data>& List<Data>::operator=(List<Data>&& list) noexcept {
    std::swap(head, list.head);
    std::swap(tail, list.tail);
    std::swap(size, list.size);
    return *this;
}

// ---------- COMPARISON OPERATORS ----------

template <typename Data>
bool List<Data>::operator==(const List<Data>& list) const noexcept {
    if (size != list.size) {
        return false;
    }

    Node *current = head;
    Node *listCurrent = list.head;

    while (current != nullptr) {
        if (current->element != listCurrent->element) {
            return false;
        }

        current = current->next;
        listCurrent = listCurrent->next;
    }

    return true;
}

template <typename Data>
inline bool List<Data>::operator!=(const List<Data>& list) const noexcept {
    return !(*this == list);
}

// ---------- SPECIFIC MEMBER FUNCTIONS ----------

template <typename Data>
void List<Data>::InsertAtFront(const Data& data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;

    if (tail == nullptr) {
        tail = head;
    }

    size++;
}

template <typename Data>
void List<Data>::InsertAtFront(Data&& data) {
    Node *newNode = new Node(std::move(data));
    newNode->next = head;
    head = newNode;

    if (tail == nullptr) {
        tail = head;
    }

    size++;
}

template <typename Data>
void List<Data>::RemoveFromFront() {
    if (head != nullptr) {
        Node *front = head;

        if (tail == head) {
            head = tail = nullptr;
        } else {
            head = head->next;
        }

        --size;
        front->next = nullptr;
        delete front;
    } else {
        throw std::length_error("Stai provando ad accedere a una lista vuota!");
    }
}

template <typename Data>
Data List<Data>::FrontNRemove() {
    if (head != nullptr) {
        Node *front = head;

        if (tail == head) {
            head = tail = nullptr;
        } else {
            head = head->next;
        }

        --size;
        front->next = nullptr;
        Data data(std::move(front->element));
        delete front;
        return data;
    } else {
        throw std::length_error("Stai provando ad accedere a una lista vuota!");
    }
}

template <typename Data>
void List<Data>::InsertAtBack(const Data& data) {
    Node *newNode = new Node(data);

    if (tail == nullptr) {
        head = newNode;
    } else {
        tail->next = newNode;
    }

    tail = newNode;
    ++size;
}

template <typename Data>
void List<Data>::InsertAtBack(Data&& data) {
    Node *newNode = new Node(std::move(data));

    if (tail == nullptr) {
        head = newNode;
    } else {
        tail->next = newNode;
    }

    tail = newNode;
    ++size;
}

// ---------- INHERITED FROM CLEARABLE CONTAINER ----------

template <typename Data>
void List<Data>::Clear() {
    delete head;
    head = tail = nullptr;
    size = 0;
}

// ---------- INHERITED FROM DICTIONARY CONTAINER ----------

template <typename Data>
bool List<Data>::Insert(const Data& data) {
    Node *current = head;

    while (current != nullptr) {
        if (current->element == data) {
            return false;
        }
        current = current->next;
    }

    InsertAtBack(data);
    return true;
}

template <typename Data>
bool List<Data>::Insert(Data&& data) {
    Node *current = head;

    while (current != nullptr) {
        if (current->element == data) {
            return false;
        }
        current = current->next;
    }

    InsertAtBack(std::move(data));
    return true;
}

template <typename Data>
bool List<Data>::Remove(const Data& data) {
    Node* last = nullptr;

        for(Node** cur = &head; *cur != nullptr; last = *cur, cur = &((*cur) -> next)) {
            if((*cur) -> element == data) {
                Node* node = *cur;
                *cur = node -> next;
                node -> next = nullptr;
                delete node;
                size--;

                if (tail == node) {
                    tail = last;
                }
                return true;
            }
        }

        return false;
}

// ---------- INHERITED FROM LINEAR CONTAINER ----------

template <typename Data>
const Data& List<Data>::operator[](const ulong index) const {
    if (index < size) {
        Node *current = head;

        for (ulong i = 0; i < index; i++, current = current->next) {}
        return current->element;
    } else {
        throw std::out_of_range(("Indice " + std::to_string(index) + " al di fuori dei limiti (dimensione: " + std::to_string(size) + ")"));
    }
}

template <typename Data>
Data& List<Data>::operator[](const ulong index) {
    if (index < size) {
        Node *current = head;

        for (ulong i = 0; i < index; i++, current = current->next) {}
        return current->element;
    } else {
        throw std::out_of_range(("Indice " + std::to_string(index) + " al di fuori dei limiti (dimensione: " + std::to_string(size) + ")"));
    }
}

template <typename Data>
const Data& List<Data>::Front() const {
    if (head != nullptr) {
        return head->element;
    } else {
        throw std::length_error("Stai provando ad accedere a una lista vuota!");
    }
}

template <typename Data>
Data& List<Data>::Front() {
    if (head != nullptr) {
        return head->element;
    } else {
        throw std::length_error("Stai provando ad accedere a una lista vuota!");
    }
}

template <typename Data>
const Data& List<Data>::Back() const {
    if (tail != nullptr) {
        return tail->element;
    } else {
        throw std::length_error("Stai provando ad accedere a una lista vuota!");
    }
}

template <typename Data>
Data& List<Data>::Back() {
    if (tail != nullptr) {
        return tail->element;
    } else {
        throw std::length_error("Stai provando ad accedere a una lista vuota!");
    }
}

// ---------- INHERITED FROM TRAVERSABLE CONTAINER ----------

template <typename Data>
inline void List<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun,head);
}

template <typename Data>
inline void List<Data>::PreOrderTraverse(TraverseFun fun) const {
    PreOrderTraverse(fun,head);
}

template <typename Data>
inline void List<Data>::PostOrderTraverse(TraverseFun fun) const {
    PostOrderTraverse(fun,head);
}

template <typename Data>
void List<Data>::PreOrderTraverse(TraverseFun fun, const Node* node) const {
    for (; node != nullptr; node = node->next) {
        fun(node->element);
    }
}

template <typename Data>
void List<Data>::PostOrderTraverse(TraverseFun fun, const Node* node) const {
    if (node != nullptr) {
        PostOrderTraverse(fun, node->next);
        fun(node->element);
    }
}

// ---------- INHERITED FROM MAPPABLE CONTAINER ----------

template <typename Data>
inline void List<Data>::Map(MapFun fun) {
    PreOrderMap(fun, head);
}

template <typename Data>
inline void List<Data>::PreOrderMap(MapFun fun) {
    PreOrderMap(fun, head);
}

template <typename Data>
inline void List<Data>::PostOrderMap(MapFun fun) {
    PostOrderMap(fun, head);
}

template <typename Data>
void List<Data>::PreOrderMap(MapFun fun, Node* node) {
    for (; node != nullptr; node = node->next) {
        fun(node->element);
    }
}

template <typename Data>
void List<Data>::PostOrderMap(MapFun fun, Node* node) {
    if (node != nullptr) {
        PostOrderMap(fun, node->next);
        fun(node->element);
    }
}

/* ************************************************************************** */

}
