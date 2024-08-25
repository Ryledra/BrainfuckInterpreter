# BrainfuckInterpreter
A Brainfuck Interpreter

## Install

Run the following command

```
  make clean && make
```

## Run

In-line Brainfuck code can be run:

```
  ./bin/Brainfuck "-[------->+<]>-.--[-->+++<]>."
```

With a brainfuck source file:

```
  ./bin/Brainfuck [-f, --file] /path/to/bf/file
```

Running the program without arguments provides help:

```
  Usage:
    Brainfuck [options] [*brainfuck code]

  Flags:
    -f, --file     indicates the following filepath holds the code
```