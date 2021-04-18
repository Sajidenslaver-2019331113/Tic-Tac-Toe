/*
	Original Author: Sheikh Sajid Hossain
	Instructor Credit: Mohammad Fahim Shahriar
	Institution: Shahjalal University of Science and Technology
	Description: An ordinary Tic-Tac-Toe game created by using iGraphics

*/


# include "iGraphics.h"
#include <iostream>
using namespace std;


int check[10];
int xAxis[10] = { 0 , 600 , 600 + 200 , 600 + 200 + 200 , 600 , 600 + 200 , 600 + 200 + 200 , 600 , 600 + 200 , 600 + 200 + 200 };    /// prottek box er co ordinate
int yAxis[10] = { 0 , 300 , 300 , 300 , 300 + 200 , 300 + 200 , 300 + 200 , 300 + 200 + 200 , 300 + 200 + 200 , 300 + 200 + 200 };
bool flag = 0, winA = 0, winB = 0;  /// flag decides which player's turn. /// winA-> player A is the winner
int changed = 0;  /// total box numbers.

int mposx,  mposy;
/*
	function iDraw() is called again and again by the system.
*/
void zeroCross(int i){
	if (check[i] == 0)
	{
		if (flag == 0)
		{
			flag = 1;
			check[i] = 1;
		}
		else
		{
			flag = 0;
			check[i] = 2;
		}
		changed++;
	}
}
void iDraw()
{
	//place your drawing codes here
	iClear();

	iSetColor(0, 220, 255);
	iLine(600, 300, 1200, 300);
	iLine(600, 300, 600, 900);
	iLine(1200, 300, 1200, 900);
	iLine(600, 900, 1200, 900);

	iLine(800, 300, 800, 900);
	iLine(1000, 300, 1000, 900);
	iLine(600, 500, 1200, 500);
	iLine(600, 700, 1200, 700);

	for (int i = 1; i <= 9; i++)
	{

		if (check[i] == 1)
		{
			iSetColor(255, 0, 0);
			iCircle(xAxis[i] + 100, yAxis[i] + 100, 80, 1000);
		}
		if (check[i] == 2)
		{
			iSetColor(0, 255, 0);
			iLine(xAxis[i] + 10, yAxis[i] + 10, xAxis[i] + 190, yAxis[i] + 190);
			iLine(xAxis[i] + 10, yAxis[i] + 190, xAxis[i] + 190, yAxis[i] + 10);
		}
	}

	if (flag)
	{
		iSetColor(0, 255, 0);
		iText(800, 1150, "PLAYER B's TURN", GLUT_BITMAP_TIMES_ROMAN_24);

	}
	else
	{
		iSetColor(0, 255, 0);
		iText(800, 1150, "PLAYER A's TURN", GLUT_BITMAP_TIMES_ROMAN_24);

	}

	if (winA)
	{
		iClear();
		iSetColor(255, 0, 0);
		iText(750, 400, "PLAYER A IS THE WINNER", GLUT_BITMAP_TIMES_ROMAN_24);

	}
	if (winB)
	{
		iClear();
		iSetColor(0, 255, 0);
		iText(750, 400, "PLAYER B IS THE WINNER", GLUT_BITMAP_TIMES_ROMAN_24);

	}
	if (changed >= 9 && winA == 0 && winB == 0)
	{
		iClear();
		iSetColor(0, 0, 255);
		iText(750, 400, "DRAW!!!", GLUT_BITMAP_TIMES_ROMAN_24);

	}


}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == '1')
	{
		zeroCross(1);
	}
	if (key == '2')
	{
		zeroCross(2);
	}
	if (key == '3')
	{
		zeroCross(3);
	}
	if (key == '4')
	{
		zeroCross(4);
	}
	if (key == '5')
	{
		zeroCross(5);
	}
	if (key == '6')
	{
		zeroCross(6);
	}
	if (key == '7')
	{
		zeroCross(7);
	}
	if (key == '8')
	{
		zeroCross(8);
	}
	if (key == '9')
	{
		zeroCross(9);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}
//
void realityCheck(){

	if (winA == 0 && winB == 0){

		if ((check[1] == 1 && check[4] == 1 && check[7] == 1) || (check[2] == 1 && check[5] == 1 && check[8] == 1) || (check[3] == 1 && check[6] == 1 && check[9] == 1) || (check[1] == 1 && check[2] == 1 && check[3] == 1) || (check[4] == 1 && check[5] == 1 && check[6] == 1) || (check[7] == 1 && check[8] == 1 && check[9] == 1) || (check[7] == 1 && check[5] == 1 && check[3] == 1) || (check[1] == 1 && check[5] == 1 && check[9] == 1)){
			winA = 1;
		}
		if ((check[1] == 2 && check[4] == 2 && check[7] == 2) || (check[2] == 2 && check[5] == 2 && check[8] == 2) || (check[3] == 2 && check[6] == 2 && check[9] == 2) || (check[1] == 2 && check[2] == 2 && check[3] == 2) || (check[4] == 2 && check[5] == 2 && check[6] == 2) || (check[7] == 2 && check[8] == 2 && check[9] == 2) || (check[7] == 2 && check[5] == 2 && check[3] == 2) || (check[1] == 2 && check[5] == 2 && check[9] == 2)){
			winB = 1;
		}

	}


}

int main()
{
	//place your own initialization codes here.
	iSetTimer(25, realityCheck);
	iInitialize(1800, 1200, "Tictactoe");
	return 0;
}
