.section .data
.global b
.global empty
.global my_string
.size b, 7
b: .byte 3, 4, 5, 6, 7, 8, 9
.size empty, 10
empty: .zero 10
.size my_string, 13
my_string: .asciz "hello world!"

.section .text
.global woah
woah:
	;change this to fail the functionality testcases
	add r24, r22
	;uncomment the below to fail the stack testcase
	/*
	pop r26
	pop r27
	push r0
	push r27
	push r26
	*/
	;uncomment the below to fail the register testcase
	;inc r4
	;inc r5
	
	;comment below to fail the return testcase
	ret

.end
