#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <GL/glut.h>
//	↑OpenGL使うときに使う？

//	自分で作ったヘッダーファイル
#include "Figure.h"

void display(void)
{
	/*
		画面が初期化した時に
		何も無いところの
		ウインドウを塗りつぶす
	*/
	glClear(GL_COLOR_BUFFER_BIT);


	//	↓直線のクラス化
	LINE Line(-1, 0, 1, 0);
	Line.Draw(Color(1,0,0,1));
	LINE line( 0, 1, 0, -1);
	line.Draw(Color(1,0,0,1));
	
	
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

	//	ウインドウの生成する座標
	glutInitWindowPosition(0, 0);
	//	生成したウインドウの大きさ
	glutInitWindowSize(640, 480);

	//	↓ウインドウの表示モードの設定
	//	INDEXモードっていうのもあるらしい
	glutInitDisplayMode(GLUT_RGBA);

	//	↓ウインドウを開く
	glutCreateWindow(argv[0]);

	//	ウインドウ全体をビューポートにする
	glViewport(0, 0, 640, 480);

	//	変換行列の初期化
	glLoadIdentity();

	//	スクリーン上の表示領域をビューポートの大きさに比例させる
	glOrtho(-640,640, -480, 480, -1.0, 1.0);



	init();

	//	↓そのウインドウ内に絵を描く関数を決めて
	glutDisplayFunc(display);

	//display();

	//	↓何かことが起こるのを待つ
	glutMainLoop();

	return 0;
}