SECTION .bss
	answer: RESB 80

SECTION .data 

	question: DB 'Полдень наступил?'
	questionLen: EQU $-question
	morning: DB 'Доброе утро!'
	morningLen: EQU $-morning
	day: DB 'Добрый день!'
	dayLen: EQU $-day

SECTION .text

GLOBAL _start

_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, question
	mov edx, questionLen
	int 80h
	
	mov eax, 3
	mov ebx, 0
	mov ecx, answer
	mov edx, 80
	int 80h
	
	cmp byte[answer], 'y'
	je _showDay
	cmp byte[answer], 'n'
	je _showMorning

	jmp _start

_showDay: 
	mov eax, 4
	mov ebx, 1
 	mov ecx, day
	mov edx, dayLen
	int 80h
	jmp end

_showMorning:
	mov eax, 4
	mov ebx, 1
 	mov ecx, morning
	mov edx, morningLen
	int 80h
	jmp end
end: 
	mov eax, 1
	mov ebx, 0
	int 80h
