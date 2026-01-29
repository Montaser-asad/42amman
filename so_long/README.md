*This project has been created as part of the 42 curriculum by masad.*

# so_long

## Description
so_long is a simple 2D game developed as part of the 42 school curriculum. The goal of the project is to create a small graphical game using the MiniLibX library, where the player navigates a map, collects items, and reaches the exit while avoiding obstacles. The project emphasizes understanding of basic graphics programming, event handling, and file parsing in C.

## Instructions

### Compilation
To compile the project, run the following command in the root directory:

```
make
```

This will build the executable using the provided Makefile. Ensure you have the required dependencies (MiniLibX, X11 libraries) installed on your system.

### Execution
To run the game, use:

```
./so_long maps/map.ber
```

Replace `maps/map1.ber` with the path to your desired map file. Map files must have the `.ber` extension and follow the required format.

## Resources
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [42 School Subject PDF](https://github.com/42Paris/subject/blob/master/so_long/subject.pdf)
- [X11 Documentation](https://www.x.org/releases/current/doc/libX11/libX11/libX11.html)
- [C Programming Reference](https://en.cppreference.com/w/c)

### Use of AI
AI was used to assist with:
- Explaining compilation and execution steps
- helped with explaining prebuilt functions


## Additional Information
- The project uses a custom implementation of standard C library functions (see `libft/`).
- Maps are located in the `maps/` directory.
- Images and assets are in the `imgs/` directory.
- For more details, refer to the source code and comments.
