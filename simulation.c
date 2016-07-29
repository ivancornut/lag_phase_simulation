#include "mt64.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


long fill_at_certain_rate(double rate)
{
	long a = 0;
	if (genrand64_real2() < rate)
	{
		a = 2;
	}
	
	return a;
}

long activate_at_certain_rate(double rate)
{
	long a = 1;
	if (genrand64_real2() < rate)
	{
		a = 2;
	}
	
	return a;
}

long die_at_certain_rate(double rate)
{
	long a = 2;
	if (genrand64_real2() < rate)
	{
		a = 0;
	}
	
	return a;

}

long mod(long a, long b)
{
   long ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}

long * update_landscape(long *landscape, long x_size, long y_size, double wake_up_rate, double division_rate, double death_rate)
{
	long position;
	long position_neighbor;

	for (long i = 0; i < x_size*y_size; i++)
	{
		position = (long) floor(genrand64_real3()*(x_size*y_size));
		printf("%ld \n",position);
		printf("i : %ld\n",i );
		printf("Youhou\n");

		switch(landscape[position])
		{
	
			case 0: 
				
				switch((long) ceil(genrand64_real3()*4))
				{
					case 1:
						position_neighbor = mod(position - x_size, x_size*y_size);

						switch(landscape[position_neighbor])
						{
							case 0:
								break;
						
							case 1:
								break;
						
							case 2:
								landscape[position] = fill_at_certain_rate(division_rate);
								break;
						}
						break;

					case 2:
						position_neighbor = (position + 1)%x_size + ((position/x_size)*x_size);  
						switch(landscape[position_neighbor])
						{
							case 0:
								break;
						
							case 1:
								break;
						
							case 2:
								landscape[position] = fill_at_certain_rate(division_rate);
								break;
						}
						break;

					case 3:
						position_neighbor = (position + x_size) %(x_size*y_size);

						switch(landscape[position_neighbor])
						{
							case 0:
								break;
						
							case 1:
								break;
						
							case 2:
								landscape[position] = fill_at_certain_rate(division_rate);
								break;
						}
						break;

					case 4:
						position_neighbor = mod(position - 1, x_size) + ((position/x_size)*x_size);

						switch(landscape[position_neighbor])
						{
							case 0:
								break;
						
							case 1:
								break;
						
							case 2:
								landscape[position] = fill_at_certain_rate(division_rate);
								break;
						}
						break;
				}
				break;

			case 1:
				printf("case 1\n");
				landscape[position] = activate_at_certain_rate(wake_up_rate);
				break;

			case 2:
				printf("case 2\n");
				landscape[position] = die_at_certain_rate(death_rate);
				break;
		}

	}
return landscape;

}

long * initialize_landscape(long *landscape, long x_size, long y_size, double occupancy)
{
	for(long i = 0; i < x_size*y_size; i++)
	{
		if (genrand64_real2() < occupancy)
		{
			landscape[i] = 1;
		}
		else 
		{
			landscape[i] = 0;
		}
	}

	return landscape;
}

int run_simulation(long x_size, long y_size, int iterations, double wake_up_rate, double division_rate, double death_rate, double occupancy)
{
	
	long *landscape = (long*)malloc(x_size * y_size * sizeof(long));
//	long *stor_of_sites = (long*) malloc(3 * sizeof(long));
	
	landscape = initialize_landscape(landscape, x_size, y_size, occupancy);
	
//	ini_dat_file();

	for(long u = 0; u < iterations; u++)
	{
		landscape = update_landscape(landscape, x_size, y_size, wake_up_rate, division_rate, death_rate);
//		stor_of_sites = do_what_ever_funtion();
//		draw_bmp(landscape, x_size, y_size, i);
//		write_dat_file(stor_of_sites,i);
	}
//	close(file);
	free(landscape);
//	free(stor_of_sites);

	return 1;
}




