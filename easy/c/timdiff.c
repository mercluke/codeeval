#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *fp;
	int time1, time2, hour, min, sec, diff;
	char h1[3], m1[3], s1[3], h2[3], m2[3], s2[3];

	fp = fopen(argv[1], "r");

	while(fscanf(fp, "%2s:%2s:%2s %2s:%2s:%2s\n",
		h1, m1, s1, h2, m2, s2) == 6)
	{
		time1 = atoi(h1)*3600 + atoi(m1)*60 + atoi(s1);
		time2 = atoi(h2)*3600 + atoi(m2)*60 + atoi(s2);

		if(time1 > time2)
		{	
			diff = time1-time2;
		}
		else
		{
			diff = time2-time1;
		}

		hour = diff/3600;
		min = (diff%3600)/60;
		sec = diff%60;

		printf("%02i:%02i:%02i\n",
			hour, min, sec);
	}

	return 0;
}
