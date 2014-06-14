#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <freeglut.h>
//	��OpenGL�g���Ƃ��Ɏg���H
#include <stdio.h>


//	�����ō�����w�b�_�[�t�@�C��
#include "Figure.h"	//	�}�`�`��
#include "Window.h"	//	�E�C���h�E�̐���
#include "Font.h"	//	�����`��

FONT *font;


void display(void)
{
	/*
		��ʂ���������������
		���������Ƃ����
		�E�C���h�E��h��Ԃ�
	*/
	glClear(GL_COLOR_BUFFER_BIT);


	//	�\���ɐ�������
	LINE Line(-WINDOW::Width, 0, WINDOW::Width, 0);
	Line.Draw(Color(1,0,0,1));
	LINE line( 0, WINDOW::Height, 0, -WINDOW::Height);
	line.Draw(Color(1,0,0,1));
	
	//	�l�p��\��
	BOX Box(100,100, -100, -100);
	Box.Draw(Color(0,1,0,1),true);

	//	�_�̕`��
	PIXEL Pixle(0, 0);
	Pixle.Draw(Color(0, 0, 1, 1));


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	font->Draw(10,120,L"����ɂ��� OpenGL�̐��E!!");
	glutSwapBuffers();

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

	font = new FONT(L"�l�r����", 24);
}

int main(int argc, char *argv[])
{
	//	������������
	glutInit(&argc, argv);
	
	//	�E�C���h�E�̐���
	WINDOW Window(0, 0, WINDOW::Width, WINDOW::Height);
	Window.Init();

	init();

	//	�����̃E�C���h�E���ɊG��`���֐������߂�
	glutDisplayFunc(display);

	//	���������Ƃ��N����̂�҂�
	glutMainLoop();

	return 0;
}