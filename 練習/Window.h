#pragma once


//	�E�C���h�E�̐����Ɋւ���N���X
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
		//	�E�C���h�E�̐���������W
		glutInitWindowPosition(x, y);

		//	���������E�C���h�E�̑傫��
		glutInitWindowSize(width, height);

		//	���E�C���h�E�̕\�����[�h�̐ݒ�
		//	INDEX���[�h���Ă����̂�����炵��
		glutInitDisplayMode(GLUT_RGBA);

		//	���E�C���h�E���J��
		glutCreateWindow("OpenGL���K");

		//	�E�C���h�E�S�̂��r���[�|�[�g�ɂ���
		glViewport(0, 0, width, height);

		//	�ϊ��s��̏�����
		glLoadIdentity();

		//	�X�N���[����̕\���̈���r���[�|�[�g�̑傫���ɔ�Ⴓ����
		glOrtho(-width, width, -height, height, -1.0, 1.0);
	}


	
	static const int Width = 640;	//	��ʂ̕�
	static const int Height = 480;	//	��ʂ̍���

	
private:
	
	float x, y, width, height;


};