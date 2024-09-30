#include <GL/glut.h>

// Ball properties
float ballRadius = 0.5f;
float ballX = 0.0f, ballY = 0.0f, ballZ = 0.0f;
float xSpeed = 0.02f, ySpeed = 0.007f, zSpeed = 0.02f;

// Box boundaries
float boxXMin = -1.0f, boxXMax = 1.0f;
float boxYMin = -1.0f, boxYMax = 1.0f;
float boxZMin = -1.0f, boxZMax = 1.0f;

// Initialize OpenGL
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);               // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);                // Set the type of depth-test
    glShadeModel(GL_SMOOTH);               // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

// Function to handle rendering the ball and box
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
    glLoadIdentity();               // Reset the model-view matrix

    // Draw box (cube)
    glBegin(GL_LINE_LOOP); // Front face
    glVertex3f(boxXMin, boxYMin, boxZMax);
    glVertex3f(boxXMax, boxYMin, boxZMax);
    glVertex3f(boxXMax, boxYMax, boxZMax);
    glVertex3f(boxXMin, boxYMax, boxZMax);
    glEnd();

    glBegin(GL_LINE_LOOP); // Back face
    glVertex3f(boxXMin, boxYMin, boxZMin);
    glVertex3f(boxXMax, boxYMin, boxZMin);
    glVertex3f(boxXMax, boxYMax, boxZMin);
    glVertex3f(boxXMin, boxYMax, boxZMin);
    glEnd();

    glBegin(GL_LINES); // Connect edges
    glVertex3f(boxXMin, boxYMin, boxZMax);
    glVertex3f(boxXMin, boxYMin, boxZMin);
    glVertex3f(boxXMax, boxYMin, boxZMax);
    glVertex3f(boxXMax, boxYMin, boxZMin);
    glVertex3f(boxXMax, boxYMax, boxZMax);
    glVertex3f(boxXMax, boxYMax, boxZMin);
    glVertex3f(boxXMin, boxYMax, boxZMax);
    glVertex3f(boxXMin, boxYMax, boxZMin);
    glEnd();

    // Draw ball
    glTranslatef(ballX, ballY, ballZ);  // Translate ball to its position
    glColor3f(1.0f, 0.0f, 0.0f);       // Red ball
    glutSolidSphere(ballRadius, 20, 20);

    glutSwapBuffers();  // Swap front and back buffers (double buffering)
}

// Update ball position
void update(int value) {
    // Update ball position
    ballX += xSpeed;
    ballY += ySpeed;
    ballZ += zSpeed;

    // Check for collision with the box and reverse the velocity if needed
    if (ballX + ballRadius > boxXMax || ballX - ballRadius < boxXMin) {
        xSpeed = -xSpeed; // Reverse direction
    }
    if (ballY + ballRadius > boxYMax || ballY - ballRadius < boxYMin) {
        ySpeed = -ySpeed; // Reverse direction
    }
    if (ballZ + ballRadius > boxZMax || ballZ - ballRadius < boxZMin) {
        zSpeed = -zSpeed; // Reverse direction
    }

    glutPostRedisplay();  // Redisplay the scene
    glutTimerFunc(16, update, 0); // 16 ms for roughly 60 frames per second
}

// Handle window resize
void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;  // Prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("3D Bounce Ball Game"); // Create window with the given title

    glutDisplayFunc(display); // Register callback handler for window re-paint event
    glutReshapeFunc(reshape); // Register callback handler for window resize event
    glutTimerFunc(0, update, 0); // First timer call immediately

    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
