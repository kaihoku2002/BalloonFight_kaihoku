/**
 * �����ł��ꂼ��̉摜��UV���W���w�肷��
 */

#pragma once

#include "stdafx.h"
#include "Common3DType.h"
 

float LeftX = 0.0f;
float RightX = 1.0f;
float OverY = 0.0f;
float DownY = 1.0f;
float UVCntX = 8.0f;
float UVCntY = 12.0f;

//�u���b�N�i���j
const std::vector <QuadrangleTexel>  kTexelBlockBers = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 3.0f, 1.0f / 1.0f},  {0.0f / 3.0f, 0.0f / 1.0f}, {1.0f / 3.0f, 1.0f / 1.0f}, {1.0f / 3.0, 0.0f / 1.0f}},//�n��
	{{1.0f / 3.0f, 1.0f / 1.0f},  {1.0f / 3.0f, 0.0f / 1.0f}, {2.0f / 3.0f, 1.0f / 1.0f}, {2.0f / 3.0, 0.0f / 1.0f}},//���i�����j
	{{2.0f / 3.0f, 1.0f / 1.0f},  {2.0f / 3.0f, 0.0f / 1.0f}, {3.0f / 3.0f, 1.0f / 1.0f}, {3.0f / 3.0, 0.0f / 1.0f}},//���i��j
};

//�p�C�v�i�{�[�i�X�X�e�[�W�j
const std::vector <QuadrangleTexel>  kTexelBPipes = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 2.0f, 1.0f / 1.0f},  {0.0f / 2.0f, 0.0f / 1.0f}, {1.0f / 2.0f, 1.0f / 1.0f}, {1.0f / 2.0, 0.0f / 1.0f}},//�n��
	{{1.0f / 2.0f, 1.0f / 1.0f},  {1.0f / 2.0f, 0.0f / 1.0f}, {2.0f / 2.0f, 1.0f / 1.0f}, {2.0f / 2.0, 0.0f / 1.0f}},//���i�����j
};

//�p�C�v�i�{�[�i�X�X�e�[�W�j
const std::vector <QuadrangleTexel>  kTexeltitleballoons = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 4.0f, 1.0f / 1.0f},  {0.0f / 4.0f, 0.0f / 1.0f}, {1.0f / 4.0f, 1.0f / 1.0f}, {1.0f / 4.0, 0.0f / 1.0f}},//�n��
	{{1.0f / 4.0f, 1.0f / 1.0f},  {1.0f / 4.0f, 0.0f / 1.0f}, {2.0f / 4.0f, 1.0f / 1.0f}, {2.0f / 4.0, 0.0f / 1.0f}},//���i�����j
	{{2.0f / 4.0f, 1.0f / 1.0f},  {2.0f / 4.0f, 0.0f / 1.0f}, {3.0f / 4.0f, 1.0f / 1.0f}, {3.0f / 4.0, 0.0f / 1.0f}},//�n��
	{{3.0f / 4.0f, 1.0f / 1.0f},  {3.0f / 4.0f, 0.0f / 1.0f}, {4.0f / 4.0f, 1.0f / 1.0f}, {4.0f / 4.0, 0.0f / 1.0f}},//���i�����j
};

//�v���C���[�̉摜��UV���W
const std::vector <QuadrangleTexel>  kTexelPlayers = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 8.0f, 1.0f / 5.0f},  {0.0f / 8.0f, 0.0f / 5.0f}, {1.0f / 8.0f, 1.0f / 5.0f}, {1.0f / 8.0, 0.0f / 5.0f}},//���D�Q���s1(1)
	{{1.0f / 8.0f, 1.0f / 5.0f},  {1.0f / 8.0f, 0.0f / 5.0f}, {2.0f / 8.0f, 1.0f / 5.0f}, {2.0f / 8.0, 0.0f / 5.0f}},//���D�Q���s2(2)
	{{2.0f / 8.0f, 1.0f / 5.0f},  {2.0f / 8.0f, 0.0f / 5.0f}, {3.0f / 8.0f, 1.0f / 5.0f}, {3.0f / 8.0, 0.0f / 5.0f}},//���D�Q���s3(3)
	{{3.0f / 8.0f, 1.0f / 5.0f},  {3.0f / 8.0f, 0.0f / 5.0f}, {4.0f / 8.0f, 1.0f / 5.0f}, {4.0f / 8.0, 0.0f / 5.0f}},//���D�Q���s4(4)
	{{4.0f / 8.0f, 1.0f / 5.0f},  {4.0f / 8.0f, 0.0f / 5.0f}, {5.0f / 8.0f, 1.0f / 5.0f}, {5.0f / 8.0, 0.0f / 5.0f}},//���D�Q���s5(5)
	{{5.0f / 8.0f, 1.0f / 5.0f},  {5.0f / 8.0f, 0.0f / 5.0f}, {6.0f / 8.0f, 1.0f / 5.0f}, {6.0f / 8.0, 0.0f / 5.0f}},//���D�Q���s6(6)
	{{6.0f / 8.0f, 1.0f / 5.0f},  {6.0f / 8.0f, 0.0f / 5.0f}, {7.0f / 8.0f, 1.0f / 5.0f}, {7.0f / 8.0, 0.0f / 5.0f}},//���D�Q���s7(7)
	{{7.0f / 8.0f, 1.0f / 5.0f},  {7.0f / 8.0f, 0.0f / 5.0f}, {8.0f / 8.0f, 1.0f / 5.0f}, {8.0f / 8.0, 0.0f / 5.0f}},//���D�Q���s8(8)

	{{0.0f / 8.0f, 2.0f / 5.0f},  {0.0f / 8.0f, 1.0f / 5.0f}, {1.0f / 8.0f, 2.0f / 5.0f}, {1.0f / 8.0, 1.0f / 5.0f}},//���D�P���s1(9)
	{{1.0f / 8.0f, 2.0f / 5.0f},  {1.0f / 8.0f, 1.0f / 5.0f}, {2.0f / 8.0f, 2.0f / 5.0f}, {2.0f / 8.0, 1.0f / 5.0f}},//���D�P���s2(10)
	{{2.0f / 8.0f, 2.0f / 5.0f},  {2.0f / 8.0f, 1.0f / 5.0f}, {3.0f / 8.0f, 2.0f / 5.0f}, {3.0f / 8.0, 1.0f / 5.0f}},//���D�P���s3(11)
	{{3.0f / 8.0f, 2.0f / 5.0f},  {3.0f / 8.0f, 1.0f / 5.0f}, {4.0f / 8.0f, 2.0f / 5.0f}, {4.0f / 8.0, 1.0f / 5.0f}},//���D�P���s4(12)
	{{4.0f / 8.0f, 2.0f / 5.0f},  {4.0f / 8.0f, 1.0f / 5.0f}, {5.0f / 8.0f, 2.0f / 5.0f}, {5.0f / 8.0, 1.0f / 5.0f}},//���D�P���s5(13)
	{{5.0f / 8.0f, 2.0f / 5.0f},  {5.0f / 8.0f, 1.0f / 5.0f}, {6.0f / 8.0f, 2.0f / 5.0f}, {6.0f / 8.0, 1.0f / 5.0f}},//���D�P���s6(14)
	{{6.0f / 8.0f, 2.0f / 5.0f},  {6.0f / 8.0f, 1.0f / 5.0f}, {7.0f / 8.0f, 2.0f / 5.0f}, {7.0f / 8.0, 1.0f / 5.0f}},//���D�P���s7(15)

	{{0.0f / 8.0f, 3.0f / 5.0f},  {0.0f / 8.0f, 2.0f / 5.0f}, {1.0f / 8.0f, 3.0f / 5.0f}, {1.0f / 8.0, 2.0f / 5.0f}},//���D�Q��s1(16)
	{{1.0f / 8.0f, 3.0f / 5.0f},  {1.0f / 8.0f, 2.0f / 5.0f}, {2.0f / 8.0f, 3.0f / 5.0f}, {2.0f / 8.0, 2.0f / 5.0f}},//���D�Q��s2(17)
	{{2.0f / 8.0f, 3.0f / 5.0f},  {2.0f / 8.0f, 2.0f / 5.0f}, {3.0f / 8.0f, 3.0f / 5.0f}, {3.0f / 8.0, 2.0f / 5.0f}},//���D�Q��s3(18)
	{{3.0f / 8.0f, 3.0f / 5.0f},  {3.0f / 8.0f, 2.0f / 5.0f}, {4.0f / 8.0f, 3.0f / 5.0f}, {4.0f / 8.0, 2.0f / 5.0f}},//���D�Q��s4(19)
	{{4.0f / 8.0f, 3.0f / 5.0f},  {4.0f / 8.0f, 2.0f / 5.0f}, {5.0f / 8.0f, 3.0f / 5.0f}, {5.0f / 8.0, 2.0f / 5.0f}},//���D�Q��s5(20)
	{{5.0f / 8.0f, 3.0f / 5.0f},  {5.0f / 8.0f, 2.0f / 5.0f}, {6.0f / 8.0f, 3.0f / 5.0f}, {6.0f / 8.0, 2.0f / 5.0f}},//���D�Q��s6(21)

	{{0.0f / 8.0f, 4.0f / 5.0f},  {0.0f / 8.0f, 3.0f / 5.0f}, {1.0f / 8.0f, 4.0f / 5.0f}, {1.0f / 8.0, 3.0f / 5.0f}},//���D�P��s1(22)
	{{1.0f / 8.0f, 4.0f / 5.0f},  {1.0f / 8.0f, 3.0f / 5.0f}, {2.0f / 8.0f, 4.0f / 5.0f}, {2.0f / 8.0, 3.0f / 5.0f}},//���D�P��s2(23)
	{{2.0f / 8.0f, 4.0f / 5.0f},  {2.0f / 8.0f, 3.0f / 5.0f}, {3.0f / 8.0f, 4.0f / 5.0f}, {3.0f / 8.0, 3.0f / 5.0f}},//���D�P��s3(24)
	{{3.0f / 8.0f, 4.0f / 5.0f},  {3.0f / 8.0f, 3.0f / 5.0f}, {4.0f / 8.0f, 4.0f / 5.0f}, {4.0f / 8.0, 3.0f / 5.0f}},//���D�P��s4(25)
	{{4.0f / 8.0f, 4.0f / 5.0f},  {4.0f / 8.0f, 3.0f / 5.0f}, {5.0f / 8.0f, 4.0f / 5.0f}, {5.0f / 8.0, 3.0f / 5.0f}},//���D�P��s5(26)

	{{0.0f / 8.0f, 5.0f / 5.0f},  {0.0f / 8.0f, 4.0f / 5.0f}, {1.0f / 8.0f, 5.0f / 5.0f}, {1.0f / 8.0, 4.0f / 5.0f}},//���S1(27)
	{{1.0f / 8.0f, 5.0f / 5.0f},  {1.0f / 8.0f, 4.0f / 5.0f}, {2.0f / 8.0f, 5.0f / 5.0f}, {2.0f / 8.0, 4.0f / 5.0f}},//���S2(28)
	{{2.0f / 8.0f, 5.0f / 5.0f},  {2.0f / 8.0f, 4.0f / 5.0f}, {3.0f / 8.0f, 5.0f / 5.0f}, {3.0f / 8.0, 4.0f / 5.0f}},//���S3(29)
	{{3.0f / 8.0f, 5.0f / 5.0f},  {3.0f / 8.0f, 4.0f / 5.0f}, {4.0f / 8.0f, 5.0f / 5.0f}, {4.0f / 8.0, 4.0f / 5.0f}},//�r���r��(30)
};

 //�G�l�~�[�̉摜��UV���W
const std::vector <QuadrangleTexel>  kTexelEnemys = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{(LeftX = 0.0f) / UVCntX, (DownY = 1.0f) / UVCntY},  {LeftX / UVCntX, (OverY = 0.0f) / UVCntY}, {(RightX = 1.0f) / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)

	{{(LeftX = 0.0f) / UVCntX, ++DownY / UVCntY},  {LeftX / UVCntX, ++OverY / UVCntY}, {(RightX = 1.0f) / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	
	{{(LeftX = 0.0f) / UVCntX, ++DownY / UVCntY},  {LeftX / UVCntX, ++OverY / UVCntY}, {(RightX = 1.0f) / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)

	{{(LeftX = 0.0f) / UVCntX, ++DownY / UVCntY},  {LeftX / UVCntX, ++OverY / UVCntY}, {(RightX = 1.0f) / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	
	{{(LeftX = 0.0f) / UVCntX, ++DownY / UVCntY},  {LeftX / UVCntX, ++OverY / UVCntY}, {(RightX = 1.0f) / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)

	{{(LeftX = 0.0f) / UVCntX, ++DownY / UVCntY},  {LeftX / UVCntX, ++OverY / UVCntY}, {(RightX = 1.0f) / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)

	{{(LeftX = 0.0f) / UVCntX, ++DownY / UVCntY},  {LeftX / UVCntX, ++OverY / UVCntY}, {(RightX = 1.0f) / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)

	{{(LeftX = 0.0f) / UVCntX, ++DownY / UVCntY},  {LeftX / UVCntX, ++OverY / UVCntY}, {(RightX = 1.0f) / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)

	{{(LeftX = 0.0f) / UVCntX, ++DownY / UVCntY},  {LeftX / UVCntX, ++OverY / UVCntY}, {(RightX = 1.0f) / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)

	{{(LeftX = 0.0f) / UVCntX, ++DownY / UVCntY},  {LeftX / UVCntX, ++OverY / UVCntY}, {(RightX = 1.0f) / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)

	{{(LeftX = 0.0f) / UVCntX, ++DownY / UVCntY},  {LeftX / UVCntX, ++OverY / UVCntY}, {(RightX = 1.0f) / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)

	{{(LeftX = 0.0f) / UVCntX, ++DownY / UVCntY},  {LeftX / UVCntX, ++OverY / UVCntY}, {(RightX = 1.0f) / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
	{{++LeftX / UVCntX, DownY / UVCntY},  {LeftX / UVCntX, OverY / UVCntY}, {++RightX / UVCntX, DownY / UVCntY}, {RightX / UVCntX, OverY / UVCntY}},//���D�Q���s1(1)
};

//�����Ԃ�
const std::vector <QuadrangleTexel>  kTexelEnteringWaters = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 3.0f, 1.0f / 1.0f},  {0.0f / 3.0f, 0.0f / 1.0f}, {1.0f / 3.0f, 1.0f / 1.0f}, {1.0f / 3.0, 0.0f / 1.0f}},//1
	{{1.0f / 3.0f, 1.0f / 1.0f},  {1.0f / 3.0f, 0.0f / 1.0f}, {2.0f / 3.0f, 1.0f / 1.0f}, {2.0f / 3.0, 0.0f / 1.0f}},//2
	{{2.0f / 3.0f, 1.0f / 1.0f},  {2.0f / 3.0f, 0.0f / 1.0f}, {3.0f / 3.0f, 1.0f / 1.0f}, {3.0f / 3.0, 0.0f / 1.0f}},//3
};

//��
const std::vector <QuadrangleTexel>  kTexelFishs = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 9.0f, 1.0f / 2.0f},  {0.0f / 9.0f, 0.0f / 2.0f}, {1.0f / 9.0f, 1.0f / 2.0f}, {1.0f / 9.0, 0.0f / 2.0f}},//1
	{{1.0f / 9.0f, 1.0f / 2.0f},  {1.0f / 9.0f, 0.0f / 2.0f}, {2.0f / 9.0f, 1.0f / 2.0f}, {2.0f / 9.0, 0.0f / 2.0f}},//2
	{{2.0f / 9.0f, 1.0f / 2.0f},  {2.0f / 9.0f, 0.0f / 2.0f}, {3.0f / 9.0f, 1.0f / 2.0f}, {3.0f / 9.0, 0.0f / 2.0f}},//3
	{{3.0f / 9.0f, 1.0f / 2.0f},  {3.0f / 9.0f, 0.0f / 2.0f}, {4.0f / 9.0f, 1.0f / 2.0f}, {4.0f / 9.0, 0.0f / 2.0f}},//4
	{{4.0f / 9.0f, 1.0f / 2.0f},  {4.0f / 9.0f, 0.0f / 2.0f}, {5.0f / 9.0f, 1.0f / 2.0f}, {5.0f / 9.0, 0.0f / 2.0f}},//5
	{{5.0f / 9.0f, 1.0f / 2.0f},  {5.0f / 9.0f, 0.0f / 2.0f}, {6.0f / 9.0f, 1.0f / 2.0f}, {6.0f / 9.0, 0.0f / 2.0f}},//6
	{{6.0f / 9.0f, 1.0f / 2.0f},  {6.0f / 9.0f, 0.0f / 2.0f}, {7.0f / 9.0f, 1.0f / 2.0f}, {7.0f / 9.0, 0.0f / 2.0f}},//7
	{{7.0f / 9.0f, 1.0f / 2.0f},  {7.0f / 9.0f, 0.0f / 2.0f}, {8.0f / 9.0f, 1.0f / 2.0f}, {8.0f / 9.0, 0.0f / 2.0f}},//8
	{{8.0f / 9.0f, 1.0f / 2.0f},  {8.0f / 9.0f, 0.0f / 2.0f}, {9.0f / 9.0f, 1.0f / 2.0f}, {9.0f / 9.0, 0.0f / 2.0f}},//9

	{{0.0f / 9.0f, 2.0f / 2.0f},  {0.0f / 9.0f, 1.0f / 2.0f}, {1.0f / 9.0f, 2.0f / 2.0f}, {1.0f / 9.0, 1.0f / 2.0f}},//enemy1
	{{1.0f / 9.0f, 2.0f / 2.0f},  {1.0f / 9.0f, 1.0f / 2.0f}, {2.0f / 9.0f, 2.0f / 2.0f}, {2.0f / 9.0, 1.0f / 2.0f}},//enemy2
	{{2.0f / 9.0f, 2.0f / 2.0f},  {2.0f / 9.0f, 1.0f / 2.0f}, {3.0f / 9.0f, 2.0f / 2.0f}, {3.0f / 9.0, 1.0f / 2.0f}},//enemy3
	{{3.0f / 9.0f, 2.0f / 2.0f},  {3.0f / 9.0f, 1.0f / 2.0f}, {4.0f / 9.0f, 2.0f / 2.0f}, {4.0f / 9.0, 1.0f / 2.0f}},//enemy1
	{{4.0f / 9.0f, 2.0f / 2.0f},  {4.0f / 9.0f, 1.0f / 2.0f}, {5.0f / 9.0f, 2.0f / 2.0f}, {5.0f / 9.0, 1.0f / 2.0f}},//enemy2
	{{5.0f / 9.0f, 2.0f / 2.0f},  {5.0f / 9.0f, 1.0f / 2.0f}, {6.0f / 9.0f, 2.0f / 2.0f}, {6.0f / 9.0, 1.0f / 2.0f}},//enemy3
};

//���e
const std::vector <QuadrangleTexel>  kTexelThunderBalls = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 5.0f, 1.0f / 1.0f},  {0.0f / 5.0f, 0.0f / 1.0f}, {1.0f / 5.0f, 1.0f / 1.0f}, {1.0f / 5.0, 0.0f / 1.0f}},//1
	{{1.0f / 5.0f, 1.0f / 1.0f},  {1.0f / 5.0f, 0.0f / 1.0f}, {2.0f / 5.0f, 1.0f / 1.0f}, {2.0f / 5.0, 0.0f / 1.0f}},//2
	{{2.0f / 5.0f, 1.0f / 1.0f},  {2.0f / 5.0f, 0.0f / 1.0f}, {3.0f / 5.0f, 1.0f / 1.0f}, {3.0f / 5.0, 0.0f / 1.0f}},//3
	{{3.0f / 5.0f, 1.0f / 1.0f},  {3.0f / 5.0f, 0.0f / 1.0f}, {4.0f / 5.0f, 1.0f / 1.0f}, {4.0f / 5.0, 0.0f / 1.0f}},//3
	{{4.0f / 5.0f, 1.0f / 1.0f},  {4.0f / 5.0f, 0.0f / 1.0f}, {5.0f / 5.0f, 1.0f / 1.0f}, {5.0f / 5.0, 0.0f / 1.0f}},//3
};

//��
const std::vector <QuadrangleTexel>  kTexelThunders = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
		{{0.0f / 4.0f, 1.0f / 1.0f},  {0.0f / 4.0f, 0.0f / 1.0f}, {1.0f / 4.0f, 1.0f / 1.0f}, {1.0f / 4.0, 0.0f / 1.0f}},//1
		{{1.0f / 4.0f, 1.0f / 1.0f},  {1.0f / 4.0f, 0.0f / 1.0f}, {2.0f / 4.0f, 1.0f / 1.0f}, {2.0f / 4.0, 0.0f / 1.0f}},//2
		{{2.0f / 4.0f, 1.0f / 1.0f},  {2.0f / 4.0f, 0.0f / 1.0f}, {3.0f / 4.0f, 1.0f / 1.0f}, {3.0f / 4.0, 0.0f / 1.0f}},//1
		{{3.0f / 4.0f, 1.0f / 1.0f},  {3.0f / 4.0f, 0.0f / 1.0f}, {4.0f / 4.0f, 1.0f / 1.0f}, {4.0f / 4.0, 0.0f / 1.0f}},//2
};

//�_
const std::vector <QuadrangleTexel>  kTexelClouds = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 3.0f, 1.0f / 1.0f},  {0.0f / 3.0f, 0.0f / 1.0f}, {1.0f / 3.0f, 1.0f / 1.0f}, {1.0f / 3.0, 0.0f / 1.0f}},//1
	{{1.0f / 3.0f, 1.0f / 1.0f},  {1.0f / 3.0f, 0.0f / 1.0f}, {2.0f / 3.0f, 1.0f / 1.0f}, {2.0f / 3.0, 0.0f / 1.0f}},//2
	{{2.0f / 3.0f, 1.0f / 1.0f},  {2.0f / 3.0f, 0.0f / 1.0f}, {3.0f / 3.0f, 1.0f / 1.0f}, {3.0f / 3.0, 0.0f / 1.0f}},//3
};

//�A
const std::vector <QuadrangleTexel>  kTexelBubbles = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 3.0f, 1.0f / 1.0f},  {0.0f / 3.0f, 0.0f / 1.0f}, {1.0f / 3.0f, 1.0f / 1.0f}, {1.0f / 3.0, 0.0f / 1.0f}},//1
	{{1.0f / 3.0f, 1.0f / 1.0f},  {1.0f / 3.0f, 0.0f / 1.0f}, {2.0f / 3.0f, 1.0f / 1.0f}, {2.0f / 3.0, 0.0f / 1.0f}},//2
	{{2.0f / 3.0f, 1.0f / 1.0f},  {2.0f / 3.0f, 0.0f / 1.0f}, {3.0f / 3.0f, 1.0f / 1.0f}, {3.0f / 3.0, 0.0f / 1.0f}},//3
};

//�o�b�N�O���E���h
const std::vector <QuadrangleTexel>  kTex_BackAnims = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 4.0f, 1.0f / 1.0f},  {0.0f / 4.0f, 0.0f / 1.0f}, {1.0f / 4.0f, 1.0f / 1.0f}, {1.0f / 4.0, 0.0f / 1.0f}},//1
	{{1.0f / 4.0f, 1.0f / 1.0f},  {1.0f / 4.0f, 0.0f / 1.0f}, {2.0f / 4.0f, 1.0f / 1.0f}, {2.0f / 4.0, 0.0f / 1.0f}},//2
	{{2.0f / 4.0f, 1.0f / 1.0f},  {2.0f / 4.0f, 0.0f / 1.0f}, {3.0f / 4.0f, 1.0f / 1.0f}, {3.0f / 4.0, 0.0f / 1.0f}},//3
	{{3.0f / 4.0f, 1.0f / 1.0f},  {3.0f / 4.0f, 0.0f / 1.0f}, {4.0f / 4.0f, 1.0f / 1.0f}, {4.0f / 4.0, 0.0f / 1.0f}},//3
};

//�o�b�N�O���E���h
const std::vector <QuadrangleTexel>  kTex_bBackAnims = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 4.0f, 1.0f / 1.0f},  {0.0f / 4.0f, 0.0f / 1.0f}, {1.0f / 4.0f, 1.0f / 1.0f}, {1.0f / 4.0, 0.0f / 1.0f}},//1
	{{1.0f / 4.0f, 1.0f / 1.0f},  {1.0f / 4.0f, 0.0f / 1.0f}, {2.0f / 4.0f, 1.0f / 1.0f}, {2.0f / 4.0, 0.0f / 1.0f}},//2
	{{2.0f / 4.0f, 1.0f / 1.0f},  {2.0f / 4.0f, 0.0f / 1.0f}, {3.0f / 4.0f, 1.0f / 1.0f}, {3.0f / 4.0, 0.0f / 1.0f}},//3
	{{3.0f / 4.0f, 1.0f / 1.0f},  {3.0f / 4.0f, 0.0f / 1.0f}, {4.0f / 4.0f, 1.0f / 1.0f}, {4.0f / 4.0, 0.0f / 1.0f}},//3
};

//�V���{��
const std::vector<QuadrangleTexel> kTexelSymbol = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 2.0f,1.0f / 1.0f},{0.0f / 2.0f, 0.0f / 1.0f},{1.0f / 2.0f, 1.0f / 1.0f},{1.0f / 2.0f, 0.0f / 1.0f}},
	{{1.0f / 2.0f,1.0f / 1.0f},{1.0f / 2.0f, 0.0f / 1.0f},{2.0f / 2.0f, 1.0f / 1.0f},{2.0f / 2.0f, 0.0f / 1.0f}},
};
//�o���[���i�{�[�i�X�X�e�[�W�j
const std::vector<QuadrangleTexel> kTexelBBalloons = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 5.0f, 1.0f / 1.0f},  {0.0f / 5.0f, 0.0f / 1.0f}, {1.0f / 5.0f, 1.0f / 1.0f}, {1.0f / 5.0, 0.0f / 1.0f}},//1
	{{1.0f / 5.0f, 1.0f / 1.0f},  {1.0f / 5.0f, 0.0f / 1.0f}, {2.0f / 5.0f, 1.0f / 1.0f}, {2.0f / 5.0, 0.0f / 1.0f}},//2
	{{2.0f / 5.0f, 1.0f / 1.0f},  {2.0f / 5.0f, 0.0f / 1.0f}, {3.0f / 5.0f, 1.0f / 1.0f}, {3.0f / 5.0, 0.0f / 1.0f}},//3
	{{3.0f / 5.0f, 1.0f / 1.0f},  {3.0f / 5.0f, 0.0f / 1.0f}, {4.0f / 5.0f, 1.0f / 1.0f}, {4.0f / 5.0, 0.0f / 1.0f}},//4
	{{4.0f / 5.0f, 1.0f / 1.0f},  {4.0f / 5.0f, 0.0f / 1.0f}, {5.0f / 5.0f, 1.0f / 1.0f}, {5.0f / 5.0, 0.0f / 1.0f}},//5
};

//UI
 //������UV���W
const std::vector <QuadrangleTexel> kTexelNumbers = {
	//   ����        ����       �E��         �E��
	{{0.8f,1.0f},{0.8f,0.5f},{1.0f,1.0f},{1.0f,0.5f}},   //!<Number0
	{{0.0f,0.5f},{0.0f,0.0f},{0.2f,0.5f},{0.2f,0.0f}},   //!<Number1
	{{0.2f,0.5f},{0.2f,0.0f},{0.4f,0.5f},{0.4f,0.0f}},   //!<Number2
	{{0.4f,0.5f},{0.4f,0.0f},{0.6f,0.5f},{0.6f,0.0f}},   //!<Number3
	{{0.6f,0.5f},{0.6f,0.0f},{0.8f,0.5f},{0.8f,0.0f}},   //!<Number4
	{{0.8f,0.5f},{0.8f,0.0f},{1.0f,0.5f},{1.0f,0.0f}},   //!<Number5
	{{0.0f,1.0f},{0.0f,0.5f},{0.2f,1.0f},{0.2f,0.5f}},   //!<Number6
	{{0.2f,1.0f},{0.2f,0.5f},{0.4f,1.0f},{0.4f,0.5f}},   //!<Number7
	{{0.4f,1.0f},{0.4f,0.5f},{0.6f,1.0f},{0.6f,0.5f}},   //!<Number8
	{{0.6f,1.0f},{0.6f,0.5f},{0.8f,1.0f},{0.8f,0.5f}},   //!<Number9
};

//���Z�X�R�A
const std::vector <QuadrangleTexel>  kTexelAddScores = {
	//          �����@�@�@�@�@�@              ����@�@�@�@�@             �E���@�@�@ �@              �E��
	{{0.0f / 5.0f, 1.0f / 1.0f},  {0.0f / 5.0f, 0.0f / 1.0f}, {1.0f / 5.0f, 1.0f / 1.0f}, {1.0f / 5.0, 0.0f / 1.0f}},//1
	{{1.0f / 5.0f, 1.0f / 1.0f},  {1.0f / 5.0f, 0.0f / 1.0f}, {2.0f / 5.0f, 1.0f / 1.0f}, {2.0f / 5.0, 0.0f / 1.0f}},//2
	{{2.0f / 5.0f, 1.0f / 1.0f},  {2.0f / 5.0f, 0.0f / 1.0f}, {3.0f / 5.0f, 1.0f / 1.0f}, {3.0f / 5.0, 0.0f / 1.0f}},//3
	{{3.0f / 5.0f, 1.0f / 1.0f},  {3.0f / 5.0f, 0.0f / 1.0f}, {4.0f / 5.0f, 1.0f / 1.0f}, {4.0f / 5.0, 0.0f / 1.0f}},//4
	{{4.0f / 5.0f, 1.0f / 1.0f},  {4.0f / 5.0f, 0.0f / 1.0f}, {5.0f / 5.0f, 1.0f / 1.0f}, {5.0f / 5.0, 0.0f / 1.0f}},//5
};