#pragma once

#include <iterator>
#include <type_traits>

namespace ecosnail::tail {

template <class T, class = void>
struct IsIterator : std::false_type {};

template <class T>
struct IsIterator<T, std::void_t<
        typename std::iterator_traits<T>::difference_type,
        typename std::iterator_traits<T>::value_type,
        typename std::iterator_traits<T>::pointer,
        typename std::iterator_traits<T>::reference,
        typename std::iterator_traits<T>::iterator_category>>
    : std::true_type {};

template <class T, class = void>
struct IsConstIterator : std::false_type {};

template <class T>
struct IsConstIterator<T, std::enable_if_t<
        IsIterator<T>::value &&
            std::is_const_v<
                std::remove_reference_t<
                    typename std::iterator_traits<T>::reference>>>>
    : std::true_type {};

template <class T, template <class...> class Template>
struct IsFromTemplate : std::false_type {};

template <template <class...> class Template, class... Args>
struct IsFromTemplate<Template<Args...>, Template> : std::true_type {};

} // namespace ecosnail::tail
