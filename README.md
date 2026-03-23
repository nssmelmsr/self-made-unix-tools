# Self made linux utils
Collection of Unix utilities implemented in C using POSIX APIs.

## Programs

### mycat
Simple implementation of the Unix `cat` command.

Usage:
- ./mycat `file1` `file2` `...`

Uses:
- open()
- read()
- write()

### myls
Simple implementation of the Unix `ls` command.

Usage:
- ./myls `directory`
If no directory is used myls lists actual directory

Uses:
- opendir()
- readdir()

### mywc
Simple implementation of word count utility

Usage:
- ./mywc `file`

Uses:
- open()
- read()

### myps
Simple process snapshot utility

Usage:
- ./myps

Uses:
- opendir()
- readdir()
- open()
- read()

## Build

Use directly the `make` command to build all utilities