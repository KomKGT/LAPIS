;; Compile Options : /TML621367 /MS /near /SD /Od /W 1 /Fasource files\ /Zs 
;; Version Number  : Ver.3.64.5
;; File Name       : reset.c

	type (ML621367) 
	model small, near
	$$reset_detBrkr$reset segment code 2h #0h
	$$reset_detFiar$reset segment code 2h #0h
	$$reset_detPor$reset segment code 2h #0h
	$$reset_detRper$reset segment code 2h #0h
	$$reset_detRstr$reset segment code 2h #0h
	$$reset_detVls0r$reset segment code 2h #0h
	$$reset_detWdtr$reset segment code 2h #0h
	$$reset_detWdtwr$reset segment code 2h #0h
CVERSION 3.64.5
CGLOBAL 01H 03H 0000H "reset_detBrkr" 08H 02H 00H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "reset_detFiar" 08H 02H 07H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "reset_detVls0r" 08H 02H 02H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "reset_detWdtwr" 08H 02H 03H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "reset_detRper" 08H 02H 06H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "reset_detRstr" 08H 02H 01H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "reset_detPor" 08H 02H 05H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "reset_detWdtr" 08H 02H 04H 00H 80H 00H 00H 00H 07H
CSTRUCTTAG 0000H 0000H 0000H 0008H 00000001H "_Notag"
CSTRUCTMEM 52H 00000001H 00000000H "b0" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000001H "b1" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000002H "b2" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000003H "b3" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000004H "b4" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000005H "b5" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000006H "b6" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000007H "b7" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "_BYTE_FIELD" 04H 00H 05H 00H 00H
CFILE 0001H 0000117DH "D:\\U8Dev\\Inc\\ml621367.h"
CFILE 0002H 0000004BH "..\\source files\\rdwr_reg.h"
CFILE 0003H 000000ACH "..\\source files\\reset.h"
CFILE 0004H 00000030H "..\\source files\\reset_common.h"
CFILE 0000H 0000009DH "..\\source files\\reset.c"

	rseg $$reset_detBrkr$reset
CFUNCTION 0

_reset_detBrkr	:
CBLOCK 0 1 56

;;void reset_detBrkr( void ) {
CLINEA 0000H 0001H 0038H 0001H 001CH
CBLOCK 0 2 56
CBLOCKEND 0 2 58

;;}
CLINEA 0000H 0001H 003AH 0001H 0001H
	rt
CBLOCKEND 0 1 58
CFUNCTIONEND 0


	rseg $$reset_detRstr$reset
CFUNCTION 1

_reset_detRstr	:
CBLOCK 1 1 71

;;void reset_detRstr( void ) {
CLINEA 0000H 0001H 0047H 0001H 001CH
CBLOCK 1 2 71
CBLOCKEND 1 2 73

;;}
CLINEA 0000H 0001H 0049H 0001H 0001H
	rt
CBLOCKEND 1 1 73
CFUNCTIONEND 1


	rseg $$reset_detVls0r$reset
CFUNCTION 2

_reset_detVls0r	:
CBLOCK 2 1 85

;;void reset_detVls0r( void ) {
CLINEA 0000H 0001H 0055H 0001H 001DH
CBLOCK 2 2 85
CBLOCKEND 2 2 87

;;}
CLINEA 0000H 0001H 0057H 0001H 0001H
	rt
CBLOCKEND 2 1 87
CFUNCTIONEND 2


	rseg $$reset_detWdtwr$reset
CFUNCTION 3

_reset_detWdtwr	:
CBLOCK 3 1 99

;;void reset_detWdtwr( void ) {
CLINEA 0000H 0001H 0063H 0001H 001DH
CBLOCK 3 2 99
CBLOCKEND 3 2 101

;;}
CLINEA 0000H 0001H 0065H 0001H 0001H
	rt
CBLOCKEND 3 1 101
CFUNCTIONEND 3


	rseg $$reset_detWdtr$reset
CFUNCTION 4

_reset_detWdtr	:
CBLOCK 4 1 113

;;void reset_detWdtr( void ) {
CLINEA 0000H 0001H 0071H 0001H 001CH
CBLOCK 4 2 113
CBLOCKEND 4 2 115

;;}
CLINEA 0000H 0001H 0073H 0001H 0001H
	rt
CBLOCKEND 4 1 115
CFUNCTIONEND 4


	rseg $$reset_detPor$reset
CFUNCTION 5

_reset_detPor	:
CBLOCK 5 1 126

;;void reset_detPor( void ) {
CLINEA 0000H 0001H 007EH 0001H 001BH
CBLOCK 5 2 126
CBLOCKEND 5 2 128

;;}
CLINEA 0000H 0001H 0080H 0001H 0001H
	rt
CBLOCKEND 5 1 128
CFUNCTIONEND 5


	rseg $$reset_detRper$reset
CFUNCTION 6

_reset_detRper	:
CBLOCK 6 1 140

;;void reset_detRper( void ) {
CLINEA 0000H 0001H 008CH 0001H 001CH
CBLOCK 6 2 140
CBLOCKEND 6 2 142

;;}
CLINEA 0000H 0001H 008EH 0001H 0001H
	rt
CBLOCKEND 6 1 142
CFUNCTIONEND 6


	rseg $$reset_detFiar$reset
CFUNCTION 7

_reset_detFiar	:
CBLOCK 7 1 154

;;void reset_detFiar( void ) {
CLINEA 0000H 0001H 009AH 0001H 001CH
CBLOCK 7 2 154
CBLOCKEND 7 2 156

;;}
CLINEA 0000H 0001H 009CH 0001H 0001H
	rt
CBLOCKEND 7 1 156
CFUNCTIONEND 7

	public _reset_detBrkr
	public _reset_detFiar
	public _reset_detVls0r
	public _reset_detWdtwr
	public _reset_detRper
	public _reset_detRstr
	public _reset_detPor
	public _reset_detWdtr
	extrn code near : _main

	end
