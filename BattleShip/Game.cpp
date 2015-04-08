#include "StdAfx.h"
#include "Game.h"

#include "Computer.h"
#include "Human.h"
#include "Computer.h"

Game::Game(void)
{
}


Game::~Game(void)
{
}

void Game::Greeting()
{
	cout<<"*****Морской бой*****"<<endl;
	cout<<"Добро пожаловать в игру! \n";
	cout<<"Вы знакомы с правилами? (y/n)";
	char answ = '0';
	cin>>answ;
	if(answ == 'n') ShowRules();
	cout<<endl;
}

void Game::ShowRules()
{}

void Game::StartGame()
{
	//Greeting();

	Computer *computer = new Computer();
	_sleep(500);
	Human *human = new Human();

	Player *player1 = human;
	Player *player2 = computer;

	Field *field = player2->GetPlayerField();

	player1->SetEnemyField(field);
	player2->SetEnemyField(player1->GetPlayerField());

	player1->ShowFields();
	player2->ShowFields();//for debug

	while(true)
	{
		player1->Fire();
		player2->Fire();
		if(player2->IsWinner() || player1->IsWinner()) 
			break;
		system("cls");
		player1->ShowFields();
		player2->ShowFields();//for debug
	}
}