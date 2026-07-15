
namespace lasd {

/* ************************************************************************** */

//----------------- CONSTRUCTORS -----------------

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong newSize) {
    tableSize = std::pow(2, std::ceil(log2((newSize <= 16) ? 16 : newSize)));
    table = new BST<Data>[tableSize]{};
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& trav) : HashTableClsAdr<Data>(trav.Size()) {
    InsertAll(trav);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong newSize, const TraversableContainer<Data>& trav) : HashTableClsAdr<Data>(newSize) {
    InsertAll(trav);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& map) noexcept : HashTableClsAdr<Data>(map.Size()) {
    InsertAll(std::move(map));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong newSize, MappableContainer<Data>&& map) noexcept : HashTableClsAdr<Data>(newSize) {
    InsertAll(std::move(map));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& hash) : HashTable<Data>(hash) {
    table = new BST<Data>[tableSize]{};
    std::copy(hash.table, hash.table + tableSize, table);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& hash) noexcept : HashTable<Data>(std::move(hash)) {
    std::swap(table, hash.table);
}

//----------------- ASSIGNEMENTS -----------------

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& hash) {
    HashTable<Data>::operator=(hash);
    delete[] table;
    table = new BST<Data>[tableSize]{};

    for (ulong i = 0; i < tableSize; i++) {
        table[i] = hash.table[i];
    }

    return *this;
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& hash) noexcept {
    HashTable<Data>::operator=(std::move(hash));
    std::swap(table, hash.table);
    return *this;
}

//----------------- COMPARISON OPERATOR -----------------

template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& hash) const noexcept {
    bool result = true;

    if (hash.size != size) {
        return false;
    }

    for (ulong i = 0; i < tableSize; i++) {
        table[i].Traverse(
            [&hash, &result](const Data& data) {
                if (!hash.Exists(data)) {
                    result = false;
                    return;
                }
            }
        );

        if (!result) {
            return false;
        }
    }

    return true;
}

//----------------- SPECIFI1C MEMBER FUNCTIONS (FROM DICTIONARY CONTAINER) -----------------

template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data) {
    bool result = false;
    ulong index = HashKey(Hashable<Data>()(data));
    result = table[index].Insert(data);

    if (result) {
        size++;
    }

    return result;
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data) {
    bool result = false;
    ulong index = HashKey(Hashable<Data>()(data));
    result = table[index].Insert(std::move(data));

    if (result) {
        size++;
    }

    return result;
}

template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data) {
    bool result = false;
    ulong index = HashKey(Hashable<Data>()(data));
    result = table[index].BST<Data>::Remove(data);

    if (result) {
        size--;
    }

    return result;
}

//----------------- SPECIFI1C MEMBER FUNCTIONS (FROM TESTABLE CONTAINER) -----------------

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept {
    ulong index = HashKey(Hashable<Data>()(data));

    if (table[index].Exists(data)) {
        return true;
    }

    return false;
}

//----------------- SPECIFI1C MEMBER FUNCTIONS (FROM RESIZABLE CONTAINER) -----------------

template <typename Data>
void HashTableClsAdr<Data>::Resize(const ulong newSize) {
    ulong newTableSize = (newSize <= 16) ? 16 : std::pow(2, std::ceil(log2(newSize)));
    size = 0;
    BST<Data> *newTable = new BST<Data>[newTableSize]{};

    std::swap(newTable, table);
    std::swap(newTableSize, tableSize);

    for (ulong i = 0; i < newTableSize; i++) {
        InsertAll(newTable[i]);
    }

    delete[] newTable;
}

//----------------- SPECIFI1C MEMBER FUNCTIONS (FROM CLEARABLE CONTAINER) -----------------

template <typename Data>
void HashTableClsAdr<Data>::Clear() {
    delete[] table;
    table = new BST<Data>[tableSize]{};
    size = 0;
}


/* ************************************************************************** */

}
