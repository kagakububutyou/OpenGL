#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <GL/glut.h>
//	��OpenGL�g���Ƃ��Ɏg���H

void display(void)
{
	/*
		��ʂ���������������
		���������Ƃ����
		�E�C���h�E��h��Ԃ�
	*/
	glClear(GL_COLOR_BUFFER_BIT);

	//	�����̐F���ς��
	glColor3d(1.0, 0.0, 0.0);

	/*
		glBegin(mode)mode�ŕ`�悷��
		�}�`�̃^�C�v���w�肷��

		glBegin()����glEnd()�܂ł�
		glVertex2d()�𒸓_�ɐݒ肷��
	*/
	glBegin(GL_POLYGON);
	glVertex2d(-0.9, -0.9);
	glVertex2d( 0.9, -0.9);
	glVertex2d( 0.9,  0.9);
	glVertex2d(-0.9,  0.9);
	glEnd();
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
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char *argv[])
{
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