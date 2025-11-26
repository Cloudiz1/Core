#ifndef GENTYPENAME
#define GENTYPENAME GENTYPE
#endif // GENTYPEGENNAME

#define _CONCAT_(a, b) a ## b
#define _CONCAT(a, b) _CONCAT_(a, b)

#define GEN_NAME(qualifier) _CONCAT(qualifier, _CONCAT(_, GENTYPENAME))
#define GEN_TYPE GEN_NAME(GEN_PREFIX)
