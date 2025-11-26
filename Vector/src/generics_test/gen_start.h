#ifndef GEN_TYPE_NAME
#define GEN_TYPE_NAME GEN_TYPE
#endif // GEN_TYPE_NAME

#define _CONCAT_(a, b) a ## b
#define _CONCAT(a, b) _CONCAT_(a, b)

#define GEN_NAME(qualifier) _CONCAT(GEN_PREFIX, _CONCAT(_, _CONCAT(qualifier, _CONCAT(_, GEN_TYPE_NAME))))
#define GEN_DATA _CONCAT(GEN_PREFIX, _CONCAT(_, GEN_TYPE_NAME))
