#include <ecosnail/tail.hpp>

#include <map>
#include <vector>
#include <type_traits>

namespace tail = ecosnail::tail;

#define DEMAND(CONDITION) \
static_assert(CONDITION, #CONDITION)

#define FORBID(CONDITION) \
static_assert(!(CONDITION), "!(" #CONDITION ")")

#define SAME_TYPE(U, V) \
static_assert(std::is_same<U, V>(), "types differ: " #U " <-> " #V)

int main() {}

void isIteratorTest()
{
    using Struct = struct {};

    // Simple types and references are not iterators

    FORBID(tail::IsIterator<int>());
    FORBID(tail::IsIterator<const int>());
    FORBID(tail::IsIterator<int&>());
    FORBID(tail::IsIterator<const int&>());

    FORBID(tail::IsIterator<Struct>());
    FORBID(tail::IsIterator<const Struct>());
    FORBID(tail::IsIterator<Struct&>());
    FORBID(tail::IsIterator<const Struct&>());

    // Pointers have iterator_traits, and are considered to be iterators

    DEMAND(tail::IsIterator<int*>());
    DEMAND(tail::IsIterator<const int*>());

    DEMAND(tail::IsIterator<Struct*>());
    DEMAND(tail::IsIterator<const Struct*>());

    // Standard container iterators are recognized
    using Vector = std::vector<int>;
    using Map = std::map<int, int>;

    DEMAND(tail::IsIterator<Map::iterator>());
    DEMAND(tail::IsIterator<Map::const_iterator>());
    DEMAND(tail::IsIterator<Vector::iterator>());
    DEMAND(tail::IsIterator<Vector::const_iterator>());
}

void isConstIteratorTest()
{
    using Struct = struct {};

    // If a type is not an iterator, it is not a const iterator

    FORBID(tail::IsConstIterator<int>());
    FORBID(tail::IsConstIterator<const int>());
    FORBID(tail::IsConstIterator<int&>());
    FORBID(tail::IsConstIterator<const int&>());

    FORBID(tail::IsConstIterator<Struct>());
    FORBID(tail::IsConstIterator<const Struct>());
    FORBID(tail::IsConstIterator<Struct&>());
    FORBID(tail::IsConstIterator<const Struct&>());

    // Constant pointers are considered const iterators

    FORBID(tail::IsConstIterator<int*>());
    DEMAND(tail::IsConstIterator<const int*>());
    FORBID(tail::IsConstIterator<Struct*>());
    DEMAND(tail::IsConstIterator<const Struct*>());

    // Iterators from standard containers
    using Vector = std::vector<int>;
    using Map = std::map<int, int>;

    FORBID(tail::IsConstIterator<Vector::iterator>());
    DEMAND(tail::IsConstIterator<Vector::const_iterator>());
    FORBID(tail::IsConstIterator<Map::iterator>());
    DEMAND(tail::IsConstIterator<Map::const_iterator>());
}
