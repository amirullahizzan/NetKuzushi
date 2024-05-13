#pragma once

// �p�b�h���
enum PAD_NO {
	PAD_NO1 = 0,		// �R���g���[��1
	PAD_NO2,
	PAD_NO3,
	PAD_NO4,

	PAD_NO_MAX
};

enum PAD_ID {
	PAD_UP = 0,
	PAD_DOWN,
	PAD_LEFT,
	PAD_RIGHT,

	PAD_A,	PAD_B,	PAD_C,	PAD_X,
	PAD_Y,	PAD_Z,	PAD_L,	PAD_R,
	PAD_START, PAD_M,

	PAD_ID_MAX
};

enum PAD_ID_PLAYSTATION {
	PS_SQUARE = 4, PS_CROSS, PS_CIRCLE, PS_TRIANGLE,
	PS_L1, PS_R1, PS_L2, PS_R2,
	PS_START, PS_SELECT,

	PS_ID_MAX
};

void PadInputInit();	// ������
void PadInputUpdate();	// �X�V
void PadInputExit();	// �I��

bool IsPadOn(int pad_id, PAD_NO pad_no = PAD_NO1);		// 1�񂾂�
bool IsPadRelease(int pad_id, PAD_NO pad_no = PAD_NO1);	// ���
bool IsPadRepeat(int pad_id, PAD_NO pad_no = PAD_NO1);	// �A��