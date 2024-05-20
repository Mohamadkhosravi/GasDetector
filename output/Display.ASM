; Generated by holtek-gcc v3.19, Mon May 20 17:10:53 2024
; 
; Configuration:
;       without long instruction
;       Single ROM, Multi-RAM
;       bits_per_rom_unit:16
;       with mp1
;       with tbhp, address(0x9)
;          Use tabrd-const
;       
;       
;       
; use 'tabrdc' instead of 'tabrd'
;       

#pragma translator "holtek-gcc 4.6.4" "3.19" "build 20130711"
; Rebuild 718

ir equ [2]
mp equ [3]
sbp equ [1]
acc equ [5]
bp equ [4]
tblp equ [7]
tbhp equ [9]
status equ [10]
c equ [10].0
ac equ [10].1
z equ [10].2
ov equ [10].3
intc equ [11]

extern ra:byte
extern rb:byte
extern rc:byte
extern rd:byte
extern re:byte
extern rf:byte
extern rg:byte
extern rh:byte
extern _Crom2Prom:near
extern _Crom2PromNext:near

RAMBANK 0 @HCCINIT, @HCCINIT0

RAMBANK 0 @BITDATASEC, @BITDATASEC1
@HCCINIT	.section 'data'
@HCCINIT0	.section 'data'
@BITDATASEC	 .section 'data'
@BITDATASEC1	 .section 'data'

#pragma debug scope 1 1
	extern __DELAY3:near
	extern __DELAYX3:near
	extern __DELAYX6:near
	extern __DELAYY5:near
	extern __DELAYY3:near
	extern _builtin_holtek_delay_2:byte
___pb equ [27]
___pc equ [31]
___pd equ [35]
___pa equ [20]
public _DisplayInit
#pragma debug scope 2 1
#line 4 "c:\users\tech\desktop\gasdetector\Display\Display.c"
_DisplayInit .section 'code'
_DisplayInit proc
#line 6 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].5
#line 7 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].6
#line 8 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].7
#line 9 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].4
#line 10 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 11 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 12 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 13 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
#line 14 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
#line 15 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].1
#line 16 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].3
	ret
_DisplayInit endp
#line 16 "c:\users\tech\desktop\gasdetector\Display\Display.c"
#pragma debug scope 1 1
public _segmentNumbers
#pragma debug scope 3 1
#line 20 "c:\users\tech\desktop\gasdetector\Display\Display.c"
_segmentNumbers .section 'code'
_segmentNumbers proc
    local _segmentNumbers_2 db 1 dup(?)	; 0,1
	mov ra,a
	mov _segmentNumbers_2[0],a
#pragma debug variable 8 3 _segmentNumbers_2+0 "n"
#line 22 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,0
	sz z
	jmp _L4
	sub a,(1)-(0)
	sz z
	jmp _L5
#line 22 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,2
	sz z
	jmp _L6
	sub a,(3)-(2)
	sz z
	jmp _L7
	mov a,ra
	sub a,4
	sz z
	jmp _L8
	sub a,(5)-(4)
	sz z
	jmp _L9
	mov a,ra
	sub a,6
	sz z
	jmp _L10
	sub a,(7)-(6)
	sz z
	jmp _L11
	mov a,ra
	sub a,8
	sz z
	jmp _L12
	sub a,(9)-(8)
	sz z
	jmp _L13
	mov a,ra
	sub a,45
	sz z
	jmp _L14
	sub a,(98)-(45)
	sz z
	jmp _L15
	mov a,ra
	sub a,108
	sz z
	jmp _L16
	sub a,(110)-(108)
	sz z
	jmp _L17
	mov a,ra
	sub a,111
	snz z
	jmp _L2
#line 143 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 144 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 145 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
	jmp _L26
_L4:
#line 25 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 26 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 27 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
	jmp _L20
_L5:
#line 34 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
	jmp _L24
_L6:
#line 43 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 44 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 45 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].4
	jmp _L26
_L7:
#line 52 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 53 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 54 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 55 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
	jmp _L23
_L8:
#line 61 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 62 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 63 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 64 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [20].7
	jmp _L30
_L9:
#line 70 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 71 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
	jmp _L31
_L10:
#line 79 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
	jmp _L28
_L11:
#line 88 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
_L24:
#line 89 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 90 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 91 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [20].7
#line 92 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].6
#line 93 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].1
	jmp _L22
_L12:
#line 97 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 98 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
	jmp _L29
_L13:
#line 106 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 107 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
_L31:
#line 108 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 109 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
_L30:
#line 110 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].6
	jmp _L27
_L15:
#line 116 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
_L28:
#line 117 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
_L29:
#line 118 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 119 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
#line 120 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
_L27:
#line 121 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].1
	jmp _L21
_L16:
#line 125 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 126 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 127 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].4
_L20:
#line 128 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
#line 129 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
#line 130 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].1
_L22:
#line 131 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].3
#line 132 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	jmp _L2
_L17:
#line 134 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 135 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 136 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 137 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [20].7
	jmp _L25
_L26:
#line 146 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
_L25:
#line 147 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
	jmp _L19
_L14:
#line 152 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 153 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 154 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].4
#line 155 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [20].7
_L23:
#line 156 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].6
_L19:
#line 157 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].1
_L21:
#line 158 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].3
_L2:
	ret
_segmentNumbers endp
#line 158 "c:\users\tech\desktop\gasdetector\Display\Display.c"
#pragma debug scope 1 1
public _segmentCharters
#pragma debug scope 4 1
#line 163 "c:\users\tech\desktop\gasdetector\Display\Display.c"
_segmentCharters .section 'code'
_segmentCharters proc
    local _segmentCharters_2 db 1 dup(?)	; 0,1
	mov ra,a
	mov _segmentCharters_2[0],a
#pragma debug variable 8 4 _segmentCharters_2+0 "n"
#line 165 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,45
	sz z
	jmp _L35
	sub a,(98)-(45)
	sz z
	jmp _L36
#line 165 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,108
	sz z
	jmp _L37
	sub a,(110)-(108)
	sz z
	jmp _L38
	mov a,ra
	sub a,111
	snz z
	jmp _L33
#line 196 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 197 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 198 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 199 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
	jmp _L40
_L36:
#line 169 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 170 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 171 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 172 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
#line 173 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
#line 174 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].1
	jmp _L41
_L37:
#line 178 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 179 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 180 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].4
#line 181 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
#line 182 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
#line 183 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].1
#line 184 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].3
#line 185 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	jmp _L33
_L38:
#line 187 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 188 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 189 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 190 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [20].7
_L40:
#line 200 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
#line 201 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].1
_L41:
#line 202 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].3
#line 203 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	jmp _L33
_L35:
#line 205 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 206 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 207 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].4
_L33:
	ret
_segmentCharters endp
#line 207 "c:\users\tech\desktop\gasdetector\Display\Display.c"
#pragma debug scope 1 1
public _Display
#pragma debug scope 5 1
#line 211 "c:\users\tech\desktop\gasdetector\Display\Display.c"
_Display .section 'code'
_Display proc
public _Display_2
    local _Display_2 db 11 dup(?)	; 3,8
#pragma debug variable 11 5 _Display_2+0 "number"
#pragma debug variable 7 5 _Display_2+2 "letter"
#pragma debug array 42 7 4 5
#pragma debug variable 42 5 _Display_2+3 "displayBuffer"
#pragma debug variable 7 5 _Display_2+7 "digitNumber"
#line 213 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr _Display_2[3]
	clr _Display_2[4]
	clr _Display_2[5]
#line 219 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[2]
	sub a,48
	snz z
	jmp _L43
#line 213 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr _Display_2[6]
#line 215 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,3
	mov rb,a
	jmp _L44
_L43:
#line 222 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[2]
	mov _Display_2[6],a
#line 221 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,2
	mov rb,a
_L44:
#line 215 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr ra
#line 227 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,rb
	mov _Display_2[7],a
	clr _Display_2[8]
	sz acc.7
	set _Display_2[8]
	mov a,low offset _Display_2
	mov rb,a
	mov a,high offset _Display_2
	mov rc,a
	mov a,3
	add a,rb
	mov _Display_2[9],a
	mov a,0
	adc a,rc
	mov _Display_2[10],a
_L45:
#line 224 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[0]
	or a,_Display_2[1]
	sz z
	jmp _L56
#line 227 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[0]
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,_Display_2[1]
	mov _builtin_holtek_udivmodhi4_2[1],a
	mov a,10
	mov _builtin_holtek_udivmodhi4_2[2],a
	mov a,0
	mov _builtin_holtek_udivmodhi4_2[3],a
	call _builtin_holtek_divmodhi4
	mov a,_builtin_holtek_udivmodhi4_2[4]
	mov rb,a
	mov a,_builtin_holtek_udivmodhi4_2[5]
	mov rc,a
	mov a,_Display_2[7]
	sub a,ra
	mov rd,a
	mov a,_Display_2[8]
	clr re
	sz ra.7
	set re
	sbcm a,re
	mov a,rd
	add a,_Display_2[9]
	mov mp,a
	mov a,re
	adc a,_Display_2[10]
	mov sbp,a
	mov a,sbp
	mov bp,a
	mov a,rb
	mov ir,a
#line 228 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[0]
	subm a,rb
	mov a,_Display_2[1]
	sbcm a,rc
	mov a,rb
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,rc
	mov _builtin_holtek_udivmodhi4_2[1],a
	mov a,10
	mov _builtin_holtek_udivmodhi4_2[2],a
	mov a,0
	mov _builtin_holtek_udivmodhi4_2[3],a
	call _builtin_holtek_divmodhi4
	mov a,_builtin_holtek_udivmodhi4_2[0]
	mov _Display_2[0],a
	mov a,_builtin_holtek_udivmodhi4_2[1]
	mov _Display_2[1],a
#line 229 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	inc ra
	jmp _L45
_L56:
#line 224 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr _Display_2[7]
_L53:
#line 244 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[7]
	sub a,1
	sz z
	jmp _L48
	sub a,(2)-(1)
	sz z
	jmp _L49
	mov a,_Display_2[7]
	sub a,3
	sz z
	jmp _L50
#line 247 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[3]
	call _segmentNumbers
#line 248 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].5
#line 249 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
	jmp _L55
_L48:
#line 255 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[4]
	mov ra,a
	mov a,ra
	call _segmentNumbers
#line 256 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 257 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].6
_L55:
#line 258 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
	jmp _L54
_L49:
#line 263 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[5]
	mov ra,a
	mov a,ra
	call _segmentNumbers
#line 264 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 265 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 266 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].7
_L54:
#line 267 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].4
#line 269 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	jmp _L51
_L50:
#line 272 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[6]
	mov ra,a
	mov a,ra
	call _segmentNumbers
#line 273 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 274 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 275 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
#line 276 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].4
_L51:
#line 280 "c:\users\tech\desktop\gasdetector\Display\Display.c"
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	IF 1000>263690
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	ERRMESSAGE 'the value 1000of the argument exceeds the maxinum 263690'
	ENDIF
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	IF 1000<0
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	ERRMESSAGE 'the value 1000 of the argument exceeds the mininum 0'
	ENDIF
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	IF 1000==0
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	JMP $
	ENDIF
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	IF 1000==1
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	NOP
	ENDIF
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	IF 1000==2
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	NOP
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	NOP
	ENDIF
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	IF 1000==3
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	NOP
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	NOP
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	NOP
	ENDIF
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	IF (1000<8) AND (1000>3)
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	CALL __DELAY3 + 7 -1000
	ENDIF
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	IF (1000< 0404h) AND (1000>7)
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	MOV A,1000/4-1
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	CALL __DELAYX3 + 3 -(1000 MOD 4)
	ENDIF
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	IF (1000< 0x40B) AND (1000> 0403h)
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	MOV A,0 
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	CALL __DELAYX6 + 0x40a -1000
	ENDIF
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	IF (1000 >= 0x40b) AND ((((1000-9)%0402h)/4+1)>256)
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	MOV A,(1000-9)/0402h
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	MOV _builtin_holtek_delay_2,A
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	MOV A,0
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	CALL __DELAYY5 +5- (((1000-9)%0402h)%6)
	ENDIF
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	IF (1000 >= 0x40b) AND ((((1000-9)%0402h)/4+1)<=256)
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	MOV A,(1000-9)/0402h
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	MOV _builtin_holtek_delay_2,A
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	MOV A,((1000-9)%0402h)/4+1
;# 280 "c:\users\tech\desktop\gasdetector\Display\Display.c" 1
	CALL __DELAYY3 +3-(((1000-9)%0402h)%4)
	ENDIF
#line 240 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	inc _Display_2[7]
	mov a,_Display_2[7]
	sub a,4
	snz z
	jmp _L53
	ret
_Display endp
#line 240 "c:\users\tech\desktop\gasdetector\Display\Display.c"
#pragma debug scope 1 1
#pragma debug struct_begin 43 "__pa_bits"
#pragma debug field 21 8 0 1 "__pa0" ;0,1
#pragma debug field 21 8 0 1 "__pa1" ;1,1
#pragma debug field 21 8 0 1 "__pa2" ;2,1
#pragma debug field 21 8 0 1 "__pa3" ;3,1
#pragma debug field 21 8 0 1 "__pa4" ;4,1
#pragma debug field 21 8 0 1 "__pa5" ;5,1
#pragma debug field 21 8 0 1 "__pa6" ;6,1
#pragma debug field 21 8 0 1 "__pa7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 44 ""
#pragma debug field 2 43 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 44 1 ___pa "__pa" 1
#pragma debug struct_begin 45 "__pb_bits"
#pragma debug field 21 8 0 1 "__pb0" ;0,1
#pragma debug field 21 8 0 1 "__pb1" ;1,1
#pragma debug field 21 8 0 1 "__pb2" ;2,1
#pragma debug field 21 8 0 1 "__pb3" ;3,1
#pragma debug field 21 8 0 1 "__pb4" ;4,1
#pragma debug field 21 8 0 1 "__pb5" ;5,1
#pragma debug field 21 8 0 1 "__pb6" ;6,1
#pragma debug field 21 8 0 1 "__pb7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 46 ""
#pragma debug field 2 45 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 46 1 ___pb "__pb" 1
#pragma debug struct_begin 47 "__pc_bits"
#pragma debug field 21 8 0 1 "__pc0" ;0,1
#pragma debug field 21 8 0 1 "__pc1" ;1,1
#pragma debug field 21 8 0 1 "__pc2" ;2,1
#pragma debug field 21 8 0 1 "__pc3" ;3,1
#pragma debug field 21 8 0 1 "__pc4" ;4,1
#pragma debug field 21 8 0 1 "__pc5" ;5,1
#pragma debug field 21 8 0 1 "__pc6" ;6,1
#pragma debug field 21 8 0 1 "__pc7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 48 ""
#pragma debug field 2 47 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 48 1 ___pc "__pc" 1
#pragma debug struct_begin 49 "__pd_bits"
#pragma debug field 21 8 0 1 "__pd0" ;0,1
#pragma debug field 21 8 0 1 "__pd1" ;1,1
#pragma debug field 21 8 0 6 ;2,6
#pragma debug struct_end
#pragma debug union_begin 50 ""
#pragma debug field 2 49 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 50 1 ___pd "__pd" 1
extern _builtin_holtek_divmodhi4:near
extern _builtin_holtek_udivmodhi4_2:byte
extern _builtin_holtek_udivmodhi4:near

; 
; Generated by holtek-gcc v3.19, Mon May 20 17:10:53 2024
; Rebuild 718
; end of file