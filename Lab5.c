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


    	int disk[diskSize], memory[memSize], cache[cacheSize];

    	int i;
    	for (i = 0; i < diskSize; i++) {
        	disk[i] = i;
 	}
	for(i=0; i < memSize; i++){
		memory[i] = 0;
	}
	for(i=0; i<cacheSize; i++){
		cache[i] = 0;
	}

	int value;
	printf("Enter a integer value in the cache: ");
	scanf("%d", &value);
	
		
	int cacheIndex = value % cacheSize;
	int memIndex = value % memSize;

	
    //This if statement runs if the cache[cacheIndex] is empty (Compulsory miss)
	if(cache[cacheIndex] == 0){
        printf("\nCompulsory​ Miss: NULL");
        cache[cacheIndex] = disk[value]; //Takes the content of the disk[value] and copies it into cache[cacheIndex]
 		if(memory[memIndex] != value){ //If the memory[memIndex] is empty OR it contains a value != to the value entered by the user
			printf("Not in memory\n");
            memory[memIndex] = disk[value]; //Takes the content of the disk[value] and copies it into memory[memIndex]
		}
		else //If the value entered is in memory[memIndex]
			printf("In memory\n");
    }
    
    //This if statement runs if the cache[cacheIndex] is a value that is != to the value entered by the user (Conflict miss)
    else if ((cache[cacheIndex] != value) && (cache[cacheIndex] != 0)){
        printf("\Conflict​ Miss: %d", cache[cacheIndex]);
        cache[cacheIndex] = disk[value];
        if(memory[memIndex] != value){
            printf("Not in memory\n");
            memory[memIndex] = disk[value];
        }
        else
            printf("In memory\n");
    }
    
    //This if statement runs if the cache[cacheIndex] is equal to the value entered
    else {
        printf("Hit: %d", cache[cacheIndex]);
        if(memory[memIndex] != value){
            printf("Not in memory\n");
            memory[memIndex] = disk[value];
        }
        else
            printf("In memory\n");
    }

    
	double cacheAccess = cacheSize / 4;
	double memAccess = 100 * (memSize / 16);
	double diskAccess = 100000 * (diskSize / 256);

	printf("Access Time to Cache: %f ns.\n", cacheAccess);
	printf("Access Time to Memory: %f ns.\n", memAccess);
	printf("Access Time to Disk: %f ns.\n", diskAccess);
    	return (0);
//
}

