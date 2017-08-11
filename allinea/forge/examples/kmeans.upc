/**
 * k-means UPC example
 * --------------------
 *
 * Number of threads = Number of centroids
 *
 * How to compile:
 * 1- Dinamically: $upc -g upcKmeans.upc -o upcKmeans
 * 2- Statically: $upc -g -fupc-threads-3 upcKmeans.upc -o upcKmeans
 *
 * How to run the dinamic version (X = number of centroids, Y = number of objects):
 * $ ./upcKmeans -n X     		//it uses a default number of objects
 *       or
 * $ ./upcKmeans -n X Y
 *
 * How to run the static version (compilation number of threads = number of centroids,
 * Y = number of objects):
 * $ ./upcKmeans      		//it uses a default number of objects
 *       or
 * $ ./upcKmeans Y
 *
 **/

#include <upc.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_X 15
#define MAX_Y 15
#define SEED_OBJECTS 100
#define SEED_CENTROIDS 200
#define NUMBER_OF_CENTROIDS THREADS
#define DEFAULT_NUMBER_OF_OBJECTS 40

#define true 1
#define false 0

typedef int bool;

typedef struct{
	float x, y;
}Point;

void initializePoints(shared Point *points, int seed, unsigned int numberOfElements);
float distanceToPoint(Point p1, Point p2);
void assignObjectsToCentroid(shared Point *objects, shared Point *centroids, shared unsigned int *objectAssignedToCentroid);
void recalculateCentroidPosition( shared Point* objects, shared Point *centroids, shared unsigned int *objectAssignedToCentroid);
void moveCentroids( shared Point *objects, shared Point *centroids);
bool areSame(float a, float b);
void printCluster( shared Point *objects, shared Point *centroids);
void readArguments(int argc, char **argv);

shared Point *shared objects;
shared Point *shared centroids;
shared bool *shared moves;
shared unsigned int *shared objectAssignedToCentroid;
shared bool nextMove;
shared unsigned int NUMBER_OF_OBJECTS;


int main(int argc, char **argv)
{
	if (MYTHREAD==0){

		readArguments(argc, argv);
		
		objects =  upc_global_alloc( NUMBER_OF_OBJECTS, sizeof(Point));
		centroids =  upc_global_alloc( NUMBER_OF_CENTROIDS, sizeof(Point));
		moves =  upc_global_alloc( NUMBER_OF_CENTROIDS, sizeof(bool));
		objectAssignedToCentroid = upc_global_alloc( NUMBER_OF_OBJECTS, sizeof(unsigned int));

		initializePoints(objects, SEED_OBJECTS, NUMBER_OF_OBJECTS);

		initializePoints(centroids, SEED_CENTROIDS, NUMBER_OF_CENTROIDS);

		printf("Initial cluster:\n");
		printCluster(objects, centroids);
	}

	upc_barrier;

	moveCentroids(objects, centroids);

	if (MYTHREAD==0){
		printf("Final cluster:\n");
		printCluster(objects, centroids);

		upc_free(objects);
		upc_free(centroids);
		upc_free(moves);
		upc_free(objectAssignedToCentroid);
	}
	upc_barrier;

	return 0;
}


void moveCentroids( shared Point *objects, shared Point *centroids){

	nextMove=true;

	int i;

	while(nextMove){
		assignObjectsToCentroid(objects, centroids, objectAssignedToCentroid);
		
		upc_barrier;
		
		recalculateCentroidPosition(objects, centroids, objectAssignedToCentroid);
		upc_barrier;

		if (MYTHREAD==0){
			nextMove = 0;
			for(i=0; i<THREADS; i++)
				nextMove += moves[i];
		}
		upc_barrier;
	}
}

void assignObjectsToCentroid( shared Point *objects, shared Point *centroids, shared unsigned int *objectAssignedToCentroid){

	float bestDistance, newDistance;
	unsigned int i;
	upc_forall(i = 0; i<NUMBER_OF_OBJECTS; i++; &objects[i]){

		bestDistance = distanceToPoint(objects[i], centroids[0]);
		objectAssignedToCentroid[i]=0;
		unsigned int j;
		for( j = 1; j<NUMBER_OF_CENTROIDS; j++){
			newDistance = distanceToPoint(objects[i], centroids[j]);

			if(newDistance < bestDistance){
				bestDistance=newDistance;
				objectAssignedToCentroid[i]=j;
			}
		}
	}
}

void recalculateCentroidPosition( shared Point *objects, shared Point *centroids, shared unsigned int *objectAssignedToCentroid){

	float x,y;
	unsigned int count;
	moves[MYTHREAD] = false;
	unsigned int centroid, j;
	upc_forall( centroid = 0; centroid < NUMBER_OF_CENTROIDS; centroid++; centroid){
		count=0;
		x=0.0;
		y=0.0;

		for( j = 0; j < NUMBER_OF_OBJECTS; j++){
			if(objectAssignedToCentroid[j] == centroid){
				x+=objects[j].x;
				y+=objects[j].y;
				count++;
			}
		}

		if(count!=0){
			x /= (float) count;
			y /= (float) count;

			if( !(areSame(centroids[centroid].x, x) && areSame(centroids[centroid].x, x))){
				centroids[centroid].x = x;
				centroids[centroid].y = y;
				moves[MYTHREAD] = true;
			}
		}
	}
}


void initializePoints(shared Point *points, int seed, unsigned int numberOfElements){

	srand(seed);
	unsigned int i;
	for(i=0; i<numberOfElements; ++i){
		points[i].x =  (float)(rand()%MAX_X)+ (float)((rand()%10))/10;
		points[i].y =  (float)(rand()%MAX_Y)+ (float)((rand()%10))/10;

	}
}

float distanceToPoint(Point p1, Point p2){

	return sqrtf( pow(p1.x-p2.x,2.0) + pow(p1.y-p2.y,2.0) );
}

bool areSame(float a, float b){
    return fabs(a - b) < 0.01;
}

void readArguments(int argc, char **argv){
	if(argc>1){
		NUMBER_OF_OBJECTS = atoi(argv[1]);
	}
	else{
		NUMBER_OF_OBJECTS = DEFAULT_NUMBER_OF_OBJECTS;
	}
}

void printCluster( shared Point *objects, shared Point *centroids){

	char matrix[MAX_X][MAX_Y];
	for(unsigned int i=0; i<MAX_X; i++)
		for(unsigned int j=0; j<MAX_Y; j++)
			matrix[i][j]='~';

	for(unsigned int i = 0; i<NUMBER_OF_OBJECTS; i++){
		matrix[(unsigned int)objects[i].x][(unsigned int)objects[i].y]='#';
	}

	for(unsigned int i = 0; i<NUMBER_OF_CENTROIDS; i++){
		matrix[(unsigned int)centroids[i].x][(unsigned int)centroids[i].y]='O';
	}


	for(unsigned int i=0; i<MAX_X; i++){
		for(unsigned int j=0; j<MAX_Y; j++)
			printf("%c",matrix[i][j]);
		printf("\n");
	}

	printf("\n");

}
