#pragma once

#include <ecosnail/tail/traits.hpp>

#include <iterator>

namespace ecosnail::tail {

template <class It>
class KeyIterator {
    static_assert(IsIterator<It>(),
        "ecosnail::tail::KeyIterator: underlying type is not an iterator");
    static_assert(
        IsFromTemplate<
            typename std::iterator_traits<It>::value_type,
            std::pair>(),
        "ecosnail::tail::KeyIterator:"
        " underlying iterator does not iterate pairs");

public:
    explicit KeyIterator(It iterator)
        : _iterator(iterator)
    { }

    KeyIterator& operator++()
    {
        ++_iterator;
        return *this;
    }

    KeyIterator operator++(int)
    {
        auto current = *this;
        operator++();
        return current;
    }

    const auto& operator*() const
    {
        return _iterator->first;
    }

    friend bool operator==(const KeyIterator& lhs, const KeyIterator& rhs)
    {
        return lhs._iterator == rhs._iterator;
    }

    friend bool operator!=(const KeyIterator& lhs, const KeyIterator& rhs)
    {
        return lhs._iterator != rhs._iterator;
    }

private:
    It _iterator;
};

} // namespace ecosnail::tail

namespace std {

template <class It>
struct iterator_traits<ecosnail::tail::KeyIterator<It>> {
    using difference_type = typename iterator_traits<It>::difference_type;
    using value_type = typename iterator_traits<It>::value_type::first_type;
    using pointer = value_type*;
    using reference = value_type&;
    using iterator_category = forward_iterator_tag;
};

} // namespace std
