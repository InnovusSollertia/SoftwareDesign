SECTION .data 
	offer: DB 'Write some text: ', 10
	offerLen: EQU $-offer
	result: DB 'Your reversed text: ', 10
	resultLen: EQU $-result

SECTION .bss
	original: RESB 80
	reversed: RESB 80

SECTION .text
GLOBAL _start

_start: 
	mov eax, 4
	mov ebx, 1
	mov ecx, offer
	mov edx, offerLen
	int 80h
	
	mov eax, 3
	mov ebx, 0
	mov ecx, original
	mov edx, 80
	int 80h

	mov ecx, 0
	mov esi, original
	mov edx, reversed
	
;	mov eax, 5
;	mov ebx, ecx
;	mov esi, reversed

_steps: 
	mov al, byte[esi]
	cmp al, 10
	je _reverse
	push ax
	inc esi
	inc ecx
	jmp _steps
 
_reverse: 
	pop ax
	mov byte[edx], al
	inc edx
	loop _reverse
	
	mov byte [edx], 10

	mov eax, 4
	mov ebx, 1
	mov ecx, result,
	mov edx, resultLen
	int 80h
	
	mov eax, 4
	mov ebx, 1
	mov ecx, reversed
	mov edx, 80
	int 80h
	
	mov eax, 1
	mov ebx, 0
	int 80h	
