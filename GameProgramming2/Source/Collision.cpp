//----------------------------------------------
// �t�@�C���� �FCollision.cpp
// �T�v�@�@�@ �F�����蔻��̏���
// ��ҁ@�@�@ �F21Cu0312 �͍� �t
// �X�V���e   �F2022/03/04 21CU0312 �͍� �t �쐬
// �@�@�@�@�@ �F2022/03/04 21CU0312 �͍� �t UnderCollision()��ǉ�
//            �F2022/03/07 21CU0312 �͍� �t UnderCollision()�̂��蔲���o�O���C��
// �@�@�@�@�@ �F2022/03/07 21CU0312 �͍� �t SideCollision()�AOverCollision()��ǉ�
//            �F2022/03/08 21CU0312 �͍� �t OverCollision()�̂��蔲���o�O���C��
//------------------------------------------------

#include "CActionGameApp.h"
#include "GameResource.h"

//�����蔻��i��j
void CActionGameApp::UnderCollision(CPicture* Getg_pPicture, XMFLOAT4 GetBeforePos,int i)
{
	if(GetBeforePos.y >= Getg_pPicture->getPos().y)
	{
		//�n��
		//����
		for (int j = 0; j < Ground.Count; ++j)
		{
			if (Getg_pPicture->getPos().y > (g_pGround[j]->getPos().y + (Ground.Size_Y / 2.0f) + (100.0f / 2.0f))
				&& Getg_pPicture->collisionOffset(g_pGround[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size))
			{
				//�ʒu�𓖂��蔻��̊O���ɂ��炷
				Getg_pPicture->setPos(Getg_pPicture->getPos().x, g_pGround[j]->getPos().y + (Ground.Size_Y / 2.0f) + PLAYER_SIZE_Y / 2.0f);
				if(Getg_pPicture == g_pPlayer[0] || Getg_pPicture == g_pPlayer[1])
				{
					//������Ԃɂ���
					PlayerLanding = true;
				}
				else if (Getg_pPicture == g_enemyObjs[i].obj && g_enemyObjs[i].EnemyStatus == 1)
				{
					if (g_pSEnemyLanding)
					{
						disposeSound(g_pSEnemyLanding);
						g_pSEnemyLanding = NULL;
					}
					// �쐬����Ă��Ȃ���΁A�쐬
					if (!g_pSEnemyLanding)
					{
						// ��2�����F���[�v�ݒ�
						// ���[�v���Ȃ��̂ŁAfalse��ݒ�
						g_pSEnemyLanding = createSound(SEnemyLanding, false);
					}
					
					//������Ԃɂ���
					g_enemyObjs[i].EnemyStatus = 2;
				}
				break;
			}
		}
		//�E�[
		if (Getg_pPicture->getPos().y > (g_pRightGround->getPos().y + (RightGround.Size_Y / 2.0f) + (100.0f / 2.0f) + 4.0f)
			&& Getg_pPicture->collisionOffset(g_pRightGround, EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size))
		{
			//�ʒu�𓖂��蔻��̊O���ɂ��炷
			Getg_pPicture->setPos(Getg_pPicture->getPos().x, g_pRightGround->getPos().y + (RightGround.Size_Y / 2.0f) + PLAYER_SIZE_Y / 2.0f);
			if (Getg_pPicture == g_pPlayer[0] || Getg_pPicture == g_pPlayer[1])
			{
				//������Ԃɂ���
				PlayerLanding = true;
			}
			else if (Getg_pPicture == g_enemyObjs[i].obj && g_enemyObjs[i].EnemyStatus == 1)
			{
				if (g_pSEnemyLanding)
				{
					disposeSound(g_pSEnemyLanding);
					g_pSEnemyLanding = NULL;
				}
				// �쐬����Ă��Ȃ���΁A�쐬
				if (!g_pSEnemyLanding)
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pSEnemyLanding = createSound(SEnemyLanding, false);
				}
				//������Ԃɂ���
				g_enemyObjs[i].EnemyStatus = 2;
			}
		}
		//���[
		if (Getg_pPicture->getPos().y > (g_pLeftGround->getPos().y + (LeftGround.Size_Y / 2.0f) + (100.0f / 2.0f))
			&& Getg_pPicture->collisionOffset(g_pLeftGround, EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size))
		{
			//�ʒu�𓖂��蔻��̊O���ɂ��炷
			Getg_pPicture->setPos(Getg_pPicture->getPos().x, g_pLeftGround->getPos().y + (LeftGround.Size_Y / 2.0f) + PLAYER_SIZE_Y / 2.0f);
			if (Getg_pPicture == g_pPlayer[0] || Getg_pPicture == g_pPlayer[1])
			{
				//������Ԃɂ���
				PlayerLanding = true;
			}
			else if (Getg_pPicture == g_enemyObjs[i].obj && g_enemyObjs[i].EnemyStatus == 1)
			{
				if (g_pSEnemyLanding)
				{
					disposeSound(g_pSEnemyLanding);
					g_pSEnemyLanding = NULL;
				}
				// �쐬����Ă��Ȃ���΁A�쐬
				if (!g_pSEnemyLanding)
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pSEnemyLanding = createSound(SEnemyLanding, false);
				}
				//������Ԃɂ���
				g_enemyObjs[i].EnemyStatus = 2;
			}
		}

		//����
		//����
		for (int j = 0; j < Block.Count; ++j)
		{
			if (Getg_pPicture->getPos().y > (g_pBlock[j]->getPos().y + (Block.Size_Y / 2.0f) + (100.0f / 2.0f))
				&& Getg_pPicture->collisionOffset(g_pBlock[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
				&& g_pBlock[j] != NULL)
			{
				//�ʒu�𓖂��蔻��̊O���ɂ��炷
				Getg_pPicture->setPos(Getg_pPicture->getPos().x, g_pBlock[j]->getPos().y + (Block.Size_Y / 2.0f) + PLAYER_SIZE_Y / 2.0f);
				if (Getg_pPicture == g_pPlayer[0] || Getg_pPicture == g_pPlayer[1])
				{
					//������Ԃɂ���
					PlayerLanding = true;
				}
				else if (Getg_pPicture == g_enemyObjs[i].obj && g_enemyObjs[i].EnemyStatus == 1)
				{
					if (g_pSEnemyLanding)
					{
						disposeSound(g_pSEnemyLanding);
						g_pSEnemyLanding = NULL;
					}
					// �쐬����Ă��Ȃ���΁A�쐬
					if (!g_pSEnemyLanding)
					{
						// ��2�����F���[�v�ݒ�
						// ���[�v���Ȃ��̂ŁAfalse��ݒ�
						g_pSEnemyLanding = createSound(SEnemyLanding, false);
					}
					//������Ԃɂ���
					g_enemyObjs[i].EnemyStatus = 2;
				}
				break;
			}
		}
		//�E�[
		for (int j = 0; j < (BlockPos[PhaseNum - 1].Count + BlockBerPos[PhaseNum - 1].Count); ++j)
		{
			if (Getg_pPicture->getPos().y > (g_pRightBlock[j]->getPos().y + (RightBlock.Size_Y / 2.0f) + (100.0f / 2.0f))
				&& Getg_pPicture->collisionOffset(g_pRightBlock[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
				&& g_pRightBlock[j] != NULL)
			{
				//�ʒu�𓖂��蔻��̊O���ɂ��炷
				Getg_pPicture->setPos(Getg_pPicture->getPos().x, g_pRightBlock[j]->getPos().y + (RightBlock.Size_Y / 2.0f) + PLAYER_SIZE_Y / 2.0f);
				if (Getg_pPicture == g_pPlayer[0] || Getg_pPicture == g_pPlayer[1])
				{
					//������Ԃɂ���
					PlayerLanding = true;
				}
				else if (Getg_pPicture == g_enemyObjs[i].obj && g_enemyObjs[i].EnemyStatus == 1)
				{
					if (g_pSEnemyLanding)
					{
						disposeSound(g_pSEnemyLanding);
						g_pSEnemyLanding = NULL;
					}
					// �쐬����Ă��Ȃ���΁A�쐬
					if (!g_pSEnemyLanding)
					{
						// ��2�����F���[�v�ݒ�
						// ���[�v���Ȃ��̂ŁAfalse��ݒ�
						g_pSEnemyLanding = createSound(SEnemyLanding, false);
					}
					//������Ԃɂ���
					g_enemyObjs[i].EnemyStatus = 2;
				}
				break;
			}
		}
		//���[
		for (int j = 0; j < (BlockPos[PhaseNum - 1].Count + BlockBerPos[PhaseNum - 1].Count); ++j)
		{
			if (Getg_pPicture->getPos().y > (g_pLeftBlock[j]->getPos().y + (LeftBlock.Size_Y / 2.0f) + (100.0f / 2.0f))
				&& Getg_pPicture->collisionOffset(g_pLeftBlock[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
				&& g_pLeftBlock[j] != NULL)
			{
				//�ʒu�𓖂��蔻��̊O���ɂ��炷
				Getg_pPicture->setPos(Getg_pPicture->getPos().x, g_pLeftBlock[j]->getPos().y + (LeftBlock.Size_Y / 2.0f) + PLAYER_SIZE_Y / 2.0f);
				if (Getg_pPicture == g_pPlayer[0] || Getg_pPicture == g_pPlayer[1])
				{
					//������Ԃɂ���
					PlayerLanding = true;
				}
				else if (Getg_pPicture == g_enemyObjs[i].obj && g_enemyObjs[i].EnemyStatus == 1)
				{
					if (g_pSEnemyLanding)
					{
						disposeSound(g_pSEnemyLanding);
						g_pSEnemyLanding = NULL;
					}
					// �쐬����Ă��Ȃ���΁A�쐬
					if (!g_pSEnemyLanding)
					{
						// ��2�����F���[�v�ݒ�
						// ���[�v���Ȃ��̂ŁAfalse��ݒ�
						g_pSEnemyLanding = createSound(SEnemyLanding, false);
					}
					//������Ԃɂ���
					g_enemyObjs[i].EnemyStatus = 2;
				}
				break;
			}
		}
		//����(��)
		//���_
		for (int j = 0; j < (BlockBerPos[PhaseNum - 1].ConnectCount[0] + BlockBerPos[PhaseNum - 1].ConnectCount[1] + BlockBerPos[PhaseNum - 1].ConnectCount[2] + BlockBerPos[PhaseNum - 1].ConnectCount[3] + BlockBerPos[PhaseNum - 1].ConnectCount[4]); ++j)
		{
			if (Getg_pPicture->getPos().y > (g_pBlockBer[j]->getPos().y + (BlockBer.Size_Y / 2.0f) + (100.0f / 2.0f))
				&& Getg_pPicture->collisionOffset(g_pBlockBer[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
				&& g_pBlockBer[j] != NULL)
			{
				//�ʒu�𓖂��蔻��̊O���ɂ��炷
				Getg_pPicture->setPos(Getg_pPicture->getPos().x, g_pBlockBer[j]->getPos().y + (BlockBer.Size_Y / 2.0f) + PLAYER_SIZE_Y / 2.0f);
				if (Getg_pPicture == g_pPlayer[0] || Getg_pPicture == g_pPlayer[1])
				{
					//������Ԃɂ���
					PlayerLanding = true;
				}
				else if (Getg_pPicture == g_enemyObjs[i].obj && g_enemyObjs[i].EnemyStatus == 1)
				{
					if (g_pSEnemyLanding)
					{
						disposeSound(g_pSEnemyLanding);
						g_pSEnemyLanding = NULL;
					}
					// �쐬����Ă��Ȃ���΁A�쐬
					if (!g_pSEnemyLanding)
					{
						// ��2�����F���[�v�ݒ�
						// ���[�v���Ȃ��̂ŁAfalse��ݒ�
						g_pSEnemyLanding = createSound(SEnemyLanding, false);
					}
					//������Ԃɂ���
					g_enemyObjs[i].EnemyStatus = 2;
				}
				break;
			}
		}

		//�d�͂�������
		if (PlayerLanding == true)
		{
			Gravity = 0.0f;
			//���������u�Ԃ̉��ړ����x���ێ�
			if (g_pPlayerFlySpeed != 0.0f)
			{
				g_playerMoveSpeed = g_pPlayerFlySpeed;
				if (g_playerMoveSpeed > 0.0f)
				{
					WidthSwitch = true;
				}
				else if (g_playerMoveSpeed < 0.0f)
				{
					WidthSwitch = false;
				}
				g_pPlayerFlySpeed = 0.0f;
			}
		}
	}
}

//�����蔻��i���ʁj
void CActionGameApp::SideCollision(CPicture* Getg_pPicture, int i)
{
	//�n��
	//�E�[
	if (Getg_pPicture->getPos().y < (g_pRightGround->getPos().y + (RightGround.Size_Y / 2.0f) + (100.0f / 2.0f))
		&& Getg_pPicture->getPos().x >= (g_pRightGround->getPos().x + (RightGround.Size_X / 2.0f))
		&& Getg_pPicture->collisionOffset(g_pRightGround, EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size))
	{
		//�ʒu�𓖂��蔻��̊O���ɂ��炷
		Getg_pPicture->setPos(g_pRightGround->getPos().x + (RightGround.Size_X / 2.0f) + (40.0f / 2.0f), Getg_pPicture->getPos().y);
		//�v���C���[�̈ړ������𔽓]
		if (Getg_pPicture == g_pPlayer[0])
		{
			//�Ԃ�������
			// �쐬����Ă��Ȃ���΁A�쐬
			if (!(g_pHit))
			{
				// ��2�����F���[�v�ݒ�
				// ���[�v���Ȃ��̂ŁAfalse��ݒ�
				g_pHit = createSound(Hit, false);
			}
			g_pPlayerFlySpeed = -(g_pPlayerFlySpeed);
			if (g_pPlayerFlySpeed > 1.0f)
			{
				g_pPlayerFlySpeed -= 0.5f;
			}
			else
			{
				g_pPlayerFlySpeed = 0.5f;
			}
		}
		if (Getg_pPicture == g_enemyObjs[i].obj)
		{
			//���S���̗�����
			if (g_enemyObjs[i].EnemyStatus == 1)
			{
				//�P�̏ꍇ�͂Q��
				if (g_enemyObjs[i].EnemyCourse == 1)
				{
					g_enemyObjs[i].EnemyCourse = 2;
					//�������Ԃ����Z�b�g
					g_enemyObjs[i].EnemyFall = 0;
					g_enemyObjs[i].EnemyFallSpeed = 0;
					g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					g_enemyObjs[i+1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
				}
				//�Q�̏ꍇ�͂P��
				else if (g_enemyObjs[i].EnemyCourse == 2)
				{
					g_enemyObjs[i].EnemyCourse = 1;
					//�������Ԃ����Z�b�g
					g_enemyObjs[i].EnemyFall = 0;
					g_enemyObjs[i].EnemyFallSpeed = 0;
					g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
				}
			}
			else
			{
				g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
				g_enemyObjs[i].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
				if (g_enemyObjs[i].g_pEnemyFlySpeed_X > 1.0f)
				{
					g_enemyObjs[i].g_pEnemyFlySpeed_X -= 0.5f;
				}
				else
				{
					g_enemyObjs[i].g_pEnemyFlySpeed_X = 0.5f;
				}
			}
		}
	}
	//���[
	if (Getg_pPicture->getPos().y < (g_pLeftGround->getPos().y + (LeftGround.Size_Y / 2.0f) + (100.0f / 2.0f))
		&& Getg_pPicture->getPos().x <= (g_pLeftGround->getPos().x - (LeftGround.Size_X / 2.0f))
		&& Getg_pPicture->collisionOffset(g_pLeftGround, EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size))
	{
		//�ʒu�𓖂��蔻��̊O���ɂ��炷
		Getg_pPicture->setPos(g_pLeftGround->getPos().x - (LeftGround.Size_X / 2.0f) - (40.0f / 2.0f), Getg_pPicture->getPos().y);
		//�v���C���[�̈ړ������𔽓]
		if (Getg_pPicture == g_pPlayer[0])
		{
			//�Ԃ�������
			// �쐬����Ă��Ȃ���΁A�쐬
			if (!(g_pHit))
			{
				// ��2�����F���[�v�ݒ�
				// ���[�v���Ȃ��̂ŁAfalse��ݒ�
				g_pHit = createSound(Hit, false);
			}
			g_pPlayerFlySpeed = -(g_pPlayerFlySpeed);
			if (g_pPlayerFlySpeed < -1.0f)
			{
				g_pPlayerFlySpeed += 0.5f;
			}
			else
			{
				g_pPlayerFlySpeed = -0.5f;
			}
		}
		if (Getg_pPicture == g_enemyObjs[i].obj)
		{
			//���S���̗�����
			if (g_enemyObjs[i].EnemyStatus == 1)
			{
				//�P�̏ꍇ�͂Q��
				if (g_enemyObjs[i].EnemyCourse == 1)
				{
					g_enemyObjs[i].EnemyCourse = 2;
					//�������Ԃ����Z�b�g
					g_enemyObjs[i].EnemyFall = 0;
					g_enemyObjs[i].EnemyFallSpeed = 0;
					g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
				}
				//�Q�̏ꍇ�͂P��
				else if (g_enemyObjs[i].EnemyCourse == 2)
				{
					g_enemyObjs[i].EnemyCourse = 1;
					//�������Ԃ����Z�b�g
					g_enemyObjs[i].EnemyFall = 0;
					g_enemyObjs[i].EnemyFallSpeed = 0;
					g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
				}
			}
			else
			{
				g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
				g_enemyObjs[i].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
				if (g_enemyObjs[i].g_pEnemyFlySpeed_X < 1.0f)
				{
					g_enemyObjs[i].g_pEnemyFlySpeed_X += 0.5f;
				}
				else
				{
					g_enemyObjs[i].g_pEnemyFlySpeed_X = -0.5f;
				}
			}
		}
	}

	//������
	//�E�[
	for (int j = 0; j < (BlockPos[PhaseNum - 1].Count + BlockBerPos[PhaseNum - 1].Count); ++j)
	{
		//�ʒu�𓖂��蔻��̊O���ɂ��炷
		if (Getg_pPicture->getPos().y - 16.0f > (g_pRightBlock[j]->getPos().y - (RightBlock.Size_Y / 2.0f) - (96.0f / 2.0f))
			&& Getg_pPicture->getPos().y < (g_pRightBlock[j]->getPos().y + (RightBlock.Size_Y / 2.0f) + (100.0f / 2.0f))
			&& Getg_pPicture->getPos().x >= (g_pRightBlock[j]->getPos().x + (RightBlock.Size_X / 2.0f))
			&& Getg_pPicture->collisionOffset(g_pRightBlock[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
			&& g_pRightBlock[j] != NULL)
		{
			//�ʒu�𓖂��蔻��̊O���ɂ��炷
			Getg_pPicture->setPos(g_pRightBlock[j]->getPos().x + (RightBlock.Size_X / 2.0f) + (40.0f / 2.0f), Getg_pPicture->getPos().y);
			//�v���C���[�̈ړ������𔽓]
			if (Getg_pPicture == g_pPlayer[0])
			{
				//�Ԃ�������
			// �쐬����Ă��Ȃ���΁A�쐬
				if (!(g_pHit))
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pHit = createSound(Hit, false);
				}
				g_pPlayerFlySpeed = -(g_pPlayerFlySpeed);
				if (g_pPlayerFlySpeed > 1.0f)
				{
					g_pPlayerFlySpeed -= 0.5f;
				}
				else
				{
					g_pPlayerFlySpeed = 0.5f;
				}
			}
			if (Getg_pPicture == g_enemyObjs[i].obj)
			{
				//���S���̗�����
				if (g_enemyObjs[i].EnemyStatus == 1)
				{
					//�P�̏ꍇ�͂Q��
					if (g_enemyObjs[i].EnemyCourse == 1)
					{
						g_enemyObjs[i].EnemyCourse = 2;
						//�������Ԃ����Z�b�g
						g_enemyObjs[i].EnemyFall = 0;
						g_enemyObjs[i].EnemyFallSpeed = 0;
						g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					}
					//�Q�̏ꍇ�͂P��
					else if (g_enemyObjs[i].EnemyCourse == 2)
					{
						g_enemyObjs[i].EnemyCourse = 1;
						//�������Ԃ����Z�b�g
						g_enemyObjs[i].EnemyFall = 0;
						g_enemyObjs[i].EnemyFallSpeed = 0;
						g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					}
				}
				else
				{
					g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
					g_enemyObjs[i].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
					if (g_enemyObjs[i].g_pEnemyFlySpeed_X > 1.0f)
					{
						g_enemyObjs[i].g_pEnemyFlySpeed_X -= 0.5f;
					}
					else
					{
						g_enemyObjs[i].g_pEnemyFlySpeed_X = 0.5f;
					}
				}
			}
			break;
		}
	}
	//���[
	for (int j = 0; j < (BlockPos[PhaseNum - 1].Count + BlockBerPos[PhaseNum - 1].Count); ++j)
	{
		//�ʒu�𓖂��蔻��̊O���ɂ��炷
		if (Getg_pPicture->getPos().y - 16.0f > (g_pLeftBlock[j]->getPos().y - (LeftBlock.Size_Y / 2.0f) - (96.0f / 2.0f))
			&& Getg_pPicture->getPos().y < (g_pLeftBlock[j]->getPos().y + (LeftBlock.Size_Y / 2.0f) + (100.0f / 2.0f))
			&& Getg_pPicture->getPos().x <= (g_pLeftBlock[j]->getPos().x - (LeftBlock.Size_X / 2.0f))
			&& Getg_pPicture->collisionOffset(g_pLeftBlock[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
			&& g_pLeftBlock[j] != NULL)
		{
			Getg_pPicture->setPos(g_pLeftBlock[j]->getPos().x - (LeftBlock.Size_X / 2.0f) - (40.0f / 2.0f), Getg_pPicture->getPos().y);
			//�v���C���[�̈ړ������𔽓]
			if (Getg_pPicture == g_pPlayer[0])
			{
				//�Ԃ�������
			// �쐬����Ă��Ȃ���΁A�쐬
				if (!(g_pHit))
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pHit = createSound(Hit, false);
				}
				g_pPlayerFlySpeed = -(g_pPlayerFlySpeed);
				if (g_pPlayerFlySpeed < -1.0f)
				{
					g_pPlayerFlySpeed += 0.5f;
				}
				else
				{
					g_pPlayerFlySpeed = -0.5f;
				}
			}
			if (Getg_pPicture == g_enemyObjs[i].obj)
			{
				//���S���̗�����
				if (g_enemyObjs[i].EnemyStatus == 1)
				{
					//�P�̏ꍇ�͂Q��
					if (g_enemyObjs[i].EnemyCourse == 1)
					{
						g_enemyObjs[i].EnemyCourse = 2;
						//�������Ԃ����Z�b�g
						g_enemyObjs[i].EnemyFall = 0;
						g_enemyObjs[i].EnemyFallSpeed = 0;
						g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					}
					//�Q�̏ꍇ�͂P��
					else if (g_enemyObjs[i].EnemyCourse == 2)
					{
						g_enemyObjs[i].EnemyCourse = 1;
						//�������Ԃ����Z�b�g
						g_enemyObjs[i].EnemyFall = 0;
						g_enemyObjs[i].EnemyFallSpeed = 0;
						g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					}
				}
				else
				{
					g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
					g_enemyObjs[i].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
					if (g_enemyObjs[i].g_pEnemyFlySpeed_X < 1.0f)
					{
						g_enemyObjs[i].g_pEnemyFlySpeed_X += 0.5f;
					}
					else
					{
						g_enemyObjs[i].g_pEnemyFlySpeed_X = -0.5f;
					}
				}
			}
			break;
		}
	}
	//��(�E)
	for (int j = 0; j < (BlockBerPos[PhaseNum - 1].ConnectCount[0] + BlockBerPos[PhaseNum - 1].ConnectCount[1] + BlockBerPos[PhaseNum - 1].ConnectCount[2] + BlockBerPos[PhaseNum - 1].ConnectCount[3] + BlockBerPos[PhaseNum - 1].ConnectCount[4]); ++j)
	{
		//�ʒu�𓖂��蔻��̊O���ɂ��炷
		if (Getg_pPicture->getPos().y - 16.0f > (g_pBlockBer[j]->getPos().y - (BlockBer.Size_Y / 2.0f) - (96.0f / 2.0f))
			&& Getg_pPicture->getPos().y < (g_pBlockBer[j]->getPos().y + (BlockBer.Size_Y / 2.0f) + (100.0f / 2.0f))
			&& Getg_pPicture->getPos().x >= (g_pBlockBer[j]->getPos().x + (BlockBer.Size_X / 2.0f))
			&& Getg_pPicture->collisionOffset(g_pBlockBer[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
			&& g_pBlockBer[j] != NULL)
		{
			//�ʒu�𓖂��蔻��̊O���ɂ��炷
			Getg_pPicture->setPos(g_pBlockBer[j]->getPos().x + (BlockBer.Size_X / 2.0f) + (40.0f / 2.0f), Getg_pPicture->getPos().y);
			//�v���C���[�̈ړ������𔽓]
			if (Getg_pPicture == g_pPlayer[0])
			{
				//�Ԃ�������
				// �쐬����Ă��Ȃ���΁A�쐬
				if (!(g_pHit))
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pHit = createSound(Hit, false);
				}
				g_pPlayerFlySpeed = -(g_pPlayerFlySpeed);
				if (g_pPlayerFlySpeed > 1.0f)
				{
					g_pPlayerFlySpeed -= 0.5f;
				}
				else
				{
					g_pPlayerFlySpeed = 0.5f;
				}
			}
			if (Getg_pPicture == g_enemyObjs[i].obj)
			{
				//���S���̗�����
				if (g_enemyObjs[i].EnemyStatus == 1)
				{
					//�P�̏ꍇ�͂Q��
					if (g_enemyObjs[i].EnemyCourse == 1)
					{
						g_enemyObjs[i].EnemyCourse = 2;
						//�������Ԃ����Z�b�g
						g_enemyObjs[i].EnemyFall = 0;
						g_enemyObjs[i].EnemyFallSpeed = 0;
						g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					}
					//�Q�̏ꍇ�͂P��
					else if (g_enemyObjs[i].EnemyCourse == 2)
					{
						g_enemyObjs[i].EnemyCourse = 1;
						//�������Ԃ����Z�b�g
						g_enemyObjs[i].EnemyFall = 0;
						g_enemyObjs[i].EnemyFallSpeed = 0;
						g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					}
				}
				else
				{
					g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
					g_enemyObjs[i].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
					if (g_enemyObjs[i].g_pEnemyFlySpeed_X > 1.0f)
					{
						g_enemyObjs[i].g_pEnemyFlySpeed_X -= 0.5f;
					}
					else
					{
						g_enemyObjs[i].g_pEnemyFlySpeed_X = 0.5f;
					}
				}
			}
			break;
		}
	}
	//��(��)
	for (int j = 0; j < (BlockBerPos[PhaseNum - 1].ConnectCount[0] + BlockBerPos[PhaseNum - 1].ConnectCount[1] + BlockBerPos[PhaseNum - 1].ConnectCount[2] + BlockBerPos[PhaseNum - 1].ConnectCount[3] + BlockBerPos[PhaseNum - 1].ConnectCount[4]); ++j)
	{
		//�ʒu�𓖂��蔻��̊O���ɂ��炷
		if (Getg_pPicture->getPos().y - 16.0f > (g_pBlockBer[j]->getPos().y - (BlockBer.Size_Y / 2.0f) - (96.0f / 2.0f))
			&& Getg_pPicture->getPos().y < (g_pBlockBer[j]->getPos().y + (BlockBer.Size_Y / 2.0f) + (100.0f / 2.0f))
			&& Getg_pPicture->getPos().x <= (g_pBlockBer[j]->getPos().x - (BlockBer.Size_X / 2.0f))
			&& Getg_pPicture->collisionOffset(g_pBlockBer[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
			&& g_pBlockBer[j] != NULL)
		{
			Getg_pPicture->setPos(g_pBlockBer[j]->getPos().x - (BlockBer.Size_X / 2.0f) - (40.0f / 2.0f), Getg_pPicture->getPos().y);
			//�v���C���[�̈ړ������𔽓]
			if (Getg_pPicture == g_pPlayer[0])
			{
				//�Ԃ�������
				// �쐬����Ă��Ȃ���΁A�쐬
				if (!(g_pHit))
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pHit = createSound(Hit, false);
				}
				g_pPlayerFlySpeed = -(g_pPlayerFlySpeed);
				if (g_pPlayerFlySpeed < -1.0f)
				{
					g_pPlayerFlySpeed += 0.5f;
				}
				else
				{
					g_pPlayerFlySpeed = -0.5f;
				}
			}
			if (Getg_pPicture == g_enemyObjs[i].obj)
			{
				//���S���̗�����
				if (g_enemyObjs[i].EnemyStatus == 1)
				{
					//�P�̏ꍇ�͂Q��
					if (g_enemyObjs[i].EnemyCourse == 1)
					{
						g_enemyObjs[i].EnemyCourse = 2;
						//�������Ԃ����Z�b�g
						g_enemyObjs[i].EnemyFall = 0;
						g_enemyObjs[i].EnemyFallSpeed = 0;
						g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					}
					//�Q�̏ꍇ�͂P��
					else if (g_enemyObjs[i].EnemyCourse == 2)
					{
						g_enemyObjs[i].EnemyCourse = 1;
						//�������Ԃ����Z�b�g
						g_enemyObjs[i].EnemyFall = 0;
						g_enemyObjs[i].EnemyFallSpeed = 0;
						g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					}
				}
				else
				{
					g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
					g_enemyObjs[i].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
					if (g_enemyObjs[i].g_pEnemyFlySpeed_X < 1.0f)
					{
						g_enemyObjs[i].g_pEnemyFlySpeed_X += 0.5f;
					}
					else
					{
						g_enemyObjs[i].g_pEnemyFlySpeed_X = -0.5f;
					}
				}
			}
			break;
		}
	}

	//�g(���[)
	//�E�[
	if (Getg_pPicture->getPos().y < (g_pEndWave[1]->getPos().y + (EndWave.Size_Y / 2.0f) + (100.0f / 2.0f))
		&& Getg_pPicture->getPos().x >= (g_pEndWave[1]->getPos().x + (EndWave.Size_X / 2.0f))
		&& Getg_pPicture->collisionOffset(g_pEndWave[1], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
		&& g_pEndWave[1] != NULL)
	{
		//�ʒu�𓖂��蔻��̊O���ɂ��炷
		Getg_pPicture->setPos(g_pEndWave[1]->getPos().x + (EndWave.Size_X / 2.0f) + (40.0f / 2.0f), Getg_pPicture->getPos().y);
		//�v���C���[�̈ړ������𔽓]
		if (Getg_pPicture == g_pPlayer[0])
		{
			//�Ԃ�������
			// �쐬����Ă��Ȃ���΁A�쐬
			if (!(g_pHit))
			{
				// ��2�����F���[�v�ݒ�
				// ���[�v���Ȃ��̂ŁAfalse��ݒ�
				g_pHit = createSound(Hit, false);
			}
			g_pPlayerFlySpeed = -(g_pPlayerFlySpeed);
			if (g_pPlayerFlySpeed > 1.0f)
			{
				g_pPlayerFlySpeed -= 0.5f;
			}
			else
			{
				g_pPlayerFlySpeed = 0.5f;
			}
		}
		if (Getg_pPicture == g_enemyObjs[i].obj)
		{
			//���S���̗�����
			if (g_enemyObjs[i].EnemyStatus == 1)
			{
				//�P�̏ꍇ�͂Q��
				if (g_enemyObjs[i].EnemyCourse == 1)
				{
					g_enemyObjs[i].EnemyCourse = 2;
					//�������Ԃ����Z�b�g
					g_enemyObjs[i].EnemyFall = 0;
					g_enemyObjs[i].EnemyFallSpeed = 0;
					g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
				}
				//�Q�̏ꍇ�͂P��
				else if (g_enemyObjs[i].EnemyCourse == 2)
				{
					g_enemyObjs[i].EnemyCourse = 1;
					//�������Ԃ����Z�b�g
					g_enemyObjs[i].EnemyFall = 0;
					g_enemyObjs[i].EnemyFallSpeed = 0;
					g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
				}
			}
			else
			{
				g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
				g_enemyObjs[i].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
				if (g_enemyObjs[i].g_pEnemyFlySpeed_X > 1.0f)
				{
					g_enemyObjs[i].g_pEnemyFlySpeed_X -= 0.5f;
				}
				else
				{
					g_enemyObjs[i].g_pEnemyFlySpeed_X = 0.5f;
				}
			}
		}
	}
	//���[
	if (Getg_pPicture->getPos().y < (g_pEndWave[2]->getPos().y + (EndWave.Size_Y / 2.0f) + (100.0f / 2.0f))
		&& Getg_pPicture->getPos().x <= (g_pEndWave[3]->getPos().x - (EndWave.Size_X / 2.0f))
		&& Getg_pPicture->collisionOffset(g_pEndWave[3], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
		&& g_pEndWave[3] != NULL)
	{
		//�ʒu�𓖂��蔻��̊O���ɂ��炷
		Getg_pPicture->setPos(g_pEndWave[3]->getPos().x - (EndWave.Size_X / 2.0f) - (40.0f / 2.0f), Getg_pPicture->getPos().y);
		//�v���C���[�̈ړ������𔽓]
		if (Getg_pPicture == g_pPlayer[0])
		{
			//�Ԃ�������
			// �쐬����Ă��Ȃ���΁A�쐬
			if (!(g_pHit))
			{
				// ��2�����F���[�v�ݒ�
				// ���[�v���Ȃ��̂ŁAfalse��ݒ�
				g_pHit = createSound(Hit, false);
			}
			g_pPlayerFlySpeed = -(g_pPlayerFlySpeed);
			if (g_pPlayerFlySpeed < -1.0f)
			{
				g_pPlayerFlySpeed += 0.5f;
			}
			else
			{
				g_pPlayerFlySpeed = -0.5f;
			}
		}
		if (Getg_pPicture == g_enemyObjs[i].obj)
		{
			//���S���̗�����
			if (g_enemyObjs[i].EnemyStatus == 1)
			{
				//�P�̏ꍇ�͂Q��
				if (g_enemyObjs[i].EnemyCourse == 1)
				{
					g_enemyObjs[i].EnemyCourse = 2;
					//�������Ԃ����Z�b�g
					g_enemyObjs[i].EnemyFall = 0;
					g_enemyObjs[i].EnemyFallSpeed = 0;
					g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
				}
				//�Q�̏ꍇ�͂P��
				else if (g_enemyObjs[i].EnemyCourse == 2)
				{
					g_enemyObjs[i].EnemyCourse = 1;
					//�������Ԃ����Z�b�g
					g_enemyObjs[i].EnemyFall = 0;
					g_enemyObjs[i].EnemyFallSpeed = 0;
					g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
					g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
				}
			}
			else
			{
				g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
				g_enemyObjs[i].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
				if (g_enemyObjs[i].g_pEnemyFlySpeed_X < 1.0f)
				{
					g_enemyObjs[i].g_pEnemyFlySpeed_X += 0.5f;
				}
				else
				{
					g_enemyObjs[i].g_pEnemyFlySpeed_X = -0.5f;
				}
			}
		}

	}
}

//�����蔻��i��j
void CActionGameApp::OverCollision(CPicture* Getg_pPicture, int i)
{
	//����
	//����
 	for (int j = 0; j < Block.Count; ++j)
	{

		if (Getg_pPicture->getPos().y - 16.0f < (g_pBlock[j]->getPos().y - (Block.Size_Y / 2.0f) - (100.0f / 2.0f) + 16.0f)
			&& Getg_pPicture->collisionOffset(g_pBlock[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
			&& g_pBlock[j] != NULL)
		{
			//�ʒu�𓖂��蔻��̊O���ɂ��炷
			Getg_pPicture->setPos(Getg_pPicture->getPos().x, g_pBlock[j]->getPos().y - (Block.Size_Y / 2.0f) - (100.0f / 2.0f) + 16.0);
			//�v���C���[�̈ړ������𔽓]
			if (Getg_pPicture == g_pPlayer[0] && Gravity < 0.0f)
			{
				//�Ԃ�������
				// �쐬����Ă��Ȃ���΁A�쐬
				if (!(g_pHit))
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pHit = createSound(Hit, false);
				}
				Gravity = -(Gravity);
			}
			if (Getg_pPicture == g_enemyObjs[i].obj)
			{
				g_enemyObjs[i].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
				g_enemyObjs[i].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
			}
			break;
		}
	}
	//���[
	for (int j = 0; j < (BlockPos[PhaseNum - 1].Count + BlockBerPos[PhaseNum - 1].Count); ++j)
	{
		if (Getg_pPicture->getPos().y - 16.0f < (g_pLeftBlock[j]->getPos().y - (LeftBlock.Size_Y / 2.0f) - (100.0f / 2.0f) + 16.0f)
			&& Getg_pPicture->collisionOffset(g_pLeftBlock[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
			&& g_pLeftBlock[j] != NULL)
		{
			//�ʒu�𓖂��蔻��̊O���ɂ��炷
			Getg_pPicture->setPos(Getg_pPicture->getPos().x, g_pLeftBlock[j]->getPos().y - (LeftBlock.Size_Y / 2.0f) - (100.0f / 2.0f) + 16.0);
			//�v���C���[�̈ړ������𔽓]
			if (Getg_pPicture == g_pPlayer[0] && Gravity < 0.0f)
			{
				//�Ԃ�������
				// �쐬����Ă��Ȃ���΁A�쐬
				if (!(g_pHit))
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pHit = createSound(Hit, false);
				}
				Gravity = -(Gravity);
			}
			if (Getg_pPicture == g_enemyObjs[i].obj)
			{
				g_enemyObjs[i].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
				g_enemyObjs[i].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
			}
			break;
		}
	}
	//�E�[
	for (int j = 0; j < (BlockPos[PhaseNum - 1].Count + BlockBerPos[PhaseNum - 1].Count); ++j)
	{
		if (Getg_pPicture->getPos().y - 16.0f < (g_pRightBlock[j]->getPos().y - (RightBlock.Size_Y / 2.0f) - (100.0f / 2.0f) + 16.0f)
			&& Getg_pPicture->collisionOffset(g_pRightBlock[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
			&& g_pBlock[j] != NULL)
		{
			//�ʒu�𓖂��蔻��̊O���ɂ��炷
			Getg_pPicture->setPos(Getg_pPicture->getPos().x, g_pRightBlock[j]->getPos().y - (RightBlock.Size_Y / 2.0f) - (100.0f / 2.0f) + 16.0);
			//�v���C���[�̈ړ������𔽓]
			if (Getg_pPicture == g_pPlayer[0] && Gravity < 0.0f)
			{
				//�Ԃ�������
				// �쐬����Ă��Ȃ���΁A�쐬
				if (!(g_pHit))
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pHit = createSound(Hit, false);
				}
				Gravity = -(Gravity);
			}
			if (Getg_pPicture == g_enemyObjs[i].obj)
			{
				g_enemyObjs[i].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
				g_enemyObjs[i].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
			}
			break;
		}
	}

	//����
	//����
	for (int j = 0; j < (BlockBerPos[PhaseNum - 1].ConnectCount[0] + BlockBerPos[PhaseNum - 1].ConnectCount[1] + BlockBerPos[PhaseNum - 1].ConnectCount[2] + BlockBerPos[PhaseNum - 1].ConnectCount[3] + BlockBerPos[PhaseNum - 1].ConnectCount[4]); ++j)
	{

		if (Getg_pPicture->getPos().y - 16.0f < (g_pBlockBer[j]->getPos().y - (Block.Size_Y / 2.0f) - (100.0f / 2.0f) + 16.0f)
			&& Getg_pPicture->collisionOffset(g_pBlockBer[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size)
			&& g_pBlockBer[j] != NULL)
		{
			//�ʒu�𓖂��蔻��̊O���ɂ��炷
			Getg_pPicture->setPos(Getg_pPicture->getPos().x, g_pBlockBer[j]->getPos().y - (BlockBer.Size_Y / 2.0f) - (100.0f / 2.0f) + 16.0);
			//�v���C���[�̈ړ������𔽓]
			if (Getg_pPicture == g_pPlayer[0] && Gravity < 0.0f)
			{
				//�Ԃ�������
				// �쐬����Ă��Ȃ���΁A�쐬
				if (!(g_pHit))
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pHit = createSound(Hit, false);
				}
				Gravity = -(Gravity);
			}
			if (Getg_pPicture == g_enemyObjs[i].obj)
			{
				g_enemyObjs[i].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
				g_enemyObjs[i].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
			}
			break;
		}
	}

	//��ʂ̏�[
	if (Getg_pPicture->getPos().y - 16.0f >= WINDOW_TOP - (84.0f / 2.0f) - 16.0f)
	{
		//�ʒu�𓖂��蔻��̊O���ɂ��炷
		Getg_pPicture->setPos(Getg_pPicture->getPos().x, WINDOW_TOP - (52.0f / 2.0f) - 16.0f);
		//�v���C���[�̈ړ������𔽓]
		if (Getg_pPicture == g_pPlayer[0] && Gravity < 0.0f)
		{
			//�Ԃ�������
			// �쐬����Ă��Ȃ���΁A�쐬
			if (!(g_pHit))
			{
				// ��2�����F���[�v�ݒ�
				// ���[�v���Ȃ��̂ŁAfalse��ݒ�
				g_pHit = createSound(Hit, false);
			}
			Gravity = -(Gravity);
		}
		if (Getg_pPicture == g_enemyObjs[i].obj)
		{
			g_enemyObjs[i].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
			g_enemyObjs[i].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
		}
	}
}

//�G���e�B�e�B���m�̓����蔻��
void CActionGameApp::EntityCplision(CPicture* My, CPicture* Target,int i,int j)
{
	if (My->collisionOffset(Target, EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size) &&
		Target->collisionOffset(My, EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size))
	{
		//�����������肪�v���C���[�������ꍇ
		if (Target == g_pPlayer[j] )
		{
			//���D�̓����蔻��
			//��
			if (My->getPos().y - 6.0f < Target->getPos().y - 26.0f &&
				g_enemyObjs[i].EnemyStatus != 2 && g_enemyObjs[i].EnemyStatus != 3)
			{
				if (g_enemyObjs[i].EnemyStatus == 1)
				{
					//�X�R�A���Z
					ScoreSet(1 + (g_enemyObjs[i].EnemyLevel * 3));
					AddScoreSet(g_enemyObjs[i].obj, 1 + (g_enemyObjs[i].EnemyLevel * 3));

					g_enemyObjs[i].EnemyStatus = 4;
					g_pPlayer[j]->setPos(Target->getPos().x, Target->getPos().y + 4.0f);
					Gravity = -(Gravity / 1.5f);
					g_pPlayerFlySpeed = -(g_pPlayerFlySpeed);
					//�G�l�~�[���S��
					// �쐬����Ă��Ȃ���΁A�쐬
					if (g_pEnemyDeath)
					{
						disposeSound(g_pEnemyDeath);
						g_pEnemyDeath = NULL;
					}
					if (!g_pEnemyDeath)
					{
						// ��2�����F���[�v�ݒ�
						// ���[�v���Ȃ��̂ŁAfalse��ݒ�
						g_pEnemyDeath = createSound(EnemyDeath, false);
					}
				}
				else
				{
					//�X�R�A���Z
					ScoreSet(0 + (g_enemyObjs[i].EnemyLevel * 3));
					AddScoreSet(g_enemyObjs[i].obj, 0 + (g_enemyObjs[i].EnemyLevel * 3));

					g_enemyObjs[i].EnemyStatus = 1;
					EnemyFallAnimFlag[i] = true;
					//���D�����ꂽ��
					// �쐬����Ă��Ȃ���΁A�쐬
					if (g_pBalloonBom)
					{
						disposeSound(g_pBalloonBom);
						g_pBalloonBom = NULL;
					}
					if (!g_pBalloonBom)
					{
						// ��2�����F���[�v�ݒ�
						// ���[�v���Ȃ��̂ŁAfalse��ݒ�
						g_pBalloonBom = createSound(BalloonBom, false);
					}
				}
			}
			
			//����i�v���C���[�j
			if (Target->getPos().y - 6.0f < My->getPos().y - 26.0f &&
				g_enemyObjs[i].EnemyStatus == 0)
			{
				//���D�����ꂽ��
				// �쐬����Ă��Ȃ���΁A�쐬
				if (g_pBalloonBom)
				{
					disposeSound(g_pBalloonBom);
					g_pBalloonBom = NULL;
				}
				if (!g_pBalloonBom)
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pBalloonBom = createSound(BalloonBom, false);
				}
				if (BalloonCount > 1)
				{
					--BalloonCount;
				}
				else
				{
					DeathFlag = true;
				}
			}

			//�㑤�̓����蔻��
			if (My->getPos().y + 16.0f < Target->getPos().y - (PLAYER_SIZE_Y / 2.0f))
			{
				//��
				g_enemyObjs[i].obj->setPos(My->getPos().x, My->getPos().y - 4.0f);
				if (g_enemyObjs[i].enemyVer == 0)
				{
					//�������̓G�l�~�[�̎��S����
					if (g_enemyObjs[i].EnemyStatus == 2 || g_enemyObjs[i].EnemyStatus == 3)
					{
						//�X�R�A���Z
						ScoreSet(2 + (g_enemyObjs[i].EnemyLevel * 3));
						AddScoreSet(g_enemyObjs[i].obj, 2 + (g_enemyObjs[i].EnemyLevel * 3));

						g_enemyObjs[i].EnemyStatus = 4;
						//�G�l�~�[���S��
						// �쐬����Ă��Ȃ���΁A�쐬
						if (g_pEnemyDeath)
						{
							disposeSound(g_pEnemyDeath);
							g_pEnemyDeath = NULL;
						}
						if (!g_pEnemyDeath)
						{
							// ��2�����F���[�v�ݒ�
							// ���[�v���Ȃ��̂ŁAfalse��ݒ�
							g_pEnemyDeath = createSound(EnemyDeath, false);
						}
					}
					else
					{
						g_enemyObjs[i].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
						g_enemyObjs[i].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
					}
				}
				else
				{
					g_enemyObjs[i - 1].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
					g_enemyObjs[i - 1].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
				}
				if (g_enemyObjs[i].EnemyStatus != 4)
				{
					//����
					g_pPlayer[j]->setPos(Target->getPos().x, Target->getPos().y + 4.0f);
					Gravity = -(Gravity / 1.5f);
				}
			}
			//�����̓����蔻��
			else if (My->getPos().y - (PLAYER_SIZE_Y / 2.0f) > Target->getPos().y + 16.0f)
			{
				//��
				g_enemyObjs[i].obj->setPos(My->getPos().x, My->getPos().y + 4.0f);
				if (g_enemyObjs[i].enemyVer == 0)
				{
					//�������̓G�l�~�[�̎��S����
					if (g_enemyObjs[i].EnemyStatus == 2 || g_enemyObjs[i].EnemyStatus == 3)
					{
						//�X�R�A���Z
						ScoreSet(2 + (g_enemyObjs[i].EnemyLevel * 3));
						AddScoreSet(g_enemyObjs[i].obj, 2 + (g_enemyObjs[i].EnemyLevel * 3));

						g_enemyObjs[i].EnemyStatus = 4;
						//�G�l�~�[���S��
						// �쐬����Ă��Ȃ���΁A�쐬
						if (g_pEnemyDeath)
						{
							disposeSound(g_pEnemyDeath);
							g_pEnemyDeath = NULL;
						}
						if (!g_pEnemyDeath)
						{
							// ��2�����F���[�v�ݒ�
							// ���[�v���Ȃ��̂ŁAfalse��ݒ�
							g_pEnemyDeath = createSound(EnemyDeath, false);
						}
					}
					else
					{
						g_enemyObjs[i].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
						g_enemyObjs[i].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
					}
				}
				else
				{
					g_enemyObjs[i - 1].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
					g_enemyObjs[i - 1].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
				}
				
				if (g_enemyObjs[i].EnemyStatus != 4)
				{
					//����
					g_pPlayer[j]->setPos(Target->getPos().x, Target->getPos().y - 4.0f);
					Gravity = -(Gravity / 1.5f);
				}
			}
			//�E���̓����蔻��
			if (My->getPos().x< Target->getPos().x - (PLAYER_SIZE_X / 2.0f))
			{
				//��
				g_enemyObjs[i].obj->setPos(My->getPos().x - 4.0f, My->getPos().y);
				if (g_enemyObjs[i].enemyVer == 0)
				{
					//�������̓G�l�~�[�̎��S����
					if (g_enemyObjs[i].EnemyStatus == 2 || g_enemyObjs[i].EnemyStatus == 3)
					{
						//�X�R�A���Z
						ScoreSet(2 + (g_enemyObjs[i].EnemyLevel * 3));
						AddScoreSet(g_enemyObjs[i].obj, 2 + (g_enemyObjs[i].EnemyLevel * 3));

						g_enemyObjs[i].EnemyStatus = 4;
						//�G�l�~�[���S��
						// �쐬����Ă��Ȃ���΁A�쐬
						if (g_pEnemyDeath)
						{
							disposeSound(g_pEnemyDeath);
							g_pEnemyDeath = NULL;
						}
						if (!g_pEnemyDeath)
						{
							// ��2�����F���[�v�ݒ�
							// ���[�v���Ȃ��̂ŁAfalse��ݒ�
							g_pEnemyDeath = createSound(EnemyDeath, false);
						}
					}
					//���S���̗�����
					else if (g_enemyObjs[i].EnemyStatus == 1)
					{
						//�P�̏ꍇ�͂Q��
						if (g_enemyObjs[i].EnemyCourse == 1)
						{
							g_enemyObjs[i].EnemyCourse = 2;
							//�������Ԃ����Z�b�g
							g_enemyObjs[i].EnemyFall = 0;
							g_enemyObjs[i].EnemyFallSpeed = 0;
							g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
							g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						}
						//�Q�̏ꍇ�͂P��
						else if (g_enemyObjs[i].EnemyCourse == 2)
						{
							g_enemyObjs[i].EnemyCourse = 1;
							//�������Ԃ����Z�b�g
							g_enemyObjs[i].EnemyFall = 0;
							g_enemyObjs[i].EnemyFallSpeed = 0;
							g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
							g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						}
					}
					else
					{
						g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
						g_enemyObjs[i].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
					}
				}
				else
				{
					g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
					g_enemyObjs[i - 1].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
				}
				if (g_enemyObjs[i].EnemyStatus != 4)
				{
					//����
					g_pPlayer[j]->setPos(Target->getPos().x + 4.0f, Target->getPos().y);
					g_pPlayerFlySpeed = -(g_pPlayerFlySpeed);
					g_playerMoveSpeed = -(g_playerMoveSpeed);
				}
			}
			//�����̓����蔻��
			else if (My->getPos().x> Target->getPos().x + (PLAYER_SIZE_X / 2.0f))
			{
				//��
				g_enemyObjs[i].obj->setPos(My->getPos().x + 4.0f, My->getPos().y);
				if (g_enemyObjs[i].enemyVer == 0)
				{
					//�������̓G�l�~�[�̎��S����
					if (g_enemyObjs[i].EnemyStatus == 2 || g_enemyObjs[i].EnemyStatus == 3)
					{
						//�X�R�A���Z
						ScoreSet(2 + (g_enemyObjs[i].EnemyLevel * 3));
						AddScoreSet(g_enemyObjs[i].obj, 2 + (g_enemyObjs[i].EnemyLevel * 3));

						g_enemyObjs[i].EnemyStatus = 4;
						//�G�l�~�[���S��
						// �쐬����Ă��Ȃ���΁A�쐬
						if (g_pEnemyDeath)
						{
							disposeSound(g_pEnemyDeath);
							g_pEnemyDeath = NULL;
						}
						if (!g_pEnemyDeath)
						{
							// ��2�����F���[�v�ݒ�
							// ���[�v���Ȃ��̂ŁAfalse��ݒ�
							g_pEnemyDeath = createSound(EnemyDeath, false);
						}
					}
					//���S���̗�����
					else if (g_enemyObjs[i].EnemyStatus == 1)
					{
						//�P�̏ꍇ�͂Q��
						if (g_enemyObjs[i].EnemyCourse == 1)
						{
							g_enemyObjs[i].EnemyCourse = 2;
							//�������Ԃ����Z�b�g
							g_enemyObjs[i].EnemyFall = 0;
							g_enemyObjs[i].EnemyFallSpeed = 0;
							g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
							g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						}
						//�Q�̏ꍇ�͂P��
						else if (g_enemyObjs[i].EnemyCourse == 2)
						{
							g_enemyObjs[i].EnemyCourse = 1;
							//�������Ԃ����Z�b�g
							g_enemyObjs[i].EnemyFall = 0;
							g_enemyObjs[i].EnemyFallSpeed = 0;
							g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
							g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						}
					}
					else
					{
						g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
						g_enemyObjs[i].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
					}
				}
				else
				{
					g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
					g_enemyObjs[i - 1].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
				}
				if (g_enemyObjs[i].EnemyStatus != 4)
				{
					//����
					g_pPlayer[j]->setPos(Target->getPos().x - 4.0f, Target->getPos().y);
					g_pPlayerFlySpeed = -(g_pPlayerFlySpeed);
					g_playerMoveSpeed = -(g_playerMoveSpeed);
				}
			}
		}

		//�����������肪�G�l�~�[�������ꍇ
		else if (Target == g_enemyObjs[j].obj)
		{
			//�㑤�̓����蔻��
			if (My->getPos().y + 16.0f < Target->getPos().y - (PLAYER_SIZE_Y / 2.0f))
			{
				//��
				g_enemyObjs[i].obj->setPos(My->getPos().x, My->getPos().y - 4.0f);
				if (g_enemyObjs[i].enemyVer == 0)
				{
					g_enemyObjs[i].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
					g_enemyObjs[i].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
				}
				else
				{
					g_enemyObjs[i - 1].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
					g_enemyObjs[i - 1].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
				}
				//����
				g_enemyObjs[j].obj->setPos(Target->getPos().x, Target->getPos().y + 4.0f);
				if (g_enemyObjs[j].enemyVer == 0)
				{
					g_enemyObjs[j].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
					g_enemyObjs[j].g_pEnemyFlySpeed_Y = -(g_enemyObjs[j].g_pEnemyFlySpeed_Y);
				}
				else
				{
					g_enemyObjs[j - 1].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
					g_enemyObjs[j - 1].g_pEnemyFlySpeed_Y = -(g_enemyObjs[j].g_pEnemyFlySpeed_Y);
				}
			}
			//�����̓����蔻��
			else if (My->getPos().y - (PLAYER_SIZE_Y / 2.0f) > Target->getPos().y + 16.0f)
			{
				//��
				if (g_enemyObjs[i].enemyVer == 0)
				{
					g_enemyObjs[i].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
					g_enemyObjs[i].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
				}
				else
				{
					g_enemyObjs[i - 1].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
					g_enemyObjs[i - 1].g_pEnemyFlySpeed_Y = -(g_enemyObjs[i].g_pEnemyFlySpeed_Y);
				}
				g_enemyObjs[i].obj->setPos(My->getPos().x, My->getPos().y + 4.0f);
				//����
				if (g_enemyObjs[j].enemyVer == 0)
				{
					g_enemyObjs[j].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
					g_enemyObjs[j].g_pEnemyFlySpeed_Y = -(g_enemyObjs[j].g_pEnemyFlySpeed_Y);
				}
				else
				{
					g_enemyObjs[j - 1].g_pEnemyMaxSpeed_Y = -(g_enemyObjs[i].g_pEnemyMaxSpeed_Y);
					g_enemyObjs[j - 1].g_pEnemyFlySpeed_Y = -(g_enemyObjs[j].g_pEnemyFlySpeed_Y);
				}
				g_enemyObjs[j].obj->setPos(Target->getPos().x, Target->getPos().y - 4.0f);
			}
			//�E���̓����蔻��
			if (My->getPos().x < Target->getPos().x - (PLAYER_SIZE_X / 2.0f))
			{
				//��
				g_enemyObjs[i].obj->setPos(My->getPos().x - 4.0f, My->getPos().y);
				if (g_enemyObjs[i].enemyVer == 0)
				{
					//���S���̗�����
					if (g_enemyObjs[i].EnemyStatus == 1)
					{
						//�P�̏ꍇ�͂Q��
						if (g_enemyObjs[i].EnemyCourse == 1)
						{
							g_enemyObjs[i].EnemyCourse = 2;
							//�������Ԃ����Z�b�g
							g_enemyObjs[i].EnemyFall = 0;
							g_enemyObjs[i].EnemyFallSpeed = 0;
							g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
							g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						}
						//�Q�̏ꍇ�͂P��
						else if (g_enemyObjs[i].EnemyCourse == 2)
						{
							g_enemyObjs[i].EnemyCourse = 1;
							//�������Ԃ����Z�b�g
							g_enemyObjs[i].EnemyFall = 0;
							g_enemyObjs[i].EnemyFallSpeed = 0;
							g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
							g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						}
					}
					else
					{
						g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
						g_enemyObjs[i].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
					}
				}
				else
				{
					g_enemyObjs[i - 1].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
					g_enemyObjs[i - 1].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
				}
				//����
				g_enemyObjs[j].obj->setPos(Target->getPos().x + 4.0f, Target->getPos().y);
				if (g_enemyObjs[j].enemyVer == 0)
				{
					//���S���̗�����
					if (g_enemyObjs[j].EnemyStatus == 1)
					{
						//�P�̏ꍇ�͂Q��
						if (g_enemyObjs[j].EnemyCourse == 1)
						{
							g_enemyObjs[j].EnemyCourse = 2;
							//�������Ԃ����Z�b�g
							g_enemyObjs[j].EnemyFall = 0;
							g_enemyObjs[j].EnemyFallSpeed = 0;
							g_enemyObjs[j].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
							g_enemyObjs[j + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						}
						//�Q�̏ꍇ�͂P��
						else if (g_enemyObjs[j].EnemyCourse == 2)
						{
							g_enemyObjs[j].EnemyCourse = 1;
							//�������Ԃ����Z�b�g
							g_enemyObjs[j].EnemyFall = 0;
							g_enemyObjs[j].EnemyFallSpeed = 0;
							g_enemyObjs[j].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
							g_enemyObjs[j + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						}
					}
					else
					{
						g_enemyObjs[j].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
						g_enemyObjs[j].g_pEnemyFlySpeed_X = -(g_enemyObjs[j].g_pEnemyFlySpeed_X);
					}
				}
				else
				{
					g_enemyObjs[j - 1].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
					g_enemyObjs[j - 1].g_pEnemyFlySpeed_X = -(g_enemyObjs[j].g_pEnemyFlySpeed_X);
				}
			}
			//�����̓����蔻��
			else if (My->getPos().x > Target->getPos().x + (PLAYER_SIZE_X / 2.0f))
			{
				//��
				if (g_enemyObjs[i].enemyVer == 0)
				{
					//���S���̗�����
					if (g_enemyObjs[i].EnemyStatus == 1)
					{
						//�P�̏ꍇ�͂Q��
						if (g_enemyObjs[i].EnemyCourse == 1)
						{
							g_enemyObjs[i].EnemyCourse = 2;
							//�������Ԃ����Z�b�g
							g_enemyObjs[i].EnemyFall = 0;
							g_enemyObjs[i].EnemyFallSpeed = 0;
							g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
							g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						}
						//�Q�̏ꍇ�͂P��
						else if (g_enemyObjs[i].EnemyCourse == 2)
						{
							g_enemyObjs[i].EnemyCourse = 1;
							//�������Ԃ����Z�b�g
							g_enemyObjs[i].EnemyFall = 0;
							g_enemyObjs[i].EnemyFallSpeed = 0;
							g_enemyObjs[i].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
							g_enemyObjs[i + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						}
					}
					else
					{
						g_enemyObjs[i].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
						g_enemyObjs[i].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
					}
				}
				else
				{
					g_enemyObjs[i - 1].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
					g_enemyObjs[i - 1].g_pEnemyFlySpeed_X = -(g_enemyObjs[i].g_pEnemyFlySpeed_X);
				}
				g_enemyObjs[i].obj->setPos(My->getPos().x + 4.0f, My->getPos().y);
				//����
				if (g_enemyObjs[j].enemyVer == 0)
				{
					//���S���̗�����
					if (g_enemyObjs[j].EnemyStatus == 1)
					{
						//�P�̏ꍇ�͂Q��
						if (g_enemyObjs[j].EnemyCourse == 1)
						{
							g_enemyObjs[j].EnemyCourse = 2;
							//�������Ԃ����Z�b�g
							g_enemyObjs[j].EnemyFall = 0;
							g_enemyObjs[j].EnemyFallSpeed = 0;
							g_enemyObjs[j].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
							g_enemyObjs[j + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						}
						//�Q�̏ꍇ�͂P��
						else if (g_enemyObjs[j].EnemyCourse == 2)
						{
							g_enemyObjs[j].EnemyCourse = 1;
							//�������Ԃ����Z�b�g
							g_enemyObjs[j].EnemyFall = 0;
							g_enemyObjs[j].EnemyFallSpeed = 0;
							g_enemyObjs[j].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
							g_enemyObjs[j + 1].obj->addAngle(XMFLOAT3(0.0f, 180.0f, 0.0f));
						}
					}
					else
					{
						g_enemyObjs[j].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
						g_enemyObjs[j].g_pEnemyFlySpeed_X = -(g_enemyObjs[j].g_pEnemyFlySpeed_X);
					}
				}
				else
				{
					g_enemyObjs[j - 1].g_pEnemyMaxSpeed_X = -(g_enemyObjs[i].g_pEnemyMaxSpeed_X);
					g_enemyObjs[j - 1].g_pEnemyFlySpeed_X = -(g_enemyObjs[j].g_pEnemyFlySpeed_X);
				}
				g_enemyObjs[j].obj->setPos(Target->getPos().x - 4.0f, Target->getPos().y);
			}
		}
	}
}

//�v���C���[�̓����蔻�菈���̂܂Ƃ�
void CActionGameApp::PlayerCollision()
{
	for (int i = 0; i < 2; i++)
	{
		if (((g_pPlayer[i]->getPos().x < WINDOW_RIGHT && g_pPlayer[i]->getPos().x > WINDOW_LEFT) && g_pPlayer[i]->getPos().y > -200.0f) || g_pPlayer[i]->getPos().y <= -200.0f)
		{
			//��ʉ��ɏo�����̔���
			if (g_pPlayer[i]->getPos().y <= -(WINDOW_WIDTH / 2.0f))
			{
				//�����Ԃ��̃A�j���[�V����
				if (g_pPlayer[i]->getPos().x < WINDOW_RIGHT && g_pPlayer[i]->getPos().x > WINDOW_LEFT)
				{
					//�����Ԃ��̃A�j���[�V����
					EnteringWaterCreate(g_pPlayer[i]);
					DeathStatusSet();
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
				}
			}
			
			PlayerLanding = false;
			//�v���C���[�̑Ώە��ɑ΂��铖���蔻��
			SideCollision(g_pPlayer[i], i);     //(����)
			UnderCollision(g_pPlayer[i], XMFLOAT4(0.0f, BeforePlayerPos[i].y, 0.0f, 0.0f), i);    //(��)
			OverCollision(g_pPlayer[i], i);     //(��)

			//�v���C���[�̍ŏI�ʒu��ۑ�
			BeforePlayerPos[i].y = g_pPlayer[i]->getPos().y;
		}
	}
}


//�G�l�~�[�̓����蔻�菈���̂܂Ƃ�
void CActionGameApp::EnemyCollision()
{
	for (int i = 0; i < ENEMY_OBJECT_COUNT; i++)
	{
		if (((g_enemyObjs[i].enemyVer == 0 && g_enemyObjs[i].NowEdge != true) || g_enemyObjs[i].NowEdge == true) &&
			g_enemyObjs[i].obj != NULL && EnemyDeathFallFlag[i] != true && EnemyDeathFallFlag[i + 1] != true)
		{
			//��ʉ��ɏo�����̔���
			if (g_enemyObjs[i].obj->getPos().y <= -(WINDOW_WIDTH / 2.0f))
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
				break;
			}

			//�G���e�B�e�B���m�̓����蔻��
			if (g_pPlayer[0] != NULL && DeathFlag != true && DeathThunderFlag != true &&
				CollisionFlag == true && g_pPlayer[0]->getActive() == true && DeathCoolFlag != true)
			{
				EntityCplision(g_enemyObjs[i].obj, g_pPlayer[0], i, 0);
			}
			for (int j = i + 1; j < ENEMY_OBJECT_COUNT; ++j)
			{
				if (g_enemyObjs[j].obj != NULL &&
					g_enemyObjs[i].EnemyStatus != 2 && g_enemyObjs[j].EnemyStatus != 2 &&
					g_enemyObjs[i].EnemyStatus != 4 && g_enemyObjs[j].EnemyStatus != 4)
				{
					EntityCplision(g_enemyObjs[i].obj, g_enemyObjs[j].obj, i, j);
				}
			}

			//�G�l�~�[�̑Ώە��ɑ΂��铖���蔻��
			SideCollision(g_enemyObjs[i].obj, i);     //(����)
			UnderCollision(g_enemyObjs[i].obj, XMFLOAT4(0.0f, BeforeEnemyPos[i].y, 0.0f, 0.0f), i);    //(��)
			OverCollision(g_enemyObjs[i].obj, i);     //(��)

			//Enemy�̍ŏI�ʒu��ۑ�
			BeforeEnemyPos[i].y = g_enemyObjs[i].obj->getPos().y;
		}
	}

	//�G�l�~�[�̃X�e�[�^�X�ύX
	procPlayMain_EnemyStatus();
	
	
}


//�{�[�i�X�X�e�[�W�̓����蔻��
void CActionGameApp::BonusCollision()
{
	for (int i = 0; i < 2; i++)
	{
		PlayerLanding = false;
		//UnderCollision(g_pPlayer[i], XMFLOAT4(0.0f, BeforePlayerPos[i].y, 0.0f, 0.0f), i);    //(��)
		//OverCollision(g_pPlayer[i], i);     //(��)
		if (BeforePlayerPos[i].y >= g_pPlayer[i]->getPos().y)
		{
			//�n�ʂ̓����蔻��
			for (int j = 0; j < BGround.Count; ++j)
			{
				if (g_pBGround[j] != NULL)
				{
					if (g_pPlayer[i]->getPos().y > (g_pBGround[j]->getPos().y + (BGround.Size_Y / 2.0f) + (100.0f / 2.0f))
						&& g_pPlayer[i]->collisionOffset(g_pBGround[j], EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size))
					{
						//�ʒu�𓖂��蔻��̊O���ɂ��炷
						g_pPlayer[i]->setPos(g_pPlayer[i]->getPos().x, g_pBGround[j]->getPos().y + (BGround.Size_Y / 2.0f) + PLAYER_SIZE_Y / 2.0f);
						//������Ԃɂ���
						PlayerLanding = true;
						break;
					}
				}
			}
		}
		if (g_pPlayer[i]->getPos().y - 16.0f >= WINDOW_TOP - (84.0f / 2.0f) - 16.0f)
		{
			//�ʒu�𓖂��蔻��̊O���ɂ��炷
			g_pPlayer[i]->setPos(g_pPlayer[i]->getPos().x, WINDOW_TOP - (52.0f / 2.0f) - 16.0f);
			//�v���C���[�̈ړ������𔽓]
			if (Gravity < 0.0f)
			{
				//�Ԃ�������
				// �쐬����Ă��Ȃ���΁A�쐬
				if (!(g_pHit))
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pHit = createSound(Hit, false);
				}
				Gravity = -(Gravity);
			}
		}

		//�d�͂�������
		if (PlayerLanding == true)
		{
			Gravity = 0.0f;
			//���������u�Ԃ̉��ړ����x���ێ�
			if (g_pPlayerFlySpeed != 0.0f)
			{
				g_playerMoveSpeed = g_pPlayerFlySpeed;
				if (g_playerMoveSpeed > 0.0f)
				{
					WidthSwitch = true;
				}
				else if (g_playerMoveSpeed < 0.0f)
				{
					WidthSwitch = false;
				}
				g_pPlayerFlySpeed = 0.0f;
			}
		}
		//�v���C���[�̍ŏI�ʒu��ۑ�
		BeforePlayerPos[i].y = g_pPlayer[i]->getPos().y;
	}
}

void CActionGameApp::BBalloonCollision()
{
	for (int j = 0; j < 20; ++j)
	{
		if (g_pBalloon[j].Obj != NULL)
		{
			for (int i = 0; i < Pipe.Count; ++i)
			{
				if (g_pBalloon[j].Obj->collision(g_pPipe[i]))
				{
					g_pBalloon[j].inPipe = true;
					break;
				}
				else
				{
					g_pBalloon[j].inPipe = false;
				}
			}
			if (g_pBalloon[j].inPipe == false)
			{
				//50%�łP�C�Q�����߂�
						//�P�Ȃ�E�����A�Q�Ȃ獶����
				if (g_pBalloon[j].BalloonCourse == 3)
				{
					g_pBalloon[j].BalloonCourse = rand() % 2 + 1;
					//���D�̈ړ��ʂ������_���Ō��߂�
					g_pBalloon[j].BalloonMove = (float(rand() % 100 + 50) / 100.0f);
				}
			}
			for (int i = 0; i < 2; ++i)
			{
				//���D�ƃv���C���[���ڐG�����Ƃ�
				if (g_pPlayer[i]->collisionOffset(g_pBalloon[j].Obj, EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size) && g_pBalloon[j].inPipe == false && g_pBalloon[j].HIt != true)
				{
					//�ڐG�����o���[����j������
 					g_pBalloon[j].HIt = true;
					//���������D�̐���+1����
					BreakBallonCnt++;
					break;
				}
			}
		}

	}
}