#include <bits/stdc++.h>
using namespace std;

vector < string > fullmap;

enum Direction
{ UP, RIGHT, DOWN, LEFT };

std::pair < int, int >
getNextPosition (int x, int y, Direction direction)
{
  switch (direction)
	{
	case UP:
	  return
	  {
	  x, y - 1};
	case RIGHT:
	  return
	  {
	  x + 1, y};
	case DOWN:
	  return
	  {
	  x, y + 1};
	case LEFT:
	  return
	  {
	  x - 1, y};
	}
  return
  {
  x, y};
}

Direction
getNextDirection (char pipe, Direction direction)
{
  switch (pipe)
	{
	case '|':
	case '-':
	  return direction;
	case 'L':
	  return direction == DOWN ? RIGHT : UP;
	case 'J':
	  return direction == DOWN ? LEFT : UP;
	case '7':
	  return direction == UP ? LEFT : DOWN;
	case 'F':
	  return direction == UP ? RIGHT : DOWN;
	}
  return direction;
}

int
main ()
{

  fstream file;
  string tp;

  file.open ("day5.txt", ios::in);
  if (file.is_open ())
	{

	  while (getline (file, tp))
		{
		  fullmap.push_back (tp);
		}
	}

  int sloc_i, sloc_j;
  int flag = 0;
  for (int i = 0; i < fullmap.size (); i++)
	{
	  for (int j = 0; j < fullmap[0].size (); j++)
		{
		  if (fullmap[i][j] == 'S')
			{
			  sloc_j = j;
			  sloc_i = i;
			  flag = 1;
			  break;
			}
		}
	  if (flag == 1)
		break;
	}
  int part1 = 0;
  int part2 = 0;

  std::vector < string > grid = fullmap;
  size_t startX, startY;
  for (size_t y = 0; y < grid.size (); y++)
	for (size_t x = 0; x < grid[y].size (); x++)
	  if (grid[y][x] == 'S')
		{
		  startX = x;
		  startY = y;
		  goto start_found;
		}

start_found:
  char pipe;
  Direction direction;
  if (startY > 0)
	{
	  pipe = grid[startY - 1][startX];
	  if (pipe == '|' || pipe == '7' || pipe == 'F')
		direction = UP;
	}
  if (startX < grid[0].size () - 1)
	{
	  pipe = grid[startY][startX + 1];
	  if (pipe == '-' || pipe == '7' || pipe == 'J')
		direction = RIGHT;
	}
  if (startY < grid.size () - 1)
	{
	  pipe = grid[startY + 1][startX];
	  if (pipe == '|' || pipe == 'J' || pipe == 'L')
		direction = DOWN;
	}

  Direction startDirection = direction;

  size_t steps = 1;
  auto[x, y] = getNextPosition (startX, startY, direction);
  pipe = grid[y][x];

  std::set < std::pair < int, int >>mainLoop = { std::make_pair (x, y) };


  while (pipe != 'S')
	{
	  steps++;
	  direction = getNextDirection (pipe, direction);
	  std::tie (x, y) = getNextPosition (x, y, direction);
	  mainLoop.insert (std::make_pair (x, y));
	  pipe = grid[y][x];
	}

  Direction endDirection = direction;

  part1 = steps / 2;


  if ((startDirection == RIGHT && endDirection == DOWN)
	  || (startDirection == UP && endDirection == LEFT))
	grid[startY][startX] = 'L';
  else if ((startDirection == RIGHT && endDirection == UP)
		   || (startDirection == DOWN && endDirection == LEFT))
	grid[startY][startX] = 'F';
  else if ((startDirection == LEFT && endDirection == DOWN)
		   || (startDirection == UP && endDirection == RIGHT))
	grid[startY][startX] = 'J';
  else if ((startDirection == LEFT && endDirection == UP)
		   || (startDirection == DOWN && endDirection == RIGHT))
	grid[startY][startX] = '7';
  else if (startDirection == RIGHT)
	grid[startY][startX] = '-';
  else
	grid[startY][startX] = '|';

  // Part 2
  for (size_t y = 0; y < grid.size (); y++)
	{
	  bool inLoop = false;
	  char previous = ' ';
	  for (size_t x = 0; x < grid[y].size (); x++)
		{
		  if (!mainLoop.count (std::make_pair (x, y)))
			{
			  if (inLoop)
				part2++;
			  continue;
			}

		  char tile = grid[y][x];
		  if (tile == '|')
			inLoop = !inLoop;
		  else if (tile == 'L' || tile == 'F')
			previous = tile;
		  else if (tile == '7' || tile == 'J')
			if (previous + tile == 'L' + '7' || previous + tile == 'F' + 'J')
			  inLoop = !inLoop;
			else
			  previous = ' ';
		}
	}

  std::cout << "Part 1: " << part1 << std::endl;
  std::cout << "Part 2: " << part2 << std::endl;


}
