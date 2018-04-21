// Title:       Modifying the String Matching Algorithms Part 2(d) - Cumulation
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
#define MAXGENOMELENGTH		32
#define MAXGENEVARIETIES	32 
#define MAXMUTATIONRATE 16
#define MAXCHILDRENPERGENERATION 100 // Switched for this part to max children as this makes more sense for this part.
#define BREEDINGPOOL 90
#define POPULATIONDIVERSITY 50

int main(void)
{
  char commandString[COMMANDSTRINGLENGTH];
  
        for(int genomeLength=1;genomeLength<=MAXGENOMELENGTH;genomeLength*=2)
        {
            for( int mutationRate = 1; mutationRate<=MAXMUTATIONRATE;mutationRate*=2) //Mutation rate
            {
                for(int geneVarieties=1;geneVarieties<=MAXGENEVARIETIES;geneVarieties*=2)
                {
                    for(int childrenPerGeneration=1;childrenPerGeneration<=MAXCHILDRENPERGENERATION;childrenPerGeneration++) //Loops through children O(n) linear time
                    {
                            // int randomChance = rand() % 100 + 1;

                            // if( randomChance < 50)
                            // {
                            //     printf("\nRunning Test with Settings %d and %d with mutation rate %d. The current generation %d, the current child genome (weak) %d.", genomeLength, geneVarieties, mutationRate, childrenPerGeneration, randomChance);
                            //     sprintf(commandString, "./cumulative %d %d %d %d >> Part2c.csv", genomeLength, geneVarieties, mutationRate, childrenPerGeneration);
                            //     system(commandString);
                            // }
                                                    
                            // if(childrenPerGeneration >= BREEDINGPOOL) // prints out breeding pool of top 90% ++
                            // {
                            //     printf("\nRunning Test with Settings %d and %d with mutation rate %d. The current generation %d, the current child genome %d.", genomeLength, geneVarieties, mutationRate, childrenPerGeneration, BREEDINGPOOL);
                            //     sprintf(commandString, "./cumulative %d %d %d %d %d >> Part2c.csv", genomeLength, geneVarieties, mutationRate, childrenPerGeneration, BREEDINGPOOL);
                            //     system(commandString);
                            // }
                    }
                }
            }
        }
  printf("\n\n");
  return EXIT_SUCCESS;
}