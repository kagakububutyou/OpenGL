#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#pragma comment(lib,"winmm.lib")

#include <windows.h>
#include <mmsystem.h>
#include <freeglut.h>
//	↑OpenGL使うときに使う？
#include <stdio.h>
#include <iostream>

//	自分で作ったヘッダーファイル
#include "Color.h"	//	色
#include "Figure.h"	//	図形描画
#include "Window.h"	//	ウインドウの生成
#include "Font.h"	//	文字描画

int x = 100;
int y = 100;

void idle(void)
{
	JOYINFOEX JOYPAD;

	JOYPAD.dwSize = sizeof(JOYINFOEX);
	JOYPAD.dwFlags = JOY_RETURNALL; // 全ての情報を取得

	if(joyGetPosEx(JOYSTICKID1, &JOYPAD) == JOYERR_NOERROR)
	{	
		// 成功
		if(JOYPAD.dwXpos > 0x7FFF + 0x4000) x+=2;
		if(JOYPAD.dwXpos < 0x7FFF - 0x4000) x-=2;
		if(JOYPAD.dwYpos > 0x7FFF + 0x4000) y+=2;
		if(JOYPAD.dwYpos < 0x7FFF - 0x4000) y-=2;

		//ボタン32個まで 空制御 コピペ用
		//if(JOYPAD.dwButtons & JOY_BUTTON1);
		//if(JOYPAD.dwButtons & JOY_BUTTON2);
	}
	Sleep(1);
	glutPostRedisplay();
}
void display(void)
{
	/*
		画面が初期化した時に
		何も無いところの
		ウインドウを塗りつぶす
	*/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT);


	//	十字に線を引く
	LINE Line(-WINDOW::Width, 0, WINDOW::Width, 0);
	Line.Draw(Color(1,0,0,1));
	LINE line( 0, WINDOW::Height, 0, -WINDOW::Height);
	line.Draw(Color(1,0,0,1));
	
	//	四角を表示
	BOX Box(x,y, x-200, y-200);
	Box.Draw(Color(0,1,0,1),true);

	CIRCLE Circle(0, 0, 100);
	Circle.Draw(Color(0,0,1,1),false);

	//	点の描画
	PIXEL Pixle(0, 0);
	Pixle.Draw(Color(0, 0, 1, 1));

	//	文字列描画
	FONT Font(24);
	Font.Draw(0,-13,L"←ここが中心",Color(0, 0, 1, 1));

	/*
		↓実行していない命令を
		全部実行する命令
		描画の終了時に書く
	*/
	glFlush();
}
void init(void)
{
	/*
		↓ウインドウの塗りつぶしの時の
		RGB(赤、緑、青)0～1の間
		第4引数はアルファ値透過度を指す
		背景色を変更しないのであれば
		最初に一度だけ設定すれば大丈夫
	*/	
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char *argv[])
{
	//	↓初期化して
	glutInit(&argc, argv);
	
	//	ウインドウの生成
	WINDOW Window(0, 0, WINDOW::Width, WINDOW::Height);
	Window.Init();

	init();

	//	↓そのウインドウ内に絵を描く関数を決めて
	glutDisplayFunc(display);

	//	↓コントローラー
	glutIdleFunc(idle);

	//	↓何かことが起こるのを待つ
	glutMainLoop();

	return 0;
}