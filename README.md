# Philosophers
One or more philosophers sit at a round table and there is a large bowl of spaghetti in the middle of the table.
<p>
General rules:
<p>
• The philosophers alternatively eat, think, or sleep
<p>
  While they are eating, they are not thinking nor sleeping;
<p>
  while thinking, they are not eating nor sleeping;
<p>
  while sleeping, they are not eating nor thinking.
<p>
• There are also forks on the table. There are as many forks as philosophers
<p>
• Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand
• When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again.
<p>
The simulation stops when a philosopher dies of starvation.
<p>
The program take the following arguments in order:
<p>
"number_of_philosophers" "time_to_die" "time_to_eat" "time_to_sleep" and an optionable "number_of_times_each_philosopher_must_eat"
<p>
◦ number_of_philosophers: The number of philosophers and also the number of forks
<p>
◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
<p>
◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
<p>
◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
<p>
◦ number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
<p>
