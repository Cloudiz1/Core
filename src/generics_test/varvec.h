#if defined (GENTYPE)

#ifndef GENTYPENAME
#define GENTYPENAME GENTYPE
#endif // GENTYPENAME

#define _CONCAT_(a, b) a ## b
#define _CONCAT(a, b) _CONCAT_(a, b)
#define _PREFIX Vector
#define _NAME(qualifier) _CONCAT(qualifier, _CONCAT(_, GENTYPENAME))

typedef struct {
    size_t size;
    size_t capacity;
    size_t typesize;
    GENTYPE data;
} _NAME(Vector);

GENTYPE _NAME(vectorNew)()
{
    return 0;
}

#undef _CONCAT_
#undef _CONCAT
#undef _NAME
#undef TYPENAME

#endif // defined (GENTYPE)

#undef GENTYPE
#undef GENTYPENAME

