// Title:       Experimental Comparison of Saltation and Genetic String Matching Algorithms Part 1(b)
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
#define MAXGENOMELENGTH		6 // Genome Length set to 6
#define MAXGENEVARIETIES	32
#define MAXMUTATIONRATE 64
#define NUMREPLICATES           3
#define CHILDRENPERGENERATION 8

int main(void)
{
  char commandString[COMMANDSTRINGLENGTH];

  for(int genomeLength=1;genomeLength<=MAXGENOMELENGTH;genomeLength++)
  {
    for( int mutationRate = 1; mutationRate<=MAXMUTATIONRATE;mutationRate*=2) //Mutation rate
    {
        for(int geneVarieties=1;geneVarieties<=MAXGENEVARIETIES;geneVarieties*=2)
        {
            for(int replicate=1;replicate<=NUMREPLICATES;replicate++)
            {
                printf("\nRunning Test with Settings %d and %d with mutation rate %d", genomeLength, geneVarieties, mutationRate);
                sprintf(commandString, "./cumulative %d %d %d %d >> Part1b.csv", genomeLength, geneVarieties, mutationRate, CHILDRENPERGENERATION );
                system(commandString);
            }
        }
    }
  }
  printf("\n\n");
  return EXIT_SUCCESS;
}

// Small Description: If percent is expecte then below provides an example what the above mutation does in JS with % value.
 
// for (var j = 1; j <= 64; j*=2){
//            var currentMutationRate= j/100;
//            console.log("This is j"+currentMutationRate)
 
//   for (var i = 1; i <= 32; i*=2){
//         console.log("This is is i "+j * i);
// //         console.log(currentMutationRate);
//     }
// }

// Also for this specific task values of Genome Length (1, 2, 4, 8, 16, 32) were not suitable as desribed within the module guide the data
// runs for a total of days to weeks so I have reduced the genome lengths to 1, 2, 3, 4, 5, 6. The reason this is done is so some data can at least be collected,
// graphed and analysed for the construction of other task. Check Partb test data (TD) for the results thus far. The 
//time complexity of this can be described as exponential O(n!) as the genome length is increased.