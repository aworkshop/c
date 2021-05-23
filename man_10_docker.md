## Using docker or a vm and tools

When you don't have the compiler, try to use docker. Install the compiler and
debugger.
```
docker run -it ubuntu
apt-get update
apt-get install gcc
apt-get install gdb
apt-get install ltrace
apt-get install nano
```

## Using gcc

We saw gcc that just compiles the source, using ```-o``` we can specify the
name of the output executable.

GCC is combining multiple phases;
- Pre-process (pre-compile)
- Compile
- Assemble
- Link (links multiple object files together)

Other options will be shown later.


## Using objdump

Copy the 07_createfile.c to this image and compile it. We can look into
the ```a.out``` sections in a hexdump format. Below we only show 1 section.

```
# objdump -s a.out

a.out:     file format elf64-x86-64

<deleted sections>

Contents of section .rodata:
 2000 01000200 55736167 653a2025 73203c73  ....Usage: %s <s
 2010 697a653e 203c6669 6c656e61 6d653e0a  ize> <filename>.
 2020 0053697a 696e6720 256c6420 746f2025  .Sizing %ld to %
 2030 732e0a00 7700                        s...w.

<deleted sections>
```

Using the same objdump we can also disassemble.

```
 # objdump -S a.out

 a.out:     file format elf64-x86-64

 Disassembly of section .init:

 0000000000001000 <_init>:
     1000:	f3 0f 1e fa          	endbr64
     1004:	48 83 ec 08          	sub    $0x8,%rsp
     1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
     100f:	48 85 c0             	test   %rax,%rax
     1012:	74 02                	je     1016 <_init+0x16>
     1014:	ff d0                	callq  *%rax
     1016:	48 83 c4 08          	add    $0x8,%rsp
     101a:	c3                   	retq

<deleted sections>

00000000000010c0 <printf@plt>:
    10c0:	f3 0f 1e fa          	endbr64
    10c4:	f2 ff 25 dd 2e 00 00 	bnd jmpq *0x2edd(%rip)        # 3fa8 <printf@GLIBC_2.2.5>
    10cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

<deleted sections>

0000000000001209 <main>:
    1209:	f3 0f 1e fa          	endbr64
    120d:	55                   	push   %rbp
    120e:	48 89 e5             	mov    %rsp,%rbp
    1211:	48 83 ec 30          	sub    $0x30,%rsp
    1215:	89 7d dc             	mov    %edi,-0x24(%rbp)
    1218:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
    121c:	83 7d dc 03          	cmpl   $0x3,-0x24(%rbp)
    1220:	74 25                	je     1247 <main+0x3e>
    1222:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    1226:	48 8b 00             	mov    (%rax),%rax
    1229:	48 89 c6             	mov    %rax,%rsi
    122c:	48 8d 3d d1 0d 00 00 	lea    0xdd1(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
    1233:	b8 00 00 00 00       	mov    $0x0,%eax
    1238:	e8 83 fe ff ff       	callq  10c0 <printf@plt>
    123d:	bf 01 00 00 00       	mov    $0x1,%edi
    1242:	e8 c9 fe ff ff       	callq  1110 <exit@plt>
    ....
    ....
<deleted sections>

```

In the above sections, we see ```init```, we see ```printf``` and ```main```
that calls functions like ```printf```. Many sections are not displayed here.

Functions like ```printf``` have compiled code in _object files_ and
are _linked_ with ours.


## file

```
# file a.out
a.out: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=7c95bc4a3984f7f81407911afe85ebfcdb51050d, for GNU/Linux 3.2.0, not stripped
#
```

Here ```not stripped``` means it is not stripped from debug info.

## strip

The (debug) information can be stripped, the file size will be less.
```
# strip a.out -o b.out
# ls -l *.out
-rwxr-xr-x 1 root root 16960 May 23 13:23 a.out
-rwxr-xr-x 1 root root 14472 May 23 13:45 b.out
#
```

### gcc with debug information for gdb

When you start gdb and it tells you that you miss debug info, you can add that
to the file. This file will be larger.

```
# gcc -ggdb 07_createfile.c
# ls -l a.out
-rwxr-xr-x 1 root root 19632 May 23 14:13 a.out
# gdb a.out
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.out...
(gdb)
(gdb) b main
Breakpoint 1 at 0x1209: file 09_createfile.c, line 4.
(gdb) disas main
Dump of assembler code for function main:
   0x0000000000001209 <+0>:	endbr64
   0x000000000000120d <+4>:	push   %rbp
   0x000000000000120e <+5>:	mov    %rsp,%rbp
   0x0000000000001211 <+8>:	sub    $0x30,%rsp
   0x0000000000001215 <+12>:	mov    %edi,-0x24(%rbp)
   0x0000000000001218 <+15>:	mov    %rsi,-0x30(%rbp)
   0x000000000000121c <+19>:	cmpl   $0x3,-0x24(%rbp)
   0x0000000000001220 <+23>:	je     0x1247 <main+62>
   0x0000000000001222 <+25>:	mov    -0x30(%rbp),%rax
   0x0000000000001226 <+29>:	mov    (%rax),%rax
   0x0000000000001229 <+32>:	mov    %rax,%rsi
   0x000000000000122c <+35>:	lea    0xdd1(%rip),%rdi        # 0x2004
   0x0000000000001233 <+42>:	mov    $0x0,%eax
   0x0000000000001238 <+47>:	callq  0x10c0 <printf@plt>
   0x000000000000123d <+52>:	mov    $0x1,%edi
   0x0000000000001242 <+57>:	callq  0x1110 <exit@plt>
   ...
   ...
```

## objdump with debug info

When compiled with gdb debug info, this is shown inline in objdump.

```
...
...
0000000000001209 <main>:
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    1209:	f3 0f 1e fa          	endbr64
    120d:	55                   	push   %rbp
    120e:	48 89 e5             	mov    %rsp,%rbp
    1211:	48 83 ec 30          	sub    $0x30,%rsp
    1215:	89 7d dc             	mov    %edi,-0x24(%rbp)
    1218:	48 89 75 d0          	mov    %rsi,-0x30(%rbp)
    if (argc != 3) {
    121c:	83 7d dc 03          	cmpl   $0x3,-0x24(%rbp)
    1220:	74 25                	je     1247 <main+0x3e>
      printf("Usage: %s <size> <filename>\n", argv[0]);
    1222:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    1226:	48 8b 00             	mov    (%rax),%rax
    1229:	48 89 c6             	mov    %rax,%rsi
    122c:	48 8d 3d d1 0d 00 00 	lea    0xdd1(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
    1233:	b8 00 00 00 00       	mov    $0x0,%eax
    1238:	e8 83 fe ff ff       	callq  10c0 <printf@plt>
      exit(1);
    123d:	bf 01 00 00 00       	mov    $0x1,%edi
    1242:	e8 c9 fe ff ff       	callq  1110 <exit@plt>
    }
    long size = atol(argv[1]);
    1247:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    124b:	48 83 c0 08          	add    $0x8,%rax
    124f:	48 8b 00             	mov    (%rax),%rax
    1252:	48 89 c7             	mov    %rax,%rdi
    1255:	e8 96 fe ff ff       	callq  10f0 <atol@plt>
    125a:	48 89 45 e8          	mov    %rax,-0x18(%rbp)
    char *name = argv[2];
    125e:	48 8b 45 d0          	mov    -0x30(%rbp),%rax
    1262:	48 8b 40 10          	mov    0x10(%rax),%rax
    1266:	48 89 45 f0          	mov    %rax,-0x10(%rbp)
    printf("Sizing %ld to %s.\n", size, name);
    126a:	48 8b 55 f0          	mov    -0x10(%rbp),%rdx
    126e:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
    1272:	48 89 c6             	mov    %rax,%rsi
    1275:	48 8d 3d a5 0d 00 00 	lea    0xda5(%rip),%rdi        # 2021 <_IO_stdin_used+0x21>
    127c:	b8 00 00 00 00       	mov    $0x0,%eax
    1281:	e8 3a fe ff ff       	callq  10c0 <printf@plt>
    ...
    ...
```

The ```-visualize-jumps``` option makes it easier to show these.

```
...
1315:	/----- 74 1f                	je     1336 <__libc_csu_init+0x56>
1317:	|      31 db                	xor    %ebx,%ebx
1319:	|      0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
1320:	|  /-> 4c 89 f2             	mov    %r14,%rdx
1323:	|  |   4c 89 ee             	mov    %r13,%rsi
1326:	|  |   44 89 e7             	mov    %r12d,%edi
1329:	|  |   41 ff 14 df          	callq  *(%r15,%rbx,8)
132d:	|  |   48 83 c3 01          	add    $0x1,%rbx
1331:	|  |   48 39 dd             	cmp    %rbx,%rbp
1334:	|  \-- 75 ea                	jne    1320 <__libc_csu_init+0x40>
1336:	\----> 48 83 c4 08          	add    $0x8,%rsp
133a:	       5b                   	pop    %rbx
...
```

## Modify jumps

In the above disassembled code you see instructions like ```je``` jump-if-equal,
and ```jne``` jump-if-not-equal. These have hexadecimal codes ```74``` and
```75```. So if we get executable and want to modify the behavior, we can
try to change that byte.


## ltrace

With our example code, the ltrace has almost no useful output. So try this on
your own larger apps yourself.

```
# gcc -ggdb 09_hexdump.c -o hd
# echo "Hello World." | ltrace  ./hd
...
```
