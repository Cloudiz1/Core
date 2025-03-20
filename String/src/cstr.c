#include "include/cstr.h"

String *snew(const char *input) {
    String *out = malloc(sizeof(String));
    if (out == NULL) return NULL;

    out->len = strlen(input);
    out->val = malloc(strlen(input) + 1); // sizeof(char) == 1
    if (out->val == NULL) {
        free(out);
        return NULL;
    }

    strcpy(out->val, input);
    return out;
}

String *sadd(String *dest, const char *new) {
    dest->len += strlen(new);
    void *out = realloc(dest->val, dest->len + 1);
    if (out == NULL) return NULL;

    strcat(dest->val, new);
    return dest;
}

/*
String* str = snew("hello world");
sslice(str, 0, 4) -> "hello" (as String *, ofc)
sslice(str, 6, str->len - 1) (also equivalent to sslice(str, 6, -1)) -> "world"
sslice(str, -5, -1) -> "world"
*/
String *sslice(const String *input, int a, int b) {
    if (a > (int)input->len || a < -1 * (int)input->len - 1) {
        // printf("first index out of bounds \n");
        // exit(-1);
        return NULL;
    }
    
    if (b > (int)input->len || b < -1 * (int)input->len - 1) {
        // printf("second index is out of bounds \n");
        // exit(-1);
        return NULL;
    }

    if (a < 0) {
        a += input->len;
    }

    if (b < 0) {
        b += input->len;
    }

    if (a > b) {
        // printf("first index is larger than second index \n");
        // exit(-1);
        return NULL;
    }

    char *outval = malloc(b - a + 1); // +1 for '\0'
    if (outval == NULL) return NULL;
    strncpy(outval, input->val + a, b - a);
    outval[b - a] = '\0';
    String *out = snew(outval);
    out->len = strlen(out->val);
    return out;
}

String *supper(String *input) {
    char *outval = malloc(input->len + 1);
    for (int i = 0; i < (int)input->len; i++) {
        outval[i] = toupper(input->val[i]);
    }

    outval[input->len] = '\0';
    return snew(outval);
}

String *slower(String *input) {
    char *outval = malloc(input->len + 1);
    for (int i = 0; i < (int)input->len; i++) {
        outval[i] = tolower(input->val[i]);
    }

    outval[input->len] = '\0';
    return snew(outval);
}

int scmp(const String *s1, const String *s2) {
    return strcmp(s1->val, s2->val);
}

void sclear(String *input) {
    free(input->val);
    input->val = malloc(1);
    input->val[0] = '\0';
    input->len = 0;
}

int sisempty(const String *input) {
    if (input->len == 0) {
        return 1;
    }

    return 0;
}

String *sreplace(String *input, const char *s1, const char *s2) {
    char *p;
    while ((p = strstr(input->val, s1)) != NULL) {
        char *new = malloc(input->len + strlen(s2) - strlen(s1) + 1);
        if (new == NULL) return NULL;

        size_t plen = p - input->val;

        strncpy(new, input->val, plen);
        strcpy(new + plen, s2);
        strcpy(new + plen + strlen(s2), p + strlen(s1));

        free(input->val);
        input->val = new;
        input->len = strlen(new);
    }

    return input;
}

void sprint(const String *str) {
    printf("%s", str->val);
}

void sprintln(const String *str) {
    printf("%s\n", str->val);
}

void sfree(String *str) {
    free(str->val);
    free(str);
}