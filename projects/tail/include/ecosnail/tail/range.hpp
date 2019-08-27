#pragma once

#include <ecosnail/tail/traits.hpp>
#include <ecosnail/tail/key_iterator.hpp>
#include <ecosnail/tail/value_iterator.hpp>

#include <utility>

namespace ecosnail::tail {

template <class Iterator>
class Range {
    static_assert(IsIterator<Iterator>(),
        "ecosnail::tail::Range: underlying type is not an iterator");

public:
    Range(Iterator begin, Iterator end)
        : _begin(std::move(begin))
        , _end(std::move(end))
    { }

    auto begin() const
    {
        return _begin;
    }

    auto end() const
    {
        return _end;
    }

private:
    const Iterator _begin;
    const Iterator _end;
};

template <class Map>
auto keyRange(const Map& map)
{
    return Range{KeyIterator{map.begin()}, KeyIterator{map.end()}};
}

template <class Map>
auto valueRange(Map& map)
{
    return Range{ValueIterator{map.begin()}, ValueIterator{map.end()}};
}

} // namespace ecosnail::tail
