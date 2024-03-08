#pragma once


class GameOverMenu
{
private:

	enum RetryMenu
	{
		MENU_RETRY,
		MENU_RETURNMAP,
		MENU_BACKTITLE,
		MENU_MAX_NUM
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