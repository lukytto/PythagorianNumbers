// PitagoroSkaiciai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

	float X[4];
	float Y[4];
	float Z[4];
	float result[4];

	for (short i = 1; i <= 1000; i += 4)
		for (short j = i + 1; j <= 1000; j++)
		{
		
			float x = i;
			float y = j;
			X[0] = x;    //1
			X[1] = x + 1;//2
			X[2] = x + 2;//3
			X[3] = x + 3;//4
			Y[0] = y;    //2
			Y[1] = y + 1;//3
			Y[2] = y + 2;//4
			Y[3] = y + 3;//5

			__asm {
				movups xmm0, X          //load X into xmm0 Move Unaligned Packed Single-Precision Floating-Point
				movups xmm1, Y          //load Y into xmm1 Move Unaligned Packed Single-Precision Floating-Point
				mulps xmm0, xmm0        //pirmø 4 skc kelimas kvadratu
				mulps xmm1, xmm1        //kitu 4 skc kelimas kvadratu
				addps xmm0, xmm1        // kv suma                                  ----------------------------
				sqrtps xmm1, xmm0       // saknies traukimas
				roundps xmm1, xmm1, 10  // sveikoji dalis is saknies traukimo
				movups Z, xmm1          // issaugai saknies sveikas dalis Z
				mulps xmm1, xmm1        // vel keli kvadratu
				subps xmm0, xmm1        // atimi is kv sumos kvadratus
				movups result, xmm0     // result
			}

			for (int k = 0; k <= 4; k++)
				if (result[k] == 0)
					cout << x + k << ", " << y + k << ", " << Z[k] << endl;
		}

	return(0);
}













