#include "CActionGameApp.h"
#include "GameResource.h"



//�{�[�i�X�X�e�[�W�̃��C������
void CActionGameApp::BonusStage()
{

	for (int i = 0; i < 2; i++)
	{
		//�v���C���[�̑���
		if (g_pPlayer[i] != NULL && DeathFishFlag == false &&
			g_pPlayer[i]->getActive() == true)
		{
			//�v���C���[�̈ړ����x
			procPlayMain_movePlayer();
		}
	}

	//��ʒ[�̏���
	procPlayMain_BothEnds();

	BBackrender();

	//UI�̕`��
	UIrender();

	//���D
	// �ݒu
	balloonSet();
	//�����蔻��
	BBalloonCollision();
	BalloonAnim();
	for (int i = 0; i < BALLOON_OBJECT_COUNT; ++i)
	{
		//�쐬����Ă����珈�����s��
		if (g_pBalloon[i].Obj != NULL)
		{
			/*g_pBallon->setPos(g_pBallon->getPos().x, g_pBallon->getPos().y + 3.0f);*/


			//���̈ړ�����
			if (g_pBalloon[i].BalloonCourse == 1)
			{
				if (-(g_pBalloon[i].BalloonMove) < g_pBalloon[i].BalloonSpeed)
				{
					g_pBalloon[i].BalloonSpeed -= 0.07;
				}
				else
				{
					g_pBalloon[i].BalloonCourse = 2;
				}
				g_pBalloon[i].Obj->setPos(g_pBalloon[i].Obj->getPos().x + g_pBalloon[i].BalloonSpeed, g_pBalloon[i].Obj->getPos().y + 2.5f);
			}
			//�E�̈ړ�����
			else if (g_pBalloon[i].BalloonCourse == 2)
			{
				if (g_pBalloon[i].BalloonMove > g_pBalloon[i].BalloonSpeed)
				{
					g_pBalloon[i].BalloonSpeed += 0.07;
				}
				else
				{
					g_pBalloon[i].BalloonCourse = 1;
				}
				g_pBalloon[i].Obj->setPos(g_pBalloon[i].Obj->getPos().x + g_pBalloon[i].BalloonSpeed, g_pBalloon[i].Obj->getPos().y + 2.5f);
			}
			//�y�ǂ̒�
			else if(g_pBalloon[i].BalloonCourse == 3)
			{
				g_pBalloon[i].Obj->setPos(g_pBalloon[i].Obj->getPos().x, g_pBalloon[i].Obj->getPos().y + 2.5f);
			}
		}
	}
	//�`��
	for (int i = 0; i < 20; ++i)
	{
		if (g_pBalloon[i].Obj != NULL)
		{
			renderSprite(g_pBalloon[i].Obj);
		}

	}


	//�I�u�W�F�N�g�`��
	BObjrender();

	//�v���C���[�摜���쐬����Ă�����`�悷��
	//�v���C���[�̉摜�͍ŏ���0�����쐬�A�\������
	if (DeathFlag != true && DeathFishFlag != true && DeathCoolFlag != true)
	{
		for (int i = 0; i < 2; i++)
		{
			if (g_pPlayer[i] != NULL)
			{
				renderSprite(g_pPlayer[i]);
			}
		}
	}
}
