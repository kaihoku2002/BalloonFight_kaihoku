//----------------------------------------------------------
// �t�@�C����		�FThunder.cpp
// �T�v				�F���Ɨ��̒e�𐧌䂷��֐��̒�`
// �쐬��			�F21CU0136 ���{����
// �X�V���e			�F2022/03/10 21CU0136 ���{�@�e�̑��x�����X�ɑ�������悤�����cThunderBall0Pos(),ThunderBall1Pos()
//					  2022/03/15 21CU0136 ���{  ���Ԃ̕␳�����ύX�cCnt��Phase
//					  2022/03/16 21CU0136 ���{  �v���C���[�Ƃ̓����蔻��������cThunderBallCollision()�AThunderBall()�������ύX
// 					  2022/03/17 21CU0136 ���{  �u���b�N�Ƃ̓����蔻�蒲���cThunderBallCollision()
//  				  2022/03/18 21CU0136 ���{  �{�[�����������ύX�cThunder(),ThunderBallCollision(),ThunderBall0Pos(),ThunderBall1Pos()
//  				  2022/03/18 21CU0136 ���{  �u���b�N�Ƃ̓����蔻�蒲���cThunderBallCollision()
//----------------------------------------------------------

#include "CActionGameApp.h"
#include "GameResource.h"
#include <time.h>
#include <stdlib.h>

/*
 * ���̏������s���֐�
 */
void CActionGameApp::Thunder()
{

	//�����^�C�~���O�̏���
	++g_ThunderObj.ThunderTime;
	if (g_ThunderObj.ThunderTime == 29.5 * 60.0 && g_ThunderObj.Phase == 0 && g_ThunderObj.Cnt < 2)
	{
		CloudThunderRand = rand() % 2;
		//�A�j���[�V�����t���O���I���ɂ���
		g_ThunderObj.AnimFlag = true;
	}
	//�P���ڂ̔��˃^�C�~���O
	if (g_ThunderObj.ThunderTime == 30 * 60 && g_ThunderObj.Phase == 0 && g_ThunderObj.Cnt < 2)
	{
		//�A�j���[�V�����t���O���I�t�ɂ���
		g_ThunderObj.AnimFlag = false;
		//�t���O��ݒ�
		g_ThunderObj.flag = g_ThunderObj.flag | 0b0001;

		//���̃t�F�[�Y���J�E���g
		g_ThunderObj.Phase = 1;
		//�����J�E���g
		++g_ThunderObj.Cnt;

		//���Ԃ̃��Z�b�g
		g_ThunderObj.ThunderTime = 0;

		//���W�̐ݒ�
		ThunderPos();
	}
	//�P���ڂ̃t���O���I���ɂȂ����痋���݂���悤�ɂ���
	if (g_ThunderObj.flag & 0b0001)
	{
		//����\��
		g_ThunderObj.obj->setActive(true);
		//������܂ł̎��Ԃ��v��
		++g_ThunderObj.DisThunder;
	}

	//�Q���ڈȍ~�̔��˃^�C�~���O
	if (g_ThunderObj.ThunderTime == 9.5 * 60.0 && g_ThunderObj.Phase >= 1 && g_ThunderObj.Cnt < 2)
	{
		CloudThunderRand = rand() % 4;
		//�A�j���[�V�����t���O���I���ɂ���
		g_ThunderObj.AnimFlag = true;
	}
	if (g_ThunderObj.ThunderTime == 10 * 60 && g_ThunderObj.Phase >= 1 && g_ThunderObj.Cnt < 2)
	{
		//�A�j���[�V�����t���O���I�t�ɂ���
		g_ThunderObj.AnimFlag = false;

		//�t���O��ݒ�
		g_ThunderObj.flag = g_ThunderObj.flag | 0b0010;

		//���̃t�F�[�Y���J�E���g
		++g_ThunderObj.Phase;
		//�����J�E���g
		++g_ThunderObj.Cnt;

		//���Ԃ̃��Z�b�g
		g_ThunderObj.ThunderTime = 0;

		//���W�̐ݒ�
		ThunderPos();
	}
	//2���ڂ̃t���O���I���ɂȂ����痋��������悤�ɂ���
	if (g_ThunderObj.flag & 0b0010)
	{
		//����\��
		g_ThunderObj.obj->setActive(true);
		//������܂ł̎��Ԃ��v��
		++g_ThunderObj.DisThunder;
	}

	//0.5�b��ɗ�������
	if (g_ThunderObj.DisThunder > 0.5 * 60)
	{
		//�����\��
		g_ThunderObj.obj->setActive(false);

		//���Ԃ̃��Z�b�g
		g_ThunderObj.DisThunder = 0.0;

		//�A�j���[�V�����t���O���I�t�ɂ���
		g_ThunderObj.AnimFlag = false;

		//���̒e�̉����l��ݒ�
		if (g_ThunderObj.Phase > 3 && BallAcceleration < MaxBallAcceleration)
		{
			BallAcceleration = BallAcceleration + 0.5f;
		}
		//�e�̃X�s�[�h�̒l�����Z�b�g����
		for (int i = 0; i < ThunderBallCnt; ++i)
		{
			if (g_ThunderBallObj[i].obj == NULL)
			{
					//�X�s�[�h�𖈉񃊃Z�b�g����
					g_ThunderBallObj[i].XMoveSpeed = DefaultXSpeed;
					g_ThunderBallObj[i].YMoveSpeed = DefaultYSpeed;
			}
		}

		//�e���쐬
		for (int i = 0; i < ThunderBallCnt; ++i)
		{
			if (g_ThunderBallObj[i].obj == NULL)
			{
				//1����
				if (g_ThunderObj.flag == 0b0001 && g_ThunderObj.Phase == 1)
				{
					g_ThunderBallObj[0].obj = createSprite(Tex_ThunderBall, g_ThunderBallObj[0].Ball_SIZE_X, g_ThunderBallObj[0].Ball_SIZE_Y);
					ThunderBall0Pos();
				}
				//2����
				else if (g_ThunderObj.flag == 0b0010 && g_ThunderObj.Phase == 2)
				{
					g_ThunderBallObj[1].obj = createSprite(Tex_ThunderBall, g_ThunderBallObj[1].Ball_SIZE_X, g_ThunderBallObj[1].Ball_SIZE_Y);
					ThunderBall1Pos();
				}
				//3���ڈȍ~�Œe���P��ʏ�ɑ��݂���ꍇ
				else if (g_ThunderBallObj[0].obj == NULL && g_ThunderBallObj[1].obj != NULL)
				{
					g_ThunderBallObj[0].obj = createSprite(Tex_ThunderBall, g_ThunderBallObj[0].Ball_SIZE_X, g_ThunderBallObj[0].Ball_SIZE_Y);
					ThunderBall0Pos();
				}
				else if (g_ThunderBallObj[0].obj != NULL && g_ThunderBallObj[1].obj == NULL)
				{
					g_ThunderBallObj[1].obj = createSprite(Tex_ThunderBall, g_ThunderBallObj[1].Ball_SIZE_X, g_ThunderBallObj[1].Ball_SIZE_Y);
					ThunderBall1Pos();
				}
				//��ʏ��1���Ȃ��ꍇ
				else if (g_ThunderBallObj[1].obj == NULL)
				{
					g_ThunderBallObj[1].obj = createSprite(Tex_ThunderBall, g_ThunderBallObj[1].Ball_SIZE_X, g_ThunderBallObj[1].Ball_SIZE_Y);
					ThunderBall1Pos();
				}
			}
		}
		//�t���O�̃��Z�b�g
		g_ThunderObj.flag = 0b0000;
	}

	//���Ԃ̕␳
	if (g_ThunderObj.ThunderTime >= 11 * 60 && g_ThunderObj.Phase >= 1)
	{
		g_ThunderObj.ThunderTime = 0;
	}

	ThunderAnim();

}

/*
 * ���̒e�̏���
 */
void CActionGameApp::ThunderBall()
{
	//�e�����݂���Ƃ��̂ݏ������s��
	for (int i = 0; i < ThunderBallCnt; ++i)
	{
		if (g_ThunderBallObj[i].obj != NULL)
		{
			//���W�̎擾
			XMFLOAT4 EnemyBallPos = g_ThunderBallObj[i].obj->getPos();
			//�ړ�
			//�o�E���h�̏���
			//��ʏ㉺
			if (g_ThunderBallObj[i].obj->getPos().y >= WINDOW_TOP - (g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) ||
				g_ThunderBallObj[i].obj->getPos().y <= WINDOW_BOTTOM)
			{
				g_ThunderBallObj[i].YMoveSpeed = -g_ThunderBallObj[i].YMoveSpeed;

				if (!g_pThunderHit)
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pThunderHit = createSound(ThunderHit, false);
				}
			}
			//��ʍ��E
			else if (g_ThunderBallObj[i].obj->getPos().x <= WINDOW_LEFT + (g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) - g_ThunderBallObj[i].XMoveSpeed ||
				g_ThunderBallObj[i].obj->getPos().x >= WINDOW_RIGHT - (g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) - g_ThunderBallObj[i].XMoveSpeed)
			{
				g_ThunderBallObj[i].XMoveSpeed = -g_ThunderBallObj[i].XMoveSpeed;

				if (!g_pThunderHit)
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pThunderHit = createSound(ThunderHit, false);
				}
			}

			//�ړ�
			EnemyBallPos.x += g_ThunderBallObj[i].XMoveSpeed;
			EnemyBallPos.y += g_ThunderBallObj[i].YMoveSpeed;
			//�Z�b�g 
			g_ThunderBallObj[i].obj->setPos(EnemyBallPos);

			//�X�s�[�h�̏��
			//X�l
			if (g_ThunderBallObj[i].XMoveSpeed > 5.0f)
			{
				g_ThunderBallObj[i].XMoveSpeed = 5.0f;
			}
			else if (g_ThunderBallObj[i].XMoveSpeed < -5.0f)
			{
				g_ThunderBallObj[i].XMoveSpeed = -5.0f;
			}
			//Y�l
			if (g_ThunderBallObj[i].YMoveSpeed > 5.0f)
			{
				g_ThunderBallObj[i].YMoveSpeed = 5.0f;
			}
			else if (g_ThunderBallObj[i].YMoveSpeed < -5.0f)
			{
				g_ThunderBallObj[i].YMoveSpeed = -5.0f;
			}

			//��ʊO�ɍs�����ۂɒe������
			if (g_ThunderBallObj[i].obj->getPos().y <= WINDOW_BOTTOM)
			{
				disposeSprite(g_ThunderBallObj[i].obj);
				g_ThunderBallObj[i].obj = NULL;
				//���J�E���g�����炷
				--g_ThunderObj.Cnt;
				//�␳
				if (g_ThunderObj.Cnt < 0)
				{
					g_ThunderObj.Cnt = 0;
				}
			}
			//�����蔻��
			ThunderBallCollision();
		}
	}
}

/*
 * ���̒e�̓����蔻��̏������s���֐�
 */
void CActionGameApp::ThunderBallCollision()
{
	//��
	for (int i = 0; i < g_ThunderObj.Cnt; ++i)
	{
		if (g_ThunderObj.obj != NULL && g_ThunderObj.obj->getActive() == true)
		{
			if (g_pPlayer[0]->collisionOffset(g_ThunderObj.obj, EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size))
			{
				//�c�@�����炷
				DeathThunderFlag = true;
			}
		}
	}
	//���̒e
	for (int i = 0; i < ThunderBallCnt; ++i)
	{
		if (g_ThunderBallObj[i].obj != NULL)
		{
			//�ʏ�u���b�N(����)
			for (int j = 0; j < Block.Count; ++j)
			{
				if (g_pBlock[j] != NULL)
				{
					if (g_ThunderBallObj[i].obj->collision(g_pBlock[j]))
					{
						//�㉺
						if (g_pBlock[j]->getPos().y + ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (Block.Size_Y / 2.0f)) + g_ThunderBallObj[i].YMoveSpeed <= g_ThunderBallObj[i].obj->getPos().y)
						{
							g_ThunderBallObj[i].YMoveSpeed = -g_ThunderBallObj[i].YMoveSpeed;
							g_ThunderBallObj[i].obj->setPos(g_ThunderBallObj[i].obj->getPos().x, g_pBlock[j]->getPos().y + ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (Block.Size_Y / 2.0f)));

						}
						else if (g_pBlock[j]->getPos().y - ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (Block.Size_Y / 2.0f)) + g_ThunderBallObj[i].YMoveSpeed >= g_ThunderBallObj[i].obj->getPos().y)
						{
							g_ThunderBallObj[i].YMoveSpeed = -g_ThunderBallObj[i].YMoveSpeed;
							g_ThunderBallObj[i].obj->setPos(g_ThunderBallObj[i].obj->getPos().x, g_pBlock[j]->getPos().y - ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (Block.Size_Y / 2.0f)));

						}
						//���E
						else if (g_pBlock[j]->getPos().x - ((g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + (Block.Size_X / 2.0f)) - g_ThunderBallObj[i].XMoveSpeed >= g_ThunderBallObj[i].obj->getPos().x)
						{
							g_ThunderBallObj[i].XMoveSpeed = -g_ThunderBallObj[i].XMoveSpeed;
							g_ThunderBallObj[i].obj->setPos(g_pBlock[j]->getPos().x - ((g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + (Block.Size_X / 2.0f)), g_ThunderBallObj[i].obj->getPos().y);

						}
						else if (g_pBlock[j]->getPos().x + ((g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + (Block.Size_X / 2.0f)) + g_ThunderBallObj[i].XMoveSpeed <= g_ThunderBallObj[i].obj->getPos().x)
						{
							g_ThunderBallObj[i].XMoveSpeed = -g_ThunderBallObj[i].XMoveSpeed;
							g_ThunderBallObj[i].obj->setPos(g_pBlock[j]->getPos().x + ((g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + (Block.Size_X / 2.0f)), g_ThunderBallObj[i].obj->getPos().y);

						}
						if (!g_pThunderHit)
						{
							// ��2�����F���[�v�ݒ�
							// ���[�v���Ȃ��̂ŁAfalse��ݒ�
							g_pThunderHit = createSound(ThunderHit, false);
						}
					}
				}
			}
			//���[�u���b�N(����)
			for (int j = 0; j < (BlockPos[PhaseNum - 1].Count + BlockBerPos[PhaseNum - 1].Count); ++j)
			{
				if (g_pLeftBlock[j] != NULL)
				{
					if (g_ThunderBallObj[i].obj->collision(g_pLeftBlock[j]))
					{
						//��
						if (g_pLeftBlock[j]->getPos().y + ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (LeftBlock.Size_Y / 2.0f)) + g_ThunderBallObj[i].YMoveSpeed <= g_ThunderBallObj[i].obj->getPos().y)
						{
							g_ThunderBallObj[i].obj->setPos(g_ThunderBallObj[i].obj->getPos().x, g_pLeftBlock[j]->getPos().y + ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (LeftBlock.Size_Y / 2.0f)));
							g_ThunderBallObj[i].YMoveSpeed = -g_ThunderBallObj[i].YMoveSpeed;
						}
						//��
						else if (g_pLeftBlock[j]->getPos().y - ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (LeftBlock.Size_Y / 2.0f)) + g_ThunderBallObj[i].YMoveSpeed >= g_ThunderBallObj[i].obj->getPos().y)
						{
							g_ThunderBallObj[i].obj->setPos(g_ThunderBallObj[i].obj->getPos().x, g_pLeftBlock[j]->getPos().y - ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (LeftBlock.Size_Y / 2.0f)));
							g_ThunderBallObj[i].YMoveSpeed = -g_ThunderBallObj[i].YMoveSpeed;
						}
						//��
						if (g_pLeftBlock[j]->getPos().x - ((g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + (LeftBlock.Size_X / 2.0f)) + g_ThunderBallObj[i].XMoveSpeed >= g_ThunderBallObj[i].obj->getPos().x)
						{
							g_ThunderBallObj[i].obj->setPos(g_pLeftBlock[j]->getPos().x - ((g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + (LeftBlock.Size_Y / 2.0f)), g_ThunderBallObj[i].obj->getPos().y);
							g_ThunderBallObj[i].XMoveSpeed = -g_ThunderBallObj[i].XMoveSpeed;
						}
						if (!g_pThunderHit)
						{
							// ��2�����F���[�v�ݒ�
							// ���[�v���Ȃ��̂ŁAfalse��ݒ�
							g_pThunderHit = createSound(ThunderHit, false);
						}
					}
				}
			}
			//�E�[�u���b�N(����)
			for (int j = 0; j < (BlockPos[PhaseNum - 1].Count + BlockBerPos[PhaseNum - 1].Count); ++j)
			{
				if (g_pRightBlock[j] != NULL)
				{
					if (g_ThunderBallObj[i].obj->collision(g_pRightBlock[j]))
					{
						//��
						if (g_pRightBlock[j]->getPos().y + ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (RightBlock.Size_Y / 2.0f)) + g_ThunderBallObj[i].YMoveSpeed <= g_ThunderBallObj[i].obj->getPos().y)
						{
							g_ThunderBallObj[i].obj->setPos(g_ThunderBallObj[i].obj->getPos().x, g_pRightBlock[j]->getPos().y + ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (RightBlock.Size_Y / 2.0f)));
							g_ThunderBallObj[i].YMoveSpeed = -g_ThunderBallObj[i].YMoveSpeed;
						}
						//��
						else if (g_pRightBlock[j]->getPos().y - ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (RightBlock.Size_Y / 2.0f)) + g_ThunderBallObj[i].YMoveSpeed >= g_ThunderBallObj[i].obj->getPos().y)
						{
							g_ThunderBallObj[i].obj->setPos(g_ThunderBallObj[i].obj->getPos().x, g_pRightBlock[j]->getPos().y - ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (RightBlock.Size_Y / 2.0f)));
							g_ThunderBallObj[i].YMoveSpeed = -g_ThunderBallObj[i].YMoveSpeed;
						}
						//�E
						if (g_pRightBlock[j]->getPos().x + ((g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + (RightBlock.Size_X / 2.0f)) + g_ThunderBallObj[i].XMoveSpeed <= g_ThunderBallObj[i].obj->getPos().x)
						{
							g_ThunderBallObj[i].obj->setPos(g_pRightBlock[j]->getPos().x + ((g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + (RightBlock.Size_X / 2.0f)), g_ThunderBallObj[i].obj->getPos().y);
							g_ThunderBallObj[i].XMoveSpeed = -g_ThunderBallObj[i].XMoveSpeed;
						}
						if (!g_pThunderHit)
						{
							// ��2�����F���[�v�ݒ�
							// ���[�v���Ȃ��̂ŁAfalse��ݒ�
							g_pThunderHit = createSound(ThunderHit, false);
						}
					}
				}
			}
			//��
			for (int j = 0; j < (BlockBerPos[PhaseNum - 1].ConnectCount[0] + BlockBerPos[PhaseNum - 1].ConnectCount[1] + BlockBerPos[PhaseNum - 1].ConnectCount[2] + BlockBerPos[PhaseNum - 1].ConnectCount[3] + BlockBerPos[PhaseNum - 1].ConnectCount[4]); ++j)
			{
				if (g_pBlockBer[j] != NULL)
				{
					if (g_ThunderBallObj[i].obj->collision(g_pBlockBer[j]))
					{
						//�㉺
						if (g_pBlockBer[j]->getPos().y + ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (BlockBer.Size_Y / 2.0f)) + g_ThunderBallObj[i].YMoveSpeed <= g_ThunderBallObj[i].obj->getPos().y)
						{
							g_ThunderBallObj[i].YMoveSpeed = -g_ThunderBallObj[i].YMoveSpeed;
							g_ThunderBallObj[i].obj->setPos(g_ThunderBallObj[i].obj->getPos().x, g_pBlockBer[j]->getPos().y + ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (BlockBer.Size_Y / 2.0f)));

						}
						else if (g_pBlockBer[j]->getPos().y - ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (BlockBer.Size_Y / 2.0f)) + g_ThunderBallObj[i].YMoveSpeed >= g_ThunderBallObj[i].obj->getPos().y)
						{
							g_ThunderBallObj[i].YMoveSpeed = -g_ThunderBallObj[i].YMoveSpeed;
							g_ThunderBallObj[i].obj->setPos(g_ThunderBallObj[i].obj->getPos().x, g_pBlockBer[j]->getPos().y - ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (BlockBer.Size_Y / 2.0f)));

						}
						//���E
						if (g_pBlockBer[j]->getPos().x - (BlockBer.Size_X / 2.0f) + (g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) - g_ThunderBallObj[i].XMoveSpeed >= g_ThunderBallObj[i].obj->getPos().x)
						{
							g_ThunderBallObj[i].XMoveSpeed = -g_ThunderBallObj[i].XMoveSpeed;
							g_ThunderBallObj[i].obj->setPos(g_pBlockBer[j]->getPos().x - ((g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + (BlockBer.Size_X / 2.0f)), g_ThunderBallObj[i].obj->getPos().y);

						}
						else if (g_pBlockBer[j]->getPos().x + (BlockBer.Size_X / 2.0f) + (g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + g_ThunderBallObj[i].XMoveSpeed <= g_ThunderBallObj[i].obj->getPos().x)
						{
							g_ThunderBallObj[i].XMoveSpeed = -g_ThunderBallObj[i].XMoveSpeed;
							g_ThunderBallObj[i].obj->setPos(g_pBlockBer[j]->getPos().x + ((g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + (BlockBer.Size_X / 2.0f)), g_ThunderBallObj[i].obj->getPos().y);

						}
						if (!g_pThunderHit)
						{
							// ��2�����F���[�v�ݒ�
							// ���[�v���Ȃ��̂ŁAfalse��ݒ�
							g_pThunderHit = createSound(ThunderHit, false);
						}
					}
				}
			}
			//�ʏ�n��
			for (int j = 0; j < Ground.Count; ++j)
			{
				if (g_pGround[j] != NULL)
				{
					if (g_ThunderBallObj[i].obj->collision(g_pGround[j]))
					{
						//��
						if (g_pGround[j]->getPos().y + (Ground.Size_Y / 2.0f + g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + g_ThunderBallObj[i].YMoveSpeed <= g_ThunderBallObj[i].obj->getPos().y)
						{
							g_ThunderBallObj[i].obj->setPos(g_ThunderBallObj[i].obj->getPos().x, g_pGround[j]->getPos().y + ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (Ground.Size_Y / 2.0f)));
							g_ThunderBallObj[i].YMoveSpeed = -g_ThunderBallObj[i].YMoveSpeed;
						}
						if (!g_pThunderHit)
						{
							// ��2�����F���[�v�ݒ�
							// ���[�v���Ȃ��̂ŁAfalse��ݒ�
							g_pThunderHit = createSound(ThunderHit, false);
						}
					}
				}
			}
			//���[�n��
			if (g_ThunderBallObj[i].obj->collision(g_pLeftGround))
			{
				//��
				if (g_pLeftGround->getPos().y + (LeftGround.Size_Y / 2.0f + g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + g_ThunderBallObj[i].YMoveSpeed <= g_ThunderBallObj[i].obj->getPos().y)
				{
					g_ThunderBallObj[i].obj->setPos(g_ThunderBallObj[i].obj->getPos().x, g_pLeftGround->getPos().y + ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (LeftGround.Size_Y / 2.0f)));
					g_ThunderBallObj[i].YMoveSpeed = -g_ThunderBallObj[i].YMoveSpeed;
				}
				//��
				else if (g_pLeftGround->getPos().x - (LeftGround.Size_X / 2.0f + g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) - g_ThunderBallObj[i].XMoveSpeed >= g_ThunderBallObj[i].obj->getPos().x)
				{
					g_ThunderBallObj[i].obj->setPos(g_pLeftGround->getPos().x - ((g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + (LeftGround.Size_X / 2.0f)), g_ThunderBallObj[i].obj->getPos().y);
					g_ThunderBallObj[i].XMoveSpeed = -g_ThunderBallObj[i].XMoveSpeed;
				}
				if (!g_pThunderHit)
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pThunderHit = createSound(ThunderHit, false);
				}
			}
			//�E�[�n��
			if (g_ThunderBallObj[i].obj->collision(g_pRightGround))
			{
				//��
				if (g_pRightGround->getPos().y + (RightGround.Size_Y / 2.0f + g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + g_ThunderBallObj[i].YMoveSpeed <= g_ThunderBallObj[i].obj->getPos().y)
				{
					g_ThunderBallObj[i].obj->setPos(g_ThunderBallObj[i].obj->getPos().x, g_pRightGround->getPos().y + ((g_ThunderBallObj[i].Ball_SIZE_Y / 2.0f) + (RightGround.Size_Y / 2.0f)));
					g_ThunderBallObj[i].YMoveSpeed = -g_ThunderBallObj[i].YMoveSpeed;
				}
				//�E
				else if (g_pRightGround->getPos().x + (RightGround.Size_X / 2.0f + g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) + g_ThunderBallObj[i].XMoveSpeed <= g_ThunderBallObj[i].obj->getPos().x)
				{
					g_ThunderBallObj[i].obj->setPos(g_pRightGround->getPos().x + ((g_ThunderBallObj[i].Ball_SIZE_X / 2.0f) - (RightGround.Size_X / 2.0f)), g_ThunderBallObj[i].obj->getPos().y);
					g_ThunderBallObj[i].XMoveSpeed = -g_ThunderBallObj[i].XMoveSpeed;
				}
				if (!g_pThunderHit)
				{
					// ��2�����F���[�v�ݒ�
					// ���[�v���Ȃ��̂ŁAfalse��ݒ�
					g_pThunderHit = createSound(ThunderHit, false);
				}
			}
		}
	}
	//�v���C���[
	for (int j = 0; j < 2; ++j)
	{
		if (g_pPlayer[j] != NULL && DeathFlag != true && DeathThunderFlag != true &&
			CollisionFlag == true && g_pPlayer[0]->getActive() == true && DeathCoolFlag != true)
		{
			for (int i = 0; i < ThunderBallCnt; ++i)
			{
				if (g_ThunderBallObj[i].obj != NULL)
				{
					if (g_pPlayer[j]->collisionOffset(g_ThunderBallObj[i].obj, EntityToObjCollisionData.Pos, EntityToObjCollisionData.Size))
					{
						//�e������
						disposeSprite(g_ThunderBallObj[i].obj);
						g_ThunderBallObj[i].obj = NULL;
						//���J�E���g�����炷
						--g_ThunderObj.Cnt;
						//�␳
						if (g_ThunderObj.Cnt < 0)
						{
							g_ThunderObj.Cnt = 0;
						}
						//�e�̃X�s�[�h��߂�
						g_ThunderBallObj[i].XMoveSpeed = DefaultXSpeed;
						g_ThunderBallObj[i].YMoveSpeed = DefaultYSpeed;
						//�c�@�����炷
						DeathThunderFlag = true;
						//���̃t�F�[�Y��߂�
						g_ThunderObj.Phase = 0;
						if (!g_pThunderDeath)
						{
							// ��2�����F���[�v�ݒ�
							// ���[�v���Ȃ��̂ŁAfalse��ݒ�
							g_pThunderDeath = createSound(ThunderDeath, false);
						}
					}
				}
			}
		}
	}
}

/*
 * ���̍��W�̏������s���֐�
 */
void CActionGameApp::ThunderPos()
{
	//�����̒���
	g_ThunderObj.ThunderRand = rand() % 4;

	//�摜�̃Z�b�g
	for (int i = 0; i < Cloud.Count; ++i)
	{
		if (PhaseNum == 1)
		{
			g_ThunderObj.obj->setPos(g_pCloud[i]->getPos().x, g_pCloud[i]->getPos().y);
		}
		else
		{
			if (CloudThunderRand == 0)
			{
				g_ThunderObj.obj->setPos(g_pCloud[0]->getPos().x, g_pCloud[0]->getPos().y);
			}
			else
			{
				g_ThunderObj.obj->setPos(g_pCloud[1]->getPos().x, g_pCloud[1]->getPos().y);
			}
		}
	}
	//�����ɂ���ė��̌�����ς���
	if (g_ThunderObj.ThunderRand == 0)
	{
		//�E��
		g_ThunderObj.obj->setPos(g_ThunderObj.obj->getPos().x + 36.0f + g_ThunderObj.Thunder_SIZE_X / 2, g_ThunderObj.obj->getPos().y + 80.0f);
		g_ThunderObj.obj->setAngle(0.0f, 180.0f, .0f);
	}
	else if (g_ThunderObj.ThunderRand == 1)
	{
		//����
		g_ThunderObj.obj->setPos(g_ThunderObj.obj->getPos().x - 28.0f - g_ThunderObj.Thunder_SIZE_X / 2, g_ThunderObj.obj->getPos().y + 76.0f);
		g_ThunderObj.obj->setAngle(0.0f, 0.0f, 0.0f);
	}
	else if (g_ThunderObj.ThunderRand == 2)
	{
		//�E��
		g_ThunderObj.obj->setPos(g_ThunderObj.obj->getPos().x + 36.0f + g_ThunderObj.Thunder_SIZE_X / 2, g_ThunderObj.obj->getPos().y - 88.0f);
		g_ThunderObj.obj->setAngle(0.0f, 0.0f, 180.0f);
	}
	else if (g_ThunderObj.ThunderRand == 3)
	{
		//����
		g_ThunderObj.obj->setPos(g_ThunderObj.obj->getPos().x - 28.0f - g_ThunderObj.Thunder_SIZE_X / 2, g_ThunderObj.obj->getPos().y - 92.0f);
		g_ThunderObj.obj->setAngle(0.0f, 180.0f, 180.0f);
	}
}

/*
 * �e0�̍��W�ݒ���s���֐�
 */
void CActionGameApp::ThunderBall0Pos()
{
	//�����ɂ���Ēe�̏�����ύX
	if (g_ThunderBallObj[0].obj != NULL)
	{
		//�E��
		if (g_ThunderObj.ThunderRand == 0)
		{
			//�e�̃x�N�g����ύX
			if (g_ThunderBallObj[0].XMoveSpeed < 0)
			{
				g_ThunderBallObj[0].XMoveSpeed = -g_ThunderBallObj[0].XMoveSpeed;
			}
			if (g_ThunderBallObj[0].YMoveSpeed < 0)
			{
				g_ThunderBallObj[0].YMoveSpeed = -g_ThunderBallObj[0].YMoveSpeed;
			}
			g_ThunderBallObj[0].obj->setPos(g_ThunderObj.obj->getPos().x + g_ThunderObj.Thunder_SIZE_X / 2, g_ThunderObj.obj->getPos().y + g_ThunderObj.Thunder_SIZE_Y / 2);
			//���X�ɃX�s�[�h�𑬂�����
			if (g_ThunderObj.Phase > 2)
			{
				g_ThunderBallObj[0].XMoveSpeed = g_ThunderBallObj[0].XMoveSpeed + BallAcceleration;
				g_ThunderBallObj[0].YMoveSpeed = g_ThunderBallObj[0].YMoveSpeed + (BallAcceleration * 2);
			}
		}
		//����
		else if (g_ThunderObj.ThunderRand == 1)
		{
			//�e�̃x�N�g����ύX
			if (g_ThunderBallObj[0].XMoveSpeed > 0)
			{
				g_ThunderBallObj[0].XMoveSpeed = -g_ThunderBallObj[0].XMoveSpeed;
			}
			if (g_ThunderBallObj[0].YMoveSpeed < 0)
			{
				g_ThunderBallObj[0].YMoveSpeed = -g_ThunderBallObj[0].YMoveSpeed;
			}
			//�摜�̃Z�b�g
			g_ThunderBallObj[0].obj->setPos(g_ThunderObj.obj->getPos().x - g_ThunderObj.Thunder_SIZE_X / 2, g_ThunderObj.obj->getPos().y + g_ThunderObj.Thunder_SIZE_Y / 2);
			//���X�ɃX�s�[�h�𑬂�����
			if (g_ThunderObj.Phase > 2)
			{
				g_ThunderBallObj[0].XMoveSpeed = g_ThunderBallObj[0].XMoveSpeed - BallAcceleration;
				g_ThunderBallObj[0].YMoveSpeed = g_ThunderBallObj[0].YMoveSpeed + (BallAcceleration * 2);
			}
		}
		//�E��
		else if (g_ThunderObj.ThunderRand == 2)
		{
			//�e�̃x�N�g����ύX
			if (g_ThunderBallObj[0].XMoveSpeed < 0)
			{
				g_ThunderBallObj[0].XMoveSpeed = -g_ThunderBallObj[0].XMoveSpeed;
			}
			if (g_ThunderBallObj[0].YMoveSpeed > 0)
			{
				g_ThunderBallObj[0].YMoveSpeed = -g_ThunderBallObj[0].YMoveSpeed;
			}
			//�摜�̃Z�b�g
			g_ThunderBallObj[0].obj->setPos(g_ThunderObj.obj->getPos().x + g_ThunderObj.Thunder_SIZE_X / 2, g_ThunderObj.obj->getPos().y - g_ThunderObj.Thunder_SIZE_Y / 2);
			//���X�ɃX�s�[�h�𑬂�����
			if (g_ThunderObj.Phase > 2)
			{
				g_ThunderBallObj[0].XMoveSpeed = g_ThunderBallObj[0].XMoveSpeed + BallAcceleration;
				g_ThunderBallObj[0].YMoveSpeed = g_ThunderBallObj[0].YMoveSpeed - (BallAcceleration * 2);
			}
		}
		//����
		else if (g_ThunderObj.ThunderRand == 3)
		{
			//�e�̃x�N�g����ύX
			if (g_ThunderBallObj[0].XMoveSpeed > 0)
			{
				g_ThunderBallObj[0].XMoveSpeed = -g_ThunderBallObj[0].XMoveSpeed;
			}
			if (g_ThunderBallObj[0].YMoveSpeed > 0)
			{
				g_ThunderBallObj[0].YMoveSpeed = -g_ThunderBallObj[0].YMoveSpeed;
			}
			//�摜�̃Z�b�g
			g_ThunderBallObj[0].obj->setPos(g_ThunderObj.obj->getPos().x - g_ThunderObj.Thunder_SIZE_X / 2, g_ThunderObj.obj->getPos().y - g_ThunderObj.Thunder_SIZE_Y / 2);
			//���X�ɃX�s�[�h�𑬂�����
			if (g_ThunderObj.Phase > 2)
			{
				g_ThunderBallObj[0].XMoveSpeed = g_ThunderBallObj[0].XMoveSpeed - BallAcceleration;
				g_ThunderBallObj[0].YMoveSpeed = g_ThunderBallObj[0].YMoveSpeed - (BallAcceleration * 2);
			}
		}
	}
}
/*
 * �e1�̍��W�ݒ���s���֐�
 */
void CActionGameApp::ThunderBall1Pos()
{
	//�����ɂ���Ēe�̏�����ύX
	if (g_ThunderBallObj[1].obj != NULL)
	{
		//�E��
		if (g_ThunderObj.ThunderRand == 0)
		{
			//�e�̃x�N�g����ύX
			if (g_ThunderBallObj[1].XMoveSpeed < 0)
			{
				g_ThunderBallObj[1].XMoveSpeed = -g_ThunderBallObj[1].XMoveSpeed;
			}
			if (g_ThunderBallObj[1].YMoveSpeed < 0)
			{
				g_ThunderBallObj[1].YMoveSpeed = -g_ThunderBallObj[1].YMoveSpeed;
			}
			g_ThunderBallObj[1].obj->setPos(g_ThunderObj.obj->getPos().x + g_ThunderObj.Thunder_SIZE_X / 2, g_ThunderObj.obj->getPos().y + g_ThunderObj.Thunder_SIZE_Y / 2);
			//���X�ɃX�s�[�h�𑬂�����
			if (g_ThunderObj.Phase > 2)
			{
				g_ThunderBallObj[1].XMoveSpeed = g_ThunderBallObj[1].XMoveSpeed + BallAcceleration;
				g_ThunderBallObj[1].YMoveSpeed = g_ThunderBallObj[1].YMoveSpeed + (BallAcceleration * 2);
			}
		}
		//����
		else if (g_ThunderObj.ThunderRand == 1)
		{
			//�e�̃x�N�g����ύX
			if (g_ThunderBallObj[1].XMoveSpeed > 0)
			{
				g_ThunderBallObj[1].XMoveSpeed = -g_ThunderBallObj[1].XMoveSpeed;
			}
			if (g_ThunderBallObj[1].YMoveSpeed < 0)
			{
				g_ThunderBallObj[1].YMoveSpeed = -g_ThunderBallObj[1].YMoveSpeed;
			}
			//�摜�̃Z�b�g
			g_ThunderBallObj[1].obj->setPos(g_ThunderObj.obj->getPos().x - g_ThunderObj.Thunder_SIZE_X / 2, g_ThunderObj.obj->getPos().y + g_ThunderObj.Thunder_SIZE_Y / 2);
			//���X�ɃX�s�[�h�𑬂�����
			if (g_ThunderObj.Phase > 2)
			{
				g_ThunderBallObj[1].XMoveSpeed = g_ThunderBallObj[1].XMoveSpeed - BallAcceleration;
				g_ThunderBallObj[1].YMoveSpeed = g_ThunderBallObj[1].YMoveSpeed + (BallAcceleration * 2);
			}
		}
		//�E��
		else if (g_ThunderObj.ThunderRand == 2)
		{
			//�e�̃x�N�g����ύX
			if (g_ThunderBallObj[1].XMoveSpeed < 0)
			{
				g_ThunderBallObj[1].XMoveSpeed = -g_ThunderBallObj[1].XMoveSpeed;
			}
			if (g_ThunderBallObj[1].YMoveSpeed > 0)
			{
				g_ThunderBallObj[1].YMoveSpeed = -g_ThunderBallObj[1].YMoveSpeed;
			}
			//�摜�̃Z�b�g
			g_ThunderBallObj[1].obj->setPos(g_ThunderObj.obj->getPos().x + g_ThunderObj.Thunder_SIZE_X / 2, g_ThunderObj.obj->getPos().y - g_ThunderObj.Thunder_SIZE_Y / 2);
			//���X�ɃX�s�[�h�𑬂�����
			if (g_ThunderObj.Phase > 2)
			{
				g_ThunderBallObj[1].XMoveSpeed = g_ThunderBallObj[1].XMoveSpeed + BallAcceleration;
				g_ThunderBallObj[1].YMoveSpeed = g_ThunderBallObj[1].YMoveSpeed - (BallAcceleration * 2);
			}
		}
		//����
		else if (g_ThunderObj.ThunderRand == 3)
		{
			//�e�̃x�N�g����ύX
			if (g_ThunderBallObj[1].XMoveSpeed > 0)
			{
				g_ThunderBallObj[1].XMoveSpeed = -g_ThunderBallObj[1].XMoveSpeed;
			}
			if (g_ThunderBallObj[1].YMoveSpeed > 0)
			{
				g_ThunderBallObj[1].YMoveSpeed = -g_ThunderBallObj[1].YMoveSpeed;
			}
			//�摜�̃Z�b�g
			g_ThunderBallObj[1].obj->setPos(g_ThunderObj.obj->getPos().x - g_ThunderObj.Thunder_SIZE_X / 2, g_ThunderObj.obj->getPos().y - g_ThunderObj.Thunder_SIZE_Y / 2);
			//���X�ɃX�s�[�h�𑬂�����
			if (g_ThunderObj.Phase > 2)
			{
				g_ThunderBallObj[1].XMoveSpeed = g_ThunderBallObj[1].XMoveSpeed - BallAcceleration;
				g_ThunderBallObj[1].YMoveSpeed = g_ThunderBallObj[1].YMoveSpeed - (BallAcceleration * 2);
			}
		}
	}
}

/*
 * ���̉摜�̍쐬���s���֐�
 */
void CActionGameApp::ThunderCreate()
{
	//�摜�쐬
	if (g_ThunderObj.obj == NULL)
	{
		g_ThunderObj.obj = createSprite(Tex_Thunder, g_ThunderObj.Thunder_SIZE_X, g_ThunderObj.Thunder_SIZE_Y);
		//�ŏ��͌����Ȃ�����
		g_ThunderObj.obj->setActive(false);
	}
}

/*
 * ���̉摜�̕`����s���֐�
 */
void CActionGameApp::ThunderRender()
{
	//�摜�`��
	if (g_ThunderObj.obj != NULL)
	{
		renderSprite(g_ThunderObj.obj);
	}

	//�e�`��
	for (int i = 0; i < ThunderBallCnt; ++i)
	{
		if (g_ThunderBallObj[i].obj != NULL)
		{
			renderSprite(g_ThunderBallObj[i].obj);
		}
	}
}

/*
 * ���̉摜�̔j�����s���֐�
 */
void CActionGameApp::ThunderDispose()
{
	//�摜�j��
	if (g_ThunderObj.obj != NULL)
	{
		disposeSprite(g_ThunderObj.obj);
		g_ThunderObj.obj = NULL;
	}

	//�e�j��
	for (int i = 0; i < ThunderBallCnt; ++i)
	{
		if (g_ThunderBallObj[i].obj != NULL)
		{
			disposeSprite(g_ThunderBallObj[i].obj);
			g_ThunderBallObj[i].obj = NULL;
		}
	}

	//�t���O���Z�b�g
	g_ThunderObj.flag = 0b0000;

	//���̃��Z�b�g
	g_ThunderObj.Cnt = 0;

	//���Ԃ̃��Z�b�g
	g_ThunderObj.ThunderTime = 0;
	g_ThunderObj.Phase = 0;

	g_ThunderObj.AnimFlag = false;
}