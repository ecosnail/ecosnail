#pragma once

#include <string>
#include <vector>
#include <map>
#include <type_traits>
#include <variant>
#include <stdexcept>
#include <ostream>

namespace ecosnail {
namespace tops {

template <class T> struct TopsTypeName;

class Tops {
public:
    using String = std::string;
    using List = std::vector<Tops>;
    using Dictionary = std::map<std::string, Tops>;
    using Value = std::variant<std::monostate, String, List, Dictionary>;

    Tops() {}
    Tops(Value value, std::string name = "");

    //
    // Common operations
    //

    // operator=

    Tops& operator=(const   String& str);

    Tops& operator=(const String::value_type* s);
    Tops& operator=(String::value_type ch);

    Tops& operator=(String&& str);
    Tops& operator=(std::initializer_list<String::value_type> ilist);

    Tops& operator=(std::basic_string_view<char, String::traits_type> sv);

    // std::string::assign

    Tops& assign(String::size_type count, String::value_type ch);
    Tops& assign(const String& str);

    basic_string& assign(const basic_string& str,
        size_type pos,
        size_type count);

    Tops& assign(
        const String& str,
        String::size_type pos,
        String::size_type count = String::npos);

    Tops& assign(String&& str);
    Tops& assign(std::initializer_list<String::value_type> ilist);

    Tops& assign(const String::value_type* s, String::size_type count);
    Tops& assign(const String::value_type* s);

    template <class InputIt>
    Tops& assign(InputIt first, InputIt last);

    Tops& assign(
        std::basic_string_view<String::value_type, String::traits_type> sv);

    template < class T >
    Tops& assign(
        const T& t,
        String::size_type pos,
        String::size_type count = String::npos);

    // std::string::get_allocator

    String::allocator_type get_allocator() const;

    // std::string::at

    String::reference at(String::size_type pos);
    String::const_reference at(String::size_type pos) const;

    // std::string::operator[]

    String::reference operator[](String::size_type pos);
    String::const_reference operator[](String::size_type pos) const;

    // std::string::front

    String::value_type& front();
    const String::value_type& front() const;

    // std::string::back

    String::value_type& back();
    const String::value_type& back() const;

    // std::string::data

    const String::value_type* data() const;

    String::value_type* data();

    // std::string::c_str

    const String::value_type* c_str() const;

    // std::string::operator basic_string_view

    operator std::basic_string_view<
        String::value_type, String::traits_type>() const noexcept;

    // std::string::begin, std::string::cbegin

    String::iterator begin();
    String::const_iterator begin() const;

    String::const_iterator cbegin() const;

    // end, cend

    String::iterator end();
    String::const_iterator end() const;

    String::const_iterator cend() const;

    // rbegin, crbegin

    String::reverse_iterator rbegin();
    String::const_reverse_iterator rbegin() const;

    String::const_reverse_iterator crbegin() const;

    // rend, crend

    String::reverse_iterator rend();
    String::const_reverse_iterator rend() const;

    String::const_reverse_iterator crend() const;

    // empty

    bool empty() const;

    // size, length

    String::size_type size() const;
    String::size_type length() const;

    // max_size

    String::size_type max_size() const;

    // reserve

    void reserve(String::size_type new_cap = 0);

    // capacity

    String::size_type capacity() const;

    // shrink to fit

    void shrink_to_fit();

    // clear

    void clear();

    // insert

    Tops& insert(String::size_type index, String::size_type count, String::value_type ch);
    Tops& insert(String::size_type index, const String::value_type* s);
    Tops& insert(String::size_type index, const String::value_type* s, String::size_type count);
    Tops& insert(String::size_type index, const String& str);

    basic_string& insert(size_type index, const basic_string& str,
        size_type index_str, size_type count);

    Tops& insert(String::size_type index, const String& str,
        String::size_type index_str, String::size_type count = String::npos);

    iterator insert(iterator pos, CharT ch);
    void insert(iterator pos, size_type count, CharT ch);

    String::iterator insert(String::const_iterator pos, String::value_type ch);
    String::iterator insert(String::const_iterator pos, String::size_type count, String::value_type ch);

    template< class InputIt >
    void insert(iterator pos, InputIt first, InputIt last);
    template< class InputIt >
    String::iterator insert(String::const_iterator pos, InputIt first, InputIt last);

    String::iterator insert(String::const_iterator pos, std::initializer_list<String::value_type> ilist);

    Tops& insert(String::size_type pos, std::basic_string_view<String::value_type, String::traits_type> sv);

    template < class T >
    Tops& insert(String::size_type index, const T& t,
        String::size_type index_str, String::size_type count = String::npos);

    // erase

    Tops& erase(String::size_type index = 0, String::size_type count = String::npos);

    String::iterator erase(String::iterator position);
    String::iterator erase(String::const_iterator position);

    String::iterator erase(String::iterator first, String::iterator last);
    String::iterator erase(String::const_iterator first, String::const_iterator last);

    // push_back

    void push_back(String::value_type ch);

    // pop_back

    void pop_back();

    // append

    Tops& append(String::size_type count, String::value_type ch);
    Tops& append(const String& str);

    basic_string& append(const basic_string& str,
        size_type pos,
        size_type count);
    Tops& append(const String& str,
        String::size_type pos,
        String::size_type count = String::npos);

    Tops& append(const String::value_type* s, String::size_type count);
    Tops& append(const String::value_type* s);

    template< class InputIt >
    Tops& append(InputIt first, InputIt last);

    Tops& append(std::initializer_list<String::value_type> ilist);

    Tops& append(std::basic_string_view<String::value_type, String::traits_type> sv);

    template < class T >
    Tops& append(const T& t, String::size_type pos,
        String::size_type count = String::npos);

    // operator+=

    Tops& operator+=(const String& str);
    Tops& operator+=(String::value_type ch);
    Tops& operator+=(const String::value_type* s);

    Tops& operator+=(std::initializer_list<CharT> ilist);

    Tops& operator+=(std::basic_string_view<CharT, Traits> sv);

    // compare

    int compare(const basic_string& str) const;
    int compare(size_type pos1, size_type count1,
        const basic_string& str) const;

    int compare(size_type pos1, size_type count1,
        const basic_string& str,
        size_type pos2, size_type count2) const;
    int compare(size_type pos1, size_type count1,
        const basic_string& str,
        size_type pos2, size_type count2 = npos) const;

    int compare(const CharT* s) const;
    int compare(size_type pos1, size_type count1,
        const CharT* s) const;
    int compare(size_type pos1, size_type count1,
        const CharT* s, size_type count2) const;
    int compare(std::basic_string_view<CharT, Traits> sv) const;

    int compare(size_type pos1, size_type count1,
        std::basic_string_view<CharT, Traits> sv) const;
    template < class T >
    int compare(size_type pos1, size_type count1,
        const T& t,
        size_type pos2, size_type count2 = npos) const;

    // replace

    basic_string& replace( size_type pos, size_type count,
                           const basic_string& str );
    basic_string& replace( const_iterator first, const_iterator last,
                           const basic_string& str );

    basic_string& replace( size_type pos, size_type count,
                           const basic_string& str,
                           size_type pos2, size_type count2 );
    basic_string& replace( size_type pos, size_type count,
                           const basic_string& str,
                           size_type pos2, size_type count2 = npos );

    template< class InputIt >
    basic_string& replace( const_iterator first, const_iterator last,
                           InputIt first2, InputIt last2 );
    basic_string& replace( size_type pos, size_type count,
                           const CharT* cstr, size_type count2 );
    basic_string& replace( const_iterator first, const_iterator last,
                           const CharT* cstr, size_type count2 );
    basic_string& replace( size_type pos, size_type count,
                           const CharT* cstr );
    basic_string& replace( const_iterator first, const_iterator last,
                           const CharT* cstr );
    basic_string& replace( size_type pos, size_type count,
                           size_type count2, CharT ch );
    basic_string& replace( const_iterator first, const_iterator last,
                           size_type count2, CharT ch );
    basic_string& replace( const_iterator first, const_iterator last, 
                           std::initializer_list<CharT> ilist );

    basic_string& replace( size_type pos, size_type count,
                           std::basic_string_view<CharT, Traits> sv );
    basic_string& replace( const_iterator first, const_iterator last,
                           std::basic_string_view<CharT, Traits> sv );
    template < class T >
    basic_string& replace( size_type pos, size_type count, const T& t,
                           size_type pos2, size_type count2 = npos );

    // substr

    basic_string substr( size_type pos = 0,
                     size_type count = npos ) const;

    // copy

    size_type copy( CharT* dest,
                size_type count,
                size_type pos = 0) const;

    // resize

    void resize( size_type count );
    void resize( size_type count, CharT ch );

    // swap

    void swap( basic_string& other );
    void swap( basic_string& other ) noexcept(
        std::allocator_traits<Allocator>::propagate_on_container_swap::value ||
            std::allocator_traits<Allocator>::is_always_equal::value);

    // find

    size_type find( const basic_string& str, size_type pos = 0 ) const
    size_type find( const CharT* s, size_type pos, size_type count ) const;
    size_type find( const CharT* s, size_type pos = 0 ) const;
    size_type find( CharT ch, size_type pos = 0 ) const;

    size_type find( std::basic_string_view<CharT, Traits> sv,
                    size_type pos = 0) const

    // rfind

    size_type find( const basic_string& str, size_type pos = 0 ) const
    size_type find( const CharT* s, size_type pos, size_type count ) const;
    size_type find( const CharT* s, size_type pos = 0 ) const;
    size_type find( CharT ch, size_type pos = 0 ) const;

    size_type find( std::basic_string_view<CharT, Traits> sv,
                    size_type pos = 0) const

    // find_first_of

    size_type find_first_of( const basic_string& str, size_type pos = 0 ) const;
    size_type find_first_of( const CharT* s, size_type pos, size_type count ) const;
    size_type find_first_of( const CharT* s, size_type pos = 0 ) const;
    size_type find_first_of( CharT ch, size_type pos = 0 ) const;

    size_type find_first_of( std::basic_string_view<CharT, Traits> sv,
                             size_type pos = 0 ) const

    // find_first_not_of

    size_type find_first_not_of( const basic_string& str, size_type pos = 0 ) const;
    size_type find_first_not_of( const CharT* s, size_type pos, size_type count ) const;
    size_type find_first_not_of( const CharT* s, size_type pos = 0 ) const;
    size_type find_first_not_of( CharT ch, size_type pos = 0 ) const;
    size_type find_first_not_of( std::basic_string_view<CharT, Traits> sv,
                                 size_type pos = 0) const

    // find_last_of

    size_type find_last_of( const basic_string& str, size_type pos = npos ) const;
    size_type find_last_of( const CharT* s, size_type pos, size_type count ) const;
    size_type find_last_of( const CharT* s, size_type pos = npos ) const;
    size_type find_last_of( CharT ch, size_type pos = npos ) const;

    size_type find_last_of( std::basic_string_view<CharT, Traits> sv,
                            size_type pos = npos) const

    // find_last_not_of

    size_type find_last_not_of( const basic_string& str, size_type pos = npos ) const;
    size_type find_last_not_of( const CharT* s, size_type pos, size_type count ) const;
    size_type find_last_not_of( const CharT* s, size_type pos = npos ) const;
    size_type find_last_not_of( CharT ch, size_type pos = npos ) const;

    size_type find_last_not_of( std::basic_string_view<CharT, Traits> sv,
                                size_type pos = npos) const



    friend std::ostream& operator<<(std::ostream& stream, const Tops& tops);

private:
    void prettyPrint(
        std::ostream& stream,
        int offset = 0,
        bool skipFirst = false) const;

    template <class T> T& get()
    {
        if (std::holds_alternative<std::monostate>(_value)) {
            _value.emplace<T>();
        } else if (!std::holds_alternative<T>(_value)) {
            throw std::runtime_error("not a " + TopsTypeName<T>::value);
        }
        return std::get<T>(_value);
    }

    std::string _name;
    Value _value;
};

template <> struct TopsTypeName<Tops::String> { static const char* value; };
template <> struct TopsTypeName<Tops::List> { static const char* value; };
template <> struct TopsTypeName<Tops::Dictionary> { static const char* value; };

Tops parseDocument(const std::string& path);

}} // namespace ecosnail::tops
