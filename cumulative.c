// Title: Cumulative Selection String Matching Algorithm (Genetic)
//
// Author: Fabian
//
// Date: 06-02-15

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define NARGS 5

int main(int argc, char** argv)
{
 if(argc<NARGS)
  {
    printf("\nUsage: %s [Genome Length] [Gene Varieties] [Mutation Rate (0 to 100)] [Children per Generation]\n\n", argv[0]);
    fflush(stdout);
    exit(EXIT_FAILURE);
 }
srand(getpid());
int genomeLength = atoi(argv[1]);
int geneVarieties = atoi(argv[2]);
int mutationRate = atoi(argv[3]);
int childrenPerGeneration = atoi(argv[4]);
unsigned char targetGenome[genomeLength];
unsigned char parentGenome[genomeLength];
unsigned char currentChildGenome[genomeLength];
unsigned char bestChildGenomeThisGeneration[genomeLength];
for(int currentGene=0; currentGene<genomeLength; currentGene++)
{ targetGenome[currentGene] = rand()%geneVarieties;
parentGenome[currentGene] = rand()%geneVarieties;

} // Create Our Target Genome for Matching Against, AND A First Parent to Start Evolving From
int currentChildFitness = 0, highestEverFitness = 0, highestFitnessThisGeneration=0;
long int currentGenerationNumber=0;
while(highestEverFitness!=genomeLength)
{
currentGenerationNumber++; highestFitnessThisGeneration = 0;
for(int currentChild = 0; currentChild < childrenPerGeneration; currentChild++)
{
currentChildFitness = 0;
for(int currentGene = 0; currentGene < genomeLength; currentGene++)
{
currentChildGenome[currentGene] = parentGenome[currentGene];
} // Copy Current Parent Genome As Basis For The Next Child
for(int currentGene = 0; currentGene < genomeLength; currentGene++)
{
if(rand()%100 < mutationRate)
currentChildGenome[currentGene] = rand()%geneVarieties;
if(currentChildGenome[currentGene] == targetGenome[currentGene])
currentChildFitness++;
} // Loop Through Current Child Genome Mutating Some Genes, AND Calculate Its Fitness
if(currentChildFitness > highestFitnessThisGeneration)
{
highestFitnessThisGeneration = currentChildFitness;
for(int currentGene = 0; currentGene < genomeLength; currentGene++)
bestChildGenomeThisGeneration[currentGene] = currentChildGenome[currentGene];
if(highestFitnessThisGeneration > highestEverFitness)
highestEverFitness = highestFitnessThisGeneration;
} // Evaluate Fitness Of New Child; Is It The Best We've Ever Had? If So, Keep It
} // Generate Next Child in This Generation
for(int currentGene = 0; currentGene < genomeLength; currentGene++) // Make New Parent From Best Child
parentGenome[currentGene] = bestChildGenomeThisGeneration[currentGene];
} // Repeat Until A Perfect Child Evolves (Termination Condition)
printf("\n%d,%d,%d,%d,%ld\n",genomeLength,geneVarieties,mutationRate,childrenPerGeneration,
currentGenerationNumber);
}