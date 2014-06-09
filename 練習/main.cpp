#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <GL/glut.h>
//	��OpenGL�g���Ƃ��Ɏg���H

//	�����ō�����w�b�_�[�t�@�C��
#include "Figure.h"

void display(void)
{
	/*
		��ʂ���������������
		���������Ƃ����
		�E�C���h�E��h��Ԃ�
	*/
	glClear(GL_COLOR_BUFFER_BIT);


	//	�������̃N���X��
	LINE Line(-1, 0, 1, 0);
	Line.Draw(Color(1,0,0,1));
	LINE line( 0, 1, 0, -1);
	line.Draw(Color(1,0,0,1));
	
	
	/*
		�����s���Ă��Ȃ����߂�
		�S�����s���閽��
		�`��̏I�����ɏ���
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
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char *argv[])
{
	//	������������
	glutInit(&argc, argv);

	//	�E�C���h�E�̐���������W
	glutInitWindowPosition(0, 0);
	//	���������E�C���h�E�̑傫��
	glutInitWindowSize(640, 480);

	//	���E�C���h�E�̕\�����[�h�̐ݒ�
	//	INDEX���[�h���Ă����̂�����炵��
	glutInitDisplayMode(GLUT_RGBA);

	//	���E�C���h�E���J��
	glutCreateWindow(argv[0]);

	//	�E�C���h�E�S�̂��r���[�|�[�g�ɂ���
	glViewport(0, 0, 640, 480);

	//	�ϊ��s��̏�����
	glLoadIdentity();

	//	�X�N���[����̕\���̈���r���[�|�[�g�̑傫���ɔ�Ⴓ����
	glOrtho(-640,640, -480, 480, -1.0, 1.0);



	init();

	//	�����̃E�C���h�E���ɊG��`���֐������߂�
	glutDisplayFunc(display);

	//display();

	//	���������Ƃ��N����̂�҂�
	glutMainLoop();

	return 0;
}