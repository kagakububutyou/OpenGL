#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <GL/glut.h>
//	��OpenGL�g���Ƃ��Ɏg���H

void display(void)
{

}

int main(int argc, char *argv[])
{

	//	�E�C���h�E������\��
	glutInit(&argc, argv);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}