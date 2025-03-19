def generate(types: list[str], signatures: list[str]):
    file = open("test.c", "w")

    for type in types:
        file.writelines(
            [
                f"#define GENTYPE {type}\n",
                f'#include "varvec.h"\n',
                f"\n",
                f"#define GENTYPE {type} *\n",
                f"#define GENTYPENAME {type}_p\n",
                f'#include "varvec.h"\n',
                f"\n",
            ]
        )

    for signature in signatures:
        fname, *params = signature.split()
        param_comma = "v"
        param_grouped = ""
        if params != []:
            param_comma = ""
            for param in params[:-1]:
                param_comma += f"{param}, "
                param_grouped += f"({param}), "
            param_comma += f"{params[-1]}"
            param_grouped += f"({params[-1]})"

        print(fname, params, param_grouped)
        file.write(f"#define {fname}({param_comma}) _Generic((*v), \\\n")

        for type in types:
            file.write(f"    Vector_{type}: {fname}_{type}, \\\n")

        for type in types:
            file.write(f"    Vector_{type}_p: {fname}_{type}_p, \\\n")

        file.write(f"    )({param_grouped})\n")
        file.write(f"\n")

    file.close()


def main():
    generate(["char", "int", "float"], ["vnew", "vadd v e"])


if __name__ == "__main__":
    main()
