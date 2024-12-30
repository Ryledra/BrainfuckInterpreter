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

## Contributing
### Submit a pull request

If you'd like to contribute, please fork the repository and open a pull request to the `main` branch.
