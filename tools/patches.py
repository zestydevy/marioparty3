#!/usr/bin/env python3

# Applies some manual changes after splitting the ROM.

# Nonmatching functions accessing HVQ ROM_START are patched to refer to that symbol.
hvq_asm_files = [
    "asm/nonmatchings/overlays/overlay110/4C8050/func_8010FC98_4CCEC8.s",
    "asm/nonmatchings/overlays/overlay115/4F01F0/func_801059A0_4F01F0.s",
    "asm/nonmatchings/overlays/overlay124/5486A0/func_8010D1E8_549A68.s",
    "asm/nonmatchings/overlays/overlay125/54F360/func_80107204_54F574.s"
]

for file_path in hvq_asm_files:
    with open(file_path, 'r') as file :
        filedata = file.read()

    filedata = filedata.replace('$a0, 0x129', '$a0, %hi(bin_hvq_ROM_START)')
    filedata = filedata.replace('$a0, $a0, -0x33a0', '$a0, $a0, %lo(bin_hvq_ROM_START)')

    with open(file_path, 'w') as file:
        file.write(filedata)

# Nonmatching String ROM references are in a single tricky function.
strings_fn = "asm/nonmatchings/5ACF0/func_8005A6B0.s"
with open(strings_fn, 'r') as file :
    filedata = file.read()

filedata = filedata.replace('$a0, 0x121', '$a0, %hi(bin_strings_jp_ROM_START)')
filedata = filedata.replace('$a0, $a0, -0x67b0', '$a0, $a0, %lo(bin_strings_jp_ROM_START)')

filedata = filedata.replace('$a0, 0x122', '$a0, %hi(bin_strings_en_ROM_START)')
filedata = filedata.replace('$a0, $a0, -0x3560', '$a0, $a0, %lo(bin_strings_en_ROM_START)')

filedata = filedata.replace('$a0, 0x125', '$a0, %hi(bin_strings_fr_ROM_START)')
filedata = filedata.replace('$a0, $a0, -0x2bc0', '$a0, $a0, %lo(bin_strings_fr_ROM_START)')

filedata = filedata.replace('$a0, 0x123', '$a0, %hi(bin_strings_de_ROM_START)')
filedata = filedata.replace('$a0, $a0, 0x55c0', '$a0, $a0, %lo(bin_strings_de_ROM_START)')

filedata = filedata.replace('$a0, 0x127', '$a0, %hi(bin_strings_es_ROM_START)')
filedata = filedata.replace('$a0, $a0, 0x65f0', '$a0, $a0, %lo(bin_strings_es_ROM_START)')

filedata = filedata.replace('$a0, 0x126', '$a0, %hi(bin_strings_it_ROM_START)')
filedata = filedata.replace('$a0, $a0, 0x1f90', '$a0, $a0, %lo(bin_strings_it_ROM_START)')

with open(strings_fn, 'w') as file:
    file.write(filedata)


# Make it easy to patch out the save type check.
c210file = "asm/nonmatchings/CE10/func_8000C210.s"
with open(c210file, 'r') as file :
    filedata = file.read()

filedata = filedata.replace('/* CEC0 8000C2C0 080030B0 */  j         .L8000C2C0', """
.ifdef MP_SAVETYPE_PATCH
/* CEC0 8000C2C0 00000000 */  nop
.else
/* CEC0 8000C2C0 080030B0 */  j         .L8000C2C0
.endif
""")

with open(c210file, 'w') as file:
    file.write(filedata)
