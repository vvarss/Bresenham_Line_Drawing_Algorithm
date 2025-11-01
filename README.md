# 🛑Bresenham_Line_Drawing_Algorithm
## ➕Project Overview
   This project implements Bresenham’s Line Drawing Algorithm in C using OpenGL (GLUT) to draw lines across all 8 octants.
 The algorithm uses integer-based rasterization, making it fast, efficient, and ideal for computer graphics applications.

## ⭕Features

* Implementation of Bresenham’s Line Algorithm
* Handles all 8 octants (positive/negative slopes, steep/shallow lines)
* Draws line segments using pixel plotting
* Built using C, OpenGL, and GLUT
* Simple and clear visualization
  
## ⭕How It Works
### Core Function: bresenham()
The algorithm:
* Computes dx and dy
* Decides step direction for x and y (sx, sy)
* Selects appropriate decision parameter p
Handles both:
Slope ≤ 1
Slope > 1

## ⭕Pixel Rendering

Each pixel is plotted using:

```
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
```

## ⭕Advantages of using Line Drawing Algorithm
* Uses no floating-point operations
* Faster than DDA
* Produces visually consistent rasterized lines
* Used for Rasterization demos
* Used in Low-level rendering engines

## ✨Output 
<img width="489" height="497" alt="image" src="https://github.com/user-attachments/assets/6cd41297-c4cc-46b6-94e0-7136e3d7b667" />
