#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include "assets/edea.h"

#define VARNAME(a) #a

struct Asset {
	char* name;
	unsigned int* data;
};

typedef struct Asset Asset;

//int countFilesInFolder(const char *folderPath) {
//    int count = 0;
//    DIR *dir;
//    struct dirent *entry;
//    // Open the directory
//    dir = opendir(folderPath);
//    if (dir == NULL) {
//        perror("Unable to open directory");
//        return -1;
//    }
//    // Iterate over each entry in the directory
//    while ((entry = readdir(dir)) != NULL) {
//        // Check if the entry is a regular file (DT_REG) and not a directory (DT_DIR)
//        if (entry->d_type == DT_REG) {
//            count++;
//        }
//    }
//    closedir(dir);
//    return count;
//}


Asset*
get_assets()
{
	Asset assets[1];
    assets[0].data = malloc(sizeof(EDEA_CARD));
    memcpy(assets[0].data, EDEA_CARD, sizeof(EDEA_CARD));
    assets[0].name = VARNAME(EDEA_CARD);
	return assets;
}
