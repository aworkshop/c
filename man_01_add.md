### 01_add.c
This first example is showing a couple of things that need attention. And it needs improvement. But let us just compile and run it first. Open your terminal and compile and link it.

```
gcc 01_add.c
```

This will show you warnings. And when you ```ls``` this folder there is a new file ```a.out```. And that is already your executable. You can run it by ```./a.out```. You see a prompt, and then type two numbers like ```32 64``` separated by a space or by a new line. It then responds with the calculated sum ```96```.

When you look into the ```01_add.c``` file using a text editor like Atom, VSCode, etcetera, you can see the line number before every line. And that line number is used to discuss the code.

So line numbers 3 and 5 print information, and line 4 is scanning information (our input). You also see on line 4 and 5 this ```%d``` used for the two numbers that are scanned and the sum that is printed, and this ```d``` is used for ```int``` integer values on line 2. There is also the ```\n``` on line 5 and this is just printing a newline character. Line 4 also has ```&a, &b``` and this is the most difficult! The ```scanf``` scan the input according to its format parameter. And stores the scanned values into the addresses of variables a and b. Remember that ```&a``` is the address of ```a```, or the pointer to ```a```.


**Advanced**

When looking on my file system I see that the ```a.out``` is about 8 Kb in size.
It has all kind of binary code, debug information, but also the strings that you recognize from the source code.
Use the ```strings``` command;
```
strings a.out
Enter two numbers:
%d%d
Sum: %d
```

When looking at lines of the executable content, I use a hex-dump. This
shows the address, the bytes in hexadecimal and its character (when printable).
```
xxd a.out | head
00000000: cffa edfe 0700 0001 0300 0080 0200 0000  ................
00000010: 0f00 0000 c004 0000 8500 2000 0000 0000  .......... .....
00000020: 1900 0000 4800 0000 5f5f 5041 4745 5a45  ....H...__PAGEZE
00000030: 524f 0000 0000 0000 0000 0000 0000 0000  RO..............
00000040: 0000 0000 0100 0000 0000 0000 0000 0000  ................
00000050: 0000 0000 0000 0000 0000 0000 0000 0000  ................
00000060: 0000 0000 0000 0000 1900 0000 d801 0000  ................
00000070: 5f5f 5445 5854 0000 0000 0000 0000 0000  __TEXT..........
00000080: 0000 0000 0100 0000 0010 0000 0000 0000  ................
00000090: 0000 0000 0000 0000 0010 0000 0000 0000  ................

xxd a.out | tail
00002080: 0000 0000 0100 0000 1600 0000 0f01 0000  ................
00002090: 000f 0000 0100 0000 1c00 0000 0100 0001  ................
000020a0: 0000 0000 0000 0000 2400 0000 0100 0001  ........$.......
000020b0: 0000 0000 0000 0000 2b00 0000 0100 0001  ........+.......
000020c0: 0000 0000 0000 0000 0200 0000 0300 0000  ................
000020d0: 0400 0000 0000 0040 0200 0000 0300 0000  .......@........
000020e0: 2000 5f5f 6d68 5f65 7865 6375 7465 5f68   .__mh_execute_h
000020f0: 6561 6465 7200 5f6d 6169 6e00 5f70 7269  eader._main._pri
00002100: 6e74 6600 5f73 6361 6e66 0064 796c 645f  ntf._scanf.dyld_
00002110: 7374 7562 5f62 696e 6465 7200 0000 0000  stub_binder.....

file a.out
a.out: Mach-O 64-bit executable x86_64
```
The output depends on the operating system and processor.
