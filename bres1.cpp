#include <GL/glut.h>
#include <cmath>

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 >= x1) ? 1 : -1;
    int sy = (y2 >= y1) ? 1 : -1;

    int x = x1;
    int y = y1;

    // Slope <= 1
    if (dx >= dy) {
        int p = 2 * dy - dx;
        for (int i = 0; i <= dx; i++) {
            setPixel(x, y);
            x += sx;
            if (p < 0)
                p += 2 * dy;
            else {
                y += sy;
                p += 2 * dy - 2 * dx;
            }
        }
    } 
    // Slope > 1
    else {
        int p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++) {
            setPixel(x, y);
            y += sy;
            if (p < 0)
                p += 2 * dx;
            else {
                x += sx;
                p += 2 * dx - 2 * dy;
            }
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red color

    // Test lines for all 8 octants
    bresenham(200, 200, 300, 250);  // Octant 1
    bresenham(200, 200, 250, 300);  // Octant 2
    bresenham(200, 200, 150, 300);  // Octant 3
    bresenham(200, 200, 100, 250);  // Octant 4
    bresenham(200, 200, 100, 150);  // Octant 5
    bresenham(200, 200, 150, 100);  // Octant 6
    bresenham(200, 200, 250, 100);  // Octant 7
    bresenham(200, 200, 300, 150);  // Octant 8

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // White background
    glColor3f(1.0, 0.0, 0.0);         // Drawing color
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line - All Octants");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
