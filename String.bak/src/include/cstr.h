#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct {
    char *val;
    size_t len;
} String;

String *snew(const char *input);
String *sadd(String *dest, const char *new);
String *sslice(const String *src, int a, int b);
String *supper(String *input);
String *slower(String *input);
int scmp(const String *s1, const String *s2);
void sclear(String *input);
int sisempty(const String *input);
String *sreplace(String *input, const char *s1, const char *s2);
void sprint(const String *str);
void sprintln(const String *str);