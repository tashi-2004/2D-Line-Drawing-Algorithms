# 2D-Line-Drawing-Algorithms-VectorLineRenderer
This project demonstrates the implementation of three fundamental line drawing algorithms in 2D space using SDL:
- Bresenham Line Algorithm
- Midpoint Line Algorithm
- Parametric Line Algorithm

## Project Structure

The project consists of two main files:
- `Algo.cpp`: Contains the `main` function which sets up the SDL environment and handles rendering and input.
- `Header.h`: Contains all the function implementations for line drawing, pixel drawing, clearing the back buffer, and handling input.

## Functionality

### Initialization
The program initializes SDL, creates a window and a renderer, and sets up the initial screen.

### Clearing the Back Buffer
The `ClearBackBuffer` function clears the screen to a specified color.

### Drawing Pixels
The `DrawPixel` function draws a single pixel at a given position with a specified color.

### Drawing Markers
The `DrawMarker` function draws a square marker of a specified size and color at a given position.

### Line Drawing Algorithms
The project implements three line drawing algorithms:
- **Bresenham Line Algorithm:** Efficiently draws lines using integer calculations.
- **Midpoint Line Algorithm:** Draws lines by determining the midpoint between two points.
- **Parametric Line Algorithm:** Draws lines using parametric equations.

### Random Line Drawing
When key 1, 2, or 3 are pressed, the program draws a random line of a specified color (red, green, or blue/purple) on the screen and marks the start and end points with yellow pixels.

  <img width="1000" height="650" alt="1" src="https://github.com/user-attachments/assets/6c56eaf9-9225-4217-8900-b9c2b09412cc">

  <img width="1000" height="650" alt="2" src="https://github.com/user-attachments/assets/524e193e-8008-41a5-9ab6-5b2a4e168ed3">

  <img width="1000" height="650" alt="3" src="https://github.com/user-attachments/assets/ea79e72f-6a74-4e54-895d-d42c2be80b22">


### Sky of Stars
When key 4 is pressed, all lines are cleared, and the screen is filled with randomly placed white pixels, simulating a sky full of stars.

   <img width="1000" height="650" alt="4" src="https://github.com/user-attachments/assets/e69677e0-cdf6-4134-a59e-6cb966cd3deb">


### Final Output 

  <img width="1000" height="650" alt="5" src="https://github.com/user-attachments/assets/f73372dd-23e8-404d-b89c-87b100b9ca03">

### Video

https://github.com/user-attachments/assets/48517f9a-f6b5-4513-8bb7-ca90621c21b9

### Handling User Input
The `HandleInput` function captures keyboard input to draw lines or clear the screen based on the user's key presses.

## Setup

To set up the SDL library in Visual Studio, follow the instructions provided in this [YouTube tutorial](https://youtu.be/13AEnd8XB70?si=IXO8L4JBEZiY1018).

## How to Run

1. Clone this repository.
2. Set up SDL in your development environment.
3. Compile and run `Algo.cpp`.

## Contributors

- M.Tashfeen Abbasi
- [Laiba Mazhar](https://github.com/laiba-mazhar)

## Contact

For any questions or suggestions, feel free to contact at [abbasitashfeen7@gmail.com]

---

Enjoy experimenting with 2D line drawing algorithms!
