#include <stdio.h>
#include <stdlib.h>

int run(int moves[], int movesLen, int res[], int resLen){
    enum State{
        POP=-5,
        CONTINUE,
        REPEAT,
        BREAK,
        INITIALISATION
        };

    int arr1[4][4] = {1, REPEAT, 8, BREAK,
                      POP, 2, BREAK, 5,
                      6, CONTINUE, 3, POP,
                      BREAK, 7, BREAK, 4};

    int arr2[4][4] = {1, 1, 0, 666,
                      3, 2, 666, 1,
                      2, 1, 3, 0,
                      666, 3, 666, 0};
    enum State currentState = INITIALISATION;
    int currentPosition = 0;
    int colon, i, j=0;
    for (i = 0; i < movesLen; i++)
	{
	    currentState = INITIALISATION;
		switch (moves[i]) {
				case 4:
				    colon = 0; break;
				case 16:
				    colon = 1; break;
				case 31:
				    colon = 2; break;
				case 301:
				    colon = 3; break;
				default:
				    colon = 4; currentState = 0; break;
		}

      if (colon != 4 && arr1[currentPosition][colon] > 0)
		  {
			  res[j] = arr1[currentPosition][colon];
			  j++;
          }
		else{
			currentState = arr1[currentPosition][colon];
		switch(currentState){
        case BREAK:
            i = movesLen;
			int a;
			for (a = j; a < resLen; a++)
				res[a] = 0;
			return j;
			break;
        case POP:
            if (j!=0){
                j--;
                res[j] = 0;
            }
            break;
        case REPEAT:
            i--;
            break;
		}
		}
		if (j == resLen)
			i = movesLen;
		currentPosition = arr2[currentPosition][colon];

	}
	int c = j;
	while (j++ < resLen)
	{
		res[j - 1] = 0;
	}
	return c;
}
