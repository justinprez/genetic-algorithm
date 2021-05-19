#include "a4.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
  // Process input parameters
  if (argc!=6)
    {
      printf("Usage ./evolve in_file out_file num_gen p_size rate\n");
      return 1;
    }
  const char *input_file = argv[1];
  const char *output_file = argv[2];

  int num_generations = atoi(argv[3]);
  int population_size = atoi(argv[4]);

  double mutation_rate = atof(argv[5]);
  
  // Read image.
  PPM_IMAGE *goal = read_ppm(input_file);
  printf("\nFile %s:\n %dx%d, max color %d, pixels to mutate %d\n",
	 input_file, goal->width, goal->height, goal->max_color, (int)(mutation_rate/100*goal->width*goal->height));

  // Compute image
  

  for (int i = 0; i <= num_generations; i = i + 500 ) {
    PPM_IMAGE *new_image = evolve_image(goal, i, population_size, mutation_rate);
    write_ppm(output_file, new_image);
  }

  
  // Write image

  // Free memory
  //free_image(goal);
  //free_image(new_image);

  return (0);
}
