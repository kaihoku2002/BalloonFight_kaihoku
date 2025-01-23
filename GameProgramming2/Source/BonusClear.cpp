//----------------------------------------------------------
// �t�@�C����		�FBonusClear.cpp
// �T�v				�F�{�[�i�X�X�e�[�W�N���A��ʂ̏����̊֐��̒�`
// �쐬��			�F21CU0136 ���{����
// �X�V���e			�F2022/03/28 21CU0136���{�@�쐬
//					�F2022/03/30 21CU0136���{�@�A�j���[�V�����ݒ�
//----------------------------------------------------------

#include "CActionGameApp.h"
#include "GameResource.h"
#include <Windows.h>

/*
 * �{�[�i�X�X�e�[�W�N���A��ʂ̏������s������
 */
void CActionGameApp::procBonusClear()
{
	switch (g_BonusClearPhase)
	{
		case eBegin:
		{
			//g_pPlayer ���쐬����Ă��鎞�̂ݔj������
			for (int i = 0; i < 2; i++)
			{
				if (g_pPlayer[i] != NULL)
				{
					disposeSprite(g_pPlayer[i]);
					g_pPlayer[i] = NULL;
				}
			}
			//�{�[�i�X�N���A��ʊJ�n���ɍs������
			procBonusClearBegin();
			//�i�s��Ԃ����C���ɕύX����
			g_BonusClearPhase = eMain;
		}
		break;
		case eMain:
		{
			//�f�o�b�O�p
			if (m_pDirectInput->isPressedOnce(DIK_F))
			{
				PerfectFlag = false;
			}
			//���[�h�̃t���O�����Z�b�g
			IsLoad = IsLoad & 0b0111;
			//�{�[�i�X�N���A��ʂ̃��C������
			procBonusClearMain();
		}
		break;
		case eEnd:
		{
			//���[�h����
			IsLoad = IsLoad | 0b0010;
			//�{�[�i�X��ʏI�����ɍs������
			procBonusClearEnd();
			procPlayEnd();
			//�t�F�[�Y��߂�
			g_BonusClearPhase = eBegin;
			//�ēx�^�C�g����ʂɗ������ɊJ�n���珈�����s�����߂Ƀt�F�[�Y��߂��Ă���
			SetNextGameStatus(g_NextStatusFromBonusClear);
		}
		break;
	}
}

//�֐���		:procBonusClearBegin()
//�������e		:�{�[�i�X�N���A��ʂ̊J�n���ɍs������
//����			:�Ȃ�
//�߂�l		:�Ȃ�
void CActionGameApp::procBonusClearBegin()
{
	//�l���X�R�A�v�Z
	TotalScore = BalloonPoints * BreakBallonCnt; //20���{�[�i�X�X�e�[�W�̕ϐ��ɕϊ�
	//�p�[�t�F�N�g�t���O�̊Ǘ� �Е���20���{�[�i�X�X�e�[�W�̕ϐ��ɕϊ�
	if (BreakBallonCnt == 20)
	{
		PerfectFlag = true;
	}

	//�摜�쐬
	if (g_BonusClearBack == NULL)
	{
		g_BonusClearBack = createSprite(Tex_Black);
	}
	if (g_pBounusPerfect == NULL)
	{
		g_pBounusPerfect = createSprite(Tex_BounusPerfect);
	}
	if (g_pPlayer[0] == NULL)
	{
		g_pPlayer[0] = createSprite(Tex_Player,PLAYER_SIZE_X,PLAYER_SIZE_Y);
		g_pPlayer[0]->setPos(-PLAYER_SIZE_X * 5.5f, PLAYER_SIZE_Y * 1.0f);
	}
	if (g_pMultiplicationMark == NULL)
	{
		g_pMultiplicationMark = createSprite(Tex_Symbol, Symbol_SIZE_X, Symbol_SIZE_Y);
		g_pMultiplicationMark->setPos(-Symbol_SIZE_X * 4.5f, Symbol_SIZE_Y * 5.2f);
		g_pMultiplicationMark->setAnimation(0);
	}
	if (g_pEqualSign == NULL)
	{
		g_pEqualSign = createSprite(Tex_Symbol, PlayerScore.Size_X, Symbol_SIZE_Y);
		g_pEqualSign->setPos(Symbol_SIZE_X * 4.0f, Symbol_SIZE_Y * 5.2f);
		g_pEqualSign->setAnimation(1);
	}
	if (g_pPTS == NULL)
	{
		g_pPTS = createSprite(Tex_PTS, 108.0f, 28.0f);
		g_pPTS->setPos(108.0f * 3.5f, 28.0f * 4.5f);
	}
	if (g_pBBalloon == NULL)
	{
		g_pBBalloon = createSprite(Tex_BBalloon, 64.0f, 64.0f);
		g_pBBalloon->setPos(-64.0f * 3.3f, 64.0f * 1.9f);
	}

	//�t�H���g�쐬
	if (g_BalloonScore == NULL)
	{
		g_BalloonScore = createFont(Tex_Score,3, PlayerScore.Size_X, PlayerScore.Size_Y);
		g_BalloonScore->setPos(-PlayerScore.Size_X * 8.5f, PlayerScore.Size_Y * 4.0f);
	}
	if (g_pGetBalloon == NULL)
	{
		g_pGetBalloon = createFont(Tex_Score, 2, PlayerScore.Size_X, PlayerScore.Size_Y);
		g_pGetBalloon->setPos(-PlayerScore.Size_X * 1.5f, PlayerScore.Size_Y * 4.0f);
	}
	if (g_pTotalScore == NULL)
	{
		g_pTotalScore = createFont(Tex_Score, 4, PlayerScore.Size_X, PlayerScore.Size_Y); //������ϐ��ɂł����炢��
		g_pTotalScore->setPos(PlayerScore.Size_X * 4.5f, PlayerScore.Size_Y * 4.0f);
	}
}
//�֐���		:procBonusClearMain()
//�������e		:�{�[�i�X�N���A��ʂ̃��C������
//����			:�Ȃ�
//�߂�l		:�Ȃ�
void CActionGameApp::procBonusClearMain()
{
	//���Ԃ̌v�Z
	++BonusTimeCnt;
	//6�b��Ɏ����ŉ�ʈڍs����
	if (BonusTimeCnt > 60 * 6)
	{
		//�^�C�g���ɃX�e�[�^�X���ڍs���鏀��������
		g_BonusClearPhase = eEnd;
		g_NextStatusFromBonusClear = ePlaying;
		//�t�F�[�Y1�Ɉڍs
		PhaseNum = 1;
		Block.Count = BlockPos[PhaseNum - 1].ConnectCount[0] + BlockPos[PhaseNum - 1].ConnectCount[1] + BlockPos[PhaseNum - 1].ConnectCount[2] + BlockPos[PhaseNum - 1].ConnectCount[3] + BlockPos[PhaseNum - 1].ConnectCount[4];
		RightBlock.Count = BlockPos[PhaseNum - 1].Count;
		LeftBlock.Count = BlockPos[PhaseNum - 1].Count;
		Cloud.Count = CloudPos[PhaseNum - 1].Count;
	}

	//3�b��ɃX�R�A���Z 20���{�[�i�X�X�e�[�W�̕ϐ��ɕϊ� �E��3���{�[�i�X�X�e�[�W�t�F�[�Y�̕ϐ��ɕϊ�
	if (BonusTimeCnt > 60 * 3 && getballoonCnt / 3 < BreakBallonCnt)
	{
		//�{�[�i�X�|�C���g
		if (g_pPoint && BonusTimeCnt % 3 == 0)
		{
			disposeSound(g_pPoint);
			g_pPoint = NULL;
		}
		if (!g_pPoint)
		{
			// ��2�����F���[�v�ݒ�
			// ���[�v���Ȃ��̂ŁAfalse��ݒ�
			g_pPoint = createSound(Point, false);
		}
		//�J��Ԃ������v�Z
		++getballoonCnt;
		//�o���[���l���������Z
		PlayerScore.Score += 100;
		//���Z
		TotalScore -= 100;
	}
	//�v�Z���I������^�C�~���O�Ńt���O���I���ɂ��� 20���{�[�i�X�X�e�[�W�̕ϐ��ɕϊ� 3���{�[�i�X�X�e�[�W�t�F�[�Y�̕ϐ��ɕϊ�
	else if (getballoonCnt == BreakBallonCnt * 3)
	{
		ScoreFlag = true;
		getballoonCnt += 1;
	}
	//�p�[�t�F�N�g���̌v�Z �v���X����X�R�A���t�F�[�Y�ɂ���ĕς���
	if (PerfectFlag != false && ScoreFlag != false)
	{
		//�{�[�i�X�|�C���g
		if (g_pPoint)
		{
			disposeSound(g_pPoint);
			g_pPoint = NULL;
		}
		if (!g_pPoint)
		{
			// ��2�����F���[�v�ݒ�
			// ���[�v���Ȃ��̂ŁAfalse��ݒ�
			g_pPoint = createSound(Point, false);
		}
		//1�b�~�߂�
		Sleep(1000);
		PlayerScore.Score += 10000;
		ScoreFlag = false;
	}
	//���
	if (PlayerScore.Score > 999999)
	{
		PlayerScore.Score = 999999;
	}

	//�ŏ�����`��
	//�摜�`��
	if (g_BonusClearBack != NULL)
	{
		renderSprite(g_BonusClearBack);
	}
	if (g_pPlayer[0] != NULL)
	{
		renderSprite(g_pPlayer[0]);
	}
	if (g_pBBalloon != NULL)
	{
		renderSprite(g_pBBalloon);
	}
	//UI�̕`��
	UIrender();

	//0.5�b��ɕ`��
	if (BonusTimeCnt > 30 * 1)
	{
		//�摜�`��
		if (g_pMultiplicationMark != NULL)
		{
			renderSprite(g_pMultiplicationMark);
		}
		//�t�H���g�`��
		if (g_pGetBalloon != NULL)
		{
			renderFont(g_pGetBalloon, BreakBallonCnt); //20�̕������{�[�i�X�X�e�[�W�Ŏg�p����ϐ��ɕύX
		}
	}
	//0.95�b��ɕ`��
	if ((float)BonusTimeCnt > 30.0f * 1.9f)
	{
		//�A�j���[�V�����Z�b�g
		if (g_pBBalloon != NULL)
		{
			g_pBBalloon->setAnimation(4);
		}
	}
	//1�b��ɕ`��A�j��
	if (BonusTimeCnt > 30 * 2)
	{
		//�摜�j��
		if (g_pBBalloon != NULL)
		{
			disposeSprite(g_pBBalloon);
			g_pBBalloon = NULL;
		}
		//�摜�`��
		if (g_pEqualSign != NULL)
		{
			renderSprite(g_pEqualSign);
		}
		if (g_pPTS != NULL)
		{
			renderSprite(g_pPTS);
		}
		//�t�H���g�`��
		if (g_pTotalScore != NULL)
		{
			renderFont(g_pTotalScore, TotalScore);
		}
		if (g_BalloonScore != NULL)
		{
			renderFont(g_BalloonScore, BalloonPoints);
		}
	}
	//1.5�b�ォ�p�[�t�F�N�g���ɕ`��
	if (PerfectFlag != false && BonusTimeCnt > 30 * 3)
	{
		if (g_pBounusPerfect != NULL)
		{
			if (!g_pPerfect && BonusTimeCnt < 30 * 4)
			{
				// ��2�����F���[�v�ݒ�
				// ���[�v���Ȃ��̂ŁAfalse��ݒ�
				g_pPerfect = createSound(Perfect, false);
			}
			renderSprite(g_pBounusPerfect);
		}
	}
	SoundPlay();
	SoundDispose();
}

//�֐���		:procBonusClearEnd()
//�������e		:�{�[�i�X�N���A��ʂ̏I�����ɍs������
//����			:�Ȃ�
//�߂�l		:�Ȃ�
void CActionGameApp::procBonusClearEnd()
{
	//�摜�̔j��
	if (g_BonusClearBack != NULL)
	{
		disposeSprite(g_BonusClearBack);
		g_BonusClearBack = NULL;
	}
	if (g_pBounusPerfect != NULL)
	{
		disposeSprite(g_pBounusPerfect);
		g_pBounusPerfect = NULL;
	}
	if (g_pPlayer[0] != NULL)
	{
		disposeSprite(g_pPlayer[0]);
		g_pPlayer[0] = NULL;
	}
	if (g_pPlayer[1] != NULL)
	{
		disposeSprite(g_pPlayer[1]);
		g_pPlayer[1] = NULL;
	}
	if (g_pMultiplicationMark != NULL)
	{
		disposeSprite(g_pMultiplicationMark);
		g_pMultiplicationMark = NULL;
	}
	if (g_pEqualSign != NULL)
	{
		disposeSprite(g_pEqualSign);
		g_pEqualSign = NULL;
	}
	if (g_pPTS != NULL)
	{
		disposeSprite(g_pPTS);
		g_pPTS = NULL;
	}

	//�t�H���g�j��
	if (g_BalloonScore != NULL)
	{
		disposeFont(g_BalloonScore);
		g_BalloonScore = NULL;
	}
	if (g_pGetBalloon != NULL)
	{
		disposeFont(g_pGetBalloon);
		g_pGetBalloon = NULL;
	}
	if (g_pTotalScore != NULL)
	{
		disposeFont(g_pTotalScore);
		g_pTotalScore = NULL;
	}


	//�l���Z�b�g
	getballoonCnt = 0;
	BonusTimeCnt = 0;
	PerfectFlag = false;
	ScoreFlag = false;
	BonusON = false;
	PhaseNum = 1;

	for (int i = 0; i < Balloon.Count; ++i)
	{
		g_pBalloon[i].BalloonCourse = 3;
		g_pBalloon[i].BalloonSpeed = 0.0f;
		g_pBalloon[i].inPipe = true;
		g_pBalloon[i].HIt = false;
	}
	NowballoonCnt = 0;
	BreakBallonCnt = 0;
	balloonCnt = 0;
	DeathCoolFlag = true;

	//�j��
	BObjDispose();
	SoundDispose();              //����
}