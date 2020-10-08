int main()
{
	int delay = 50;
	srand(time(NULL));
	snake nagini;
	nagini.initGround();
	nagini.initSnake();
	nagini.updateFood();
	nagini.firstDraw();
	_beginthread(userInput, 0, (void*)0);
	
	do
	{
		nagini.updateSnake(delay);
		if (item == FOOD)
			nagini.updateFood();
	} while (item >= 0 && input != EXIT);

	gotoxy(WIDTH / 2 - 5, HEIGHT / 2 - 2);
	cout << "GAME OVER";
	gotoxy(WIDTH / 2 - 8, HEIGHT / 2 + 2);
	cout << "Your score is " << nagini.getFoodCounter() - 1 << "!" << endl;
	gotoxy(WIDTH / 2, HEIGHT / 2);

	_getch();
	return 0;
}
