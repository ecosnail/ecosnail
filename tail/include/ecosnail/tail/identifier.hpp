#pragma once

#define ECOSNAIL_IDENTIFIER(TYPE_NAME, IDENTIFIER_NAME) \
    template <class T> struct TYPE_NAME { T IDENTIFIER_NAME; }
