#pragma once




//	文字を描画するクラス
class FONT
{
private:
	
	HFONT Hfont;
	HDC Hdc;

	float size;

public:
	FONT(float _size, wchar_t *_fontname = L"ＭＳ Ｐゴシック")
	{
		Hfont = CreateFont
		(
			_size,						//	フォントの高さ
			0,							//	文字幅
			0,							//	テキストの角度
			0,							//	ベースラインとx軸との角度
			FW_REGULAR,					//	フォントの太さ
			FALSE,						//	イタリック体
			FALSE,						//	アンダーライン
			FALSE,						//	打ち消し線
			SHIFTJIS_CHARSET,			//	文字セット
			OUT_DEFAULT_PRECIS,			//	出力精度
			CLIP_DEFAULT_PRECIS,		//	クリッピング精度
			ANTIALIASED_QUALITY,		//	出力品質
			FIXED_PITCH | FF_MODERN,	//	ピッチとファミリー
			_fontname					//	書体名
		);
		Hdc = wglGetCurrentDC();
		SelectObject(Hdc, Hfont);
	}
	~FONT(){}

	void Draw(float _x, float _y, wchar_t *_format, Color &color)
	{
		wchar_t buf[256];
		va_list ap;
		int Length = 0;
		int list = 0;

		if(_format == NULL) return;

		//文字列変換
		va_start(ap, _format);
		vswprintf_s(buf, _format, ap);
		va_end(ap);

		//	色
		glColor4f(color.r, color.g, color.b, color.a);

		Length = wcslen(buf);
		list = glGenLists(Length);
		for(int i = 0; i < Length; i++)
		{
			wglUseFontBitmapsW(Hdc, buf[i], 1, list + (DWORD)i);
		}

		glDisable(GL_LIGHTING);
		glRasterPos2f(_x, _y);
		//	ディスプレイリストで描画
		for(int i = 0; i < Length; i++)
		{
			glCallList(list + i);
		}
		glEnable(GL_LIGHTING);
		//	ディスプレイリストの破棄
		glDeleteLists(list, Length);
		list = 0;
		Length = 0;
	}

};

