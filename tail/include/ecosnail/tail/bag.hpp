#pragma once

#include <ecosnail/tail/ith.hpp>

#include <cstddef>

namespace ecosnail::tail {

template <class T, template <class> class... Ids>
struct Bag : Ids<T>... {};

template <size_t I, class T, template <class> class... Ids>
constexpr T& get(tail::Bag<T, Ids...>& bag)
{
    static_assert(I < sizeof...(Ids));
    using Base = tail::ith_t<I, Ids<T>...>;
    return reinterpret_cast<T&>(static_cast<Base&>(bag));
}

template <size_t I, class T, template <class> class... Ids>
constexpr T&& get(tail::Bag<T, Ids...>&& bag)
{
    static_assert(I < sizeof...(Ids));
    using Base = tail::ith_t<I, Ids<T>...>;
    return reinterpret_cast<T&&>(static_cast<Base&&>(bag));
}

template <size_t I, class T, template <class> class... Ids>
constexpr const T& get(const tail::Bag<T, Ids...>& bag)
{
    static_assert(I < sizeof...(Ids));
    using Base = tail::ith_t<I, Ids<T>...>;
    return reinterpret_cast<const T&>(static_cast<const Base&>(bag));
}

template <size_t I, class T, template <class> class... Ids>
constexpr const T&& get(const tail::Bag<T, Ids...>&& bag)
{
    static_assert(I < sizeof...(Ids));
    using Base = tail::ith_t<I, Ids<T>...>;
    return reinterpret_cast<const T&&>(static_cast<const Base&&>(bag));
}

} // namespace ecosnail::tail
