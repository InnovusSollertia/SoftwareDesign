text 	segment
assume 	CS:text, DS:data

begin: 	mov AV, data
		mov DS, AX
		move AH, 09h
		mov DX, offset mesg
		int 21h
		mov AH, 4Ch
		mov AL, 0
		in 21h
text	ends
data	segment
mesg	ds 'Начинаем!$'
data	ends
stk		segment stack
		ds 256 dup (0)
stk 	ends
		end	begin
	