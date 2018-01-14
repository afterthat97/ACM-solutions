#include <iostream>
int m, n, q;
char map[103][103];
bool vis[103][103] = {};

void draw(int x, int y, char ch) {
	map[x][y] = ch;
	vis[x][y] = 1;
	if (x != 1 && map[x - 1][y] != '|' && map[x - 1][y] != '+' && map[x - 1][y] != '-' && !vis[x - 1][y])
		draw(x - 1, y, ch);
	if (y != 1 && map[x][y - 1] != '|' && map[x][y - 1] != '+' && map[x][y - 1] != '-' && !vis[x][y - 1])
		draw(x, y - 1, ch);
	if (x != m && map[x + 1][y] != '|' && map[x + 1][y] != '+' && map[x + 1][y] != '-' && !vis[x + 1][y])
		draw(x + 1, y, ch);
	if (y != n && map[x][y + 1] != '|' && map[x][y + 1] != '+' && map[x][y + 1] != '-' && !vis[x][y + 1])
		draw(x, y + 1, ch);
}

int main() {
	std::cin >> m >> n >> q;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			map[i][j] = '.';

	for (int req = 1; req <= q; req++) {
		int index;
		std::cin >> index;
		switch (index) {
			case 0: {
				int x1, y1, x2, y2;
				std::cin >> x1 >> y1 >> x2 >> y2;
				x1++;
				x2++;
				y1++;
				y2++;
				if (x1 == x2)
					if (y1 < y2)
						for (int j = y1; j <= y2; j++)
							map[x1][j] = ((map[x1][j] == '-' || map[x1][j] == '+') ? '+' : '|');
					else
						for (int j = y1; j >= y2; j--)
							map[x1][j] = ((map[x1][j] == '-' || map[x1][j] == '+') ? '+' : '|');
				else
					if (x1 < x2)
						for (int i = x1; i <= x2; i++)
							map[i][y1] = ((map[i][y1] == '|' || map[i][y1] == '+') ? '+' : '-');
					else
						for (int i = x1; i >= x2; i--)
							map[i][y1] = ((map[i][y1] == '|' || map[i][y1] == '+') ? '+' : '-');
				break;
			}
			case 1:
				int px, py;
				char ch;
				std::cin >> px >> py;
				std::cin >> ch;
				px++;
				py++;
				for (int i = 1; i <= m; i++)
					for (int j = 1; j <= n; j++)
						vis[i][j] = 0;
				draw(px, py, ch);
				break;
		}
	}
	for (int j = n; j >= 1; j--) {
		for (int i = 1; i <= m; i++)
			std::cout << map[i][j];
		std::cout << std::endl;
	}
	return 0;
}
