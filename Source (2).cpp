#include<windows.h>
#include<glut.h>

GLfloat x = 0;
//Materail-Chrome
GLfloat mat_ambient[] = { 0.25f, 0.25f, 0.25f, 1.0f };
GLfloat mat_diffuse[] = { 0.4f, 0.4f, 0.4f, 1.0f };
GLfloat mat_specular[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
GLfloat shine = 76.8f;
GLfloat position[] = { 200.0f, 300.0f, 100.0f, 0.0f };
float angle = 0.0f;
float anglex = 0.0f;
float angleX = 0.0f, angleY = 0.0f, angleZ = 0.0f;
int axis = 1; // Default axis set to y-axis for initial rotation

void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 0, 150, 0, 0, 0, 0, 1, 0);
    // Set background color to blue
    glClearColor(0.0f, 0.0f, 0.5f, 1.0f); // dark blue color


    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);


    gluLookAt(0, 0, 150, 0, 0, 0, 0, 1, 0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
    glLightfv(GL_LIGHT0, GL_POSITION, position);



    // Apply rotation based on the selected axis
   
    glRotatef(angleZ, 0, 0, 1);
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);


    glRotatef(angle, 0, 1, 0);
    //First Object the body
    glPushMatrix();
    glColor3ub(192, 192, 192);// sliver
    glScaled(1.1, 0.7, 1);
    glTranslated(0, 10, 0);
    glutSolidSphere(40, 20, 60);
    glPopMatrix();
    // Object the circyle in the body
    glPushMatrix();
    glColor3ub(173, 216, 230); //lightblue
    glTranslated(0, 30, 0);
    glScaled(2, 1.1, 1);
    glutSolidSphere(10, 20, 60);
    glPopMatrix();
    //Second Object the outer ring
    glPushMatrix();
    glColor3ub(255, 21, 146);//pink
    glRotated(80, 1, 0, 0);
    glTranslated(0, 6, -1);
    glutSolidTorus(3, 45, 30, 30);
    glPopMatrix();
    //third Object outer ring
    glPushMatrix();
    glColor3ub(255, 255, 153);// yellow
    glRotated(80, 1, 0, 0);
    glTranslated(0, 6, 5);
    glutSolidTorus(3, 45, 30, 30);
    glPopMatrix();
    //fourth Object  outer ring last one
    glPushMatrix();
    glColor3ub(48, 142, 255); // blue
    glRotated(80, 1, 0, 0);
    glTranslated(0, 6, 7);
    glutSolidTorus(3, 40, 30, 30);
    glPopMatrix();
    //five Object  right tires
    glPushMatrix();
    glColor3ub(48, 142, 255); // blue
    glTranslated(20, -20, -1);
    glutSolidSphere(4, 20, 60);
    glPopMatrix();
    //six Object  left tires
    glPushMatrix();
    glColor3ub(48, 142, 255); // blue
    glTranslated(-20, -20, -1);
    glutSolidSphere(4, 20, 60);
    glPopMatrix();
    //seven Object  intel
    glPushMatrix();
    glColor3ub(48, 142, 255); // blue
    glRotated(80, 0, 1, 0);
    glScaled(1, 0.5, 1);
    glTranslated(1, 85, -1);
    glutSolidSphere(3, 20, 60);
    glPopMatrix();
    //eight Object  the inside side window
    glPushMatrix();
    glColor3ub(173, 216, 146); //lightblue
    glTranslated(1, 15, 39);
    glScaled(1, 1, 0.5);
    glutSolidSphere(6, 20, 60);
    glPopMatrix();
    //nine Object  the outer window
    glPushMatrix();
    glColor3ub(169, 169, 169); // darkgrey
    glTranslated(1, 15, 39);
    glutSolidTorus(1.1, 6, 50, 50);
    glPopMatrix();
    x += 0.1;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutSwapBuffers();
}

void update(int value) {
    if (axis == 0) {
        angleX += anglex;
        if (angleX > 360) angleX -= 360;
    }
    else if (axis == 1) {
        angleY += anglex;
        if (angleY > 360) angleY -= 360;
    }
    else if (axis == 2) {
        angleZ += anglex;
        if (angleZ > 360) angleZ -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Re-register the update function every 16 milliseconds
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1': anglex = 1.0f; break;
    case '2': anglex = 2.0f; break;
    case '3': anglex = 3.0f; break;
    case '4': anglex = 4.0f; break;
    case '5': anglex = 5.0f; break;
    case '6': anglex = 6.0f; break;
    case '7': anglex = 7.0f; break;
    case '8': anglex = 8.0f; break;
    case '9': anglex = 9.0f; break;
    case '0': anglex = 0.0f; break;
    case 'x':
    case 'X': axis = 0; break; // X-axis
    case 'y':
    case 'Y': axis = 1; break; // Y-axis
    case 'z':
    case 'Z': axis = 2; break;
    }
}
int main() {
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("SpaceShip");
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 80, -100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1, 1, 1, 1);
    glutDisplayFunc(draw);
    glutIdleFunc(draw);
    glutKeyboardFunc(keyboard);
    update(0);
    glutMainLoop();
}