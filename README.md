*This project has been created as part of the 42 curriculum by aalemami*

# Fract-ol

## Description
Fract-ol is a graphical exploration program written in C using the MiniLibX library. It renders mathematically complex fractals like the Mandelbrot set and the Julia set in real-time, allowing users to zoom and navigate deep into the fractal patterns. The project focuses on mathematical visualization, optimization, and event handling.

## Instructions

### Compilation & Usage
Clone the repository and compile using `make`.

```bash
make
./fractol mandelbrot
./fractol julia [cx] [cy]

```

### Controls

* **Scroll Wheel**: Zoom in/out at mouse position.
* **Arrows**: Move view.
* **M / P**: Decrease/Increase iterations.
* **C**: Shift colors.
* **J**: Randomize Julia constants.
* **R**: Reset view.
* **ESC**: Quit.

## Resources

### References

* [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) - Comprehensive documentation for the 42 graphical library.
* [Fract-ol Tutorial by Leo Gaudin](https://medium.com/@leogaudin/fract-ol-creating-graphically-beautiful-fractals-6664b6b045b5) - Guide on creating graphically beautiful fractals.

### AI Usage

Artificial Intelligence (Gemini) was used to assist with specific development tasks:

* **Debugging**: Resolving strict function pointer casting errors in `main.c` for newer compilers.
* **Syntax**: Correcting syntax errors in the `Makefile`.
* **Refactoring**: Condensing the `ft_atof` logic in `utils.c` to meet Norminette length requirements using pointer arithmetic.
* **Structure**: Organizing `main.c` into static helper functions for cleaner argument parsing.

```

```