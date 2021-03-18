# ST Background Event Emitter

This is a simple program that uses Xorg to emit an event, that prompts the currently running st instances to update their image background.

Not that for this to work, st must have been patched to use [image backgrounds](https://github.com/hexoctal/st-image-background).

# Compilation

To compile, run make in the project directory:

```shell
make
```

# Usage

To use this, just run the program:

```shell
./st-bg-event
```

You should probably use this program in a theme script instead of running it yourself every time you set a new background image. Use this [script](https://github.com/hexoctal/change-theme) if you don't want to write your own.
