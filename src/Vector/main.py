formats = {
    "int": "i",
    "float": "f",
    "double": "f",
    "char": "c",
    "str": "s"
}

def body(type, formatter):
    return f"""static inline void vector_printf_{type}(vector_{type} *v) {{
    printf("[");
    for (int i = 0; i < v->size; i++) {{
        printf("%{formatter}", v->data[i]);
        if (i != v->size - 1) {{
            printf(", ");
        }}
    }}
    printf("]\\n");
}}

"""

with open("out.c", "w") as f:
    for (type, formatter) in zip(formats.keys(), formats.values()):
        f.write(body(type, formatter))

