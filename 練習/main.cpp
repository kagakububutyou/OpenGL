#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include <GL/glut.h>
//	↑OpenGL使うときに使う？

void display(void)
{

}

int main(int argc, char *argv[])
{

	//	ウインドウだけを表示
	//	↓初期化して
	glutInit(&argc, argv);
	//	↓ウインドウを開く
	glutCreateWindow(argv[0]);
	//	↓そのウインドウ内に絵を描く関数を決めて
	glutDisplayFunc(display);
	//	↓何かことが起こるのを待つ
	glutMainLoop();

	return 0;
}