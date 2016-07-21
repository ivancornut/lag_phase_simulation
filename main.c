#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	
	init_genrad64(time(NULL));

	int x_size = atoi(argv[1]);
	int y_size = atoi(argv[2]);
	int iterations = atoi(arg[3]);
	
	double wake_up_rate = strtod(argv[4], NULL);
	double division_rate = strtod(argv[5], NULL);
	double death_rate = strtod(argv[6], NULL);

	long *landscape = create_landscape();
	status = run_simulation(x_size, y_size, iterations, landscape, wake_up_rate, division_rate, death_rate);
	if (status == 1)
	{
		printf("Everything has worked fine. The csv has been outputed\n");
	}
	else
	{
		printf("Something has gone wrong you may want to check your parameters\n");
	}
	
	return 0;

}