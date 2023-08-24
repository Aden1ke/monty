# Comprehensive test for the Monty interpreter
push 1
push 2
push 3
pall
pop
pall
push 4
push 5
pop
pop
pop
pall
push 6
push 7
pint
pop
pall
add
pall
sub
pall
mul
pall
div
pall
mod
pall
push 8
push 9
swap
pall
nop
pall
pchar
pstr
push 10
push 11
push 12
rotl
pall
rotr
pall
stack
queue
pall
# Errors and edge cases
push a
push
pop
pint
add
sub
mul
div
mod
swap
pchar
pstr
rotl
rotr
pall

