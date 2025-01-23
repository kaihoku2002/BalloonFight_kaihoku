#include "stdafx.h"
#include "CActionGameApp.h"
#include "GameResource.h"
#include "UV.h"


/**
 * �֐��� : createSprite()
 * �������e : �w�肳�ꂽ�p�X�ɂ���摜���A�w�肳�ꂽ�T�C�Y�ō쐬����
 * ���� :	path_		�摜�̂���p�X
 *			width_		�쐬����摜�̕�
 *			height_		�쐬����摜�̍���
 * �߂�l : �쐬�����摜���Ǘ�����I�u�W�F�N�g
 */
CPicture* CActionGameApp::createSprite (LPCWSTR path_, float width_, float height_)
{
	vector <QuadrangleTexel>  singleTexels = {
	QuadrangleTexel{ { 0, 1.0f },{ 0, 0.0f },{ 1, 1.0f },{ 1, 0.0f } }	// �w�肷��UV���W����̔z��
	};
	XMFLOAT2 spriteSize = { width_, height_};
	CPicture* object = NULL;

	//�v���C���[
	if (path_ == Tex_Player)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexelPlayers);            //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_EnteringWater)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexelEnteringWaters);      //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_Thunder)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexelThunders);               //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_ThunderBall)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexelThunderBalls);               //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_Bubble)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexelBubbles);               //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_Fish)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexelFishs);               //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_Cloud)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexelClouds);               //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_Enemy1)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexelEnemys);               //!<�w�肷��U�u���W�̔z��
	}
	else if(path_ == Tex_BackAnim)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTex_BackAnims);               //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_bBackAnim)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTex_bBackAnims);               //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_BlockBer)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexelBlockBers);               //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_BPipe)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexelBPipes);               //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_titleballoon)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexeltitleballoons);               //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_Symbol)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexelSymbol);               //!<�w�肷��U�u���W�̔z��
	}
	else if (path_ == Tex_BBalloon)
	{
		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //!<�X�v���C�g�̈ʒu
			spriteSize,                //!<�X�v���C�g�T�C�Y
			kTexelBBalloons);               //!<�w�肷��U�u���W�̔z��
	}
	else
	{

		object = CPicture::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// �X�v���C�g�̈ʒu
			spriteSize,					// �X�v���C�g�̃T�C�Y
			singleTexels);				// �w�肷��UV���W�̔z��
	}

	return object;
}

CFont* CActionGameApp::createFont(LPCWSTR path_, int digits_, float width_, float height_)
{
	XMFLOAT2 spriteSize = { width_, height_ };
	CFont* objects = NULL;

	if (path_ == Tex_Addscore)
	{
		objects = CFont::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //�X�v���C�g�̈ʒu
			spriteSize,                //�X�v���C�g�T�C�Y
			kTexelAddScores,          //�w�肷��UV���W�̔z��
			digits_);                  //����
	}
	else
	{
		objects = CFont::create(m_pDevice, m_pDeviceContext, m_viewPort, HLSL_AlphaHLSL, path_,
			{ 0.0f,0.0f,0.0f,0.0f },   //�X�v���C�g�̈ʒu
			spriteSize,                //�X�v���C�g�T�C�Y
			kTexelNumbers,          //�w�肷��UV���W�̔z��
			digits_);                  //����
	}

	return objects;
}
