#include <GL/glut.h>
#include <iostream>

// Funci�n para inicializar OpenGL
void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0); // Establece el color de fondo a blanco
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 600.0); // Establece el sistema de coordenadas
}

// Funci�n para dibujar la l�nea utilizando el algoritmo del punto medio
void drawLine(int x1, int y1, int x2, int y2, float lineWidth) {
	// Calcula la diferencia entre las coordenadas x y y
	int dx = x2 - x1;
	int dy = y2 - y1;
	
	// Calcula la variable de decisi�n inicial
	int d = 2 * dy - dx;
	int incrE = 2 * dy;
	int incrNE = 2 * (dy - dx);
	
	// Punto inicial
	int x = x1, y = y1;
	
	// Dibuja el punto inicial
	glPointSize(lineWidth); // Ajusta el tama�o de los puntos
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	
	// Bucle para dibujar la l�nea
	while (x < x2) {
		if (d <= 0) {
			d += incrE;
			x++;
		} else {
			d += incrNE;
			x++;
			y++;
		}
		glVertex2i(x, y);
	}
	glEnd();
}

// Funci�n de renderizado
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0); // Establece el color de la l�nea a negro
	drawLine(100, 100, 400, 300, 3.0); // Dibuja la l�nea de grosor 5 desde (100, 100) a (400, 300)
	glFlush();
}

// Funci�n principal
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600); // Tama�o de la ventana
	glutInitWindowPosition(100, 100); // Posici�n de la ventana
	glutCreateWindow("Generador de linea en OpenGL"); // T�tulo de la ventana
	init(); // Inicializa OpenGL
	glutDisplayFunc(display); // Registra la funci�n de renderizado
	glutMainLoop(); // Bucle principal de GLUT
	return 0;
}
