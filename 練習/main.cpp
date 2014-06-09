#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <GL/glut.h>
//	↑OpenGL使うときに使う？

void display(void)
{
	/*
		画面が初期化した時に
		何も無いところの
		ウインドウを塗りつぶす
	*/
	glClear(GL_COLOR_BUFFER_BIT);

	//	↓線の色が変わる
	glColor3d(1.0, 0.0, 0.0);

	/*
		glBegin(mode)modeで描画する
		図形のタイプを指定する

		glBegin()からglEnd()までの
		glVertex2d()を頂点に設定する
	*/
	glBegin(GL_POLYGON);
	glVertex2d(-0.9, -0.9);
	glVertex2d( 0.9, -0.9);
	glVertex2d( 0.9,  0.9);
	glVertex2d(-0.9,  0.9);
	glEnd();
	/*
		実行していない命令を
		全部実行する命令
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

	//	↓ウインドウの表示モードの設定
	//	INDEXモードっていうのもあるらしい
	glutInitDisplayMode(GLUT_RGBA);

	//	↓ウインドウを開く
	glutCreateWindow(argv[0]);

	//	↓そのウインドウ内に絵を描く関数を決めて
	glutDisplayFunc(display);


	init();

	//	↓何かことが起こるのを待つ
	glutMainLoop();

	return 0;
}