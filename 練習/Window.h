#pragma once


//	ウインドウの生成に関するクラス
class WINDOW
{
public:

	WINDOW(float x, float y, float width, float height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height=height;
	}
	~WINDOW(){}

	void Init()
	{
		//	ウインドウの生成する座標
		glutInitWindowPosition(x, y);

		//	生成したウインドウの大きさ
		glutInitWindowSize(width, height);

		//	↓ウインドウの表示モードの設定
		//	INDEXモードっていうのもあるらしい
		glutInitDisplayMode(GLUT_RGBA);

		//	↓ウインドウを開く
		glutCreateWindow("OpenGL練習");

		//	ウインドウ全体をビューポートにする
		glViewport(0, 0, width, height);

		//	変換行列の初期化
		glLoadIdentity();

		//	スクリーン上の表示領域をビューポートの大きさに比例させる
		glOrtho(-width, width, -height, height, -1.0, 1.0);
	}


	
	static const int Width = 640;	//	画面の幅
	static const int Height = 480;	//	画面の高さ

	
private:
	
	float x, y, width, height;


};