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