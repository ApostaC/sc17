#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <string.h>
int my_rank, procs;
int size;

double distance(double ax, double ay, double bx, double by)
{
    double dx = bx-ax;
    double dy = by-ay;
    return sqrt(dx*dx + dy*dy);
}

double distanceFromCenter(int x, int y)
{
    return distance(size/2, size/2, x, y);
}

double wave(int x, int y)
{
    return sin(distanceFromCenter(x, y) / size * 8 * M_PI );
}

double rank(int x, int y)
{
    return my_rank;
}

double rampX(int x, int y)
{
    return x;
}

double rampY(int x, int y)
{
    return y;
}

double (*calculate)(int x, int y);

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &procs);

    calculate = wave;   // default is "sine wave"

    int i;
    for(i=1;i<argc;i++)
    {
        if (0 == strcmp(argv[i], "distance")) 
            calculate = distanceFromCenter;
        else if (0 == strcmp(argv[i], "x-ramp")) 
            calculate = rampX;
        else if (0 == strcmp(argv[i], "y-ramp")) 
            calculate = rampY;
        else if (0 == strcmp(argv[i], "rank")) 
            calculate = rank;
    }

    size = 120; // works well for 1,4,9,16,25,36 processes

    int blocks = (int)sqrt(procs);
    int blockSize = size / blocks;
    int xOffset = (my_rank % blocks) * blockSize;
    int yOffset = (my_rank / blocks) * blockSize;

    double* heightmap = malloc(sizeof(double)*blockSize*blockSize);
    memset(heightmap, 0, sizeof(double)*blockSize*blockSize);
    int x,y;
    for (x=0; x < blockSize; x++)
    {
        for (y=0; y < blockSize; y++)
        {
            heightmap[y * blockSize + x] = calculate(xOffset + x, yOffset + y);
        }
    }

    free(heightmap);
    
    MPI_Finalize();
}

