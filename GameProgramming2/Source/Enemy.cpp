//----------------------------------------------
// �t�@�C���� �FEnemy.cpp
// �T�v�@�@�@ �F�G�l�~�[�̐����E�z�u�E�`��E�j���E�ړ��̏���
// ��ҁ@�@�@ �F21CU0239 �n�Ӑ����Y
// �X�V���e     :2022/03/09/�@�G�l�~�[�摜�̍쐬�E�G�l�~�[�̕`��E�G�l�~�[�̔j��
//------------------------------------------------

#include "CActionGameApp.h"
#include "GameResource.h"
#include <math.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


//�֐���		�@ :procPlayMain_EnemyCreate()
//�������e		:�G�l�~�[�̍쐬
//����			:�Ȃ�
//�߂�l		    :�Ȃ�
void CActionGameApp::procPlayMain_EnemyCreate()
{
	for (int i = 0; i < iEnemyCount[PhaseNum - 1]; ++i)
	{
		g_enemyObjs[i].beginPos = EnemybeginPos[PhaseNum - 1][i];
		g_enemyObjs[i].EnemyLevel = iEnemyLevel[PhaseNum - 1][i];
	}

	//�G�̉摜���쐬����
	for (int i = 0; i < iEnemyCount[PhaseNum - 1]; ++i)
	{
		//���ꂼ��́@obj�@���@NULL�̎��̂݉摜���쐬����
		if (g_enemyObjs[i].obj == NULL)
		{
			//�G�̉摜���쐬����
			g_enemyObjs[i].obj = createSprite(Tex_Enemy1, ENEMY_SIZE_X, ENEMY_SIZE_Y);
		}
	}
	//�G�̉摜��z�u����
	for (int i = 0; i < iEnemyCount[PhaseNum - 1]; ++i)
	{
		//g_enemyObjs[i].obj ���쐬����Ă���ꍇ�̂ݍ쐬����
		if (g_enemyObjs[i].obj != NULL)
		{
			//�G�̉摜��z�u����
			g_enemyObjs[i].obj->setPos(g_enemyObjs[i].beginPos);
			g_enemyObjs[i].obj->setAnimation(0 + (g_enemyObjs[i].EnemyLevel * 18));
			g_enemyObjs[i].obj->setAngle(0.0f, 0.0f, 0.0f);
		}
	}
}


//�֐���		:procPlayMain_EnemyBothEnd()
//�������e		:��ʒ[�̏���
//����			:�Ȃ�
//�߂�l		:�Ȃ�
void CActionGameApp::procPlayMain_EnemyBothEnd()
{
	//�G�l�~�[����ʒ[�𒴂����甽�Α��̉�ʒ[�ɕ`�悷��
	//���[�ɍs�����Ƃ�
	for (int i = 0; i < ENEMY_OBJECT_COUNT; ++i)
	{
		//enemyVer��0�̎�
		if (g_enemyObjs[i].enemyVer == 0 && g_enemyObjs[i].obj != NULL)
		{
			//���[�ɍs�����Ƃ�
			if (g_enemyObjs[i].obj->getPos().x < WINDOW_LEFT + (ENEMY_SIZE_X / 2.0f))
			{
				//���W�𒲐�
				g_enemyObjs[i + 1].obj->setPos(g_enemyObjs[i].obj->getPos().x + WINDOW_WIDTH, g_enemyObjs[i].obj->getPos().y);
				//��ʊO�Ɋ��S�ɏo���ꍇ
				if (g_enemyObjs[i].obj->getPos().x < WINDOW_LEFT - (ENEMY_SIZE_X / 2.0f))
				{
					g_enemyObjs[i].obj->setPos(g_enemyObjs[i + 1].obj->getPos().x, g_enemyObjs[i + 1].obj->getPos().y);
					g_enemyObjs[i + 1].NowEdge = false;
				}
			}
			//�E�[�ɍs�����Ƃ�
			else if (g_enemyObjs[i].obj->getPos().x > WINDOW_RIGHT - (ENEMY_SIZE_X / 2.0f))
			{
				//���W�𒲐�
				g_enemyObjs[i + 1].obj->setPos(g_enemyObjs[i].obj->getPos().x - WINDOW_WIDTH, g_enemyObjs[i].obj->getPos().y);
				g_enemyObjs[i + 1].NowEdge = true;
				//��ʊO�Ɋ��S�ɏo���ꍇ
				if (g_enemyObjs[i].obj->getPos().x > WINDOW_RIGHT + (ENEMY_SIZE_X / 2.0f))
				{
					g_enemyObjs[i].obj->setPos(g_enemyObjs[i + 1].obj->getPos().x, g_enemyObjs[i + 1].obj->getPos().y);
					g_enemyObjs[i + 1].NowEdge = false;
				}
			}
			else
			{
				g_enemyObjs[i + 1].obj->setPos(g_enemyObjs[i].obj->getPos().x, g_enemyObjs[i].obj->getPos().y);
				g_enemyObjs[i + 1].NowEdge = false;
			}
		}
	}
	
}


//�֐���		:procPlayMain_procEnemy()
//�������e		:�G�l�~�[�̃��C������
//����			:�Ȃ�
//�߂�l		    :�Ȃ�
void CActionGameApp::procPlayMain_procEnemy()
{


	//�����\�̊�l��ݒ�
	srand((unsigned)time(NULL));


	//�G�̏���
	for (int i = 0; i < ENEMY_OBJECT_COUNT; ++i)
	{
		//�G�摜���쐬����Ă����珈�����s��
		if (g_enemyObjs[i].obj != NULL && g_enemyObjs[i].EnemyStatus != 4)
		{
			//�`�悷��
			renderSprite(g_enemyObjs[i].obj);

			if (g_enemyObjs[i].EnemyStatus == 0 &&
				EnemyDeathFallFlag[i] != true &&
				EnemyDeathFallFlag[i + 1] != true)
			{

				//�J�E���^���N��
				g_enemyObjs[i].flameCnt[0] += 1;
				g_enemyObjs[i].flameCnt[1] += 1;

				//�G�l�~�[�̍��W
				g_enemyObjs[i].enemyPos = g_enemyObjs[i].obj->getPos();
				//�v���C���[�̍��W
				XMFLOAT4 Playerpos = g_pPlayer[0]->getPos();

				//���݂̃G�l�~�[�̍��W�ɂ����EnemyArea�̒l��ς���
				//����
				if (g_enemyObjs[i].enemyPos.x < AreaLineLeft && g_enemyObjs[i].enemyPos.x > WINDOW_LEFT && g_enemyObjs[i].enemyPos.y > AreaLineOver)
				{
					g_enemyObjs[i].EnemyArea = 0;
				}
				//������
				else if (g_enemyObjs[i].enemyPos.x > AreaLineLeft && g_enemyObjs[i].enemyPos.x < AreaLineRight && g_enemyObjs[i].enemyPos.y > AreaLineOver)
				{
					g_enemyObjs[i].EnemyArea = 1;
				}
				//�E��
				else if (g_enemyObjs[i].enemyPos.x < WINDOW_RIGHT && g_enemyObjs[i].enemyPos.x > AreaLineRight && g_enemyObjs[i].enemyPos.y > AreaLineOver)
				{
					g_enemyObjs[i].EnemyArea = 2;
				}
				//��
				if (g_enemyObjs[i].enemyPos.x < AreaLineLeft && g_enemyObjs[i].enemyPos.x > WINDOW_LEFT &&
					g_enemyObjs[i].enemyPos.y < AreaLineOver && g_enemyObjs[i].enemyPos.y > AreaLineUnder)
				{
					g_enemyObjs[i].EnemyArea = 3;
				}
				//����
				else if (g_enemyObjs[i].enemyPos.x > AreaLineLeft && g_enemyObjs[i].enemyPos.x < AreaLineRight &&
					g_enemyObjs[i].enemyPos.y < AreaLineOver && g_enemyObjs[i].enemyPos.y > AreaLineUnder)
				{
					g_enemyObjs[i].EnemyArea = 4;
				}
				//�E
				else if (g_enemyObjs[i].enemyPos.x < WINDOW_RIGHT && g_enemyObjs[i].enemyPos.x > AreaLineRight &&
					g_enemyObjs[i].enemyPos.y < AreaLineOver && g_enemyObjs[i].enemyPos.y > AreaLineUnder)
				{
					g_enemyObjs[i].EnemyArea = 5;
				}
				//����
				else if (g_enemyObjs[i].enemyPos.x < AreaLineLeft && g_enemyObjs[i].enemyPos.x > WINDOW_LEFT && g_enemyObjs[i].enemyPos.y < AreaLineUnder)
				{
					g_enemyObjs[i].EnemyArea = 6;
				}
				//������
				else if (g_enemyObjs[i].enemyPos.x > AreaLineLeft && g_enemyObjs[i].enemyPos.x < AreaLineRight && g_enemyObjs[i].enemyPos.y < AreaLineUnder)
				{
					g_enemyObjs[i].EnemyArea = 7;
				}
				//�E��
				else if (g_enemyObjs[i].enemyPos.x < WINDOW_RIGHT && g_enemyObjs[i].enemyPos.x > AreaLineRight && g_enemyObjs[i].enemyPos.y < AreaLineUnder)
				{
					g_enemyObjs[i].EnemyArea = 8;
				}

				//�i�X�Ƒ��x���グ��
				//x���̈ړ�
				//g_pEnemyMaxSpeed_X���v���X�̏ꍇ
				if (g_enemyObjs[i].g_pEnemyMaxSpeed_X >= 0.1)
				{
					if (g_enemyObjs[i].g_pEnemyFlySpeed_X < g_enemyObjs[i].g_pEnemyMaxSpeed_X)
					{
						g_enemyObjs[i].g_pEnemyFlySpeed_X += 0.1;
					}
				}
				//g_pEnemyMaxSpeed_X���}�C�i�X�̏ꍇ
				else if (g_enemyObjs[i].g_pEnemyMaxSpeed_X <= -0.1)
				{
					if (g_enemyObjs[i].g_pEnemyFlySpeed_X > g_enemyObjs[i].g_pEnemyMaxSpeed_X)
					{
						g_enemyObjs[i].g_pEnemyFlySpeed_X -= 0.1;
					}
				}
				//y���̈ړ�
				//g_pEnemyMaxSpeed_Y���v���X�̏ꍇ
				if (g_enemyObjs[i].g_pEnemyMaxSpeed_Y >= 0.1)
				{
					if (g_enemyObjs[i].g_pEnemyFlySpeed_Y < g_enemyObjs[i].g_pEnemyMaxSpeed_Y)
					{
						g_enemyObjs[i].g_pEnemyFlySpeed_Y += 0.1;
					}
				}
				//g_pEnemyMaxSpeed_Y���}�C�i�X�̏ꍇ
				else if (g_enemyObjs[i].g_pEnemyMaxSpeed_Y <= -0.1)
				{
					if (g_enemyObjs[i].g_pEnemyFlySpeed_Y > g_enemyObjs[i].g_pEnemyMaxSpeed_Y)
					{
						g_enemyObjs[i].g_pEnemyFlySpeed_Y -= 0.1;
					}
				}


				//���t���[���𒴂�������������W���Ď擾����
				if (g_enemyObjs[i].obj->collision(g_enemyObjs[i].DirectionPos,64.0f) || g_enemyObjs[i].flameCnt[1] >= (rand() % 100) + 360)
				{
					//����������
					g_enemyObjs[i].pattern = rand() % 10;
					//�G�l�~�[�̌��݂̃G���A�ɉ����āA�����_���ɍ��W���擾����
					//����
					if (g_enemyObjs[i].EnemyArea == 0)
					{
						//������Ɉړ�
						if (g_enemyObjs[i].pattern > 4)
						{
							g_enemyObjs[i].DirectionPos.x = 0.0f;
							g_enemyObjs[i].DirectionPos.y = 400.0f;
						}
						//���Ɉړ�
						else if (g_enemyObjs[i].pattern > 8)
						{
							g_enemyObjs[i].DirectionPos.x = -400.0f;
							g_enemyObjs[i].DirectionPos.y = 100.0f;
						}
						//�����Ɉړ�
						else
						{
							g_enemyObjs[i].DirectionPos.x = 0.0f;
							g_enemyObjs[i].DirectionPos.y = 100.0f;
						}
					}
					//������
					else if (g_enemyObjs[i].EnemyArea == 1)
					{
						//����Ɉړ�
						if (g_enemyObjs[i].pattern > 4)
						{
							g_enemyObjs[i].DirectionPos.x = -400.0f;
							g_enemyObjs[i].DirectionPos.y = 400.0f;
						}
						//�E��Ɉړ�
						else if (g_enemyObjs[i].pattern > 8)
						{
							g_enemyObjs[i].DirectionPos.x = 400.0f;
							g_enemyObjs[i].DirectionPos.y = 400.0f;
						}
						//�����Ɉړ�
						else
						{
							g_enemyObjs[i].DirectionPos.x = 0.0f;
							g_enemyObjs[i].DirectionPos.y = 100.0f;
						}

					}
					//�E��
					else if (g_enemyObjs[i].EnemyArea == 2)
					{
						//������Ɉړ�
						if (g_enemyObjs[i].pattern < 4)
						{
							g_enemyObjs[i].DirectionPos.x = 0.0f;
							g_enemyObjs[i].DirectionPos.y = 400.0f;
						}
						//�E�Ɉړ�
						else if (g_enemyObjs[i].pattern < 8)
						{
							g_enemyObjs[i].DirectionPos.x = 400.0f;
							g_enemyObjs[i].DirectionPos.y = 100.0f;
						}
						//�����Ɉړ�
						else
						{
							g_enemyObjs[i].DirectionPos.x = 0.0f;
							g_enemyObjs[i].DirectionPos.y = 100.0f;
						}
					}
					//��
					if (g_enemyObjs[i].EnemyArea == 3)
					{
						//����Ɉړ�
						if (g_enemyObjs[i].pattern < 4)
						{
							g_enemyObjs[i].DirectionPos.x = -400.0f;
							g_enemyObjs[i].DirectionPos.y = 400.0f;
						}
						//�����Ɉړ�
						else if (g_enemyObjs[i].pattern < 8)
						{
							g_enemyObjs[i].DirectionPos.x = -400.0f;
							g_enemyObjs[i].DirectionPos.y = -200.0f;
						}
						//�����Ɉړ�
						else
						{
							g_enemyObjs[i].DirectionPos.x = 0.0f;
							g_enemyObjs[i].DirectionPos.y = 100.0f;
						}
					}
					//����
					else if (g_enemyObjs[i].EnemyArea == 4)
					{
						//������Ɉړ�
						if (g_enemyObjs[i].pattern < 2)
						{
							g_enemyObjs[i].DirectionPos.x = 400.0f;
							g_enemyObjs[i].DirectionPos.y = 100.0f;
						}
						//����Ɉړ�
						else if (g_enemyObjs[i].pattern < 5)
						{
							g_enemyObjs[i].DirectionPos.x = -400.0f;
							g_enemyObjs[i].DirectionPos.y = 400.0f;
						}
						//�E��Ɉړ�
						else if (g_enemyObjs[i].pattern < 8)
						{
							g_enemyObjs[i].DirectionPos.x = 400.0f;
							g_enemyObjs[i].DirectionPos.y = 400.0f;
						}
						//�E�Ɉړ�
						else if (g_enemyObjs[i].pattern < 9)
						{
							g_enemyObjs[i].DirectionPos.x = 400.0f;
							g_enemyObjs[i].DirectionPos.y = 100.0f;
						}
						//���Ɉړ�
						else
						{
							g_enemyObjs[i].DirectionPos.x = -400.0f;
							g_enemyObjs[i].DirectionPos.y = 100.0f;
						}
					}
					//�E
					else if (g_enemyObjs[i].EnemyArea == 5)
					{
						//�E��Ɉړ�
						if (g_enemyObjs[i].pattern < 4)
						{
							g_enemyObjs[i].DirectionPos.x = 400.0f;
							g_enemyObjs[i].DirectionPos.y = 400.0f;
						}
						//�E���Ɉړ�
						if (g_enemyObjs[i].pattern < 8)
						{
							g_enemyObjs[i].DirectionPos.x = 400.0f;
							g_enemyObjs[i].DirectionPos.y = -200.0f;
						}
						//�����Ɉړ�
						else
						{
							g_enemyObjs[i].DirectionPos.x = 0.0f;
							g_enemyObjs[i].DirectionPos.y = 100.0f;
						}
					}
					//����
					if (g_enemyObjs[i].EnemyArea == 6)
					{
						//���Ɉړ�
						if (g_enemyObjs[i].pattern < 8)
						{
							g_enemyObjs[i].DirectionPos.x = -400.0f;
							g_enemyObjs[i].DirectionPos.y = 100.0f;
						}
						//�������Ɉړ�
						else
						{
							g_enemyObjs[i].DirectionPos.x = 0.0f;
							g_enemyObjs[i].DirectionPos.y = -200.0f;
						}
					}
					//������
					else if (g_enemyObjs[i].EnemyArea == 7)
					{
						//�E���Ɉړ�
						if (g_enemyObjs[i].pattern < 5)
						{
							g_enemyObjs[i].DirectionPos.x = 400.0f;
							g_enemyObjs[i].DirectionPos.y = -200.0f;
						}
						//�����Ɉړ�
						else
						{
							g_enemyObjs[i].DirectionPos.x = -400.0f;
							g_enemyObjs[i].DirectionPos.y = -200.0f;
						}
					}
					//�E��
					else if (g_enemyObjs[i].EnemyArea == 8)
					{
						//�E�Ɉړ�
						if (g_enemyObjs[i].pattern < 8)
						{
							g_enemyObjs[i].DirectionPos.x = 400.0f;
							g_enemyObjs[i].DirectionPos.y = 100.0f;
						}
						//�������Ɉړ�
						else
						{
							g_enemyObjs[i].DirectionPos.x = 0.0f;
							g_enemyObjs[i].DirectionPos.y = -200.0f;
						}
					}
					g_enemyObjs[i].flameCnt[1] = 0;
				}

				if ((g_enemyObjs[i].flameCnt[0] >= (rand() % 40) + 120) || g_enemyObjs[i].enemyPos.y < EnemyNotInWater)
				{

					//	�G�l�~�[�ƌ������_�̋������v��
					g_enemyObjs[i].PlayerDistance.x = g_enemyObjs[i].DirectionPos.x - g_enemyObjs[i].enemyPos.x;
					g_enemyObjs[i].PlayerDistance.y = g_enemyObjs[i].DirectionPos.y - g_enemyObjs[i].enemyPos.y;

					//�G�l�~�[�ƌ������_���q�����������߂�
					g_enemyObjs[i].g_pEnemyMoveLine = sqrt((g_enemyObjs[i].PlayerDistance.x * g_enemyObjs[i].PlayerDistance.x) + (g_enemyObjs[i].PlayerDistance.y * g_enemyObjs[i].PlayerDistance.y));
					//�v���C���[�ƃG�l�~�[���q�����������߂�
					g_enemyObjs[i].g_pPlayerEnemyLine = sqrt(((Playerpos.x - g_enemyObjs[i].enemyPos.x) * (Playerpos.x - g_enemyObjs[i].enemyPos.x)) + ((Playerpos.y - g_enemyObjs[i].enemyPos.y) * (Playerpos.y - g_enemyObjs[i].enemyPos.y)));

					//����������
					g_enemyObjs[i].pattern = rand() % 10;
					//�G�l�~�[�ƃv���C���[�̋��������ȉ��Ȃ�v���C���[�̍��W���擾���A�Ǐ]����
					if (g_enemyObjs[i].g_pPlayerEnemyLine <= 300.0f && g_enemyObjs[i].pattern < 3 &&
						(PlayerLanding == true && g_pPlayer[0]->getPos().y > g_enemyObjs[i].obj->getPos().y) != true)
					{
						g_enemyObjs[i].g_pEnemyMaxSpeed_X = (Playerpos.x - g_enemyObjs[i].enemyPos.x) / g_enemyObjs[i].g_pPlayerEnemyLine * g_enemyObjs[i].SpeedMagnification;
						g_enemyObjs[i].g_pEnemyMaxSpeed_Y = (Playerpos.y - g_enemyObjs[i].enemyPos.y) / g_enemyObjs[i].g_pPlayerEnemyLine * g_enemyObjs[i].SpeedMagnification;
					}
					//����ȊO�̏ꍇ�͌������_�Ɍ����đ��x���擾
					else
					{
						g_enemyObjs[i].g_pEnemyMaxSpeed_X = (g_enemyObjs[i].PlayerDistance.x / g_enemyObjs[i].g_pEnemyMoveLine * g_enemyObjs[i].SpeedMagnification);
						g_enemyObjs[i].g_pEnemyMaxSpeed_Y = (g_enemyObjs[i].PlayerDistance.y / g_enemyObjs[i].g_pEnemyMoveLine * g_enemyObjs[i].SpeedMagnification);
					}

					g_enemyObjs[i].flameCnt[0] = 0;

				}

				//�ړ�
				g_enemyObjs[i].enemyPos.x += g_enemyObjs[i].g_pEnemyFlySpeed_X;
				g_enemyObjs[i].enemyPos.y += g_enemyObjs[i].g_pEnemyFlySpeed_Y;
				g_enemyObjs[i].obj->setPos(g_enemyObjs[i].enemyPos);

				//�G�l�~�[�̃��x���ɂ���ăG�l�~�[�̃X�s�[�h�𒲐�����l���㏸������
				if (g_enemyObjs[i].EnemyLevel == 1)
				{
					g_enemyObjs[i].SpeedMagnification = 2.5;
				}
				else if (g_enemyObjs[i].EnemyLevel == 2)
				{
					g_enemyObjs[i].SpeedMagnification = 4.5;
				}

				//�f�o�b�O�p
				if (m_pDirectInput->isKeyPressed(DIK_1))
				{
					g_enemyObjs[i].EnemyLevel = 1;
				}
				if (m_pDirectInput->isKeyPressed(DIK_2))
				{
					g_enemyObjs[i].EnemyLevel = 2;
				}
			}

		}
	}
	//�G�l�~�[�̓����蔻��
	EnemyCollision();

	//�G�l�~�[�̉�ʒ[����
	procPlayMain_EnemyBothEnd();

	//�A�j���[�V����
	EnemyAnim();

}

//�֐���		�@ :procPlayMain_EnemyDispose()
//�������e		:�G�l�~�[�̔j��
//����			:�Ȃ�
//�߂�l		    :�Ȃ�
void CActionGameApp::procPlayMain_EnemyDispose()
{
	//�G�摜��j������
	for (int i = 0; i < ENEMY_OBJECT_COUNT; ++i)
	{
		//���ꂼ��� obj ���쐬����Ă���ꍇ�̂ݔj������
		if (g_enemyObjs[i].obj != NULL)
		{
			disposeSprite(g_enemyObjs[i].obj);
			g_enemyObjs[i].obj = NULL;
		}
	}
}

void CActionGameApp::procPlayMain_EnemyStatus()//�G�l�~�[�̃X�e�[�^�X
{
	//�G�̏���
	for (int i = 0; i < ENEMY_OBJECT_COUNT; ++i)
	{

		//�G�摜���쐬����Ă����珈�����s��
		if (g_enemyObjs[i].obj != NULL)
		{

			//�G�l�~�[���������̃X�e�[�^�X�̎��̋���
			if (g_enemyObjs[i].EnemyStatus == 1)
			{

				//50%�łP�C�Q�����߂�
				//�P�Ȃ�E�����A�Q�Ȃ獶����
				if (g_enemyObjs[i].EnemyCourse == 3)
				{
					g_enemyObjs[i].EnemyCourse = rand() % 2 + 1;

				}
				//�G�l�~�[�̗��������̓����_���Ō��܂�
				//�P�Ȃ�E����
				if (g_enemyObjs[i].EnemyCourse == 1)
				{
					g_enemyObjs[i].obj->setPos(g_enemyObjs[i].obj->getPos().x + g_enemyObjs[i].EnemyFallSpeed, g_enemyObjs[i].obj->getPos().y - 1.0f);


					//�����̎��Ԃ𑝂₵�Ă���
					++g_enemyObjs[i].EnemyFall;
				}

				//�G�l�~�[�̗��������̓����_���Ō��܂�
				//�Q�Ȃ獶����
				else if (g_enemyObjs[i].EnemyCourse == 2)
				{
					g_enemyObjs[i].obj->setPos(g_enemyObjs[i].obj->getPos().x - g_enemyObjs[i].EnemyFallSpeed, g_enemyObjs[i].obj->getPos().y - 1.0f);
					//�����̎��Ԃ𑝂₵�Ă���
					++g_enemyObjs[i].EnemyFall;
				}

				//�������Ԃ���萔�𒴂����Ƃ��ɁA�����̕�����ς���
				if (g_enemyObjs[i].EnemyFall > EnemyFallTime)
				{
					//�P�̏ꍇ�͂Q��
					if (g_enemyObjs[i].EnemyCourse == 1)
					{
						g_enemyObjs[i].EnemyCourse = 2;
						//�������Ԃ����Z�b�g
						g_enemyObjs[i].EnemyFall = 0;
					}
					//�Q�̏ꍇ�͂P��
					else if (g_enemyObjs[i].EnemyCourse == 2)
					{
						g_enemyObjs[i].EnemyCourse = 1;
						//�������Ԃ����Z�b�g
						g_enemyObjs[i].EnemyFall = 0;
					}
				}

				//�������x�iX��������������j
				//��������ō����x�i���ԁj�܂ł͉�������
				if (g_enemyObjs[i].EnemyFall <= EnemyFallTime / 2)
				{
					g_enemyObjs[i].EnemyFallSpeed += 0.07f;
				}

				else if (g_enemyObjs[i].EnemyFall > EnemyFallTime / 2)
				{
					g_enemyObjs[i].EnemyFallSpeed -= 0.07f;
				}



			}

			//�G�l�~�[�����n�����Ƃ��̃X�e�[�^�X
			else if (g_enemyObjs[i].EnemyStatus == 2)
			{
				if (g_enemyObjs[i].EnemyReturn_Num > rand() % 7 + 4)
				{
					BalloonReloadFlag[i] = true;
				}
				else if (BalloonReloadFlag[i] != true)
				{
					//�����Ŋ��o���J���Ăӂ������c��܂��ĕ�������
					g_enemyObjs[i].EnemyReturn_Num += 0.01666;

					g_enemyObjs[i].obj->setAnimation(0 + (g_enemyObjs[i].EnemyLevel * 18));
					g_enemyObjs[i + 1].obj->setAnimation(0 + (g_enemyObjs[i].EnemyLevel * 18));
				}
				
			}

			//�Q�[�����n�܂��čŏ��ɕ��D������鎞�Ȃ̂ŁA�����̑��������ɂȂ�悤�ɂ���
			else if (g_enemyObjs[i].EnemyStatus == 3)
			{
				if (BalloonReloadFlag[i] == false)
				{
					g_enemyObjs[i].EnemyStatus = 0;

					//���������̂Œl�����Z�b�g
					g_enemyObjs[i].EnemyReturn_Num = 0.0;
				}
			}

			else if (g_enemyObjs[i].EnemyStatus == 4)
			{
				//���ꂼ��� obj ���쐬����Ă���ꍇ�̂ݔj������
				if (g_enemyObjs[i].obj != NULL)
				{
					if (EnemyDeathFlag[i] == true)
					{
						disposeSprite(g_enemyObjs[i].obj);
						g_enemyObjs[i].obj = NULL;

						disposeSprite(g_enemyObjs[i + 1].obj);
						g_enemyObjs[i + 1].obj = NULL;
						EnemyDeathFlag[i] = false;
					}
					else
					{
						//��ʊO�ɏo��܂ŗ�������
						if (g_enemyObjs[i].obj->getPos().y < WINDOW_BOTTOM + 32.0f || g_enemyObjs[i + 1].obj->getPos().y < WINDOW_BOTTOM + 32.0f)
						{
							if (g_pWater)
							{
								disposeSound(g_pWater);
								g_pWater = NULL;
							}
							// �쐬����Ă��Ȃ���΁A�쐬
							if (!g_pWater)
							{
								// ��2�����F���[�v�ݒ�
								// ���[�v���Ȃ��̂ŁAfalse��ݒ�
								g_pWater = createSound(Water, false);
							}
							//�����Ԃ��̃A�j���[�V����
							EnteringWaterCreate(g_enemyObjs[i].obj);
							EnteringWaterCreate(g_enemyObjs[i + 1].obj);
							//�A
							BubbleCreate(g_enemyObjs[i].obj);
							BubbleCreate(g_enemyObjs[i + 1].obj);

							EnemyDeathFallFlag[i] = false;
							EnemyDeathFallFlag[i + 1] = false;
							EnemyDeathFallSpeed[i] = 3.0f;
							EnemyDeathFlag[i] = true;

							disposeSprite(g_enemyObjs[i].obj);
							g_enemyObjs[i].obj = NULL;

							disposeSprite(g_enemyObjs[i + 1].obj);
							g_enemyObjs[i + 1].obj = NULL;
						}
						//�ŏ��ɏ����㏸
						else if (EnemyDeathFallSpeed[i] > -8.0f)
						{
							g_enemyObjs[i].obj->setPos(g_enemyObjs[i].obj->getPos().x, g_enemyObjs[i].obj->getPos().y + (EnemyDeathFallSpeed[i] -= 0.2f));
							g_enemyObjs[i + 1].obj->setPos(g_enemyObjs[i].obj->getPos().x, g_enemyObjs[i].obj->getPos().y);
							EnemyDeathFallFlag[i] = true;
							EnemyDeathFallFlag[i + 1] = true;
							if (EnemyDeathFallSpeed[i] > 0.0f)
							{
								//�A�j���[�V����
								g_enemyObjs[i].obj->setAnimation(13 + (g_enemyObjs[i].EnemyLevel * 18));
								g_enemyObjs[i + 1].obj->setAnimation(13 + (g_enemyObjs[i].EnemyLevel * 18));
							}
							else
							{
								++AnimCount[AnimCountEnemy + i];
								if (AnimCount[AnimCountEnemy + i] % 7 != 0)
								{
									if (AnimCount[AnimCountEnemy + i] < 4)
									{
										g_enemyObjs[i].obj->setAnimation(13 + (g_enemyObjs[i].EnemyLevel * 18));
										g_enemyObjs[i + 1].obj->setAnimation(13 + (g_enemyObjs[i].EnemyLevel * 18));
									}
									else if (AnimCount[AnimCountEnemy + i] < 7)
									{
										g_enemyObjs[i].obj->setAnimation(14 + (g_enemyObjs[i].EnemyLevel * 18));
										g_enemyObjs[i + 1].obj->setAnimation(14 + (g_enemyObjs[i].EnemyLevel * 18));
									}
								}
								else
								{
									AnimCount[AnimCountEnemy + i] = 0;
								}
							}
						}
						//�㏸�㉺�~
						else
						{
							g_enemyObjs[i].obj->setPos(g_enemyObjs[i].obj->getPos().x, g_enemyObjs[i].obj->getPos().y + EnemyDeathFallSpeed[i]);
							g_enemyObjs[i + 1].obj->setPos(g_enemyObjs[i].obj->getPos().x, g_enemyObjs[i].obj->getPos().y);
							++AnimCount[AnimCountEnemy + i];
							if (AnimCount[AnimCountEnemy + i] % 7 != 0)
							{
								if (AnimCount[AnimCountEnemy + i] < 4)
								{
									g_enemyObjs[i].obj->setAnimation(13 + (g_enemyObjs[i].EnemyLevel * 18));
									g_enemyObjs[i + 1].obj->setAnimation(13 + (g_enemyObjs[i].EnemyLevel * 18));
								}
								else if (AnimCount[AnimCountEnemy + i] < 7)
								{
									g_enemyObjs[i].obj->setAnimation(14 + (g_enemyObjs[i].EnemyLevel * 18));
									g_enemyObjs[i + 1].obj->setAnimation(14 + (g_enemyObjs[i].EnemyLevel * 18));
								}
							}
							else
							{
								AnimCount[AnimCountEnemy + i] = 0;
							}
						}
					}
				}
			}
		}


	}

}