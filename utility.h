#ifndef UTILITY_H
#define UTILITY_H

#include "ext4.h"

FILESYSTEM readfilesystem;

void printSuperBlock(char* file){
    FILE *f = fopen(file,"r");
    fread(&readfilesystem, sizeof(struct  FILESYSTEM),1,f);

    printf("Inode count: %d\n",readfilesystem.ext4sb.s_inodes_count);
    printf("Block count: %d\n",readfilesystem.ext4sb.s_blocks_count_lo);
    printf("Reserved block count: %d\n",readfilesystem.ext4sb.s_r_blocks_count_lo);
    printf("Free blocks: %d\n",readfilesystem.ext4sb.s_free_blocks_count_lo);
    printf("Free inodes: %d\n",readfilesystem.ext4sb.s_free_inodes_count);
    printf("First block: %d\n",readfilesystem.ext4sb.s_first_data_block);
    printf("Block size: %d\n",readfilesystem.ext4sb.s_log_block_size);
    printf("Fragment(cluster) size: %d\n",readfilesystem.ext4sb.s_log_cluster_size);
    printf("Blocks per group: %d\n",readfilesystem.ext4sb.s_blocks_per_group);
    printf("Fragments(clusters) per group: %d\n",readfilesystem.ext4sb.s_clusters_per_group);
    printf("Inodes per group: %d\n",readfilesystem.ext4sb.s_inodes_per_group);
    printf("Magic signature: %d\n",readfilesystem.ext4sb.s_magic);
    printf("Behavior when detecting errors: %d\n",readfilesystem.ext4sb.s_errors);
    printf("OS: %d\n",readfilesystem.ext4sb.s_creator_os);
    printf("First no-reversed inode: %d\n",readfilesystem.ext4sb.s_first_ino);
    printf("Inode size: %d\n",readfilesystem.ext4sb.s_inode_size);
    printf("Block group number of super block: %d\n",readfilesystem.ext4sb.s_block_group_nr);
    printf("Size of group descriptor: %d\n",readfilesystem.ext4sb.s_desc_size);

    fclose(f);
}

void printGroupDesc(char* file){
    // FILE *f = fopen(file,"r");
    // fread(&readfilesystem, sizeof(struct  FILESYSTEM),1,f);
    
    // //Print group descriptor information here

    // fclose(f);
}

#endif