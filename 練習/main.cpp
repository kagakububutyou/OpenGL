#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <GL/glut.h>
//	��OpenGL�g���Ƃ��Ɏg���H

void display(void)
{
	/*
		��ʂ���������������
		�����\�����Ȃ�����
		�E�C���h�E��h��Ԃ�
	*/
	glClear(GL_COLOR_BUFFER_BIT);

	/*
		���s���Ă��Ȃ����߂�
		�S�����s���閽��
	*/
	glFlush();
}

void init(void)
{
	/*
		���E�C���h�E�̓h��Ԃ��̎���
		RGB(�ԁA�΁A��)0�`1�̊�
		��4�����̓A���t�@�l���ߓx���w��
		�w�i�F��ύX���Ȃ��̂ł����
		�ŏ��Ɉ�x�����ݒ肷��Α��v
	*/	
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char *argv[])
{

	//	�E�C���h�E������\��

	//	������������
	glutInit(&argc, argv);

	//	���E�C���h�E�̕\�����[�h�̐ݒ�
	//	INDEX���[�h���Ă����̂�����炵��
	glutInitDisplayMode(GLUT_RGBA);

	//	���E�C���h�E���J��
	glutCreateWindow(argv[0]);

	//	�����̃E�C���h�E���ɊG��`���֐������߂�
	glutDisplayFunc(display);


	init();

	//	���������Ƃ��N����̂�҂�
	glutMainLoop();

	return 0;
}