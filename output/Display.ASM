; Generated by holtek-gcc v3.19, Sun Jun 16 15:51:54 2024
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
___pc equ [31]
___pd equ [35]
___pa equ [20]
public _segmentNumbers
#pragma debug scope 2 1
#line 20 "c:\users\tech\desktop\gasdetector\Display\Display.c"
_segmentNumbers .section 'code'
_segmentNumbers proc
    local _segmentNumbers_2 db 1 dup(?)	; 0,1
	mov ra,a
	mov _segmentNumbers_2[0],a
#pragma debug variable 8 2 _segmentNumbers_2+0 "number"
#line 22 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,0
	sz z
	jmp _L3
	sub a,(1)-(0)
	sz z
	jmp _L4
#line 22 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,2
	sz z
	jmp _L5
	sub a,(3)-(2)
	sz z
	jmp _L6
	mov a,ra
	sub a,4
	sz z
	jmp _L7
	sub a,(5)-(4)
	sz z
	jmp _L8
	mov a,ra
	sub a,6
	sz z
	jmp _L9
	sub a,(7)-(6)
	sz z
	jmp _L10
	mov a,ra
	sub a,8
	sz z
	jmp _L11
	mov a,ra
	sub a,9
	snz z
	jmp _L1
#line 113 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 114 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
	jmp _L15
_L3:
#line 26 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 27 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 28 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 29 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
#line 30 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
#line 31 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].1
	jmp _L13
_L4:
#line 36 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
	jmp _L18
_L5:
#line 46 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 47 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 48 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].4
#line 49 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
#line 50 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
	jmp _L20
_L6:
#line 56 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 57 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 58 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 59 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
#line 60 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].6
_L20:
#line 61 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].1
	jmp _L17
_L7:
#line 66 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 67 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 68 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 69 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [20].7
	jmp _L16
_L8:
#line 76 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 77 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
	jmp _L15
_L9:
#line 86 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 87 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
	jmp _L19
_L10:
#line 95 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
_L18:
#line 96 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 97 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 98 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [20].7
#line 99 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].6
#line 100 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].1
_L13:
#line 101 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].3
#line 102 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	jmp _L1
_L11:
#line 104 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 105 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
_L19:
#line 106 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 107 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
#line 108 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
	jmp _L14
_L15:
#line 115 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 116 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
_L16:
#line 117 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].6
_L14:
#line 118 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].1
_L17:
#line 119 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].3
_L1:
	ret
_segmentNumbers endp
#line 119 "c:\users\tech\desktop\gasdetector\Display\Display.c"
#pragma debug scope 1 1
public _segmentCharacters
#pragma debug scope 3 1
#line 126 "c:\users\tech\desktop\gasdetector\Display\Display.c"
_segmentCharacters .section 'code'
_segmentCharacters proc
    local _segmentCharacters_2 db 1 dup(?)	; 0,1
	mov ra,a
	mov _segmentCharacters_2[0],a
#pragma debug variable 8 3 _segmentCharacters_2+0 "character"
#line 128 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,65
	sz z
	jmp _L24
	sub a,(69)-(65)
	sz z
	jmp _L25
#line 128 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,76
	sz z
	jmp _L26
	sub a,(78)-(76)
	sz z
	jmp _L27
	mov a,ra
	sub a,79
	sz z
	jmp _L28
	sub a,(83)-(79)
	sz z
	jmp _L29
	mov a,ra
	sub a,84
	sz z
	jmp _L30
	sub a,(98)-(84)
	sz z
	jmp _L31
	mov a,ra
	sub a,111
	sz z
	jmp _L32
	mov a,ra
	sub a,114
	snz z
	jmp _L22
#line 201 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 202 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 203 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].4
#line 204 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [20].7
	jmp _L41
_L24:
#line 131 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 132 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 133 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 134 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [20].7
	jmp _L38
_L31:
#line 141 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 142 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 143 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
	jmp _L39
_L26:
#line 151 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 152 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 153 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].4
#line 154 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
	jmp _L41
_L27:
#line 161 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 162 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 163 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 164 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [20].7
	jmp _L40
_L32:
#line 171 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].7
#line 172 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 173 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 174 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
_L40:
#line 175 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
#line 176 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].1
	jmp _L37
_L28:
#line 181 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 182 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 183 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].4
#line 184 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [20].7
	jmp _L36
_L25:
#line 191 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 192 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 193 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].4
_L39:
#line 194 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
_L38:
#line 195 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
	jmp _L35
_L41:
#line 205 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].6
#line 206 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].1
	jmp _L34
_L29:
#line 210 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 211 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].0
#line 212 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 213 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [20].7
_L36:
#line 214 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].6
_L35:
#line 215 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].1
_L37:
#line 216 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].3
#line 217 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	jmp _L22
_L30:
#line 221 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].7
#line 222 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [35].0
#line 223 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [31].4
#line 224 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [20].7
#line 225 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].6
#line 226 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [35].1
_L34:
#line 227 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [31].3
_L22:
	ret
_segmentCharacters endp
#line 227 "c:\users\tech\desktop\gasdetector\Display\Display.c"
#pragma debug scope 1 1
___pb equ [27]
public _Display
#pragma debug scope 4 1
#line 234 "c:\users\tech\desktop\gasdetector\Display\Display.c"
_Display .section 'code'
_Display proc
public _Display_2
    local _Display_2 db 6 dup(?)	; 5,1
#pragma debug variable 11 4 _Display_2+0 "number"
#pragma debug variable 8 4 _Display_2+2 "character"
#pragma debug pointer 42 7 4
#pragma debug variable 42 4 _Display_2+3 "clock"
#line 235 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[3]
	mov mp,a
	mov a,_Display_2[4]
	mov sbp,a
	call _Crom2Prom
	mov _Display_2[5],a
	mov a,_Display_2[5]
	sub a,0
	sz z
	jmp _L44
	sub a,(1)-(0)
	sz z
	jmp _L45
#line 235 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[5]
	sub a,2
	sz z
	jmp _L46
	mov a,_Display_2[5]
	sub a,3
	snz z
	jmp _L42
#line 279 "c:\users\tech\desktop\gasdetector\Display\Display.c"
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
	mov a,rb
	call _segmentNumbers
#line 281 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 282 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 283 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
#line 284 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].4
#line 286 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	jmp _L42
_L44:
#line 239 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[2]
	sub a,48
	sz z
	jmp _L48
#line 242 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[2]
	mov ra,a
	mov a,ra
	call _segmentCharacters
	jmp _L49
_L48:
#line 247 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[0]
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,_Display_2[1]
	mov _builtin_holtek_udivmodhi4_2[1],a
	mov a,232
	mov _builtin_holtek_udivmodhi4_2[2],a
	mov a,3
	mov _builtin_holtek_udivmodhi4_2[3],a
	call _builtin_holtek_divmodhi4
	mov a,_builtin_holtek_udivmodhi4_2[0]
	mov rb,a
	mov a,_builtin_holtek_udivmodhi4_2[1]
	mov rc,a
	mov a,rb
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,rc
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
	mov a,rb
	call _segmentNumbers
_L49:
#line 250 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].5
#line 251 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
	jmp _L51
_L45:
#line 260 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[0]
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,_Display_2[1]
	mov _builtin_holtek_udivmodhi4_2[1],a
	mov a,100
	mov _builtin_holtek_udivmodhi4_2[2],a
	mov a,0
	mov _builtin_holtek_udivmodhi4_2[3],a
	call _builtin_holtek_divmodhi4
	mov a,_builtin_holtek_udivmodhi4_2[0]
	mov rb,a
	mov a,_builtin_holtek_udivmodhi4_2[1]
	mov rc,a
	mov a,rb
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,rc
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
	mov a,rb
	call _segmentNumbers
#line 261 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 262 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].6
_L51:
#line 263 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
	jmp _L50
_L46:
#line 269 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,_Display_2[0]
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,_Display_2[1]
	mov _builtin_holtek_udivmodhi4_2[1],a
	mov a,10
	mov _builtin_holtek_udivmodhi4_2[2],a
	mov a,0
	mov _builtin_holtek_udivmodhi4_2[3],a
	call _builtin_holtek_divmodhi4
	mov a,_builtin_holtek_udivmodhi4_2[0]
	mov rb,a
	mov a,_builtin_holtek_udivmodhi4_2[1]
	mov rc,a
	mov a,rb
	mov _builtin_holtek_udivmodhi4_2[0],a
	mov a,rc
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
	mov a,rb
	call _segmentNumbers
#line 271 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 272 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 273 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].7
_L50:
#line 274 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].4
_L42:
	ret
_Display endp
#line 274 "c:\users\tech\desktop\gasdetector\Display\Display.c"
#pragma debug scope 1 1
public _DisplayLoading
#pragma debug scope 5 1
#line 293 "c:\users\tech\desktop\gasdetector\Display\Display.c"
_DisplayLoading .section 'code'
_DisplayLoading proc
    local _DisplayLoading_2 db 1 dup(?)	; 0,1
	mov ra,a
	mov _DisplayLoading_2[0],a
#pragma debug variable 7 5 _DisplayLoading_2+0 "cunterDigit"
#line 295 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,0
	sz z
	jmp _L54
	sub a,(1)-(0)
	sz z
	jmp _L60
#line 295 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,2
	sz z
	jmp _L59
	sub a,(3)-(2)
	sz z
	jmp _L64
	mov a,ra
	sub a,4
	sz z
	jmp _L58
	sub a,(5)-(4)
	sz z
	jmp _L59
	mov a,ra
	sub a,6
	sz z
	jmp _L60
	mov a,ra
	sub a,7
	snz z
	jmp _L52
	jmp _L61
_L54:
#line 298 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,111
	call _segmentCharacters
	jmp _L61
_L58:
#line 333 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,79
	call _segmentCharacters
_L64:
#line 334 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 335 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 336 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
#line 337 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].4
#line 339 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	jmp _L52
_L59:
#line 343 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 344 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 345 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].7
	jmp _L62
_L60:
#line 352 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 353 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].6
	jmp _L63
_L61:
#line 362 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].5
#line 363 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
_L63:
#line 364 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
_L62:
#line 365 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].4
_L52:
	ret
_DisplayLoading endp
#line 365 "c:\users\tech\desktop\gasdetector\Display\Display.c"
#pragma debug scope 1 1
public _DisplayBatteryLOW
#pragma debug scope 6 1
#line 374 "c:\users\tech\desktop\gasdetector\Display\Display.c"
_DisplayBatteryLOW .section 'code'
_DisplayBatteryLOW proc
    local _DisplayBatteryLOW_2 db 1 dup(?)	; 0,1
	mov ra,a
	mov _DisplayBatteryLOW_2[0],a
#pragma debug variable 7 6 _DisplayBatteryLOW_2+0 "cunterDigit"
#line 375 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,0
	sz z
	jmp _L67
	sub a,(1)-(0)
	sz z
	jmp _L68
#line 375 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,2
	sz z
	jmp _L69
	mov a,ra
	sub a,3
	snz z
	jmp _L65
#line 402 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,84
	call _segmentCharacters
#line 403 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 404 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 405 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
#line 406 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].4
#line 408 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	jmp _L65
_L67:
#line 378 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,76
	call _segmentCharacters
#line 379 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].5
#line 380 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
	jmp _L72
_L68:
#line 386 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,98
	call _segmentCharacters
#line 387 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 388 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].6
_L72:
#line 389 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
	jmp _L71
_L69:
#line 394 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,65
	call _segmentCharacters
#line 395 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 396 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 397 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].7
_L71:
#line 398 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].4
_L65:
	ret
_DisplayBatteryLOW endp
#line 398 "c:\users\tech\desktop\gasdetector\Display\Display.c"
#pragma debug scope 1 1
public _DisplayBatteryError
#pragma debug scope 7 1
#line 415 "c:\users\tech\desktop\gasdetector\Display\Display.c"
_DisplayBatteryError .section 'code'
_DisplayBatteryError proc
    local _DisplayBatteryError_2 db 1 dup(?)	; 0,1
	mov ra,a
	mov _DisplayBatteryError_2[0],a
#pragma debug variable 7 7 _DisplayBatteryError_2+0 "cunterDigit"
#line 416 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,0
	sz z
	jmp _L75
	sub a,(1)-(0)
	sz z
	jmp _L76
#line 416 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,2
	sz z
	jmp _L77
	mov a,ra
	sub a,3
	snz z
	jmp _L73
#line 443 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,114
	call _segmentCharacters
#line 444 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 445 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 446 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
#line 447 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].4
#line 449 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	jmp _L73
_L75:
#line 419 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,98
	call _segmentCharacters
#line 420 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].5
#line 421 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
	jmp _L80
_L76:
#line 427 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,69
	call _segmentCharacters
#line 428 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 429 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].6
_L80:
#line 430 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
	jmp _L79
_L77:
#line 435 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,114
	call _segmentCharacters
#line 436 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 437 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 438 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].7
_L79:
#line 439 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].4
_L73:
	ret
_DisplayBatteryError endp
#line 439 "c:\users\tech\desktop\gasdetector\Display\Display.c"
#pragma debug scope 1 1
public _DisplaySupplyError
#pragma debug scope 8 1
#line 456 "c:\users\tech\desktop\gasdetector\Display\Display.c"
_DisplaySupplyError .section 'code'
_DisplaySupplyError proc
    local _DisplaySupplyError_2 db 1 dup(?)	; 0,1
	mov ra,a
	mov _DisplaySupplyError_2[0],a
#pragma debug variable 7 8 _DisplaySupplyError_2+0 "cunterDigit"
#line 457 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,0
	sz z
	jmp _L83
	sub a,(1)-(0)
	sz z
	jmp _L84
#line 457 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,2
	sz z
	jmp _L85
	mov a,ra
	sub a,3
	snz z
	jmp _L81
#line 484 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,114
	call _segmentCharacters
#line 485 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 486 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 487 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
#line 488 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].4
#line 490 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	jmp _L81
_L83:
#line 460 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,112
	call _segmentCharacters
#line 461 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].5
#line 462 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
	jmp _L88
_L84:
#line 468 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,69
	call _segmentCharacters
#line 469 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 470 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].6
_L88:
#line 471 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
	jmp _L87
_L85:
#line 476 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,114
	call _segmentCharacters
#line 477 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 478 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 479 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].7
_L87:
#line 480 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].4
_L81:
	ret
_DisplaySupplyError endp
#line 480 "c:\users\tech\desktop\gasdetector\Display\Display.c"
#pragma debug scope 1 1
public _DisplaySensorError
#pragma debug scope 9 1
#line 497 "c:\users\tech\desktop\gasdetector\Display\Display.c"
_DisplaySensorError .section 'code'
_DisplaySensorError proc
    local _DisplaySensorError_2 db 1 dup(?)	; 0,1
	mov ra,a
	mov _DisplaySensorError_2[0],a
#pragma debug variable 7 9 _DisplaySensorError_2+0 "cunterDigit"
#line 498 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,0
	sz z
	jmp _L91
	sub a,(1)-(0)
	sz z
	jmp _L92
#line 498 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,ra
	sub a,2
	sz z
	jmp _L93
	mov a,ra
	sub a,3
	snz z
	jmp _L89
#line 525 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,69
	call _segmentCharacters
#line 526 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 527 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 528 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
#line 529 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].4
#line 531 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	jmp _L89
_L91:
#line 501 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,83
	call _segmentCharacters
#line 502 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].5
#line 503 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
	jmp _L96
_L92:
#line 509 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,69
	call _segmentCharacters
#line 510 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 511 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].6
_L96:
#line 512 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].7
	jmp _L95
_L93:
#line 517 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	mov a,110
	call _segmentCharacters
#line 518 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].5
#line 519 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].6
#line 520 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	set [27].7
_L95:
#line 521 "c:\users\tech\desktop\gasdetector\Display\Display.c"
	clr [27].4
_L89:
	ret
_DisplaySensorError endp
#line 521 "c:\users\tech\desktop\gasdetector\Display\Display.c"
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
; Generated by holtek-gcc v3.19, Sun Jun 16 15:51:54 2024
; Rebuild 718
; end of file
