//�v���C���[�̏���
//21CU0207_�C�k
#include "CActionGameApp.h"
#include "GameResource.h"

//�֐���		:procPlayMain_movePlayer()
//�������e		:�v���C���[�̈ړ�����
//����			:�Ȃ�
//�߂�l		:�Ȃ�
void CActionGameApp::procPlayMain_movePlayer()
{
	//���S���ȊO
	if (DeathFlag != true && DeathThunderFlag != true)
	{
		//�v���C���[�̈ړ�
	/*for (int i = 0; i < 2; i++)
	{
		XMFLOAT4 pos = g_pPlayer[i]->getPos();
	}*/

		XMFLOAT4 pos0 = g_pPlayer[0]->getPos();
		XMFLOAT4 pos1 = g_pPlayer[1]->getPos();

		//�v���C���[���n�ʂɂ���Ƃ��̉��ړ��̏���
		if (PlayerLanding == true)
		{
			//�E�Ɉړ����鎞
			if (m_pDirectInput->isKeyPressed(DIK_RIGHTARROW))
			{
				//�i�X�Ƒ��x���グ��
				if (g_playerMoveSpeed <= 2.6f)
				{
					g_playerMoveSpeed += 0.1f;
				}
				pos0.x += g_playerMoveSpeed;
				pos1.x += g_playerMoveSpeed;

				MoveAnim = true;

				WidthSwitch = true;
				if (DeathCoolFlag == true)
				{
					DeathCoolFlag = false;
				}
			}

			//���Ɉړ����鎞
			else if (m_pDirectInput->isKeyPressed(DIK_LEFTARROW))
			{
				//�i�X�Ƒ��x���グ��
				if (g_playerMoveSpeed >= -2.6f)
				{
					g_playerMoveSpeed -= 0.1f;
				}
				pos0.x += g_playerMoveSpeed;
				pos1.x += g_playerMoveSpeed;

				MoveAnim = true;

				WidthSwitch = false;
				if (DeathCoolFlag == true)
				{
					DeathCoolFlag = false;
				}
			}



			//�~�܂������ɏ��X��
			else
			{

				//�E�ړ����Ă��鎞
				if (WidthSwitch == true)
				{
					if (g_playerMoveSpeed > 0.0f)
					{
						g_playerMoveSpeed -= 0.1f;
						pos0.x += g_playerMoveSpeed;
						pos1.x += g_playerMoveSpeed;
						MoveAnim = false;
					}
					else
					{
						g_playerMoveSpeed = 0.0f;
					}
				}
				//���ړ����Ă��鎞
				else if (WidthSwitch != true)
				{
					if (g_playerMoveSpeed < 0.0f)
					{
						g_playerMoveSpeed += 0.1f;
						pos0.x += g_playerMoveSpeed;
						pos1.x += g_playerMoveSpeed;

						MoveAnim = false;
					}
					else
					{
						g_playerMoveSpeed = 0.0f;
					}
				}
			}
			for (int i = 0; i < 2; i++)
			{
				g_pPlayer[i]->setPos(pos0);
			}

		}

		//�d�͂�ǉ� �󒆂ɂ���Ԃ͏�����������������悤�ɂ���
		if (PlayerLanding != true)
		{
			if (Gravity <= 4.0f)
			{
				Gravity += 0.03f;

				/*g_pJumpRise -= 0.1f;*/
			}
			pos0.y -= Gravity;
			pos1.y -= Gravity;
		}

		//�X�y�[�X�L�[�������ꂽ��W�����v����
		if (m_pDirectInput->isPressedOnce(DIK_SPACE))
		{
			if (g_pJumpRise <= g_pMaxRise)
			{
				g_pJumpPower += 0.002f;
				g_pJumpRise += g_pJumpPower;
			}

			if (Gravity > -3.0f)
			{
				Gravity -= 0.5f;

			}

			pos0.y += g_pJumpRise;
			pos1.y += g_pJumpRise;

			for (int i = 0; i < 2; i++)
			{
				g_pPlayer[i]->setPos(pos0);
			}

			if (JumpCount < 2)
			{
				++JumpCount;
			}
			if (DeathCoolFlag == true)
			{
				DeathCoolFlag = false;
			}
		}

		//�󒆂ł̌����Ă����
		if (PlayerLanding == false)
		{
			//�E�Ɉړ����鎞
			if (m_pDirectInput->isPressedOnce(DIK_RIGHTARROW))
			{
				WidthSwitch = true;
			}

			//���Ɉړ����鎞
			else if (m_pDirectInput->isPressedOnce(DIK_LEFTARROW))
			{
				WidthSwitch = false;
			}
		}


		//�󒆈ړ�
		if (PlayerLanding == false)
		{
			//���������u�Ԃ̉��ړ����x���ێ�
			if (g_playerMoveSpeed != 0.0f)
			{
				g_pPlayerFlySpeed = g_playerMoveSpeed;
				g_playerMoveSpeed = 0.0f;
			}
			//�E�Ɉړ����鎞
			if (m_pDirectInput->isPressedOnce(DIK_RIGHTARROW) && m_pDirectInput->isKeyPressed(DIK_SPACE)
				|| m_pDirectInput->isKeyTrigger(DIK_RIGHTARROW) && m_pDirectInput->isPressedOnce(DIK_SPACE))
			{
				//�i�X�Ƒ��x���グ��
				if (g_pPlayerFlySpeed < 3.0f)
				{
					g_pPlayerFlySpeed += 0.5f;
				}
				else
				{
					g_pPlayerFlySpeed = 3.0f;
				}
				FlameCnt = 0;
			}

			//���Ɉړ����鎞
			else if (m_pDirectInput->isPressedOnce(DIK_LEFTARROW) && m_pDirectInput->isKeyPressed(DIK_SPACE)
				|| m_pDirectInput->isKeyTrigger(DIK_LEFTARROW) && m_pDirectInput->isPressedOnce(DIK_SPACE))
			{
				//�i�X�Ƒ��x���グ��
				if (g_pPlayerFlySpeed > -3.0f)
				{
					g_pPlayerFlySpeed -= 0.5f;
				}
				else
				{
					g_pPlayerFlySpeed = -3.0f;
				}
				FlameCnt = 0;
			}

			pos0.x += g_pPlayerFlySpeed;
			pos1.x += g_pPlayerFlySpeed;

			for (int i = 0; i < 2; i++)
			{
				g_pPlayer[i]->setPos(pos0);
			}
		}

		//���삪�Ȃ��ꍇ�Ag_playerMoveSpeed��0�ɖ߂��Ă���
		if (PlayerLanding != true)
		{
			g_playerMoveSpeed = 0.0f;
		}




		//------------------------------------------------
		//�v���C���[�̓����蔻��̏���
		if (BonusON == true)
		{
			BonusCollision();
		}
		else
		{
			PlayerCollision();
		}

		//------------------------------------------------

	}
	//���S��
	else if(DeathFlag == true)
	{
	//��ʊO�ɏo��܂ŗ�������
		if (g_pPlayer[0]->getPos().y < WINDOW_BOTTOM + 32.0f || g_pPlayer[1]->getPos().y < WINDOW_BOTTOM + 32.0f)
		{
			if (g_pWater)
			{
				disposeSound(g_pWater);
				g_pWater = NULL;
			}
			if (g_pFall)
			{
				disposeSound(g_pFall);
				g_pFall = NULL;
			}
			// �쐬����Ă��Ȃ���΁A�쐬
			if (!g_pWater)
			{
				// ��2�����F���[�v�ݒ�
				// ���[�v���Ȃ��̂ŁAfalse��ݒ�
				g_pWater = createSound(Water, false);
			}
				//�����Ԃ��̃A�j���[�V����
				EnteringWaterCreate(g_pPlayer[0]);
				EnteringWaterCreate(g_pPlayer[1]);

				DeathStatusSet();
		}
		//�ŏ��ɏ����㏸
		else if (g_pPlayer[0]->getPos().y < BeforePlayerPos->y + 32.0f && DeathFallFlag != true)
		{
			// �쐬����Ă��Ȃ���΁A�쐬
			if (!g_pFall)
			{
				// ��2�����F���[�v�ݒ�
				// ���[�v���Ȃ��̂ŁAfalse��ݒ�
				g_pFall = createSound(Fall, false);
			}
			g_playerMoveSpeed = 2.0f;
		}
		//�㏸�㉺�~
		else if (g_playerMoveSpeed >= -6.0f)
		{
			// �쐬����Ă��Ȃ���΁A�쐬
			if (!g_pFall)
			{
				// ��2�����F���[�v�ݒ�
				// ���[�v���Ȃ��̂ŁAfalse��ݒ�
				g_pFall = createSound(Fall, false);
			}
			g_playerMoveSpeed -= 0.1f;
			DeathFallFlag = true;
		}
		g_pPlayer[0]->setPos(g_pPlayer[0]->getPos().x, g_pPlayer[0]->getPos().y + g_playerMoveSpeed);
		g_pPlayer[1]->setPos(g_pPlayer[0]->getPos().x, g_pPlayer[0]->getPos().y);
	}

	if (DeathCoolFlag != true)
	{
		//�v���C���[�̃A�j���[�V����
		PlayerAnim();
	}
}

//�֐���		:procPlayMain_BothEnds()
//�������e		:��ʒ[�̏���
//����			:�Ȃ�
//�߂�l		:�Ȃ�
void CActionGameApp::procPlayMain_BothEnds()
{
	for (int i = 0; i < 2; i++)
	{
		//���[�ɍs������
		if (g_pPlayer[i]->getPos().x < -400.0f)
		{
			
			
			//�v���C���[�O����ʒ[�ɂ�������
			if (PlayerNum == 0)
			{
				g_pPlayer[1]->setPos(g_pPlayer[0]->getPos().x + 1024.0f, g_pPlayer[0]->getPos().y);
				//���C���̃v���C���[�͂P�ɂȂ�
				PlayerNum = 1;
			}
			//�v���C���[�P����ʒ[�ɂ�������
			else if (PlayerNum == 1)
			{
				g_pPlayer[0]->setPos(g_pPlayer[1]->getPos().x + 1024.0f, g_pPlayer[0]->getPos().y);
				//���C���̃v���C���[�͂P�ɂȂ�
				PlayerNum = 1;

			}
		}

		//�E�[�ɍs������
		if (g_pPlayer[i]->getPos().x > 400.0f)
		{
			
			//�v���C���[�O����ʒ[�ɂ�������
			if (PlayerNum == 0)
			{
				g_pPlayer[1]->setPos(g_pPlayer[0]->getPos().x - 1024.0f, g_pPlayer[0]->getPos().y);
				//���C���̃v���C���[�͂P�ɂȂ�
				PlayerNum = 1;
			}
			//�v���C���[�P����ʒ[�ɂ�������
			else if (PlayerNum == 1)
			{
				g_pPlayer[0]->setPos(g_pPlayer[1]->getPos().x - 1024.0f, g_pPlayer[0]->getPos().y);
				//���C���̃v���C���[�͂P�ɂȂ�
				PlayerNum = 1;

			}
		}
	}
	

	
}