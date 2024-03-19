#pragma once

class DialogueButtons;


// �v�����[�O�ƃG�s���[�O���Ǘ��i�@SceneTitle_SelectMenu�̎��@�� �X�e�[�W�T�J�n���@�j
class SceneConversation : public SceneBase
{
public:

	SceneConversation();

	void Update(const float deltaTime) override;
	void Render(const float deltaTime) override;

private:

	void ReleaseMem() override;

	//�@�L�����N�^�[�摜�`��------------------------------------------------------------

	// �v���C���[
	void ShowPlayerImage_Prologue();
	void ShowPlayerImage_Epilogue();
	// ���_
	void ShowGoddessImage();
	// ����
	void ShowGirlImage();
	// �ŏI�{�X
	void ShowFinalBossImage();

	//�@�L�����N�^�[�̃n�C���C�g--------------------------------------------------------

	// �v���C���[
	void SetPlayersHighlight_Prologue();
	void SetPlayersHighlight_Epilogue();
	// ���_
	void SetGoddessHighlight();
	// ����
	void SetGirlHighlight();
	// �ŏI�{�X
	void SetFinalBossHighlight();

	//�@�e�L�X�g--------------------------------------------------------------------------------

	void GetInputName_AtLast();     // ���O����
	void SetPlayersName();          // ���O�ݒ�

	void PrintDialogueText();       // �e�L�X�g�`��
	void PrintNextByInput();        // �e�L�X�g����
	void Control_StoryLineStream();	// ��Q�̊֐��𐧌�(�G���^�[�L�[�j

	//�@--------------------------------------------------------------------------------
	void StartFinalBossBattle();    // �ŏI��J�n
	void MoveToStageMap();          // �o�g���I����Ƀ}�b�v�ɖ߂�

private:

	DialogueButtons* _buttons_ptr = nullptr;

public:

	// �v�����[�O�i0�j�ƃG�s���[�O�i1�j�̐؂�ւ��p
	static int Prologue_Epilogue;

	// �e�L�X�g�̃C���f�b�N�X
	static int _CURRENT_TEXTROW;

private:

	bool      _isSetPlayerBright = false;
	bool      _isSetGoddessBright = false;
	bool      _isSetGirlBright = false;
	bool      _isSetFinalBossBright = false;
		      
	bool      _showPlayer = false;
	bool      _showGoddess = false;
	bool      _showGirl = false;

	// ----------------------------------------
	int       _bg_hdl{};        // �w�i�n���h��
	int       _inputName_hdl{}; // ���O�n���h��

	// �e�L�X�g----------------------------------------
	int       _printTextSpeed = 0;
	const int _printTextSpeed_adjustRate = 3;

private:

	std::string _PLAYER_NAME{};

	std::string _receiveText[140];
};