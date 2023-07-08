SECTIONS
{
    __romPos = 0x0;
    . = __romPos;
    header_ROM_START = __romPos;
    header_VRAM = ADDR(.header);
    .header : AT(header_ROM_START) SUBALIGN(16)
    {
        header_TEXT_END = .;
        header_DATA_START = .;
        header_bin = .;
        build/assets/header.bin.o(.data);
        header_DATA_END = .;
    }
    header_ROM_END = 0x40;
    __romPos = 0x40;

    __romPos = 0x40;
    . = __romPos;
    boot_ROM_START = __romPos;
    boot_VRAM = ADDR(.boot);
    .boot : AT(boot_ROM_START) SUBALIGN(16)
    {
        boot_TEXT_END = .;
        boot_DATA_START = .;
        boot_bin = .;
        build/assets/boot.bin.o(.data);
        boot_DATA_END = .;
    }
    boot_ROM_END = 0x1000;
    __romPos = 0x1000;

    __romPos = 0x1000;
    . = __romPos;
    _1000_ROM_START = __romPos;
    _1000_VRAM = ADDR(._1000);
    ._1000 0x80000400 : AT(_1000_ROM_START) SUBALIGN(4)
    {
        _1000_TEXT_START = .;
        build/asm/1000.s.o(.text);
        build/asm/1060.s.o(.text);
        build/asm/8F20.s.o(.text);
        build/asm/99D0.s.o(.text);
        build/src/data.c.o(.text);
        build/src/decode.c.o(.text);
        build/asm/BCA0.s.o(.text);
        build/asm/C1F0.s.o(.text);
        build/asm/esprite.s.o(.text);
        build/asm/eeprom.s.o(.text);
        build/asm/D7A0.s.o(.text);
        build/asm/E560.s.o(.text);
        build/src/stubbed.c.o(.text);
        build/asm/gameman.s.o(.text);
        build/asm/graphics.s.o(.text);
        build/asm/hmfload.s.o(.text);
        build/asm/12E20.s.o(.text);
        build/asm/13F90.s.o(.text);
        build/asm/14EA0.s.o(.text);
        build/asm/19C30.s.o(.text);
        build/src/mallocblock.c.o(.text);
        build/asm/hmfman.s.o(.text);
        build/asm/20A20.s.o(.text);
        build/asm/22EB0.s.o(.text);
        build/asm/30C40.s.o(.text);
        build/asm/32160.s.o(.text);
        build/asm/34DD0.s.o(.text);
        build/asm/main.s.o(.text);
        build/src/mallocperm.c.o(.text);
        build/src/malloctemp.c.o(.text);
        build/asm/365E0.s.o(.text);
        build/asm/save.s.o(.text);
        build/src/malloc.c.o(.text);
        build/asm/36F80.s.o(.text);
        build/asm/37210.s.o(.text);
        build/asm/45F50.s.o(.text);
        build/asm/471D0.s.o(.text);
        build/asm/47D60.s.o(.text);
        build/asm/4B120.s.o(.text);
        build/asm/4BF40.s.o(.text);
        build/src/rom.c.o(.text);
        build/asm/4E800.s.o(.text);
        build/src/process.c.o(.text);
        build/asm/4FE90.s.o(.text);
        build/asm/508F0.s.o(.text);
        build/asm/nnsched.s.o(.text);
        build/asm/52350.s.o(.text);
        build/asm/527E0.s.o(.text);
        build/asm/sprman.s.o(.text);
        build/asm/sprput.s.o(.text);
        build/asm/5ACF0.s.o(.text);
        build/asm/62750.s.o(.text);
        build/asm/66E70.s.o(.text);
        build/asm/67000.s.o(.text);
        build/asm/setjmp.s.o(.text);
        build/asm/lib/hvq.s.o(.text);
        build/asm/6B050.s.o(.text);
        build/asm/6BA20.s.o(.text);
        build/asm/6C140.s.o(.text);
        build/asm/6C320.s.o(.text);
        build/asm/6C3A0.s.o(.text);
        build/asm/6C3C0.s.o(.text);
        build/asm/6C9F0.s.o(.text);
        build/asm/6DBD0.s.o(.text);
        build/asm/6DBF0.s.o(.text);
        build/asm/6DC10.s.o(.text);
        build/asm/6DC30.s.o(.text);
        build/asm/6DC50.s.o(.text);
        build/asm/6DCD0.s.o(.text);
        build/asm/6DCE0.s.o(.text);
        build/asm/6DD10.s.o(.text);
        build/asm/6DF20.s.o(.text);
        build/asm/6DFA0.s.o(.text);
        build/asm/6E6B0.s.o(.text);
        build/asm/6E780.s.o(.text);
        build/asm/6E7E0.s.o(.text);
        build/asm/6E840.s.o(.text);
        build/asm/6E880.s.o(.text);
        build/asm/6E8E0.s.o(.text);
        build/asm/6E940.s.o(.text);
        build/asm/6F470.s.o(.text);
        build/asm/70420.s.o(.text);
        build/asm/707B0.s.o(.text);
        build/asm/70850.s.o(.text);
        build/asm/70940.s.o(.text);
        build/asm/709E0.s.o(.text);
        build/asm/70A70.s.o(.text);
        build/asm/70B20.s.o(.text);
        build/asm/70BB0.s.o(.text);
        build/asm/70C30.s.o(.text);
        build/asm/72740.s.o(.text);
        build/asm/72750.s.o(.text);
        _1000_TEXT_END = .;
        _1000_DATA_START = .;
        _72890_bin = .;
        build/assets/72890.bin.o(.data);
        build/asm/libultra/io/conteepwrite.s.o(.text);
        build/asm/libultra/io/conteepprobe.s.o(.text);
        build/asm/730A0.s.o(.text);
        build/asm/libultra/io/conteeplongread.s.o(.text);
        build/asm/libultra/os/setintmask.s.o(.text);
        build/asm/libultra/io/pimgr.s.o(.text);
        build/asm/libultra/io/epirawdma.s.o(.text);
        build/asm/libultra/io/epidma.s.o(.text);
        build/asm/libultra/io/cartrominit.s.o(.text);
        build/asm/libultra/io/devmgr.s.o(.text);
        build/asm/libultra/io/piacs.s.o(.text);
        build/asm/lubultra/audio/aisetfreq.s.o(.text);
        build/asm/libultra/audio/aisetnextbuf.s.o(.text);
        build/asm/libultra/audio/drvrnew.s.o(.text);
        build/asm/libultra/audio/load.s.o(.text);
        build/asm/libultra/audio/auxbus.s.o(.text);
        build/asm/libultra/audio/bnkf.s.o(.text);
        build/asm/libultra/audio/env.s.o(.text);
        build/asm/libultra/audio/event.s.o(.text);
        build/asm/libultra/audio/filter.s.o(.text);
        build/asm/libultra/audio/mainbus.s.o(.text);
        build/asm/libultra/audio/resample.s.o(.text);
        build/asm/libultra/audio/reverb.s.o(.text);
        build/asm/libultra/audio/save.s.o(.text);
        build/asm/libultra/audio/seq.s.o(.text);
        build/asm/libultra/audio/sl.s.o(.text);
        build/asm/libultra/audio/heapinit.s.o(.text);
        build/asm/libultra/audio/heapalloc.s.o(.text);
        build/asm/libultra/audio/copy.s.o(.text);
        build/asm/libultra/audio/cseq.s.o(.text);
        build/asm/libultra/audio/synthesizer.s.o(.text);
        build/asm/libultra/audio/syndelete.s.o(.text);
        build/asm/libultra/audio/synaddplayer.s.o(.text);
        build/asm/libultra/audio/synfreevoice.s.o(.text);
        build/asm/libultra/audio/synallocvoice.s.o(.text);
        build/asm/libultra/audio/synstopvoice.s.o(.text);
        build/asm/libultra/audio/synstartvoice.s.o(.text);
        build/asm/libultra/audio/synsetpitch.s.o(.text);
        build/asm/libultra/audio/synsetvol.s.o(.text);
        build/asm/libultra/audio/synsetfxmix.s.o(.text);
        build/asm/libultra/audio/synsetpan.s.o(.text);
        build/asm/libultra/audio/synallocfx.s.o(.text);
        build/asm/libultra/audio/cents2ratio.s.o(.text);
        build/asm/libultra/os/invaldcache.s.o(.text);
        build/asm/libultra/os/invalicache.s.o(.text);
        build/asm/libultra/os/writebackdcache.s.o(.text);
        build/asm/libultra/os/writebackdcacheall.s.o(.text);
        build/asm/libultra/io/contreaddata.s.o(.text);
        build/asm/libultra/io/controller.s.o(.text);
        build/asm/libultra/io/contsetch.s.o(.text);
        build/asm/libultra/os/virtualtophysical.s.o(.text);
        build/asm/libultra/gu/cosf.s.o(.text);
        build/asm/libultra/gu/lookat.s.o(.text);
        build/asm/libultra/gu/lookathil.s.o(.text);
        build/asm/libultra/gu/lookatref.s.o(.text);
        build/asm/libultra/gu/ortho.s.o(.text);
        build/asm/libultra/gu/perspective.s.o(.text);
        build/asm/libultra/gu/random.s.o(.text);
        build/asm/libultra/gu/rotaterpy.s.o(.text);
        build/asm/libultra/gu/sinf.s.o(.text);
        build/asm/libultra/os/rdbsend.s.o(.text);
        build/asm/libultra/os/osInitRdb.s.o(.text);
        build/asm/libultra/libc/bcopy.s.o(.text);
        build/asm/libultra/libc/string.s.o(.text);
        build/asm/libultra/libc/sprintf.s.o(.text);
        build/asm/libultra/libc/syncprintf.s.o(.text);
        build/asm/libultra/os/osCreateMesgQueue.s.o(.text);
        build/asm/libultra/os/osJamMesg.s.o(.text);
        build/asm/libultra/os/osRecvMesg.s.o(.text);
        build/asm/libultra/os/osSendMesg.s.o(.text);
        build/asm/libultra/os/seteventmesg.s.o(.text);
        build/asm/libultra/os/setcause.s.o(.text);
        build/asm/libultra/os/setcompare.s.o(.text);
        build/asm/libultra/os/setcount.s.o(.text);
        build/asm/libultra/os/setsr.s.o(.text);
        build/asm/libultra/io/sptask.s.o(.text);
        build/asm/libultra/io/sptaskyield.s.o(.text);
        build/asm/libultra/io/sptaskyielded.s.o(.text);
        build/asm/libultra/io/sirawdma.s.o(.text);
        build/asm/libultra/io/siacs.s.o(.text);
        build/asm/libultra/os/createthread.s.o(.text);
        build/asm/libultra/os/destroythread.s.o(.text);
        build/asm/libultra/os/getthreadpri.s.o(.text);
        build/asm/libultra/os/setthreadpri.s.o(.text);
        build/asm/libultra/os/startthread.s.o(.text);
        build/asm/__osDequeueThread.s.o(.text);
        build/asm/libultra/os/yieldthread.s.o(.text);
        build/asm/libultra/os/osGetTime.s.o(.text);
        build/asm/libultra/os/osSetTimer.s.o(.text);
        build/asm/libultra/os/timerintr.s.o(.text);
        build/asm/libultra/os/probetlb.s.o(.text);
        build/asm/libultra/io/vigetcurrframebuf.s.o(.text);
        build/asm/libultra/io/vigetnextframebuf.s.o(.text);
        build/asm/libultra/io/vimgr.s.o(.text);
        build/asm/libultra/io/visetevent.s.o(.text);
        build/asm/libultra/io/visetmode.s.o(.text);
        build/asm/libultra/io/visetspecial.s.o(.text);
        build/asm/libultra/io/visetyscale.s.o(.text);
        build/asm/libultra/io/viswapbuf.s.o(.text);
        build/asm/libultra/io/viswapcontext.s.o(.text);
        build/asm/libultra/io/viblack.s.o(.text);
        build/asm/libultra/gu/mtxidenf.s.o(.text);
        build/asm/libultra/gu/mtxf2l.s.o(.text);
        build/asm/libultra/gu/mtxl2f.s.o(.text);
        build/asm/libultra/gu/mtxcatf.s.o(.text);
        build/asm/libultra/gu/scale.s.o(.text);
        build/asm/libultra/gu/translatef.s.o(.text);
        build/asm/libultra/gu/mtxcatl.s.o(.text);
        build/asm/libultra/gu/rotate.s.o(.text);
        build/asm/libultra/io/motor.s.o(.text);
        build/asm/libultra/io/pfsselectbank.s.o(.text);
        build/asm/libultra/io/contramread.s.o(.text);
        build/asm/libultra/io/contramwrite.s.o(.text);
        build/asm/libultra/os/afterprenmi.s.o(.text);
        build/asm/libultra/os/getmemsize.s.o(.text);
        build/asm/libultra/os/initialize.s.o(.text);
        build/asm/libultra/os/initialize_kmc.s.o(.text);
        build/asm/libultra/os/initialize_msp.s.o(.text);
        build/asm/libultra/os/initialize_emu.s.o(.text);
        build/asm/libultra/io/conteepread.s.o(.text);
        build/asm/libultra/os/exceptasm.s.o(.text);
        build/asm/libultra/os/setglobalintmask.s.o(.text);
        build/asm/libultra/os/resetglobalintmask.s.o(.text);
        build/asm/libultra/io/pirawdma.s.o(.text);
        build/asm/libultra/io/pigetcmdq.s.o(.text);
        build/asm/libultra/io/epirawread.s.o(.text);
        build/asm/818C0.s.o(.text);
        build/asm/81A30.s.o(.text);
        build/asm/81A80.s.o(.text);
        build/asm/81AD0.s.o(.text);
        build/asm/81AF0.s.o(.text);
        build/asm/81DB0.s.o(.text);
        build/asm/sqrtf.s.o(.text);
        build/asm/81E50.s.o(.text);
        build/asm/81F20.s.o(.text);
        build/asm/824C0.s.o(.text);
        build/asm/_Printf.s.o(.text);
        build/asm/osGetCount.s.o(.text);
        build/asm/830B0.s.o(.text);
        build/asm/830C0.s.o(.text);
        build/asm/83290.s.o(.text);
        build/asm/832B0.s.o(.text);
        build/asm/83390.s.o(.text);
        build/asm/833E0.s.o(.text);
        build/asm/83430.s.o(.text);
        build/asm/83520.s.o(.text);
        build/asm/83580.s.o(.text);
        build/asm/835D0.s.o(.text);
        build/asm/836E0.s.o(.text);
        build/asm/83700.s.o(.text);
        build/asm/83760.s.o(.text);
        build/asm/83A40.s.o(.text);
        build/asm/83C50.s.o(.text);
        build/asm/846E0.s.o(.text);
        build/asm/84780.s.o(.text);
        build/asm/847E0.s.o(.text);
        build/asm/84840.s.o(.text);
        build/asm/85630.s.o(.text);
        build/asm/856C0.s.o(.text);
        build/asm/87310.s.o(.text);
        build/asm/87750.s.o(.text);
        build/asm/osStopThread.s.o(.text);
        build/asm/87830.s.o(.text);
        build/asm/87A00.s.o(.text);
        build/asm/88440.s.o(.text);
        build/asm/88460.s.o(.text);
        build/asm/88710.s.o(.text);
        build/asm/88830.s.o(.text);
        build/asm/88CE0.s.o(.text);
        build/asm/88D50.s.o(.text);
        build/asm/890B0.s.o(.text);
        build/asm/89120.s.o(.text);
        build/asm/89510.s.o(.text);
        build/asm/89FB0.s.o(.text);
        build/asm/8A350.s.o(.text);
        build/asm/8A3D0.s.o(.text);
        build/asm/8A420.s.o(.text);
        build/asm/8A460.s.o(.text);
        build/asm/8A4A0.s.o(.text);
        build/asm/8A4D0.s.o(.text);
        build/asm/8A580.s.o(.text);
        build/asm/8A610.s.o(.text);
        build/asm/8A640.s.o(.text);
        build/asm/8A670.s.o(.text);
        build/asm/8A6B0.s.o(.text);
        build/asm/8A6F0.s.o(.text);
        build/asm/8A770.s.o(.text);
        build/asm/8A830.s.o(.text);
        build/asm/8A860.s.o(.text);
        build/asm/8A890.s.o(.text);
        build/asm/8AA90.s.o(.text);
        build/asm/8AC30.s.o(.text);
        build/asm/8AC70.s.o(.text);
        build/asm/8ACD0.s.o(.text);
        build/asm/8AD20.s.o(.text);
        build/asm/8ADB0.s.o(.text);
        build/asm/8AEA0.s.o(.text);
        build/asm/8AF30.s.o(.text);
        build/asm/8B030.s.o(.text);
        build/asm/8B0C0.s.o(.text);
        build/asm/8B1C0.s.o(.text);
        build/asm/8B3F0.s.o(.text);
        build/asm/8B560.s.o(.text);
        build/asm/8B960.s.o(.text);
        build/asm/8D730.s.o(.text);
        build/asm/8D790.s.o(.text);
        build/asm/8D7F0.s.o(.text);
        build/asm/8D860.s.o(.text);
        build/asm/8D8C0.s.o(.text);
        build/asm/8E050.s.o(.text);
        build/asm/8E4A0.s.o(.text);
        build/asm/8E6B0.s.o(.text);
        build/asm/8EA10.s.o(.text);
        build/asm/8EFF0.s.o(.text);
        build/asm/8F320.s.o(.text);
        build/asm/8F480.s.o(.text);
        build/asm/8F620.s.o(.text);
        build/asm/8F760.s.o(.text);
        build/asm/8F7D0.s.o(.text);
        build/asm/8F830.s.o(.text);
        build/asm/8FB20.s.o(.text);
        _8FCF0_bin = .;
        build/assets/8FCF0.bin.o(.data);
        BCA0_data__s = .;
        build/asm/data/BCA0.data.s.o(.data);
        _98260_bin = .;
        build/assets/98260.bin.o(.data);
        _98310_bin = .;
        build/assets/98310.bin.o(.data);
        build/src/decode.c.o(.rodata);
        A75A8_bin = .;
        build/assets/A75A8.bin.o(.data);
        build/src/mallocblock.c.o(.rodata);
        A77BC_bin = .;
        build/assets/A77BC.bin.o(.data);
        _1000_DATA_END = .;
        _1000_BSS_START = .;
        build/asm/1000.s.o(.bss);
        build/asm/1060.s.o(.bss);
        build/asm/8F20.s.o(.bss);
        build/asm/99D0.s.o(.bss);
        build/src/data.c.o(.bss);
        build/src/decode.c.o(.bss);
        build/asm/BCA0.s.o(.bss);
        build/asm/C1F0.s.o(.bss);
        build/asm/esprite.s.o(.bss);
        build/asm/eeprom.s.o(.bss);
        build/asm/D7A0.s.o(.bss);
        build/asm/E560.s.o(.bss);
        build/src/stubbed.c.o(.bss);
        build/asm/gameman.s.o(.bss);
        build/asm/graphics.s.o(.bss);
        build/asm/hmfload.s.o(.bss);
        build/asm/12E20.s.o(.bss);
        build/asm/13F90.s.o(.bss);
        build/asm/14EA0.s.o(.bss);
        build/asm/19C30.s.o(.bss);
        build/src/mallocblock.c.o(.bss);
        build/asm/hmfman.s.o(.bss);
        build/asm/20A20.s.o(.bss);
        build/asm/22EB0.s.o(.bss);
        build/asm/30C40.s.o(.bss);
        build/asm/32160.s.o(.bss);
        build/asm/34DD0.s.o(.bss);
        build/asm/main.s.o(.bss);
        build/src/mallocperm.c.o(.bss);
        build/src/malloctemp.c.o(.bss);
        build/asm/365E0.s.o(.bss);
        build/asm/save.s.o(.bss);
        build/src/malloc.c.o(.bss);
        build/asm/36F80.s.o(.bss);
        build/asm/37210.s.o(.bss);
        build/asm/45F50.s.o(.bss);
        build/asm/471D0.s.o(.bss);
        build/asm/47D60.s.o(.bss);
        build/asm/4B120.s.o(.bss);
        build/asm/4BF40.s.o(.bss);
        build/src/rom.c.o(.bss);
        build/asm/4E800.s.o(.bss);
        build/src/process.c.o(.bss);
        build/asm/4FE90.s.o(.bss);
        build/asm/508F0.s.o(.bss);
        build/asm/nnsched.s.o(.bss);
        build/asm/52350.s.o(.bss);
        build/asm/527E0.s.o(.bss);
        build/asm/sprman.s.o(.bss);
        build/asm/sprput.s.o(.bss);
        build/asm/5ACF0.s.o(.bss);
        build/asm/62750.s.o(.bss);
        build/asm/66E70.s.o(.bss);
        build/asm/67000.s.o(.bss);
        build/asm/setjmp.s.o(.bss);
        build/asm/lib/hvq.s.o(.bss);
        build/asm/6B050.s.o(.bss);
        build/asm/6BA20.s.o(.bss);
        build/asm/6C140.s.o(.bss);
        build/asm/6C320.s.o(.bss);
        build/asm/6C3A0.s.o(.bss);
        build/asm/6C3C0.s.o(.bss);
        build/asm/6C9F0.s.o(.bss);
        build/asm/6DBD0.s.o(.bss);
        build/asm/6DBF0.s.o(.bss);
        build/asm/6DC10.s.o(.bss);
        build/asm/6DC30.s.o(.bss);
        build/asm/6DC50.s.o(.bss);
        build/asm/6DCD0.s.o(.bss);
        build/asm/6DCE0.s.o(.bss);
        build/asm/6DD10.s.o(.bss);
        build/asm/6DF20.s.o(.bss);
        build/asm/6DFA0.s.o(.bss);
        build/asm/6E6B0.s.o(.bss);
        build/asm/6E780.s.o(.bss);
        build/asm/6E7E0.s.o(.bss);
        build/asm/6E840.s.o(.bss);
        build/asm/6E880.s.o(.bss);
        build/asm/6E8E0.s.o(.bss);
        build/asm/6E940.s.o(.bss);
        build/asm/6F470.s.o(.bss);
        build/asm/70420.s.o(.bss);
        build/asm/707B0.s.o(.bss);
        build/asm/70850.s.o(.bss);
        build/asm/70940.s.o(.bss);
        build/asm/709E0.s.o(.bss);
        build/asm/70A70.s.o(.bss);
        build/asm/70B20.s.o(.bss);
        build/asm/70BB0.s.o(.bss);
        build/asm/70C30.s.o(.bss);
        build/asm/72740.s.o(.bss);
        build/asm/72750.s.o(.bss);
        build/asm/libultra/io/conteepwrite.s.o(.bss);
        build/asm/libultra/io/conteepprobe.s.o(.bss);
        build/asm/730A0.s.o(.bss);
        build/asm/libultra/io/conteeplongread.s.o(.bss);
        build/asm/libultra/os/setintmask.s.o(.bss);
        build/asm/libultra/io/pimgr.s.o(.bss);
        build/asm/libultra/io/epirawdma.s.o(.bss);
        build/asm/libultra/io/epidma.s.o(.bss);
        build/asm/libultra/io/cartrominit.s.o(.bss);
        build/asm/libultra/io/devmgr.s.o(.bss);
        build/asm/libultra/io/piacs.s.o(.bss);
        build/asm/lubultra/audio/aisetfreq.s.o(.bss);
        build/asm/libultra/audio/aisetnextbuf.s.o(.bss);
        build/asm/libultra/audio/drvrnew.s.o(.bss);
        build/asm/libultra/audio/load.s.o(.bss);
        build/asm/libultra/audio/auxbus.s.o(.bss);
        build/asm/libultra/audio/bnkf.s.o(.bss);
        build/asm/libultra/audio/env.s.o(.bss);
        build/asm/libultra/audio/event.s.o(.bss);
        build/asm/libultra/audio/filter.s.o(.bss);
        build/asm/libultra/audio/mainbus.s.o(.bss);
        build/asm/libultra/audio/resample.s.o(.bss);
        build/asm/libultra/audio/reverb.s.o(.bss);
        build/asm/libultra/audio/save.s.o(.bss);
        build/asm/libultra/audio/seq.s.o(.bss);
        build/asm/libultra/audio/sl.s.o(.bss);
        build/asm/libultra/audio/heapinit.s.o(.bss);
        build/asm/libultra/audio/heapalloc.s.o(.bss);
        build/asm/libultra/audio/copy.s.o(.bss);
        build/asm/libultra/audio/cseq.s.o(.bss);
        build/asm/libultra/audio/synthesizer.s.o(.bss);
        build/asm/libultra/audio/syndelete.s.o(.bss);
        build/asm/libultra/audio/synaddplayer.s.o(.bss);
        build/asm/libultra/audio/synfreevoice.s.o(.bss);
        build/asm/libultra/audio/synallocvoice.s.o(.bss);
        build/asm/libultra/audio/synstopvoice.s.o(.bss);
        build/asm/libultra/audio/synstartvoice.s.o(.bss);
        build/asm/libultra/audio/synsetpitch.s.o(.bss);
        build/asm/libultra/audio/synsetvol.s.o(.bss);
        build/asm/libultra/audio/synsetfxmix.s.o(.bss);
        build/asm/libultra/audio/synsetpan.s.o(.bss);
        build/asm/libultra/audio/synallocfx.s.o(.bss);
        build/asm/libultra/audio/cents2ratio.s.o(.bss);
        build/asm/libultra/os/invaldcache.s.o(.bss);
        build/asm/libultra/os/invalicache.s.o(.bss);
        build/asm/libultra/os/writebackdcache.s.o(.bss);
        build/asm/libultra/os/writebackdcacheall.s.o(.bss);
        build/asm/libultra/io/contreaddata.s.o(.bss);
        build/asm/libultra/io/controller.s.o(.bss);
        build/asm/libultra/io/contsetch.s.o(.bss);
        build/asm/libultra/os/virtualtophysical.s.o(.bss);
        build/asm/libultra/gu/cosf.s.o(.bss);
        build/asm/libultra/gu/lookat.s.o(.bss);
        build/asm/libultra/gu/lookathil.s.o(.bss);
        build/asm/libultra/gu/lookatref.s.o(.bss);
        build/asm/libultra/gu/ortho.s.o(.bss);
        build/asm/libultra/gu/perspective.s.o(.bss);
        build/asm/libultra/gu/random.s.o(.bss);
        build/asm/libultra/gu/rotaterpy.s.o(.bss);
        build/asm/libultra/gu/sinf.s.o(.bss);
        build/asm/libultra/os/rdbsend.s.o(.bss);
        build/asm/libultra/os/osInitRdb.s.o(.bss);
        build/asm/libultra/libc/bcopy.s.o(.bss);
        build/asm/libultra/libc/string.s.o(.bss);
        build/asm/libultra/libc/sprintf.s.o(.bss);
        build/asm/libultra/libc/syncprintf.s.o(.bss);
        build/asm/libultra/os/osCreateMesgQueue.s.o(.bss);
        build/asm/libultra/os/osJamMesg.s.o(.bss);
        build/asm/libultra/os/osRecvMesg.s.o(.bss);
        build/asm/libultra/os/osSendMesg.s.o(.bss);
        build/asm/libultra/os/seteventmesg.s.o(.bss);
        build/asm/libultra/os/setcause.s.o(.bss);
        build/asm/libultra/os/setcompare.s.o(.bss);
        build/asm/libultra/os/setcount.s.o(.bss);
        build/asm/libultra/os/setsr.s.o(.bss);
        build/asm/libultra/io/sptask.s.o(.bss);
        build/asm/libultra/io/sptaskyield.s.o(.bss);
        build/asm/libultra/io/sptaskyielded.s.o(.bss);
        build/asm/libultra/io/sirawdma.s.o(.bss);
        build/asm/libultra/io/siacs.s.o(.bss);
        build/asm/libultra/os/createthread.s.o(.bss);
        build/asm/libultra/os/destroythread.s.o(.bss);
        build/asm/libultra/os/getthreadpri.s.o(.bss);
        build/asm/libultra/os/setthreadpri.s.o(.bss);
        build/asm/libultra/os/startthread.s.o(.bss);
        build/asm/__osDequeueThread.s.o(.bss);
        build/asm/libultra/os/yieldthread.s.o(.bss);
        build/asm/libultra/os/osGetTime.s.o(.bss);
        build/asm/libultra/os/osSetTimer.s.o(.bss);
        build/asm/libultra/os/timerintr.s.o(.bss);
        build/asm/libultra/os/probetlb.s.o(.bss);
        build/asm/libultra/io/vigetcurrframebuf.s.o(.bss);
        build/asm/libultra/io/vigetnextframebuf.s.o(.bss);
        build/asm/libultra/io/vimgr.s.o(.bss);
        build/asm/libultra/io/visetevent.s.o(.bss);
        build/asm/libultra/io/visetmode.s.o(.bss);
        build/asm/libultra/io/visetspecial.s.o(.bss);
        build/asm/libultra/io/visetyscale.s.o(.bss);
        build/asm/libultra/io/viswapbuf.s.o(.bss);
        build/asm/libultra/io/viswapcontext.s.o(.bss);
        build/asm/libultra/io/viblack.s.o(.bss);
        build/asm/libultra/gu/mtxidenf.s.o(.bss);
        build/asm/libultra/gu/mtxf2l.s.o(.bss);
        build/asm/libultra/gu/mtxl2f.s.o(.bss);
        build/asm/libultra/gu/mtxcatf.s.o(.bss);
        build/asm/libultra/gu/scale.s.o(.bss);
        build/asm/libultra/gu/translatef.s.o(.bss);
        build/asm/libultra/gu/mtxcatl.s.o(.bss);
        build/asm/libultra/gu/rotate.s.o(.bss);
        build/asm/libultra/io/motor.s.o(.bss);
        build/asm/libultra/io/pfsselectbank.s.o(.bss);
        build/asm/libultra/io/contramread.s.o(.bss);
        build/asm/libultra/io/contramwrite.s.o(.bss);
        build/asm/libultra/os/afterprenmi.s.o(.bss);
        build/asm/libultra/os/getmemsize.s.o(.bss);
        build/asm/libultra/os/initialize.s.o(.bss);
        build/asm/libultra/os/initialize_kmc.s.o(.bss);
        build/asm/libultra/os/initialize_msp.s.o(.bss);
        build/asm/libultra/os/initialize_emu.s.o(.bss);
        build/asm/libultra/io/conteepread.s.o(.bss);
        build/asm/libultra/os/exceptasm.s.o(.bss);
        build/asm/libultra/os/setglobalintmask.s.o(.bss);
        build/asm/libultra/os/resetglobalintmask.s.o(.bss);
        build/asm/libultra/io/pirawdma.s.o(.bss);
        build/asm/libultra/io/pigetcmdq.s.o(.bss);
        build/asm/libultra/io/epirawread.s.o(.bss);
        build/asm/818C0.s.o(.bss);
        build/asm/81A30.s.o(.bss);
        build/asm/81A80.s.o(.bss);
        build/asm/81AD0.s.o(.bss);
        build/asm/81AF0.s.o(.bss);
        build/asm/81DB0.s.o(.bss);
        build/asm/sqrtf.s.o(.bss);
        build/asm/81E50.s.o(.bss);
        build/asm/81F20.s.o(.bss);
        build/asm/824C0.s.o(.bss);
        build/asm/_Printf.s.o(.bss);
        build/asm/osGetCount.s.o(.bss);
        build/asm/830B0.s.o(.bss);
        build/asm/830C0.s.o(.bss);
        build/asm/83290.s.o(.bss);
        build/asm/832B0.s.o(.bss);
        build/asm/83390.s.o(.bss);
        build/asm/833E0.s.o(.bss);
        build/asm/83430.s.o(.bss);
        build/asm/83520.s.o(.bss);
        build/asm/83580.s.o(.bss);
        build/asm/835D0.s.o(.bss);
        build/asm/836E0.s.o(.bss);
        build/asm/83700.s.o(.bss);
        build/asm/83760.s.o(.bss);
        build/asm/83A40.s.o(.bss);
        build/asm/83C50.s.o(.bss);
        build/asm/846E0.s.o(.bss);
        build/asm/84780.s.o(.bss);
        build/asm/847E0.s.o(.bss);
        build/asm/84840.s.o(.bss);
        build/asm/85630.s.o(.bss);
        build/asm/856C0.s.o(.bss);
        build/asm/87310.s.o(.bss);
        build/asm/87750.s.o(.bss);
        build/asm/osStopThread.s.o(.bss);
        build/asm/87830.s.o(.bss);
        build/asm/87A00.s.o(.bss);
        build/asm/88440.s.o(.bss);
        build/asm/88460.s.o(.bss);
        build/asm/88710.s.o(.bss);
        build/asm/88830.s.o(.bss);
        build/asm/88CE0.s.o(.bss);
        build/asm/88D50.s.o(.bss);
        build/asm/890B0.s.o(.bss);
        build/asm/89120.s.o(.bss);
        build/asm/89510.s.o(.bss);
        build/asm/89FB0.s.o(.bss);
        build/asm/8A350.s.o(.bss);
        build/asm/8A3D0.s.o(.bss);
        build/asm/8A420.s.o(.bss);
        build/asm/8A460.s.o(.bss);
        build/asm/8A4A0.s.o(.bss);
        build/asm/8A4D0.s.o(.bss);
        build/asm/8A580.s.o(.bss);
        build/asm/8A610.s.o(.bss);
        build/asm/8A640.s.o(.bss);
        build/asm/8A670.s.o(.bss);
        build/asm/8A6B0.s.o(.bss);
        build/asm/8A6F0.s.o(.bss);
        build/asm/8A770.s.o(.bss);
        build/asm/8A830.s.o(.bss);
        build/asm/8A860.s.o(.bss);
        build/asm/8A890.s.o(.bss);
        build/asm/8AA90.s.o(.bss);
        build/asm/8AC30.s.o(.bss);
        build/asm/8AC70.s.o(.bss);
        build/asm/8ACD0.s.o(.bss);
        build/asm/8AD20.s.o(.bss);
        build/asm/8ADB0.s.o(.bss);
        build/asm/8AEA0.s.o(.bss);
        build/asm/8AF30.s.o(.bss);
        build/asm/8B030.s.o(.bss);
        build/asm/8B0C0.s.o(.bss);
        build/asm/8B1C0.s.o(.bss);
        build/asm/8B3F0.s.o(.bss);
        build/asm/8B560.s.o(.bss);
        build/asm/8B960.s.o(.bss);
        build/asm/8D730.s.o(.bss);
        build/asm/8D790.s.o(.bss);
        build/asm/8D7F0.s.o(.bss);
        build/asm/8D860.s.o(.bss);
        build/asm/8D8C0.s.o(.bss);
        build/asm/8E050.s.o(.bss);
        build/asm/8E4A0.s.o(.bss);
        build/asm/8E6B0.s.o(.bss);
        build/asm/8EA10.s.o(.bss);
        build/asm/8EFF0.s.o(.bss);
        build/asm/8F320.s.o(.bss);
        build/asm/8F480.s.o(.bss);
        build/asm/8F620.s.o(.bss);
        build/asm/8F760.s.o(.bss);
        build/asm/8F7D0.s.o(.bss);
        build/asm/8F830.s.o(.bss);
        build/asm/8FB20.s.o(.bss);
        _1000_BSS_END = .;
    }
    _1000_ROM_END = 0xA96F0;
    __romPos = 0xA96F0;

    __romPos = 0xA96F0;
    . = __romPos;
    overlays_shared_overlay130_ROM_START = __romPos;
    overlays_shared_overlay130_VRAM = ADDR(.overlays_shared_overlay130);
    .overlays_shared_overlay130 0x800D6B70 : AT(overlays_shared_overlay130_ROM_START) SUBALIGN(16)
    {
        overlays_shared_overlay130_TEXT_START = .;
        build/asm/overlays/shared_overlay130/A96F0.s.o(.text);
        build/asm/overlays/shared_overlay130/AB1C0.s.o(.text);
        build/asm/overlays/shared_overlay130/B3CE0.s.o(.text);
        build/asm/overlays/shared_overlay130/B63A0.s.o(.text);
        build/asm/overlays/shared_overlay130/B7600.s.o(.text);
        build/asm/overlays/shared_overlay130/B88C0.s.o(.text);
        build/asm/overlays/shared_overlay130/B8A20.s.o(.text);
        build/asm/overlays/shared_overlay130/BA4B0.s.o(.text);
        build/asm/overlays/shared_overlay130/BC7A0.s.o(.text);
        build/asm/overlays/shared_overlay130/BD210.s.o(.text);
        overlays_shared_overlay130_TEXT_END = .;
        overlays_shared_overlay130_DATA_START = .;
        overlays_shared_overlay130_BE2A0_bin = .;
        build/assets/overlays/shared_overlay130/BE2A0.bin.o(.data);
        overlays_shared_overlay130_overlays_shared_overlay130_A96F0_s = .;
        build/asm/overlays/shared_overlay130/A96F0.s.o(.data);
        overlays_shared_overlay130_overlays_shared_overlay130_AB1C0_s = .;
        build/asm/overlays/shared_overlay130/AB1C0.s.o(.data);
        overlays_shared_overlay130_overlays_shared_overlay130_B3CE0_s = .;
        build/asm/overlays/shared_overlay130/B3CE0.s.o(.data);
        overlays_shared_overlay130_overlays_shared_overlay130_B63A0_s = .;
        build/asm/overlays/shared_overlay130/B63A0.s.o(.data);
        overlays_shared_overlay130_overlays_shared_overlay130_B7600_s = .;
        build/asm/overlays/shared_overlay130/B7600.s.o(.data);
        overlays_shared_overlay130_overlays_shared_overlay130_B88C0_s = .;
        build/asm/overlays/shared_overlay130/B88C0.s.o(.data);
        overlays_shared_overlay130_overlays_shared_overlay130_B8A20_s = .;
        build/asm/overlays/shared_overlay130/B8A20.s.o(.data);
        overlays_shared_overlay130_overlays_shared_overlay130_BA4B0_s = .;
        build/asm/overlays/shared_overlay130/BA4B0.s.o(.data);
        overlays_shared_overlay130_overlays_shared_overlay130_BC7A0_s = .;
        build/asm/overlays/shared_overlay130/BC7A0.s.o(.data);
        overlays_shared_overlay130_overlays_shared_overlay130_BD210_s = .;
        build/asm/overlays/shared_overlay130/BD210.s.o(.data);
        build/asm/overlays/shared_overlay130/A96F0.s.o(.rodata);
        build/asm/overlays/shared_overlay130/AB1C0.s.o(.rodata);
        build/asm/overlays/shared_overlay130/B3CE0.s.o(.rodata);
        build/asm/overlays/shared_overlay130/B63A0.s.o(.rodata);
        build/asm/overlays/shared_overlay130/B7600.s.o(.rodata);
        build/asm/overlays/shared_overlay130/B88C0.s.o(.rodata);
        build/asm/overlays/shared_overlay130/B8A20.s.o(.rodata);
        build/asm/overlays/shared_overlay130/BA4B0.s.o(.rodata);
        build/asm/overlays/shared_overlay130/BC7A0.s.o(.rodata);
        build/asm/overlays/shared_overlay130/BD210.s.o(.rodata);
        overlays_shared_overlay130_DATA_END = .;
        overlays_shared_overlay130_BSS_START = .;
        build/asm/overlays/shared_overlay130/A96F0.s.o(.bss);
        build/asm/overlays/shared_overlay130/AB1C0.s.o(.bss);
        build/asm/overlays/shared_overlay130/B3CE0.s.o(.bss);
        build/asm/overlays/shared_overlay130/B63A0.s.o(.bss);
        build/asm/overlays/shared_overlay130/B7600.s.o(.bss);
        build/asm/overlays/shared_overlay130/B88C0.s.o(.bss);
        build/asm/overlays/shared_overlay130/B8A20.s.o(.bss);
        build/asm/overlays/shared_overlay130/BA4B0.s.o(.bss);
        build/asm/overlays/shared_overlay130/BC7A0.s.o(.bss);
        build/asm/overlays/shared_overlay130/BD210.s.o(.bss);
        overlays_shared_overlay130_BSS_END = .;
    }
    overlays_shared_overlay130_ROM_END = 0xBE940;
    __romPos = 0xBE940;

    __romPos = 0xBE940;
    . = __romPos;
    overlays_shared_overlay129_ROM_START = __romPos;
    overlays_shared_overlay129_VRAM = ADDR(.overlays_shared_overlay129);
    .overlays_shared_overlay129 0x800D6B70 : AT(overlays_shared_overlay129_ROM_START) SUBALIGN(16)
    {
        overlays_shared_overlay129_TEXT_START = .;
        build/asm/overlays/shared_overlay129/BE940.s.o(.text);
        build/asm/overlays/shared_overlay129/BF4A0.s.o(.text);
        build/asm/overlays/shared_overlay129/BFB40.s.o(.text);
        build/asm/overlays/shared_overlay129/C1580.s.o(.text);
        build/asm/overlays/shared_overlay129/C1BA0.s.o(.text);
        build/asm/overlays/shared_overlay129/C1D60.s.o(.text);
        build/asm/overlays/shared_overlay129/C4430.s.o(.text);
        build/asm/overlays/shared_overlay129/C45D0.s.o(.text);
        build/asm/overlays/shared_overlay129/C5770.s.o(.text);
        build/asm/overlays/shared_overlay129/C9330.s.o(.text);
        build/asm/overlays/shared_overlay129/C9690.s.o(.text);
        build/asm/overlays/shared_overlay129/CA640.s.o(.text);
        build/asm/overlays/shared_overlay129/CCD20.s.o(.text);
        build/asm/overlays/shared_overlay129/D1190.s.o(.text);
        build/asm/overlays/shared_overlay129/D28F0.s.o(.text);
        build/asm/overlays/shared_overlay129/D3450.s.o(.text);
        build/asm/overlays/shared_overlay129/D5B20.s.o(.text);
        build/asm/overlays/shared_overlay129/DBE50.s.o(.text);
        build/asm/overlays/shared_overlay129/DC0D0.s.o(.text);
        build/asm/overlays/shared_overlay129/DC4E0.s.o(.text);
        build/asm/overlays/shared_overlay129/DFD60.s.o(.text);
        build/asm/overlays/shared_overlay129/E3CD0.s.o(.text);
        build/asm/overlays/shared_overlay129/E78B0.s.o(.text);
        build/asm/overlays/shared_overlay129/E7AE0.s.o(.text);
        overlays_shared_overlay129_TEXT_END = .;
        overlays_shared_overlay129_DATA_START = .;
        overlays_shared_overlay129_E8BE0_bin = .;
        build/assets/overlays/shared_overlay129/E8BE0.bin.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_BE940_s = .;
        build/asm/overlays/shared_overlay129/BE940.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_BF4A0_s = .;
        build/asm/overlays/shared_overlay129/BF4A0.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_BFB40_s = .;
        build/asm/overlays/shared_overlay129/BFB40.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_C1580_s = .;
        build/asm/overlays/shared_overlay129/C1580.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_C1BA0_s = .;
        build/asm/overlays/shared_overlay129/C1BA0.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_C1D60_s = .;
        build/asm/overlays/shared_overlay129/C1D60.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_C4430_s = .;
        build/asm/overlays/shared_overlay129/C4430.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_C45D0_s = .;
        build/asm/overlays/shared_overlay129/C45D0.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_C5770_s = .;
        build/asm/overlays/shared_overlay129/C5770.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_C9330_s = .;
        build/asm/overlays/shared_overlay129/C9330.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_C9690_s = .;
        build/asm/overlays/shared_overlay129/C9690.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_CA640_s = .;
        build/asm/overlays/shared_overlay129/CA640.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_CCD20_s = .;
        build/asm/overlays/shared_overlay129/CCD20.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_D1190_s = .;
        build/asm/overlays/shared_overlay129/D1190.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_D28F0_s = .;
        build/asm/overlays/shared_overlay129/D28F0.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_D3450_s = .;
        build/asm/overlays/shared_overlay129/D3450.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_D5B20_s = .;
        build/asm/overlays/shared_overlay129/D5B20.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_DBE50_s = .;
        build/asm/overlays/shared_overlay129/DBE50.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_DC0D0_s = .;
        build/asm/overlays/shared_overlay129/DC0D0.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_DC4E0_s = .;
        build/asm/overlays/shared_overlay129/DC4E0.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_DFD60_s = .;
        build/asm/overlays/shared_overlay129/DFD60.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_E3CD0_s = .;
        build/asm/overlays/shared_overlay129/E3CD0.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_E78B0_s = .;
        build/asm/overlays/shared_overlay129/E78B0.s.o(.data);
        overlays_shared_overlay129_overlays_shared_overlay129_E7AE0_s = .;
        build/asm/overlays/shared_overlay129/E7AE0.s.o(.data);
        build/asm/overlays/shared_overlay129/BE940.s.o(.rodata);
        build/asm/overlays/shared_overlay129/BF4A0.s.o(.rodata);
        build/asm/overlays/shared_overlay129/BFB40.s.o(.rodata);
        build/asm/overlays/shared_overlay129/C1580.s.o(.rodata);
        build/asm/overlays/shared_overlay129/C1BA0.s.o(.rodata);
        build/asm/overlays/shared_overlay129/C1D60.s.o(.rodata);
        build/asm/overlays/shared_overlay129/C4430.s.o(.rodata);
        build/asm/overlays/shared_overlay129/C45D0.s.o(.rodata);
        build/asm/overlays/shared_overlay129/C5770.s.o(.rodata);
        build/asm/overlays/shared_overlay129/C9330.s.o(.rodata);
        build/asm/overlays/shared_overlay129/C9690.s.o(.rodata);
        build/asm/overlays/shared_overlay129/CA640.s.o(.rodata);
        build/asm/overlays/shared_overlay129/CCD20.s.o(.rodata);
        build/asm/overlays/shared_overlay129/D1190.s.o(.rodata);
        build/asm/overlays/shared_overlay129/D28F0.s.o(.rodata);
        build/asm/overlays/shared_overlay129/D3450.s.o(.rodata);
        build/asm/overlays/shared_overlay129/D5B20.s.o(.rodata);
        build/asm/overlays/shared_overlay129/DBE50.s.o(.rodata);
        build/asm/overlays/shared_overlay129/DC0D0.s.o(.rodata);
        build/asm/overlays/shared_overlay129/DC4E0.s.o(.rodata);
        build/asm/overlays/shared_overlay129/DFD60.s.o(.rodata);
        build/asm/overlays/shared_overlay129/E3CD0.s.o(.rodata);
        build/asm/overlays/shared_overlay129/E78B0.s.o(.rodata);
        build/asm/overlays/shared_overlay129/E7AE0.s.o(.rodata);
        overlays_shared_overlay129_DATA_END = .;
        overlays_shared_overlay129_BSS_START = .;
        build/asm/overlays/shared_overlay129/BE940.s.o(.bss);
        build/asm/overlays/shared_overlay129/BF4A0.s.o(.bss);
        build/asm/overlays/shared_overlay129/BFB40.s.o(.bss);
        build/asm/overlays/shared_overlay129/C1580.s.o(.bss);
        build/asm/overlays/shared_overlay129/C1BA0.s.o(.bss);
        build/asm/overlays/shared_overlay129/C1D60.s.o(.bss);
        build/asm/overlays/shared_overlay129/C4430.s.o(.bss);
        build/asm/overlays/shared_overlay129/C45D0.s.o(.bss);
        build/asm/overlays/shared_overlay129/C5770.s.o(.bss);
        build/asm/overlays/shared_overlay129/C9330.s.o(.bss);
        build/asm/overlays/shared_overlay129/C9690.s.o(.bss);
        build/asm/overlays/shared_overlay129/CA640.s.o(.bss);
        build/asm/overlays/shared_overlay129/CCD20.s.o(.bss);
        build/asm/overlays/shared_overlay129/D1190.s.o(.bss);
        build/asm/overlays/shared_overlay129/D28F0.s.o(.bss);
        build/asm/overlays/shared_overlay129/D3450.s.o(.bss);
        build/asm/overlays/shared_overlay129/D5B20.s.o(.bss);
        build/asm/overlays/shared_overlay129/DBE50.s.o(.bss);
        build/asm/overlays/shared_overlay129/DC0D0.s.o(.bss);
        build/asm/overlays/shared_overlay129/DC4E0.s.o(.bss);
        build/asm/overlays/shared_overlay129/DFD60.s.o(.bss);
        build/asm/overlays/shared_overlay129/E3CD0.s.o(.bss);
        build/asm/overlays/shared_overlay129/E78B0.s.o(.bss);
        build/asm/overlays/shared_overlay129/E7AE0.s.o(.bss);
        overlays_shared_overlay129_BSS_END = .;
    }
    overlays_shared_overlay129_ROM_END = 0xEA790;
    __romPos = 0xEA790;

    __romPos = 0xEA790;
    . = __romPos;
    overlays_shared_board_ROM_START = __romPos;
    overlays_shared_board_VRAM = ADDR(.overlays_shared_board);
    .overlays_shared_board 0x800D6B70 : AT(overlays_shared_board_ROM_START) SUBALIGN(16)
    {
        overlays_shared_board_TEXT_START = .;
        build/asm/overlays/shared_board/EA790.s.o(.text);
        build/asm/overlays/shared_board/EB2F0.s.o(.text);
        build/asm/overlays/shared_board/EC3B0.s.o(.text);
        build/asm/overlays/shared_board/ECA50.s.o(.text);
        build/asm/overlays/shared_board/EE3B0.s.o(.text);
        build/asm/overlays/shared_board/EE660.s.o(.text);
        build/asm/overlays/shared_board/F2910.s.o(.text);
        build/asm/overlays/shared_board/F5070.s.o(.text);
        build/asm/overlays/shared_board/F5B90.s.o(.text);
        build/asm/overlays/shared_board/FFB10.s.o(.text);
        build/asm/overlays/shared_board/1006F0.s.o(.text);
        build/asm/overlays/shared_board/101840.s.o(.text);
        build/asm/overlays/shared_board/105D50.s.o(.text);
        build/asm/overlays/shared_board/1063F0.s.o(.text);
        build/asm/overlays/shared_board/106640.s.o(.text);
        build/asm/overlays/shared_board/106A50.s.o(.text);
        build/asm/overlays/shared_board/10AD50.s.o(.text);
        build/asm/overlays/shared_board/10C230.s.o(.text);
        build/asm/overlays/shared_board/113520.s.o(.text);
        build/asm/overlays/shared_board/113750.s.o(.text);
        overlays_shared_board_TEXT_END = .;
        overlays_shared_board_DATA_START = .;
        overlays_shared_board_1143C0_bin = .;
        build/assets/overlays/shared_board/1143C0.bin.o(.data);
        overlays_shared_board_overlays_shared_board_EA790_s = .;
        build/asm/overlays/shared_board/EA790.s.o(.data);
        overlays_shared_board_overlays_shared_board_EB2F0_s = .;
        build/asm/overlays/shared_board/EB2F0.s.o(.data);
        overlays_shared_board_overlays_shared_board_EC3B0_s = .;
        build/asm/overlays/shared_board/EC3B0.s.o(.data);
        overlays_shared_board_overlays_shared_board_ECA50_s = .;
        build/asm/overlays/shared_board/ECA50.s.o(.data);
        overlays_shared_board_overlays_shared_board_EE3B0_s = .;
        build/asm/overlays/shared_board/EE3B0.s.o(.data);
        overlays_shared_board_overlays_shared_board_EE660_s = .;
        build/asm/overlays/shared_board/EE660.s.o(.data);
        overlays_shared_board_overlays_shared_board_F2910_s = .;
        build/asm/overlays/shared_board/F2910.s.o(.data);
        overlays_shared_board_overlays_shared_board_F5070_s = .;
        build/asm/overlays/shared_board/F5070.s.o(.data);
        overlays_shared_board_overlays_shared_board_F5B90_s = .;
        build/asm/overlays/shared_board/F5B90.s.o(.data);
        overlays_shared_board_overlays_shared_board_FFB10_s = .;
        build/asm/overlays/shared_board/FFB10.s.o(.data);
        overlays_shared_board_overlays_shared_board_1006F0_s = .;
        build/asm/overlays/shared_board/1006F0.s.o(.data);
        overlays_shared_board_overlays_shared_board_101840_s = .;
        build/asm/overlays/shared_board/101840.s.o(.data);
        overlays_shared_board_overlays_shared_board_105D50_s = .;
        build/asm/overlays/shared_board/105D50.s.o(.data);
        overlays_shared_board_overlays_shared_board_1063F0_s = .;
        build/asm/overlays/shared_board/1063F0.s.o(.data);
        overlays_shared_board_overlays_shared_board_106640_s = .;
        build/asm/overlays/shared_board/106640.s.o(.data);
        overlays_shared_board_overlays_shared_board_106A50_s = .;
        build/asm/overlays/shared_board/106A50.s.o(.data);
        overlays_shared_board_overlays_shared_board_10AD50_s = .;
        build/asm/overlays/shared_board/10AD50.s.o(.data);
        overlays_shared_board_overlays_shared_board_10C230_s = .;
        build/asm/overlays/shared_board/10C230.s.o(.data);
        overlays_shared_board_overlays_shared_board_113520_s = .;
        build/asm/overlays/shared_board/113520.s.o(.data);
        overlays_shared_board_overlays_shared_board_113750_s = .;
        build/asm/overlays/shared_board/113750.s.o(.data);
        build/asm/overlays/shared_board/EA790.s.o(.rodata);
        build/asm/overlays/shared_board/EB2F0.s.o(.rodata);
        build/asm/overlays/shared_board/EC3B0.s.o(.rodata);
        build/asm/overlays/shared_board/ECA50.s.o(.rodata);
        build/asm/overlays/shared_board/EE3B0.s.o(.rodata);
        build/asm/overlays/shared_board/EE660.s.o(.rodata);
        build/asm/overlays/shared_board/F2910.s.o(.rodata);
        build/asm/overlays/shared_board/F5070.s.o(.rodata);
        build/asm/overlays/shared_board/F5B90.s.o(.rodata);
        build/asm/overlays/shared_board/FFB10.s.o(.rodata);
        build/asm/overlays/shared_board/1006F0.s.o(.rodata);
        build/asm/overlays/shared_board/101840.s.o(.rodata);
        build/asm/overlays/shared_board/105D50.s.o(.rodata);
        build/asm/overlays/shared_board/1063F0.s.o(.rodata);
        build/asm/overlays/shared_board/106640.s.o(.rodata);
        build/asm/overlays/shared_board/106A50.s.o(.rodata);
        build/asm/overlays/shared_board/10AD50.s.o(.rodata);
        build/asm/overlays/shared_board/10C230.s.o(.rodata);
        build/asm/overlays/shared_board/113520.s.o(.rodata);
        build/asm/overlays/shared_board/113750.s.o(.rodata);
        overlays_shared_board_DATA_END = .;
        overlays_shared_board_BSS_START = .;
        build/asm/overlays/shared_board/EA790.s.o(.bss);
        build/asm/overlays/shared_board/EB2F0.s.o(.bss);
        build/asm/overlays/shared_board/EC3B0.s.o(.bss);
        build/asm/overlays/shared_board/ECA50.s.o(.bss);
        build/asm/overlays/shared_board/EE3B0.s.o(.bss);
        build/asm/overlays/shared_board/EE660.s.o(.bss);
        build/asm/overlays/shared_board/F2910.s.o(.bss);
        build/asm/overlays/shared_board/F5070.s.o(.bss);
        build/asm/overlays/shared_board/F5B90.s.o(.bss);
        build/asm/overlays/shared_board/FFB10.s.o(.bss);
        build/asm/overlays/shared_board/1006F0.s.o(.bss);
        build/asm/overlays/shared_board/101840.s.o(.bss);
        build/asm/overlays/shared_board/105D50.s.o(.bss);
        build/asm/overlays/shared_board/1063F0.s.o(.bss);
        build/asm/overlays/shared_board/106640.s.o(.bss);
        build/asm/overlays/shared_board/106A50.s.o(.bss);
        build/asm/overlays/shared_board/10AD50.s.o(.bss);
        build/asm/overlays/shared_board/10C230.s.o(.bss);
        build/asm/overlays/shared_board/113520.s.o(.bss);
        build/asm/overlays/shared_board/113750.s.o(.bss);
        overlays_shared_board_BSS_END = .;
    }
    overlays_shared_board_ROM_END = 0x116320;
    __romPos = 0x116320;

    __romPos = 0x116320;
    . = __romPos;
    overlays_test_menu1_ROM_START = __romPos;
    overlays_test_menu1_VRAM = ADDR(.overlays_test_menu1);
    .overlays_test_menu1 0x801059A0 : AT(overlays_test_menu1_ROM_START) SUBALIGN(16)
    {
        overlays_test_menu1_TEXT_START = .;
        build/asm/overlays/test_menu1/116320.s.o(.text);
        overlays_test_menu1_TEXT_END = .;
        overlays_test_menu1_DATA_START = .;
        overlays_test_menu1_119560_bin = .;
        build/assets/overlays/test_menu1/119560.bin.o(.data);
        overlays_test_menu1_overlays_test_menu1_116320_s = .;
        build/asm/overlays/test_menu1/116320.s.o(.data);
        build/asm/overlays/test_menu1/116320.s.o(.rodata);
        overlays_test_menu1_DATA_END = .;
        overlays_test_menu1_BSS_START = .;
        build/asm/overlays/test_menu1/116320.s.o(.bss);
        overlays_test_menu1_BSS_END = .;
    }
    overlays_test_menu1_ROM_END = 0x11A480;
    __romPos = 0x11A480;

    __romPos = 0x11A480;
    . = __romPos;
    overlays_minigames_hand_line_sinker_ROM_START = __romPos;
    overlays_minigames_hand_line_sinker_VRAM = ADDR(.overlays_minigames_hand_line_sinker);
    .overlays_minigames_hand_line_sinker 0x801059A0 : AT(overlays_minigames_hand_line_sinker_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_hand_line_sinker_TEXT_START = .;
        build/asm/overlays/minigames/hand_line_sinker/11A480.s.o(.text);
        build/asm/overlays/minigames/hand_line_sinker/120090.s.o(.text);
        overlays_minigames_hand_line_sinker_TEXT_END = .;
        overlays_minigames_hand_line_sinker_DATA_START = .;
        overlays_minigames_hand_line_sinker_1209E0_bin = .;
        build/assets/overlays/minigames/hand_line_sinker/1209E0.bin.o(.data);
        overlays_minigames_hand_line_sinker_overlays_minigames_hand_line_sinker_11A480_s = .;
        build/asm/overlays/minigames/hand_line_sinker/11A480.s.o(.data);
        overlays_minigames_hand_line_sinker_overlays_minigames_hand_line_sinker_120090_s = .;
        build/asm/overlays/minigames/hand_line_sinker/120090.s.o(.data);
        build/asm/overlays/minigames/hand_line_sinker/11A480.s.o(.rodata);
        build/asm/overlays/minigames/hand_line_sinker/120090.s.o(.rodata);
        overlays_minigames_hand_line_sinker_DATA_END = .;
        overlays_minigames_hand_line_sinker_BSS_START = .;
        build/asm/overlays/minigames/hand_line_sinker/11A480.s.o(.bss);
        build/asm/overlays/minigames/hand_line_sinker/120090.s.o(.bss);
        overlays_minigames_hand_line_sinker_BSS_END = .;
    }
    overlays_minigames_hand_line_sinker_ROM_END = 0x120BC0;
    __romPos = 0x120BC0;

    __romPos = 0x120BC0;
    . = __romPos;
    overlays_minigames_coconut_conk_ROM_START = __romPos;
    overlays_minigames_coconut_conk_VRAM = ADDR(.overlays_minigames_coconut_conk);
    .overlays_minigames_coconut_conk 0x801059A0 : AT(overlays_minigames_coconut_conk_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_coconut_conk_TEXT_START = .;
        build/asm/overlays/minigames/coconut_conk/120BC0.s.o(.text);
        overlays_minigames_coconut_conk_TEXT_END = .;
        overlays_minigames_coconut_conk_DATA_START = .;
        overlays_minigames_coconut_conk_126180_bin = .;
        build/assets/overlays/minigames/coconut_conk/126180.bin.o(.data);
        overlays_minigames_coconut_conk_overlays_minigames_coconut_conk_120BC0_s = .;
        build/asm/overlays/minigames/coconut_conk/120BC0.s.o(.data);
        build/asm/overlays/minigames/coconut_conk/120BC0.s.o(.rodata);
        overlays_minigames_coconut_conk_DATA_END = .;
        overlays_minigames_coconut_conk_BSS_START = .;
        build/asm/overlays/minigames/coconut_conk/120BC0.s.o(.bss);
        overlays_minigames_coconut_conk_BSS_END = .;
    }
    overlays_minigames_coconut_conk_ROM_END = 0x1263E0;
    __romPos = 0x1263E0;

    __romPos = 0x1263E0;
    . = __romPos;
    overlays_minigames_spotlight_swim_ROM_START = __romPos;
    overlays_minigames_spotlight_swim_VRAM = ADDR(.overlays_minigames_spotlight_swim);
    .overlays_minigames_spotlight_swim 0x801059A0 : AT(overlays_minigames_spotlight_swim_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_spotlight_swim_TEXT_START = .;
        build/asm/overlays/minigames/spotlight_swim/1263E0.s.o(.text);
        overlays_minigames_spotlight_swim_TEXT_END = .;
        overlays_minigames_spotlight_swim_DATA_START = .;
        overlays_minigames_spotlight_swim_12D700_bin = .;
        build/assets/overlays/minigames/spotlight_swim/12D700.bin.o(.data);
        overlays_minigames_spotlight_swim_overlays_minigames_spotlight_swim_1263E0_s = .;
        build/asm/overlays/minigames/spotlight_swim/1263E0.s.o(.data);
        build/asm/overlays/minigames/spotlight_swim/1263E0.s.o(.rodata);
        overlays_minigames_spotlight_swim_DATA_END = .;
        overlays_minigames_spotlight_swim_BSS_START = .;
        build/asm/overlays/minigames/spotlight_swim/1263E0.s.o(.bss);
        overlays_minigames_spotlight_swim_BSS_END = .;
    }
    overlays_minigames_spotlight_swim_ROM_END = 0x12DD30;
    __romPos = 0x12DD30;

    __romPos = 0x12DD30;
    . = __romPos;
    overlays_minigames_boulder_ball_ROM_START = __romPos;
    overlays_minigames_boulder_ball_VRAM = ADDR(.overlays_minigames_boulder_ball);
    .overlays_minigames_boulder_ball 0x801059A0 : AT(overlays_minigames_boulder_ball_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_boulder_ball_TEXT_START = .;
        build/asm/overlays/minigames/boulder_ball/12DD30.s.o(.text);
        overlays_minigames_boulder_ball_TEXT_END = .;
        overlays_minigames_boulder_ball_DATA_START = .;
        overlays_minigames_boulder_ball_131A90_bin = .;
        build/assets/overlays/minigames/boulder_ball/131A90.bin.o(.data);
        overlays_minigames_boulder_ball_overlays_minigames_boulder_ball_12DD30_s = .;
        build/asm/overlays/minigames/boulder_ball/12DD30.s.o(.data);
        build/asm/overlays/minigames/boulder_ball/12DD30.s.o(.rodata);
        overlays_minigames_boulder_ball_DATA_END = .;
        overlays_minigames_boulder_ball_BSS_START = .;
        build/asm/overlays/minigames/boulder_ball/12DD30.s.o(.bss);
        overlays_minigames_boulder_ball_BSS_END = .;
    }
    overlays_minigames_boulder_ball_ROM_END = 0x131C10;
    __romPos = 0x131C10;

    __romPos = 0x131C10;
    . = __romPos;
    overlays_minigames_crazy_cogs_ROM_START = __romPos;
    overlays_minigames_crazy_cogs_VRAM = ADDR(.overlays_minigames_crazy_cogs);
    .overlays_minigames_crazy_cogs 0x801059A0 : AT(overlays_minigames_crazy_cogs_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_crazy_cogs_TEXT_START = .;
        build/asm/overlays/minigames/crazy_cogs/131C10.s.o(.text);
        overlays_minigames_crazy_cogs_TEXT_END = .;
        overlays_minigames_crazy_cogs_DATA_START = .;
        overlays_minigames_crazy_cogs_137A80_bin = .;
        build/assets/overlays/minigames/crazy_cogs/137A80.bin.o(.data);
        overlays_minigames_crazy_cogs_overlays_minigames_crazy_cogs_131C10_s = .;
        build/asm/overlays/minigames/crazy_cogs/131C10.s.o(.data);
        build/asm/overlays/minigames/crazy_cogs/131C10.s.o(.rodata);
        overlays_minigames_crazy_cogs_DATA_END = .;
        overlays_minigames_crazy_cogs_BSS_START = .;
        build/asm/overlays/minigames/crazy_cogs/131C10.s.o(.bss);
        overlays_minigames_crazy_cogs_BSS_END = .;
    }
    overlays_minigames_crazy_cogs_ROM_END = 0x137C00;
    __romPos = 0x137C00;

    __romPos = 0x137C00;
    . = __romPos;
    overlays_minigames_hide_and_sneak_ROM_START = __romPos;
    overlays_minigames_hide_and_sneak_VRAM = ADDR(.overlays_minigames_hide_and_sneak);
    .overlays_minigames_hide_and_sneak 0x801059A0 : AT(overlays_minigames_hide_and_sneak_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_hide_and_sneak_TEXT_START = .;
        build/asm/overlays/minigames/hide_and_sneak/137C00.s.o(.text);
        overlays_minigames_hide_and_sneak_TEXT_END = .;
        overlays_minigames_hide_and_sneak_DATA_START = .;
        overlays_minigames_hide_and_sneak_13E5D0_bin = .;
        build/assets/overlays/minigames/hide_and_sneak/13E5D0.bin.o(.data);
        overlays_minigames_hide_and_sneak_overlays_minigames_hide_and_sneak_137C00_s = .;
        build/asm/overlays/minigames/hide_and_sneak/137C00.s.o(.data);
        build/asm/overlays/minigames/hide_and_sneak/137C00.s.o(.rodata);
        overlays_minigames_hide_and_sneak_DATA_END = .;
        overlays_minigames_hide_and_sneak_BSS_START = .;
        build/asm/overlays/minigames/hide_and_sneak/137C00.s.o(.bss);
        overlays_minigames_hide_and_sneak_BSS_END = .;
    }
    overlays_minigames_hide_and_sneak_ROM_END = 0x13E9C0;
    __romPos = 0x13E9C0;

    __romPos = 0x13E9C0;
    . = __romPos;
    overlays_minigames_ridiculous_relay_ROM_START = __romPos;
    overlays_minigames_ridiculous_relay_VRAM = ADDR(.overlays_minigames_ridiculous_relay);
    .overlays_minigames_ridiculous_relay 0x801059A0 : AT(overlays_minigames_ridiculous_relay_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_ridiculous_relay_TEXT_START = .;
        build/asm/overlays/minigames/ridiculous_relay/13E9C0.s.o(.text);
        overlays_minigames_ridiculous_relay_TEXT_END = .;
        overlays_minigames_ridiculous_relay_DATA_START = .;
        overlays_minigames_ridiculous_relay_149CD0_bin = .;
        build/assets/overlays/minigames/ridiculous_relay/149CD0.bin.o(.data);
        overlays_minigames_ridiculous_relay_overlays_minigames_ridiculous_relay_13E9C0_s = .;
        build/asm/overlays/minigames/ridiculous_relay/13E9C0.s.o(.data);
        build/asm/overlays/minigames/ridiculous_relay/13E9C0.s.o(.rodata);
        overlays_minigames_ridiculous_relay_DATA_END = .;
        overlays_minigames_ridiculous_relay_BSS_START = .;
        build/asm/overlays/minigames/ridiculous_relay/13E9C0.s.o(.bss);
        overlays_minigames_ridiculous_relay_BSS_END = .;
    }
    overlays_minigames_ridiculous_relay_ROM_END = 0x14A810;
    __romPos = 0x14A810;

    __romPos = 0x14A810;
    . = __romPos;
    overlays_minigames_thwomp_pull_ROM_START = __romPos;
    overlays_minigames_thwomp_pull_VRAM = ADDR(.overlays_minigames_thwomp_pull);
    .overlays_minigames_thwomp_pull 0x801059A0 : AT(overlays_minigames_thwomp_pull_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_thwomp_pull_TEXT_START = .;
        build/asm/overlays/minigames/thwomp_pull/14A810.s.o(.text);
        overlays_minigames_thwomp_pull_TEXT_END = .;
        overlays_minigames_thwomp_pull_DATA_START = .;
        overlays_minigames_thwomp_pull_153BD0_bin = .;
        build/assets/overlays/minigames/thwomp_pull/153BD0.bin.o(.data);
        overlays_minigames_thwomp_pull_overlays_minigames_thwomp_pull_14A810_s = .;
        build/asm/overlays/minigames/thwomp_pull/14A810.s.o(.data);
        build/asm/overlays/minigames/thwomp_pull/14A810.s.o(.rodata);
        overlays_minigames_thwomp_pull_DATA_END = .;
        overlays_minigames_thwomp_pull_BSS_START = .;
        build/asm/overlays/minigames/thwomp_pull/14A810.s.o(.bss);
        overlays_minigames_thwomp_pull_BSS_END = .;
    }
    overlays_minigames_thwomp_pull_ROM_END = 0x1542E0;
    __romPos = 0x1542E0;

    __romPos = 0x1542E0;
    . = __romPos;
    overlays_minigames_river_raiders_ROM_START = __romPos;
    overlays_minigames_river_raiders_VRAM = ADDR(.overlays_minigames_river_raiders);
    .overlays_minigames_river_raiders 0x801059A0 : AT(overlays_minigames_river_raiders_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_river_raiders_TEXT_START = .;
        build/asm/overlays/minigames/river_raiders/1542E0.s.o(.text);
        overlays_minigames_river_raiders_TEXT_END = .;
        overlays_minigames_river_raiders_DATA_START = .;
        overlays_minigames_river_raiders_15BCF0_bin = .;
        build/assets/overlays/minigames/river_raiders/15BCF0.bin.o(.data);
        overlays_minigames_river_raiders_overlays_minigames_river_raiders_1542E0_s = .;
        build/asm/overlays/minigames/river_raiders/1542E0.s.o(.data);
        build/asm/overlays/minigames/river_raiders/1542E0.s.o(.rodata);
        overlays_minigames_river_raiders_DATA_END = .;
        overlays_minigames_river_raiders_BSS_START = .;
        build/asm/overlays/minigames/river_raiders/1542E0.s.o(.bss);
        overlays_minigames_river_raiders_BSS_END = .;
    }
    overlays_minigames_river_raiders_ROM_END = 0x15C310;
    __romPos = 0x15C310;

    __romPos = 0x15C310;
    . = __romPos;
    overlays_minigames_tidal_toss_ROM_START = __romPos;
    overlays_minigames_tidal_toss_VRAM = ADDR(.overlays_minigames_tidal_toss);
    .overlays_minigames_tidal_toss 0x801059A0 : AT(overlays_minigames_tidal_toss_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_tidal_toss_TEXT_START = .;
        build/asm/overlays/minigames/tidal_toss/15C310.s.o(.text);
        overlays_minigames_tidal_toss_TEXT_END = .;
        overlays_minigames_tidal_toss_DATA_START = .;
        overlays_minigames_tidal_toss_1613E0_bin = .;
        build/assets/overlays/minigames/tidal_toss/1613E0.bin.o(.data);
        overlays_minigames_tidal_toss_overlays_minigames_tidal_toss_15C310_s = .;
        build/asm/overlays/minigames/tidal_toss/15C310.s.o(.data);
        build/asm/overlays/minigames/tidal_toss/15C310.s.o(.rodata);
        overlays_minigames_tidal_toss_DATA_END = .;
        overlays_minigames_tidal_toss_BSS_START = .;
        build/asm/overlays/minigames/tidal_toss/15C310.s.o(.bss);
        overlays_minigames_tidal_toss_BSS_END = .;
    }
    overlays_minigames_tidal_toss_ROM_END = 0x161750;
    __romPos = 0x161750;

    __romPos = 0x161750;
    . = __romPos;
    overlays_minigames_eatsa_pizza_ROM_START = __romPos;
    overlays_minigames_eatsa_pizza_VRAM = ADDR(.overlays_minigames_eatsa_pizza);
    .overlays_minigames_eatsa_pizza 0x801059A0 : AT(overlays_minigames_eatsa_pizza_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_eatsa_pizza_TEXT_START = .;
        build/asm/overlays/minigames/eatsa_pizza/161750.s.o(.text);
        overlays_minigames_eatsa_pizza_TEXT_END = .;
        overlays_minigames_eatsa_pizza_DATA_START = .;
        overlays_minigames_eatsa_pizza_164EB0_bin = .;
        build/assets/overlays/minigames/eatsa_pizza/164EB0.bin.o(.data);
        overlays_minigames_eatsa_pizza_overlays_minigames_eatsa_pizza_161750_s = .;
        build/asm/overlays/minigames/eatsa_pizza/161750.s.o(.data);
        build/asm/overlays/minigames/eatsa_pizza/161750.s.o(.rodata);
        overlays_minigames_eatsa_pizza_DATA_END = .;
        overlays_minigames_eatsa_pizza_BSS_START = .;
        build/asm/overlays/minigames/eatsa_pizza/161750.s.o(.bss);
        overlays_minigames_eatsa_pizza_BSS_END = .;
    }
    overlays_minigames_eatsa_pizza_ROM_END = 0x165010;
    __romPos = 0x165010;

    __romPos = 0x165010;
    . = __romPos;
    overlays_minigames_baby_bowser_broadside_ROM_START = __romPos;
    overlays_minigames_baby_bowser_broadside_VRAM = ADDR(.overlays_minigames_baby_bowser_broadside);
    .overlays_minigames_baby_bowser_broadside 0x801059A0 : AT(overlays_minigames_baby_bowser_broadside_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_baby_bowser_broadside_TEXT_START = .;
        build/asm/overlays/minigames/baby_bowser_broadside/165010.s.o(.text);
        build/asm/overlays/minigames/baby_bowser_broadside/169540.s.o(.text);
        overlays_minigames_baby_bowser_broadside_TEXT_END = .;
        overlays_minigames_baby_bowser_broadside_DATA_START = .;
        overlays_minigames_baby_bowser_broadside_16F3D0_bin = .;
        build/assets/overlays/minigames/baby_bowser_broadside/16F3D0.bin.o(.data);
        overlays_minigames_baby_bowser_broadside_overlays_minigames_baby_bowser_broadside_165010_s = .;
        build/asm/overlays/minigames/baby_bowser_broadside/165010.s.o(.data);
        overlays_minigames_baby_bowser_broadside_overlays_minigames_baby_bowser_broadside_169540_s = .;
        build/asm/overlays/minigames/baby_bowser_broadside/169540.s.o(.data);
        build/asm/overlays/minigames/baby_bowser_broadside/165010.s.o(.rodata);
        build/asm/overlays/minigames/baby_bowser_broadside/169540.s.o(.rodata);
        overlays_minigames_baby_bowser_broadside_DATA_END = .;
        overlays_minigames_baby_bowser_broadside_BSS_START = .;
        build/asm/overlays/minigames/baby_bowser_broadside/165010.s.o(.bss);
        build/asm/overlays/minigames/baby_bowser_broadside/169540.s.o(.bss);
        overlays_minigames_baby_bowser_broadside_BSS_END = .;
    }
    overlays_minigames_baby_bowser_broadside_ROM_END = 0x16F670;
    __romPos = 0x16F670;

    __romPos = 0x16F670;
    . = __romPos;
    overlays_minigames_pump_pump_away_ROM_START = __romPos;
    overlays_minigames_pump_pump_away_VRAM = ADDR(.overlays_minigames_pump_pump_away);
    .overlays_minigames_pump_pump_away 0x801059A0 : AT(overlays_minigames_pump_pump_away_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_pump_pump_away_TEXT_START = .;
        build/asm/overlays/minigames/pump_pump_away/16F670.s.o(.text);
        overlays_minigames_pump_pump_away_TEXT_END = .;
        overlays_minigames_pump_pump_away_DATA_START = .;
        overlays_minigames_pump_pump_away_17AB40_bin = .;
        build/assets/overlays/minigames/pump_pump_away/17AB40.bin.o(.data);
        overlays_minigames_pump_pump_away_overlays_minigames_pump_pump_away_16F670_s = .;
        build/asm/overlays/minigames/pump_pump_away/16F670.s.o(.data);
        build/asm/overlays/minigames/pump_pump_away/16F670.s.o(.rodata);
        overlays_minigames_pump_pump_away_DATA_END = .;
        overlays_minigames_pump_pump_away_BSS_START = .;
        build/asm/overlays/minigames/pump_pump_away/16F670.s.o(.bss);
        overlays_minigames_pump_pump_away_BSS_END = .;
    }
    overlays_minigames_pump_pump_away_ROM_END = 0x17B3B0;
    __romPos = 0x17B3B0;

    __romPos = 0x17B3B0;
    . = __romPos;
    overlays_minigames_hyper_hydrants_ROM_START = __romPos;
    overlays_minigames_hyper_hydrants_VRAM = ADDR(.overlays_minigames_hyper_hydrants);
    .overlays_minigames_hyper_hydrants 0x801059A0 : AT(overlays_minigames_hyper_hydrants_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_hyper_hydrants_TEXT_START = .;
        build/asm/overlays/minigames/hyper_hydrants/17B3B0.s.o(.text);
        overlays_minigames_hyper_hydrants_TEXT_END = .;
        overlays_minigames_hyper_hydrants_DATA_START = .;
        overlays_minigames_hyper_hydrants_1817F0_bin = .;
        build/assets/overlays/minigames/hyper_hydrants/1817F0.bin.o(.data);
        overlays_minigames_hyper_hydrants_overlays_minigames_hyper_hydrants_17B3B0_s = .;
        build/asm/overlays/minigames/hyper_hydrants/17B3B0.s.o(.data);
        build/asm/overlays/minigames/hyper_hydrants/17B3B0.s.o(.rodata);
        overlays_minigames_hyper_hydrants_DATA_END = .;
        overlays_minigames_hyper_hydrants_BSS_START = .;
        build/asm/overlays/minigames/hyper_hydrants/17B3B0.s.o(.bss);
        overlays_minigames_hyper_hydrants_BSS_END = .;
    }
    overlays_minigames_hyper_hydrants_ROM_END = 0x181950;
    __romPos = 0x181950;

    __romPos = 0x181950;
    . = __romPos;
    overlays_minigames_picking_panic_ROM_START = __romPos;
    overlays_minigames_picking_panic_VRAM = ADDR(.overlays_minigames_picking_panic);
    .overlays_minigames_picking_panic 0x801059A0 : AT(overlays_minigames_picking_panic_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_picking_panic_TEXT_START = .;
        build/asm/overlays/minigames/picking_panic/181950.s.o(.text);
        overlays_minigames_picking_panic_TEXT_END = .;
        overlays_minigames_picking_panic_DATA_START = .;
        overlays_minigames_picking_panic_18A560_bin = .;
        build/assets/overlays/minigames/picking_panic/18A560.bin.o(.data);
        overlays_minigames_picking_panic_overlays_minigames_picking_panic_181950_s = .;
        build/asm/overlays/minigames/picking_panic/181950.s.o(.data);
        build/asm/overlays/minigames/picking_panic/181950.s.o(.rodata);
        overlays_minigames_picking_panic_DATA_END = .;
        overlays_minigames_picking_panic_BSS_START = .;
        build/asm/overlays/minigames/picking_panic/181950.s.o(.bss);
        overlays_minigames_picking_panic_BSS_END = .;
    }
    overlays_minigames_picking_panic_ROM_END = 0x18ABD0;
    __romPos = 0x18ABD0;

    __romPos = 0x18ABD0;
    . = __romPos;
    overlays_minigames_cosmic_coaster_ROM_START = __romPos;
    overlays_minigames_cosmic_coaster_VRAM = ADDR(.overlays_minigames_cosmic_coaster);
    .overlays_minigames_cosmic_coaster 0x801059A0 : AT(overlays_minigames_cosmic_coaster_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_cosmic_coaster_TEXT_START = .;
        build/asm/overlays/minigames/cosmic_coaster/18ABD0.s.o(.text);
        build/asm/overlays/minigames/cosmic_coaster/18EB30.s.o(.text);
        overlays_minigames_cosmic_coaster_TEXT_END = .;
        overlays_minigames_cosmic_coaster_DATA_START = .;
        overlays_minigames_cosmic_coaster_190D60_bin = .;
        build/assets/overlays/minigames/cosmic_coaster/190D60.bin.o(.data);
        overlays_minigames_cosmic_coaster_overlays_minigames_cosmic_coaster_18ABD0_s = .;
        build/asm/overlays/minigames/cosmic_coaster/18ABD0.s.o(.data);
        overlays_minigames_cosmic_coaster_overlays_minigames_cosmic_coaster_18EB30_s = .;
        build/asm/overlays/minigames/cosmic_coaster/18EB30.s.o(.data);
        build/asm/overlays/minigames/cosmic_coaster/18ABD0.s.o(.rodata);
        build/asm/overlays/minigames/cosmic_coaster/18EB30.s.o(.rodata);
        overlays_minigames_cosmic_coaster_DATA_END = .;
        overlays_minigames_cosmic_coaster_BSS_START = .;
        build/asm/overlays/minigames/cosmic_coaster/18ABD0.s.o(.bss);
        build/asm/overlays/minigames/cosmic_coaster/18EB30.s.o(.bss);
        overlays_minigames_cosmic_coaster_BSS_END = .;
    }
    overlays_minigames_cosmic_coaster_ROM_END = 0x191240;
    __romPos = 0x191240;

    __romPos = 0x191240;
    . = __romPos;
    overlays_minigames_puddle_paddle_ROM_START = __romPos;
    overlays_minigames_puddle_paddle_VRAM = ADDR(.overlays_minigames_puddle_paddle);
    .overlays_minigames_puddle_paddle 0x801059A0 : AT(overlays_minigames_puddle_paddle_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_puddle_paddle_TEXT_START = .;
        build/asm/overlays/minigames/puddle_paddle/191240.s.o(.text);
        overlays_minigames_puddle_paddle_TEXT_END = .;
        overlays_minigames_puddle_paddle_DATA_START = .;
        overlays_minigames_puddle_paddle_19CAC0_bin = .;
        build/assets/overlays/minigames/puddle_paddle/19CAC0.bin.o(.data);
        overlays_minigames_puddle_paddle_overlays_minigames_puddle_paddle_191240_s = .;
        build/asm/overlays/minigames/puddle_paddle/191240.s.o(.data);
        build/asm/overlays/minigames/puddle_paddle/191240.s.o(.rodata);
        overlays_minigames_puddle_paddle_DATA_END = .;
        overlays_minigames_puddle_paddle_BSS_START = .;
        build/asm/overlays/minigames/puddle_paddle/191240.s.o(.bss);
        overlays_minigames_puddle_paddle_BSS_END = .;
    }
    overlays_minigames_puddle_paddle_ROM_END = 0x19CEF0;
    __romPos = 0x19CEF0;

    __romPos = 0x19CEF0;
    . = __romPos;
    overlays_minigames_etch_n_catch_ROM_START = __romPos;
    overlays_minigames_etch_n_catch_VRAM = ADDR(.overlays_minigames_etch_n_catch);
    .overlays_minigames_etch_n_catch 0x801059A0 : AT(overlays_minigames_etch_n_catch_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_etch_n_catch_TEXT_START = .;
        build/asm/overlays/minigames/etch_n_catch/19CEF0.s.o(.text);
        overlays_minigames_etch_n_catch_TEXT_END = .;
        overlays_minigames_etch_n_catch_DATA_START = .;
        overlays_minigames_etch_n_catch_1A3BF0_bin = .;
        build/assets/overlays/minigames/etch_n_catch/1A3BF0.bin.o(.data);
        overlays_minigames_etch_n_catch_overlays_minigames_etch_n_catch_19CEF0_s = .;
        build/asm/overlays/minigames/etch_n_catch/19CEF0.s.o(.data);
        build/asm/overlays/minigames/etch_n_catch/19CEF0.s.o(.rodata);
        overlays_minigames_etch_n_catch_DATA_END = .;
        overlays_minigames_etch_n_catch_BSS_START = .;
        build/asm/overlays/minigames/etch_n_catch/19CEF0.s.o(.bss);
        overlays_minigames_etch_n_catch_BSS_END = .;
    }
    overlays_minigames_etch_n_catch_ROM_END = 0x1A3D80;
    __romPos = 0x1A3D80;

    __romPos = 0x1A3D80;
    . = __romPos;
    overlays_minigames_log_jam_ROM_START = __romPos;
    overlays_minigames_log_jam_VRAM = ADDR(.overlays_minigames_log_jam);
    .overlays_minigames_log_jam 0x801059A0 : AT(overlays_minigames_log_jam_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_log_jam_TEXT_START = .;
        build/asm/overlays/minigames/log_jam/1A3D80.s.o(.text);
        overlays_minigames_log_jam_TEXT_END = .;
        overlays_minigames_log_jam_DATA_START = .;
        overlays_minigames_log_jam_1AC270_bin = .;
        build/assets/overlays/minigames/log_jam/1AC270.bin.o(.data);
        overlays_minigames_log_jam_overlays_minigames_log_jam_1A3D80_s = .;
        build/asm/overlays/minigames/log_jam/1A3D80.s.o(.data);
        build/asm/overlays/minigames/log_jam/1A3D80.s.o(.rodata);
        overlays_minigames_log_jam_DATA_END = .;
        overlays_minigames_log_jam_BSS_START = .;
        build/asm/overlays/minigames/log_jam/1A3D80.s.o(.bss);
        overlays_minigames_log_jam_BSS_END = .;
    }
    overlays_minigames_log_jam_ROM_END = 0x1AC970;
    __romPos = 0x1AC970;

    __romPos = 0x1AC970;
    . = __romPos;
    overlays_minigames_slot_synch_ROM_START = __romPos;
    overlays_minigames_slot_synch_VRAM = ADDR(.overlays_minigames_slot_synch);
    .overlays_minigames_slot_synch 0x801059A0 : AT(overlays_minigames_slot_synch_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_slot_synch_TEXT_START = .;
        build/asm/overlays/minigames/slot_synch/1AC970.s.o(.text);
        overlays_minigames_slot_synch_TEXT_END = .;
        overlays_minigames_slot_synch_DATA_START = .;
        overlays_minigames_slot_synch_1B47C0_bin = .;
        build/assets/overlays/minigames/slot_synch/1B47C0.bin.o(.data);
        overlays_minigames_slot_synch_overlays_minigames_slot_synch_1AC970_s = .;
        build/asm/overlays/minigames/slot_synch/1AC970.s.o(.data);
        build/asm/overlays/minigames/slot_synch/1AC970.s.o(.rodata);
        overlays_minigames_slot_synch_DATA_END = .;
        overlays_minigames_slot_synch_BSS_START = .;
        build/asm/overlays/minigames/slot_synch/1AC970.s.o(.bss);
        overlays_minigames_slot_synch_BSS_END = .;
    }
    overlays_minigames_slot_synch_ROM_END = 0x1B4F10;
    __romPos = 0x1B4F10;

    __romPos = 0x1B4F10;
    . = __romPos;
    overlays_minigames_treadmill_grill_ROM_START = __romPos;
    overlays_minigames_treadmill_grill_VRAM = ADDR(.overlays_minigames_treadmill_grill);
    .overlays_minigames_treadmill_grill 0x801059A0 : AT(overlays_minigames_treadmill_grill_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_treadmill_grill_TEXT_START = .;
        build/asm/overlays/minigames/treadmill_grill/1B4F10.s.o(.text);
        overlays_minigames_treadmill_grill_TEXT_END = .;
        overlays_minigames_treadmill_grill_DATA_START = .;
        overlays_minigames_treadmill_grill_1BA4F0_bin = .;
        build/assets/overlays/minigames/treadmill_grill/1BA4F0.bin.o(.data);
        overlays_minigames_treadmill_grill_overlays_minigames_treadmill_grill_1B4F10_s = .;
        build/asm/overlays/minigames/treadmill_grill/1B4F10.s.o(.data);
        build/asm/overlays/minigames/treadmill_grill/1B4F10.s.o(.rodata);
        overlays_minigames_treadmill_grill_DATA_END = .;
        overlays_minigames_treadmill_grill_BSS_START = .;
        build/asm/overlays/minigames/treadmill_grill/1B4F10.s.o(.bss);
        overlays_minigames_treadmill_grill_BSS_END = .;
    }
    overlays_minigames_treadmill_grill_ROM_END = 0x1BA850;
    __romPos = 0x1BA850;

    __romPos = 0x1BA850;
    . = __romPos;
    overlays_minigames_toadstool_titan_ROM_START = __romPos;
    overlays_minigames_toadstool_titan_VRAM = ADDR(.overlays_minigames_toadstool_titan);
    .overlays_minigames_toadstool_titan 0x801059A0 : AT(overlays_minigames_toadstool_titan_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_toadstool_titan_TEXT_START = .;
        build/asm/overlays/minigames/toadstool_titan/1BA850.s.o(.text);
        overlays_minigames_toadstool_titan_TEXT_END = .;
        overlays_minigames_toadstool_titan_DATA_START = .;
        overlays_minigames_toadstool_titan_1C3C50_bin = .;
        build/assets/overlays/minigames/toadstool_titan/1C3C50.bin.o(.data);
        overlays_minigames_toadstool_titan_overlays_minigames_toadstool_titan_1BA850_s = .;
        build/asm/overlays/minigames/toadstool_titan/1BA850.s.o(.data);
        build/asm/overlays/minigames/toadstool_titan/1BA850.s.o(.rodata);
        overlays_minigames_toadstool_titan_DATA_END = .;
        overlays_minigames_toadstool_titan_BSS_START = .;
        build/asm/overlays/minigames/toadstool_titan/1BA850.s.o(.bss);
        overlays_minigames_toadstool_titan_BSS_END = .;
    }
    overlays_minigames_toadstool_titan_ROM_END = 0x1C4280;
    __romPos = 0x1C4280;

    __romPos = 0x1C4280;
    . = __romPos;
    overlays_minigames_aces_high_ROM_START = __romPos;
    overlays_minigames_aces_high_VRAM = ADDR(.overlays_minigames_aces_high);
    .overlays_minigames_aces_high 0x801059A0 : AT(overlays_minigames_aces_high_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_aces_high_TEXT_START = .;
        build/asm/overlays/minigames/aces_high/1C4280.s.o(.text);
        build/asm/overlays/minigames/aces_high/1CC400.s.o(.text);
        overlays_minigames_aces_high_TEXT_END = .;
        overlays_minigames_aces_high_DATA_START = .;
        overlays_minigames_aces_high_1CC420_bin = .;
        build/assets/overlays/minigames/aces_high/1CC420.bin.o(.data);
        overlays_minigames_aces_high_overlays_minigames_aces_high_1C4280_s = .;
        build/asm/overlays/minigames/aces_high/1C4280.s.o(.data);
        overlays_minigames_aces_high_overlays_minigames_aces_high_1CC400_s = .;
        build/asm/overlays/minigames/aces_high/1CC400.s.o(.data);
        build/asm/overlays/minigames/aces_high/1C4280.s.o(.rodata);
        build/asm/overlays/minigames/aces_high/1CC400.s.o(.rodata);
        overlays_minigames_aces_high_DATA_END = .;
        overlays_minigames_aces_high_BSS_START = .;
        build/asm/overlays/minigames/aces_high/1C4280.s.o(.bss);
        build/asm/overlays/minigames/aces_high/1CC400.s.o(.bss);
        overlays_minigames_aces_high_BSS_END = .;
    }
    overlays_minigames_aces_high_ROM_END = 0x1CC730;
    __romPos = 0x1CC730;

    __romPos = 0x1CC730;
    . = __romPos;
    overlays_minigames_bounce_n_trounce_ROM_START = __romPos;
    overlays_minigames_bounce_n_trounce_VRAM = ADDR(.overlays_minigames_bounce_n_trounce);
    .overlays_minigames_bounce_n_trounce 0x801059A0 : AT(overlays_minigames_bounce_n_trounce_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_bounce_n_trounce_TEXT_START = .;
        build/asm/overlays/minigames/bounce_n_trounce/1CC730.s.o(.text);
        build/asm/overlays/minigames/bounce_n_trounce/1D1920.s.o(.text);
        overlays_minigames_bounce_n_trounce_TEXT_END = .;
        overlays_minigames_bounce_n_trounce_DATA_START = .;
        overlays_minigames_bounce_n_trounce_1D1940_bin = .;
        build/assets/overlays/minigames/bounce_n_trounce/1D1940.bin.o(.data);
        overlays_minigames_bounce_n_trounce_overlays_minigames_bounce_n_trounce_1CC730_s = .;
        build/asm/overlays/minigames/bounce_n_trounce/1CC730.s.o(.data);
        overlays_minigames_bounce_n_trounce_overlays_minigames_bounce_n_trounce_1D1920_s = .;
        build/asm/overlays/minigames/bounce_n_trounce/1D1920.s.o(.data);
        build/asm/overlays/minigames/bounce_n_trounce/1CC730.s.o(.rodata);
        build/asm/overlays/minigames/bounce_n_trounce/1D1920.s.o(.rodata);
        overlays_minigames_bounce_n_trounce_DATA_END = .;
        overlays_minigames_bounce_n_trounce_BSS_START = .;
        build/asm/overlays/minigames/bounce_n_trounce/1CC730.s.o(.bss);
        build/asm/overlays/minigames/bounce_n_trounce/1D1920.s.o(.bss);
        overlays_minigames_bounce_n_trounce_BSS_END = .;
    }
    overlays_minigames_bounce_n_trounce_ROM_END = 0x1D1C40;
    __romPos = 0x1D1C40;

    __romPos = 0x1D1C40;
    . = __romPos;
    overlays_minigames_ice_rink_risk_ROM_START = __romPos;
    overlays_minigames_ice_rink_risk_VRAM = ADDR(.overlays_minigames_ice_rink_risk);
    .overlays_minigames_ice_rink_risk 0x801059A0 : AT(overlays_minigames_ice_rink_risk_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_ice_rink_risk_TEXT_START = .;
        build/asm/overlays/minigames/ice_rink_risk/1D1C40.s.o(.text);
        overlays_minigames_ice_rink_risk_TEXT_END = .;
        overlays_minigames_ice_rink_risk_DATA_START = .;
        overlays_minigames_ice_rink_risk_1D47F0_bin = .;
        build/assets/overlays/minigames/ice_rink_risk/1D47F0.bin.o(.data);
        overlays_minigames_ice_rink_risk_overlays_minigames_ice_rink_risk_1D1C40_s = .;
        build/asm/overlays/minigames/ice_rink_risk/1D1C40.s.o(.data);
        build/asm/overlays/minigames/ice_rink_risk/1D1C40.s.o(.rodata);
        overlays_minigames_ice_rink_risk_DATA_END = .;
        overlays_minigames_ice_rink_risk_BSS_START = .;
        build/asm/overlays/minigames/ice_rink_risk/1D1C40.s.o(.bss);
        overlays_minigames_ice_rink_risk_BSS_END = .;
    }
    overlays_minigames_ice_rink_risk_ROM_END = 0x1D4970;
    __romPos = 0x1D4970;

    __romPos = 0x1D4970;
    . = __romPos;
    overlays_minigames_locked_out_ROM_START = __romPos;
    overlays_minigames_locked_out_VRAM = ADDR(.overlays_minigames_locked_out);
    .overlays_minigames_locked_out 0x801059A0 : AT(overlays_minigames_locked_out_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_locked_out_TEXT_START = .;
        build/asm/overlays/minigames/locked_out/1D4970.s.o(.text);
        overlays_minigames_locked_out_TEXT_END = .;
        overlays_minigames_locked_out_DATA_START = .;
        overlays_minigames_locked_out_1D90E0_bin = .;
        build/assets/overlays/minigames/locked_out/1D90E0.bin.o(.data);
        overlays_minigames_locked_out_overlays_minigames_locked_out_1D4970_s = .;
        build/asm/overlays/minigames/locked_out/1D4970.s.o(.data);
        build/asm/overlays/minigames/locked_out/1D4970.s.o(.rodata);
        overlays_minigames_locked_out_DATA_END = .;
        overlays_minigames_locked_out_BSS_START = .;
        build/asm/overlays/minigames/locked_out/1D4970.s.o(.bss);
        overlays_minigames_locked_out_BSS_END = .;
    }
    overlays_minigames_locked_out_ROM_END = 0x1D9550;
    __romPos = 0x1D9550;

    __romPos = 0x1D9550;
    . = __romPos;
    overlays_minigames_chip_shot_challenge_ROM_START = __romPos;
    overlays_minigames_chip_shot_challenge_VRAM = ADDR(.overlays_minigames_chip_shot_challenge);
    .overlays_minigames_chip_shot_challenge 0x801059A0 : AT(overlays_minigames_chip_shot_challenge_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_chip_shot_challenge_TEXT_START = .;
        build/asm/overlays/minigames/chip_shot_challenge/1D9550.s.o(.text);
        overlays_minigames_chip_shot_challenge_TEXT_END = .;
        overlays_minigames_chip_shot_challenge_DATA_START = .;
        overlays_minigames_chip_shot_challenge_1DE3D0_bin = .;
        build/assets/overlays/minigames/chip_shot_challenge/1DE3D0.bin.o(.data);
        overlays_minigames_chip_shot_challenge_overlays_minigames_chip_shot_challenge_1D9550_s = .;
        build/asm/overlays/minigames/chip_shot_challenge/1D9550.s.o(.data);
        build/asm/overlays/minigames/chip_shot_challenge/1D9550.s.o(.rodata);
        overlays_minigames_chip_shot_challenge_DATA_END = .;
        overlays_minigames_chip_shot_challenge_BSS_START = .;
        build/asm/overlays/minigames/chip_shot_challenge/1D9550.s.o(.bss);
        overlays_minigames_chip_shot_challenge_BSS_END = .;
    }
    overlays_minigames_chip_shot_challenge_ROM_END = 0x1DE610;
    __romPos = 0x1DE610;

    __romPos = 0x1DE610;
    . = __romPos;
    overlays_minigames_parasol_plummet_ROM_START = __romPos;
    overlays_minigames_parasol_plummet_VRAM = ADDR(.overlays_minigames_parasol_plummet);
    .overlays_minigames_parasol_plummet 0x801059A0 : AT(overlays_minigames_parasol_plummet_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_parasol_plummet_TEXT_START = .;
        build/asm/overlays/minigames/parasol_plummet/1DE610.s.o(.text);
        overlays_minigames_parasol_plummet_TEXT_END = .;
        overlays_minigames_parasol_plummet_DATA_START = .;
        overlays_minigames_parasol_plummet_1E3510_bin = .;
        build/assets/overlays/minigames/parasol_plummet/1E3510.bin.o(.data);
        overlays_minigames_parasol_plummet_overlays_minigames_parasol_plummet_1DE610_s = .;
        build/asm/overlays/minigames/parasol_plummet/1DE610.s.o(.data);
        build/asm/overlays/minigames/parasol_plummet/1DE610.s.o(.rodata);
        overlays_minigames_parasol_plummet_DATA_END = .;
        overlays_minigames_parasol_plummet_BSS_START = .;
        build/asm/overlays/minigames/parasol_plummet/1DE610.s.o(.bss);
        overlays_minigames_parasol_plummet_BSS_END = .;
    }
    overlays_minigames_parasol_plummet_ROM_END = 0x1E37C0;
    __romPos = 0x1E37C0;

    __romPos = 0x1E37C0;
    . = __romPos;
    overlays_minigames_messy_memory_ROM_START = __romPos;
    overlays_minigames_messy_memory_VRAM = ADDR(.overlays_minigames_messy_memory);
    .overlays_minigames_messy_memory 0x801059A0 : AT(overlays_minigames_messy_memory_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_messy_memory_TEXT_START = .;
        build/asm/overlays/minigames/messy_memory/1E37C0.s.o(.text);
        overlays_minigames_messy_memory_TEXT_END = .;
        overlays_minigames_messy_memory_DATA_START = .;
        overlays_minigames_messy_memory_1EEDE0_bin = .;
        build/assets/overlays/minigames/messy_memory/1EEDE0.bin.o(.data);
        overlays_minigames_messy_memory_overlays_minigames_messy_memory_1E37C0_s = .;
        build/asm/overlays/minigames/messy_memory/1E37C0.s.o(.data);
        build/asm/overlays/minigames/messy_memory/1E37C0.s.o(.rodata);
        overlays_minigames_messy_memory_DATA_END = .;
        overlays_minigames_messy_memory_BSS_START = .;
        build/asm/overlays/minigames/messy_memory/1E37C0.s.o(.bss);
        overlays_minigames_messy_memory_BSS_END = .;
    }
    overlays_minigames_messy_memory_ROM_END = 0x1EF420;
    __romPos = 0x1EF420;

    __romPos = 0x1EF420;
    . = __romPos;
    overlays_minigames_picture_imperfect_ROM_START = __romPos;
    overlays_minigames_picture_imperfect_VRAM = ADDR(.overlays_minigames_picture_imperfect);
    .overlays_minigames_picture_imperfect 0x801059A0 : AT(overlays_minigames_picture_imperfect_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_picture_imperfect_TEXT_START = .;
        build/asm/overlays/minigames/picture_imperfect/1EF420.s.o(.text);
        overlays_minigames_picture_imperfect_TEXT_END = .;
        overlays_minigames_picture_imperfect_DATA_START = .;
        overlays_minigames_picture_imperfect_1F3A60_bin = .;
        build/assets/overlays/minigames/picture_imperfect/1F3A60.bin.o(.data);
        overlays_minigames_picture_imperfect_overlays_minigames_picture_imperfect_1EF420_s = .;
        build/asm/overlays/minigames/picture_imperfect/1EF420.s.o(.data);
        build/asm/overlays/minigames/picture_imperfect/1EF420.s.o(.rodata);
        overlays_minigames_picture_imperfect_DATA_END = .;
        overlays_minigames_picture_imperfect_BSS_START = .;
        build/asm/overlays/minigames/picture_imperfect/1EF420.s.o(.bss);
        overlays_minigames_picture_imperfect_BSS_END = .;
    }
    overlays_minigames_picture_imperfect_ROM_END = 0x1F3B90;
    __romPos = 0x1F3B90;

    __romPos = 0x1F3B90;
    . = __romPos;
    overlays_minigames_marios_puzzle_party_ROM_START = __romPos;
    overlays_minigames_marios_puzzle_party_VRAM = ADDR(.overlays_minigames_marios_puzzle_party);
    .overlays_minigames_marios_puzzle_party 0x801059A0 : AT(overlays_minigames_marios_puzzle_party_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_marios_puzzle_party_TEXT_START = .;
        build/asm/overlays/minigames/marios_puzzle_party/1F3B90.s.o(.text);
        build/asm/overlays/minigames/marios_puzzle_party/1FD760.s.o(.text);
        overlays_minigames_marios_puzzle_party_TEXT_END = .;
        overlays_minigames_marios_puzzle_party_DATA_START = .;
        overlays_minigames_marios_puzzle_party_1FE270_bin = .;
        build/assets/overlays/minigames/marios_puzzle_party/1FE270.bin.o(.data);
        overlays_minigames_marios_puzzle_party_overlays_minigames_marios_puzzle_party_1F3B90_s = .;
        build/asm/overlays/minigames/marios_puzzle_party/1F3B90.s.o(.data);
        overlays_minigames_marios_puzzle_party_overlays_minigames_marios_puzzle_party_1FD760_s = .;
        build/asm/overlays/minigames/marios_puzzle_party/1FD760.s.o(.data);
        build/asm/overlays/minigames/marios_puzzle_party/1F3B90.s.o(.rodata);
        build/asm/overlays/minigames/marios_puzzle_party/1FD760.s.o(.rodata);
        overlays_minigames_marios_puzzle_party_DATA_END = .;
        overlays_minigames_marios_puzzle_party_BSS_START = .;
        build/asm/overlays/minigames/marios_puzzle_party/1F3B90.s.o(.bss);
        build/asm/overlays/minigames/marios_puzzle_party/1FD760.s.o(.bss);
        overlays_minigames_marios_puzzle_party_BSS_END = .;
    }
    overlays_minigames_marios_puzzle_party_ROM_END = 0x1FE4D0;
    __romPos = 0x1FE4D0;

    __romPos = 0x1FE4D0;
    . = __romPos;
    overlays_minigames_the_beat_goes_on_ROM_START = __romPos;
    overlays_minigames_the_beat_goes_on_VRAM = ADDR(.overlays_minigames_the_beat_goes_on);
    .overlays_minigames_the_beat_goes_on 0x801059A0 : AT(overlays_minigames_the_beat_goes_on_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_the_beat_goes_on_TEXT_START = .;
        build/asm/overlays/minigames/the_beat_goes_on/1FE4D0.s.o(.text);
        overlays_minigames_the_beat_goes_on_TEXT_END = .;
        overlays_minigames_the_beat_goes_on_DATA_START = .;
        overlays_minigames_the_beat_goes_on_204DB0_bin = .;
        build/assets/overlays/minigames/the_beat_goes_on/204DB0.bin.o(.data);
        overlays_minigames_the_beat_goes_on_overlays_minigames_the_beat_goes_on_1FE4D0_s = .;
        build/asm/overlays/minigames/the_beat_goes_on/1FE4D0.s.o(.data);
        build/asm/overlays/minigames/the_beat_goes_on/1FE4D0.s.o(.rodata);
        overlays_minigames_the_beat_goes_on_DATA_END = .;
        overlays_minigames_the_beat_goes_on_BSS_START = .;
        build/asm/overlays/minigames/the_beat_goes_on/1FE4D0.s.o(.bss);
        overlays_minigames_the_beat_goes_on_BSS_END = .;
    }
    overlays_minigames_the_beat_goes_on_ROM_END = 0x204F90;
    __romPos = 0x204F90;

    __romPos = 0x204F90;
    . = __romPos;
    overlays_minigames_mpiq_ROM_START = __romPos;
    overlays_minigames_mpiq_VRAM = ADDR(.overlays_minigames_mpiq);
    .overlays_minigames_mpiq 0x801059A0 : AT(overlays_minigames_mpiq_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_mpiq_TEXT_START = .;
        build/asm/overlays/minigames/mpiq/204F90.s.o(.text);
        overlays_minigames_mpiq_TEXT_END = .;
        overlays_minigames_mpiq_DATA_START = .;
        overlays_minigames_mpiq_20BC70_bin = .;
        build/assets/overlays/minigames/mpiq/20BC70.bin.o(.data);
        overlays_minigames_mpiq_overlays_minigames_mpiq_204F90_s = .;
        build/asm/overlays/minigames/mpiq/204F90.s.o(.data);
        build/asm/overlays/minigames/mpiq/204F90.s.o(.rodata);
        overlays_minigames_mpiq_DATA_END = .;
        overlays_minigames_mpiq_BSS_START = .;
        build/asm/overlays/minigames/mpiq/204F90.s.o(.bss);
        overlays_minigames_mpiq_BSS_END = .;
    }
    overlays_minigames_mpiq_ROM_END = 0x20BFA0;
    __romPos = 0x20BFA0;

    __romPos = 0x20BFA0;
    . = __romPos;
    overlays_minigames_curtain_call_ROM_START = __romPos;
    overlays_minigames_curtain_call_VRAM = ADDR(.overlays_minigames_curtain_call);
    .overlays_minigames_curtain_call 0x801059A0 : AT(overlays_minigames_curtain_call_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_curtain_call_TEXT_START = .;
        build/asm/overlays/minigames/curtain_call/20BFA0.s.o(.text);
        overlays_minigames_curtain_call_TEXT_END = .;
        overlays_minigames_curtain_call_DATA_START = .;
        overlays_minigames_curtain_call_2116C0_bin = .;
        build/assets/overlays/minigames/curtain_call/2116C0.bin.o(.data);
        overlays_minigames_curtain_call_overlays_minigames_curtain_call_20BFA0_s = .;
        build/asm/overlays/minigames/curtain_call/20BFA0.s.o(.data);
        build/asm/overlays/minigames/curtain_call/20BFA0.s.o(.rodata);
        overlays_minigames_curtain_call_DATA_END = .;
        overlays_minigames_curtain_call_BSS_START = .;
        build/asm/overlays/minigames/curtain_call/20BFA0.s.o(.bss);
        overlays_minigames_curtain_call_BSS_END = .;
    }
    overlays_minigames_curtain_call_ROM_END = 0x211AB0;
    __romPos = 0x211AB0;

    __romPos = 0x211AB0;
    . = __romPos;
    overlays_minigames_water_whirled_ROM_START = __romPos;
    overlays_minigames_water_whirled_VRAM = ADDR(.overlays_minigames_water_whirled);
    .overlays_minigames_water_whirled 0x801059A0 : AT(overlays_minigames_water_whirled_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_water_whirled_TEXT_START = .;
        build/asm/overlays/minigames/water_whirled/211AB0.s.o(.text);
        overlays_minigames_water_whirled_TEXT_END = .;
        overlays_minigames_water_whirled_DATA_START = .;
        overlays_minigames_water_whirled_216270_bin = .;
        build/assets/overlays/minigames/water_whirled/216270.bin.o(.data);
        overlays_minigames_water_whirled_overlays_minigames_water_whirled_211AB0_s = .;
        build/asm/overlays/minigames/water_whirled/211AB0.s.o(.data);
        build/asm/overlays/minigames/water_whirled/211AB0.s.o(.rodata);
        overlays_minigames_water_whirled_DATA_END = .;
        overlays_minigames_water_whirled_BSS_START = .;
        build/asm/overlays/minigames/water_whirled/211AB0.s.o(.bss);
        overlays_minigames_water_whirled_BSS_END = .;
    }
    overlays_minigames_water_whirled_ROM_END = 0x216670;
    __romPos = 0x216670;

    __romPos = 0x216670;
    . = __romPos;
    overlays_minigames_fridged_bridges_ROM_START = __romPos;
    overlays_minigames_fridged_bridges_VRAM = ADDR(.overlays_minigames_fridged_bridges);
    .overlays_minigames_fridged_bridges 0x801059A0 : AT(overlays_minigames_fridged_bridges_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_fridged_bridges_TEXT_START = .;
        build/asm/overlays/minigames/fridged_bridges/216670.s.o(.text);
        build/asm/overlays/minigames/fridged_bridges/21CAC0.s.o(.text);
        overlays_minigames_fridged_bridges_TEXT_END = .;
        overlays_minigames_fridged_bridges_DATA_START = .;
        overlays_minigames_fridged_bridges_21DBF0_bin = .;
        build/assets/overlays/minigames/fridged_bridges/21DBF0.bin.o(.data);
        overlays_minigames_fridged_bridges_overlays_minigames_fridged_bridges_216670_s = .;
        build/asm/overlays/minigames/fridged_bridges/216670.s.o(.data);
        overlays_minigames_fridged_bridges_overlays_minigames_fridged_bridges_21CAC0_s = .;
        build/asm/overlays/minigames/fridged_bridges/21CAC0.s.o(.data);
        build/asm/overlays/minigames/fridged_bridges/216670.s.o(.rodata);
        build/asm/overlays/minigames/fridged_bridges/21CAC0.s.o(.rodata);
        overlays_minigames_fridged_bridges_DATA_END = .;
        overlays_minigames_fridged_bridges_BSS_START = .;
        build/asm/overlays/minigames/fridged_bridges/216670.s.o(.bss);
        build/asm/overlays/minigames/fridged_bridges/21CAC0.s.o(.bss);
        overlays_minigames_fridged_bridges_BSS_END = .;
    }
    overlays_minigames_fridged_bridges_ROM_END = 0x21E010;
    __romPos = 0x21E010;

    __romPos = 0x21E010;
    . = __romPos;
    overlays_minigames_awful_tower_ROM_START = __romPos;
    overlays_minigames_awful_tower_VRAM = ADDR(.overlays_minigames_awful_tower);
    .overlays_minigames_awful_tower 0x801059A0 : AT(overlays_minigames_awful_tower_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_awful_tower_TEXT_START = .;
        build/asm/overlays/minigames/awful_tower/21E010.s.o(.text);
        overlays_minigames_awful_tower_TEXT_END = .;
        overlays_minigames_awful_tower_DATA_START = .;
        overlays_minigames_awful_tower_2251D0_bin = .;
        build/assets/overlays/minigames/awful_tower/2251D0.bin.o(.data);
        overlays_minigames_awful_tower_overlays_minigames_awful_tower_21E010_s = .;
        build/asm/overlays/minigames/awful_tower/21E010.s.o(.data);
        build/asm/overlays/minigames/awful_tower/21E010.s.o(.rodata);
        overlays_minigames_awful_tower_DATA_END = .;
        overlays_minigames_awful_tower_BSS_START = .;
        build/asm/overlays/minigames/awful_tower/21E010.s.o(.bss);
        overlays_minigames_awful_tower_BSS_END = .;
    }
    overlays_minigames_awful_tower_ROM_END = 0x225740;
    __romPos = 0x225740;

    __romPos = 0x225740;
    . = __romPos;
    overlays_minigames_cheep_cheep_chase_ROM_START = __romPos;
    overlays_minigames_cheep_cheep_chase_VRAM = ADDR(.overlays_minigames_cheep_cheep_chase);
    .overlays_minigames_cheep_cheep_chase 0x801059A0 : AT(overlays_minigames_cheep_cheep_chase_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_cheep_cheep_chase_TEXT_START = .;
        build/asm/overlays/minigames/cheep_cheep_chase/225740.s.o(.text);
        overlays_minigames_cheep_cheep_chase_TEXT_END = .;
        overlays_minigames_cheep_cheep_chase_DATA_START = .;
        overlays_minigames_cheep_cheep_chase_22DDB0_bin = .;
        build/assets/overlays/minigames/cheep_cheep_chase/22DDB0.bin.o(.data);
        overlays_minigames_cheep_cheep_chase_overlays_minigames_cheep_cheep_chase_225740_s = .;
        build/asm/overlays/minigames/cheep_cheep_chase/225740.s.o(.data);
        build/asm/overlays/minigames/cheep_cheep_chase/225740.s.o(.rodata);
        overlays_minigames_cheep_cheep_chase_DATA_END = .;
        overlays_minigames_cheep_cheep_chase_BSS_START = .;
        build/asm/overlays/minigames/cheep_cheep_chase/225740.s.o(.bss);
        overlays_minigames_cheep_cheep_chase_BSS_END = .;
    }
    overlays_minigames_cheep_cheep_chase_ROM_END = 0x22E100;
    __romPos = 0x22E100;

    __romPos = 0x22E100;
    . = __romPos;
    overlays_minigames_pipe_cleaners_ROM_START = __romPos;
    overlays_minigames_pipe_cleaners_VRAM = ADDR(.overlays_minigames_pipe_cleaners);
    .overlays_minigames_pipe_cleaners 0x801059A0 : AT(overlays_minigames_pipe_cleaners_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_pipe_cleaners_TEXT_START = .;
        build/asm/overlays/minigames/pipe_cleaners/22E100.s.o(.text);
        overlays_minigames_pipe_cleaners_TEXT_END = .;
        overlays_minigames_pipe_cleaners_DATA_START = .;
        overlays_minigames_pipe_cleaners_232620_bin = .;
        build/assets/overlays/minigames/pipe_cleaners/232620.bin.o(.data);
        overlays_minigames_pipe_cleaners_overlays_minigames_pipe_cleaners_22E100_s = .;
        build/asm/overlays/minigames/pipe_cleaners/22E100.s.o(.data);
        build/asm/overlays/minigames/pipe_cleaners/22E100.s.o(.rodata);
        overlays_minigames_pipe_cleaners_DATA_END = .;
        overlays_minigames_pipe_cleaners_BSS_START = .;
        build/asm/overlays/minigames/pipe_cleaners/22E100.s.o(.bss);
        overlays_minigames_pipe_cleaners_BSS_END = .;
    }
    overlays_minigames_pipe_cleaners_ROM_END = 0x232A10;
    __romPos = 0x232A10;

    __romPos = 0x232A10;
    . = __romPos;
    overlays_minigames_snowball_summit_ROM_START = __romPos;
    overlays_minigames_snowball_summit_VRAM = ADDR(.overlays_minigames_snowball_summit);
    .overlays_minigames_snowball_summit 0x801059A0 : AT(overlays_minigames_snowball_summit_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_snowball_summit_TEXT_START = .;
        build/asm/overlays/minigames/snowball_summit/232A10.s.o(.text);
        overlays_minigames_snowball_summit_TEXT_END = .;
        overlays_minigames_snowball_summit_DATA_START = .;
        overlays_minigames_snowball_summit_23C5C0_bin = .;
        build/assets/overlays/minigames/snowball_summit/23C5C0.bin.o(.data);
        overlays_minigames_snowball_summit_overlays_minigames_snowball_summit_232A10_s = .;
        build/asm/overlays/minigames/snowball_summit/232A10.s.o(.data);
        build/asm/overlays/minigames/snowball_summit/232A10.s.o(.rodata);
        overlays_minigames_snowball_summit_DATA_END = .;
        overlays_minigames_snowball_summit_BSS_START = .;
        build/asm/overlays/minigames/snowball_summit/232A10.s.o(.bss);
        overlays_minigames_snowball_summit_BSS_END = .;
    }
    overlays_minigames_snowball_summit_ROM_END = 0x23C8F0;
    __romPos = 0x23C8F0;

    __romPos = 0x23C8F0;
    . = __romPos;
    overlays_minigames_all_fired_up_ROM_START = __romPos;
    overlays_minigames_all_fired_up_VRAM = ADDR(.overlays_minigames_all_fired_up);
    .overlays_minigames_all_fired_up 0x801059A0 : AT(overlays_minigames_all_fired_up_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_all_fired_up_TEXT_START = .;
        build/asm/overlays/minigames/all_fired_up/23C8F0.s.o(.text);
        overlays_minigames_all_fired_up_TEXT_END = .;
        overlays_minigames_all_fired_up_DATA_START = .;
        overlays_minigames_all_fired_up_240880_bin = .;
        build/assets/overlays/minigames/all_fired_up/240880.bin.o(.data);
        overlays_minigames_all_fired_up_overlays_minigames_all_fired_up_23C8F0_s = .;
        build/asm/overlays/minigames/all_fired_up/23C8F0.s.o(.data);
        build/asm/overlays/minigames/all_fired_up/23C8F0.s.o(.rodata);
        overlays_minigames_all_fired_up_DATA_END = .;
        overlays_minigames_all_fired_up_BSS_START = .;
        build/asm/overlays/minigames/all_fired_up/23C8F0.s.o(.bss);
        overlays_minigames_all_fired_up_BSS_END = .;
    }
    overlays_minigames_all_fired_up_ROM_END = 0x240A10;
    __romPos = 0x240A10;

    __romPos = 0x240A10;
    . = __romPos;
    overlays_minigames_stacked_deck_ROM_START = __romPos;
    overlays_minigames_stacked_deck_VRAM = ADDR(.overlays_minigames_stacked_deck);
    .overlays_minigames_stacked_deck 0x801059A0 : AT(overlays_minigames_stacked_deck_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_stacked_deck_TEXT_START = .;
        build/asm/overlays/minigames/stacked_deck/240A10.s.o(.text);
        overlays_minigames_stacked_deck_TEXT_END = .;
        overlays_minigames_stacked_deck_DATA_START = .;
        overlays_minigames_stacked_deck_24A300_bin = .;
        build/assets/overlays/minigames/stacked_deck/24A300.bin.o(.data);
        overlays_minigames_stacked_deck_overlays_minigames_stacked_deck_240A10_s = .;
        build/asm/overlays/minigames/stacked_deck/240A10.s.o(.data);
        build/asm/overlays/minigames/stacked_deck/240A10.s.o(.rodata);
        overlays_minigames_stacked_deck_DATA_END = .;
        overlays_minigames_stacked_deck_BSS_START = .;
        build/asm/overlays/minigames/stacked_deck/240A10.s.o(.bss);
        overlays_minigames_stacked_deck_BSS_END = .;
    }
    overlays_minigames_stacked_deck_ROM_END = 0x24A760;
    __romPos = 0x24A760;

    __romPos = 0x24A760;
    . = __romPos;
    overlays_minigames_three_door_monty_ROM_START = __romPos;
    overlays_minigames_three_door_monty_VRAM = ADDR(.overlays_minigames_three_door_monty);
    .overlays_minigames_three_door_monty 0x801059A0 : AT(overlays_minigames_three_door_monty_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_three_door_monty_TEXT_START = .;
        build/asm/overlays/minigames/three_door_monty/24A760.s.o(.text);
        overlays_minigames_three_door_monty_TEXT_END = .;
        overlays_minigames_three_door_monty_DATA_START = .;
        overlays_minigames_three_door_monty_251AD0_bin = .;
        build/assets/overlays/minigames/three_door_monty/251AD0.bin.o(.data);
        overlays_minigames_three_door_monty_overlays_minigames_three_door_monty_24A760_s = .;
        build/asm/overlays/minigames/three_door_monty/24A760.s.o(.data);
        build/asm/overlays/minigames/three_door_monty/24A760.s.o(.rodata);
        overlays_minigames_three_door_monty_DATA_END = .;
        overlays_minigames_three_door_monty_BSS_START = .;
        build/asm/overlays/minigames/three_door_monty/24A760.s.o(.bss);
        overlays_minigames_three_door_monty_BSS_END = .;
    }
    overlays_minigames_three_door_monty_ROM_END = 0x251FF0;
    __romPos = 0x251FF0;

    __romPos = 0x251FF0;
    . = __romPos;
    overlays_minigames_rockin_raceway_ROM_START = __romPos;
    overlays_minigames_rockin_raceway_VRAM = ADDR(.overlays_minigames_rockin_raceway);
    .overlays_minigames_rockin_raceway 0x801059A0 : AT(overlays_minigames_rockin_raceway_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_rockin_raceway_TEXT_START = .;
        build/asm/overlays/minigames/rockin_raceway/251FF0.s.o(.text);
        overlays_minigames_rockin_raceway_TEXT_END = .;
        overlays_minigames_rockin_raceway_DATA_START = .;
        overlays_minigames_rockin_raceway_25D530_bin = .;
        build/assets/overlays/minigames/rockin_raceway/25D530.bin.o(.data);
        overlays_minigames_rockin_raceway_overlays_minigames_rockin_raceway_251FF0_s = .;
        build/asm/overlays/minigames/rockin_raceway/251FF0.s.o(.data);
        build/asm/overlays/minigames/rockin_raceway/251FF0.s.o(.rodata);
        overlays_minigames_rockin_raceway_DATA_END = .;
        overlays_minigames_rockin_raceway_BSS_START = .;
        build/asm/overlays/minigames/rockin_raceway/251FF0.s.o(.bss);
        overlays_minigames_rockin_raceway_BSS_END = .;
    }
    overlays_minigames_rockin_raceway_ROM_END = 0x25E110;
    __romPos = 0x25E110;

    __romPos = 0x25E110;
    . = __romPos;
    overlays_minigames_merry_go_chomp_ROM_START = __romPos;
    overlays_minigames_merry_go_chomp_VRAM = ADDR(.overlays_minigames_merry_go_chomp);
    .overlays_minigames_merry_go_chomp 0x801059A0 : AT(overlays_minigames_merry_go_chomp_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_merry_go_chomp_TEXT_START = .;
        build/asm/overlays/minigames/merry_go_chomp/25E110.s.o(.text);
        overlays_minigames_merry_go_chomp_TEXT_END = .;
        overlays_minigames_merry_go_chomp_DATA_START = .;
        overlays_minigames_merry_go_chomp_2648B0_bin = .;
        build/assets/overlays/minigames/merry_go_chomp/2648B0.bin.o(.data);
        overlays_minigames_merry_go_chomp_overlays_minigames_merry_go_chomp_25E110_s = .;
        build/asm/overlays/minigames/merry_go_chomp/25E110.s.o(.data);
        build/asm/overlays/minigames/merry_go_chomp/25E110.s.o(.rodata);
        overlays_minigames_merry_go_chomp_DATA_END = .;
        overlays_minigames_merry_go_chomp_BSS_START = .;
        build/asm/overlays/minigames/merry_go_chomp/25E110.s.o(.bss);
        overlays_minigames_merry_go_chomp_BSS_END = .;
    }
    overlays_minigames_merry_go_chomp_ROM_END = 0x264B80;
    __romPos = 0x264B80;

    __romPos = 0x264B80;
    . = __romPos;
    overlays_minigames_slapdown_ROM_START = __romPos;
    overlays_minigames_slapdown_VRAM = ADDR(.overlays_minigames_slapdown);
    .overlays_minigames_slapdown 0x801059A0 : AT(overlays_minigames_slapdown_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_slapdown_TEXT_START = .;
        build/asm/overlays/minigames/slapdown/264B80.s.o(.text);
        overlays_minigames_slapdown_TEXT_END = .;
        overlays_minigames_slapdown_DATA_START = .;
        overlays_minigames_slapdown_269880_bin = .;
        build/assets/overlays/minigames/slapdown/269880.bin.o(.data);
        overlays_minigames_slapdown_overlays_minigames_slapdown_264B80_s = .;
        build/asm/overlays/minigames/slapdown/264B80.s.o(.data);
        build/asm/overlays/minigames/slapdown/264B80.s.o(.rodata);
        overlays_minigames_slapdown_DATA_END = .;
        overlays_minigames_slapdown_BSS_START = .;
        build/asm/overlays/minigames/slapdown/264B80.s.o(.bss);
        overlays_minigames_slapdown_BSS_END = .;
    }
    overlays_minigames_slapdown_ROM_END = 0x269BF0;
    __romPos = 0x269BF0;

    __romPos = 0x269BF0;
    . = __romPos;
    overlays_minigames_storm_chasers_ROM_START = __romPos;
    overlays_minigames_storm_chasers_VRAM = ADDR(.overlays_minigames_storm_chasers);
    .overlays_minigames_storm_chasers 0x801059A0 : AT(overlays_minigames_storm_chasers_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_storm_chasers_TEXT_START = .;
        build/asm/overlays/minigames/storm_chasers/269BF0.s.o(.text);
        overlays_minigames_storm_chasers_TEXT_END = .;
        overlays_minigames_storm_chasers_DATA_START = .;
        overlays_minigames_storm_chasers_270B00_bin = .;
        build/assets/overlays/minigames/storm_chasers/270B00.bin.o(.data);
        overlays_minigames_storm_chasers_overlays_minigames_storm_chasers_269BF0_s = .;
        build/asm/overlays/minigames/storm_chasers/269BF0.s.o(.data);
        build/asm/overlays/minigames/storm_chasers/269BF0.s.o(.rodata);
        overlays_minigames_storm_chasers_DATA_END = .;
        overlays_minigames_storm_chasers_BSS_START = .;
        build/asm/overlays/minigames/storm_chasers/269BF0.s.o(.bss);
        overlays_minigames_storm_chasers_BSS_END = .;
    }
    overlays_minigames_storm_chasers_ROM_END = 0x270EF0;
    __romPos = 0x270EF0;

    __romPos = 0x270EF0;
    . = __romPos;
    overlays_minigames_eye_sore_ROM_START = __romPos;
    overlays_minigames_eye_sore_VRAM = ADDR(.overlays_minigames_eye_sore);
    .overlays_minigames_eye_sore 0x801059A0 : AT(overlays_minigames_eye_sore_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_eye_sore_TEXT_START = .;
        build/asm/overlays/minigames/eye_sore/270EF0.s.o(.text);
        overlays_minigames_eye_sore_TEXT_END = .;
        overlays_minigames_eye_sore_DATA_START = .;
        overlays_minigames_eye_sore_276160_bin = .;
        build/assets/overlays/minigames/eye_sore/276160.bin.o(.data);
        overlays_minigames_eye_sore_overlays_minigames_eye_sore_270EF0_s = .;
        build/asm/overlays/minigames/eye_sore/270EF0.s.o(.data);
        build/asm/overlays/minigames/eye_sore/270EF0.s.o(.rodata);
        overlays_minigames_eye_sore_DATA_END = .;
        overlays_minigames_eye_sore_BSS_START = .;
        build/asm/overlays/minigames/eye_sore/270EF0.s.o(.bss);
        overlays_minigames_eye_sore_BSS_END = .;
    }
    overlays_minigames_eye_sore_ROM_END = 0x276470;
    __romPos = 0x276470;

    __romPos = 0x276470;
    . = __romPos;
    overlays_minigames_vine_with_me_ROM_START = __romPos;
    overlays_minigames_vine_with_me_VRAM = ADDR(.overlays_minigames_vine_with_me);
    .overlays_minigames_vine_with_me 0x801059A0 : AT(overlays_minigames_vine_with_me_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_vine_with_me_TEXT_START = .;
        build/asm/overlays/minigames/vine_with_me/276470.s.o(.text);
        overlays_minigames_vine_with_me_TEXT_END = .;
        overlays_minigames_vine_with_me_DATA_START = .;
        overlays_minigames_vine_with_me_282620_bin = .;
        build/assets/overlays/minigames/vine_with_me/282620.bin.o(.data);
        overlays_minigames_vine_with_me_overlays_minigames_vine_with_me_276470_s = .;
        build/asm/overlays/minigames/vine_with_me/276470.s.o(.data);
        build/asm/overlays/minigames/vine_with_me/276470.s.o(.rodata);
        overlays_minigames_vine_with_me_DATA_END = .;
        overlays_minigames_vine_with_me_BSS_START = .;
        build/asm/overlays/minigames/vine_with_me/276470.s.o(.bss);
        overlays_minigames_vine_with_me_BSS_END = .;
    }
    overlays_minigames_vine_with_me_ROM_END = 0x283060;
    __romPos = 0x283060;

    __romPos = 0x283060;
    . = __romPos;
    overlays_minigames_popgun_pickoff_ROM_START = __romPos;
    overlays_minigames_popgun_pickoff_VRAM = ADDR(.overlays_minigames_popgun_pickoff);
    .overlays_minigames_popgun_pickoff 0x801059A0 : AT(overlays_minigames_popgun_pickoff_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_popgun_pickoff_TEXT_START = .;
        build/asm/overlays/minigames/popgun_pickoff/283060.s.o(.text);
        overlays_minigames_popgun_pickoff_TEXT_END = .;
        overlays_minigames_popgun_pickoff_DATA_START = .;
        overlays_minigames_popgun_pickoff_289C50_bin = .;
        build/assets/overlays/minigames/popgun_pickoff/289C50.bin.o(.data);
        overlays_minigames_popgun_pickoff_overlays_minigames_popgun_pickoff_283060_s = .;
        build/asm/overlays/minigames/popgun_pickoff/283060.s.o(.data);
        build/asm/overlays/minigames/popgun_pickoff/283060.s.o(.rodata);
        overlays_minigames_popgun_pickoff_DATA_END = .;
        overlays_minigames_popgun_pickoff_BSS_START = .;
        build/asm/overlays/minigames/popgun_pickoff/283060.s.o(.bss);
        overlays_minigames_popgun_pickoff_BSS_END = .;
    }
    overlays_minigames_popgun_pickoff_ROM_END = 0x28A290;
    __romPos = 0x28A290;

    __romPos = 0x28A290;
    . = __romPos;
    overlays_minigames_end_of_the_line_ROM_START = __romPos;
    overlays_minigames_end_of_the_line_VRAM = ADDR(.overlays_minigames_end_of_the_line);
    .overlays_minigames_end_of_the_line 0x801059A0 : AT(overlays_minigames_end_of_the_line_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_end_of_the_line_TEXT_START = .;
        build/asm/overlays/minigames/end_of_the_line/28A290.s.o(.text);
        build/asm/overlays/minigames/end_of_the_line/290E70.s.o(.text);
        overlays_minigames_end_of_the_line_TEXT_END = .;
        overlays_minigames_end_of_the_line_DATA_START = .;
        overlays_minigames_end_of_the_line_290E90_bin = .;
        build/assets/overlays/minigames/end_of_the_line/290E90.bin.o(.data);
        overlays_minigames_end_of_the_line_overlays_minigames_end_of_the_line_28A290_s = .;
        build/asm/overlays/minigames/end_of_the_line/28A290.s.o(.data);
        overlays_minigames_end_of_the_line_overlays_minigames_end_of_the_line_290E70_s = .;
        build/asm/overlays/minigames/end_of_the_line/290E70.s.o(.data);
        build/asm/overlays/minigames/end_of_the_line/28A290.s.o(.rodata);
        build/asm/overlays/minigames/end_of_the_line/290E70.s.o(.rodata);
        overlays_minigames_end_of_the_line_DATA_END = .;
        overlays_minigames_end_of_the_line_BSS_START = .;
        build/asm/overlays/minigames/end_of_the_line/28A290.s.o(.bss);
        build/asm/overlays/minigames/end_of_the_line/290E70.s.o(.bss);
        overlays_minigames_end_of_the_line_BSS_END = .;
    }
    overlays_minigames_end_of_the_line_ROM_END = 0x291020;
    __romPos = 0x291020;

    __romPos = 0x291020;
    . = __romPos;
    overlays_minigames_bowser_toss_ROM_START = __romPos;
    overlays_minigames_bowser_toss_VRAM = ADDR(.overlays_minigames_bowser_toss);
    .overlays_minigames_bowser_toss 0x801059A0 : AT(overlays_minigames_bowser_toss_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_bowser_toss_TEXT_START = .;
        build/asm/overlays/minigames/bowser_toss/291020.s.o(.text);
        overlays_minigames_bowser_toss_TEXT_END = .;
        overlays_minigames_bowser_toss_DATA_START = .;
        overlays_minigames_bowser_toss_29A7D0_bin = .;
        build/assets/overlays/minigames/bowser_toss/29A7D0.bin.o(.data);
        overlays_minigames_bowser_toss_overlays_minigames_bowser_toss_291020_s = .;
        build/asm/overlays/minigames/bowser_toss/291020.s.o(.data);
        build/asm/overlays/minigames/bowser_toss/291020.s.o(.rodata);
        overlays_minigames_bowser_toss_DATA_END = .;
        overlays_minigames_bowser_toss_BSS_START = .;
        build/asm/overlays/minigames/bowser_toss/291020.s.o(.bss);
        overlays_minigames_bowser_toss_BSS_END = .;
    }
    overlays_minigames_bowser_toss_ROM_END = 0x29B1D0;
    __romPos = 0x29B1D0;

    __romPos = 0x29B1D0;
    . = __romPos;
    overlays_minigames_baby_bowser_bonkers_ROM_START = __romPos;
    overlays_minigames_baby_bowser_bonkers_VRAM = ADDR(.overlays_minigames_baby_bowser_bonkers);
    .overlays_minigames_baby_bowser_bonkers 0x801059A0 : AT(overlays_minigames_baby_bowser_bonkers_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_baby_bowser_bonkers_TEXT_START = .;
        build/asm/overlays/minigames/baby_bowser_bonkers/29B1D0.s.o(.text);
        overlays_minigames_baby_bowser_bonkers_TEXT_END = .;
        overlays_minigames_baby_bowser_bonkers_DATA_START = .;
        overlays_minigames_baby_bowser_bonkers_2A0C30_bin = .;
        build/assets/overlays/minigames/baby_bowser_bonkers/2A0C30.bin.o(.data);
        overlays_minigames_baby_bowser_bonkers_overlays_minigames_baby_bowser_bonkers_29B1D0_s = .;
        build/asm/overlays/minigames/baby_bowser_bonkers/29B1D0.s.o(.data);
        build/asm/overlays/minigames/baby_bowser_bonkers/29B1D0.s.o(.rodata);
        overlays_minigames_baby_bowser_bonkers_DATA_END = .;
        overlays_minigames_baby_bowser_bonkers_BSS_START = .;
        build/asm/overlays/minigames/baby_bowser_bonkers/29B1D0.s.o(.bss);
        overlays_minigames_baby_bowser_bonkers_BSS_END = .;
    }
    overlays_minigames_baby_bowser_bonkers_ROM_END = 0x2A1430;
    __romPos = 0x2A1430;

    __romPos = 0x2A1430;
    . = __romPos;
    overlays_minigames_motor_rooter_ROM_START = __romPos;
    overlays_minigames_motor_rooter_VRAM = ADDR(.overlays_minigames_motor_rooter);
    .overlays_minigames_motor_rooter 0x801059A0 : AT(overlays_minigames_motor_rooter_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_motor_rooter_TEXT_START = .;
        build/asm/overlays/minigames/motor_rooter/2A1430.s.o(.text);
        build/asm/overlays/minigames/motor_rooter/2A9850.s.o(.text);
        overlays_minigames_motor_rooter_TEXT_END = .;
        overlays_minigames_motor_rooter_DATA_START = .;
        overlays_minigames_motor_rooter_2ACFE0_bin = .;
        build/assets/overlays/minigames/motor_rooter/2ACFE0.bin.o(.data);
        overlays_minigames_motor_rooter_overlays_minigames_motor_rooter_2A1430_s = .;
        build/asm/overlays/minigames/motor_rooter/2A1430.s.o(.data);
        overlays_minigames_motor_rooter_overlays_minigames_motor_rooter_2A9850_s = .;
        build/asm/overlays/minigames/motor_rooter/2A9850.s.o(.data);
        build/asm/overlays/minigames/motor_rooter/2A1430.s.o(.rodata);
        build/asm/overlays/minigames/motor_rooter/2A9850.s.o(.rodata);
        overlays_minigames_motor_rooter_DATA_END = .;
        overlays_minigames_motor_rooter_BSS_START = .;
        build/asm/overlays/minigames/motor_rooter/2A1430.s.o(.bss);
        build/asm/overlays/minigames/motor_rooter/2A9850.s.o(.bss);
        overlays_minigames_motor_rooter_BSS_END = .;
    }
    overlays_minigames_motor_rooter_ROM_END = 0x2AF250;
    __romPos = 0x2AF250;

    __romPos = 0x2AF250;
    . = __romPos;
    overlays_minigames_silly_screws_ROM_START = __romPos;
    overlays_minigames_silly_screws_VRAM = ADDR(.overlays_minigames_silly_screws);
    .overlays_minigames_silly_screws 0x801059A0 : AT(overlays_minigames_silly_screws_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_silly_screws_TEXT_START = .;
        build/asm/overlays/minigames/silly_screws/2AF250.s.o(.text);
        build/asm/overlays/minigames/silly_screws/2B4B20.s.o(.text);
        overlays_minigames_silly_screws_TEXT_END = .;
        overlays_minigames_silly_screws_DATA_START = .;
        overlays_minigames_silly_screws_2B56D0_bin = .;
        build/assets/overlays/minigames/silly_screws/2B56D0.bin.o(.data);
        overlays_minigames_silly_screws_overlays_minigames_silly_screws_2AF250_s = .;
        build/asm/overlays/minigames/silly_screws/2AF250.s.o(.data);
        overlays_minigames_silly_screws_overlays_minigames_silly_screws_2B4B20_s = .;
        build/asm/overlays/minigames/silly_screws/2B4B20.s.o(.data);
        build/asm/overlays/minigames/silly_screws/2AF250.s.o(.rodata);
        build/asm/overlays/minigames/silly_screws/2B4B20.s.o(.rodata);
        overlays_minigames_silly_screws_DATA_END = .;
        overlays_minigames_silly_screws_BSS_START = .;
        build/asm/overlays/minigames/silly_screws/2AF250.s.o(.bss);
        build/asm/overlays/minigames/silly_screws/2B4B20.s.o(.bss);
        overlays_minigames_silly_screws_BSS_END = .;
    }
    overlays_minigames_silly_screws_ROM_END = 0x2B5830;
    __romPos = 0x2B5830;

    __romPos = 0x2B5830;
    . = __romPos;
    overlays_minigames_crowd_cover_ROM_START = __romPos;
    overlays_minigames_crowd_cover_VRAM = ADDR(.overlays_minigames_crowd_cover);
    .overlays_minigames_crowd_cover 0x801059A0 : AT(overlays_minigames_crowd_cover_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_crowd_cover_TEXT_START = .;
        build/asm/overlays/minigames/crowd_cover/2B5830.s.o(.text);
        overlays_minigames_crowd_cover_TEXT_END = .;
        overlays_minigames_crowd_cover_DATA_START = .;
        overlays_minigames_crowd_cover_2BC550_bin = .;
        build/assets/overlays/minigames/crowd_cover/2BC550.bin.o(.data);
        overlays_minigames_crowd_cover_overlays_minigames_crowd_cover_2B5830_s = .;
        build/asm/overlays/minigames/crowd_cover/2B5830.s.o(.data);
        build/asm/overlays/minigames/crowd_cover/2B5830.s.o(.rodata);
        overlays_minigames_crowd_cover_DATA_END = .;
        overlays_minigames_crowd_cover_BSS_START = .;
        build/asm/overlays/minigames/crowd_cover/2B5830.s.o(.bss);
        overlays_minigames_crowd_cover_BSS_END = .;
    }
    overlays_minigames_crowd_cover_ROM_END = 0x2BCE10;
    __romPos = 0x2BCE10;

    __romPos = 0x2BCE10;
    . = __romPos;
    overlays_minigames_tick_tock_hop_ROM_START = __romPos;
    overlays_minigames_tick_tock_hop_VRAM = ADDR(.overlays_minigames_tick_tock_hop);
    .overlays_minigames_tick_tock_hop 0x801059A0 : AT(overlays_minigames_tick_tock_hop_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_tick_tock_hop_TEXT_START = .;
        build/asm/overlays/minigames/tick_tock_hop/2BCE10.s.o(.text);
        build/asm/overlays/minigames/tick_tock_hop/2C0E70.s.o(.text);
        overlays_minigames_tick_tock_hop_TEXT_END = .;
        overlays_minigames_tick_tock_hop_DATA_START = .;
        overlays_minigames_tick_tock_hop_2C5910_bin = .;
        build/assets/overlays/minigames/tick_tock_hop/2C5910.bin.o(.data);
        overlays_minigames_tick_tock_hop_overlays_minigames_tick_tock_hop_2BCE10_s = .;
        build/asm/overlays/minigames/tick_tock_hop/2BCE10.s.o(.data);
        overlays_minigames_tick_tock_hop_overlays_minigames_tick_tock_hop_2C0E70_s = .;
        build/asm/overlays/minigames/tick_tock_hop/2C0E70.s.o(.data);
        build/asm/overlays/minigames/tick_tock_hop/2BCE10.s.o(.rodata);
        build/asm/overlays/minigames/tick_tock_hop/2C0E70.s.o(.rodata);
        overlays_minigames_tick_tock_hop_DATA_END = .;
        overlays_minigames_tick_tock_hop_BSS_START = .;
        build/asm/overlays/minigames/tick_tock_hop/2BCE10.s.o(.bss);
        build/asm/overlays/minigames/tick_tock_hop/2C0E70.s.o(.bss);
        overlays_minigames_tick_tock_hop_BSS_END = .;
    }
    overlays_minigames_tick_tock_hop_ROM_END = 0x2C5B50;
    __romPos = 0x2C5B50;

    __romPos = 0x2C5B50;
    . = __romPos;
    overlays_minigames_fowl_play_ROM_START = __romPos;
    overlays_minigames_fowl_play_VRAM = ADDR(.overlays_minigames_fowl_play);
    .overlays_minigames_fowl_play 0x801059A0 : AT(overlays_minigames_fowl_play_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_fowl_play_TEXT_START = .;
        build/asm/overlays/minigames/fowl_play/2C5B50.s.o(.text);
        overlays_minigames_fowl_play_TEXT_END = .;
        overlays_minigames_fowl_play_DATA_START = .;
        overlays_minigames_fowl_play_2CE950_bin = .;
        build/assets/overlays/minigames/fowl_play/2CE950.bin.o(.data);
        overlays_minigames_fowl_play_overlays_minigames_fowl_play_2C5B50_s = .;
        build/asm/overlays/minigames/fowl_play/2C5B50.s.o(.data);
        build/asm/overlays/minigames/fowl_play/2C5B50.s.o(.rodata);
        overlays_minigames_fowl_play_DATA_END = .;
        overlays_minigames_fowl_play_BSS_START = .;
        build/asm/overlays/minigames/fowl_play/2C5B50.s.o(.bss);
        overlays_minigames_fowl_play_BSS_END = .;
    }
    overlays_minigames_fowl_play_ROM_END = 0x2CF3B0;
    __romPos = 0x2CF3B0;

    __romPos = 0x2CF3B0;
    . = __romPos;
    overlays_minigames_winners_wheel_ROM_START = __romPos;
    overlays_minigames_winners_wheel_VRAM = ADDR(.overlays_minigames_winners_wheel);
    .overlays_minigames_winners_wheel 0x801059A0 : AT(overlays_minigames_winners_wheel_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_winners_wheel_TEXT_START = .;
        build/asm/overlays/minigames/winners_wheel/2CF3B0.s.o(.text);
        overlays_minigames_winners_wheel_TEXT_END = .;
        overlays_minigames_winners_wheel_DATA_START = .;
        overlays_minigames_winners_wheel_2D3C70_bin = .;
        build/assets/overlays/minigames/winners_wheel/2D3C70.bin.o(.data);
        overlays_minigames_winners_wheel_overlays_minigames_winners_wheel_2CF3B0_s = .;
        build/asm/overlays/minigames/winners_wheel/2CF3B0.s.o(.data);
        build/asm/overlays/minigames/winners_wheel/2CF3B0.s.o(.rodata);
        overlays_minigames_winners_wheel_DATA_END = .;
        overlays_minigames_winners_wheel_BSS_START = .;
        build/asm/overlays/minigames/winners_wheel/2CF3B0.s.o(.bss);
        overlays_minigames_winners_wheel_BSS_END = .;
    }
    overlays_minigames_winners_wheel_ROM_END = 0x2D3E70;
    __romPos = 0x2D3E70;

    __romPos = 0x2D3E70;
    . = __romPos;
    overlays_minigames_hey_batter_batter_ROM_START = __romPos;
    overlays_minigames_hey_batter_batter_VRAM = ADDR(.overlays_minigames_hey_batter_batter);
    .overlays_minigames_hey_batter_batter 0x801059A0 : AT(overlays_minigames_hey_batter_batter_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_hey_batter_batter_TEXT_START = .;
        build/asm/overlays/minigames/hey_batter_batter/2D3E70.s.o(.text);
        overlays_minigames_hey_batter_batter_TEXT_END = .;
        overlays_minigames_hey_batter_batter_DATA_START = .;
        overlays_minigames_hey_batter_batter_2D8030_bin = .;
        build/assets/overlays/minigames/hey_batter_batter/2D8030.bin.o(.data);
        overlays_minigames_hey_batter_batter_overlays_minigames_hey_batter_batter_2D3E70_s = .;
        build/asm/overlays/minigames/hey_batter_batter/2D3E70.s.o(.data);
        build/asm/overlays/minigames/hey_batter_batter/2D3E70.s.o(.rodata);
        overlays_minigames_hey_batter_batter_DATA_END = .;
        overlays_minigames_hey_batter_batter_BSS_START = .;
        build/asm/overlays/minigames/hey_batter_batter/2D3E70.s.o(.bss);
        overlays_minigames_hey_batter_batter_BSS_END = .;
    }
    overlays_minigames_hey_batter_batter_ROM_END = 0x2D8370;
    __romPos = 0x2D8370;

    __romPos = 0x2D8370;
    . = __romPos;
    overlays_minigames_bobbing_bow_loons_ROM_START = __romPos;
    overlays_minigames_bobbing_bow_loons_VRAM = ADDR(.overlays_minigames_bobbing_bow_loons);
    .overlays_minigames_bobbing_bow_loons 0x801059A0 : AT(overlays_minigames_bobbing_bow_loons_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_bobbing_bow_loons_TEXT_START = .;
        build/asm/overlays/minigames/bobbing_bow_loons/2D8370.s.o(.text);
        overlays_minigames_bobbing_bow_loons_TEXT_END = .;
        overlays_minigames_bobbing_bow_loons_DATA_START = .;
        overlays_minigames_bobbing_bow_loons_2DC0F0_bin = .;
        build/assets/overlays/minigames/bobbing_bow_loons/2DC0F0.bin.o(.data);
        overlays_minigames_bobbing_bow_loons_overlays_minigames_bobbing_bow_loons_2D8370_s = .;
        build/asm/overlays/minigames/bobbing_bow_loons/2D8370.s.o(.data);
        build/asm/overlays/minigames/bobbing_bow_loons/2D8370.s.o(.rodata);
        overlays_minigames_bobbing_bow_loons_DATA_END = .;
        overlays_minigames_bobbing_bow_loons_BSS_START = .;
        build/asm/overlays/minigames/bobbing_bow_loons/2D8370.s.o(.bss);
        overlays_minigames_bobbing_bow_loons_BSS_END = .;
    }
    overlays_minigames_bobbing_bow_loons_ROM_END = 0x2DC4D0;
    __romPos = 0x2DC4D0;

    __romPos = 0x2DC4D0;
    . = __romPos;
    overlays_minigames_dorrie_dip_ROM_START = __romPos;
    overlays_minigames_dorrie_dip_VRAM = ADDR(.overlays_minigames_dorrie_dip);
    .overlays_minigames_dorrie_dip 0x801059A0 : AT(overlays_minigames_dorrie_dip_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_dorrie_dip_TEXT_START = .;
        build/asm/overlays/minigames/dorrie_dip/2DC4D0.s.o(.text);
        overlays_minigames_dorrie_dip_TEXT_END = .;
        overlays_minigames_dorrie_dip_DATA_START = .;
        overlays_minigames_dorrie_dip_2E0B70_bin = .;
        build/assets/overlays/minigames/dorrie_dip/2E0B70.bin.o(.data);
        overlays_minigames_dorrie_dip_overlays_minigames_dorrie_dip_2DC4D0_s = .;
        build/asm/overlays/minigames/dorrie_dip/2DC4D0.s.o(.data);
        build/asm/overlays/minigames/dorrie_dip/2DC4D0.s.o(.rodata);
        overlays_minigames_dorrie_dip_DATA_END = .;
        overlays_minigames_dorrie_dip_BSS_START = .;
        build/asm/overlays/minigames/dorrie_dip/2DC4D0.s.o(.bss);
        overlays_minigames_dorrie_dip_BSS_END = .;
    }
    overlays_minigames_dorrie_dip_ROM_END = 0x2E0D20;
    __romPos = 0x2E0D20;

    __romPos = 0x2E0D20;
    . = __romPos;
    overlays_minigames_swinging_with_sharks_ROM_START = __romPos;
    overlays_minigames_swinging_with_sharks_VRAM = ADDR(.overlays_minigames_swinging_with_sharks);
    .overlays_minigames_swinging_with_sharks 0x801059A0 : AT(overlays_minigames_swinging_with_sharks_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_swinging_with_sharks_TEXT_START = .;
        build/asm/overlays/minigames/swinging_with_sharks/swinging_with_sharks.s.o(.text);
        overlays_minigames_swinging_with_sharks_TEXT_END = .;
        overlays_minigames_swinging_with_sharks_DATA_START = .;
        overlays_minigames_swinging_with_sharks_2E6060_bin = .;
        build/assets/overlays/minigames/swinging_with_sharks/2E6060.bin.o(.data);
        overlays_minigames_swinging_with_sharks_overlays_minigames_swinging_with_sharks_swinging_with_sharks_s = .;
        build/asm/overlays/minigames/swinging_with_sharks/swinging_with_sharks.s.o(.data);
        build/asm/overlays/minigames/swinging_with_sharks/swinging_with_sharks.s.o(.rodata);
        overlays_minigames_swinging_with_sharks_DATA_END = .;
        overlays_minigames_swinging_with_sharks_BSS_START = .;
        build/asm/overlays/minigames/swinging_with_sharks/swinging_with_sharks.s.o(.bss);
        overlays_minigames_swinging_with_sharks_BSS_END = .;
    }
    overlays_minigames_swinging_with_sharks_ROM_END = 0x2E6BE0;
    __romPos = 0x2E6BE0;

    __romPos = 0x2E6BE0;
    . = __romPos;
    overlays_minigames_swing_n_swipe_ROM_START = __romPos;
    overlays_minigames_swing_n_swipe_VRAM = ADDR(.overlays_minigames_swing_n_swipe);
    .overlays_minigames_swing_n_swipe 0x801059A0 : AT(overlays_minigames_swing_n_swipe_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_swing_n_swipe_TEXT_START = .;
        build/asm/overlays/minigames/swing_n_swipe/2E6BE0.s.o(.text);
        overlays_minigames_swing_n_swipe_TEXT_END = .;
        overlays_minigames_swing_n_swipe_DATA_START = .;
        overlays_minigames_swing_n_swipe_2ECF70_bin = .;
        build/assets/overlays/minigames/swing_n_swipe/2ECF70.bin.o(.data);
        overlays_minigames_swing_n_swipe_overlays_minigames_swing_n_swipe_2E6BE0_s = .;
        build/asm/overlays/minigames/swing_n_swipe/2E6BE0.s.o(.data);
        build/asm/overlays/minigames/swing_n_swipe/2E6BE0.s.o(.rodata);
        overlays_minigames_swing_n_swipe_DATA_END = .;
        overlays_minigames_swing_n_swipe_BSS_START = .;
        build/asm/overlays/minigames/swing_n_swipe/2E6BE0.s.o(.bss);
        overlays_minigames_swing_n_swipe_BSS_END = .;
    }
    overlays_minigames_swing_n_swipe_ROM_END = 0x2ED2D0;
    __romPos = 0x2ED2D0;

    __romPos = 0x2ED2D0;
    . = __romPos;
    overlays_minigames_stardust_battle_ROM_START = __romPos;
    overlays_minigames_stardust_battle_VRAM = ADDR(.overlays_minigames_stardust_battle);
    .overlays_minigames_stardust_battle 0x801059A0 : AT(overlays_minigames_stardust_battle_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_stardust_battle_TEXT_START = .;
        build/asm/overlays/minigames/stardust_battle/2ED2D0.s.o(.text);
        overlays_minigames_stardust_battle_TEXT_END = .;
        overlays_minigames_stardust_battle_DATA_START = .;
        overlays_minigames_stardust_battle_2FB5E0_bin = .;
        build/assets/overlays/minigames/stardust_battle/2FB5E0.bin.o(.data);
        overlays_minigames_stardust_battle_overlays_minigames_stardust_battle_2ED2D0_s = .;
        build/asm/overlays/minigames/stardust_battle/2ED2D0.s.o(.data);
        build/asm/overlays/minigames/stardust_battle/2ED2D0.s.o(.rodata);
        overlays_minigames_stardust_battle_DATA_END = .;
        overlays_minigames_stardust_battle_BSS_START = .;
        build/asm/overlays/minigames/stardust_battle/2ED2D0.s.o(.bss);
        overlays_minigames_stardust_battle_BSS_END = .;
    }
    overlays_minigames_stardust_battle_ROM_END = 0x2FC270;
    __romPos = 0x2FC270;

    __romPos = 0x2FC270;
    . = __romPos;
    overlays_minigames_game_guys_roulette_ROM_START = __romPos;
    overlays_minigames_game_guys_roulette_VRAM = ADDR(.overlays_minigames_game_guys_roulette);
    .overlays_minigames_game_guys_roulette 0x801059A0 : AT(overlays_minigames_game_guys_roulette_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_game_guys_roulette_TEXT_START = .;
        build/asm/overlays/minigames/game_guys_roulette/2FC270.s.o(.text);
        build/asm/overlays/minigames/game_guys_roulette/2FF5F0.s.o(.text);
        overlays_minigames_game_guys_roulette_TEXT_END = .;
        overlays_minigames_game_guys_roulette_DATA_START = .;
        overlays_minigames_game_guys_roulette_300F10_bin = .;
        build/assets/overlays/minigames/game_guys_roulette/300F10.bin.o(.data);
        overlays_minigames_game_guys_roulette_overlays_minigames_game_guys_roulette_2FC270_s = .;
        build/asm/overlays/minigames/game_guys_roulette/2FC270.s.o(.data);
        overlays_minigames_game_guys_roulette_overlays_minigames_game_guys_roulette_2FF5F0_s = .;
        build/asm/overlays/minigames/game_guys_roulette/2FF5F0.s.o(.data);
        build/asm/overlays/minigames/game_guys_roulette/2FC270.s.o(.rodata);
        build/asm/overlays/minigames/game_guys_roulette/2FF5F0.s.o(.rodata);
        overlays_minigames_game_guys_roulette_DATA_END = .;
        overlays_minigames_game_guys_roulette_BSS_START = .;
        build/asm/overlays/minigames/game_guys_roulette/2FC270.s.o(.bss);
        build/asm/overlays/minigames/game_guys_roulette/2FF5F0.s.o(.bss);
        overlays_minigames_game_guys_roulette_BSS_END = .;
    }
    overlays_minigames_game_guys_roulette_ROM_END = 0x3010E0;
    __romPos = 0x3010E0;

    __romPos = 0x3010E0;
    . = __romPos;
    overlays_minigames_game_guys_lucky_7_ROM_START = __romPos;
    overlays_minigames_game_guys_lucky_7_VRAM = ADDR(.overlays_minigames_game_guys_lucky_7);
    .overlays_minigames_game_guys_lucky_7 0x801059A0 : AT(overlays_minigames_game_guys_lucky_7_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_game_guys_lucky_7_TEXT_START = .;
        build/asm/overlays/minigames/game_guys_lucky_7/3010E0.s.o(.text);
        build/asm/overlays/minigames/game_guys_lucky_7/306F70.s.o(.text);
        overlays_minigames_game_guys_lucky_7_TEXT_END = .;
        overlays_minigames_game_guys_lucky_7_DATA_START = .;
        overlays_minigames_game_guys_lucky_7_308890_bin = .;
        build/assets/overlays/minigames/game_guys_lucky_7/308890.bin.o(.data);
        overlays_minigames_game_guys_lucky_7_overlays_minigames_game_guys_lucky_7_3010E0_s = .;
        build/asm/overlays/minigames/game_guys_lucky_7/3010E0.s.o(.data);
        overlays_minigames_game_guys_lucky_7_overlays_minigames_game_guys_lucky_7_306F70_s = .;
        build/asm/overlays/minigames/game_guys_lucky_7/306F70.s.o(.data);
        build/asm/overlays/minigames/game_guys_lucky_7/3010E0.s.o(.rodata);
        build/asm/overlays/minigames/game_guys_lucky_7/306F70.s.o(.rodata);
        overlays_minigames_game_guys_lucky_7_DATA_END = .;
        overlays_minigames_game_guys_lucky_7_BSS_START = .;
        build/asm/overlays/minigames/game_guys_lucky_7/3010E0.s.o(.bss);
        build/asm/overlays/minigames/game_guys_lucky_7/306F70.s.o(.bss);
        overlays_minigames_game_guys_lucky_7_BSS_END = .;
    }
    overlays_minigames_game_guys_lucky_7_ROM_END = 0x308D10;
    __romPos = 0x308D10;

    __romPos = 0x308D10;
    . = __romPos;
    overlays_minigames_game_guys_magic_boxes_ROM_START = __romPos;
    overlays_minigames_game_guys_magic_boxes_VRAM = ADDR(.overlays_minigames_game_guys_magic_boxes);
    .overlays_minigames_game_guys_magic_boxes 0x801059A0 : AT(overlays_minigames_game_guys_magic_boxes_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_game_guys_magic_boxes_TEXT_START = .;
        build/asm/overlays/minigames/game_guys_magic_boxes/308D10.s.o(.text);
        build/asm/overlays/minigames/game_guys_magic_boxes/30DC30.s.o(.text);
        overlays_minigames_game_guys_magic_boxes_TEXT_END = .;
        overlays_minigames_game_guys_magic_boxes_DATA_START = .;
        overlays_minigames_game_guys_magic_boxes_30F550_bin = .;
        build/assets/overlays/minigames/game_guys_magic_boxes/30F550.bin.o(.data);
        overlays_minigames_game_guys_magic_boxes_overlays_minigames_game_guys_magic_boxes_308D10_s = .;
        build/asm/overlays/minigames/game_guys_magic_boxes/308D10.s.o(.data);
        overlays_minigames_game_guys_magic_boxes_overlays_minigames_game_guys_magic_boxes_30DC30_s = .;
        build/asm/overlays/minigames/game_guys_magic_boxes/30DC30.s.o(.data);
        build/asm/overlays/minigames/game_guys_magic_boxes/308D10.s.o(.rodata);
        build/asm/overlays/minigames/game_guys_magic_boxes/30DC30.s.o(.rodata);
        overlays_minigames_game_guys_magic_boxes_DATA_END = .;
        overlays_minigames_game_guys_magic_boxes_BSS_START = .;
        build/asm/overlays/minigames/game_guys_magic_boxes/308D10.s.o(.bss);
        build/asm/overlays/minigames/game_guys_magic_boxes/30DC30.s.o(.bss);
        overlays_minigames_game_guys_magic_boxes_BSS_END = .;
    }
    overlays_minigames_game_guys_magic_boxes_ROM_END = 0x30F940;
    __romPos = 0x30F940;

    __romPos = 0x30F940;
    . = __romPos;
    overlays_minigames_game_guys_sweet_surprise_ROM_START = __romPos;
    overlays_minigames_game_guys_sweet_surprise_VRAM = ADDR(.overlays_minigames_game_guys_sweet_surprise);
    .overlays_minigames_game_guys_sweet_surprise 0x801059A0 : AT(overlays_minigames_game_guys_sweet_surprise_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_game_guys_sweet_surprise_TEXT_START = .;
        build/asm/overlays/minigames/game_guys_sweet_surprise/30F940.s.o(.text);
        build/asm/overlays/minigames/game_guys_sweet_surprise/3151F0.s.o(.text);
        overlays_minigames_game_guys_sweet_surprise_TEXT_END = .;
        overlays_minigames_game_guys_sweet_surprise_DATA_START = .;
        overlays_minigames_game_guys_sweet_surprise_316B10_bin = .;
        build/assets/overlays/minigames/game_guys_sweet_surprise/316B10.bin.o(.data);
        overlays_minigames_game_guys_sweet_surprise_overlays_minigames_game_guys_sweet_surprise_30F940_s = .;
        build/asm/overlays/minigames/game_guys_sweet_surprise/30F940.s.o(.data);
        overlays_minigames_game_guys_sweet_surprise_overlays_minigames_game_guys_sweet_surprise_3151F0_s = .;
        build/asm/overlays/minigames/game_guys_sweet_surprise/3151F0.s.o(.data);
        build/asm/overlays/minigames/game_guys_sweet_surprise/30F940.s.o(.rodata);
        build/asm/overlays/minigames/game_guys_sweet_surprise/3151F0.s.o(.rodata);
        overlays_minigames_game_guys_sweet_surprise_DATA_END = .;
        overlays_minigames_game_guys_sweet_surprise_BSS_START = .;
        build/asm/overlays/minigames/game_guys_sweet_surprise/30F940.s.o(.bss);
        build/asm/overlays/minigames/game_guys_sweet_surprise/3151F0.s.o(.bss);
        overlays_minigames_game_guys_sweet_surprise_BSS_END = .;
    }
    overlays_minigames_game_guys_sweet_surprise_ROM_END = 0x316DF0;
    __romPos = 0x316DF0;

    __romPos = 0x316DF0;
    . = __romPos;
    overlays_minigames_dizzy_dinghies_ROM_START = __romPos;
    overlays_minigames_dizzy_dinghies_VRAM = ADDR(.overlays_minigames_dizzy_dinghies);
    .overlays_minigames_dizzy_dinghies 0x801059A0 : AT(overlays_minigames_dizzy_dinghies_ROM_START) SUBALIGN(16)
    {
        overlays_minigames_dizzy_dinghies_TEXT_START = .;
        build/asm/overlays/minigames/dizzy_dinghies/316DF0.s.o(.text);
        overlays_minigames_dizzy_dinghies_TEXT_END = .;
        overlays_minigames_dizzy_dinghies_DATA_START = .;
        overlays_minigames_dizzy_dinghies_31AB90_bin = .;
        build/assets/overlays/minigames/dizzy_dinghies/31AB90.bin.o(.data);
        overlays_minigames_dizzy_dinghies_overlays_minigames_dizzy_dinghies_316DF0_s = .;
        build/asm/overlays/minigames/dizzy_dinghies/316DF0.s.o(.data);
        build/asm/overlays/minigames/dizzy_dinghies/316DF0.s.o(.rodata);
        overlays_minigames_dizzy_dinghies_DATA_END = .;
        overlays_minigames_dizzy_dinghies_BSS_START = .;
        build/asm/overlays/minigames/dizzy_dinghies/316DF0.s.o(.bss);
        overlays_minigames_dizzy_dinghies_BSS_END = .;
    }
    overlays_minigames_dizzy_dinghies_ROM_END = 0x31B3B0;
    __romPos = 0x31B3B0;

    __romPos = 0x31B3B0;
    . = __romPos;
    overlays_wrapper1_ROM_START = __romPos;
    overlays_wrapper1_VRAM = ADDR(.overlays_wrapper1);
    .overlays_wrapper1 0x801059A0 : AT(overlays_wrapper1_ROM_START) SUBALIGN(16)
    {
        overlays_wrapper1_TEXT_START = .;
        build/asm/overlays/wrapper1/overlay71_main.s.o(.text);
        build/asm/overlays/wrapper1/overlay71.s.o(.text);
        overlays_wrapper1_TEXT_END = .;
        overlays_wrapper1_DATA_START = .;
        overlays_wrapper1_overlay71_main_data__s = .;
        build/asm/data/overlays/wrapper1/overlay71_main.data.s.o(.data);
        build/asm/overlays/wrapper1/overlay71_main.s.o(.rodata);
        build/asm/overlays/wrapper1/overlay71.s.o(.rodata);
        overlays_wrapper1_DATA_END = .;
        overlays_wrapper1_BSS_START = .;
        build/asm/overlays/wrapper1/overlay71_main.s.o(.bss);
        build/asm/overlays/wrapper1/overlay71.s.o(.bss);
        overlays_wrapper1_BSS_END = .;
    }
    overlays_wrapper1_ROM_END = 0x31B510;
    __romPos = 0x31B510;

    __romPos = 0x31B510;
    . = __romPos;
    overlays_board_chillywaters_ROM_START = __romPos;
    overlays_board_chillywaters_VRAM = ADDR(.overlays_board_chillywaters);
    .overlays_board_chillywaters 0x801059A0 : AT(overlays_board_chillywaters_ROM_START) SUBALIGN(16)
    {
        overlays_board_chillywaters_TEXT_START = .;
        build/asm/overlays/board_chillywaters/chillywaters_main.s.o(.text);
        build/asm/overlays/board_chillywaters/chillywaters.s.o(.text);
        build/asm/overlays/board_chillywaters/chillywaters2.s.o(.text);
        overlays_board_chillywaters_TEXT_END = .;
        overlays_board_chillywaters_DATA_START = .;
        overlays_board_chillywaters_chillywaters_main_data__s = .;
        build/asm/data/overlays/board_chillywaters/chillywaters_main.data.s.o(.data);
        overlays_board_chillywaters_chillywaters2_data__s = .;
        build/asm/data/overlays/board_chillywaters/chillywaters2.data.s.o(.data);
        build/asm/data/overlays/board_chillywaters/chillywaters2.rodata.s.o(.rodata);
        overlays_board_chillywaters_DATA_END = .;
        overlays_board_chillywaters_BSS_START = .;
        build/asm/overlays/board_chillywaters/chillywaters_main.s.o(.bss);
        build/asm/overlays/board_chillywaters/chillywaters.s.o(.bss);
        build/asm/overlays/board_chillywaters/chillywaters2.s.o(.bss);
        overlays_board_chillywaters_BSS_END = .;
    }
    overlays_board_chillywaters_ROM_END = 0x3355E0;
    __romPos = 0x3355E0;

    __romPos = 0x3355E0;
    . = __romPos;
    overlays_board_deepbloobersea_ROM_START = __romPos;
    overlays_board_deepbloobersea_VRAM = ADDR(.overlays_board_deepbloobersea);
    .overlays_board_deepbloobersea 0x801059A0 : AT(overlays_board_deepbloobersea_ROM_START) SUBALIGN(16)
    {
        overlays_board_deepbloobersea_TEXT_START = .;
        build/asm/overlays/board_deepbloobersea/3355E0.s.o(.text);
        build/asm/overlays/board_deepbloobersea/335610.s.o(.text);
        overlays_board_deepbloobersea_TEXT_END = .;
        overlays_board_deepbloobersea_DATA_START = .;
        overlays_board_deepbloobersea_34C270_bin = .;
        build/assets/overlays/board_deepbloobersea/34C270.bin.o(.data);
        overlays_board_deepbloobersea_overlays_board_deepbloobersea_3355E0_s = .;
        build/asm/overlays/board_deepbloobersea/3355E0.s.o(.data);
        overlays_board_deepbloobersea_overlays_board_deepbloobersea_335610_s = .;
        build/asm/overlays/board_deepbloobersea/335610.s.o(.data);
        build/asm/overlays/board_deepbloobersea/3355E0.s.o(.rodata);
        build/asm/overlays/board_deepbloobersea/335610.s.o(.rodata);
        overlays_board_deepbloobersea_DATA_END = .;
        overlays_board_deepbloobersea_BSS_START = .;
        build/asm/overlays/board_deepbloobersea/3355E0.s.o(.bss);
        build/asm/overlays/board_deepbloobersea/335610.s.o(.bss);
        overlays_board_deepbloobersea_BSS_END = .;
    }
    overlays_board_deepbloobersea_ROM_END = 0x34E810;
    __romPos = 0x34E810;

    __romPos = 0x34E810;
    . = __romPos;
    overlays_board_spinydesert_ROM_START = __romPos;
    overlays_board_spinydesert_VRAM = ADDR(.overlays_board_spinydesert);
    .overlays_board_spinydesert 0x801059A0 : AT(overlays_board_spinydesert_ROM_START) SUBALIGN(16)
    {
        overlays_board_spinydesert_TEXT_START = .;
        build/asm/overlays/board_spinydesert/spinydesert_main.s.o(.text);
        build/asm/overlays/board_spinydesert/spinydesert.s.o(.text);
        overlays_board_spinydesert_TEXT_END = .;
        overlays_board_spinydesert_DATA_START = .;
        overlays_board_spinydesert_spinydesert_main_data__s = .;
        build/asm/data/overlays/board_spinydesert/spinydesert_main.data.s.o(.data);
        overlays_board_spinydesert_364F80_bin = .;
        build/assets/overlays/board_spinydesert/364F80.bin.o(.data);
        build/asm/overlays/board_spinydesert/spinydesert_main.s.o(.rodata);
        build/asm/overlays/board_spinydesert/spinydesert.s.o(.rodata);
        overlays_board_spinydesert_DATA_END = .;
        overlays_board_spinydesert_BSS_START = .;
        build/asm/overlays/board_spinydesert/spinydesert_main.s.o(.bss);
        build/asm/overlays/board_spinydesert/spinydesert.s.o(.bss);
        overlays_board_spinydesert_BSS_END = .;
    }
    overlays_board_spinydesert_ROM_END = 0x367930;
    __romPos = 0x367930;

    __romPos = 0x367930;
    . = __romPos;
    overlays_board_woodywoods_ROM_START = __romPos;
    overlays_board_woodywoods_VRAM = ADDR(.overlays_board_woodywoods);
    .overlays_board_woodywoods 0x801059A0 : AT(overlays_board_woodywoods_ROM_START) SUBALIGN(16)
    {
        overlays_board_woodywoods_TEXT_START = .;
        build/asm/overlays/board_woodywoods/367930.s.o(.text);
        build/asm/overlays/board_woodywoods/367960.s.o(.text);
        overlays_board_woodywoods_TEXT_END = .;
        overlays_board_woodywoods_DATA_START = .;
        overlays_board_woodywoods_37D6A0_bin = .;
        build/assets/overlays/board_woodywoods/37D6A0.bin.o(.data);
        overlays_board_woodywoods_overlays_board_woodywoods_367930_s = .;
        build/asm/overlays/board_woodywoods/367930.s.o(.data);
        overlays_board_woodywoods_overlays_board_woodywoods_367960_s = .;
        build/asm/overlays/board_woodywoods/367960.s.o(.data);
        build/asm/overlays/board_woodywoods/367930.s.o(.rodata);
        build/asm/overlays/board_woodywoods/367960.s.o(.rodata);
        overlays_board_woodywoods_DATA_END = .;
        overlays_board_woodywoods_BSS_START = .;
        build/asm/overlays/board_woodywoods/367930.s.o(.bss);
        build/asm/overlays/board_woodywoods/367960.s.o(.bss);
        overlays_board_woodywoods_BSS_END = .;
    }
    overlays_board_woodywoods_ROM_END = 0x37FF80;
    __romPos = 0x37FF80;

    __romPos = 0x37FF80;
    . = __romPos;
    overlays_board_creepycavern_ROM_START = __romPos;
    overlays_board_creepycavern_VRAM = ADDR(.overlays_board_creepycavern);
    .overlays_board_creepycavern 0x801059A0 : AT(overlays_board_creepycavern_ROM_START) SUBALIGN(16)
    {
        overlays_board_creepycavern_TEXT_START = .;
        build/asm/overlays/board_creepycavern/37FF80.s.o(.text);
        build/asm/overlays/board_creepycavern/37FFB0.s.o(.text);
        overlays_board_creepycavern_TEXT_END = .;
        overlays_board_creepycavern_DATA_START = .;
        overlays_board_creepycavern_3975F0_bin = .;
        build/assets/overlays/board_creepycavern/3975F0.bin.o(.data);
        overlays_board_creepycavern_overlays_board_creepycavern_37FF80_s = .;
        build/asm/overlays/board_creepycavern/37FF80.s.o(.data);
        overlays_board_creepycavern_overlays_board_creepycavern_37FFB0_s = .;
        build/asm/overlays/board_creepycavern/37FFB0.s.o(.data);
        build/asm/overlays/board_creepycavern/37FF80.s.o(.rodata);
        build/asm/overlays/board_creepycavern/37FFB0.s.o(.rodata);
        overlays_board_creepycavern_DATA_END = .;
        overlays_board_creepycavern_BSS_START = .;
        build/asm/overlays/board_creepycavern/37FF80.s.o(.bss);
        build/asm/overlays/board_creepycavern/37FFB0.s.o(.bss);
        overlays_board_creepycavern_BSS_END = .;
    }
    overlays_board_creepycavern_ROM_END = 0x39AD20;
    __romPos = 0x39AD20;

    __romPos = 0x39AD20;
    . = __romPos;
    overlays_board_waluigisisland_ROM_START = __romPos;
    overlays_board_waluigisisland_VRAM = ADDR(.overlays_board_waluigisisland);
    .overlays_board_waluigisisland 0x801059A0 : AT(overlays_board_waluigisisland_ROM_START) SUBALIGN(16)
    {
        overlays_board_waluigisisland_TEXT_START = .;
        build/asm/overlays/board_waluigisisland/39AD20.s.o(.text);
        build/asm/overlays/board_waluigisisland/39AD50.s.o(.text);
        overlays_board_waluigisisland_TEXT_END = .;
        overlays_board_waluigisisland_DATA_START = .;
        overlays_board_waluigisisland_3B08D0_bin = .;
        build/assets/overlays/board_waluigisisland/3B08D0.bin.o(.data);
        overlays_board_waluigisisland_overlays_board_waluigisisland_39AD20_s = .;
        build/asm/overlays/board_waluigisisland/39AD20.s.o(.data);
        overlays_board_waluigisisland_overlays_board_waluigisisland_39AD50_s = .;
        build/asm/overlays/board_waluigisisland/39AD50.s.o(.data);
        build/asm/overlays/board_waluigisisland/39AD20.s.o(.rodata);
        build/asm/overlays/board_waluigisisland/39AD50.s.o(.rodata);
        overlays_board_waluigisisland_DATA_END = .;
        overlays_board_waluigisisland_BSS_START = .;
        build/asm/overlays/board_waluigisisland/39AD20.s.o(.bss);
        build/asm/overlays/board_waluigisisland/39AD50.s.o(.bss);
        overlays_board_waluigisisland_BSS_END = .;
    }
    overlays_board_waluigisisland_ROM_END = 0x3B35F0;
    __romPos = 0x3B35F0;

    __romPos = 0x3B35F0;
    . = __romPos;
    overlays_board_rulesmap_ROM_START = __romPos;
    overlays_board_rulesmap_VRAM = ADDR(.overlays_board_rulesmap);
    .overlays_board_rulesmap 0x801059A0 : AT(overlays_board_rulesmap_ROM_START) SUBALIGN(16)
    {
        overlays_board_rulesmap_TEXT_START = .;
        build/asm/overlays/board_rulesmap/3B35F0.s.o(.text);
        build/asm/overlays/board_rulesmap/3B3620.s.o(.text);
        overlays_board_rulesmap_TEXT_END = .;
        overlays_board_rulesmap_DATA_START = .;
        overlays_board_rulesmap_3B9420_bin = .;
        build/assets/overlays/board_rulesmap/3B9420.bin.o(.data);
        overlays_board_rulesmap_overlays_board_rulesmap_3B35F0_s = .;
        build/asm/overlays/board_rulesmap/3B35F0.s.o(.data);
        overlays_board_rulesmap_overlays_board_rulesmap_3B3620_s = .;
        build/asm/overlays/board_rulesmap/3B3620.s.o(.data);
        build/asm/overlays/board_rulesmap/3B35F0.s.o(.rodata);
        build/asm/overlays/board_rulesmap/3B3620.s.o(.rodata);
        overlays_board_rulesmap_DATA_END = .;
        overlays_board_rulesmap_BSS_START = .;
        build/asm/overlays/board_rulesmap/3B35F0.s.o(.bss);
        build/asm/overlays/board_rulesmap/3B3620.s.o(.bss);
        overlays_board_rulesmap_BSS_END = .;
    }
    overlays_board_rulesmap_ROM_END = 0x3B9670;
    __romPos = 0x3B9670;

    __romPos = 0x3B9670;
    . = __romPos;
    overlays_results_cutscene_ROM_START = __romPos;
    overlays_results_cutscene_VRAM = ADDR(.overlays_results_cutscene);
    .overlays_results_cutscene 0x801059A0 : AT(overlays_results_cutscene_ROM_START) SUBALIGN(16)
    {
        overlays_results_cutscene_TEXT_START = .;
        build/asm/overlays/results_cutscene/3B9670.s.o(.text);
        build/asm/overlays/results_cutscene/3BFA00.s.o(.text);
        overlays_results_cutscene_TEXT_END = .;
        overlays_results_cutscene_DATA_START = .;
        overlays_results_cutscene_3C20B0_bin = .;
        build/assets/overlays/results_cutscene/3C20B0.bin.o(.data);
        overlays_results_cutscene_overlays_results_cutscene_3B9670_s = .;
        build/asm/overlays/results_cutscene/3B9670.s.o(.data);
        overlays_results_cutscene_overlays_results_cutscene_3BFA00_s = .;
        build/asm/overlays/results_cutscene/3BFA00.s.o(.data);
        build/asm/overlays/results_cutscene/3B9670.s.o(.rodata);
        build/asm/overlays/results_cutscene/3BFA00.s.o(.rodata);
        overlays_results_cutscene_DATA_END = .;
        overlays_results_cutscene_BSS_START = .;
        build/asm/overlays/results_cutscene/3B9670.s.o(.bss);
        build/asm/overlays/results_cutscene/3BFA00.s.o(.bss);
        overlays_results_cutscene_BSS_END = .;
    }
    overlays_results_cutscene_ROM_END = 0x3C27C0;
    __romPos = 0x3C27C0;

    __romPos = 0x3C27C0;
    . = __romPos;
    overlays_bowser_event_ROM_START = __romPos;
    overlays_bowser_event_VRAM = ADDR(.overlays_bowser_event);
    .overlays_bowser_event 0x801059A0 : AT(overlays_bowser_event_ROM_START) SUBALIGN(16)
    {
        overlays_bowser_event_TEXT_START = .;
        build/asm/overlays/bowser_event/3C27C0.s.o(.text);
        overlays_bowser_event_TEXT_END = .;
        overlays_bowser_event_DATA_START = .;
        overlays_bowser_event_3C6170_bin = .;
        build/assets/overlays/bowser_event/3C6170.bin.o(.data);
        overlays_bowser_event_overlays_bowser_event_3C27C0_s = .;
        build/asm/overlays/bowser_event/3C27C0.s.o(.data);
        build/asm/overlays/bowser_event/3C27C0.s.o(.rodata);
        overlays_bowser_event_DATA_END = .;
        overlays_bowser_event_BSS_START = .;
        build/asm/overlays/bowser_event/3C27C0.s.o(.bss);
        overlays_bowser_event_BSS_END = .;
    }
    overlays_bowser_event_ROM_END = 0x3C6310;
    __romPos = 0x3C6310;

    __romPos = 0x3C6310;
    . = __romPos;
    overlays_last_5_turns_ROM_START = __romPos;
    overlays_last_5_turns_VRAM = ADDR(.overlays_last_5_turns);
    .overlays_last_5_turns 0x801059A0 : AT(overlays_last_5_turns_ROM_START) SUBALIGN(16)
    {
        overlays_last_5_turns_TEXT_START = .;
        build/asm/overlays/last_5_turns/3C6310.s.o(.text);
        overlays_last_5_turns_TEXT_END = .;
        overlays_last_5_turns_DATA_START = .;
        overlays_last_5_turns_3C7DF0_bin = .;
        build/assets/overlays/last_5_turns/3C7DF0.bin.o(.data);
        overlays_last_5_turns_overlays_last_5_turns_3C6310_s = .;
        build/asm/overlays/last_5_turns/3C6310.s.o(.data);
        build/asm/overlays/last_5_turns/3C6310.s.o(.rodata);
        overlays_last_5_turns_DATA_END = .;
        overlays_last_5_turns_BSS_START = .;
        build/asm/overlays/last_5_turns/3C6310.s.o(.bss);
        overlays_last_5_turns_BSS_END = .;
    }
    overlays_last_5_turns_ROM_END = 0x3C7EC0;
    __romPos = 0x3C7EC0;

    __romPos = 0x3C7EC0;
    . = __romPos;
    overlays_mushroom_genie_ROM_START = __romPos;
    overlays_mushroom_genie_VRAM = ADDR(.overlays_mushroom_genie);
    .overlays_mushroom_genie 0x801059A0 : AT(overlays_mushroom_genie_ROM_START) SUBALIGN(16)
    {
        overlays_mushroom_genie_TEXT_START = .;
        build/asm/overlays/mushroom_genie/3C7EC0.s.o(.text);
        overlays_mushroom_genie_TEXT_END = .;
        overlays_mushroom_genie_DATA_START = .;
        overlays_mushroom_genie_3CA5F0_bin = .;
        build/assets/overlays/mushroom_genie/3CA5F0.bin.o(.data);
        overlays_mushroom_genie_overlays_mushroom_genie_3C7EC0_s = .;
        build/asm/overlays/mushroom_genie/3C7EC0.s.o(.data);
        build/asm/overlays/mushroom_genie/3C7EC0.s.o(.rodata);
        overlays_mushroom_genie_DATA_END = .;
        overlays_mushroom_genie_BSS_START = .;
        build/asm/overlays/mushroom_genie/3C7EC0.s.o(.bss);
        overlays_mushroom_genie_BSS_END = .;
    }
    overlays_mushroom_genie_ROM_END = 0x3CA800;
    __romPos = 0x3CA800;

    __romPos = 0x3CA800;
    . = __romPos;
    overlays_chilly_waters_intro_ROM_START = __romPos;
    overlays_chilly_waters_intro_VRAM = ADDR(.overlays_chilly_waters_intro);
    .overlays_chilly_waters_intro 0x801059A0 : AT(overlays_chilly_waters_intro_ROM_START) SUBALIGN(16)
    {
        overlays_chilly_waters_intro_TEXT_START = .;
        build/asm/overlays/chilly_waters_intro/3CA800.s.o(.text);
        overlays_chilly_waters_intro_TEXT_END = .;
        overlays_chilly_waters_intro_DATA_START = .;
        overlays_chilly_waters_intro_3CDBD0_bin = .;
        build/assets/overlays/chilly_waters_intro/3CDBD0.bin.o(.data);
        overlays_chilly_waters_intro_overlays_chilly_waters_intro_3CA800_s = .;
        build/asm/overlays/chilly_waters_intro/3CA800.s.o(.data);
        build/asm/overlays/chilly_waters_intro/3CA800.s.o(.rodata);
        overlays_chilly_waters_intro_DATA_END = .;
        overlays_chilly_waters_intro_BSS_START = .;
        build/asm/overlays/chilly_waters_intro/3CA800.s.o(.bss);
        overlays_chilly_waters_intro_BSS_END = .;
    }
    overlays_chilly_waters_intro_ROM_END = 0x3CDEC0;
    __romPos = 0x3CDEC0;

    __romPos = 0x3CDEC0;
    . = __romPos;
    overlays_rule_map_intro_ROM_START = __romPos;
    overlays_rule_map_intro_VRAM = ADDR(.overlays_rule_map_intro);
    .overlays_rule_map_intro 0x801059A0 : AT(overlays_rule_map_intro_ROM_START) SUBALIGN(16)
    {
        overlays_rule_map_intro_TEXT_START = .;
        build/asm/overlays/rule_map_intro/3CDEC0.s.o(.text);
        overlays_rule_map_intro_TEXT_END = .;
        overlays_rule_map_intro_DATA_START = .;
        overlays_rule_map_intro_3CFAE0_bin = .;
        build/assets/overlays/rule_map_intro/3CFAE0.bin.o(.data);
        overlays_rule_map_intro_overlays_rule_map_intro_3CDEC0_s = .;
        build/asm/overlays/rule_map_intro/3CDEC0.s.o(.data);
        build/asm/overlays/rule_map_intro/3CDEC0.s.o(.rodata);
        overlays_rule_map_intro_DATA_END = .;
        overlays_rule_map_intro_BSS_START = .;
        build/asm/overlays/rule_map_intro/3CDEC0.s.o(.bss);
        overlays_rule_map_intro_BSS_END = .;
    }
    overlays_rule_map_intro_ROM_END = 0x3CFC80;
    __romPos = 0x3CFC80;

    __romPos = 0x3CFC80;
    . = __romPos;
    overlays_detailed_results_main_ROM_START = __romPos;
    overlays_detailed_results_main_VRAM = ADDR(.overlays_detailed_results_main);
    .overlays_detailed_results_main 0x801059A0 : AT(overlays_detailed_results_main_ROM_START) SUBALIGN(16)
    {
        overlays_detailed_results_main_TEXT_START = .;
        build/asm/overlays/detailed_results_main/3CFC80.s.o(.text);
        overlays_detailed_results_main_TEXT_END = .;
        overlays_detailed_results_main_DATA_START = .;
        overlays_detailed_results_main_3D3A90_bin = .;
        build/assets/overlays/detailed_results_main/3D3A90.bin.o(.data);
        overlays_detailed_results_main_overlays_detailed_results_main_3CFC80_s = .;
        build/asm/overlays/detailed_results_main/3CFC80.s.o(.data);
        build/asm/overlays/detailed_results_main/3CFC80.s.o(.rodata);
        overlays_detailed_results_main_DATA_END = .;
        overlays_detailed_results_main_BSS_START = .;
        build/asm/overlays/detailed_results_main/3CFC80.s.o(.bss);
        overlays_detailed_results_main_BSS_END = .;
    }
    overlays_detailed_results_main_ROM_END = 0x3D3C80;
    __romPos = 0x3D3C80;

    __romPos = 0x3D3C80;
    . = __romPos;
    overlays_test_anim1_ROM_START = __romPos;
    overlays_test_anim1_VRAM = ADDR(.overlays_test_anim1);
    .overlays_test_anim1 0x801059A0 : AT(overlays_test_anim1_ROM_START) SUBALIGN(16)
    {
        overlays_test_anim1_TEXT_START = .;
        build/src/overlays/test_anim1/test_anim1.c.o(.text);
        overlays_test_anim1_TEXT_END = .;
        overlays_test_anim1_DATA_START = .;
        overlays_test_anim1_test_anim1_bin = .;
        build/assets/overlays/test_anim1/test_anim1.bin.o(.data);
        overlays_test_anim1_overlays_test_anim1_test_anim1_c = .;
        build/src/overlays/test_anim1/test_anim1.c.o(.data);
        build/src/overlays/test_anim1/test_anim1.c.o(.rodata);
        overlays_test_anim1_DATA_END = .;
        overlays_test_anim1_BSS_START = .;
        build/src/overlays/test_anim1/test_anim1.c.o(.bss);
        overlays_test_anim1_BSS_END = .;
    }
    overlays_test_anim1_ROM_END = 0x3D5C30;
    __romPos = 0x3D5C30;

    __romPos = 0x3D5C30;
    . = __romPos;
    overlays_test_anim2_ROM_START = __romPos;
    overlays_test_anim2_VRAM = ADDR(.overlays_test_anim2);
    .overlays_test_anim2 0x801059A0 : AT(overlays_test_anim2_ROM_START) SUBALIGN(16)
    {
        overlays_test_anim2_TEXT_START = .;
        build/asm/overlays/test_anim2/3D5C30.s.o(.text);
        overlays_test_anim2_TEXT_END = .;
        overlays_test_anim2_DATA_START = .;
        overlays_test_anim2_3D7040_bin = .;
        build/assets/overlays/test_anim2/3D7040.bin.o(.data);
        overlays_test_anim2_overlays_test_anim2_3D5C30_s = .;
        build/asm/overlays/test_anim2/3D5C30.s.o(.data);
        build/asm/overlays/test_anim2/3D5C30.s.o(.rodata);
        overlays_test_anim2_DATA_END = .;
        overlays_test_anim2_BSS_START = .;
        build/asm/overlays/test_anim2/3D5C30.s.o(.bss);
        overlays_test_anim2_BSS_END = .;
    }
    overlays_test_anim2_ROM_END = 0x3D7150;
    __romPos = 0x3D7150;

    __romPos = 0x3D7150;
    . = __romPos;
    overlays_intro_ROM_START = __romPos;
    overlays_intro_VRAM = ADDR(.overlays_intro);
    .overlays_intro 0x801059A0 : AT(overlays_intro_ROM_START) SUBALIGN(16)
    {
        overlays_intro_TEXT_START = .;
        build/asm/overlays/intro/intro_main.s.o(.text);
        build/asm/overlays/intro/intro.s.o(.text);
        overlays_intro_TEXT_END = .;
        overlays_intro_DATA_START = .;
        overlays_intro_intro_main_data__s = .;
        build/asm/data/overlays/intro/intro_main.data.s.o(.data);
        overlays_intro_intro_bin = .;
        build/assets/overlays/intro/intro.bin.o(.data);
        build/asm/overlays/intro/intro_main.s.o(.rodata);
        build/asm/overlays/intro/intro.s.o(.rodata);
        overlays_intro_DATA_END = .;
        overlays_intro_BSS_START = .;
        build/asm/overlays/intro/intro_main.s.o(.bss);
        build/asm/overlays/intro/intro.s.o(.bss);
        overlays_intro_BSS_END = .;
    }
    overlays_intro_ROM_END = 0x3D76C0;
    __romPos = 0x3D76C0;

    __romPos = 0x3D76C0;
    . = __romPos;
    overlays_test_save1_ROM_START = __romPos;
    overlays_test_save1_VRAM = ADDR(.overlays_test_save1);
    .overlays_test_save1 0x801059A0 : AT(overlays_test_save1_ROM_START) SUBALIGN(16)
    {
        overlays_test_save1_TEXT_START = .;
        build/asm/overlays/test_save1/3D76C0.s.o(.text);
        overlays_test_save1_TEXT_END = .;
        overlays_test_save1_DATA_START = .;
        overlays_test_save1_3D8680_bin = .;
        build/assets/overlays/test_save1/3D8680.bin.o(.data);
        overlays_test_save1_overlays_test_save1_3D76C0_s = .;
        build/asm/overlays/test_save1/3D76C0.s.o(.data);
        build/asm/overlays/test_save1/3D76C0.s.o(.rodata);
        overlays_test_save1_DATA_END = .;
        overlays_test_save1_BSS_START = .;
        build/asm/overlays/test_save1/3D76C0.s.o(.bss);
        overlays_test_save1_BSS_END = .;
    }
    overlays_test_save1_ROM_END = 0x3D8930;
    __romPos = 0x3D8930;

    __romPos = 0x3D8930;
    . = __romPos;
    overlays_gate_guy_intro1_ROM_START = __romPos;
    overlays_gate_guy_intro1_VRAM = ADDR(.overlays_gate_guy_intro1);
    .overlays_gate_guy_intro1 0x801059A0 : AT(overlays_gate_guy_intro1_ROM_START) SUBALIGN(16)
    {
        overlays_gate_guy_intro1_TEXT_START = .;
        build/asm/overlays/gate_guy_intro1/3D8930.s.o(.text);
        build/asm/overlays/gate_guy_intro1/3D8960.s.o(.text);
        overlays_gate_guy_intro1_TEXT_END = .;
        overlays_gate_guy_intro1_DATA_START = .;
        overlays_gate_guy_intro1_3D8A70_bin = .;
        build/assets/overlays/gate_guy_intro1/3D8A70.bin.o(.data);
        overlays_gate_guy_intro1_overlays_gate_guy_intro1_3D8930_s = .;
        build/asm/overlays/gate_guy_intro1/3D8930.s.o(.data);
        overlays_gate_guy_intro1_overlays_gate_guy_intro1_3D8960_s = .;
        build/asm/overlays/gate_guy_intro1/3D8960.s.o(.data);
        build/asm/overlays/gate_guy_intro1/3D8930.s.o(.rodata);
        build/asm/overlays/gate_guy_intro1/3D8960.s.o(.rodata);
        overlays_gate_guy_intro1_DATA_END = .;
        overlays_gate_guy_intro1_BSS_START = .;
        build/asm/overlays/gate_guy_intro1/3D8930.s.o(.bss);
        build/asm/overlays/gate_guy_intro1/3D8960.s.o(.bss);
        overlays_gate_guy_intro1_BSS_END = .;
    }
    overlays_gate_guy_intro1_ROM_END = 0x3D8A90;
    __romPos = 0x3D8A90;

    __romPos = 0x3D8A90;
    . = __romPos;
    overlays_board_gate_guy_ROM_START = __romPos;
    overlays_board_gate_guy_VRAM = ADDR(.overlays_board_gate_guy);
    .overlays_board_gate_guy 0x801059A0 : AT(overlays_board_gate_guy_ROM_START) SUBALIGN(16)
    {
        overlays_board_gate_guy_TEXT_START = .;
        build/asm/overlays/board_gate_guy/3D8A90.s.o(.text);
        build/asm/overlays/board_gate_guy/3D8AC0.s.o(.text);
        overlays_board_gate_guy_TEXT_END = .;
        overlays_board_gate_guy_DATA_START = .;
        overlays_board_gate_guy_3EB7D0_bin = .;
        build/assets/overlays/board_gate_guy/3EB7D0.bin.o(.data);
        overlays_board_gate_guy_overlays_board_gate_guy_3D8A90_s = .;
        build/asm/overlays/board_gate_guy/3D8A90.s.o(.data);
        overlays_board_gate_guy_overlays_board_gate_guy_3D8AC0_s = .;
        build/asm/overlays/board_gate_guy/3D8AC0.s.o(.data);
        build/asm/overlays/board_gate_guy/3D8A90.s.o(.rodata);
        build/asm/overlays/board_gate_guy/3D8AC0.s.o(.rodata);
        overlays_board_gate_guy_DATA_END = .;
        overlays_board_gate_guy_BSS_START = .;
        build/asm/overlays/board_gate_guy/3D8A90.s.o(.bss);
        build/asm/overlays/board_gate_guy/3D8AC0.s.o(.bss);
        overlays_board_gate_guy_BSS_END = .;
    }
    overlays_board_gate_guy_ROM_END = 0x3EC560;
    __romPos = 0x3EC560;

    __romPos = 0x3EC560;
    . = __romPos;
    overlays_board_arrowhead_intro_ROM_START = __romPos;
    overlays_board_arrowhead_intro_VRAM = ADDR(.overlays_board_arrowhead_intro);
    .overlays_board_arrowhead_intro 0x801059A0 : AT(overlays_board_arrowhead_intro_ROM_START) SUBALIGN(16)
    {
        overlays_board_arrowhead_intro_TEXT_START = .;
        build/asm/overlays/board_arrowhead_intro/3EC560.s.o(.text);
        build/asm/overlays/board_arrowhead_intro/3EC590.s.o(.text);
        overlays_board_arrowhead_intro_TEXT_END = .;
        overlays_board_arrowhead_intro_DATA_START = .;
        overlays_board_arrowhead_intro_3FD130_bin = .;
        build/assets/overlays/board_arrowhead_intro/3FD130.bin.o(.data);
        overlays_board_arrowhead_intro_overlays_board_arrowhead_intro_3EC560_s = .;
        build/asm/overlays/board_arrowhead_intro/3EC560.s.o(.data);
        overlays_board_arrowhead_intro_overlays_board_arrowhead_intro_3EC590_s = .;
        build/asm/overlays/board_arrowhead_intro/3EC590.s.o(.data);
        build/asm/overlays/board_arrowhead_intro/3EC560.s.o(.rodata);
        build/asm/overlays/board_arrowhead_intro/3EC590.s.o(.rodata);
        overlays_board_arrowhead_intro_DATA_END = .;
        overlays_board_arrowhead_intro_BSS_START = .;
        build/asm/overlays/board_arrowhead_intro/3EC560.s.o(.bss);
        build/asm/overlays/board_arrowhead_intro/3EC590.s.o(.bss);
        overlays_board_arrowhead_intro_BSS_END = .;
    }
    overlays_board_arrowhead_intro_ROM_END = 0x3FE1C0;
    __romPos = 0x3FE1C0;

    __romPos = 0x3FE1C0;
    . = __romPos;
    overlays_board_pipesqueak_intro_ROM_START = __romPos;
    overlays_board_pipesqueak_intro_VRAM = ADDR(.overlays_board_pipesqueak_intro);
    .overlays_board_pipesqueak_intro 0x801059A0 : AT(overlays_board_pipesqueak_intro_ROM_START) SUBALIGN(16)
    {
        overlays_board_pipesqueak_intro_TEXT_START = .;
        build/asm/overlays/board_pipesqueak_intro/3FE1C0.s.o(.text);
        build/asm/overlays/board_pipesqueak_intro/3FE1F0.s.o(.text);
        overlays_board_pipesqueak_intro_TEXT_END = .;
        overlays_board_pipesqueak_intro_DATA_START = .;
        overlays_board_pipesqueak_intro_40FC20_bin = .;
        build/assets/overlays/board_pipesqueak_intro/40FC20.bin.o(.data);
        overlays_board_pipesqueak_intro_overlays_board_pipesqueak_intro_3FE1C0_s = .;
        build/asm/overlays/board_pipesqueak_intro/3FE1C0.s.o(.data);
        overlays_board_pipesqueak_intro_overlays_board_pipesqueak_intro_3FE1F0_s = .;
        build/asm/overlays/board_pipesqueak_intro/3FE1F0.s.o(.data);
        build/asm/overlays/board_pipesqueak_intro/3FE1C0.s.o(.rodata);
        build/asm/overlays/board_pipesqueak_intro/3FE1F0.s.o(.rodata);
        overlays_board_pipesqueak_intro_DATA_END = .;
        overlays_board_pipesqueak_intro_BSS_START = .;
        build/asm/overlays/board_pipesqueak_intro/3FE1C0.s.o(.bss);
        build/asm/overlays/board_pipesqueak_intro/3FE1F0.s.o(.bss);
        overlays_board_pipesqueak_intro_BSS_END = .;
    }
    overlays_board_pipesqueak_intro_ROM_END = 0x4108E0;
    __romPos = 0x4108E0;

    __romPos = 0x4108E0;
    . = __romPos;
    overlays_board_blowhard_intro_ROM_START = __romPos;
    overlays_board_blowhard_intro_VRAM = ADDR(.overlays_board_blowhard_intro);
    .overlays_board_blowhard_intro 0x801059A0 : AT(overlays_board_blowhard_intro_ROM_START) SUBALIGN(16)
    {
        overlays_board_blowhard_intro_TEXT_START = .;
        build/asm/overlays/board_blowhard_intro/4108E0.s.o(.text);
        build/asm/overlays/board_blowhard_intro/410910.s.o(.text);
        overlays_board_blowhard_intro_TEXT_END = .;
        overlays_board_blowhard_intro_DATA_START = .;
        overlays_board_blowhard_intro_424BB0_bin = .;
        build/assets/overlays/board_blowhard_intro/424BB0.bin.o(.data);
        overlays_board_blowhard_intro_overlays_board_blowhard_intro_4108E0_s = .;
        build/asm/overlays/board_blowhard_intro/4108E0.s.o(.data);
        overlays_board_blowhard_intro_overlays_board_blowhard_intro_410910_s = .;
        build/asm/overlays/board_blowhard_intro/410910.s.o(.data);
        build/asm/overlays/board_blowhard_intro/4108E0.s.o(.rodata);
        build/asm/overlays/board_blowhard_intro/410910.s.o(.rodata);
        overlays_board_blowhard_intro_DATA_END = .;
        overlays_board_blowhard_intro_BSS_START = .;
        build/asm/overlays/board_blowhard_intro/4108E0.s.o(.bss);
        build/asm/overlays/board_blowhard_intro/410910.s.o(.bss);
        overlays_board_blowhard_intro_BSS_END = .;
    }
    overlays_board_blowhard_intro_ROM_END = 0x426420;
    __romPos = 0x426420;

    __romPos = 0x426420;
    . = __romPos;
    overlays_board_mr_mover_intro_ROM_START = __romPos;
    overlays_board_mr_mover_intro_VRAM = ADDR(.overlays_board_mr_mover_intro);
    .overlays_board_mr_mover_intro 0x801059A0 : AT(overlays_board_mr_mover_intro_ROM_START) SUBALIGN(16)
    {
        overlays_board_mr_mover_intro_TEXT_START = .;
        build/asm/overlays/board_mr_mover_intro/426420.s.o(.text);
        build/asm/overlays/board_mr_mover_intro/426450.s.o(.text);
        overlays_board_mr_mover_intro_TEXT_END = .;
        overlays_board_mr_mover_intro_DATA_START = .;
        overlays_board_mr_mover_intro_436100_bin = .;
        build/assets/overlays/board_mr_mover_intro/436100.bin.o(.data);
        overlays_board_mr_mover_intro_overlays_board_mr_mover_intro_426420_s = .;
        build/asm/overlays/board_mr_mover_intro/426420.s.o(.data);
        overlays_board_mr_mover_intro_overlays_board_mr_mover_intro_426450_s = .;
        build/asm/overlays/board_mr_mover_intro/426450.s.o(.data);
        build/asm/overlays/board_mr_mover_intro/426420.s.o(.rodata);
        build/asm/overlays/board_mr_mover_intro/426450.s.o(.rodata);
        overlays_board_mr_mover_intro_DATA_END = .;
        overlays_board_mr_mover_intro_BSS_START = .;
        build/asm/overlays/board_mr_mover_intro/426420.s.o(.bss);
        build/asm/overlays/board_mr_mover_intro/426450.s.o(.bss);
        overlays_board_mr_mover_intro_BSS_END = .;
    }
    overlays_board_mr_mover_intro_ROM_END = 0x436E20;
    __romPos = 0x436E20;

    __romPos = 0x436E20;
    . = __romPos;
    overlays_board_backtrack_intro_ROM_START = __romPos;
    overlays_board_backtrack_intro_VRAM = ADDR(.overlays_board_backtrack_intro);
    .overlays_board_backtrack_intro 0x801059A0 : AT(overlays_board_backtrack_intro_ROM_START) SUBALIGN(16)
    {
        overlays_board_backtrack_intro_TEXT_START = .;
        build/asm/overlays/board_backtrack_intro/436E20.s.o(.text);
        build/asm/overlays/board_backtrack_intro/436E50.s.o(.text);
        overlays_board_backtrack_intro_TEXT_END = .;
        overlays_board_backtrack_intro_DATA_START = .;
        overlays_board_backtrack_intro_445900_bin = .;
        build/assets/overlays/board_backtrack_intro/445900.bin.o(.data);
        overlays_board_backtrack_intro_overlays_board_backtrack_intro_436E20_s = .;
        build/asm/overlays/board_backtrack_intro/436E20.s.o(.data);
        overlays_board_backtrack_intro_overlays_board_backtrack_intro_436E50_s = .;
        build/asm/overlays/board_backtrack_intro/436E50.s.o(.data);
        build/asm/overlays/board_backtrack_intro/436E20.s.o(.rodata);
        build/asm/overlays/board_backtrack_intro/436E50.s.o(.rodata);
        overlays_board_backtrack_intro_DATA_END = .;
        overlays_board_backtrack_intro_BSS_START = .;
        build/asm/overlays/board_backtrack_intro/436E20.s.o(.bss);
        build/asm/overlays/board_backtrack_intro/436E50.s.o(.bss);
        overlays_board_backtrack_intro_BSS_END = .;
    }
    overlays_board_backtrack_intro_ROM_END = 0x4461B0;
    __romPos = 0x4461B0;

    __romPos = 0x4461B0;
    . = __romPos;
    overlays_battle_rules_map_intro_ROM_START = __romPos;
    overlays_battle_rules_map_intro_VRAM = ADDR(.overlays_battle_rules_map_intro);
    .overlays_battle_rules_map_intro 0x801059A0 : AT(overlays_battle_rules_map_intro_ROM_START) SUBALIGN(16)
    {
        overlays_battle_rules_map_intro_TEXT_START = .;
        build/asm/overlays/battle_rules_map_intro/4461B0.s.o(.text);
        build/asm/overlays/battle_rules_map_intro/4461E0.s.o(.text);
        overlays_battle_rules_map_intro_TEXT_END = .;
        overlays_battle_rules_map_intro_DATA_START = .;
        overlays_battle_rules_map_intro_4551C0_bin = .;
        build/assets/overlays/battle_rules_map_intro/4551C0.bin.o(.data);
        overlays_battle_rules_map_intro_overlays_battle_rules_map_intro_4461B0_s = .;
        build/asm/overlays/battle_rules_map_intro/4461B0.s.o(.data);
        overlays_battle_rules_map_intro_overlays_battle_rules_map_intro_4461E0_s = .;
        build/asm/overlays/battle_rules_map_intro/4461E0.s.o(.data);
        build/asm/overlays/battle_rules_map_intro/4461B0.s.o(.rodata);
        build/asm/overlays/battle_rules_map_intro/4461E0.s.o(.rodata);
        overlays_battle_rules_map_intro_DATA_END = .;
        overlays_battle_rules_map_intro_BSS_START = .;
        build/asm/overlays/battle_rules_map_intro/4461B0.s.o(.bss);
        build/asm/overlays/battle_rules_map_intro/4461E0.s.o(.bss);
        overlays_battle_rules_map_intro_BSS_END = .;
    }
    overlays_battle_rules_map_intro_ROM_END = 0x4554C0;
    __romPos = 0x4554C0;

    __romPos = 0x4554C0;
    . = __romPos;
    overlays_results_ROM_START = __romPos;
    overlays_results_VRAM = ADDR(.overlays_results);
    .overlays_results 0x801059A0 : AT(overlays_results_ROM_START) SUBALIGN(16)
    {
        overlays_results_TEXT_START = .;
        build/asm/overlays/results/4554C0.s.o(.text);
        build/asm/overlays/results/45A700.s.o(.text);
        overlays_results_TEXT_END = .;
        overlays_results_DATA_START = .;
        overlays_results_45CDB0_bin = .;
        build/assets/overlays/results/45CDB0.bin.o(.data);
        overlays_results_overlays_results_4554C0_s = .;
        build/asm/overlays/results/4554C0.s.o(.data);
        overlays_results_overlays_results_45A700_s = .;
        build/asm/overlays/results/45A700.s.o(.data);
        build/asm/overlays/results/4554C0.s.o(.rodata);
        build/asm/overlays/results/45A700.s.o(.rodata);
        overlays_results_DATA_END = .;
        overlays_results_BSS_START = .;
        build/asm/overlays/results/4554C0.s.o(.bss);
        build/asm/overlays/results/45A700.s.o(.bss);
        overlays_results_BSS_END = .;
    }
    overlays_results_ROM_END = 0x45D380;
    __romPos = 0x45D380;

    __romPos = 0x45D380;
    . = __romPos;
    overlays_detailed_results_battle_ROM_START = __romPos;
    overlays_detailed_results_battle_VRAM = ADDR(.overlays_detailed_results_battle);
    .overlays_detailed_results_battle 0x801059A0 : AT(overlays_detailed_results_battle_ROM_START) SUBALIGN(16)
    {
        overlays_detailed_results_battle_TEXT_START = .;
        build/asm/overlays/detailed_results_battle/45D380.s.o(.text);
        overlays_detailed_results_battle_TEXT_END = .;
        overlays_detailed_results_battle_DATA_START = .;
        overlays_detailed_results_battle_460610_bin = .;
        build/assets/overlays/detailed_results_battle/460610.bin.o(.data);
        overlays_detailed_results_battle_overlays_detailed_results_battle_45D380_s = .;
        build/asm/overlays/detailed_results_battle/45D380.s.o(.data);
        build/asm/overlays/detailed_results_battle/45D380.s.o(.rodata);
        overlays_detailed_results_battle_DATA_END = .;
        overlays_detailed_results_battle_BSS_START = .;
        build/asm/overlays/detailed_results_battle/45D380.s.o(.bss);
        overlays_detailed_results_battle_BSS_END = .;
    }
    overlays_detailed_results_battle_ROM_END = 0x460790;
    __romPos = 0x460790;

    __romPos = 0x460790;
    . = __romPos;
    overlays_gate_guy_intro2_ROM_START = __romPos;
    overlays_gate_guy_intro2_VRAM = ADDR(.overlays_gate_guy_intro2);
    .overlays_gate_guy_intro2 0x801059A0 : AT(overlays_gate_guy_intro2_ROM_START) SUBALIGN(16)
    {
        overlays_gate_guy_intro2_TEXT_START = .;
        build/asm/overlays/gate_guy_intro2/460790.s.o(.text);
        overlays_gate_guy_intro2_TEXT_END = .;
        overlays_gate_guy_intro2_DATA_START = .;
        overlays_gate_guy_intro2_463FF0_bin = .;
        build/assets/overlays/gate_guy_intro2/463FF0.bin.o(.data);
        overlays_gate_guy_intro2_overlays_gate_guy_intro2_460790_s = .;
        build/asm/overlays/gate_guy_intro2/460790.s.o(.data);
        build/asm/overlays/gate_guy_intro2/460790.s.o(.rodata);
        overlays_gate_guy_intro2_DATA_END = .;
        overlays_gate_guy_intro2_BSS_START = .;
        build/asm/overlays/gate_guy_intro2/460790.s.o(.bss);
        overlays_gate_guy_intro2_BSS_END = .;
    }
    overlays_gate_guy_intro2_ROM_END = 0x464360;
    __romPos = 0x464360;

    __romPos = 0x464360;
    . = __romPos;
    overlays_rules_map_intro_ROM_START = __romPos;
    overlays_rules_map_intro_VRAM = ADDR(.overlays_rules_map_intro);
    .overlays_rules_map_intro 0x801059A0 : AT(overlays_rules_map_intro_ROM_START) SUBALIGN(16)
    {
        overlays_rules_map_intro_TEXT_START = .;
        build/asm/overlays/rules_map_intro/464360.s.o(.text);
        overlays_rules_map_intro_TEXT_END = .;
        overlays_rules_map_intro_DATA_START = .;
        overlays_rules_map_intro_4672F0_bin = .;
        build/assets/overlays/rules_map_intro/4672F0.bin.o(.data);
        overlays_rules_map_intro_overlays_rules_map_intro_464360_s = .;
        build/asm/overlays/rules_map_intro/464360.s.o(.data);
        build/asm/overlays/rules_map_intro/464360.s.o(.rodata);
        overlays_rules_map_intro_DATA_END = .;
        overlays_rules_map_intro_BSS_START = .;
        build/asm/overlays/rules_map_intro/464360.s.o(.bss);
        overlays_rules_map_intro_BSS_END = .;
    }
    overlays_rules_map_intro_ROM_END = 0x4675D0;
    __romPos = 0x4675D0;

    __romPos = 0x4675D0;
    . = __romPos;
    overlays_test_save2_ROM_START = __romPos;
    overlays_test_save2_VRAM = ADDR(.overlays_test_save2);
    .overlays_test_save2 0x801059A0 : AT(overlays_test_save2_ROM_START) SUBALIGN(16)
    {
        overlays_test_save2_TEXT_START = .;
        build/asm/overlays/test_save2/4675D0.s.o(.text);
        build/asm/overlays/test_save2/467600.s.o(.text);
        overlays_test_save2_TEXT_END = .;
        overlays_test_save2_DATA_START = .;
        overlays_test_save2_468310_bin = .;
        build/assets/overlays/test_save2/468310.bin.o(.data);
        overlays_test_save2_overlays_test_save2_4675D0_s = .;
        build/asm/overlays/test_save2/4675D0.s.o(.data);
        overlays_test_save2_overlays_test_save2_467600_s = .;
        build/asm/overlays/test_save2/467600.s.o(.data);
        build/asm/overlays/test_save2/4675D0.s.o(.rodata);
        build/asm/overlays/test_save2/467600.s.o(.rodata);
        overlays_test_save2_DATA_END = .;
        overlays_test_save2_BSS_START = .;
        build/asm/overlays/test_save2/4675D0.s.o(.bss);
        build/asm/overlays/test_save2/467600.s.o(.bss);
        overlays_test_save2_BSS_END = .;
    }
    overlays_test_save2_ROM_END = 0x4684F0;
    __romPos = 0x4684F0;

    __romPos = 0x4684F0;
    . = __romPos;
    overlays_overlay103_ROM_START = __romPos;
    overlays_overlay103_VRAM = ADDR(.overlays_overlay103);
    .overlays_overlay103 0x801059A0 : AT(overlays_overlay103_ROM_START) SUBALIGN(16)
    {
        overlays_overlay103_TEXT_START = .;
        build/asm/overlays/overlay103/4684F0.s.o(.text);
        build/asm/overlays/overlay103/468520.s.o(.text);
        overlays_overlay103_TEXT_END = .;
        overlays_overlay103_DATA_START = .;
        overlays_overlay103_468A70_bin = .;
        build/assets/overlays/overlay103/468A70.bin.o(.data);
        overlays_overlay103_overlays_overlay103_4684F0_s = .;
        build/asm/overlays/overlay103/4684F0.s.o(.data);
        overlays_overlay103_overlays_overlay103_468520_s = .;
        build/asm/overlays/overlay103/468520.s.o(.data);
        build/asm/overlays/overlay103/4684F0.s.o(.rodata);
        build/asm/overlays/overlay103/468520.s.o(.rodata);
        overlays_overlay103_DATA_END = .;
        overlays_overlay103_BSS_START = .;
        build/asm/overlays/overlay103/4684F0.s.o(.bss);
        build/asm/overlays/overlay103/468520.s.o(.bss);
        overlays_overlay103_BSS_END = .;
    }
    overlays_overlay103_ROM_END = 0x468A90;
    __romPos = 0x468A90;

    __romPos = 0x468A90;
    . = __romPos;
    overlays_overlay104_ROM_START = __romPos;
    overlays_overlay104_VRAM = ADDR(.overlays_overlay104);
    .overlays_overlay104 0x801059A0 : AT(overlays_overlay104_ROM_START) SUBALIGN(16)
    {
        overlays_overlay104_TEXT_START = .;
        build/asm/overlays/overlay104/468A90.s.o(.text);
        build/asm/overlays/overlay104/468AC0.s.o(.text);
        build/asm/overlays/overlay104/46BB50.s.o(.text);
        overlays_overlay104_TEXT_END = .;
        overlays_overlay104_DATA_START = .;
        overlays_overlay104_46CB70_bin = .;
        build/assets/overlays/overlay104/46CB70.bin.o(.data);
        overlays_overlay104_overlays_overlay104_468A90_s = .;
        build/asm/overlays/overlay104/468A90.s.o(.data);
        overlays_overlay104_overlays_overlay104_468AC0_s = .;
        build/asm/overlays/overlay104/468AC0.s.o(.data);
        overlays_overlay104_overlays_overlay104_46BB50_s = .;
        build/asm/overlays/overlay104/46BB50.s.o(.data);
        build/asm/overlays/overlay104/468A90.s.o(.rodata);
        build/asm/overlays/overlay104/468AC0.s.o(.rodata);
        build/asm/overlays/overlay104/46BB50.s.o(.rodata);
        overlays_overlay104_DATA_END = .;
        overlays_overlay104_BSS_START = .;
        build/asm/overlays/overlay104/468A90.s.o(.bss);
        build/asm/overlays/overlay104/468AC0.s.o(.bss);
        build/asm/overlays/overlay104/46BB50.s.o(.bss);
        overlays_overlay104_BSS_END = .;
    }
    overlays_overlay104_ROM_END = 0x46CC10;
    __romPos = 0x46CC10;

    __romPos = 0x46CC10;
    . = __romPos;
    overlays_battle_room_ROM_START = __romPos;
    overlays_battle_room_VRAM = ADDR(.overlays_battle_room);
    .overlays_battle_room 0x801059A0 : AT(overlays_battle_room_ROM_START) SUBALIGN(16)
    {
        overlays_battle_room_TEXT_START = .;
        build/asm/overlays/battle_room/46CC10.s.o(.text);
        build/asm/overlays/battle_room/473130.s.o(.text);
        build/asm/overlays/battle_room/479470.s.o(.text);
        build/asm/overlays/battle_room/47D880.s.o(.text);
        build/asm/overlays/battle_room/47DD90.s.o(.text);
        overlays_battle_room_TEXT_END = .;
        overlays_battle_room_DATA_START = .;
        overlays_battle_room_480120_bin = .;
        build/assets/overlays/battle_room/480120.bin.o(.data);
        overlays_battle_room_overlays_battle_room_46CC10_s = .;
        build/asm/overlays/battle_room/46CC10.s.o(.data);
        overlays_battle_room_overlays_battle_room_473130_s = .;
        build/asm/overlays/battle_room/473130.s.o(.data);
        overlays_battle_room_overlays_battle_room_479470_s = .;
        build/asm/overlays/battle_room/479470.s.o(.data);
        overlays_battle_room_overlays_battle_room_47D880_s = .;
        build/asm/overlays/battle_room/47D880.s.o(.data);
        overlays_battle_room_overlays_battle_room_47DD90_s = .;
        build/asm/overlays/battle_room/47DD90.s.o(.data);
        build/asm/overlays/battle_room/46CC10.s.o(.rodata);
        build/asm/overlays/battle_room/473130.s.o(.rodata);
        build/asm/overlays/battle_room/479470.s.o(.rodata);
        build/asm/overlays/battle_room/47D880.s.o(.rodata);
        build/asm/overlays/battle_room/47DD90.s.o(.rodata);
        overlays_battle_room_DATA_END = .;
        overlays_battle_room_BSS_START = .;
        build/asm/overlays/battle_room/46CC10.s.o(.bss);
        build/asm/overlays/battle_room/473130.s.o(.bss);
        build/asm/overlays/battle_room/479470.s.o(.bss);
        build/asm/overlays/battle_room/47D880.s.o(.bss);
        build/asm/overlays/battle_room/47DD90.s.o(.bss);
        overlays_battle_room_BSS_END = .;
    }
    overlays_battle_room_ROM_END = 0x481970;
    __romPos = 0x481970;

    __romPos = 0x481970;
    . = __romPos;
    overlays_chance_time_ROM_START = __romPos;
    overlays_chance_time_VRAM = ADDR(.overlays_chance_time);
    .overlays_chance_time 0x801059A0 : AT(overlays_chance_time_ROM_START) SUBALIGN(16)
    {
        overlays_chance_time_TEXT_START = .;
        build/asm/overlays/chance_time/481970.s.o(.text);
        build/asm/overlays/chance_time/4822F0.s.o(.text);
        build/asm/overlays/chance_time/4832D0.s.o(.text);
        build/asm/overlays/chance_time/487F50.s.o(.text);
        overlays_chance_time_TEXT_END = .;
        overlays_chance_time_DATA_START = .;
        overlays_chance_time_48BAB0_bin = .;
        build/assets/overlays/chance_time/48BAB0.bin.o(.data);
        overlays_chance_time_overlays_chance_time_481970_s = .;
        build/asm/overlays/chance_time/481970.s.o(.data);
        overlays_chance_time_overlays_chance_time_4822F0_s = .;
        build/asm/overlays/chance_time/4822F0.s.o(.data);
        overlays_chance_time_overlays_chance_time_4832D0_s = .;
        build/asm/overlays/chance_time/4832D0.s.o(.data);
        overlays_chance_time_overlays_chance_time_487F50_s = .;
        build/asm/overlays/chance_time/487F50.s.o(.data);
        build/asm/overlays/chance_time/481970.s.o(.rodata);
        build/asm/overlays/chance_time/4822F0.s.o(.rodata);
        build/asm/overlays/chance_time/4832D0.s.o(.rodata);
        build/asm/overlays/chance_time/487F50.s.o(.rodata);
        overlays_chance_time_DATA_END = .;
        overlays_chance_time_BSS_START = .;
        build/asm/overlays/chance_time/481970.s.o(.bss);
        build/asm/overlays/chance_time/4822F0.s.o(.bss);
        build/asm/overlays/chance_time/4832D0.s.o(.bss);
        build/asm/overlays/chance_time/487F50.s.o(.bss);
        overlays_chance_time_BSS_END = .;
    }
    overlays_chance_time_ROM_END = 0x48BE30;
    __romPos = 0x48BE30;

    __romPos = 0x48BE30;
    . = __romPos;
    overlays_story_results_strength_ROM_START = __romPos;
    overlays_story_results_strength_VRAM = ADDR(.overlays_story_results_strength);
    .overlays_story_results_strength 0x801059A0 : AT(overlays_story_results_strength_ROM_START) SUBALIGN(16)
    {
        overlays_story_results_strength_TEXT_START = .;
        build/asm/overlays/story_results_strength/48BE30.s.o(.text);
        build/asm/overlays/story_results_strength/48D950.s.o(.text);
        build/asm/overlays/story_results_strength/492250.s.o(.text);
        build/asm/overlays/story_results_strength/496990.s.o(.text);
        overlays_story_results_strength_TEXT_END = .;
        overlays_story_results_strength_DATA_START = .;
        overlays_story_results_strength_49AF10_bin = .;
        build/assets/overlays/story_results_strength/49AF10.bin.o(.data);
        overlays_story_results_strength_overlays_story_results_strength_48BE30_s = .;
        build/asm/overlays/story_results_strength/48BE30.s.o(.data);
        overlays_story_results_strength_overlays_story_results_strength_48D950_s = .;
        build/asm/overlays/story_results_strength/48D950.s.o(.data);
        overlays_story_results_strength_overlays_story_results_strength_492250_s = .;
        build/asm/overlays/story_results_strength/492250.s.o(.data);
        overlays_story_results_strength_overlays_story_results_strength_496990_s = .;
        build/asm/overlays/story_results_strength/496990.s.o(.data);
        build/asm/overlays/story_results_strength/48BE30.s.o(.rodata);
        build/asm/overlays/story_results_strength/48D950.s.o(.rodata);
        build/asm/overlays/story_results_strength/492250.s.o(.rodata);
        build/asm/overlays/story_results_strength/496990.s.o(.rodata);
        overlays_story_results_strength_DATA_END = .;
        overlays_story_results_strength_BSS_START = .;
        build/asm/overlays/story_results_strength/48BE30.s.o(.bss);
        build/asm/overlays/story_results_strength/48D950.s.o(.bss);
        build/asm/overlays/story_results_strength/492250.s.o(.bss);
        build/asm/overlays/story_results_strength/496990.s.o(.bss);
        overlays_story_results_strength_BSS_END = .;
    }
    overlays_story_results_strength_ROM_END = 0x49BD40;
    __romPos = 0x49BD40;

    __romPos = 0x49BD40;
    . = __romPos;
    overlays_story_results_peach_ROM_START = __romPos;
    overlays_story_results_peach_VRAM = ADDR(.overlays_story_results_peach);
    .overlays_story_results_peach 0x801059A0 : AT(overlays_story_results_peach_ROM_START) SUBALIGN(16)
    {
        overlays_story_results_peach_TEXT_START = .;
        build/asm/overlays/story_results_peach/49BD40.s.o(.text);
        build/asm/overlays/story_results_peach/49DF30.s.o(.text);
        build/asm/overlays/story_results_peach/4A7540.s.o(.text);
        build/asm/overlays/story_results_peach/4AC200.s.o(.text);
        build/asm/overlays/story_results_peach/4B0E80.s.o(.text);
        overlays_story_results_peach_TEXT_END = .;
        overlays_story_results_peach_DATA_START = .;
        overlays_story_results_peach_4B1CC0_bin = .;
        build/assets/overlays/story_results_peach/4B1CC0.bin.o(.data);
        overlays_story_results_peach_overlays_story_results_peach_49BD40_s = .;
        build/asm/overlays/story_results_peach/49BD40.s.o(.data);
        overlays_story_results_peach_overlays_story_results_peach_49DF30_s = .;
        build/asm/overlays/story_results_peach/49DF30.s.o(.data);
        overlays_story_results_peach_overlays_story_results_peach_4A7540_s = .;
        build/asm/overlays/story_results_peach/4A7540.s.o(.data);
        overlays_story_results_peach_overlays_story_results_peach_4AC200_s = .;
        build/asm/overlays/story_results_peach/4AC200.s.o(.data);
        overlays_story_results_peach_overlays_story_results_peach_4B0E80_s = .;
        build/asm/overlays/story_results_peach/4B0E80.s.o(.data);
        build/asm/overlays/story_results_peach/49BD40.s.o(.rodata);
        build/asm/overlays/story_results_peach/49DF30.s.o(.rodata);
        build/asm/overlays/story_results_peach/4A7540.s.o(.rodata);
        build/asm/overlays/story_results_peach/4AC200.s.o(.rodata);
        build/asm/overlays/story_results_peach/4B0E80.s.o(.rodata);
        overlays_story_results_peach_DATA_END = .;
        overlays_story_results_peach_BSS_START = .;
        build/asm/overlays/story_results_peach/49BD40.s.o(.bss);
        build/asm/overlays/story_results_peach/49DF30.s.o(.bss);
        build/asm/overlays/story_results_peach/4A7540.s.o(.bss);
        build/asm/overlays/story_results_peach/4AC200.s.o(.bss);
        build/asm/overlays/story_results_peach/4B0E80.s.o(.bss);
        overlays_story_results_peach_BSS_END = .;
    }
    overlays_story_results_peach_ROM_END = 0x4B29E0;
    __romPos = 0x4B29E0;

    __romPos = 0x4B29E0;
    . = __romPos;
    overlays_story_results_luigi_ROM_START = __romPos;
    overlays_story_results_luigi_VRAM = ADDR(.overlays_story_results_luigi);
    .overlays_story_results_luigi 0x801059A0 : AT(overlays_story_results_luigi_ROM_START) SUBALIGN(16)
    {
        overlays_story_results_luigi_TEXT_START = .;
        build/asm/overlays/story_results_luigi/4B29E0.s.o(.text);
        build/asm/overlays/story_results_luigi/4B4DC0.s.o(.text);
        build/asm/overlays/story_results_luigi/4B9A30.s.o(.text);
        overlays_story_results_luigi_TEXT_END = .;
        overlays_story_results_luigi_DATA_START = .;
        overlays_story_results_luigi_4C22A0_bin = .;
        build/assets/overlays/story_results_luigi/4C22A0.bin.o(.data);
        overlays_story_results_luigi_overlays_story_results_luigi_4B29E0_s = .;
        build/asm/overlays/story_results_luigi/4B29E0.s.o(.data);
        overlays_story_results_luigi_overlays_story_results_luigi_4B4DC0_s = .;
        build/asm/overlays/story_results_luigi/4B4DC0.s.o(.data);
        overlays_story_results_luigi_overlays_story_results_luigi_4B9A30_s = .;
        build/asm/overlays/story_results_luigi/4B9A30.s.o(.data);
        build/asm/overlays/story_results_luigi/4B29E0.s.o(.rodata);
        build/asm/overlays/story_results_luigi/4B4DC0.s.o(.rodata);
        build/asm/overlays/story_results_luigi/4B9A30.s.o(.rodata);
        overlays_story_results_luigi_DATA_END = .;
        overlays_story_results_luigi_BSS_START = .;
        build/asm/overlays/story_results_luigi/4B29E0.s.o(.bss);
        build/asm/overlays/story_results_luigi/4B4DC0.s.o(.bss);
        build/asm/overlays/story_results_luigi/4B9A30.s.o(.bss);
        overlays_story_results_luigi_BSS_END = .;
    }
    overlays_story_results_luigi_ROM_END = 0x4C2BD0;
    __romPos = 0x4C2BD0;

    __romPos = 0x4C2BD0;
    . = __romPos;
    overlays_story_results_110_ROM_START = __romPos;
    overlays_story_results_110_VRAM = ADDR(.overlays_story_results_110);
    .overlays_story_results_110 0x801059A0 : AT(overlays_story_results_110_ROM_START) SUBALIGN(16)
    {
        overlays_story_results_110_TEXT_START = .;
        build/asm/overlays/story_results_110/4C2BD0.s.o(.text);
        build/asm/overlays/story_results_110/4C47E0.s.o(.text);
        build/asm/overlays/story_results_110/4C8050.s.o(.text);
        overlays_story_results_110_TEXT_END = .;
        overlays_story_results_110_DATA_START = .;
        overlays_story_results_110_4CECF0_bin = .;
        build/assets/overlays/story_results_110/4CECF0.bin.o(.data);
        overlays_story_results_110_overlays_story_results_110_4C2BD0_s = .;
        build/asm/overlays/story_results_110/4C2BD0.s.o(.data);
        overlays_story_results_110_overlays_story_results_110_4C47E0_s = .;
        build/asm/overlays/story_results_110/4C47E0.s.o(.data);
        overlays_story_results_110_overlays_story_results_110_4C8050_s = .;
        build/asm/overlays/story_results_110/4C8050.s.o(.data);
        build/asm/overlays/story_results_110/4C2BD0.s.o(.rodata);
        build/asm/overlays/story_results_110/4C47E0.s.o(.rodata);
        build/asm/overlays/story_results_110/4C8050.s.o(.rodata);
        overlays_story_results_110_DATA_END = .;
        overlays_story_results_110_BSS_START = .;
        build/asm/overlays/story_results_110/4C2BD0.s.o(.bss);
        build/asm/overlays/story_results_110/4C47E0.s.o(.bss);
        build/asm/overlays/story_results_110/4C8050.s.o(.bss);
        overlays_story_results_110_BSS_END = .;
    }
    overlays_story_results_110_ROM_END = 0x4CF350;
    __romPos = 0x4CF350;

    __romPos = 0x4CF350;
    . = __romPos;
    overlays_story_results_111_ROM_START = __romPos;
    overlays_story_results_111_VRAM = ADDR(.overlays_story_results_111);
    .overlays_story_results_111 0x801059A0 : AT(overlays_story_results_111_ROM_START) SUBALIGN(16)
    {
        overlays_story_results_111_TEXT_START = .;
        build/asm/overlays/story_results_111/4CF350.s.o(.text);
        build/asm/overlays/story_results_111/4D8E80.s.o(.text);
        overlays_story_results_111_TEXT_END = .;
        overlays_story_results_111_DATA_START = .;
        overlays_story_results_111_4DE0E0_bin = .;
        build/assets/overlays/story_results_111/4DE0E0.bin.o(.data);
        overlays_story_results_111_overlays_story_results_111_4CF350_s = .;
        build/asm/overlays/story_results_111/4CF350.s.o(.data);
        overlays_story_results_111_overlays_story_results_111_4D8E80_s = .;
        build/asm/overlays/story_results_111/4D8E80.s.o(.data);
        build/asm/overlays/story_results_111/4CF350.s.o(.rodata);
        build/asm/overlays/story_results_111/4D8E80.s.o(.rodata);
        overlays_story_results_111_DATA_END = .;
        overlays_story_results_111_BSS_START = .;
        build/asm/overlays/story_results_111/4CF350.s.o(.bss);
        build/asm/overlays/story_results_111/4D8E80.s.o(.bss);
        overlays_story_results_111_BSS_END = .;
    }
    overlays_story_results_111_ROM_END = 0x4DEB60;
    __romPos = 0x4DEB60;

    __romPos = 0x4DEB60;
    . = __romPos;
    overlays_minigame_instructions_ROM_START = __romPos;
    overlays_minigame_instructions_VRAM = ADDR(.overlays_minigame_instructions);
    .overlays_minigame_instructions 0x801059A0 : AT(overlays_minigame_instructions_ROM_START) SUBALIGN(16)
    {
        overlays_minigame_instructions_TEXT_START = .;
        build/asm/overlays/minigame_instructions/4DEB60.s.o(.text);
        build/asm/overlays/minigame_instructions/4E0630.s.o(.text);
        build/asm/overlays/minigame_instructions/4E1510.s.o(.text);
        build/asm/overlays/minigame_instructions/4E1CB0.s.o(.text);
        build/asm/overlays/minigame_instructions/4E2670.s.o(.text);
        build/asm/overlays/minigame_instructions/4E2C50.s.o(.text);
        build/asm/overlays/minigame_instructions/4E3390.s.o(.text);
        build/asm/overlays/minigame_instructions/4E4B50.s.o(.text);
        overlays_minigame_instructions_TEXT_END = .;
        overlays_minigame_instructions_DATA_START = .;
        overlays_minigame_instructions_4E65C0_bin = .;
        build/assets/overlays/minigame_instructions/4E65C0.bin.o(.data);
        overlays_minigame_instructions_overlays_minigame_instructions_4DEB60_s = .;
        build/asm/overlays/minigame_instructions/4DEB60.s.o(.data);
        overlays_minigame_instructions_overlays_minigame_instructions_4E0630_s = .;
        build/asm/overlays/minigame_instructions/4E0630.s.o(.data);
        overlays_minigame_instructions_overlays_minigame_instructions_4E1510_s = .;
        build/asm/overlays/minigame_instructions/4E1510.s.o(.data);
        overlays_minigame_instructions_overlays_minigame_instructions_4E1CB0_s = .;
        build/asm/overlays/minigame_instructions/4E1CB0.s.o(.data);
        overlays_minigame_instructions_overlays_minigame_instructions_4E2670_s = .;
        build/asm/overlays/minigame_instructions/4E2670.s.o(.data);
        overlays_minigame_instructions_overlays_minigame_instructions_4E2C50_s = .;
        build/asm/overlays/minigame_instructions/4E2C50.s.o(.data);
        overlays_minigame_instructions_overlays_minigame_instructions_4E3390_s = .;
        build/asm/overlays/minigame_instructions/4E3390.s.o(.data);
        overlays_minigame_instructions_overlays_minigame_instructions_4E4B50_s = .;
        build/asm/overlays/minigame_instructions/4E4B50.s.o(.data);
        build/asm/overlays/minigame_instructions/4DEB60.s.o(.rodata);
        build/asm/overlays/minigame_instructions/4E0630.s.o(.rodata);
        build/asm/overlays/minigame_instructions/4E1510.s.o(.rodata);
        build/asm/overlays/minigame_instructions/4E1CB0.s.o(.rodata);
        build/asm/overlays/minigame_instructions/4E2670.s.o(.rodata);
        build/asm/overlays/minigame_instructions/4E2C50.s.o(.rodata);
        build/asm/overlays/minigame_instructions/4E3390.s.o(.rodata);
        build/asm/overlays/minigame_instructions/4E4B50.s.o(.rodata);
        overlays_minigame_instructions_DATA_END = .;
        overlays_minigame_instructions_BSS_START = .;
        build/asm/overlays/minigame_instructions/4DEB60.s.o(.bss);
        build/asm/overlays/minigame_instructions/4E0630.s.o(.bss);
        build/asm/overlays/minigame_instructions/4E1510.s.o(.bss);
        build/asm/overlays/minigame_instructions/4E1CB0.s.o(.bss);
        build/asm/overlays/minigame_instructions/4E2670.s.o(.bss);
        build/asm/overlays/minigame_instructions/4E2C50.s.o(.bss);
        build/asm/overlays/minigame_instructions/4E3390.s.o(.bss);
        build/asm/overlays/minigame_instructions/4E4B50.s.o(.bss);
        overlays_minigame_instructions_BSS_END = .;
    }
    overlays_minigame_instructions_ROM_END = 0x4E6DC0;
    __romPos = 0x4E6DC0;

    __romPos = 0x4E6DC0;
    . = __romPos;
    overlays_minigame_results_ROM_START = __romPos;
    overlays_minigame_results_VRAM = ADDR(.overlays_minigame_results);
    .overlays_minigame_results 0x801059A0 : AT(overlays_minigame_results_ROM_START) SUBALIGN(16)
    {
        overlays_minigame_results_TEXT_START = .;
        build/asm/overlays/minigame_results/4E6DC0.s.o(.text);
        build/asm/overlays/minigame_results/4E8F60.s.o(.text);
        build/asm/overlays/minigame_results/4E9120.s.o(.text);
        build/asm/overlays/minigame_results/4EB420.s.o(.text);
        build/asm/overlays/minigame_results/4EBD50.s.o(.text);
        overlays_minigame_results_TEXT_END = .;
        overlays_minigame_results_DATA_START = .;
        overlays_minigame_results_4EBF10_bin = .;
        build/assets/overlays/minigame_results/4EBF10.bin.o(.data);
        overlays_minigame_results_overlays_minigame_results_4E6DC0_s = .;
        build/asm/overlays/minigame_results/4E6DC0.s.o(.data);
        overlays_minigame_results_overlays_minigame_results_4E8F60_s = .;
        build/asm/overlays/minigame_results/4E8F60.s.o(.data);
        overlays_minigame_results_overlays_minigame_results_4E9120_s = .;
        build/asm/overlays/minigame_results/4E9120.s.o(.data);
        overlays_minigame_results_overlays_minigame_results_4EB420_s = .;
        build/asm/overlays/minigame_results/4EB420.s.o(.data);
        overlays_minigame_results_overlays_minigame_results_4EBD50_s = .;
        build/asm/overlays/minigame_results/4EBD50.s.o(.data);
        build/asm/overlays/minigame_results/4E6DC0.s.o(.rodata);
        build/asm/overlays/minigame_results/4E8F60.s.o(.rodata);
        build/asm/overlays/minigame_results/4E9120.s.o(.rodata);
        build/asm/overlays/minigame_results/4EB420.s.o(.rodata);
        build/asm/overlays/minigame_results/4EBD50.s.o(.rodata);
        overlays_minigame_results_DATA_END = .;
        overlays_minigame_results_BSS_START = .;
        build/asm/overlays/minigame_results/4E6DC0.s.o(.bss);
        build/asm/overlays/minigame_results/4E8F60.s.o(.bss);
        build/asm/overlays/minigame_results/4E9120.s.o(.bss);
        build/asm/overlays/minigame_results/4EB420.s.o(.bss);
        build/asm/overlays/minigame_results/4EBD50.s.o(.bss);
        overlays_minigame_results_BSS_END = .;
    }
    overlays_minigame_results_ROM_END = 0x4EC1B0;
    __romPos = 0x4EC1B0;

    __romPos = 0x4EC1B0;
    . = __romPos;
    overlays_game_guy_results_ROM_START = __romPos;
    overlays_game_guy_results_VRAM = ADDR(.overlays_game_guy_results);
    .overlays_game_guy_results 0x801059A0 : AT(overlays_game_guy_results_ROM_START) SUBALIGN(16)
    {
        overlays_game_guy_results_TEXT_START = .;
        build/asm/overlays/game_guy_results/4EC1B0.s.o(.text);
        build/asm/overlays/game_guy_results/4ECDE0.s.o(.text);
        build/asm/overlays/game_guy_results/4EDCB0.s.o(.text);
        overlays_game_guy_results_TEXT_END = .;
        overlays_game_guy_results_DATA_START = .;
        overlays_game_guy_results_4F00D0_bin = .;
        build/assets/overlays/game_guy_results/4F00D0.bin.o(.data);
        overlays_game_guy_results_overlays_game_guy_results_4EC1B0_s = .;
        build/asm/overlays/game_guy_results/4EC1B0.s.o(.data);
        overlays_game_guy_results_overlays_game_guy_results_4ECDE0_s = .;
        build/asm/overlays/game_guy_results/4ECDE0.s.o(.data);
        overlays_game_guy_results_overlays_game_guy_results_4EDCB0_s = .;
        build/asm/overlays/game_guy_results/4EDCB0.s.o(.data);
        build/asm/overlays/game_guy_results/4EC1B0.s.o(.rodata);
        build/asm/overlays/game_guy_results/4ECDE0.s.o(.rodata);
        build/asm/overlays/game_guy_results/4EDCB0.s.o(.rodata);
        overlays_game_guy_results_DATA_END = .;
        overlays_game_guy_results_BSS_START = .;
        build/asm/overlays/game_guy_results/4EC1B0.s.o(.bss);
        build/asm/overlays/game_guy_results/4ECDE0.s.o(.bss);
        build/asm/overlays/game_guy_results/4EDCB0.s.o(.bss);
        overlays_game_guy_results_BSS_END = .;
    }
    overlays_game_guy_results_ROM_END = 0x4F01F0;
    __romPos = 0x4F01F0;

    __romPos = 0x4F01F0;
    . = __romPos;
    overlays_battle_minigame_results_ROM_START = __romPos;
    overlays_battle_minigame_results_VRAM = ADDR(.overlays_battle_minigame_results);
    .overlays_battle_minigame_results 0x801059A0 : AT(overlays_battle_minigame_results_ROM_START) SUBALIGN(16)
    {
        overlays_battle_minigame_results_TEXT_START = .;
        build/asm/overlays/battle_minigame_results/4F01F0.s.o(.text);
        build/asm/overlays/battle_minigame_results/4F1180.s.o(.text);
        overlays_battle_minigame_results_TEXT_END = .;
        overlays_battle_minigame_results_DATA_START = .;
        overlays_battle_minigame_results_4F36C0_bin = .;
        build/assets/overlays/battle_minigame_results/4F36C0.bin.o(.data);
        overlays_battle_minigame_results_overlays_battle_minigame_results_4F01F0_s = .;
        build/asm/overlays/battle_minigame_results/4F01F0.s.o(.data);
        overlays_battle_minigame_results_overlays_battle_minigame_results_4F1180_s = .;
        build/asm/overlays/battle_minigame_results/4F1180.s.o(.data);
        build/asm/overlays/battle_minigame_results/4F01F0.s.o(.rodata);
        build/asm/overlays/battle_minigame_results/4F1180.s.o(.rodata);
        overlays_battle_minigame_results_DATA_END = .;
        overlays_battle_minigame_results_BSS_START = .;
        build/asm/overlays/battle_minigame_results/4F01F0.s.o(.bss);
        build/asm/overlays/battle_minigame_results/4F1180.s.o(.bss);
        overlays_battle_minigame_results_BSS_END = .;
    }
    overlays_battle_minigame_results_ROM_END = 0x4F3780;
    __romPos = 0x4F3780;

    __romPos = 0x4F3780;
    . = __romPos;
    overlays_battle_results_ROM_START = __romPos;
    overlays_battle_results_VRAM = ADDR(.overlays_battle_results);
    .overlays_battle_results 0x801059A0 : AT(overlays_battle_results_ROM_START) SUBALIGN(16)
    {
        overlays_battle_results_TEXT_START = .;
        build/asm/overlays/battle_results/4F3780.s.o(.text);
        build/asm/overlays/battle_results/4F4980.s.o(.text);
        build/asm/overlays/battle_results/4F5AF0.s.o(.text);
        overlays_battle_results_TEXT_END = .;
        overlays_battle_results_DATA_START = .;
        overlays_battle_results_4F66B0_bin = .;
        build/assets/overlays/battle_results/4F66B0.bin.o(.data);
        overlays_battle_results_overlays_battle_results_4F3780_s = .;
        build/asm/overlays/battle_results/4F3780.s.o(.data);
        overlays_battle_results_overlays_battle_results_4F4980_s = .;
        build/asm/overlays/battle_results/4F4980.s.o(.data);
        overlays_battle_results_overlays_battle_results_4F5AF0_s = .;
        build/asm/overlays/battle_results/4F5AF0.s.o(.data);
        build/asm/overlays/battle_results/4F3780.s.o(.rodata);
        build/asm/overlays/battle_results/4F4980.s.o(.rodata);
        build/asm/overlays/battle_results/4F5AF0.s.o(.rodata);
        overlays_battle_results_DATA_END = .;
        overlays_battle_results_BSS_START = .;
        build/asm/overlays/battle_results/4F3780.s.o(.bss);
        build/asm/overlays/battle_results/4F4980.s.o(.bss);
        build/asm/overlays/battle_results/4F5AF0.s.o(.bss);
        overlays_battle_results_BSS_END = .;
    }
    overlays_battle_results_ROM_END = 0x4F6810;
    __romPos = 0x4F6810;

    __romPos = 0x4F6810;
    . = __romPos;
    overlays_wrapper2_ROM_START = __romPos;
    overlays_wrapper2_VRAM = ADDR(.overlays_wrapper2);
    .overlays_wrapper2 0x801059A0 : AT(overlays_wrapper2_ROM_START) SUBALIGN(16)
    {
        overlays_wrapper2_TEXT_START = .;
        build/asm/overlays/wrapper2/4F6810.s.o(.text);
        overlays_wrapper2_TEXT_END = .;
        overlays_wrapper2_DATA_START = .;
        overlays_wrapper2_4F69B0_bin = .;
        build/assets/overlays/wrapper2/4F69B0.bin.o(.data);
        overlays_wrapper2_overlays_wrapper2_4F6810_s = .;
        build/asm/overlays/wrapper2/4F6810.s.o(.data);
        build/asm/overlays/wrapper2/4F6810.s.o(.rodata);
        overlays_wrapper2_DATA_END = .;
        overlays_wrapper2_BSS_START = .;
        build/asm/overlays/wrapper2/4F6810.s.o(.bss);
        overlays_wrapper2_BSS_END = .;
    }
    overlays_wrapper2_ROM_END = 0x4F69F0;
    __romPos = 0x4F69F0;

    __romPos = 0x4F69F0;
    . = __romPos;
    overlays_debug_message_check_ROM_START = __romPos;
    overlays_debug_message_check_VRAM = ADDR(.overlays_debug_message_check);
    .overlays_debug_message_check 0x801059A0 : AT(overlays_debug_message_check_ROM_START) SUBALIGN(16)
    {
        overlays_debug_message_check_TEXT_START = .;
        build/asm/overlays/debug_message_check/4F69F0.s.o(.text);
        overlays_debug_message_check_TEXT_END = .;
        overlays_debug_message_check_DATA_START = .;
        overlays_debug_message_check_4F7550_bin = .;
        build/assets/overlays/debug_message_check/4F7550.bin.o(.data);
        overlays_debug_message_check_overlays_debug_message_check_4F69F0_s = .;
        build/asm/overlays/debug_message_check/4F69F0.s.o(.data);
        build/asm/overlays/debug_message_check/4F69F0.s.o(.rodata);
        overlays_debug_message_check_DATA_END = .;
        overlays_debug_message_check_BSS_START = .;
        build/asm/overlays/debug_message_check/4F69F0.s.o(.bss);
        overlays_debug_message_check_BSS_END = .;
    }
    overlays_debug_message_check_ROM_END = 0x4F7E90;
    __romPos = 0x4F7E90;

    __romPos = 0x4F7E90;
    . = __romPos;
    overlays_castle_grounds_ROM_START = __romPos;
    overlays_castle_grounds_VRAM = ADDR(.overlays_castle_grounds);
    .overlays_castle_grounds 0x801059A0 : AT(overlays_castle_grounds_ROM_START) SUBALIGN(16)
    {
        overlays_castle_grounds_TEXT_START = .;
        build/asm/overlays/castle_grounds/4F7E90.s.o(.text);
        build/asm/overlays/castle_grounds/4F7EC0.s.o(.text);
        build/asm/overlays/castle_grounds/4F8140.s.o(.text);
        overlays_castle_grounds_TEXT_END = .;
        overlays_castle_grounds_DATA_START = .;
        overlays_castle_grounds_501760_bin = .;
        build/assets/overlays/castle_grounds/501760.bin.o(.data);
        overlays_castle_grounds_overlays_castle_grounds_4F7E90_s = .;
        build/asm/overlays/castle_grounds/4F7E90.s.o(.data);
        overlays_castle_grounds_overlays_castle_grounds_4F7EC0_s = .;
        build/asm/overlays/castle_grounds/4F7EC0.s.o(.data);
        overlays_castle_grounds_overlays_castle_grounds_4F8140_s = .;
        build/asm/overlays/castle_grounds/4F8140.s.o(.data);
        build/asm/overlays/castle_grounds/4F7E90.s.o(.rodata);
        build/asm/overlays/castle_grounds/4F7EC0.s.o(.rodata);
        build/asm/overlays/castle_grounds/4F8140.s.o(.rodata);
        overlays_castle_grounds_DATA_END = .;
        overlays_castle_grounds_BSS_START = .;
        build/asm/overlays/castle_grounds/4F7E90.s.o(.bss);
        build/asm/overlays/castle_grounds/4F7EC0.s.o(.bss);
        build/asm/overlays/castle_grounds/4F8140.s.o(.bss);
        overlays_castle_grounds_BSS_END = .;
    }
    overlays_castle_grounds_ROM_END = 0x501C00;
    __romPos = 0x501C00;

    __romPos = 0x501C00;
    . = __romPos;
    overlays_star_lift_ROM_START = __romPos;
    overlays_star_lift_VRAM = ADDR(.overlays_star_lift);
    .overlays_star_lift 0x801059A0 : AT(overlays_star_lift_ROM_START) SUBALIGN(16)
    {
        overlays_star_lift_TEXT_START = .;
        build/asm/overlays/star_lift/501C00.s.o(.text);
        build/asm/overlays/star_lift/506F20.s.o(.text);
        build/asm/overlays/star_lift/508D50.s.o(.text);
        build/asm/overlays/star_lift/5092C0.s.o(.text);
        build/asm/overlays/star_lift/50B740.s.o(.text);
        build/asm/overlays/star_lift/513B70.s.o(.text);
        overlays_star_lift_TEXT_END = .;
        overlays_star_lift_DATA_START = .;
        overlays_star_lift_515670_bin = .;
        build/assets/overlays/star_lift/515670.bin.o(.data);
        overlays_star_lift_overlays_star_lift_501C00_s = .;
        build/asm/overlays/star_lift/501C00.s.o(.data);
        overlays_star_lift_overlays_star_lift_506F20_s = .;
        build/asm/overlays/star_lift/506F20.s.o(.data);
        overlays_star_lift_overlays_star_lift_508D50_s = .;
        build/asm/overlays/star_lift/508D50.s.o(.data);
        overlays_star_lift_overlays_star_lift_5092C0_s = .;
        build/asm/overlays/star_lift/5092C0.s.o(.data);
        overlays_star_lift_overlays_star_lift_50B740_s = .;
        build/asm/overlays/star_lift/50B740.s.o(.data);
        overlays_star_lift_overlays_star_lift_513B70_s = .;
        build/asm/overlays/star_lift/513B70.s.o(.data);
        build/asm/overlays/star_lift/501C00.s.o(.rodata);
        build/asm/overlays/star_lift/506F20.s.o(.rodata);
        build/asm/overlays/star_lift/508D50.s.o(.rodata);
        build/asm/overlays/star_lift/5092C0.s.o(.rodata);
        build/asm/overlays/star_lift/50B740.s.o(.rodata);
        build/asm/overlays/star_lift/513B70.s.o(.rodata);
        overlays_star_lift_DATA_END = .;
        overlays_star_lift_BSS_START = .;
        build/asm/overlays/star_lift/501C00.s.o(.bss);
        build/asm/overlays/star_lift/506F20.s.o(.bss);
        build/asm/overlays/star_lift/508D50.s.o(.bss);
        build/asm/overlays/star_lift/5092C0.s.o(.bss);
        build/asm/overlays/star_lift/50B740.s.o(.bss);
        build/asm/overlays/star_lift/513B70.s.o(.bss);
        overlays_star_lift_BSS_END = .;
    }
    overlays_star_lift_ROM_END = 0x516AE0;
    __romPos = 0x516AE0;

    __romPos = 0x516AE0;
    . = __romPos;
    overlays_file_select_ROM_START = __romPos;
    overlays_file_select_VRAM = ADDR(.overlays_file_select);
    .overlays_file_select 0x801059A0 : AT(overlays_file_select_ROM_START) SUBALIGN(16)
    {
        overlays_file_select_TEXT_START = .;
        build/asm/overlays/file_select/516AE0.s.o(.text);
        build/asm/overlays/file_select/516B10.s.o(.text);
        build/asm/overlays/file_select/516D30.s.o(.text);
        overlays_file_select_TEXT_END = .;
        overlays_file_select_DATA_START = .;
        overlays_file_select_5238E0_bin = .;
        build/assets/overlays/file_select/5238E0.bin.o(.data);
        overlays_file_select_overlays_file_select_516AE0_s = .;
        build/asm/overlays/file_select/516AE0.s.o(.data);
        overlays_file_select_overlays_file_select_516B10_s = .;
        build/asm/overlays/file_select/516B10.s.o(.data);
        overlays_file_select_overlays_file_select_516D30_s = .;
        build/asm/overlays/file_select/516D30.s.o(.data);
        build/asm/overlays/file_select/516AE0.s.o(.rodata);
        build/asm/overlays/file_select/516B10.s.o(.rodata);
        build/asm/overlays/file_select/516D30.s.o(.rodata);
        overlays_file_select_DATA_END = .;
        overlays_file_select_BSS_START = .;
        build/asm/overlays/file_select/516AE0.s.o(.bss);
        build/asm/overlays/file_select/516B10.s.o(.bss);
        build/asm/overlays/file_select/516D30.s.o(.bss);
        overlays_file_select_BSS_END = .;
    }
    overlays_file_select_ROM_END = 0x523FD0;
    __romPos = 0x523FD0;

    __romPos = 0x523FD0;
    . = __romPos;
    overlays_start_screen_ROM_START = __romPos;
    overlays_start_screen_VRAM = ADDR(.overlays_start_screen);
    .overlays_start_screen 0x801059A0 : AT(overlays_start_screen_ROM_START) SUBALIGN(16)
    {
        overlays_start_screen_TEXT_START = .;
        build/asm/overlays/start_screen/523FD0.s.o(.text);
        build/asm/overlays/start_screen/524000.s.o(.text);
        build/asm/overlays/start_screen/5242B0.s.o(.text);
        build/asm/overlays/start_screen/524820.s.o(.text);
        overlays_start_screen_TEXT_END = .;
        overlays_start_screen_DATA_START = .;
        overlays_start_screen_533180_bin = .;
        build/assets/overlays/start_screen/533180.bin.o(.data);
        overlays_start_screen_overlays_start_screen_523FD0_s = .;
        build/asm/overlays/start_screen/523FD0.s.o(.data);
        overlays_start_screen_overlays_start_screen_524000_s = .;
        build/asm/overlays/start_screen/524000.s.o(.data);
        overlays_start_screen_overlays_start_screen_5242B0_s = .;
        build/asm/overlays/start_screen/5242B0.s.o(.data);
        overlays_start_screen_overlays_start_screen_524820_s = .;
        build/asm/overlays/start_screen/524820.s.o(.data);
        build/asm/overlays/start_screen/523FD0.s.o(.rodata);
        build/asm/overlays/start_screen/524000.s.o(.rodata);
        build/asm/overlays/start_screen/5242B0.s.o(.rodata);
        build/asm/overlays/start_screen/524820.s.o(.rodata);
        overlays_start_screen_DATA_END = .;
        overlays_start_screen_BSS_START = .;
        build/asm/overlays/start_screen/523FD0.s.o(.bss);
        build/asm/overlays/start_screen/524000.s.o(.bss);
        build/asm/overlays/start_screen/5242B0.s.o(.bss);
        build/asm/overlays/start_screen/524820.s.o(.bss);
        overlays_start_screen_BSS_END = .;
    }
    overlays_start_screen_ROM_END = 0x5334D0;
    __romPos = 0x5334D0;

    __romPos = 0x5334D0;
    . = __romPos;
    overlays_inside_castle_ROM_START = __romPos;
    overlays_inside_castle_VRAM = ADDR(.overlays_inside_castle);
    .overlays_inside_castle 0x801059A0 : AT(overlays_inside_castle_ROM_START) SUBALIGN(16)
    {
        overlays_inside_castle_TEXT_START = .;
        build/asm/overlays/inside_castle/5334D0.s.o(.text);
        build/asm/overlays/inside_castle/533500.s.o(.text);
        build/asm/overlays/inside_castle/535A80.s.o(.text);
        build/asm/overlays/inside_castle/53DCA0.s.o(.text);
        overlays_inside_castle_TEXT_END = .;
        overlays_inside_castle_DATA_START = .;
        overlays_inside_castle_540FE0_bin = .;
        build/assets/overlays/inside_castle/540FE0.bin.o(.data);
        overlays_inside_castle_overlays_inside_castle_5334D0_s = .;
        build/asm/overlays/inside_castle/5334D0.s.o(.data);
        overlays_inside_castle_overlays_inside_castle_533500_s = .;
        build/asm/overlays/inside_castle/533500.s.o(.data);
        overlays_inside_castle_overlays_inside_castle_535A80_s = .;
        build/asm/overlays/inside_castle/535A80.s.o(.data);
        overlays_inside_castle_overlays_inside_castle_53DCA0_s = .;
        build/asm/overlays/inside_castle/53DCA0.s.o(.data);
        build/asm/overlays/inside_castle/5334D0.s.o(.rodata);
        build/asm/overlays/inside_castle/533500.s.o(.rodata);
        build/asm/overlays/inside_castle/535A80.s.o(.rodata);
        build/asm/overlays/inside_castle/53DCA0.s.o(.rodata);
        overlays_inside_castle_DATA_END = .;
        overlays_inside_castle_BSS_START = .;
        build/asm/overlays/inside_castle/5334D0.s.o(.bss);
        build/asm/overlays/inside_castle/533500.s.o(.bss);
        build/asm/overlays/inside_castle/535A80.s.o(.bss);
        build/asm/overlays/inside_castle/53DCA0.s.o(.bss);
        overlays_inside_castle_BSS_END = .;
    }
    overlays_inside_castle_ROM_END = 0x542220;
    __romPos = 0x542220;

    __romPos = 0x542220;
    . = __romPos;
    overlays_credits_ROM_START = __romPos;
    overlays_credits_VRAM = ADDR(.overlays_credits);
    .overlays_credits 0x801059A0 : AT(overlays_credits_ROM_START) SUBALIGN(16)
    {
        overlays_credits_TEXT_START = .;
        build/asm/overlays/credits/542220.s.o(.text);
        build/asm/overlays/credits/5436A0.s.o(.text);
        build/asm/overlays/credits/543FC0.s.o(.text);
        build/asm/overlays/credits/544E70.s.o(.text);
        build/asm/overlays/credits/5486A0.s.o(.text);
        overlays_credits_TEXT_END = .;
        overlays_credits_DATA_START = .;
        overlays_credits_54CDB0_bin = .;
        build/assets/overlays/credits/54CDB0.bin.o(.data);
        overlays_credits_overlays_credits_542220_s = .;
        build/asm/overlays/credits/542220.s.o(.data);
        overlays_credits_overlays_credits_5436A0_s = .;
        build/asm/overlays/credits/5436A0.s.o(.data);
        overlays_credits_overlays_credits_543FC0_s = .;
        build/asm/overlays/credits/543FC0.s.o(.data);
        overlays_credits_overlays_credits_544E70_s = .;
        build/asm/overlays/credits/544E70.s.o(.data);
        overlays_credits_overlays_credits_5486A0_s = .;
        build/asm/overlays/credits/5486A0.s.o(.data);
        build/asm/overlays/credits/542220.s.o(.rodata);
        build/asm/overlays/credits/5436A0.s.o(.rodata);
        build/asm/overlays/credits/543FC0.s.o(.rodata);
        build/asm/overlays/credits/544E70.s.o(.rodata);
        build/asm/overlays/credits/5486A0.s.o(.rodata);
        overlays_credits_DATA_END = .;
        overlays_credits_BSS_START = .;
        build/asm/overlays/credits/542220.s.o(.bss);
        build/asm/overlays/credits/5436A0.s.o(.bss);
        build/asm/overlays/credits/543FC0.s.o(.bss);
        build/asm/overlays/credits/544E70.s.o(.bss);
        build/asm/overlays/credits/5486A0.s.o(.bss);
        overlays_credits_BSS_END = .;
    }
    overlays_credits_ROM_END = 0x54DD10;
    __romPos = 0x54DD10;

    __romPos = 0x54DD10;
    . = __romPos;
    overlays_stamps_ROM_START = __romPos;
    overlays_stamps_VRAM = ADDR(.overlays_stamps);
    .overlays_stamps 0x801059A0 : AT(overlays_stamps_ROM_START) SUBALIGN(16)
    {
        overlays_stamps_TEXT_START = .;
        build/asm/overlays/stamps/54DD10.s.o(.text);
        build/asm/overlays/stamps/54F360.s.o(.text);
        overlays_stamps_TEXT_END = .;
        overlays_stamps_DATA_START = .;
        overlays_stamps_552C80_bin = .;
        build/assets/overlays/stamps/552C80.bin.o(.data);
        overlays_stamps_overlays_stamps_54DD10_s = .;
        build/asm/overlays/stamps/54DD10.s.o(.data);
        overlays_stamps_overlays_stamps_54F360_s = .;
        build/asm/overlays/stamps/54F360.s.o(.data);
        build/asm/overlays/stamps/54DD10.s.o(.rodata);
        build/asm/overlays/stamps/54F360.s.o(.rodata);
        overlays_stamps_DATA_END = .;
        overlays_stamps_BSS_START = .;
        build/asm/overlays/stamps/54DD10.s.o(.bss);
        build/asm/overlays/stamps/54F360.s.o(.bss);
        overlays_stamps_BSS_END = .;
    }
    overlays_stamps_ROM_END = 0x552F50;
    __romPos = 0x552F50;

    __romPos = 0x552F50;
    . = __romPos;
    overlays_test_menu2_ROM_START = __romPos;
    overlays_test_menu2_VRAM = ADDR(.overlays_test_menu2);
    .overlays_test_menu2 0x801059A0 : AT(overlays_test_menu2_ROM_START) SUBALIGN(16)
    {
        overlays_test_menu2_TEXT_START = .;
        build/asm/overlays/test_menu2/552F50.s.o(.text);
        overlays_test_menu2_TEXT_END = .;
        overlays_test_menu2_DATA_START = .;
        overlays_test_menu2_556240_bin = .;
        build/assets/overlays/test_menu2/556240.bin.o(.data);
        overlays_test_menu2_overlays_test_menu2_552F50_s = .;
        build/asm/overlays/test_menu2/552F50.s.o(.data);
        build/asm/overlays/test_menu2/552F50.s.o(.rodata);
        overlays_test_menu2_DATA_END = .;
        overlays_test_menu2_BSS_START = .;
        build/asm/overlays/test_menu2/552F50.s.o(.bss);
        overlays_test_menu2_BSS_END = .;
    }
    overlays_test_menu2_ROM_END = 0x557620;
    __romPos = 0x557620;

    __romPos = 0x557620;
    . = __romPos;
    bin_557620_ROM_START = __romPos;
    bin_557620_VRAM = ADDR(.bin_557620);
    .bin_557620 : AT(bin_557620_ROM_START) SUBALIGN(16)
    {
        bin_557620_TEXT_END = .;
        bin_557620_DATA_START = .;
        bin_557620_bin = .;
        build/assets/bin_557620.bin.o(.data);
        bin_557620_DATA_END = .;
    }
    bin_557620_ROM_END = 0x557E20;
    __romPos = 0x557E20;

    __romPos = 0x557E20;
    . = __romPos;
    bin_mainfs_ROM_START = __romPos;
    bin_mainfs_VRAM = ADDR(.bin_mainfs);
    .bin_mainfs : AT(bin_mainfs_ROM_START) SUBALIGN(16)
    {
        bin_mainfs_TEXT_END = .;
        bin_mainfs_DATA_START = .;
        bin_mainfs_bin = .;
        build/assets/bin_mainfs.bin.o(.data);
        bin_mainfs_DATA_END = .;
    }
    bin_mainfs_ROM_END = 0x1209850;
    __romPos = 0x1209850;

    __romPos = 0x1209850;
    . = __romPos;
    bin_strings_jp_ROM_START = __romPos;
    bin_strings_jp_VRAM = ADDR(.bin_strings_jp);
    .bin_strings_jp : AT(bin_strings_jp_ROM_START) SUBALIGN(16)
    {
        bin_strings_jp_TEXT_END = .;
        bin_strings_jp_DATA_START = .;
        bin_strings_jp_bin = .;
        build/assets/bin_strings_jp.bin.o(.data);
        bin_strings_jp_DATA_END = .;
    }
    bin_strings_jp_ROM_END = 0x121CAA0;
    __romPos = 0x121CAA0;

    __romPos = 0x121CAA0;
    . = __romPos;
    bin_strings_en_ROM_START = __romPos;
    bin_strings_en_VRAM = ADDR(.bin_strings_en);
    .bin_strings_en : AT(bin_strings_en_ROM_START) SUBALIGN(16)
    {
        bin_strings_en_TEXT_END = .;
        bin_strings_en_DATA_START = .;
        bin_strings_en_bin = .;
        build/assets/bin_strings_en.bin.o(.data);
        bin_strings_en_DATA_END = .;
    }
    bin_strings_en_ROM_END = 0x12355C0;
    __romPos = 0x12355C0;

    __romPos = 0x12355C0;
    . = __romPos;
    bin_strings_de_ROM_START = __romPos;
    bin_strings_de_VRAM = ADDR(.bin_strings_de);
    .bin_strings_de : AT(bin_strings_de_ROM_START) SUBALIGN(16)
    {
        bin_strings_de_TEXT_END = .;
        bin_strings_de_DATA_START = .;
        bin_strings_de_bin = .;
        build/assets/bin_strings_de.bin.o(.data);
        bin_strings_de_DATA_END = .;
    }
    bin_strings_de_ROM_END = 0x124D440;
    __romPos = 0x124D440;

    __romPos = 0x124D440;
    . = __romPos;
    bin_strings_fr_ROM_START = __romPos;
    bin_strings_fr_VRAM = ADDR(.bin_strings_fr);
    .bin_strings_fr : AT(bin_strings_fr_ROM_START) SUBALIGN(16)
    {
        bin_strings_fr_TEXT_END = .;
        bin_strings_fr_DATA_START = .;
        bin_strings_fr_bin = .;
        build/assets/bin_strings_fr.bin.o(.data);
        bin_strings_fr_DATA_END = .;
    }
    bin_strings_fr_ROM_END = 0x1261F90;
    __romPos = 0x1261F90;

    __romPos = 0x1261F90;
    . = __romPos;
    bin_strings_it_ROM_START = __romPos;
    bin_strings_it_VRAM = ADDR(.bin_strings_it);
    .bin_strings_it : AT(bin_strings_it_ROM_START) SUBALIGN(16)
    {
        bin_strings_it_TEXT_END = .;
        bin_strings_it_DATA_START = .;
        bin_strings_it_bin = .;
        build/assets/bin_strings_it.bin.o(.data);
        bin_strings_it_DATA_END = .;
    }
    bin_strings_it_ROM_END = 0x12765F0;
    __romPos = 0x12765F0;

    __romPos = 0x12765F0;
    . = __romPos;
    bin_strings_es_ROM_START = __romPos;
    bin_strings_es_VRAM = ADDR(.bin_strings_es);
    .bin_strings_es : AT(bin_strings_es_ROM_START) SUBALIGN(16)
    {
        bin_strings_es_TEXT_END = .;
        bin_strings_es_DATA_START = .;
        bin_strings_es_bin = .;
        build/assets/bin_strings_es.bin.o(.data);
        bin_strings_es_DATA_END = .;
    }
    bin_strings_es_ROM_END = 0x128CC60;
    __romPos = 0x128CC60;

    __romPos = 0x128CC60;
    . = __romPos;
    bin_hvq_ROM_START = __romPos;
    bin_hvq_VRAM = ADDR(.bin_hvq);
    .bin_hvq : AT(bin_hvq_ROM_START) SUBALIGN(16)
    {
        bin_hvq_TEXT_END = .;
        bin_hvq_DATA_START = .;
        bin_hvq_bin = .;
        build/assets/bin_hvq.bin.o(.data);
        bin_hvq_DATA_END = .;
    }
    bin_hvq_ROM_END = 0x1881C40;
    __romPos = 0x1881C40;

    __romPos = 0x1881C40;
    . = __romPos;
    bin_audio_mbf0_ROM_START = __romPos;
    bin_audio_mbf0_VRAM = ADDR(.bin_audio_mbf0);
    .bin_audio_mbf0 : AT(bin_audio_mbf0_ROM_START) SUBALIGN(16)
    {
        bin_audio_mbf0_TEXT_END = .;
        bin_audio_mbf0_DATA_START = .;
        bin_audio_mbf0_bin = .;
        build/assets/bin_audio_mbf0.bin.o(.data);
        bin_audio_mbf0_DATA_END = .;
    }
    bin_audio_mbf0_ROM_END = 0x1A56870;
    __romPos = 0x1A56870;

    __romPos = 0x1A56870;
    . = __romPos;
    bin_audio_sbf0_ROM_START = __romPos;
    bin_audio_sbf0_VRAM = ADDR(.bin_audio_sbf0);
    .bin_audio_sbf0 : AT(bin_audio_sbf0_ROM_START) SUBALIGN(16)
    {
        bin_audio_sbf0_TEXT_END = .;
        bin_audio_sbf0_DATA_START = .;
        bin_audio_sbf0_bin = .;
        build/assets/bin_audio_sbf0.bin.o(.data);
        bin_audio_sbf0_DATA_END = .;
    }
    bin_audio_sbf0_ROM_END = 0x1EFD040;
    __romPos = 0x1EFD040;

    __romPos = 0x1EFD040;
    . = __romPos;
    bin_audio_fxd0_ROM_START = __romPos;
    bin_audio_fxd0_VRAM = ADDR(.bin_audio_fxd0);
    .bin_audio_fxd0 : AT(bin_audio_fxd0_ROM_START) SUBALIGN(16)
    {
        bin_audio_fxd0_TEXT_END = .;
        bin_audio_fxd0_DATA_START = .;
        bin_audio_fxd0_bin = .;
        build/assets/bin_audio_fxd0.bin.o(.data);
        bin_audio_fxd0_DATA_END = .;
    }
    bin_audio_fxd0_ROM_END = 0x2000000;
    __romPos = 0x2000000;

    __romPos = 0x2000000;
    . = __romPos;
    overlays_testOverlay_ROM_START = __romPos;
    overlays_testOverlay_VRAM = ADDR(.overlays_testOverlay);
    .overlays_testOverlay 0x801059A0 : AT(overlays_testOverlay_ROM_START) SUBALIGN(16)
    {
        overlays_testOverlay_TEXT_START = .;
        build/src/overlays/testOverlay/testOverlay.c.o(.text);
        overlays_testOverlay_TEXT_END = .;
        overlays_testOverlay_DATA_START = .;
        overlays_testOverlay_testOverlay_bin = .;
        overlays_testOverlay_overlays_testOverlay_testOverlay_c = .;
        build/src/overlays/testOverlay/testOverlay.c.o(.data);
        build/src/overlays/testOverlay/testOverlay.c.o(COMMON);
        build/src/overlays/testOverlay/testOverlay.c.o(.rodata);
        overlays_testOverlay_DATA_END = .;
        overlays_testOverlay_BSS_START = .;
        build/src/overlays/testOverlay/testOverlay.c.o(.bss);
        overlays_testOverlay_BSS_END = .;
    }
    overlays_testOverlay_ROM_END = 0x2001000;
    __romPos = 0x2001000;

    /DISCARD/ :
    {
        *(*);
    }
}
