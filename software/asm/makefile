build: */*.asm
	nasm -f elf64 -g -l lab03a/lab031.lst lab03a/lab031.asm
	nasm -f elf64 -g -l lab03b/lab03b.lst lab03b/lab03b.asm
	ld -Map lab031.map -o lab031 lab03a/lab031.o
	ld -Map lab03b.map -o lab032 lab03b/lab03b.o
clean: 
	rm -f lab031 lab032 */*.o */*.lst */*.map
