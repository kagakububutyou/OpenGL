#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#pragma comment(lib,"winmm.lib")

#include <windows.h>
#include <mmsystem.h>
#include <freeglut.h>
//	��OpenGL�g���Ƃ��Ɏg���H
#include <stdio.h>
#include <iostream>

//	�����ō�����w�b�_�[�t�@�C��
#include "Color.h"	//	�F
#include "Figure.h"	//	�}�`�`��
#include "Window.h"	//	�E�C���h�E�̐���
#include "Font.h"	//	�����`��

int x = 100;
int y = 100;

void idle(void)
{
	JOYINFOEX JOYPAD;

	JOYPAD.dwSize = sizeof(JOYINFOEX);
	JOYPAD.dwFlags = JOY_RETURNALL; // �S�Ă̏����擾

	if(joyGetPosEx(JOYSTICKID1, &JOYPAD) == JOYERR_NOERROR)
	{	
		// ����
		if(JOYPAD.dwXpos > 0x7FFF + 0x4000) x+=2;
		if(JOYPAD.dwXpos < 0x7FFF - 0x4000) x-=2;
		if(JOYPAD.dwYpos > 0x7FFF + 0x4000) y+=2;
		if(JOYPAD.dwYpos < 0x7FFF - 0x4000) y-=2;

		//�{�^��32�܂� �󐧌� �R�s�y�p
		//if(JOYPAD.dwButtons & JOY_BUTTON1);
		//if(JOYPAD.dwButtons & JOY_BUTTON2);
	}
	Sleep(1);
	glutPostRedisplay();
}
void display(void)
{
	/*
		��ʂ���������������
		���������Ƃ����
		�E�C���h�E��h��Ԃ�
	*/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT);


	//	�\���ɐ�������
	LINE Line(-WINDOW::Width, 0, WINDOW::Width, 0);
	Line.Draw(Color(1,0,0,1));
	LINE line( 0, WINDOW::Height, 0, -WINDOW::Height);
	line.Draw(Color(1,0,0,1));
	
	//	�l�p��\��
	BOX Box(x,y, x-200, y-200);
	Box.Draw(Color(0,1,0,1),true);

	CIRCLE Circle(0, 0, 100);
	Circle.Draw(Color(0,0,1,1),false);

	//	�_�̕`��
	PIXEL Pixle(0, 0);
	Pixle.Draw(Color(0, 0, 1, 1));

	//	������`��
	FONT Font(24);
	Font.Draw(0,-13,L"�����������S",Color(0, 0, 1, 1));

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
	
	//	�E�C���h�E�̐���
	WINDOW Window(0, 0, WINDOW::Width, WINDOW::Height);
	Window.Init();

	init();

	//	�����̃E�C���h�E���ɊG��`���֐������߂�
	glutDisplayFunc(display);

	//	���R���g���[���[
	glutIdleFunc(idle);

	//	���������Ƃ��N����̂�҂�
	glutMainLoop();

	return 0;
}