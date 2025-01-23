//----------------------------------------------------------
// �t�@�C����		�FLoad.cpp
// �T�v				�F�Q�[�����[�h�����̊֐��̒�`
// �쐬��			�F21CU0136 ���{����
// �X�V���e			�F2022/03/13 21CU0136���{�@�쐬
//					  2022/03/15 21CU0136���{�@���ׂď�������
//----------------------------------------------------------
#include "CActionGameApp.h"
#include "GameResource.h"
/*
 * �Q�[�����[�h�������s������
 */
void CActionGameApp::procGameLoad()
{
	//�^�C�g�����[�h
	if (IsLoad & 0b0001)
	{
		BlackScreenCreate();
	}
	//�C���Q�[�����[�h
	else if (IsLoad & 0b0010)
	{
		BlackScreenCreate();
	}
	//�Q�[���I�[�o�[���[�h
	else if (IsLoad & 0b0100)
	{
		//--------------------------------------
		// play�̉�ʂ�������x�`�悷��
		//------------------------------------
		//�w�i�̕`��
		Backrender();

		//UI�̕`��
		UIrender();

		procPlayMain_procEnemy();
		////�v���C���[�̉摜�͍ŏ���0�����쐬�A�\������
		//for (int i = 0; i < 2; i++)
		//{
		//	if (g_pPlayer[i] != NULL)
		//	{
		//		renderSprite(g_pPlayer[i]);
		//	}
		//}

		//�I�u�W�F�N�g�̕`��
		ThunderRender();
		Objrender();
		//----------------------------------------------------------------------------------
	}
	//�Q�[���N���A���[�h
	else if (IsLoad & 0b1000)
	{
		//--------------------------------------
		// play�̉�ʂ�������x�`�悷��
		//------------------------------------
		//�w�i�̕`��
		if (BonusON == true)
		{
			BBackrender();
		}
		else
		{
			Backrender();
		}
		
		//UI�̕`��
		UIrender();

		if (BonusON != true)
		{
			procPlayMain_procEnemy();
		}

		//�v���C���[�̉摜�͍ŏ���0�����쐬�A�\������
		for (int i = 0; i < 2; i++)
		{
			if (g_pPlayer[i] != NULL)
			{
				renderSprite(g_pPlayer[i]);
			}
		}

		//�I�u�W�F�N�g�̕`��
		if (BonusON == true)
		{
			BObjrender();
		}
		else
		{
			ThunderRender();
			Objrender();
		}
		//----------------------------------------------------------------------------------
	}
	//�����X�N���[�����폜����
	else
	{
		if (g_Black != NULL)
		{
			disposeSprite(g_Black);
			g_Black = NULL;
		}
	}
}

/*
 * �Q�[�����[�h�����̍����X�N���[���̏������s������
 */
void CActionGameApp::BlackScreenCreate()
{
	if (g_Black == NULL)
	{
		g_Black = createSprite(Tex_Black);
	}
	//�摜���쐬����Ă�����`�悷��
	if (g_Black != NULL)
	{
		renderSprite(g_Black);
	}
}