//----------------------------------------------
// �t�@�C���� �FFish.cpp
// �T�v�@�@�@ �F���̏���
// ��ҁ@�@�@ �F21Cu0207 �C�k����
// �X�V���e   �F3/9 ���̕\���A���ړ�
// �@�@�@�@�@ �F
// �@�@�@�@�@ �F
//           �F
//------------------------------------------------


#include "CActionGameApp.h"
#include "GameResource.h"

//���̈ړ�����
void CActionGameApp::procPlayMain_moveFish()     
{
	//�����ړ�������
	if (FishLanding == true)
	{
		if (Movewhich == true)
		{
			g_pFish->setPos(g_pFish->getPos().x - 3.0, g_pFish->getPos().y);
			g_pFish->setAngle(0.0, 180.0f, 0.0f);
		}
		else
		{
			g_pFish->setPos(g_pFish->getPos().x + 3.0, g_pFish->getPos().y);
			g_pFish->setAngle(0.0, 0.0f, 0.0f);
		}
			
	}
	
	

	//������ʒ[�ɍs�����甽�]������
	//���[�ɍs�����Ƃ�
	if (g_pFish->getPos().x < -480.0f)
		Movewhich = false;

	//���[�ɍs�����Ƃ�
	else if (g_pFish->getPos().x > 480.0f)
		Movewhich = true;

	for (int i = 0; i < 2; i++)
	{
		if (AimPlayer == 1 || AimPlayer == 2)
		{
			//������ɍs���߂��Ȃ��l�ɐ��䂷��
			if (g_pFish->getPos().y < -340.0f)
			{
				//�v���C���[��ǂ��悤�ɂ���
				//�����v���C���[�����ɂ���ꍇ
				if (g_pPlayer[i]->getPos().x > g_pFish->getPos().x)
				{
					g_pFish->setPos(g_pFish->getPos().x + 4.0f, g_pFish->getPos().y + 3.0f);
				}
				else if (g_pPlayer[i]->getPos().x < g_pFish->getPos().x)
				{
					g_pFish->setPos(g_pFish->getPos().x - 4.0f, g_pFish->getPos().y + 3.0f);
				}
			}
		}
	}
	for (int i = 0; i < ENEMY_OBJECT_COUNT; i++)
	{
		if (AimEnemy == i + 1 && g_enemyObjs[i].obj != NULL)
		{
			//������ɍs���߂��Ȃ��l�ɐ��䂷��
			if (g_pFish->getPos().y < -340.0f)
			{
				//�v���C���[��ǂ��悤�ɂ���
				//�����v���C���[�����ɂ���ꍇ
				if (g_enemyObjs[i].obj->getPos().x > g_pFish->getPos().x)
				{
					g_pFish->setPos(g_pFish->getPos().x + 4.0f, g_pFish->getPos().y + 3.0f);
				}
				else if (g_enemyObjs[i].obj->getPos().x < g_pFish->getPos().x)
				{
					g_pFish->setPos(g_pFish->getPos().x - 4.0f, g_pFish->getPos().y + 3.0f);
				}
			}
		}
	}
	
	FishAnim();
	
}

//���̃A���S���Y��
void CActionGameApp::procPlayMain_AlgorithmFish()
{
	//�v���C���[���n�ʂ�艺�ɂ���@���@�v���C���[��X���W�Ƌ���X���W�������ɂȂ������ɕߐH�̐��ɂȂ�
	for (int i = 0; i < 2; ++i)
	{
		if ((g_pPlayer[i]->getPos().y - 64.0f < -(WINDOW_HEIGHT / 2.0f - 140.0f) && 
			g_pPlayer[i]->getPos().x - 32.0f > WINDOW_LEFT + (64.0f * 4.0f) &&
			g_pPlayer[i]->getPos().x + 32.0f < WINDOW_RIGHT - (64.0f * 4.0f) &&
			PlayerLanding == false && g_pPlayer[i]->getPos().x + ActiveArea_Num >= g_pFish->getPos().x - ActiveArea_Num && g_pPlayer[i]->getPos().x - ActiveArea_Num <= g_pFish->getPos().x + ActiveArea_Num
			) || DeathFishFlag == true)
		{
			if (!g_pSFish && FishLanding == true)
			{
				// ��2�����F���[�v�ݒ�
				// ���[�v���Ȃ��̂ŁAfalse��ݒ�
				g_pSFish = createSound(SFish, false);
			}
			//�v���C���[�Ɖ����̓����蔻���ݒ肷��
			/*if (g_pPlayer[i]->getPos().x + ActiveArea_Num >= g_pFish->getPos().x - ActiveArea_Num && g_pPlayer[i]->getPos().x - ActiveArea_Num <= g_pFish->getPos().x + ActiveArea_Num)*/
				AimPlayer = i + 1;
				FishLanding = false;
		}

		//�����ߐH����߂����ɏ��X�Ɍ��̍��W�ɖ߂�悤�ɂ���
		else if (AimPlayer == 0 && AimEnemy == 0)
		{
			if (g_pFish->getPos().y > -450.0f)
			{
				FishPos = g_pFish->getPos().x;
				g_pFish->setPos(FishPos, g_pFish->getPos().y - 2.0f);
			}
			else
			{
				FishPos = g_pFish->getPos().x;
				g_pFish->setPos(FishPos, -450.0f);
			}
		}
		else
		{
			AimPlayer = 0;
		}
	}

	//�G���n�ʂ�艺�ɂ���@���@�G��X���W�Ƌ���X���W�������ɂȂ������ɕߐH�̐��ɂȂ�
	for (int i = 0; i < ENEMY_OBJECT_COUNT; ++i)
	{
		if (g_enemyObjs[i].enemyVer == 0 && g_enemyObjs[i].obj != NULL)
		{
			if ((g_enemyObjs[i].obj->getPos().y - 64.0f < -(WINDOW_HEIGHT / 2.0f - 140.0f) &&
				g_enemyObjs[i].obj->getPos().x - 32.0f > WINDOW_LEFT + (64.0f * 4.0f) &&
				g_enemyObjs[i].obj->getPos().x + 32.0f < WINDOW_RIGHT - (64.0f * 4.0f) &&
				g_enemyObjs[i].obj->getPos().x + ActiveArea_Num >= g_pFish->getPos().x - ActiveArea_Num &&
				g_enemyObjs[i].obj->getPos().x - ActiveArea_Num <= g_pFish->getPos().x + ActiveArea_Num) ||
				EnemyDeathFishFlag == true)
			{
				if (!g_pSFish && FishLanding == true)
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pSFish = createSound(SFish, false);
				}
				//�v���C���[�Ɖ����̓����蔻���ݒ肷��
				/*if (g_pPlayer[i]->getPos().x + ActiveArea_Num >= g_pFish->getPos().x - ActiveArea_Num && g_pPlayer[i]->getPos().x - ActiveArea_Num <= g_pFish->getPos().x + ActiveArea_Num)*/
				AimEnemy = i+1;
				FishLanding = false;
			}

			//�����ߐH����߂����ɏ��X�Ɍ��̍��W�ɖ߂�悤�ɂ���
			else if (AimPlayer == 0 && AimEnemy == 0)
			{
				if (g_pFish->getPos().y > -450.0f)
				{
					FishPos = g_pFish->getPos().x;
					g_pFish->setPos(FishPos, g_pFish->getPos().y - 2.0f);
				}
				else
				{
					FishPos = g_pFish->getPos().x;
					g_pFish->setPos(FishPos, -450.0f);
				}
			}
			else if(AimEnemy == i+1)
			{
				AimEnemy = 0;
			}
		}
		else if (AimEnemy == i + 1)
		{
			AimEnemy = 0;
		}
	}

	if (g_pFish->getPos().y <= -450.0f)
	{
		FishLanding = true;
	}
	
	//�v���C���[�Ƌ��̓����蔻�������
	//�����v���C���[�̔����܂�X������ɂȂ�����v���C���[�͎���
	for (int i = 0; i < 2; i++)
	{
		if (g_pFish->getPos().y + 80.0f > g_pPlayer[i]->getPos().y && g_pFish->getPos().y > WINDOW_BOTTOM + (140.0f - 20.0f))
		{
			if (g_pPlayer[0]->getPos().y - 48.0f <= g_pFish->getPos().y && g_pPlayer[0]->getPos().x - KillArea_Num <= g_pFish->getPos().x + KillArea_Num)
			{
				DeathFishFlag = true;
				if (!g_pSFishDeath)
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pSFishDeath = createSound(SFishDeath, false);
				}
			}
			
		}
	}
	//�G
	for (int i = 0; i < ENEMY_OBJECT_COUNT; i++)
	{
		if (g_enemyObjs[i].obj != NULL)
		{
			if (g_pFish->getPos().y + 80.0f > g_enemyObjs[i].obj->getPos().y && g_pFish->getPos().y > WINDOW_BOTTOM + (140.0f - 20.0f))
			{
				if (g_enemyObjs[i].obj->getPos().y - 48.0f <= g_pFish->getPos().y && g_enemyObjs[i].obj->getPos().x - KillArea_Num <= g_pFish->getPos().x + KillArea_Num)
				{
					if (!g_pSFishDeath)
					{
						// ��2�����F���[�v�ݒ�
						// ���[�v���Ȃ��̂ŁAfalse��ݒ�
						g_pSFishDeath = createSound(SFishDeath, false);
					}
					EnemyDeathFishLvel = g_enemyObjs[i].EnemyLevel;
					EnemyDeathFishFlag = true;
					disposeSprite(g_enemyObjs[i].obj);
					g_enemyObjs[i].obj = NULL;

					disposeSprite(g_enemyObjs[i + 1].obj);
					g_enemyObjs[i + 1].obj = NULL;
				}
			}
		}
	}
}