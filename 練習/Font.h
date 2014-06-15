#pragma once




//	������`�悷��N���X
class FONT
{
private:
	
	HFONT Hfont;
	HDC Hdc;

	float size;

public:
	FONT(float _size, wchar_t *_fontname = L"�l�r �o�S�V�b�N")
	{
		Hfont = CreateFont
		(
			_size,						//	�t�H���g�̍���
			0,							//	������
			0,							//	�e�L�X�g�̊p�x
			0,							//	�x�[�X���C����x���Ƃ̊p�x
			FW_REGULAR,					//	�t�H���g�̑���
			FALSE,						//	�C�^���b�N��
			FALSE,						//	�A���_�[���C��
			FALSE,						//	�ł�������
			SHIFTJIS_CHARSET,			//	�����Z�b�g
			OUT_DEFAULT_PRECIS,			//	�o�͐��x
			CLIP_DEFAULT_PRECIS,		//	�N���b�s���O���x
			ANTIALIASED_QUALITY,		//	�o�͕i��
			FIXED_PITCH | FF_MODERN,	//	�s�b�`�ƃt�@�~���[
			_fontname					//	���̖�
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

		//������ϊ�
		va_start(ap, _format);
		vswprintf_s(buf, _format, ap);
		va_end(ap);

		//	�F
		glColor4f(color.r, color.g, color.b, color.a);

		Length = wcslen(buf);
		list = glGenLists(Length);
		for(int i = 0; i < Length; i++)
		{
			wglUseFontBitmapsW(Hdc, buf[i], 1, list + (DWORD)i);
		}

		glDisable(GL_LIGHTING);
		glRasterPos2f(_x, _y);
		//	�f�B�X�v���C���X�g�ŕ`��
		for(int i = 0; i < Length; i++)
		{
			glCallList(list + i);
		}
		glEnable(GL_LIGHTING);
		//	�f�B�X�v���C���X�g�̔j��
		glDeleteLists(list, Length);
		list = 0;
		Length = 0;
	}

};

