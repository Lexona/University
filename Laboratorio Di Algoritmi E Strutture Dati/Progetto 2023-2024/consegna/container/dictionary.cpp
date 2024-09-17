
namespace lasd {

/* ************************************************************************** */

// --------- INSERT ALL ---------

template <typename Data>
bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& trav) {
    bool result = true;

    trav.Traverse(
        [this, &result](const Data& data) { //con this catturiamo il puntatore implicito all'oggetto corrente (cioè l'istanza di DictionaryContainer<Data>)
            result &= Insert(data); //AND bit a bit 
        }
    );

    return result;
}

template <typename Data>
bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& map) {
    bool result = true;

    map.Map(
        [this, &result] (Data& data) {
            result &= Insert(std::move(data));
        } 
    );

    return result;
}

// --------- INSERT SOME ---------

template <typename Data>
bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& trav) {
    bool result = false;

    trav.Traverse (
        [this, &result] (const Data& data){
            result |= Insert(data);
        }
    );

    return result;
}

template <typename Data>
bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& map) {
    bool result = false;

    map.Map (
        [this, &result] (Data& data) {
            result |= Insert(std::move(data));
        }
    );

    return result;
}

// --------- REMOVE ALL ---------

template <typename Data>
bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data>& trav) {
    bool result = true;

    trav.Traverse (
        [this, &result] (const Data& data) {
            result &= Remove(data);
        }
    );

    return result;
}

// --------- REMOVE SOME ---------

template <typename Data>
bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& trav) {
    bool result = false;

    trav.Traverse(
        [this, &result] (const Data& data) {
            result |= Remove(data);
        }
    );

    return result;
}

/* ************************************************************************** */

}
