#ifndef EXT4_H
#define EXT4_H

#include <bits/stdc++.h>
// define new type 
#include "Component/superblock.h"
#include "Component/groupdescriptor.h"
#include "Component/inode.h"
struct DataBlock{
        int data[1024];
};
struct FILESYSTEM{
        ext4_super_block ext4sb;
        ext4_group_desc ext4gd;
        int inodebitmap[INODE_COUNT_INIT];
        int datablockbitmap[BLOCK_COUNT_INIT - FIRST_DATABLOCK_INIT];
        ext4_inode inodetable[INODE_COUNT_INIT];
        DataBlock DataBlocks[BLOCK_COUNT_INIT - FIRST_DATABLOCK_INIT];
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
        filesystem.ext4gd.bg_block_bitmap_lo=3;     /* Blocks bitmap block */
        filesystem.ext4gd.bg_inode_bitmap_lo=4;     /* Inodes bitmap block */
        filesystem.ext4gd.bg_inode_table_lo=5;      /* Inodes table block */
        filesystem.ext4gd.bg_free_blocks_count_lo=filesystem.ext4sb.s_free_blocks_count_lo;/* Free blocks count */
        filesystem.ext4gd.bg_free_inodes_count_lo=filesystem.ext4sb.s_free_inodes_count;/* Free inodes count */
        filesystem.ext4gd.bg_used_dirs_count_lo=0;  /* Directories count */
        filesystem.ext4gd.bg_itable_unused_lo=204;    /* Unused inodes count */
        return true;
};
// 
bool initializeBitmap(){
        for(int i=0;i<BLOCK_COUNT_INIT - FIRST_DATABLOCK_INIT;i++){
                filesystem.blockbitmap[i]=1;
        }
        for(int i=0;i<INODE_COUNT_INIT;i++){
                filesystem.inodebitmap[i]=1;
        }
        return true;
};
//set all 
bool initializeDataBlock(){
        for(int i=0;i<BLOCK_COUNT_INIT - FIRST_DATABLOCK_INIT;i++){
                filesystem.DataBlocks[i]=0;
        }
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

#endif
