// Title:       Experimental Comparison of Saltation and Genetic String Matching Algorithms Part 1(a)
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
#define NUMREPLICATES           10

int main(void)
{
  char commandString[COMMANDSTRINGLENGTH];

  for(int genomeLength=1;genomeLength<=MAXGENOMELENGTH;genomeLength*=2)
  {
    for(int geneVarieties=1;geneVarieties<=MAXGENEVARIETIES;geneVarieties*=2)
    {
      for(int replicate=1;replicate<=NUMREPLICATES;replicate++)
      {
        printf("\nRunning Test with Settings %d and %d", genomeLength, geneVarieties);
        sprintf(commandString, "./saltation %d %d >> Part1a.csv", genomeLength, geneVarieties);
        system(commandString);
      }
    }
  }
  printf("\n\n");
  return EXIT_SUCCESS;
}