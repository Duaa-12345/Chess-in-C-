//l174092 Duaa Sajid
//l174651 Eisha Ahmad


#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//class colour is used to determine whether it's black player or it's white player
class color
{
private:
	char c;

public:
	color();	// default constructor

	// overloaded constructor
	color(char _c);     //w for white, b for black, n for nothing
	
	// getters
	char getColor();

	// setters
	void setColor(char _c);

	// operator overloading 
	bool operator !=(color);
	bool operator ==(color);

	~color()
	{
		// default destructor called.
	}

};

class point			// used to assign coordinates to each piece on the chess-board
{
	// friend function
	friend istream& operator >> (istream&fin, const point &p);
public:

	// data members
	int x;
	int y;

public:
	point();	// default constructor
	point(int, int);  // overloaded constrcutor

	// getters
	int getPointX();  
	int getPointY();
	point getPoint();

	//--------------------------------------

	// setter
	void setPoint(int, int);

	~point()
	{
		// default destructor called
	}
};

class theBoard
{
protected:

	color player;   // player ( whether BLACK or WHITE player's turn )
	point position;		// where the piece is located on the chess-board

public:
	

	theBoard()
	{
		// default constructor 

		// initializes all the data members
		player = NULL;
		position.setPoint(0, 0);
	
	}
	void setBoard(theBoard *b[9][9]);  // this funtion sets the chess-board according to the rules of game.
	void printBoard(theBoard* b[9][9]);   // this function prints the board on console
	void play(theBoard *b[9][9]);  // rules of game
	void checkMate();    // this function checks the checkmate condition ( if the king of player is in danger )

		// this function displays the menu 
	void menu(theBoard *b[9][9]);

	// this function is used to save the game ( as per the rules of game )
	void save(theBoard *b[9][9]);

	// this function reloads the game if player wants ( as per the rules of game )
	void reload(theBoard *b[9][9]);

	// functions are made virtual so that child classes can access them according to their own functionality. 

	virtual void move(theBoard *b[9][9], point p1, point p2) = 0;   // this function is responsible for the movement of pieces on the board
	virtual void attack(theBoard *b[9][9], point p1, point p2) = 0;  // this function kills the other player

	virtual int getValue() = 0;   // this function allocates each piece with a specific code
	virtual color getPlayer() = 0;  // this function tells which player's turn it is to be.

	virtual ~theBoard()
	{
		// default destrcutor
	}
};


class Bishop : public theBoard
{
	// no private data memebers are needed
public:
	// overloaded constructor
	Bishop(point, color);
	void move(theBoard *b[9][9], point p1, point p2);   // for the movement
	void attack(theBoard *b[9][9], point p1, point p2);  // to attack opponent's piece

	int getValue();   // each piece has been assigned specific number
	color getPlayer();  // to determine which player it is

	virtual ~Bishop()
	{
		// default destructor 
	}
};

class King :public theBoard
{

	// no private data memebers are needed
public:
	King(point, color);   // overloaded constructor
	void move(theBoard *b[9][9], point p1, point p2);  // for the movement
	void attack(theBoard *b[9][9], point p1, point p2);   // to attack opponent's piece

	int getValue();    // each piece has been assigned specific number
	color getPlayer();    // to determine which player it is

	virtual ~King()
	{
		// default destructor 
	}

};


class knight : public theBoard
{

	// no private data memebers are needed
public:
	knight(point, color);   // overloaded constructor
	void move(theBoard *b[9][9], point p1, point p2);    // for the movement
	void attack(theBoard *b[9][9], point p1, point p2);    // to attack opponent's piece

	int getValue();     // each piece has been assigned specific number
	color getPlayer();    // to determine which player it is

	virtual ~knight()
	{
		// default destructor 
	}

};

class pawn :public theBoard
{
	// no private data memebers are needed

public:
	pawn(point, color);     // overloaded constructor
	void move(theBoard *b[9][9], point p1, point p2);    // for the movement
	void attack(theBoard *b[9][9], point p1, point p2);    // to attack opponent's piece
	int getValue();    // each piece has been assigned specific number
	color getPlayer();  // to determine which player it is

	void pawnPromotion(theBoard *b[9][9], point p2);  // as per rules og game

	virtual ~pawn()
	{
		// default destructor 
	}
};


class queen :public theBoard
{
	// no private data memebers are needed

public:
	queen(point, color);  // overloaded constructor 
	void move(theBoard *b[9][9], point p1, point p2);     // for the movement
	void attack(theBoard *b[9][9], point p1, point p2);     // to attack opponent's piece

	// each piece has been assigned specific number
	int getValue(); 
	color getPlayer();  // to determine which player it is

	virtual ~queen()
	{
		// default destructor 
	}
};

class rook : public theBoard
{
	// no private data memebers are needed
public:
	rook(point, color);    // overloaded constructor 
	void move(theBoard *b[9][9], point p1, point p2);   // for the movement
	void attack(theBoard *b[9][9], point p1, point p2);   // to attack opponent's piece

		// each piece has been assigned specific number
	int getValue();


	color getPlayer();   // to determine which player it is

	virtual ~rook()
	{
		// default destructor 
	}

};


color::color()  // default constructor
{
	c = '\0';
}

color::color(char _c)
{
	// overloaded 
	if (c == 'w' || c == 'b')
	{
		c = _c;  // whether it's black or white player
	}
	else
	{
		c = '\0';   //else set empty space on the board
	}  
}

// getter

char color::getColor()
{
	return c;
}

// setter

void color::setColor(char _c)
{
	c = _c;
}


// operator overloading
bool color::operator!=(color c2)
{
	if (c != c2.c)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool color::operator==(color c2)
{
	if (c == c2.c)
	{
		return true;
	}
	else
	{
		return false;
	}
}


point::point()
{
	x = 1;
	y = 1;
}

istream & operator >> (istream & fin, point & p)    // friend function
{
	
	fin >> p.x >> p.y;

	return fin;


}

point::point(int x1, int y1)    // setter
{
	if (x >= 1 && x <= 9)
	{
		x = x1;
	}

	if (y >= 1 && y <= 9)
	{
		y = y1;
	}

}

int point::getPointX()   // gets x-coordinate
{
	return x;
}

int point::getPointY()    // gets y-coordinate
{
	return y;
}

point point::getPoint()
{
	point temp(x, y);
	return temp;
}

void point::setPoint(int x1, int y1)
{   
	// sets the point
	x = x1;
	y = y1;
}

Bishop::Bishop(point _p, color _c)
{
	// overloaded const.
	player = _c;
	position = _p;
}

void Bishop::move(theBoard * b[9][9], point p1, point p2)
{

	// determines whose player turn it is
	color tempPlayer = b[p1.getPointX()][p1.getPointY()]->getPlayer();
	bool flag = true;

	if (b[p1.getPointX()][p1.getPointY()]->getValue() == 3)  // if it's bishop 
	{

		if (p1.getPointX() != p2.getPointX() && p1.getPointY() != p2.getPointY())
		{
			// if current row is less than destination row
			if (p1.getPointX() < p2.getPointX())
			{
				// if current coloumn is less than destination 
				if (p1.getPointY() < p2.getPointY())
				{
					//checks all possibilities  from left top to right bottom
					for (int i = p1.getPointX() + 1, j = p1.getPointY() + 1; i <= p2.getPointX(); i++, j++)
					{
						// if block of the board is occupied
						if (b[i][j] != nullptr)
						{
							flag = false;   // flag becomes false
							break;
						}
						else
						{
							flag = true;  // flag becomes true
						}

						if (i == p2.getPointX())
						{
							if (j != p2.getPointY())
							{
								flag = false;
								break;  // flag becomes false
							}
						}
					}
				}
				else if (p1.getPointY() > p2.getPointY())
				{
					// checks from right top to left bottom
					for (int i = p1.getPointX() + 1, j = p1.getPointY() - 1; i <= p2.getPointX(); i++, j--)
					{
						// if it is occupied by some piece
						if (b[i][j] != nullptr)
						{
							flag = false;   // flag becomes false
							break;
						}
						else
						{
							flag = true;    // flag becomes true
						}
						if (i == p2.getPointX())
						{
							if (j != p2.getPointY())
							{
								flag = false;
								break;   // flag becomes false
							}
						}
					}
				}
			}
			else if (p1.getPointX() > p2.getPointX())
			{
				if (p1.getPointY() < p2.getPointY())
				{
					// all possibilities from left bottom to right top of the board
					for (int i = p1.getPointX() - 1, j = p1.getPointY() + 1; i >= p2.getPointX(); i--, j++)
					{
						if (b[i][j] != nullptr)
						{
							flag = false;   // flag becomes false
							break;
						}
						else
						{
							flag = true;
						}
						if (i == p2.getPointX())
						{
							if (j != p2.getPointY())
							{   // flag becomes false
								flag = false;
								break;
							}
						}
					}
				}

				else if (p1.getPointY() > p2.getPointY())
				{

					//from right bottom to left top
					for (int i = p1.getPointX() - 1, j = p1.getPointY() - 1; i >= p2.getPointX(); i--, j--)
					{
						if (b[i][j] != nullptr)
						{
							flag = false;
							break;   // flag becomes false
						}
						else
						{
							flag = true;
						}
						if (i == p2.getPointX())
						{
							if (j != p2.getPointY())
							{
								flag = false;
								break;
							}    // flag becomes false
						}
					}
				}
			}
			if (flag == true)  // if flag becomes true
			{

				// otherwise replace destination with source's piece 
				b[p2.getPointX()][p2.getPointY()] = b[p1.getPointX()][p1.getPointY()];

				// and set current piece empty
				b[p1.getPointX()][p1.getPointY()] = nullptr;
			}
			else
			{
				system("cls");  // clears the whole console 
				cout << "ERROR !!!! This is an illegal move" << endl;
				cout << endl;
			}
		}
		else
		{
		cout << "ERROR !!!! This is an illegal move" << endl;
		cout << endl;
		}
	}

}

void Bishop::attack(theBoard * b[9][9], point p1, point p2)
{
	int temp2 = b[p1.getPointX()][p1.getPointY()]->getValue();
	color temp = b[p1.getPointX()][p1.getPointY()]->getPlayer();
	color temp1 = b[p2.getPointX()][p2.getPointY()]->getPlayer();
	bool flag = true;
	if (b[p1.getPointX()][p1.getPointY()]->getValue() == 3)   // if it's bishop
	{
		if (p1.getPointX() != p2.getPointX() && p1.getPointY() != p2.getPointY())
		{
			//check from left top to right bottom
			if (p1.getPointX() < p2.getPointX())
			{
				if (p1.getPointY() < p2.getPointY())
				{
					//check the very next row
					if (p1.getPointX() == p2.getPointX() - 1 && p1.getPointY() == p2.getPointY() - 1)
					{
						flag = true;   //flag becomes true
					}
					else
					{
						//from right top to left bottom
						for (int i = p1.getPointX() + 1, j = p1.getPointY() + 1; i < p2.getPointX(); i++, j++)
						{
							if (b[i][j] != nullptr)
							{
								flag = false;
								break;
							}
							else
							{
								flag = true;    //flag becomes true
							}

							if (i + 1 == p2.getPointX())
							{
								if (j + 1 != p2.getPointY())
								{
									flag = false;
									break;
								}
							}
						}
					}
				}
				else if (p1.getPointY() > p2.getPointY())
				{   //from left bottom to right top
					if (p1.getPointX() == p2.getPointX() - 1 && p2.getPointY() + 1)
					{
						flag = true;   //flag becomes true
					}
					else
					{
						for (int i = p1.getPointX() + 1, j = p1.getPointY() - 1; i < p2.getPointX(); i++, j--)
						{
							if (b[i][j] != nullptr)
							{
								flag = false;
								break;
							}
							else
							{
								flag = false;
							}
							if (i + 1 == p2.getPointX())
							{
								if (j - 1 != p2.getPointY())
								{
									flag = false;
									break;
								}
							}
						}
					}
				}

				else if (p1.getPointX() > p2.getPointX())
				{
					if (p1.getPointX() < p2.getPointY())
					{   //from right bottom to left top

						if (p1.getPointX() == p2.getPointX() + 1 && p1.getPointY() == p2.getPointY() - 1)
						{
							flag = true;  //flag becomes true
						}
						else
						{
							for (int i = p1.getPointX() - 1, j = p1.getPointY() + 1; i > p2.getPointX(); i--, j++)
							{
								if (b[i][j] == nullptr)
								{
									flag = false;
									break;
								}
								else
								{
									flag = true;  //flag becomes true
								}
								if (i - 1 == p2.getPointX())
								{
									if (j + 1 != p2.getPointY())
									{
										flag = false;
										break;
									}
								}
							}
						}
					}
					else if (p1.getPointY() > p2.getPointY())
					{
						if (p1.getPointX() == p2.getPointX() + 1 && p1.getPointY() == p2.getPointY() + 1)
						{
							flag = true;
						}
						else
						{
							for (int i = p1.getPointX() - 1, j = p1.getPointY() - 1; i < p2.getPointX(); i--, j--)
							{
								if (b[i][j] != nullptr)
								{
									flag = false;
									break;
								}
								else
								{
									flag = true;
								}
								if (i - 1 == p2.getPointX())
								{
									if (j - 1 != p2.getPointY())
									{
										flag = false;
										break;
									}
								}
							}
						}
					}
				}
				if (flag == true)
				{
					if (temp != temp1 && temp2 == 5)
					{
						cout << "***CHECK MATE***" << endl;
						if (temp.getColor() == 'w')
						{
							cout << "PLAYER 1 WINS :D" << endl;
							checkMate();
						}
						else
						{
							cout << "PLAYER 2 WINS :D" << endl;
							checkMate();
						}
					}
					b[p2.getPointX()][p2.getPointY()] = b[p1.getPointX()][p1.getPointY()];
					b[p1.getPointX()][p1.getPointY()] = nullptr;
				}
				else
				{
					system("cls");
					cout << "ERROR !!!! This is an illegal move" << endl;
					cout << endl;
				}

			}

		}
		else
		{
		cout << "ERROR !!!! This is an illegal move" << endl;
		cout << endl;
		}
	}
}

int Bishop::getValue()
{
	return 3;    //bishop is being assigned number 3 ( just for the ease of manipulations )
}

color Bishop::getPlayer()
{
	return player;    // whose turn it is
}

King::King(point p, color c)
{
	position = p;    // set the coordinates and colour of king respectively
	player = c;
}

void King::move(theBoard * b[9][9], point p1, point p2)
{
	color temp = b[p1.getPointX()][p1.getPointY()]->getPlayer();  // checks which player lies on the current piece
	bool flag = true;

	// if king lies at the current piece
	if (b[p1.getPointX()][p1.getPointY()]->getValue() == 5)
	{

		// as we know that king can move one step in all the directions

		// this condition checks in which direction king has moved ( as per the rules of game )

		if (((p1.getPointX() == p2.getPointX() + 1 || p1.getPointX() == p2.getPointX() - 1) && (p1.getPointY() == p2.getPointY() || p1.getPointY() == p2.getPointY() - 1 || p1.getPointY() == p2.getPointY() + 1)) || (p1.getPointX() == p2.getPointX() && (p1.getPointY() == p2.getPointY() - 1 || p1.getPointY() == p2.getPointY() + 1)))
		{
			flag = true;   // then flag becomes true
		}
		else
		{
			flag = false;  // else  flag becomes false
		}
		if (flag == true)
		{
			// otherwise replace destination with source's piece 
			b[p2.getPointX()][p2.getPointY()] = b[p1.getPointX()][p2.getPointY()];
			b[p1.getPointX()][p2.getPointY()] = nullptr;   	// and set current piece empty
			system("cls");   // clears the whole screen of console
		}
		else
		{
			system("cls");		// clears the whole console 
			cout << "ERROR !!!! This is an illegal move" << endl;
			cout << endl;
		}
	}
}

void King::attack(theBoard * b[9][9], point p1, point p2)
{
	bool flag = true;
	color temp = b[p1.getPointX()][p1.getPointY()]->getPlayer();  // it takes which player is located on the current location 
	color temp1 = b[p2.getPointX()][p2.getPointY()]->getPlayer();  // it takes which player is located on the destination location 
	int temp2 = b[p2.getPointX()][p2.getPointY()]->getValue();   // it takes which piece is located on the destination location 


	if (b[p1.getPointX()][p1.getPointY()]->getValue() == 5)    // if it's king 
	{

		// checks all the movements of king 
		if (((p1.getPointX() == p2.getPointX() + 1 || p1.getPointX() == p2.getPointX() - 1) && (p1.getPointY() == p2.getPointY() || p1.getPointY() == p2.getPointY() - 1 || p1.getPointY() == p2.getPointY() + 1)) || (p1.getPointX() == p2.getPointX() && (p1.getPointY() == p2.getPointY() - 1 || p1.getPointY() == p2.getPointY() + 1)))
		{
			flag = true;   // if yes then flag becomes true
		}
		else
		{
			flag = false;
		}

		if (flag == true)
		{
			if (temp != temp1 && temp2 == 5)   	// if destination and source player is not equal
			{
				// and if the opponent's piece is KING 
				cout << "CHECK MATE\n";

				if (temp.getColor() == 'w')
				{
					cout << "WARNING !!!!! CHECK MATE condition " << endl << endl;
					cout << "CONGRATULATIONS !!!!! WHITE player wins" << endl << endl;

					checkMate();
				}
				else
				{
					cout << "WARNING !!!!! CHECK MATE condition " << endl << endl;
					cout << "CONGRATULATIONS !!!!! BLACK player wins" << endl << endl;

					checkMate();
				}

				// otherwise replace destination with source's piece 
				b[p2.getPointX()][p2.getPointY()] = b[p1.getPointX()][p1.getPointY()];
				
				// and set current piece empty
				b[p1.getPointX()][p1.getPointY()] = nullptr;
				system("cls");
			}
		}
		else
		{
			system("cls");		// otherwise simply clear the screen only.
			cout << "ERROR !!!! This is an illegal move" << endl;
		}
	}

}

int King::getValue()
{
	return 5;   // king is being assigned number 5 ( just for the ease of manipulations )
}

color King::getPlayer()
{
	return player;  // whether black or white
}

knight::knight(point p, color c)
{
	// overloaded constructor
	position = p;
	player = c;
}

void knight::move(theBoard * b[9][9], point p1, point p2)
{
	color temp = b[p1.getPointX()][p1.getPointY()]->getPlayer();  // determines whose player turn it is
	bool flag = true;

	if (b[p1.getPointX()][p1.getPointY()]->getValue() == 2)  // if it's knight
	{
		if (p1.getPointX() < p2.getPointX())   // if current row is less than destination row
		{  

			//checks all possibilities of movemennt of knight
			if ((p1.getPointX() == p2.getPointX() - 1 && p1.getPointY() == p2.getPointY() - 2) || (p1.getPointX() == p2.getPointX() - 2 && p1.getPointY() == p2.getPointY() - 1) || (p1.getPointX() == p2.getPointX() - 1 && p1.getPointY() == p2.getPointY() + 2) || (p1.getPointX() == p2.getPointX() - 2 && p1.getPointY() == p2.getPointY() + 1))
			{
				flag = true;  // flag becomes true

			}
			else
			{
				flag = false;
			}
		}

		else if (p1.getPointX() > p2.getPointX())
		{
			if ((p1.getPointX() == p2.getPointX() + 1 && p1.getPointY() == p2.getPointY() - 2) || (p1.getPointX() == p1.getPointX() + 2 && p1.getPointY() == p2.getPointY() - 1) || (p1.getPointX() == p2.getPointX() + 1 && p1.getPointY() == p1.getPointY() + 2) || (p1.getPointX() == p2.getPointX() + 2 && p1.getPointY() == p1.getPointY() + 1))
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}

		else
		{
			flag = false;
		}

		if (flag == true)  // if flag becomes true
		{
			// otherwise replace destination with source's piece 
			b[p2.getPointX()][p2.getPointY()] = b[p1.getPointX()][p1.getPointY()];

			// and set current piece empty
			b[p1.getPointX()][p1.getPointY()] = nullptr;
			system("cls");  // clears the whole screen of console

		}
		else
		{
			system("cls");		// clears the whole console 
			cout << "ERROR !!!! This is an illegal move" << endl;
			cout << endl;
		}
	}
}

void knight::attack(theBoard * b[9][9], point p1, point p2)
{
	color temp = b[p1.getPointX()][p1.getPointY()]->getPlayer();  // it takes which player is located on the current location 
	color temp1 = b[p2.getPointX()][p2.getPointY()]->getPlayer();
	// it takes which player is located on the destination location 

	int temp2 = b[p2.getPointX()][p2.getPointY()]->getValue();    // it takes which piece is located on the destination location 


	bool flag = true;

	if (b[p1.getPointX()][p1.getPointY()]->getValue() == 2)  // if it's knight
	{
		// checks all the movements of knight 
		if (p1.getPointX() < p2.getPointX())
		{
			if ((p1.getPointX() == p2.getPointX() - 1 && p1.getPointY() == p2.getPointY() - 2) || (p1.getPointX() == p2.getPointX() - 2 && p1.getPointY() == p2.getPointY() - 1) || (p1.getPointX() == p2.getPointX() - 1 && p1.getPointY() == p2.getPointY() + 2) || (p1.getPointX() == p2.getPointX() - 2 && p1.getPointY() == p2.getPointY() + 1))
			{
				flag = true;   // if yes then flag becomes true

			}
			else
			{
				flag = false;  // otherwise flag becomes false
			}
		}

		else if (p1.getPointX() > p2.getPointX())
		{
			if ((p1.getPointX() == p2.getPointX() + 1 && p1.getPointY() == p2.getPointY() - 2) || (p1.getPointX() == p1.getPointX() + 2 && p1.getPointY() == p2.getPointY() - 1) || (p1.getPointX() == p2.getPointX() + 1 && p1.getPointY() == p1.getPointY() + 2) || (p1.getPointX() == p2.getPointX() + 2 && p1.getPointY() == p1.getPointY() + 1))
			{
				flag = true;
			}
			else
			{
				flag = false;  // otherwise flag becomes false
			}
		}

		else
		{
			flag = false;   // otherwise flag becomes false
		}

		if (flag == true)
		{
			if (temp != temp2 && temp2 == 5)
			{
				cout << "CHECK MATE" << endl;

				if (temp.getColor() == 'w')
				{
					cout << "WARNING !!!!! CHECK MATE condition " << endl << endl;
					cout << "CONGRATULATIONS !!!!! WHITE player wins" << endl << endl;

					checkMate();
				}
				else
				{

					cout << "WARNING !!!!! CHECK MATE condition " << endl << endl;
					cout << "CONGRATULATIONS !!!!! BLACK player wins" << endl << endl;

					checkMate();
				}

				// otherwise replace destination with source's piece 
				b[p2.getPointX()][p2.getPointY()] = b[p1.getPointX()][p1.getPointY()];

				// and set current piece empty
				b[p1.getPointX()][p1.getPointY()] = nullptr;
				system("cls");


			}
			else
			{

				system("cls");		// otherwise simply clear the screen only.
				cout << "ERROR !!!! This is an illegal move" << endl;
			}
		}


	}

}

int knight::getValue()
{
	return 2;   // knight is being assigned number 2 ( just for the ease of manipulations )
}

color knight::getPlayer()
{
	return player;   // if it's black / white player
}

pawn::pawn(point p, color c)
{
	position = p;   // set the colour and position of pawn on the board ar its respective cordinates
	player = c;
}

void pawn::move(theBoard * b[9][9], point p1, point p2)
{
	bool flag = 0;
	color temp = b[p1.getPointX()][p1.getPointY()]->getPlayer();  // determines whether it's black or white player

	if (b[p1.getPointX()][p1.getPointY()]->getValue() == 6)   // if it's pawn
	{
		if (p1.getPointY() == p2.getPointY() && p1.getPointX() != p2.getPointY())
		{
			// if it's white player
			if (b[p1.getPointX()][p1.getPointY()]->getPlayer().getColor() == 'w')
			{
				// as white player is at the end of board so ,we check 7th row of the chess-board
				if (p1.getPointX() == 7)
				{
					// if it is first move then pawn can move either 1 or 2 steps forward.
					// if that particular posiion of chess-board is not empty

					if ((p2.getPointX() == p1.getPointX() - 1) && b[p2.getPointX()][p2.getPointY()] == nullptr)
					{
						flag = true;
					}

					// if that particular posiion of chess-board is not empty
					else if ((p1.getPointX() - 2 == p2.getPointX()) && (b[p2.getPointX()][p2.getPointY()] == nullptr) && (b[p1.getPointX() - 1][p2.getPointY()] == nullptr))
					{
						flag = true;
					}
					else
					{
						flag = false;   // otherwise flag = false in every other condition
					}
				}

				else
				{
					if ((p2.getPointX() == p1.getPointX() - 1) && b[p2.getPointX()][p2.getPointY()] == nullptr)
					{
						// if the destination is empty then pawn can move at that place
						flag = true;   	// so flag = true respectively
					}
					else
					{
						flag = false;  	// so flag = false
					}
				}
			}

			// now in the same way  for player 2

			else if (b[p1.getPointX()][p1.getPointY()]->getPlayer().getColor() == 'b')
			{
				if (p1.getPointX() == 2)  // if it is first move then pawn can move either 1 or 2 steps forward.
				{
					// so either it can move one step forward
					if ((p1.getPointX() + 1 == p2.getPointX()) && b[p2.getPointX()][p2.getPointY()] == nullptr)
					{
						flag = true;
					}

					// or it can move 2 steps forward respectively ( as per the rules of game )
					else if ((p1.getPointX() + 2) == p2.getPointX() && (b[p2.getPointX()][p2.getPointY()] == nullptr) && (b[p1.getPointX() + 1][p2.getPointY()] == nullptr))
					{
						flag = 1;
					}
					else
					{
						flag = 0;  // otherwise flag = false in every other condition 
					}
				}
				else
				{
					// if the destination is not occupied
					if ((p1.getPointX() + 1 == p2.getPointX()) && b[p2.getPointX()][p2.getPointY()] == nullptr)
					{
						flag = 1;
						// then pawn can move at it's desired destination 
						// so flag = true respectively
					}
					else
					{
						flag = 0;
					}
				}
			}
		}
		else
		{
			// else pawn cannot move at desired destination 
			// so flag = flase respectively 
			flag = 0;
		}

		if (flag == 1)
		{
			// move pawn to the destination index
			b[p2.getPointX()][p2.getPointY()] = b[p1.getPointX()][p1.getPointY()];
			b[p1.getPointX()][p1.getPointY()] = nullptr;   // and free up space of source index respectively

			if (p2.getPointX() == 1)   // if pawn reaches at the end of board then pawn promotion occurs ( as per rules of game )
			{
				pawnPromotion(b, p2);
			}
			else if (p2.getPointX() == 8)  // if pawn reaches at the end of board then pawn promotion occurs ( as per rules of game )
			{
				pawnPromotion(b, p2);   // pawn promotion occurs
			}
			system("cls");      // clears the screen of console application

		}
		else
		{
			// if flag is not true then program clears the screen
			system("cls");

			cout << "ERROR !!!! This is an illegal move. Pawn cannot move in this way. " << endl << endl;

		}
	}
}

void pawn::attack(theBoard * b[9][9], point p1, point p2)
{
	bool flag = 1;
	color temp = b[p1.getPointX()][p1.getPointY()]->getPlayer();  // determines which piece is located on the desination index


	int temp1 = b[p1.getPointX()][p1.getPointY()]->getValue();  // determines which player is located on the desination index
	
	int temp2 = b[p2.getPointX()][p2.getPointY()]->getValue();   // determines which player is located on the source index

	if (b[p1.getPointX()][p1.getPointY()]->getValue() == 6)  // if it's pawn
	{  
		// if current coloumn is not equal to destination coloumn
		if (p1.getPointX() != p2.getPointX() && p1.getPointY() == p2.getPointY())
		{
			flag = true;
		}

		// white player's check 
		if (b[p1.getPointX()][p1.getPointY()]->getPlayer().getColor() == 'w')
		{
			if (p1.getPointX() - 1 == p2.getPointX() && (p1.getPointY() == p2.getPointY() + 1 || position.getPointY() == p2.getPointY() - 1) && b[p2.getPointX()][p2.getPointY()] != nullptr)
			{
				flag = 1;   	// if destination index is occupied
			}
			else
			{
				flag = 0;  // otherwise flag = false in every other condition
			}
		}
		else
		{
			if (p1.getPointX() + 1 == p2.getPointX() && (p1.getPointY() == p2.getPointY() + 1 || position.getPointY() == p2.getPointY() - 1) && b[p2.getPointX()][p2.getPointY()] != nullptr)
			{
				flag = 1;  // if destination index is occupied
			}
			else
			{
				flag = 0;   // otherwise flag = false in every other condition 
			}
		}
		if (flag == 1)   // if attack can be done then 
		{
			if (temp != temp1 && temp2 == 5)   // if destination and source player is not equal
			{
				// and if the opponent's piece is KING 
				

				if (temp.getColor() == 'w')
				{
					cout << "WARNING !!!!! CHECK MATE condition " << endl << endl;
					cout << "CONGRATULATIONS !!!!! WHITE player wins" << endl << endl;

					checkMate();
				}
				else
				{
					cout << "WARNING !!!!! CHECK MATE condition " << endl << endl;
					cout << "CONGRATULATIONS !!!!! BLACK player wins" << endl << endl;
					checkMate();
				}
			}

			// otherwise replace destination with source's piece 
			b[p2.getPointX()][p2.getPointY()] = b[p1.getPointX()][p1.getPointY()];
			b[p1.getPointX()][p1.getPointY()] = nullptr;   	// and set current piece empty
			 
			if (p2.getPointX() == 1)  // if pawn reaches at the end of board
			{
				pawnPromotion(b, p2);  // then pawn promotion occurs
			}
			else if (p2.getPointX() == 8)  // if pawn reaches at the end of board
			{
				pawnPromotion(b, p2);  // then pawn promotion occurs
			}
			system("cls");

		}
		else
		{
			cout << "ILLEGAL MOVE" << endl;
			system("cls");
		}
	}

}

int pawn::getValue()
{
	return 6;  // pawn is being assigned number 6 ( just for the ease of manipulations )
}

color pawn::getPlayer()
{
	// determines which player it is (whether black or white )

	return player;
} 

void pawn::pawnPromotion(theBoard * b[9][9], point p2)
{
	color temp1('w');
	color temp2('b');

	
	cout << "----------------------------------------------------------------------" << endl << endl;

	cout << "*********************** PAWN PROMOTION *******************************" << endl << endl;

	cout << "Please enter in which piece you want your pawn to be promoted: " << endl << endl;

	cout << "If you want your pawn to be promoted in ROOK then enter 1." << endl << endl;

	cout << "If you want your pawn to be promoted in KNIGHT then enter 2." << endl << endl;

	cout << "If you want your pawn to be promoted in BISHOP then enter 3." << endl << endl;

	cout << "If you want your pawn to be promoted in QUEEN then enter 4." << endl << endl;

	cout << "**********************************************************************" << endl << endl;
	int choice;

	cin >> choice;

	cout << "---------------------------------------------------------------------" << endl << endl;

	if (choice == 1)   // if user enters 1 then convert to ROOK 
	{
		if (p2.getPointX() == 1)  // if it's white player
		{
			b[p2.getPointX()][p2.getPointY()] = new rook(p2, temp1);  // then set in first row
		}
		else if (p2.getPointX() == 8)
		{// if it's white player
			b[p2.getPointX()][p2.getPointY()] = new rook(p2, temp2);  // then set in last row
		}
	}

	else if (choice == 2)  // if user enters 2 then convert to KNIGHT
	{ 
		// if it's white player
		if (p2.getPointX() == 1)
		{
			b[p2.getPointX()][p2.getPointY()] = new knight(p2, temp1);   // then set in first row
		}
		else if (p2.getPointX() == 8)
		{
			b[p2.getPointX()][p2.getPointY()] = new knight(p2, temp2);   // then set in last row
		}
	}

	else if (choice == 3)  // if user enters 3 then convert to BISHOP
	{
		if (p2.getPointX() == 1)
		{ // if it's white player
			b[p2.getPointX()][p2.getPointY()] = new Bishop(p2, temp1);
		}// then set in first row
		else if (p2.getPointX() == 8)  // if it's white player
		{
			b[p2.getPointX()][p2.getPointY()] = new Bishop(p2, temp2);  // then set in last row
		}
	}

	else if (choice == 4)  // if user enters 4 then convert to QUEEN
	{
		if (p2.getPointX() == 1)
		{
			b[p2.getPointX()][p2.getPointY()] = new queen(p2, temp1);
		}
		else if (p2.getPointX() == 8)
		{
			b[p2.getPointX()][p2.getPointY()] = new queen(p2, temp2);
		}
	}
	else
	{
		cout << "ERROR !! You entered wrong choice . Please enter correctly." << endl << endl;

	}
}

//constructor for queen
queen::queen(point p, color c)
{
	position = p;
	player = c;
}


//this function is called to movie piece by board if the current poece is queen
void queen::move(theBoard * b[9][9], point p1, point p2)
{
	color temp = b[p1.getPointX()][p1.getPointY()]->getPlayer();
	bool flag = true;
	int v = 4;

	if (b[p1.getPointX()][p1.getPointY()]->getValue() == v)
	{
		//checks for the queen to move either up, down, left or right on the board
		if (p1.getPointY() == p2.getPointY() && p1.getPointX() != p2.getPointX())
		{
			if (p1.getPointX() > p2.getPointX())
			{
				for (int i = p1.getPointX() - 1; i >= p2.getPointX(); i--)
				{
					if (b[i][p1.getPointY()] != nullptr)
					{
						flag = false;
						break;
					}
					else
					{
						flag = true;
					}
				}
			}
			else if (p1.getPointX() < p2.getPointX())
			{
				for (int a = p1.getPointX() + 1; a < -p2.getPointX(); a++)
				{
					if (b[a][p1.getPointY()] != nullptr)
					{
						flag = false;
						break;
					}
					else
					{
						flag = true;
					}
				}
			}
			else
			{
				flag = false;
			}
		}
		//checks for the validation pf sidwatys movement of queen

		else if (p1.getPointX() == p2.getPointX() && p1.getPointY() != p2.getPointY())
		{
			if (p1.getPointY() < p2.getPointY())
			{
				for (int i = p1.getPointX() - 1; i >= p2.getPointX(); i--)
				{
					if (b[p1.getPointX()][i] != nullptr)
					{
						flag = false;
						break;
					}
					else
					{
						flag = true;
					}
				}
			}

			else if (p1.getPointY() > p2.getPointY())
			{
				for (int i = p1.getPointY() - 1; i >= p2.getPointY(); i--)
				{
					if (b[p1.getPointX()][i] == nullptr)
					{
						flag = true;
					}
					else
					{
						flag = false;
						break;
					}
				}
			}
			else
			{
				flag = false;
			}
		}


		////checks the diagonal movements of the piece
		else if (p1.getPointX() != p1.getPointX() && p1.getPointY() != p2.getPointY())
		{
			//checks if it has to go up or down
			if (p1.getPointX() < p2.getPointX())
			{
				if (p1.getPointY() < p2.getPointY())
				{
					for (int i = p1.getPointX() + 1, j = p1.getPointY() + 1; i <= p2.getPointX(); i++, j++)
					{
						if (b[i][j] != nullptr)
						{
							flag = false;
							break;
						}
						else
						{
							flag = true;
						}

						if (i == p2.getPointX())
						{
							if (j != p2.getPointY())
							{
								flag = 0;
								break;
							}
						}

					}
				}
				else if (p1.getPointY() > p2.getPointY())
				{
					for (int k = p1.getPointX() + 1, l = p1.getPointY() - 1; k <= p2.getPointX(); k++, l--)
					{
						if (b[k][l] != nullptr)
						{
							flag = false;
							break;
						}
						else
						{
							flag = true;
						}
						if (k == p2.getPointX())
						{
							if (k != p2.getPointY())
							{
								flag = false;
								break;
							}
						}
					}
				}
			}


			//check to validate the movement of piece left ways and sideways
			else if (p1.getPointY() > p2.getPointY()) //rb rl
			{
				for (int i = p1.getPointX() - 1, j = p1.getPointY() - 1; i > -p2.getPointX(); i--, j--)
				{
					if (b[i][j] != nullptr)
					{
						flag = false;
						break;
					}
					else
					{
						flag = true;
					}
					if (i == p2.getPointX())
					{
						if (j != p2.getPointY())
						{
							flag = false;
							break;
						}
					}
				}
			}
		}
		else
		{
			flag = 0;
		}

		if (flag != 0)
		{
			b[p2.getPointX()][p2.getPointY()] = b[p1.getPointX()][p1.getPointY()];
			b[p1.getPointX()][p1.getPointY()] = nullptr;
			system("cls");
		}

		else
		{
			system("cls");
			cout << " IILEGAL MOVE" << endl;
		}
	}
}


//this function is called in play of board when a queen object come across and the choice is to attack or capture piece
void queen::attack(theBoard * b[9][9], point p1, point p2)
{
	bool flag = 0;
	int temp2 = b[p2.getPointX()][p2.getPointY()]->getValue();
	color temp1 = b[p2.getPointX()][p2.getPointY()]->getPlayer();
	color temp = b[p1.getPointX()][p1.getPointY()]->getPlayer();



	if (b[p1.getPointX()][p1.getPointY()]->getValue() == 4)
	{
		if (p1.getPointY() == p2.getPointY() && p1.getPointX() != p2.getPointX())
		{
			if (p1.getPointX() < p2.getPointX())
			{
				if (p1.getPointX() == p2.getPointX() - 1)
				{
					flag = true;
				}
				else
				{
					for (int i = p1.getPointX() + 1; i < p2.getPointX(); i++)
					{
						if (b[i][p2.getPointY()] != nullptr)
						{
							flag = false;
							break;
						}
						else
						{
							flag = true;
						}
					}
				}
			}
			else if (p1.getPointX() > p2.getPointX())
			{
				if (p1.getPointX() == p2.getPointX() + 1)
				{
					flag = true;
				}
				else
				{
					for (int i = p1.getPointX() - 1; i > p2.getPointX(); i--)
					{
						if (b[i][p2.getPointY()] != nullptr)
						{
							flag = false;
							break;
						}
						else
						{
							flag = true;
						}
					}
				}
			}

			else if (p1.getPointX() == p2.getPointY() && p1.getPointY() != p2.getPointY())
			{
				if (p1.getPointY() < p2.getPointY())
				{
					if (p1.getPointY() == p2.getPointY() + 1)
					{
						flag = true;
					}
					else
					{
						for (int i = p1.getPointY() + 1; i < p2.getPointY(); i++)
						{
							if (b[p2.getPointY()][i] != nullptr)
							{
								flag = false;
								break;
							}
							else
							{
								flag = true;
							}
						}
					}
				}
				else if (p1.getPointY() > p2.getPointY())
				{
					if (p2.getPointY() - 1 == p1.getPointY())
					{
						flag = true;
					}
					else
					{
						for (int i = p1.getPointX() - 1; i > p2.getPointY(); i--)
						{
							if (b[p2.getPointY()][i] != nullptr)
							{
								flag = false;
								break;
							}
							else
							{
								flag = true;
							}
						}
					}
				}
			}

			//checks to confirm the diagnal uo or giaginak down movement of the queen piece in the chess board;
			else if (p1.getPointX() != p2.getPointX() && p1.getPointY() != p2.getPointY())
			{
				if (p1.getPointX() < p2.getPointX())
				{
					if (p1.getPointY() < p2.getPointY())
					{
						if (p1.getPointX() == p1.getPointX() - 1 && p2.getPointY() - 1 == p1.getPointY())
						{
							flag = true;
						}
						else
						{
							for (int i = p1.getPointX() + 1, j = p1.getPointY() + 1; i < p2.getPointX(); i++, j++)
							{
								if (b[i][j] != nullptr)
								{
									flag = false;
									break;
								}
								else
								{
									flag = true;
								}
								if (i + 1 == p2.getPointX())
								{
									if (j + 1 != p2.getPointY())
									{
										flag = false;
										break;
									}
								}
							}

						}
					}
				}

				else if (p1.getPointY() > p2.getPointY())
				{
					if (p1.getPointX() == p2.getPointX() - 1 && p1.getPointY() == p2.getPointY() + 1)
					{
						flag = true;
					}
					else
					{
						for (int i = p1.getPointX() + 1, j = p1.getPointY() - 1; i > p2.getPointX(); i++, j--)
						{
							if (b[i][j] != nullptr)
							{
								flag = false;
								break;
							}
							else
							{
								flag = 1;
							}
							if (i + 1 == p2.getPointX())
							{
								if (j - 1 != p2.getPointY())
								{
									flag = false;
									break;
								}
							}
						}
					}
				}
			}

			else if (p1.getPointX() > p2.getPointX())
			{
				if (p1.getPointY() < p2.getPointY())
				{
					if (p1.getPointX() == p2.getPointX() + 1 && p1.getPointY() == p2.getPointY() - 1)
					{
						flag = 1;
					}
					else
					{
						for (int i = p1.getPointX() - 1, j = p1.getPointY() + 1; i > p2.getPointX(); i--, j++)
						{
							if (b[i][j] != nullptr)
							{
								flag = false;
								break;
							}
							else
							{
								flag = 1;
							}
							if (i - 1 == p2.getPointX())
							{
								if (j + 1 != p2.getPointY())
								{
									flag = false;
									break;
								}
							}
						}
					}
				}
				else if (p1.getPointY() > p2.getPointY())
				{
					if (p1.getPointX() == p2.getPointX() + 1 && p1.getPointY() == p2.getPointY() + 1)
					{
						flag = true;
					}
					else
					{
						for (int i = p1.getPointX() - 1, j = p1.getPointY() - 1; i > p2.getPointX(); i--, j--)
						{
							if (b[i][j] != nullptr)
							{
								flag = false;
								break;
							}
							else
							{
								flag = 1;
							}
							if (i - 1 == p2.getPointX())
							{
								if (j - 1 != p2.getPointY())
								{
									flag = false;
									break;
								}
							}
						}
					}
				}
			}


		}
		else
		{
			flag = 0;
		}
		if (flag == 1)
		{
			if (temp != temp1 && temp2 == 5)
			{
				cout << "CHECK MATE" << endl;
				if (temp.getColor() == 'w')
				{
					cout << "PLAYER 1 WINS" << endl;
					checkMate();
				}
				else
				{
					cout << "PLAYER 2 WINS" << endl;
					checkMate();
				}
			}
			b[p2.getPointX()][p2.getPointY()] = b[p1.getPointX()][p1.getPointY()];
			b[p1.getPointX()][p2.getPointY()] = nullptr;
			system("cls");
		}
		else
		{
			system("cls");
			cout << "ILLEGAL MOVE" << endl;
		}


	}
}

//this resturn the value of rook which we set to be 4 for convinience
int queen::getValue()
{
	return 4;
}

//this returns the "player" that is the color of the queen that is present at the moment
color queen::getPlayer()
{
	return player;
}

//constructor for rook that takes point p and color c types object
rook::rook(point p, color c)
{
	position = p;
	player = c;
}

void rook::move(theBoard * b[9][9], point p1, point p2)
{
	color temp = b[p1.getPointX()][p1.getPointY()]->getPlayer();
	bool flag = true;
	int v = 1;

	if (b[p1.getPointX()][p1.getPointY()]->getValue() == v)
	{
		if (p1.getPointX() == p2.getPointX() && p2.getPointY() == p1.getPointY()) //check if the horizontal coast is clear for the current rook
		{
			if (p1.getPointX() > p2.getPointX()) //if X of p1 is greater than of p2 meaning going sideways
			{
				for (int i = p1.getPointX() - 1; i >= p2.getPointY(); i--)
				{
					if (b[i][p1.getPointY()] != nullptr)
					{
						flag = false;
						break;
					}
					else
					{
						flag = 1;
					}
				}
			}
			else if (p1.getPointX() < p2.getPointX()) //if X of p1 is less than of p2 while goign sideways
			{
				for (int i = p1.getPointX() + 1; i <= p2.getPointY(); i++)
				{
					if (b[i][p1.getPointY()] != nullptr)
					{
						flag = false;
						break;
					}
					else
					{
						flag = 1;
					}
				}
			}
		}
		else if (p1.getPointX() == p2.getPointY() && p1.getPointY() != p2.getPointY()) //if the horizantal path is not equal meaning the Y coordinates of  p1, p2 are unequal
		{
			if (p1.getPointY() < p2.getPointY()) //going downwards
			{
				for (int i = p1.getPointY() + 1; i <= p2.getPointY(); i++)
				{
					if (b[p1.getPointX()][i] != nullptr)
					{
						flag = 0;
						break;
					}
					else
					{
						flag = 1;
					}
				}
			}
			else if (p1.getPointY() > p2.getPointY()) //going  to check vertically
			{

				for (int i = p1.getPointY() - 1; i >= p2.getPointY(); i--)
				{
					if (b[p1.getPointX()][i] != nullptr)
					{
						flag = 0;
						break;
					}
					else
					{
						flag = 1;
					}
				}
			}
		}
		else
		{
			flag = 0;
		}
		if (flag == 1)
		{
			b[p2.getPointX()][p2.getPointY()] = b[p1.getPointX()][p1.getPointY()];
			b[p1.getPointX()][p1.getPointY()] = nullptr;
			system("cls");
		}

		else
		{
			system("cls");
			cout << "ILLEGAL MOVE " << endl;
		}
	}
}


//rook moves forward, backward, left, right
void rook::attack(theBoard * b[9][9], point p1, point p2)
{
	bool flag = 1;
	color temp = b[p1.getPointX()][p1.getPointY()]->getPlayer();
	color temp1 = b[p2.getPointX()][p2.getPointY()]->getPlayer();
	int temp2 = b[p2.getPointX()][p2.getPointY()]->getValue();


	int v = 1;

	if (b[p1.getPointX()][p1.getPointY()]->getValue() == v)
	{
		if (b[p2.getPointX()][p2.getPointY()] != nullptr) //if the desired point is occupied then attack
		{
			if (p1.getPointY() == p2.getPointY() && p1.getPointX() != p2.getPointX()) //for the vertical movement, the Y of p1 and p2 should be same
			{
				if (p1.getPointX() < p2.getPointX()) //if X of p1 is less than X of p2 then X of p1 
				{
					if (p1.getPointX() == p2.getPointX() - 1)
					{
						flag = true;
					}
					else
					{
						for (int i = p1.getPointX() + 1; i < p2.getPointX(); i++)
						{
							if (b[i][p2.getPointY()] != nullptr)
							{
								flag = false;
								break;
							}
							else
							{
								flag = true;
							}
						}
					}
				}
				else if (p1.getPointX() > p2.getPointX()) //if X of p1 is greater than X of p2 then X of p1 
				{
					if (p1.getPointX() == p2.getPointX() + 1)
					{
						flag = 1;
					}
					else
					{
						for (int i = p1.getPointX() - 1; i > p2.getPointX(); i--)
						{
							if (b[i][p2.getPointY()] != nullptr)
							{
								flag = false;
								break;
							}
							else
							{
								flag = true;
							}
						}
					}
				}
			}
			else if (p1.getPointX() == p2.getPointX() && p1.getPointY() != p1.getPointY()) // if the vertical componoents of p1 and p2 are not equal but x are meaning sideways movement
			{
				if (p1.getPointY() < p2.getPointY())
				{
					if (p1.getPointY() == p2.getPointY() + 1)
					{
						flag = true;
					}
					else
					{
						for (int i = p1.getPointY() + 1; i < p2.getPointY(); i++)
						{
							if (b[p2.getPointY()][i] != nullptr)
							{
								flag = false;
								break;
							}
							else
							{
								flag = 1;
							}
						}
					}
				}
				else if (p1.getPointY() > p2.getPointY())
				{
					if (p1.getPointY() == p2.getPointY() - 1)
					{
						flag = true;
					}
					else
					{
						for (int i = p1.getPointY() - 1; i > p2.getPointY(); i--)
						{
							if (b[p2.getPointY()][i] != nullptr)
							{
								flag = false;
								break;
							}
							else
							{
								flag = true;
							}
						}

					}
				}
			}
			else
			{
				flag = 0;
			}


			if (flag == 1)
			{
				if (temp1 != temp && temp2 == 5)
				{
					cout << "CHECK MATE";
					{
						if (temp.getColor() == 'w')
						{
							cout << "PLAYER 1 WINS " << endl;
							checkMate();
						}
						else
						{
							cout << "PLAYER 2 WINS " << endl;
							checkMate();
						}
					}
				}

				b[p2.getPointX()][p2.getPointY()] = b[p1.getPointX()][p1.getPointY()]; //setting new position for rook
				b[p1.getPointX()][p1.getPointY()] = nullptr; //pointing old position to nullptr

				system("cls");
			}
			else
			{
				system("cls");
				cout << "ILLEGAL MOVE";
			}
		}
		else
		{
			system("cls");
			cout << "ILLEGAL MOVE";
		}
	}

}


//this resturn the value of rook which we set to be 1 for convinience
int rook::getValue()
{
	return 1;
}


//this returns the "player" that is the color of the rook that is present at the moment
color rook::getPlayer()
{
	return player;
}


//the board functions is used to set the pieces on the board
//the chess board is set by using indexes, setting the current point temp1 and color temp

void theBoard::setBoard(theBoard * b[9][9])
{
	color temp;
	temp.setColor('b');
	point temp1;


	//temp is set to be black, first we set the pieces of black player
	temp1.setPoint(1, 1);
	b[1][1] = new rook(temp1, temp);
	temp1.setPoint(1, 8);
	b[1][8] = new rook(temp1, temp);

	temp1.setPoint(1, 2);
	b[1][2] = new knight(temp1, temp);
	temp1.setPoint(1, 7);
	b[1][7] = new knight(temp1, temp);

	temp1.setPoint(1, 3);
	b[1][3] = new Bishop(temp1, temp);
	temp1.setPoint(1, 6);
	b[1][6] = new Bishop(temp1, temp);

	temp1.setPoint(1, 5);
	b[1][5] = new King(temp1, temp);
	temp1.setPoint(1, 4);
	b[1][4] = new queen(temp1, temp);

	//pawns of back pair set in a loop 
	for (int i = 1; i < 9; i++)
	{
		temp1.setPoint(2, i);
		b[2][i] = new pawn(temp1, temp);
	}

	//color is switched to white to set the pieces of white player
	temp.setColor('w');

	temp1.setPoint(8, 1);
	b[8][1] = new rook(temp1, temp);
	temp1.setPoint(8, 8);
	b[8][8] = new rook(temp1, temp);

	temp1.setPoint(8, 2);
	b[8][2] = new knight(temp1, temp);
	temp1.setPoint(8, 7);
	b[8][7] = new knight(temp1, temp);

	temp1.setPoint(8, 3);
	b[8][3] = new Bishop(temp1, temp);
	temp1.setPoint(8, 6);
	b[8][6] = new Bishop(temp1, temp);

	temp1.setPoint(8, 5);
	b[8][5] = new King(temp1, temp);
	temp1.setPoint(8, 4);
	b[8][4] = new queen(temp1, temp);


	//loop for setting the pawns of white pieces
	for (int i = 1; i < 9; i++)
	{
		temp1.setPoint(7, i);
		b[7][i] = new pawn(temp1, temp);
	}


	//initiliazing the empty cells of the chessboard with null pointer so that they can be occupied later if needed
	for (int j = 3; j < 7; j++)
	{
		for (int k = 1; k < 9; k++)
		{
			b[j][k] = nullptr;
		}
	}


}


//a basic function of class board which prints the board accordingly;
void theBoard::printBoard(theBoard * b[9][9])
{
	cout << endl << endl;
	cout << "PRESS 1 TO SEE MENU" << endl;
	cout << "PRESS 2 TO SAVE GAME" << endl;
	cout << endl << endl;
	cout << " 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t" << endl;

	//loop to print the vertical side of the chess board
	for (int i = 1; i < 9; i++)
	{
		cout << i << "|";

		for (int j = 1; j < 9; j++)
		{
			if (b[i][j] != nullptr)
			{
				int temp = b[i][j]->getValue();
				color temp1 = b[i][j]->getPlayer(); //checking what player it is

				if (temp == 6)
				{
					if (temp1.getColor() == 'w')
					{
						cout << " WP ";
					}
					else
						cout << " BP ";
				}

				else if (temp == 1)
				{
					if (temp1.getColor() == 'w')
					{
						cout << " WR ";
					}
					else
					{
						cout << " BR ";
					}
				}

				else if (temp == 3)
				{
					if (temp1.getColor() == 'w')
					{
						cout << " WB ";
					}
					else
					{
						cout << " BB ";
					}

				}

				else if (temp == 4)
				{
					if (temp1.getColor() == 'w')
					{
						cout << " WQ ";
					}
					else
					{
						cout << " BQ ";
					}
				}

				else if (temp == 2)
				{
					if (temp1.getColor() == 'w')
					{
						cout << " WN ";
					}
					else
					{
						cout << " BN ";
					}
				}

				else if (temp == 5)
				{
					if (temp1.getColor() == 'w')
					{
						cout << " WK ";
					}
					else
					{
						cout << " BK ";
					}
				}
			}

			else
			{
				cout << "    ";
			}

			cout << " | ";
		}



		cout << endl << endl;
	}




}


//one of the main function that does the job of displaying updating board, making moves and calling respective moves,
//checks the condition of checkmate
void theBoard::play(theBoard * b[9][9])
{
	bool cm = 0; //checkmate flag , updates for every piece on board
	bool flag = 0; //bool

	printBoard(b); //load board

	point CP; //current point where the piece currently is
	point DP; //desires point where the piece wannts to go

	int choice = 0, counter = 0; //default
	color count('w');
	color turn1('w');
	char input;

	int temp = 0, temp2 = 0, temp3 = 0;
	color temp1('\0');

	while (cm == 0)
	{/*
		cout << " Press 6 to move " << endl;
		cout << " Press 7 to attack" << endl;*/
		cout << "Press 1 to move and press 2 to attack" << endl;

		cin >> choice;

		cout << "Enter the current position in x and y coordinates (e.g 1,2)";
		cin >> CP;
		cout << "Enter the desired position in x and y coordinates (e.g 1,2)";
		cin >> DP;

		//getting what player turn it is
		if (b[CP.getPointX()][CP.getPointY()] != nullptr)
		{
			turn1 = b[CP.getPointX()][CP.getPointY()]->getPlayer();
		}

		//condition for valid move
		if (counter == 1 && count.getColor() == turn1.getColor())
		{
			system("cls");
			cout << "***********ILLEGAL MOVE*****************" << endl;
			if (turn1.getColor() == 'w')
			{
				cout << "Player 1 turns " << endl;
			}
			else
			{
				if (turn1.getColor() == 'b')
				{
					cout << "Player 2 turns " << endl;
				}
				else
				{
					cout << "Player 1 turns " << endl;
				}

			}
		}

		else
		{
			counter = 0;
			char ctemp = turn1.getColor();
			count.setColor(ctemp);

			if (b[CP.getPointX()][CP.getPointY()] != nullptr)
			{
				if (choice == 1 && b[DP.getPointX()][DP.getPointY()] == nullptr)
				{
					b[CP.getPointX()][CP.getPointY()]->move(b, CP, DP);
				}
				else if (choice == 2 && b[DP.getPointX()][DP.getPointY()] != nullptr)
				{
					color playerTemp = b[CP.getPointX()][CP.getPointY()]->getPlayer();
					color playerTemp2 = b[DP.getPointX()][DP.getPointY()]->getPlayer();

					if (playerTemp != playerTemp2)
					{
						b[CP.getPointX()][CP.getPointY()]->attack(b, CP, DP);
					}

					else
					{
						cout << "*** ILLEGAL MOVE :( ***" << endl;
						system("cls");
					}
				}

				else
				{
					cout << "*** ILLEGAL MOVE :( ***" << endl;
					system("cls");
				}
			}

			else
			{
				cout << "*** ILLEGAL MOVE :( ***" << endl;
				system("cls");
			}


			if (b[DP.getPointX()][DP.getPointY()] != nullptr)
			{
				temp = b[DP.getPointX()][DP.getPointY()]->getValue();

				if (temp1 == 'b' || temp1 == 4)
				{
					for (int i = DP.getPointX() + 1; i < 9; i++)
					{
						if (b[i][DP.getPointY()] != nullptr)
						{
							temp1 = b[i][DP.getPointY()]->getPlayer();
							temp2 = b[i][DP.getPointY()]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

					for (int j = DP.getPointX() - 1; j > 0; j--)
					{
						if (b[j][DP.getPointY()] != nullptr)
						{
							temp1 = b[j][DP.getPointY()]->getPlayer();
							temp2 = b[j][DP.getPointY()]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

					for (int k = DP.getPointY() - 1; k > 0; k--)
					{
						if (b[DP.getPointX()][k] != nullptr)
						{
							temp1 = b[DP.getPointX()][k]->getPlayer();
							temp2 = b[DP.getPointX()][k]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

					for (int k = DP.getPointY() + 1; k < 9; k++)
					{
						if (b[DP.getPointX()][k] != nullptr)
						{
							temp1 = b[DP.getPointX()][k]->getPlayer();
							temp2 = b[DP.getPointX()][k]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}


				}

				else if (temp == 4 || temp == 3)
				{
					for (int i = DP.getPointX() + 1, j = DP.getPointY() + 1; i < 9 && j < 9; i++, j++)
					{
						if (b[i][j] != nullptr)
						{
							temp1 = b[i][j]->getPlayer();
							temp2 = b[i][j]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

					for (int i = DP.getPointX() + 1, j = DP.getPointY() - 1; i < 9 && j > 0; i++, j--)
					{
						if (b[i][j] != nullptr)
						{
							temp1 = b[i][j]->getPlayer();
							temp2 = b[i][j]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

					for (int i = DP.getPointX() - 1, j = DP.getPointY() - 1; i > 0 && j > 0; i--, j--)
					{
						if (b[i][j] != nullptr)
						{
							temp1 = b[i][j]->getPlayer();
							temp2 = b[i][j]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

					for (int i = DP.getPointX() - 1, j = DP.getPointY() + 1; i > 0 && j < 9; i--, j++)
					{
						if (b[i][j] != nullptr)
						{
							temp1 = b[i][j]->getPlayer();
							temp2 = b[i][j]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

				}

				//checkmate for knight
				else if (temp == 2)
				{
					if (b[DP.getPointX() + 1][DP.getPointY() + 2] != nullptr)
					{
						if (DP.getPointX() + 1 < 9 && DP.getPointY() + 2 < 9)
						{
							temp2 = b[DP.getPointX() + 1][DP.getPointY() + 2]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

					if (b[DP.getPointX() + 1][DP.getPointY() - 2] != nullptr)
					{
						if (DP.getPointX() + 1 < 9 && DP.getPointY() - 2 > 0)
						{
							temp2 = b[DP.getPointX() + 1][DP.getPointY() - 2]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

					if (b[DP.getPointX() + 2][DP.getPointY() + 1] != nullptr)
					{
						if (DP.getPointX() + 2 < 9 && DP.getPointY() + 1 < 9)
						{
							temp2 = b[DP.getPointX() + 2][DP.getPointY() + 1]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}


					if (b[DP.getPointX() + 2][DP.getPointY() - 1] != nullptr)
					{
						if (DP.getPointX() + 2 < 9 && DP.getPointY() - 1 > 0)
						{
							temp2 = b[DP.getPointX() + 2][DP.getPointY() - 1]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

					if (b[DP.getPointX() - 2][DP.getPointY() - 1] != nullptr)
					{
						if (DP.getPointX() - 2 > 0 && DP.getPointY() - 1 > 0)
						{
							temp2 = b[DP.getPointX() - 2][DP.getPointY() - 1]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}
					if (b[DP.getPointX() - 1][DP.getPointY() - 2] != nullptr)
					{
						if (DP.getPointX() - 1 > 0 && DP.getPointY() - 2 > 0)
						{
							temp2 = b[DP.getPointX() - 1][DP.getPointY() - 2]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

					if (b[DP.getPointX() - 1][DP.getPointY() + 2] != nullptr)
					{
						if (DP.getPointX() - 1 > 0 && DP.getPointY() + 2 < 9)
						{
							temp2 = b[DP.getPointX() - 1][DP.getPointY() + 2]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

					if (b[DP.getPointX() - 2][DP.getPointY() + 1] != nullptr)
					{
						if (DP.getPointX() - 2 > 0 && DP.getPointY() + 1 < 9)
						{
							temp2 = b[DP.getPointX() - 2][DP.getPointY() + 1]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}




				}

				else if (temp == 5)
				{
					if (b[DP.getPointX()][DP.getPointY() + 1] != nullptr && DP.getPointY() + 1 < 9)
					{
						temp2 = b[DP.getPointX() + 1][DP.getPointY() + 1]->getValue();

						if (temp2 == 5)
						{
							flag = true;
						}
					}

					if (b[DP.getPointX()][DP.getPointY() - 1] != nullptr && DP.getPointY() - 1 > 0)
					{
						temp2 = b[DP.getPointX() + 1][DP.getPointY() - 1]->getValue();

						if (temp2 == 5)
						{
							flag = true;
						}
					}

					if (b[DP.getPointX() + 1][DP.getPointY() + 1] != nullptr && DP.getPointX() + 1 < 9 && DP.getPointY() + 1 < 9)
					{
						temp2 = b[DP.getPointX() + 1][DP.getPointY() + 1]->getValue();

						if (temp2 == 5)
						{
							flag = true;
						}
					}

					if (b[DP.getPointX() + 1][DP.getPointY() - 1] != nullptr && DP.getPointX() + 1 < 9 && DP.getPointY() - 1 > 9)
					{
						temp2 = b[DP.getPointX() + 1][DP.getPointY() - 1]->getValue();

						if (temp2 == 5)
						{
							flag = true;
						}
					}

					if (b[DP.getPointX() + 1][DP.getPointY()] != nullptr && DP.getPointX() + 1 < 9)
					{
						temp2 = b[DP.getPointX() + 1][DP.getPointY()]->getValue();

						if (temp2 == 5)
						{
							flag = true;
						}
					}

					if (b[DP.getPointX() - 1][DP.getPointY() + 1] != nullptr && DP.getPointX() - 1 > 0 && DP.getPointY() + 1 < 9)
					{
						temp2 = b[DP.getPointX() - 1][DP.getPointY() + 1]->getValue();

						if (temp2 == 5)
						{
							flag = true;
						}
					}

					if (b[DP.getPointX() - 1][DP.getPointY() - 1] != nullptr && DP.getPointX() - 1 > 0 && DP.getPointY() - 1 > 0)
					{
						temp2 = b[DP.getPointX() - 1][DP.getPointY() - 1]->getValue();

						if (temp2 == 5)
						{
							flag = true;
						}
					}

					if (b[DP.getPointX() - 1][DP.getPointY()] != nullptr && DP.getPointX() - 1 > 0)
					{
						temp2 = b[DP.getPointX() - 1][DP.getPointY()]->getValue();

						if (temp2 == 5)
						{
							flag = true;
						}
					}


				}

				else if (temp == 6)
				{
					if (turn1 == 'w')
					{
						if (b[DP.getPointX() - 1][DP.getPointY() - 1] != nullptr && DP.getPointX() - 1 > 0 && DP.getPointY() - 1 > 0)
						{
							temp2 = b[DP.getPointX() - 1][DP.getPointY() - 1]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
						if (b[DP.getPointX() - 1][DP.getPointY() + 1] != nullptr && DP.getPointX() - 1 > 0 && DP.getPointY() + 1 < 9)
						{
							temp2 = b[DP.getPointX() - 1][DP.getPointY() + 1]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

					else if (turn1 == 'b')
					{
						if (b[DP.getPointX() + 1][DP.getPointY() - 1] != nullptr && DP.getPointX() + 1 < 9 && DP.getPointY() - 1 > 0)
						{
							temp2 = b[DP.getPointX() + 1][DP.getPointY() - 1]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
						if (b[DP.getPointX() + 1][DP.getPointY() + 1] != nullptr && DP.getPointX() + 1 < 9 && DP.getPointY() + 1 < 9)
						{
							temp2 = b[DP.getPointX() + 1][DP.getPointY() + 1]->getValue();

							if (temp2 == 5)
							{
								flag = true;
							}
						}
					}

				}

				if (flag == true)
				{
					system("cls");
					cout << " ***KING IS IN CHECK*** :o" << endl;
					system("pause");
				}

			}

			//
			if (b[CP.getPointX()][CP.getPointY()] == nullptr)
			{
				if (turn1.getColor() == 'w')
				{
					cout << "PLAYER 1 TURN" << endl;
				}

				else if (turn1.getColor() == 'b')
				{
					cout << "PLAYER 2 TURN" << endl;
				}
			}

			else
			{
				//cout << "PLAYER " << turn1.getColor() << " turn" << endl;

				if (turn1.getColor() == 'w')
				{
					cout << "PLAYER 1 TURN" << endl;
				}
				else
				{
					if (turn1.getColor() == 'b')
					{
						cout << "PLAYER 2 TURN" << endl;
					}


				}
			}
		}

		printBoard(b);

		cin >> input;
		if (input == 'm' || input == 'M')
		{
			system("cls");
			menu(b);
		}
		else if (input == 's' || input == 'S')
		{
			save(b);
		}

	}
}

//a condition function which is called when the king is in check by all the pieces, it exits and declares winner
void theBoard::checkMate()
{
	system("pause");

	exit(1);
}


//a simple function that displays in the beginning for the user to enter his choice
void theBoard::menu(theBoard * b[9][9])
{
	system("cls");

	char input;

	cout << endl << "                    MENU                          ";
	cout << endl;
	cout << "Enter P to play chess" << endl;
	cout << "Enter R to re-load saved chess game" << endl;
	cout << "Enter S to save chess" << endl;
	cout << "Enter E to exit chess" << endl;

	cin >> input;
	system("cls");

	if (input == 'p' || input == 'P')
	{
		play(b); //play starts the game of chess, loads the board,player,pieces etc
	}

	else if (input == 'r' || input == 'R')
	{
		reload(b); // restores the already saved game in a file
		play(b);
	}

	else if (input == 's' || input == 'S')
	{
		save(b); //saves the game of chess
		play(b);
	}

	else if (input == 'e' || input == 'E') //allows the user to exit 
	{
		cout << "******* GOOD BYE ******* :'( \n";
		exit(1);

	}


}


//saves the current situation of the board in the file when the user presses s
void theBoard::save(theBoard * b[9][9])
{
	ifstream dataIn("input.txt");
	ofstream dataOut("Output.txt");

	for (int i = 1; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (b[i][j] != nullptr)
			{
				color tempPlayer = b[i][j]->getPlayer(); //check what piece it was black or white
				int tempValue = b[i][j]->getValue(); //check what kind of piece it was

				if (tempValue == 6)
				{
					if (tempPlayer == 'w')
					{
						dataOut << "P";
					}
					else
					{
						dataOut << "p";
					}
				}

				else if (tempValue == 1)
				{
					if (tempPlayer == 'w')
					{
						dataOut << "R";
					}
					else
					{
						dataOut << "r";
					}
				}

				else if (tempValue == 3)
				{
					if (tempPlayer == 'w')
					{
						dataOut << "B";
					}
					else
					{
						dataOut << "b";
					}
				}

				else if (tempValue == 4)
				{
					if (tempPlayer == 'w')
					{
						dataOut << "Q";
					}
					else
					{
						dataOut << "q";
					}
				}

				else if (tempValue == 2)
				{
					if (tempPlayer == 'w')
					{
						dataOut << "N";
					}
					else
					{
						dataOut << "n";
					}
				}
				else if (tempValue == 5)
				{
					if (tempPlayer == 'w')
					{
						dataOut << "K";
					}
					else
					{
						dataOut << "k";
					}
				}

			}
			else
			{
				cout << " ";
			}
		}
	}

	dataIn.close();
}

//reads the data of previously saved game from file
//sets the board by matching capslock for white pieces
//small for black
void theBoard::reload(theBoard * b[9][9])
{
	ifstream dataIn("output.txt");

	char a;

	if (dataIn.is_open())
	{
		while (!dataIn.eof())
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					a = dataIn.get();
					point p1(i, j);
					color c1('b');
					color c2('w');
					if (a == 'p')
					{
						b[i][j] = new pawn(p1, c1);
					}

					else if (a == 'r')
					{
						b[i][j] = new rook(p1, c1);
					}

					else if (a == 'b')
					{
						b[i][j] = new Bishop(p1, c1);
					}

					else if (a == 'n')
					{
						b[i][j] = new knight(p1, c1);
					}
					else if (a == 'k')
					{
						b[i][j] = new King(p1, c1);
					}
					else if (a == 'q')
					{
						b[i][j] = new queen(p1, c1);
					}

					else if ((a == 'P'))
					{
						b[i][j] = new pawn(p1, c2);
					}

					else if (a == 'R')
					{
						b[i][j] = new rook(p1, c2);
					}

					else if (a == 'B')
					{
						b[i][j] = new Bishop(p1, c2);
					}

					else if (a == 'N')
					{
						b[i][j] = new knight(p1, c2);
					}
					else if (a == 'K')
					{
						b[i][j] = new King(p1, c2);
					}
					else if (a == 'Q')
					{
						b[i][j] = new queen(p1, c2);
					}

					else if (a == ' ')
					{
						b[i][j] = nullptr;
					}

				}
			}
		}
	}
}


int main()
{
	theBoard * b1[9][9];
	theBoard * b2[2];

	b2[0]->setBoard(b1);
	b2[1]->menu(b1);

	system("pause");
	return 0;
}