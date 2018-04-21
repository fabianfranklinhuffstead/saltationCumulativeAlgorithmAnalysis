// Title:       Experimental Comparison of Saltation and Genetic String Matching Algorithms Part 1(c)
//
// OS:		MacOS/Linux
//
// Orginal Author:      Fabian
//
// Editor:      Fabian
//
// Date:        10-04-14

#include <stdio.h>
#include <stdlib.h>

#define COMMANDSTRINGLENGTH	100
#define MAXGENOMELENGTH		32 // The 6 values are now 1, 2, 3, 4, 5, 6 instead of 1, 2, 4, 8, 16, 32
#define MAXGENEVARIETIES	32 // The 6 values are now 1, 2, 3, 4, 5, 6 instead of 1, 2, 4, 8, 16, 32
#define MAXMUTATIONRATE 64
#define NUMREPLICATES           3
#define MAXCHILDRENPERGENERATION 32 // Switched for this part to max children as this makes more sense for this part.

int main(void)
{
  char commandString[COMMANDSTRINGLENGTH];

for(int childrenPerGeneration=1;childrenPerGeneration<=MAXCHILDRENPERGENERATION;childrenPerGeneration*=2) //Loops through children
{
    for(int genomeLength=1;genomeLength<=MAXGENOMELENGTH;genomeLength++) //reduce length for faster run time
    {
        for( int mutationRate = 1; mutationRate<=MAXMUTATIONRATE;mutationRate*=2) //Mutation rate
        {
            for(int geneVarieties=1;geneVarieties<=MAXGENEVARIETIES;geneVarieties++)
            {
                for(int replicate=1;replicate<=NUMREPLICATES;replicate++)
                {
                    printf("\nRunning Test with Settings %d and %d with mutation rate %d. The current child %d", genomeLength, geneVarieties, mutationRate, childrenPerGeneration);
                    sprintf(commandString, "./cumulative %d %d %d %d >> Part1c.csv", genomeLength, geneVarieties, mutationRate, childrenPerGeneration );
                    system(commandString);
                }
            }
        }
  }
}
  printf("\n\n");
  return EXIT_SUCCESS;
}

// If you are following this in a corresponding order; previous code changes plus the justification are given (please check 1b). 
//Variance in children stil exist incremnents of 1, 2, 4, 8, 16, 32. variance in gene vareity decreased to increase time taken to calculate change
//