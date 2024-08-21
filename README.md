# libasm
Small project to learn assembly by re-coding a few functions of the libft (first 42 common core project) in assembly, such as strlen etc

## todos
- [ ] code all functions
- [ ] check for errors and set errno, using `extern ___error` or `errno_location`

## Learning ressources
- This seems great, by the author of 'What all programmmers should know about memory': [Programming from the ground up](https://people.freebsd.org/~lstewart/articles/programming_from_the_ground_up.pdf)

## notes here until I get obsidian
- assembly as about talking to the cpu
    - cpu reads instructions and executes them one by one with the **fetch-execute cycle**
        - Program Counter ?
            - indicates where next instruction to load is
        - Instruction Decoder
            - cpu loads from memory address that program counter gives, and that's passed to instruction decoder, who handles what to do with it
            - operator: function to deal with (arithmetic, moving data, etc)
            - operands: memory addresse(s) of data involved in function above
        - Data Bus
            - retrieves the values at the memory addresses involved in the operation we're trying to compute
            - connects CPU to memory. It's actually a wire (a physical wire)
        - Registers
            - registers are in-cpu memory
        - Arithmetic and Logic Unit (ALU)
## reference
-  argument registers: rdi   rsi   rdx   r10   r8    r9 
- data directives (size, define data, reserve data)
    - bytes 1 = db = rb
    - bytes 2 = dw = rw
    - bytes 4 = dd = rd
    - bytes 8 = dq = rq
    - bytes 16 = dt = rt
    - bytes 32 = dq = rq
    - bytes 64 = dq = rq
    - bytes 128 = dq = rq
- htons (host to network short) by hand. means changing the byte order  to network byte order, whatever that is
    - print hex value of a number
    - swap bytes: 0x16D9 becomes 0xD916
- run strace to debug easily
    - strace ./a.out
- compilation
    - nasm -f elf64 *.s
    - ld *.o
    - strace ./a.out
- getting nasm defines
    - create c file that imports includes you're interested in
    - define nasm constants in nasm syntax `%define socket SYS_socket`
    - sys/syscall.h gives you the syscall numbers corresponding to functio names
    - run gcc -E -P constants.c > constants.txt to get the preprocessed output, including the nasm defines so you can copy paste them in the asm file