;***************************************************************
;       ML621367 start up assembly source file
;       for CCU8 version 1.xx/2.xx/3.xx
;       SMALL CODE MODEL
;       ROMWINDOW  00000H-0DFFFH
;       Version 1.01
;       Last Edition  Jul 25, 2019
;       Copyright (C) 2019 LAPIS Semiconductor Co., Ltd.
;       U8/U16 Device Information Files V2.00
;***************************************************************

        type(ML621367)

        model   small
        romwindow       0, 0dfffh

        extrn   code: _main
        extrn   data near: _$$SP
        public  $$start_up

        cseg    at 0:0h
        dw      offset _$$SP

        cseg    at 0:4h
        dw      $$brk_reset

        cseg    at 0:6h
        dw      0ffffh


$$NCODml621367sw segment code #0
        rseg    $$NCODml621367sw

$$start_up:
        tb      INITE
        bz      $begin

$$brk_reset:
$$error:
        mov     r0,     #00h
        st      r0,     WDTMOD
        mov     psw,    #02h
  ;-----------------------------------------------------
  ;     reset SFRs
  ;     If you don't need the below then remove it.
  ;
        mov     er0,    #-1
        st      er0,    BRECON0
        st      er0,    BRECON1
        st      er0,    BRECON2
        st      er0,    BRECON3
  ;-----------------------------------------------------
        bal     $               ; wait for Watch Dog Timer reset

$begin:

;---------------------------------------------------------------
;       setting Memory Model
;---------------------------------------------------------------
; nothing (fixed as Small model)

;---------------------------------------------------------------
;       setting Rom Window range
;---------------------------------------------------------------
; nothing (fixed as range 0-0dfffh)

;---------------------------------------------------------------
;       user SFR definition
;---------------------------------------------------------------
;
; In C source file, define this function as follows:
;
; void setting_SFR(void)
; {
;     ...
; }
;---------------------------------------------------------------
; extrn code : _setting_SFR
;     bl      _setting_SFR

;---------------------------------------------------------------
;       Data memory zero clear
;---------------------------------------------------------------
NEAR_RAM_START  equ     0e000h
NEAR_RAM_END    equ     0efffh

        mov     er0,    #0
        mov     er2,    #0
        mov     er4,    #0
        mov     er6,    #0

        mov     r8,     #BYTE1 NEAR_RAM_START
        mov     r9,     #BYTE2 NEAR_RAM_START
        lea     [er8]
__near_ram_loop:
        st      qr0,    [ea+]
        add     er8,    #8              ;er8 += 8
        cmp     r9,     #BYTE2 (NEAR_RAM_END+1)
        blt     __near_ram_loop
        cmp     r8,     #BYTE1 (NEAR_RAM_END+1)
        blt     __near_ram_loop

;---------------------------------------------------------------
;       WDT counter clear
;
;       !!NOTICE!!
;       After this process, you have to clear WDT counter within 
;       the time described in user's manual of LSI.
;
;       !!NOTICE!!
;       Please remove this routine when you use DTU8 simulation 
;       mode.
;---------------------------------------------------------------
;__wait_wdt_clear:
;        tb      WDTCLR1
;        bnz     __wait_wdt_clear
;        mov     r0,      psw
;        di
;        mov     r12,     #05ah
;        mov     r13,     #0a5h
;        st      r12,     WDTCON
;        st      r13,     WDTCON
;        mov     psw,     r0

;---------------------------------------------------------------
;       data variable initialization
;---------------------------------------------------------------
        mov     r10,    #SEG $$init_info
        lea     OFFSET $$init_info
__init_loop:
        ;---------------------------------------------
        ; get source offset address and set in ER0
        ;---------------------------------------------
        l       er0,    r10:[ea+]
        cmp     r0,     #0ffh
        bne     __skip
        cmp     r1,     #0ffh
        beq     __init_end              ;if er0==0ffffh then exit
__skip:
        ;---------------------------------------------
        ; get destination offset address and set in ER2
        ;---------------------------------------------
        l       er2,    r10:[ea+]

        ;---------------------------------------------
        ; get size of objects and set in ER4
        ;---------------------------------------------
        l       er4,    r10:[ea+]

        ;---------------------------------------------
        ; get source phy_seg address and set in R6
        ;---------------------------------------------
        l       r6,     r10:[ea+]

        ;---------------------------------------------
        ; get destination phy_seg address and set in R7
        ;---------------------------------------------
        l       r7,     r10:[ea+]

        ;---------------------------------------------
        ; copy
        ;---------------------------------------------
        add     er4,    #0
        bz      __init_loop             ;if er4==0000 then next

        tb      r2.0
        bnz     __loop_by_byte
        tb      r4.0
        bnz     __loop_by_byte

__init_loop2:
        l       er8,    r6:[er0]
        add     er0,    #2              ;er0 += 2
        st      er8,    r7:[er2]
        add     er2,    #2              ;er2 += 2

        add     er4,    #-2             ;er4 -= 2
        bnz     __init_loop2
        bal     __init_loop

__loop_by_byte:
        l       r8,     r6:[er0]
        add     er0,    #1              ;er0 += 1
        st      r8,     r7:[er2]
        add     er2,    #1              ;er2 += 1

        add     er4,    #-1             ;er4 -= 1
        bnz     __loop_by_byte
        bal     __init_loop

__init_end:

;---------------------------------------------------------------
;       call initializing routine
;---------------------------------------------------------------
        bl      $$content_of_init

;---------------------------------------------------------------
;       initialize DSR zero
;---------------------------------------------------------------
        mov     r0,     #0
        st      r0,     DSR

;---------------------------------------------------------------
;       far jump to main routine
;---------------------------------------------------------------
        b       _main

;---------------------------------------------------------------
;       segment definition for initializing routine
;---------------------------------------------------------------
$$content_of_init segment code
        rseg    $$content_of_init

$$end_of_init segment code
        rseg    $$end_of_init
        rt

;---------------------------------------------------------------
;       segment definition for data variable initialization
;---------------------------------------------------------------
$$init_info segment table 2
        rseg    $$init_info
        dw      $$NINITTAB
        dw      $$NINITVAR
        dw      size $$NINITTAB
        db      seg $$NINITTAB
        db      seg $$NINITVAR

$$init_info_end segment table
        rseg    $$init_info_end
        dw      0ffffh

$$NINITVAR segment data 2 #0
$$NINITTAB segment table 2

;---------------------------------------------------------------
;       Setting the code-option data (for ML621367)
;---------------------------------------------------------------
        cseg #0 at 0ffc0h       ; address
        dw      0ffffh          ; 0ffc0h
        dw      0ffffh          ; 0ffc2h
        dw      0ffffh          ; 0ffc4h
        dw      0ffffh          ; 0ffc6h
        dw      0ffffh          ; 0ffc8h
        dw      0ffffh          ; 0ffcah
        dw      0ffffh          ; 0ffcch
        dw      0ffffh          ; 0ffceh

        cseg #0 at 0ffd0h       ; address
        dw      0fff9h          ; 0ffd0h    ;Disable WDT in STOP mode

        cseg #0 at 0ffd2h       ; address
        dw      0fff9h          ; 0ffd2h	;PLL=24 MHz and CPU wait mode
        dw      0ffffh          ; 0ffd4h
        dw      0ffffh          ; 0ffd6h
        dw      0ffffh          ; 0ffd8h
        dw      0ffffh          ; 0ffdah
        dw      0ffffh          ; 0ffdch
        dw      0ffffh          ; 0ffdeh

        cseg #0 at 0ffe0h       ; address
        dw      0ffffh          ; 0ffe0h
        dw      0ffffh          ; 0ffe2h
        dw      0ffffh          ; 0ffe4h
        dw      0ffffh          ; 0ffe6h
        dw      0ffffh          ; 0ffe8h
        dw      0ffffh          ; 0ffeah
        dw      0ffffh          ; 0ffech
        dw      0ffffh          ; 0ffeeh
        dw      0ffffh          ; 0fff0h
        dw      0ffffh          ; 0fff2h
        dw      0ffffh          ; 0fff4h
        dw      0ffffh          ; 0fff6h
        dw      0ffffh          ; 0fff8h
        dw      0ffffh          ; 0fffah
        dw      0ffffh          ; 0fffch
        dw      0ffffh          ; 0fffeh

;---------------------------------------------------------------
;       Keeping the Mirror area (for ML621367)
;---------------------------------------------------------------
        tseg #08h at 00000h
        ds      10000h

        tseg #09h at 00000h
        ds      00400h

;---------------------------------------------------------------
;       Keeping the Self-Programming area (for ML621367)
;---------------------------------------------------------------
        tseg #1fh at 00000h
        ds      00800h

;---------------------------------------------------------------
;       Keeping the Test area over #1 (for ML621367)
;---------------------------------------------------------------
        tseg #01h at 00000h
        ds      00400h

        end

