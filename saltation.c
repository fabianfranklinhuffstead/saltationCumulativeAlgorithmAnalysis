// Title: Saltation String Matching Algorithm (Hoyle’s Fallacy)
//
// Author: Fabian
//
// Date: 06-02-15

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define NARGS 3

int main(int argc, char** argv)
{
if(argc<NARGS)
{
printf("\nUsage: %s [Genome Length] [Gene Varieties]\n\n", argv[0]);
exit(EXIT_FAILURE);
}
srand(getpid());
int genomeLength = atoi(argv[1]);
int geneVarieties = atoi(argv[2]);
unsigned char targetGenome[genomeLength];
unsigned char childGenome[genomeLength];
for(int currentGene = 0; currentGene < genomeLength; currentGene++)
targetGenome[currentGene] = rand()%geneVarieties; // Create Our Target Genome for Matching Against
int currentFitness = 0;
int highestEverFitness = 0;
long int currentGenerationNumber = 0;
while(highestEverFitness != genomeLength)
{
currentGenerationNumber++;
currentFitness = 0;
for(int currentGene = 0; currentGene < genomeLength; currentGene++)
{
childGenome[currentGene] = rand()%geneVarieties;
if(childGenome[currentGene] == targetGenome[currentGene])
{
currentFitness++;
}
} // Loop To Mutate All Genes To Create A New Specimen, AND Simultaneously Calculate Its Fitness
if(currentFitness>highestEverFitness)
{
highestEverFitness = currentFitness;
} // Evaluate The Fitness Of Our New Specimen; Is It The Best We’re Ever Had?
} // Repeat Until A Perfect Specimen Is Produced By Blind Chance (Termination Condition)
printf("\n%d,%d,%ld\n", genomeLength, geneVarieties, currentGenerationNumber);
return 0;
}