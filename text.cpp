#include <bits/stdc++.h>

#include "ext4.h"
#include "Component/inode.h"
#include "Component/superblock.h"
#include "Component/groupdescriptor.h"

int main(){
    // printf("%d",sizeof(struct DataBlock));
    // ext4_initialization();
    // create_ext4();
    // ext4_inode i;
    // printf("%d",sizeof(struct ext4_group_desc));
    char name[196] = "text.txt";
    char data[4096] = "sadfjhsdfkljdhflkjfhalkjhkjdshfkljahflkkjlsdaf";
    create_file(name,2,data);
    list_files();
    return 0;
}