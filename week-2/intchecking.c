#include <stdio.h>

int min(int a, int b)
{
	return a<=b ? a:b;
}

int isGCD(int a, int b, int r)
{
	return a%r == 0 && b%r == 0;
}

int checkGCD(int a, int b)
{
	int opcount = 0;
	for (int r = min(a,b); r > 0; --r)
	{
		opcount++;
		if (isGCD(a,b,r))
		{
			break;
		}
	}
	printf("%d\t%d\n", a+b,opcount);
}

int main(int argc, char const *argv[])
{
	int a[] = {1338, 3395, 3601, 5496, 6839, 7638, 10193, 12745, 12952, 12961, 12993, 13198, 15133, 17233, 17618, 17657, 18234, 18253, 18930, 19305};
	int b[] = {235, 330, 759, 1796, 4340, 4571, 4782, 7619, 8491, 9409, 9718, 10171, 10232, 11834, 12340, 13224, 14773, 15227, 15467, 17261};
	for (int i = 0; i < 20; ++i)
	{
		checkGCD(a[i], b[i]);
	}
	return 0;
}