//----------------------------------------------
// �t�@�C���� �FObjSet.cpp
// �T�v�@�@�@ �F�I�u�W�F�N�g�̐����E�z�u�E�`��E�j���̏���
// ��ҁ@�@�@ �F21Cu0312 �͍� �t
// �X�V���e   �F2022/03/28 21CU0312 �͍� �t �쐬
//------------------------------------------------


#include "CActionGameApp.h"
#include "GameResource.h"
void CActionGameApp::SoundCreate()
{
	for (int i = 0; i < ENEMY_OBJECT_COUNT; ++i)
	{

		//�G�摜���쐬����Ă����珈�����s��
		if (g_enemyObjs[i].obj != NULL)
		{
			//�G�l�~�[�~��
			// �쐬����Ă��Ȃ���΁A�쐬
			if (!g_pEnemyDown && g_enemyObjs[i].EnemyStatus == 1)
			{
				// ��2�����F���[�v�ݒ�
				// ���[�v���Ȃ��̂ŁAfalse��ݒ�
				g_pEnemyDown = createSound(EnemyDown, true);
			}
		}
	}
}

void CActionGameApp::SoundPlay()
{
	//����
	if (g_pSFishDeath)
	{
		//�Q�[���X�^�[�g
		if (g_pPhaseStart)
		{
			StopSourceSound(g_pPhaseStart);
			disposeSound(g_pPhaseStart);
			g_pPhaseStart = NULL;
		}
		PlaySourceSound(g_pSFishDeath);
	}
	//�v���C���[����
	if (g_pFall)
	{
		//�Q�[���X�^�[�g
		if (g_pPhaseStart)
		{
			StopSourceSound(g_pPhaseStart);
			disposeSound(g_pPhaseStart);
			g_pPhaseStart = NULL;
		}
		PlaySourceSound(g_pFall);
	}
	//�G�l�~�[���S��
	if (g_pEnemyDeath)
	{
		//�Q�[���X�^�[�g
		if (g_pPhaseStart)
		{
			StopSourceSound(g_pPhaseStart);
			disposeSound(g_pPhaseStart);
			g_pPhaseStart = NULL;
		}
		PlaySourceSound(g_pEnemyDeath);
	}
	// �쐬����Ă�����Đ�
	//�Q�[���X�^�[�g
	if (g_pPhaseStart)
	{
		PlaySourceSound(g_pPhaseStart);

		//�G�l�~�[�~��
		if (g_pEnemyDown)
		{
			g_pEnemyDown->ChangeVolume(0);
		}
		//�v���C���[�W�����v
		if (g_pJump)
		{
			g_pJump->ChangeVolume(0);
		}
		//�v���C���[���s
		if (g_pStep)
		{
			g_pStep->ChangeVolume(0);
		}
		//�v���C���[�̕���
		if (g_pRespawn)
		{
			g_pRespawn->ChangeVolume(0);
		}
		//�Ԃ�������
		if (g_pHit)
		{
			g_pHit->ChangeVolume(0);
		}
		//���D�����ꂽ��
		if (g_pBalloonBom)
		{
			g_pBalloonBom->ChangeVolume(0);
		}
		//�G�l�~�[�̉H��
		for (int i = 0; i < 5; ++i)
		{
			if (g_pEnemyJump[i])
			{
				g_pEnemyJump[i]->ChangeVolume(0);
			}
		}
		//�A����
		if (g_pBuble)
		{
			g_pBuble->ChangeVolume(0);
		}
		if (g_pBubleBoom)
		{
			g_pBubleBoom->ChangeVolume(0);
		}
		//����
		if (g_pWater)
		{
			g_pWater->ChangeVolume(0);
		}
		//���o��
		if (g_pSFish)
		{
			g_pSFish->ChangeVolume(0);
		}
		//�G�l�~�[�̒���
		if (g_pSEnemyLanding)
		{
			g_pSEnemyLanding->ChangeVolume(0);
		}
	}
	//�t�F�[�Y�N���A
	else if (g_pPhaseCler)
	{
		PlaySourceSound(g_pPhaseCler);

		//�G�l�~�[�~��
		if (g_pEnemyDown)
		{
			g_pEnemyDown->ChangeVolume(0);
		}
		//�v���C���[�W�����v
		if (g_pJump)
		{
			g_pJump->ChangeVolume(0);
		}
		//�v���C���[���s
		if (g_pStep)
		{
			g_pStep->ChangeVolume(0);
		}
		//�v���C���[�̕���
		if (g_pRespawn)
		{
			g_pRespawn->ChangeVolume(0);
		}
		//�Ԃ�������
		if (g_pHit)
		{
			g_pHit->ChangeVolume(0);
		}
		//���D�����ꂽ��
		if (g_pBalloonBom)
		{
			g_pBalloonBom->ChangeVolume(0);
		}
		//�G�l�~�[�̉H��
		for (int i = 0; i < 5; ++i)
		{
			if (g_pEnemyJump[i])
			{
				g_pEnemyJump[i]->ChangeVolume(0);
			}
		}
		//�A����
		if (g_pBuble)
		{
			g_pBuble->ChangeVolume(0);
		}
		if (g_pBubleBoom)
		{
			g_pBubleBoom->ChangeVolume(0);
		}
		//����
		if (g_pWater)
		{
			g_pWater->ChangeVolume(0);
		}
		//���o��
		if (g_pSFish)
		{
			g_pSFish->ChangeVolume(0);
		}
		//�G�l�~�[�̒���
		if (g_pSEnemyLanding)
		{
			g_pSEnemyLanding->ChangeVolume(0);
		}
	}
	else if (g_pGameOver)
	{
		PlaySourceSound(g_pGameOver);

		//�G�l�~�[�~��
		if (g_pEnemyDown)
		{
			g_pEnemyDown->ChangeVolume(0);
		}
		//�v���C���[�W�����v
		if (g_pJump)
		{
			g_pJump->ChangeVolume(0);
		}
		//�v���C���[���s
		if (g_pStep)
		{
			g_pStep->ChangeVolume(0);
		}
		//�v���C���[�̕���
		if (g_pRespawn)
		{
			g_pRespawn->ChangeVolume(0);
		}
		//�Ԃ�������
		if (g_pHit)
		{
			g_pHit->ChangeVolume(0);
		}
		//���D�����ꂽ��
		if (g_pBalloonBom)
		{
			g_pBalloonBom->ChangeVolume(0);
		}
		//�G�l�~�[�̉H��
		for (int i = 0; i < 5; ++i)
		{
			if (g_pEnemyJump[i])
			{
				g_pEnemyJump[i]->ChangeVolume(0);
			}
		}
		//�A����
		if (g_pBuble)
		{
			g_pBuble->ChangeVolume(0);
		}
		//�A�擾
		if (g_pBubleBoom)
		{
			g_pBubleBoom->ChangeVolume(0);
		}
		//����
		if (g_pWater)
		{
			g_pWater->ChangeVolume(0);
		}
		//���o��
		if (g_pSFish)
		{
			g_pSFish->ChangeVolume(0);
		}
		//�G�l�~�[�̒���
		if (g_pSEnemyLanding)
		{
			g_pSEnemyLanding->ChangeVolume(0);
		}
	}
	else
	{
		//�G�l�~�[�~��
		if (g_pEnemyDown)
		{
			g_pEnemyDown->ChangeVolume(100);
		}
		//�v���C���[�W�����v
		if (g_pJump)
		{
			g_pJump->ChangeVolume(100);
		}
		//�v���C���[���s
		if (g_pStep)
		{
			g_pStep->ChangeVolume(100);
		}
		//�v���C���[�̕���
		if (g_pRespawn)
		{
			g_pRespawn->ChangeVolume(100);
		}
		//�Ԃ�������
		if (g_pHit)
		{
			g_pHit->ChangeVolume(100);
		}
		//���D�����ꂽ��
		if (g_pBalloonBom)
		{
			g_pBalloonBom->ChangeVolume(100);
		}
		//�G�l�~�[�̉H��
		for (int i = 0; i < 5; ++i)
		{
			if (g_pEnemyJump[i])
			{
				g_pEnemyJump[i]->ChangeVolume(25);
			}
		}
		//�A����
		if (g_pBuble)
		{
			g_pBuble->ChangeVolume(100);
		}
		//�A�擾
		if (g_pBubleBoom)
		{
			g_pBubleBoom->ChangeVolume(100);
		}
		//����
		if (g_pWater)
		{
			g_pWater->ChangeVolume(100);
		}
		//���o��
		if (g_pSFish)
		{
			g_pSFish->ChangeVolume(100);
		}
		//�G�l�~�[�̒���
		if (g_pSEnemyLanding)
		{
			g_pSEnemyLanding->ChangeVolume(100);
		}
	}
	//�G�l�~�[�~��
	if (g_pEnemyDown)
	{
		PlaySourceSound(g_pEnemyDown);
	}
	//�v���C���[�W�����v
	if (g_pJump)
	{
		PlaySourceSound(g_pJump);
	}
	//�v���C���[���s
	if (g_pStep)
	{
		PlaySourceSound(g_pStep);
	}
	//�v���C���[�̕���
	if (g_pRespawn)
	{
		PlaySourceSound(g_pRespawn);
	}
	//�Ԃ�������
	if (g_pHit)
	{
		PlaySourceSound(g_pHit);
	}
	//���D�����ꂽ��
	if (g_pBalloonBom)
	{
		PlaySourceSound(g_pBalloonBom);
	}
	//�G�l�~�[�̉H��
	for (int i = 0; i < 5; ++i)
	{
		if (g_pEnemyJump[i])
		{
			PlaySourceSound(g_pEnemyJump[i]);
		}
	}
	//�A����
	if (g_pBuble)
	{
		PlaySourceSound(g_pBuble);
	}
	//�A�擾
	if (g_pBubleBoom)
	{
		PlaySourceSound(g_pBubleBoom);
	}
	//����
	if (g_pWater)
	{
		PlaySourceSound(g_pWater);
	}
	//���d��
	if (g_pThunderDeath)
	{
		PlaySourceSound(g_pThunderDeath);
	}
	//���o��
	if (g_pSFish)
	{
		PlaySourceSound(g_pSFish);
	}
	//���o��
	if (g_pSThunder)
	{
		PlaySourceSound(g_pSThunder);
	}
	//������
	if (g_pThunderHit)
	{
		PlaySourceSound(g_pThunderHit);
	}
	//�G�l�~�[�̒���
	if (g_pSEnemyLanding)
	{
		PlaySourceSound(g_pSEnemyLanding);
	}
	//�{�[�i�X�X�e�[�WBGM
	if (g_pBonusBgm)
	{
		PlaySourceSound(g_pBonusBgm);
	}
	//�{�[�i�X�|�C���g
	if (g_pPoint)
	{
		PlaySourceSound(g_pPoint);
	}
	//�{�[�i�X�p�[�t�F�N�g
	if (g_pPerfect)

	{
		PlaySourceSound(g_pPerfect);
	}
}

void CActionGameApp::SoundDispose()
{
	// �Đ����I�������폜
	//�i���[�v�ݒ�true�̏ꍇ�͓���Ȃ��j
	//�Q�[���X�^�[�g
	if (g_pPhaseStart && (g_pPhaseStart->isPlayed() == false))
	{
		disposeSound(g_pPhaseStart);
		g_pPhaseStart = NULL;
	}
	//�t�F�[�Y�N���A
	if (g_pPhaseCler && (g_pPhaseCler->isPlayed() == false))
	{
		disposeSound(g_pPhaseCler);
		g_pPhaseCler = NULL;
	}
	//�G�l�~�[�~��
	EnemyCount = 0;
	for (int i = 0; i < ENEMY_OBJECT_COUNT; ++i)
	{
		if (g_enemyObjs[i].obj != NULL && g_enemyObjs[i].EnemyStatus == 1 &&
			g_enemyObjs[i].enemyVer == 0)
		{
			++EnemyCount;
		}
	}
	if (g_pEnemyDown && EnemyCount <= 0)
	{
		disposeSound(g_pEnemyDown);
		g_pEnemyDown = NULL;
	}
	//�G�l�~�[���S��
	if (g_pEnemyDeath && (g_pEnemyDeath->isPlayed() == false))
	{
		disposeSound(g_pEnemyDeath);
		g_pEnemyDeath = NULL;
	}
	//�v���C���[�W�����v
	if (g_pJump && (g_pJump->isPlayed() == false))
	{
		disposeSound(g_pJump);
		g_pJump = NULL;
	}
	//�v���C���[���s
	if (g_pStep && (g_pStep->isPlayed() == false))
	{
		disposeSound(g_pStep);
		g_pStep = NULL;
	}
	//�v���C���[�̕���
	if (g_pRespawn && (g_pRespawn->isPlayed() == false))
	{
		disposeSound(g_pRespawn);
		g_pRespawn = NULL;
	}
	//�Ԃ�������
	if (g_pHit && (g_pHit->isPlayed() == false))
	{
		disposeSound(g_pHit);
		g_pHit = NULL;
	}
	//���D�����ꂽ��
	if (g_pBalloonBom && (g_pBalloonBom->isPlayed() == false))
	{
		disposeSound(g_pBalloonBom);
		g_pBalloonBom = NULL;
	}
	//�A����
	if (g_pBuble && (g_pBuble->isPlayed() == false))
	{
		disposeSound(g_pBuble);
		g_pBuble = NULL;
	}
	//�A�擾
	if (g_pBubleBoom && (g_pBubleBoom->isPlayed() == false))
	{
		disposeSound(g_pBubleBoom);
		g_pBubleBoom = NULL;
	}
	//�Q�[���I�[�o�[
	if (g_pGameOver && (g_pGameOver->isPlayed() == false))
	{
		disposeSound(g_pGameOver);
		g_pGameOver = NULL;
	}
	//����
	if (g_pWater && (g_pWater->isPlayed() == false))
	{
		disposeSound(g_pWater);
		g_pWater = NULL;
	}
	//�v���C���[����
	if (g_pFall && (g_pFall->isPlayed() == false))
	{
		disposeSound(g_pFall);
		g_pFall = NULL;
	}
	//���d��
	if (g_pThunderDeath && (g_pThunderDeath->isPlayed() == false))
	{
		disposeSound(g_pThunderDeath);
		g_pThunderDeath = NULL;
	}
	//���o��
	if (g_pSFish && (g_pSFish->isPlayed() == false))
	{
		disposeSound(g_pSFish);
		g_pSFish = NULL;
	}
	//����
	if (g_pSFishDeath && (g_pSFishDeath->isPlayed() == false))
	{
		disposeSound(g_pSFishDeath);
		g_pSFishDeath = NULL;
	}
	//���o��
	if (g_pSThunder && (g_pSThunder->isPlayed() == false))
	{
		disposeSound(g_pSThunder);
		g_pSThunder = NULL;
	}
	//������
	if (g_pThunderHit && (g_pThunderHit->isPlayed() == false))
	{
		disposeSound(g_pThunderHit);
		g_pThunderHit = NULL;
	}
	//�G�l�~�[�̒���
	if (g_pSEnemyLanding && (g_pSEnemyLanding->isPlayed() == false))
	{
		disposeSound(g_pSEnemyLanding);
		g_pSEnemyLanding = NULL;
	}
	//�{�[�i�X�X�e�[�WBGM
	if (g_pBonusBgm && (g_pBonusBgm->isPlayed() == false))
	{
		disposeSound(g_pBonusBgm);
		g_pBonusBgm = NULL;
	}
	//�{�[�i�X�|�C���g
	if (g_pPoint && (g_pPoint->isPlayed() == false))
	{
		disposeSound(g_pPoint);
		g_pPoint = NULL;
	}
	//�{�[�i�X�p�[�t�F�N�g
	if (g_pPerfect && (g_pPerfect->isPlayed() == false))
	{
		disposeSound(g_pPerfect);
		g_pPerfect = NULL;
	}
}
