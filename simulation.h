int run_simulation(long x_size, long y_size, int iterations, double wake_up_rate, double division_rate, double death_rate, double occupancy);
long * initialize_landscape(long *landscape, long x_size, long y_size, double occupancy);
long * update_landscape(long *landscape, long x_size, long y_size, double wake_up_rate, double division_rate, double death_rate);
long fill_at_certain_rate(double rate);
long activate_at_certain_rate(double rate);
long die_at_certain_rate(double rate);
long mod(long a, long b);
