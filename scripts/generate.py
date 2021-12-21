#! /usr/bin/env python3

# Generate main README.md

import os
import string
import shutil

ifilename = os.path.join(".", "input", "README.txt")
ofilename = os.path.join("..", "README.md")


def prepare():
    file_path = os.path.realpath(__file__)
    wd = os.path.dirname(file_path)
    os.chdir(wd)
    print(f"Working directory = {os.getcwd()}")
    if not os.path.isfile(ifilename):
        print(f"Can't find {ifilename}. Exit.")
        return False
    # back up
    if os.path.isfile(ofilename):
        bak = ofilename + ".bak"
        shutil.copy(ofilename, bak)
        print(f"Created {bak}")
    return True


def set_default_chapter_readme(num, name, path):
    readme_path = os.path.join(path, "README.md")

    header = f"# Chapter {num} {name}\n"


    with open(readme_path, "r+") as iofile:
        first_line = iofile.readline()
        if first_line == header:
            print(f"Chapter {num} has the standard header")
        else:
            iofile.seek(0)
            original = iofile.read()
            iofile.seek(0)
            iofile.write(header + original)
            print(f"Updated Chapter {num} with a standard header")



    if os.path.isfile(os.path.join("input", f"README-{num:02}.txt")):
        print(f"Can write meta for chapter {num}");


def set_default_chapter(num, name, path):
    if not os.path.isdir(path):
        os.mkdir(path)
        print(f"Created {path}")
    set_default_chapter_readme(num, name, path)


def chapter_repr(num, name, dirname):
    return f"  - [Chapter {num} {name}]({dirname})\n"


def part_repr(num, name):
    return f"\n- Part {num} {name}\n" if name else f"\n- Part {num}\n"



def main():
    if not prepare():
        return
    with open(ifilename) as ifile:
        with open(ofilename, "w") as ofile:
            for line in ifile:
                line = line.strip()
                # skip comments
                if not line or line.startswith("#"):
                    continue
                split = line.split(maxsplit=1)
                key = split[0]
                value = split[1] if len(split) > 1 else ""
                if key == "desc":
                    ofile.write(value + "\n")
                    continue
                try:
                    num = int(key)
                    name = value
                    table = str.maketrans("", "", ",")
                    words = "-".join(name.translate(table).lower().split())
                    dirname = f"{num:02}-{words}"
                    path = os.path.join("..", dirname)
                    set_default_chapter(num, name, path)
                    ofile.write(chapter_repr(num, name, dirname))
                except Exception as e:
                    num = key
                    name = value
                    ofile.write(part_repr(num, name))


if __name__ == "__main__":
    main()
