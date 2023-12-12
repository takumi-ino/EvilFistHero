#pragma once


class GameOverMenu
{
public:

	static void SelectGameOverMenu();
	static void BranchProcess_ByGameOverMenu();

	enum RetryMenu
	{
		MENU_RETRY,
		MENU_RETURNMAP,
		MENU_BACKTITLE,
		MENU_MAX_NUM
	};

public:

	typedef struct {
		int x, y;
		char name[128];
	} MenuElement;

public:
	
	static int _gameOverMenuIndex;
};