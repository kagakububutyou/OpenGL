#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <GL/glut.h>
//	↑OpenGL使うときに使う？

//	自分で作ったヘッダーファイル
#include "Figure.h"
#include "Window.h"

void display(void)
{
	/*
		画面が初期化した時に
		何も無いところの
		ウインドウを塗りつぶす
	*/
	glClear(GL_COLOR_BUFFER_BIT);


	//	十字に線を引く
	LINE Line(-WINDOW::Width, 0, WINDOW::Width, 0);
	Line.Draw(Color(1,0,0,1));
	LINE line( 0, WINDOW::Height, 0, -WINDOW::Height);
	line.Draw(Color(1,0,0,1));
	
	//	四角を表示
	BOX Box(100,100, -100, -100);
	Box.Draw(Color(0,1,0,1),true);

	//	三角形の描画
	TRIANGLE Triangle(100, 0, 0, 100, 0, -100);
	Triangle.Draw(Color(0, 0, 1, 1),false);

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

	//	↓何かことが起こるのを待つ
	glutMainLoop();

	return 0;
}