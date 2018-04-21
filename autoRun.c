// Title:       main autoRun file found on the Virtual learning enviroment(VLE)
//
// OS:		MacOS/Linux
//
// Author:      Fabian
//
// Date:        10-04-14

#include <stdio.h>
#include <stdlib.h>

#define COMMANDSTRINGLENGTH	100
#define MAXGENOMELENGTH		10
#define MAXGENEVARIETIES	16
#define NUMREPLICATES           10

int main(void)
{
  char commandString[COMMANDSTRINGLENGTH];

  for(int genomeLength=1;genomeLength<=MAXGENOMELENGTH;genomeLength++)
  {
    for(int geneVarieties=1;geneVarieties<=MAXGENEVARIETIES;geneVarieties++)
    {
      for(int replicate=1;replicate<=NUMREPLICATES;replicate++)
      {
        printf("\nRunning Test with Settings %d and %d", genomeLength, geneVarieties);
        sprintf(commandString, "./saltationQuietOutput %d %d >> saltTestOutputFile.txt", genomeLength, geneVarieties);
        system(commandString);
      }
    }
  }

  printf("\n\n");
  return EXIT_SUCCESS;
}