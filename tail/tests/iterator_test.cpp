#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <ecosnail/tail.hpp>

#include <iterator>
#include <type_traits>

namespace tail = ecosnail::tail;

#define SAME_TYPE(U, V) \
static_assert(std::is_same<U, V>(), "types differ: " #U " <-> " #V)

TEST_CASE("key iterator")
{
    using Map = std::map<int, float>;
    Map map {
        {1, 2},
        {3, 4},
    };

    auto it = tail::KeyIterator{map.begin()};

    using MapIteratorTraits = std::iterator_traits<Map::iterator>;
    using KeyIteratorTraits = std::iterator_traits<decltype(it)>;
    SAME_TYPE(
        KeyIteratorTraits::difference_type, MapIteratorTraits::difference_type);
    SAME_TYPE(KeyIteratorTraits::value_type, const int);
    SAME_TYPE(KeyIteratorTraits::pointer, const int*);
    SAME_TYPE(KeyIteratorTraits::reference, const int&);
    SAME_TYPE(KeyIteratorTraits::iterator_category, std::forward_iterator_tag);

    const auto end = tail::KeyIterator{map.end()};

    REQUIRE(*it++ == 1);
    REQUIRE(*it++ == 3);
    REQUIRE(it == end);
}

TEST_CASE("mutable value iterator")
{
    using Map = std::map<int, float>;
    Map map {
        {1, 2},
        {3, 4},
    };

    auto it = tail::ValueIterator{map.begin()};

    using MapIteratorTraits = std::iterator_traits<Map::iterator>;
    using ValueIteratorTraits = std::iterator_traits<decltype(it)>;

    SAME_TYPE(
        ValueIteratorTraits::difference_type,
        MapIteratorTraits::difference_type);
    SAME_TYPE(ValueIteratorTraits::value_type, float);
    SAME_TYPE(ValueIteratorTraits::pointer, float*);
    SAME_TYPE(ValueIteratorTraits::reference, float&);
    SAME_TYPE(
        ValueIteratorTraits::iterator_category,
        std::forward_iterator_tag);

    const auto end = tail::ValueIterator{map.end()};
    REQUIRE(*it == 2);
    *it++ = 20;
    REQUIRE(*it == 4);
    *it++ = 40;
    REQUIRE(it == end);
}

TEST_CASE("const value iterator")
{
    using Map = std::map<int, float>;
    Map map {
        {1, 2},
        {3, 4},
    };

    auto cit = tail::ValueIterator{map.cbegin()};

    using MapConstIteratorTraits = std::iterator_traits<Map::const_iterator>;
    using ValueConstIteratorTraits = std::iterator_traits<decltype(cit)>;

    static_assert(std::is_same<
        MapConstIteratorTraits::reference,
        const std::pair<const int, float>&>());

    SAME_TYPE(
        ValueConstIteratorTraits::difference_type,
        MapConstIteratorTraits::difference_type);
    SAME_TYPE(ValueConstIteratorTraits::value_type, float);
    SAME_TYPE(ValueConstIteratorTraits::pointer, const float*);
    SAME_TYPE(ValueConstIteratorTraits::reference, const float&);
    SAME_TYPE(
        ValueConstIteratorTraits::iterator_category,
        std::forward_iterator_tag);

    const auto cend = tail::ValueIterator{map.cend()};
    REQUIRE(*cit++ == 2);
    REQUIRE(*cit++ == 4);
    REQUIRE(cit == cend);
}
