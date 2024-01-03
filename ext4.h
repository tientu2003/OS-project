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
        // others .....
        //......

};

FILESYSTEM filesystem;

int ext4_initilization(){
        filesystem.ext4sb.s_inodes_count = 0x102030;
        filesystem.ext4sb.s_blocks_count_lo = 0x201232;
        filesystem.ext4sb.s_r_blocks_count_lo = 0x302321;
        
        //others
        return 0;
};

int create_ext4(){
        FILE *f = fopen("filesystem.ext4","w+");
        fwrite(&filesystem,sizeof(struct FILESYSTEM),1,f);
        fclose(f);
        return 0;
};

#endif