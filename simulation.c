int run_simulation(int x_size, int y_size, int iterations, double wake_up_rate, double division_rate, double death_rate, double occupancy)
{
	
	long *landscape = (long*) malloc(x_size * y_size * iterations * sizeof(long));
	landscape = initialize_landscape(landscape, x_size, y_size, occupancy);
	ini_dat_file();

	for(i = 0; i < iterations; i++)
	{
		landscape = update_landscape(landscape, x_size, y_size, wake_up_rate, division_rate, death_rate);
		stor_of_sites = do_what_ever_funtion();
		draw_bmp(landscape, x_size, y_size, i);
		write_dat_file(stor_of_sites,i);
	}
	close(file);
	free(landscape);
	free(stor_of_sites);

	return 1;
}