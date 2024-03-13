#pragma once


class GameOverMenu
{
private:

	enum class NEXT
	{
		RETRY,
		RETURNMAP,
		BACKTITLE,
		MAX_NUM
	};

public:

	typedef struct {
		int x;
		int y;
		char name[128];
	} MenuElement;

public:

	static void SelectGameOverMenu();
	static void BranchProcess_ByGameOverMenu();

private:
	
	static int gameOverMenuIndex;
};