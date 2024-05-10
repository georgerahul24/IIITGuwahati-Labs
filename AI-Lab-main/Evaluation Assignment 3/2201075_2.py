from copy import deepcopy
import random

PopulationSize = 20
MutationProbability = 0.2


class Chromosome:
    name: str
    genes: list  # [negative/positive,bit,bit,bit]
    depth: int

    def __init__(self, name: str, genes: list, depth: int):
        self.name = name
        self.genes = genes
        self.depth = depth

    def __str__(self):
        return f"{self.name}: {self.genes}"

    def geneValue(self):
        val = 0
        n = 1
        for gene in self.genes[-1:-4:-1]:
            val += gene * n
            n *= 2
        if self.genes[0] == 1:
            return -val
        return val

    def f(self, x):
        return x ** 2 - 4 * x + 4

    def fitness(self):
        return self.f(self.geneValue())


def crossover(chromosomes: list[Chromosome]):
    chromosome_copy: list = deepcopy(chromosomes)
    newChromosomes: list = []

    numberOfMutations = 0
    while len(chromosome_copy):
        chromosome1 = chromosome_copy.pop(random.randint(0, len(chromosome_copy) - 1))
        chromosome2 = chromosome_copy.pop(random.randint(0, len(chromosome_copy) - 1))
        genes1 = chromosome1.genes
        genes2 = chromosome2.genes

        newgenes1 = [genes1[0], genes1[1], genes2[2], genes2[3]]
        newgenes2 = [genes2[0], genes2[1], genes1[2], genes1[3]]

        newChromosomes.append(
            Chromosome(f"{chromosome1.name}a {chromosome2.name}b", newgenes1, chromosome1.depth + 1))
        newChromosomes.append(
            Chromosome(f"{chromosome2.name}a {chromosome1.name}b", newgenes2, chromosome2.depth + 1))
        numberOfMutations += 1
    return newChromosomes


def mutation(chromosomes: list[Chromosome]):
    chromosome_copy: list = deepcopy(chromosomes)
    newChromosomes: list = []

    for chromosome in chromosome_copy:
        genes = chromosome.genes
        if random.random() < MutationProbability:
            new_chromosome = [random.randint(0, 1), genes[1], genes[2], genes[3]]
            newChromosomes.append(Chromosome(chromosome.name + "m1", new_chromosome, chromosome.depth))
        if random.random() < MutationProbability:
            new_chromosome = [genes[0], random.randint(0, 1), genes[2], genes[3]]
            newChromosomes.append(Chromosome(chromosome.name + "m2", new_chromosome, chromosome.depth))
        if random.random() < MutationProbability:
            new_chromosome = [genes[0], genes[1], random.randint(0, 1), genes[3]]
            newChromosomes.append(Chromosome(chromosome.name + "m3", new_chromosome, chromosome.depth))
            if random.random() < MutationProbability:
                new_chromosome = [genes[0], genes[1], genes[2], random.randint(0, 1), ]
                newChromosomes.append(Chromosome(chromosome.name + "m3", new_chromosome, chromosome.depth))
    return newChromosomes + chromosomes


Population: list[Chromosome] = []
for i in range(PopulationSize):
    chromosome = Chromosome(f"i{i}", [random.randint(0, 1) for i in range(4)], 0)
    Population.append(chromosome)

print("Initial Population Size:", PopulationSize)

maxNumberOfGeneration = 1
currentGeneration = 0

while currentGeneration < maxNumberOfGeneration:
    Population = crossover(Population)
    Population = mutation(Population)

    sortedPopulation = sorted(Population, key=lambda chromosome: chromosome.fitness())
    print("Generation: ", currentGeneration, ", Min Fitness :", sortedPopulation[0].fitness(), " for Chromosome ",
          sortedPopulation[0])
    Population = sortedPopulation[:PopulationSize]
    if sortedPopulation[0].fitness() == 0:
        break
    currentGeneration += 1

print("Number of Generations taken:", currentGeneration)
