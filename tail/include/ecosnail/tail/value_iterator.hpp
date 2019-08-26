#pragma once

#include <ecosnail/tail/traits.hpp>

#include <iterator>

namespace ecosnail::tail {

template <class It>
class ValueIterator {
    static_assert(IsIterator<It>(),
        "ecosnail::tail::ValueIterator: underlying type is not an iterator");
    static_assert(
        IsFromTemplate<
            typename std::iterator_traits<It>::value_type,
            std::pair>(),
        "ecosnail::tail::ValueIterator:"
        " underlying iterator does not iterate pairs");

public:
    ValueIterator()
    { }

    explicit ValueIterator(It iterator)
        : _iterator(iterator)
    { }

    ValueIterator& operator++()
    {
        ++_iterator;
        return *this;
    }

    ValueIterator operator++(int)
    {
        auto current = *this;
        operator++();
        return current;
    }

    auto& operator*() const
    {
        return _iterator->second;
    }

    friend bool operator==(const ValueIterator& lhs, const ValueIterator& rhs)
    {
        return lhs._iterator == rhs._iterator;
    }

    friend bool operator!=(const ValueIterator& lhs, const ValueIterator& rhs)
    {
        return lhs._iterator != rhs._iterator;
    }

private:
    It _iterator;
};

} // namespace ecosnail::tail

namespace std {

template <class It>
struct iterator_traits<ecosnail::tail::ValueIterator<It>> {
    using difference_type = typename iterator_traits<It>::difference_type;
    using value_type = typename iterator_traits<It>::value_type::second_type;
    using pointer = std::conditional_t<
        ecosnail::tail::IsConstIterator<It>::value,
        const value_type*,
        value_type*>;
    using reference = std::conditional_t<
        ecosnail::tail::IsConstIterator<It>::value,
        const value_type&,
        value_type&>;
    using iterator_category = forward_iterator_tag;
};

} // namespace std
