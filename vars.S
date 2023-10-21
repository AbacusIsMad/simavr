.section .data
.global a
.global b
.global empty
.global my_string
.size a, 2
a: .byte 1, 2
.size b, 7
b: .byte 3, 4, 5, 6, 7, 8, 9
.size empty, 10
empty: .zero 10
.size my_string, 13
my_string: .asciz "hello world!"

.section .text
.global woah
woah:
	add r24, r22
	ret

.end
