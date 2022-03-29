// main.cpp
#include <iostream>
#include <Windows.h>
#include "Cursor.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Cursor cur;
	cur.read();
	cur.display();

	cur.changeView();
	cur.SizeUp();
	cur.SizeUp();

	cur.display();

	cur.move(20, 20);
	cur.SizeDown();

	cur.display();

	return 0;
}