#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
using namespace std;

struct room
{
    int east, west, south, north, stairs; //for each direction, if direcrion != 0, there is a door; other wise, there is a wall
};                                        //for stairs, if stairs == 1, it means you can go up; if stairs == -1, it means you can go down
vector<room> castle;
int princess, monster; //room numbers where princess and monster are

bool init_castle(void); //load the map from map.txt
void prin_mon(void); //randomly generate the princess and monster location
void prompting(int Room); //print the information of each room
void play(void);  
void conversation(); //conservation with princess
int count_exit(room a); //calculate the number of exits of each room

int main()
{
    if (init_castle()) //if it returns 1, map is opened successfully
    {
        prin_mon(); //randomly generate the princess and monster location
        play(); //the game begin
    }
}

bool init_castle(void)
{
    ifstream file("map.txt"); //read the map
    if (!file.is_open())
    {
        cout << "Fail to open the map!";
        return false;
    }
    for (int i = 0; i < 64; i++)
    {
        room m;
        file >> m.east >> m.west >> m.south >> m.north >> m.stairs; //read the value of each direction, which 1 represents door, 0 represents wall
        castle.push_back(m); 
    }
    return true; //read the map successfully
}

void prin_mon(void) 
{
    srand(time(nullptr)); //generate random seed
    int i, k;
    i = rand() % 64 + 1; //guarantee i is between 1 and 64
    while (i == 2)
        i = rand() % 64 + 1; //guarantee princess is not at the lobby
    k = rand() % 64 + 1; //gurantee k is between 1 and 64
    while (k == 2)
        k = rand() % 64 + 1; //guarantee monster is not at the lobby
    princess = 42; //if you want to actually play the game, please replace 42 with i
    monster = 30; //if you want to actually play the game, please replace 30 with k
    //declaration: princess and monster are supposed to be i and k, but for your convenience to check, I set them fixed and offer two sample input
}

void play()
{
    int Room = 2, old_Room = 2, Prin = 0; //Room contains the current room number, old_room contains former room number, Prin judge whether you meet the princess
    string go, direction;
    while (!Prin || Room != 2) //judge whether you have met 
    {
        prompting(Room); //print room's information
        while (Room == old_Room) //juedge whether you have move to the next room
        {
            cin >> go >> direction;
            transform(direction.begin(), direction.end(), direction.begin(), ::tolower); //transform the upper to lower
            if (direction == "east" && castle[Room - 1].east) //check where you enter and whether you can move to the east
                Room++;
            else if (direction == "west" && castle[Room - 1].west)//check where you enter and whether you can move to the west 
                Room--;
            else if (direction == "south" && castle[Room - 1].south)//check where you enter and whether you can move to the south
                Room -= 4;
            else if (direction == "north" && castle[Room - 1].north)//check where you enter and whether you can move to the north
                Room += 4;
            else if (direction == "up" && castle[Room - 1].stairs)//check where you enter and whether you can move to the upstairs
                Room += 16;
            else if (direction == "down" && castle[Room - 1].stairs)//check where you enter and whether you can move to the downstairs
                Room -= 16;
            else
                cout << "Wrong direction! Please reenter your command: "; //you enter wrong direction
        }
        old_Room = Room;
        if (Room == monster) //you meet the monter
        {
            cout << "You meet the monster! Game over.";
            return ;
        }
        if (Room == princess)
        {
            conversation(); //conversation with princess
            Prin = 1; //Prin == 1 represents that you have met princess
        }
    }
    cout << "Congratulation! You have taken the princess out of the castle!";
    return ;
}

void prompting(int Room)
{
    int num;
    num = count_exit(castle[Room - 1]); //count the number of exits
    if (Room == 2) //Room2 is lobby
        cout << "Welcome to the lobby. ";
    else
        cout << "Welcome to Room" << Room << ". ";
    cout << "There are " << num << " exits: ";
    if (castle[Room - 1].east) //judge whether the east of the room has a door
    {
        cout << "east";
        num--;
        if (!num) //judge whether the room has other exits
            cout << ".";
        else if (num == 1)
            cout << " and ";
        else
            cout << ", ";
    }
    if (castle[Room - 1].west)//judge whether the west of the room has a door
    {
        cout << "west";
        num--;
        if (!num)//judge whether the room has other exits
            cout << ".";
        else if (num == 1)
            cout << " and ";
        else
            cout << ", ";
    }
    if (castle[Room - 1].north)//judge whether the north of the room has a door
    {
        cout << "north";
        num--;
        if (!num)//judge whether the room has other exits
            cout << ".";
        else if (num == 1)
            cout << " and ";
        else
            cout << ", ";
    }
    if (castle[Room - 1].south)//judge whether the south of the room has a door
    {
        cout << "south";
        num--;
        if (!num)//judge whether the room has other exits
            cout << ".";
        else
            cout << " and ";
    }
    if (castle[Room - 1].stairs)//judge whether the room has stairs
    {
        if (castle[Room - 1].stairs == 1)//stairs == 1 represents you can go upstairs
            cout << "up.";
        else//stairs == 0 represents you can go downstairs
            cout << "down.";
    }
    cout << endl
         << "Enter your command: ";
    return;
}

int count_exit(room a)
{
    int count = 0;
    if (a.east != 0)//in the east it has a door
        count++;
    if (a.west != 0)//in the west it has a door
        count++;
    if (a.south != 0)//in the north it has a door
        count++;
    if (a.north != 0)//in the south it has a door
        count++;
    if (a.stairs != 0)//the room has a stairs
        count++;
    return count;
}

void conversation()
{
    cout << endl << "You: Princess!" << endl;
    cout << "Princess: Oh, brave man, finally you get here. Can you save me out of here?" << endl;
    cout << "You: Emmm, I want to , but there is a monster..." << endl;
    cout << "Prnicess: Please take me! I would like give you anything as long as you save me out of here." << endl;
    cout << "You: All right, I'll try." << endl;
    cout << "Now take the princess out of the castle!" << endl << endl;
}