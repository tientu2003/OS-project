#ifndef EXT4_H
#define EXT4_H

#include <bits/stdc++.h>
// define new type 
#include "Component/superblock.h"
#include "Component/groupdescriptor.h"
#include "Component/inode.h"
struct FILESYSTEM{
        ext4_super_block ext4sb;
        ext4_group_desc ext4gd;
        int inodebitmap[INODE_COUNT_INIT];
        int datablockbitmap[BLOCK_COUNT_INIT - FIRST_DATABLOCK_INIT];
        ext4_inode inodetable[INODE_COUNT_INIT];
};

FILESYSTEM filesystem;

// add Infromation for SuperBlock 
bool initializeSuperBlock(){
        filesystem.ext4sb.s_inodes_count = INODE_COUNT_INIT;
        filesystem.ext4sb.s_blocks_count_lo = BLOCK_COUNT_INIT;
        filesystem.ext4sb.s_r_blocks_count_lo = BLOCK_COUNT_INIT/8;
        filesystem.ext4sb.s_free_blocks_count_lo = BLOCK_COUNT_INIT;
        filesystem.ext4sb.s_free_inodes_count = INODE_COUNT_INIT;
        filesystem.ext4sb.s_first_data_block = FIRST_DATABLOCK_INIT;
        filesystem.ext4sb.s_log_block_size = BLOCK_SIZE;
        filesystem.ext4sb.s_log_cluster_size = BLOCK_SIZE;
        filesystem.ext4sb.s_blocks_per_group = BLOCKPERGROUP;
        filesystem.ext4sb.s_clusters_per_group = BLOCKPERGROUP;
        filesystem.ext4sb.s_inodes_per_group = INODEPERGROUP;
        filesystem.ext4sb.s_magic = MAGIC;
        filesystem.ext4sb.s_errors = ERROR1;
        filesystem.ext4sb.s_creator_os = FSCREATOR;
        filesystem.ext4sb.s_first_ino = FIRST_INODE_INIT;
        filesystem.ext4sb.s_inode_size = INODE_SIZE;
        filesystem.ext4sb.s_block_group_nr = SUPERBLOCKGROUP;
        filesystem.ext4sb.s_desc_size = GROUP_DESC_SIZE;
        return true;
}

// add information for Group desciptor
bool initializeGroupDesc(){
        return true;
};
// 
bool initializeBitmap(){
        return true;
};
//set all 
bool initializeDataBlock(){
        return true;
};

// set value for filesystem 
bool ext4_initialization(){
        initializeSuperBlock();
        initializeGroupDesc();
        initializeBitmap();
        initializeDataBlock();
        return true;
};

int create_ext4(){
        FILE *f = fopen("filesystem.ext4","w+");
        fwrite(&filesystem,sizeof(struct FILESYSTEM),1,f);
        fclose(f);
        return 0;
};


int printSuperBlock(char* file){
        FILESYSTEM readfilesystem;
        FILE *f = fopen(file,"r");
        fread(&readfilesystem,sizeof(struct  FILESYSTEM),1,f);
        
        fclose(f);
}

int printGroupDesc(char* file){
        FILESYSTEM readfilesystem;
        FILE *f = fopen(file,"r");
        fread(&readfilesystem,sizeof(struct  FILESYSTEM),1,f);
        
        fclose(f);
}

int printAddressOfFile()


#endif