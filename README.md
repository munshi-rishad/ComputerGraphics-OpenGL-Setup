# Computer Graphics OpenGL Setup

A ready-to-use OpenGL (FreeGLUT) project for the Computer Graphics course.
FreeGLUT is already inside the project, so you don't need to install or set up anything in Code::Blocks.
Just open the project, write your code in `main.cpp` and run.

It also has **17 small example programs** (points, lines, shapes, colors, transformations, animation, keyboard, DDA, Bresenham and more) that you can run one by one.

## Requirements

- **Windows**
- **Code::Blocks with MinGW** – download the `mingw-setup` version from [codeblocks.org](https://www.codeblocks.org/downloads/binaries/)
- (Optional) **VS Code** with the **C/C++** extension

## Clone the Project

```bash
git clone https://github.com/munshi-rishad/ComputerGraphics-OpenGL-Setup.git
```

## Run in Code::Blocks (easiest)

1. Open `openglportable-64bit/openglportable/openglportable.cbp` in Code::Blocks.
2. Press **F9** (Build and run).
3. A window opens with a white circle. Your setup is working.

## Run in VS Code

1. Install the MinGW compiler (the Code::Blocks `mingw-setup` installer gives it) and add
   `C:\Program Files\CodeBlocks\MinGW\bin` to the Windows `PATH`. Check with `g++ --version`.
2. Open the cloned folder in VS Code and open a terminal (**Terminal → New Terminal**).
3. Build and run:

   ```bash
   cd openglportable-64bit/openglportable
   g++ main.cpp -I../freeglut/include -L../freeglut/lib/x64 -lfreeglut -lopengl32 -lglu32 -o bin/Debug/openglportable.exe
   cd bin/Debug
   ./openglportable.exe
   ```

## How to Try the Examples

1. Open any file in the `examples` folder (for example `examples/06_circle.cpp`).
2. Copy all of its code.
3. Paste it into `openglportable-64bit/openglportable/main.cpp`, replacing everything.
4. Press **F9**.

To write your own program, start from `examples/14_basic_structure.cpp`.

## Project Structure

```
ComputerGraphics-OpenGL-Setup/
├── openglportable-64bit/
│   ├── freeglut/            # FreeGLUT headers, libraries and DLL (already set up)
│   └── openglportable/
│       ├── main.cpp         # write your code here
│       ├── openglportable.cbp   # Code::Blocks project
│       └── bin/Debug/       # freeglut.dll (the .exe is created here)
├── examples/                # 17 ready programs
└── screenshots/             # output of each example
```

## Examples and Output

#### Starter (`main.cpp`)

A white circle in the middle of the window.

![Starter circle](screenshots/00_starter_circle.png)

#### 1. Point – `01_point.cpp`

Three big points using `GL_POINTS`.

![Point](screenshots/01_point.png)

#### 2. Line – `02_line.cpp`

A horizontal and a vertical line using `GL_LINES`.

![Line](screenshots/02_line.png)

#### 3. Triangle – `03_triangle.cpp`

A triangle using `GL_TRIANGLES`.

![Triangle](screenshots/03_triangle.png)

#### 4. Rectangle – `04_rectangle.cpp`

A square using `GL_POLYGON`.

![Rectangle](screenshots/04_rectangle.png)

#### 5. Colors – `05_colors.cpp`

Red, green and blue squares, and a triangle with mixed colors.

![Colors](screenshots/05_colors.png)

#### 6. Circle – `06_circle.cpp`

Circles drawn with `cos` and `sin`.

![Circle](screenshots/06_circle.png)

#### 7. Translation – `07_translation.cpp`

The green square is the gray square moved with `glTranslatef`.

![Translation](screenshots/07_translation.png)

#### 8. Rotation – `08_rotation.cpp`

The orange square is the gray square rotated 45° with `glRotatef`.

![Rotation](screenshots/08_rotation.png)

#### 9. Scaling – `09_scaling.cpp`

The blue square is the white square made 2 times bigger with `glScalef`.

![Scaling](screenshots/09_scaling.png)

#### 10. Timer Animation – `10_timer_animation.cpp`

A square that keeps rotating using `glutTimerFunc`.

![Timer Animation](screenshots/10_timer_animation.png)

#### 11. Keyboard – `11_keyboard.cpp`

Move the square with the arrow keys, `R` resets it, `Esc` closes.

![Keyboard](screenshots/11_keyboard.png)

#### 12. DDA Line – `12_dda_line.cpp`

Lines drawn pixel by pixel with the DDA algorithm.

![DDA Line](screenshots/12_dda_line.png)

#### 13. Bresenham Line – `13_bresenham_line.cpp`

Lines drawn with the Bresenham algorithm (integers only, any direction).

![Bresenham Line](screenshots/13_bresenham_line.png)

#### 14. Basic Structure – `14_basic_structure.cpp`

Empty program with comments; start every new program from here.

#### 15. Planet System – `15_planet_system.cpp`

A planet goes around the sun and a moon goes around the planet.

![Planet System](screenshots/15_planet_system.png)

#### 16. Collision – `16_collision.cpp`

Move the green box with the arrow keys; it turns red when it touches the white box.

![Collision](screenshots/16_collision.png)

#### 17. Flag – `17_flag.cpp`

The flag of Bangladesh with a rectangle and a circle.

![Flag](screenshots/17_flag.png)
