```C
sclear(String *input); // (done)
sisempty(String *input); // (done)
sreplace(String *input, char *s1, char *s2); // done
ssplit(String *input, char *at); // waiting on vector implementation
sfree(String *input); // done
```

probably add some sort of error system with `errno` and `strerror`

automated tests; ensure:
- value is always checked
- len is always checked