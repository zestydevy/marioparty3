#!/usr/bin/env python3

# This is a script that executes the mips_to_c decompiler based on given args.
# The intention is to help streamline executing the decompiler.

# Script takes 3 arguments:
# Git repo root directory ("/home/user/code/mp3")
# Current .c file being edited ("/home/user/code/mp3/src/heap.c")
# Current .c file line (7)

# For example, you can set up a VS Code Task and key binding to execute this,
# and this script will run mips_to_c for the INCLUDE_ASM that your cursor is
# nearest to.

# {
#     "label": "Run mips_to_c on current function",
#     "type": "shell",
#     "command": "./tools/run-mips-to-c.py",
#     "args": [
#         "${workspaceFolder}",
#         "${file}",
#         "${lineNumber}"
#     ],
#     "problemMatcher": []
# }

import sys
import re
import subprocess
import m2ctx
import tempfile

rootDir = sys.argv[1]
cfile = sys.argv[2]
lineNumber = max(0, int(sys.argv[3]) - 1)

def run_mips_to_c(retType, funcPath, funcName, contextFile):
    asmPath = rootDir + "/asm/nonmatchings/" + funcPath + "/" + funcName + ".s"
    mipsToCPath = rootDir + "/tools/mips_to_c/mips_to_c.py"
    procArgs = [mipsToCPath]
    procArgs.append("--context")
    procArgs.append(contextFile)
    if retType == "void":
        procArgs.append("--void")
    procArgs.append(asmPath)
    subprocess.run(procArgs)

with tempfile.NamedTemporaryFile() as tmp:
    m2ctx.m2ctx(cfile, tmp.name)

    with open(cfile, "r") as infile:
        lines = infile.readlines()
        while (lineNumber >= 0):
            lineText = lines[lineNumber]
            x = re.match("^/*INCLUDE_ASM\(([\w\s\*]+),\s\"([/\w]+)\",\s(\w+)", lineText)
            if x:
                run_mips_to_c(x.group(1), x.group(2), x.group(3), tmp.name)
                break
            lineNumber = lineNumber - 1
