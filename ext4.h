#ifndef EXT4_H
#define EXT4_H

#include <bits/stdc++.h>
// define new type 
#include "Component/superblock.h"
#include "Component/groupdescriptor.h"
#include "Component/inode.h"
struct DataBlock{
        char data[4096];
};

#define EXT4_NAME_LEN 248
struct ext4_dir_entry {  //  structur for /root dir in datablock
__le32  inode;                  /* Inode number */
__le16  rec_len;                /* Directory entry length */
__u8    name_len;               /* Name length */
__u8    file_type;
char    name[EXT4_NAME_LEN];    /* File name */
};

struct FILESYSTEM{
        ext4_super_block ext4sb;
        ext4_group_desc ext4gd;
        int inodebitmap[INODE_COUNT_INIT];
        int datablockbitmap[BLOCK_COUNT_INIT - FIRST_DATABLOCK_INIT];
        ext4_inode inodetable[INODE_COUNT_INIT];
        ext4_dir_entry dir_entry[208]; // it's also a datablock
        DataBlock DataBlocks[BLOCK_COUNT_INIT - FIRST_DATABLOCK_INIT+13];
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
        filesystem.ext4gd.bg_used_dirs_count_lo=1;  /* Directories count */
        filesystem.ext4gd.bg_itable_unused_lo=196;    /* Unused inodes count */
        return true;
};
// 
bool initializeBitmap(){
        for(int i=0;i<BLOCK_COUNT_INIT - FIRST_DATABLOCK_INIT;i++){
                filesystem.datablockbitmap[i]=0;
        }
        for(int i=0 ; i<12; i++){
                filesystem.inodebitmap[i] =1;
        }
        for(int i=12;i<INODE_COUNT_INIT;i++){
                filesystem.inodebitmap[i]=0;
        }
        return true;
};
//set all 
bool initializeDataBlock(){
        for(int i=0;i<BLOCK_COUNT_INIT - FIRST_DATABLOCK_INIT+13;i++){
                for(int j=0;j<1024;j++){
                        filesystem.DataBlocks[i].data[j] = '0';
                }
        }
        return true;
};
bool createRootDir(){
        for(int i = 0; i<13;i++){
                filesystem.inodetable[2].i_block[i] = FIRST_DATABLOCK_INIT + i;
                filesystem.datablockbitmap[FIRST_DATABLOCK_INIT+i] = 1;
                filesystem.inodetable[2].i_links_count++;
        }
        filesystem.inodetable[2].i_mode = 0x4000; //0x4000 === dir
        filesystem.inodetable[2].i_uid = 0;
        filesystem.inodetable[2].i_blocks_lo = 1;
        filesystem.inodetable[2].i_flags = 0x20000;
        strcpy(filesystem.dir_entry[0].name,"root");
        filesystem.dir_entry[0].name_len = 1;
        filesystem.dir_entry[0].file_type = 1; //1 for dir 0 for file
        filesystem.dir_entry[0].inode = 2;
        filesystem.dir_entry[0].rec_len = 4096*13;
     return true;
}

// set value for filesystem 
bool ext4_initialization(){
        initializeSuperBlock();
        initializeGroupDesc();
        initializeBitmap();
        initializeDataBlock();
        createRootDir();
        return true;
};

int create_ext4(){
        FILE *f = fopen("filesystem.ext4","w+");
        fwrite(&filesystem,sizeof(struct FILESYSTEM),1,f);
        fclose(f);
        return 0;
};

int Find_First_UnusedInode(){
        // FILE* f = fopen("filesystem.ext4","r");
        // fread(&filesystem,sizeof(struct FILESYSTEM),1,f);
        int i=0;
        while(i<=INODE_COUNT_INIT&&filesystem.inodebitmap[i]==1){
                i++;
        }
        if(i==INODE_COUNT_INIT)return -1;
        // fclose(f);
        return i;
}
int Find_First_UnusedBlock(){
        // FILE* f = fopen("filesystem.ext4","r");
        // fread(&filesystem,sizeof(struct FILESYSTEM),1,f);
        
        int i=0;
        while(i<BLOCK_COUNT_INIT - FIRST_DATABLOCK_INIT&&filesystem.datablockbitmap[i]==1){
                i++;
        }
        if(i==BLOCK_COUNT_INIT - FIRST_DATABLOCK_INIT)return -1;
        // fclose(f);
        return i;

}
int Find_unusedDir_entry(){
        int i = 0;
        while(i<208){
                if(filesystem.dir_entry[i].inode == 0){
                        return i;
                }
                i++;
        }
        return -1;
}
//check duplicate name
bool checkValid(char* filename){
        int i = 0;
        while(i<208 && filesystem.dir_entry[i].inode != 0){
                if(strcmp(filesystem.dir_entry[i].name,filename )== 0){
                        return false;
                }
                i++;
        }     
        return true;
}

int Update_Dir(char* filename, int dir_l,int inode){
        filesystem.dir_entry[dir_l].file_type = 0;
        strcpy(filesystem.dir_entry[dir_l].name,filename);
        filesystem.dir_entry[dir_l].inode = inode;
        filesystem.dir_entry[dir_l].name_len = strlen(filename);
        return 0;
}

int create_file(char* filename,int size,char* data,int mode){
        FILE *f = fopen("filesystem.ext4","r");
        fread(&filesystem,sizeof(struct FILESYSTEM),1,f);
        fclose(f);
        if(!checkValid(filename)){
                printf("File name is duplicated\n");
                printf("------------------------------\n");
                return 0;
        }
        int block = Find_First_UnusedBlock();
        int inode = Find_First_UnusedInode();
        if(inode==-1){
                std::cout<<"Memory Full"<<std::endl;
                return 0;
        }
        filesystem.ext4sb.s_free_blocks_count_lo -=size;
        filesystem.ext4sb.s_free_inodes_count -=1;
        filesystem.ext4gd.bg_free_blocks_count_lo-=size;
        filesystem.ext4gd.bg_free_inodes_count_lo-=1;

        for(int i=0;i<size;i++){
                filesystem.datablockbitmap[block+i]=1;
                filesystem.inodetable[inode].i_block[i]=block+i;
        }
        filesystem.inodebitmap[inode]=1;
        // std::cout << filesystem.inodebitmap[inode];
        //update dir_entry of root
        int dir_l = Find_unusedDir_entry();
        Update_Dir(filename,dir_l,inode);
 
        filesystem.inodetable[inode].i_mode = mode;// 0: unreadable 1: only read, 2:read write, 3: executable
        filesystem.inodetable[inode].i_size_lo=4096*size;
        filesystem.inodetable[inode].i_links_count=size;  /* Links count */
        filesystem.inodetable[inode].i_blocks_lo=size;    /* Blocks count */ 
        strcpy(filesystem.DataBlocks[block].data,data); 
        strcpy(filesystem.DataBlocks[block+size-1].data,"/MarkENDFILE"); 
        FILE *wf = fopen("filesystem.ext4","w");

        fwrite(&filesystem,sizeof(struct FILESYSTEM),1,wf);
        fclose(f);
        return 0;
}

int list_files(){
        FILE *f = fopen("filesystem.ext4","r");
        fread(&filesystem,sizeof(struct FILESYSTEM),1,f);
        printf("-------------------------------------\n");
        printf("File/Dir in /root:\n Name                 |      Inode       |        Type       |      Permission\n");
        for(int i = 0; i<208;i++){
                if(filesystem.dir_entry[i].inode != 0)
                {
                        char per[30] ="";
                        int mode = filesystem.inodetable[filesystem.dir_entry[i].inode].i_mode;
                        if(mode == 0){
                                strcpy(per,"No Permission");
                        }else if(mode == 1){
                                 strcpy(per,"Only Read");
                        }else if(mode == 2){
                                 strcpy(per,"Read and Write");
                        }else if(mode == 3){
                                 strcpy(per,"Execute");
                        }
                        if(filesystem.dir_entry[i].file_type == 1){
                                
                                printf("/%20.20s             %d         dir            %s\n",filesystem.dir_entry[i].name,
                                filesystem.dir_entry[i].inode,per);
                        }else{
                                printf("/%20.20s             %d         file           %s\n",filesystem.dir_entry[i].name,
                                filesystem.dir_entry[i].inode,per);
                        }
                      
                }
        }
        fclose(f);
        return 0;
}



int getDataOfFile(char* filename){
        printf("-------------------------------------\n");
        FILE* f = fopen("filesystem.ext4","r");
        fread(&filesystem,sizeof(struct FILESYSTEM),1,f);
        int i = 0;
        while(strcmp(filename,filesystem.dir_entry[i].name) != 0 && i < 208){
                i++;
        }
        if(i == 208){
                printf("FILE NOT FOUND!!!!\n");
                return 0;
        }
        int inode = filesystem.dir_entry[i].inode;
        if(filesystem.inodetable[inode].i_mode == 0){
                printf("Not Permission\n");
        }else{
                printf("Data of %s:\n",filename);
                std:: vector<int> DataBlockIndex;
                for (int i = 0; i< filesystem.inodetable[inode].i_blocks_lo; i++)
                DataBlockIndex.push_back(filesystem.inodetable[inode].i_block[i]);
                for(int j :DataBlockIndex){
                        printf("Datablock %d: %s\n",j, filesystem.DataBlocks[j].data);
                }
        }
        fclose(f);
        return 0;
}

#endif
