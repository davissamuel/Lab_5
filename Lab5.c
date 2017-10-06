#include <stdio.h>

int main() {
	size_t cacheSize, memSize, diskSize;
	printf("Enter the size of the cache: ");
	scanf("%zd", &cacheSize);

	printf("\nEnter the size of Memory: ");
	scanf("%zd", &memSize);

	while(memSize<=cacheSize){
		printf("\nMemory must be larger than cache. Please enter a different size: ");
		scanf("%zd", &memSize);
	}

	printf("\nPlease enter the size of the disk: ");
	scanf("%zd", &diskSize);

	while(diskSize <= memSize){
		printf("\nDisk must be larger than memory. Please enter a different size: ");
		scanf("%zd", &diskSize);
	}

	double cacheAccess, memAccess, diskAccess, accTime = 0;

	cacheAccess = cacheSize/4;
	memAccess = 100 * (memSize / 16);
	diskAccess = 100000 * (diskSize / 256); 

    	int disk[diskSize], memory[memSize], cache[cacheSize];

    	int i;
    	for (i = 0; i < diskSize; i++) {
        	disk[i] = i;
 	}
	for(i=0; i < memSize; i++){
		memory[i] = -1;
	}
	for(i=0; i<cacheSize; i++){
		cache[i] = -1;
	}

	int value;
    int cacheIndex;
    int memIndex;
    
    double missRate = 0;
    double hitRate = 0;
    
    int z = 1;
    while(z != 0) {
        printf("Enter a integer value in the cache: ");
        scanf("%d", &value);
        
        if (value > diskSize) {
            printf("You dun goofed\n");
            printf("Enter a integer value in the cache: ");
            scanf("%d", &value);
        }
        
        cacheIndex = value % cacheSize;
        memIndex = value % memSize;

        accTime += cacheAccess;
        //This if statement runs if the cache[cacheIndex] is empty (Compulsory miss)
        if(cache[cacheIndex] == -1){
            printf("\nCompulsory​ Miss: NULL\n");
            cache[cacheIndex] = disk[value]; //Takes the content of the disk[value] and copies it into cache[cacheIndex]
            missRate++;
		accTime += memAccess;
            if(memory[memIndex] != value){ //If the memory[memIndex] is empty OR it contains a value != to the value entered by the user
                printf("Not in memory\n");
                memory[memIndex] = disk[value];
	 //Takes the content of the disk[value] and copies it into memory[memIndex]
		accTime += diskAccess;
            }
            else //If the value entered is in memory[memIndex]
                printf("In memory\n");
        }
        
        //This if statement runs if the cache[cacheIndex] is a value that is != to the value entered by the user (Conflict miss)
        else if ((cache[cacheIndex] != value) && (cache[cacheIndex] != -1)){
            printf("\nConflict​ Miss: %d\n", cache[cacheIndex]);
            cache[cacheIndex] = disk[value];
            missRate++;
            if(memory[memIndex] != value){
                printf("Not in memory\n");
                memory[memIndex] = disk[value];
            }
            else
                printf("In memory\n");
        }
        
        //This if statement runs if the cache[cacheIndex] is equal to the value entered
        else {
            printf("Hit: %d\n", cache[cacheIndex]);
            hitRate++;
            if(memory[memIndex] != value){
                printf("Not in memory\n");
                memory[memIndex] = disk[value];
            }
            else
                printf("In memory\n");
        }
	printf("Cache: ");
	for(i=0; i<cacheSize; i++){
		if(cache[i] == -1){
			printf("NULL ");
		}
		else
			printf("%d ", cache[i]);
	}

	printf("\nMemory: ");
	for(i = 0; i <memSize; i++){
		if(memory[i] == -1){
			printf("NULL ");
		}
		else
			printf("%d " , memory[i]);
		}
        printf("\nEnter 0 to exit: ");
        scanf("%d", &z);
    }
    
    double hitPercent = (hitRate / (hitRate + missRate)) * 100;
    double missPercent = (missRate / (hitRate + missRate)) * 100;
    

    printf("Hit Percent: %f%% \n", hitPercent);
    printf("Miss Percent: %f%% \n", missPercent);
    
	//printf("\nAccess Time to Cache: %f ns.\n", cacheAccess);
	//printf("Access Time to Memory: %f ns.\n", memAccess);
	//printf("Access Time to Disk: %f ns.\n", diskAccess);
    printf("Total Access Time: %f ns.\n", accTime);
    
    return (0);

}

