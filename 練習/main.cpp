#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <GL/glut.h>
//	��OpenGL�g���Ƃ��Ɏg���H

void display(void)
{

}

int main(int argc, char *argv[])
{

	//	�E�C���h�E������\��
	//	������������
	glutInit(&argc, argv);
	//	���E�C���h�E���J��
	glutCreateWindow(argv[0]);
	//	�����̃E�C���h�E���ɊG��`���֐������߂�
	glutDisplayFunc(display);
	//	���������Ƃ��N����̂�҂�
	glutMainLoop();

	return 0;
}