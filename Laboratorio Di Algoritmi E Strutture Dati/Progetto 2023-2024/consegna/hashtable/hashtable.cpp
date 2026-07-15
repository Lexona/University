
namespace lasd {

/* ************************************************************************** */

// -------------- HASHABLE --------------

template<>
class Hashable<int> {
    public:
        ulong operator()(const int& data) const noexcept {
            return data*data;
        }
};

template<>
class Hashable<std::string> {
    public:
        ulong operator()(const std::string& data) const noexcept {
            ulong accumulator = 0;
            for (ulong i = 0; i < data.length(); i++) {
                accumulator += data[i]*i;
            }
            return accumulator;
        }
};

template <>
class Hashable<double> {
    public:
        ulong operator()(const double& data) const noexcept {
            ulong intPart = floor(data);
            ulong fracPart = pow(2, 24) * (data-intPart);
            return (intPart*fracPart);
        }
};

// -------------- HASH TABLE --------------

// -------------- CONSTRUCTORS --------------

template <typename Data>
HashTable<Data>::HashTable(const HashTable<Data>& hash) {
    tableSize = hash.tableSize;
    size = hash.size;
    a = hash.a;
    b = hash.b;
}

template <typename Data>
HashTable<Data>::HashTable(HashTable<Data>&& hash) noexcept {
    std::swap(tableSize, hash.tableSize);
    std::swap(size, hash.size);
    std::swap(a, hash.a);
    std::swap(b, hash.b);
}

// -------------- ASSIGNEMENTS --------------

template <typename Data>
HashTable<Data>& HashTable<Data>::operator=(const HashTable<Data>& hash) {
    tableSize = hash.tableSize;
    size = hash.size;
    a = hash.a;
    b = hash.b;
    return *this;
}

template <typename Data>
HashTable<Data>& HashTable<Data>::operator=(HashTable<Data>&& hash) noexcept {
    std::swap(tableSize, hash.tableSize);
    std::swap(size, hash.size);
    std::swap(a, hash.a);
    std::swap(b, hash.b);
    return *this;
}

// -------------- AUXILIARY MEMBER FUNCTION --------------

template <typename Data>
ulong HashTable<Data>::HashKey(ulong key) const noexcept {
    return (a*key + b) % tableSize;
}

/* ************************************************************************** */

}
