#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i;
	for (i=1;i<=100;i++) {
		printf("%d\n", i);
		sleep(1);
	}
	return 0;
}
