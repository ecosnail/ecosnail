#pragma once

#include <cstddef>

namespace ecosnail::tail {

template <size_t I, class... Ts> struct ith;

template <size_t I, class... Ts>
using ith_t = typename ith<I, Ts...>::type;

template <class T1, class... Ts>
struct ith<0, T1, Ts...> {
    using type = T1;
};

template <size_t I, class T1, class... Ts>
struct ith<I, T1, Ts...> {
    using type = ith_t<I - 1, Ts...>;
};

} // namespace ecosnail::tail
