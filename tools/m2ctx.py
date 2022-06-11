#!/usr/bin/python3

# Generates a "context" file for use with mips_to_c
# ./m2ctx.py file.c [output.c]

import os
import sys
import subprocess
from pathlib import Path

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))
src_dir = root_dir + "src/"


def get_c_dir(dirname):
    for root, dirs, files in os.walk(src_dir):
        for directory in dirs:
            if directory == dirname:
                return os.path.join(root, directory)


def get_c_file(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".c") and "data" not in file:
                return file


def import_c_file(in_file):
    in_file = os.path.relpath(in_file, root_dir)
    cpp_command = ["gcc", "-E", "-P", "-Iinclude", "-Isrc","-D_LANGUAGE_C",
                   "-ffreestanding", "-DF3DEX_GBI_2", "-D_MIPS_SZLONG=32", "-DSCRIPT(...)={}", in_file]
    try:
        return subprocess.check_output(cpp_command, cwd=root_dir, encoding="utf-8")
    except subprocess.CalledProcessError:
        print(
            "Failed to preprocess input file, when running command:\n"
            + cpp_command,
            file=sys.stderr,
            )
        sys.exit(1)


def main():
    if len(sys.argv) > 1:
        c_file_path = Path.cwd() / sys.argv[1]
    if len(sys.argv) > 2:
        out_file_path = Path.cwd() / sys.argv[2]
    m2ctx(c_file_path, out_file_path)


def m2ctx(c_file_path, out_file_path):
    processed = import_c_file(c_file_path)
    processed_lines = processed.split("\n")
    output = []

    for line in processed_lines:
        if ("__attribute__" not in line
            and "__asm" not in line):
            output.append(line)

    with open(out_file_path, "w", encoding="UTF-8") as f:
        f.write("\n".join(output))


if __name__ == "__main__":
    main()
