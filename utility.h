#ifndef UTILITY_H
#define UTILITY_H

#include "ext4.h"

int printSuperBlock(char* file){
        ext4_super_block sb_struct;
        FILE *f = fopen(file,"r");
        fread(&sb_struct, sizeof(struct  ext4_super_block),1,f);
        
        fclose(f);
}

int printGroupDesc(char* file){
        FILESYSTEM readfilesystem;
        FILE *f = fopen(file,"r");
        fread(&readfilesystem,sizeof(struct  FILESYSTEM),1,f);
        
        fclose(f);
}

int printAddressOfFile()
{

}

#endif