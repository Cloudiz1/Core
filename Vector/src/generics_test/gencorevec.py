import sys


def main():
    generate(["char", "int", "float"], ["vnew", "vadd v e"])


def generate(types: list[str], signatures: list[str]):
    if types == [] or signatures == []:
        print("invalid arguments", file=sys.stderr)
        return

    file = open("test.c", "w")

    for type in types:
        file.writelines(
            [
                f"#define GENTYPE {type}\n",
                f'#include "varvec.h"\n',
                f"\n",
            ]
        )

    for type in types:
        file.writelines(
            [
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
            param_comma += params[-1]
            param_grouped += f"({params[-1]})"

        print(fname, params, param_grouped)
        file.write(f"#define {fname}({param_comma}) _Generic((*v),".ljust(40) + "\\\n")

        for type in types:
            file.write(f"    Vector_{type}: {fname}_{type},".ljust(40) + "\\\n")

        for type in types[:-1]:
            file.write(f"    Vector_{type}_p: {fname}_{type}_p,".ljust(40) + "\\\n")
        file.write(
            f"    Vector_{types[-1]}_p: {fname}_{types[-1]}_p".ljust(40) + "\\\n"
        )

        file.write(f"    )({param_grouped})\n")
        file.write("\n")

    file.close()


if __name__ == "__main__":
    main()
