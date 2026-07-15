
namespace lasd {

/* ************************************************************************** */

//----------------- CONSTRUCTORS -----------------

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newSize) {
    tableSize = std::pow(2, std::ceil(log2((newSize<16) ? 16 : newSize)));
    table = new Data[tableSize]{};
    tableFlag = new Flag[tableSize]{};
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& trav) : HashTableOpnAdr(trav.Size()*2) {
    InsertAll(trav);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newSize, const TraversableContainer<Data>& trav) : HashTableOpnAdr(newSize) {
    InsertAll(trav);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data>&& map) noexcept : HashTableOpnAdr(map.Size()*2) {
    InsertAll(std::move(map));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong newSize, MappableContainer<Data>&& map) noexcept : HashTableOpnAdr(newSize) {
    InsertAll(std::move(map));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& hash) : HashTable<Data>(hash) {
    table = new Data[tableSize]{};
    tableFlag = new Flag[tableSize]{};

    for (ulong i = 0; i < tableSize; i++) {
        table[i] = hash.table[i];
        tableFlag[i] = hash.tableFlag[i];
    }
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& hash) noexcept : HashTable<Data>(std::move(hash)){
    std::swap(table, hash.table);
    std::swap(tableFlag, hash.tableFlag);
}

//----------------- ASSIGNEMENTS -----------------

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& hash) {
    HashTable<Data>::operator=(hash);

    delete[] table;
    delete[] tableFlag;

    table = new Data[tableSize]{};
    tableFlag = new Flag[tableSize]{};

    for (ulong i = 0; i < tableSize; i++) {
        table[i] = hash.table[i];
        tableFlag[i] = hash.tableFlag[i];
    }

    return *this;
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data>&& hash) noexcept {
    HashTable<Data>::operator=(std::move(hash));

    std::swap(table, hash.table);
    std::swap(tableFlag, hash.tableFlag);

    return *this;
}

//----------------- COMPARISON OPERATOR -----------------

template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& hash) const noexcept {
    if (size != hash.Size()) {
        return false;
    }

    for (ulong i = 0; i < tableSize; i++) {
        if (tableFlag[i] == valid) {
            if (!hash.Exists(table[i])) {
                return false;
            }
        }
    }
    return true;
}

//----------------- SPECIFIC MEMBER FUNCTIONS (FROM DICTIONARY CONTAINER) -----------------

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& data) {
    ulong prob_index = 0;

    if (size*2 > tableSize) {
        Resize(tableSize*2);
    }

    ulong index = FindEmpty(data, prob_index);
    if (tableFlag[index] != valid) {
        table[index] = data;
        tableFlag[index] = valid;
        ++size;
        return !Remove(++prob_index, data);
    }

    prob_index = 0;
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& data) {
    ulong prob_index = 0;

    if (size*2 > tableSize) {
        Resize(tableSize*2);
    }

    ulong index = FindEmpty(data, prob_index);
    if (tableFlag[index] != valid) {
        table[index] = std::move(data);
        tableFlag[index] = valid;
        ++size;
        return !Remove(++prob_index, data);
    }

    prob_index = 0;
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data) {
    ulong prob_index = 0;
    return Remove(prob_index, data);
}

//----------------- SPECIFIC MEMBER FUNCTIONS (FROM TESTABLE CONTAINER) -----------------

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& data) const noexcept {
    ulong prob_index = 0;
    ulong index = HashKey(Hashable<Data>()(data));
    return Find(index, prob_index, data);
}

//----------------- SPECIFIC MEMBER FUNCTIONS (FROM RESIZABLE CONTAINER) -----------------

template <typename Data>
void HashTableOpnAdr<Data>::Resize(const ulong newSize) {
    ulong tmpSize = (newSize <= 16) ? 16 : std::pow(2, std::ceil(log2(newSize)));

    Data *tmpTable = new Data[tmpSize]{};
    Flag *tmpFlag = new Flag[tmpSize]{};

    std::swap(tmpSize, tableSize);
    std::swap(tmpTable, table);
    std::swap(tmpFlag, tableFlag);

    size = 0;
    for (ulong i = 0; i < tmpSize; i++) {
        if (tmpFlag[i] == valid) {
            Insert(tmpTable[i]);
        }
    }

    delete[] tmpTable;
    delete[] tmpFlag;
}

//----------------- SPECIFIC MEMBER FUNCTIONS (FROM CLEARABLE CONTAINER) -----------------

template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    for (ulong i = 0; i < tableSize; i++) {
        tableFlag[i] = dirty;
    }

    size = 0;
}

//----------------- AUXILIARY MEMBER FUNCTIONS -----------------

template <typename Data>
ulong HashTableOpnAdr<Data>::HashKey(const Data& key, ulong& prob_index) const noexcept {
    ulong index = HashKey(Hashable<Data>()(key));
    return (index + tableSize + ((prob_index * prob_index) + prob_index)/2) % tableSize;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Find(ulong& index, ulong& prob_index, const Data& data) const noexcept {
    ulong tmpIndex = HashKey(data, prob_index);
    ulong jumps = 0;

    do {
        if (jumps == tableSize - 1) {
            return false;
        }

        if ((table[tmpIndex] == data) && (tableFlag[tmpIndex] == valid)) {
            index = tmpIndex;
            return true;
        }

        tmpIndex = HashKey(data, ++prob_index);
        jumps++;
    } while(!(tableFlag[tmpIndex] == empt));
    return false;
}

template <typename Data>
ulong HashTableOpnAdr<Data>::FindEmpty(const Data& data, ulong& prob_index) const noexcept {
    ulong tmpIndex = HashKey(data, prob_index);

    while ((tableFlag[tmpIndex] == valid) && (table[tmpIndex] != data)) {
        tmpIndex = HashKey(data, ++prob_index);
    }

    return tmpIndex;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(ulong& prob_index, const Data& key) noexcept {
    ulong tmpIndex;

    if (Find(tmpIndex, prob_index, key)) {
        tableFlag[tmpIndex] = dirty;
        size--;
        prob_index = 0;

        if ((size < tableSize/5) && (tableSize > 16)) {
            Resize(tableSize/2);
        }
        return true;
    }

    prob_index = 0;
    return false;
}

/* ************************************************************************** */

}
