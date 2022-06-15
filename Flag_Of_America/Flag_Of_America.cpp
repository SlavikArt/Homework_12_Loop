#include <iostream>
#include <windows.h>

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void color(ConsoleColor text, ConsoleColor background)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, (WORD)((background << 4) | text));
}

int main()
{
	int height = 13;
	int width = 50;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			color(White, White);
			if (x <= width / 2 - width * 5 / 100 && y <= height / 2)
			{
				color(White, Blue);
				if (y % 2 == 0)
				{
					if (x % 2 != 0)
					{
						std::cout << " ";
					}
					else
					{
						std::cout << "*";
					}
				}
				else
				{
					if (x % 2 != 0)
					{
						std::cout << "*";
					}
					else
					{
						std::cout << " ";
					}
				}
				
			}
			else if (y % 2 == 0)
			{
				color(White, Red);
				std::cout << " ";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
	color(White, Black);
}