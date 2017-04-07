#pragma once
#include <iostream>
#include <string>

#include "SimplePoint.h"
#include "Map.h"
#include "LeePathfinder.h"

#define FIELD_SIZE 20

using namespace std;
bool error_flag;

int main(int argc, char* argv[])
{
	error_flag = false;
#pragma region create field
	SimplePoint field[FIELD_SIZE][FIELD_SIZE];

	for (int i = 0; i < FIELD_SIZE; i++)
		for (int j = 0; j < FIELD_SIZE; j++)
			field[i][j] = SimplePoint{ i, j, 0 };

	//field[0][5].val = -1;
	field[1][5].val = -1;
	field[2][5].val = -1;
	field[2][4].val = -1;
	field[3][4].val = -1;
	field[4][4].val = -1;
	field[5][4].val = -1;
	field[5][3].val = -1;
	field[5][2].val = -1;
	field[5][1].val = -1;
	field[5][0].val = -1;

	/*cout << "Field: " << endl;
	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
			cout << field[i][j].val;
		cout << endl;
	}*/
#pragma endregion

	//create and set map
	Map map(FIELD_SIZE, FIELD_SIZE);
	map.populate_map_default();
	map.display_map();
	map.link_tiles();

	//get user input
	string startx, starty, endx, endy;
	cout << "Enter start coordinates: " << endl;
	getline(cin, startx);
	getline(cin, starty);

	LeePathfinder pathfinder(map);
	pathfinder.mark_field(map.get_tile(stoi(startx), stoi(starty)));
	pathfinder.display_field();

	cout << "Enter end coordinates: " << endl;
	getline(cin, endx);
	getline(cin, endy);
	pathfinder.calculate_path(map.get_tile(stoi(endx), stoi(endy)));
	vector<SimplePoint*> path = pathfinder.get_path();

	for (int i = 0; i < path.size(); i++)
		field[path.at(i)->x][path.at(i)->y].val = -5;

	for (int i = 0; i < FIELD_SIZE; i++)
	{
		for (int j = 0; j < FIELD_SIZE; j++)
		{
			switch (field[i][j].val)
			{
			case -10:
				cout << "s ";
				break;
			case 0:
				cout << "_ ";
				break;
			case -5:
				cout << "p ";
				break;
			case -1:
				cout << "w ";
			}
		}
		cout << endl;
	}

end:
   if (error_flag)
	   cout << "Some error appeared. Aborting execution." << endl;

	//don't exit until user presses enter
	string asd;
	getline(cin, asd);

	return 0;
}

//set up start and end point
/*SimplePoint* start = &temp[1][2];
SimplePoint* end = &temp[7][9];*/

/*for (int i = 0; i < FIELD_SIZE; i++)
{
for (int j = 0; j < FIELD_SIZE; j++)
{
temp[i][j] = map.field[i][j];
cout << temp[i][j].neighbours.size();
}
cout << endl;
}*/
////set up every tile's neighbours
//for (int i = 0; i < FIELD_SIZE; i++)
//{
//	for (int j = 0; j < FIELD_SIZE; j++)
//	{
//		if (i > 0)
//			temp[i][j].neighbours.push_back(&temp[i - 1][j]);
//		if (j < FIELD_SIZE-1)
//			temp[i][j].neighbours.push_back(&temp[i][j + 1]);
//		if (i < FIELD_SIZE-1)
//			temp[i][j].neighbours.push_back(&temp[i + 1][j]);
//		if (j > 0)
//			temp[i][j].neighbours.push_back(&temp[i][j - 1]);
//		if (i > 0 && j > 0)
//			temp[i][j].neighbours.push_back(&temp[i - 1][j - 1]);
//		if (i > 0 && j < FIELD_SIZE-1)
//			temp[i][j].neighbours.push_back(&temp[i - 1][j + 1]);
//		if (i < FIELD_SIZE-1 && j > 0)
//			temp[i][j].neighbours.push_back(&temp[i + 1][j - 1]);
//		if (i < FIELD_SIZE-1 && j < FIELD_SIZE-1)
//			temp[i][j].neighbours.push_back(&temp[i + 1][j + 1]);
//	}
//}	

/*
try
{
if (stoi(startx) > FIELD_SIZE - 1 || stoi(starty) > FIELD_SIZE - 1 || stoi(endx) > FIELD_SIZE - 1 || stoi(endy) > FIELD_SIZE - 1)
{
error_flag = true;
goto end;
}

start = &temp[stoi(startx)][stoi(starty)];
end = &temp[stoi(endx)][stoi(endy)];
}
catch (invalid_argument e)
{
error_flag = true;
goto end;
}


start->val = -10;
end->val = -11;
#pragma endregion

shortest_path(start);
backtrack(end, start);


#pragma region display stuff
//add path to field
for (int i = 0; i < path.size(); i++)
{
field[path.at(i)->x][path.at(i)->y].val = 3;
}

start->val = -10;
end->val = -11;

//display calculations
cout << "calculations: " << endl;
for (int i = 0; i < FIELD_SIZE; i++)
{
for (int j = 0; j < FIELD_SIZE; j++)
cout << temp[i][j].val << " ";
cout << endl;
}
cout << endl;

//display field
cout << "shortest path: " << endl;
for (int i = 0; i < FIELD_SIZE; i++)
{
for (int j = 0; j < FIELD_SIZE; j++)
if (field[i][j].val == -1)
cout << "w ";
else if (temp[i][j].val == -10)
cout << "s ";
else if (temp[i][j].val == -11)
cout << "e ";
else if (field[i][j].val == 0)
cout << "_ ";
else
cout << "p ";
cout << endl;
}
#pragma endregion
*/

//method that marks the neighbours of a given tile with the given number
//vector<SimplePoint*> mark(SimplePoint* point, int num)
//{
//	vector<SimplePoint*> temp;
//	//mark the neighbours
//	for (int i = 0; i < point->neighbours.size(); i++)
//	{
//		if (point->neighbours.at(i)->val == 0)
//		{
//			point->neighbours.at(i)->val = num;
//			temp.push_back(point->neighbours.at(i));
//		}
//		else if (point->neighbours.at(i)->val == -11)
//		{
//			vector<SimplePoint*> empty;
//			found = true;
//			return empty;
//		}
//	}
//
//	return temp;
//}
//
////method that will keep marking tiles and their neighbours until the end tile is found or it runs out of tiles to mark
////thus finding the shortest path
//void shortest_path(SimplePoint* start)
//{
//	int num = 1;
//	cur_number = mark(start, num);
//	cout << endl << cur_number.size() << endl;
//	while (!found)
//	{
//		//cout << cur_number.size() << endl;
//		num++;
//		vector<SimplePoint*> iteration_points;
//		for (int i = 0; i < cur_number.size(); i++)
//		{
//			vector<SimplePoint*> t1 = mark(cur_number.at(i), num);
//			for (int j = 0; j < t1.size(); j++)
//				iteration_points.push_back(t1.at(j));
//		}
//
//		cur_number = iteration_points;
//		//if there is no more tiles to be marked, stop looping
//		if (iteration_points.size() == 0)
//			return;
//	}
//}
//
////method that backtracks through all of the marked tiles and stores the shortest path
////from endpoint to startpoint in path vector
//void backtrack(SimplePoint* endpoint, SimplePoint* startpoint)
//{
//	if (found)
//	{
//		SimplePoint* cur_point = endpoint;
//		//path.push_back(endpoint);
//		bool start_reached = false;
//		while (!start_reached)
//		{
//			SimplePoint* min_point = cur_point->neighbours.at(0);
//			int counter = 1;
//			while (min_point->val == -1)
//			{
//				min_point = cur_point->neighbours.at(counter);
//				counter++;
//			}
//
//			for (int i = 0; i < cur_point->neighbours.size(); i++)
//			{
//				if (min_point->val > cur_point->neighbours.at(i)->val &&
//					cur_point->neighbours.at(i)->val != 0 &&
//					cur_point->neighbours.at(i)->val != -11 &&
//					cur_point->neighbours.at(i)->val != -1)
//					min_point = cur_point->neighbours.at(i);
//			}
//
//			SimplePoint* temp = new SimplePoint{ min_point->x, min_point->y, 3 };
//
//			if (min_point->val == -10)
//				start_reached = true;
//			else
//				path.push_back(temp);
//
//			cur_point = min_point;
//		}
//	}
//	else
//		cout << "destination not found" << endl;
//}
//
