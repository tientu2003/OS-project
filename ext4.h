#ifndef EXT4_H
#define EXT4_H

#include <bits/stdc++.h>
// define new type 
#include <superblock.h>

ext4_super_block ext4sb;
int ext4_initilization(){
        ext4sb.s_inodes_count = 0x102030;
        ext4sb.s_blocks_count_lo = 0x201232;
        ext4sb.s_r_blocks_count_lo = 0x302321;
        // arrayinodes = (inodes*) malloc (sizeof(inodes)*ext4sb.s_inodes_count);
        return 0;
}

int create_ext4(){
        FILE *f = fopen("filesystem.ext4","w+");
        fwrite(&ext4sb,sizeof(struct ext4_super_block),1,f);
        fclose(f);
        ext4_super_block test;
        FILE *fr = fopen("filesystem.ext4","r");
        fread(&test,sizeof(struct ext4_super_block),1,fr);
        printf("%d",test.s_inodes_count);
        fclose(fr);
        return 0;
}

#endif