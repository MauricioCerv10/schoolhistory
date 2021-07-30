section .bss
	string resb 50
section .text
global _start

_start:
	mov edx,50d
        mov ecx,string
        mov ebx,0
        mov eax,3
        int 0x80

	mov eax,string
	mov ecx,-1
loop:
    	inc ecx
    	cmp byte [eax + ecx], 0
    	jne loop
	mov eax,ecx
	dec eax
loop2:
	mov edx,0
	mov ebx,10
	div ebx
	add edx,48
	push edx
	inc esi
	cmp eax,0
	jz next
	jmp loop2
next:
	cmp esi,0
	jz done
	dec esi
	mov eax,4
	mov ecx,esp
	mov ebx,1
	mov edx,1
	int 0x80
	add esp,4
	jmp next
done:
    	mov eax, 1
    	mov ebx, ecx
    	int 0x80

