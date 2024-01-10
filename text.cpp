#include <bits/stdc++.h>

#include "ext4.h"
#include "Component/inode.h"
#include "Component/superblock.h"
#include "Component/groupdescriptor.h"
#include "utility.h"
int main(){
    char name[196];
    char data[4096];
    int mode;
    int size;
    int key;
    while(1){
        printf("-----------------Menu----------------\n");
        printf("0.EXIT\n");
        printf("1.create filesystem.ext4\n");
        printf("2.create a file\n");
        printf("3.read SuperBlock\n");
        printf("4.read Group Descriptor\n");
        printf("5.read data of file\n");
        printf("6.read Inode information of File\n");
        printf("7.list all file\n");
        printf("--------------------------------------\n");
        scanf("%d",&key);
        switch(key){
            case 0:
                return 0;
            break;
            case 1:       
                ext4_initialization();
                create_ext4();
            break;
            case 2:
                std:: cout<< "Enter filename:";
                std:: cin >> name;
                std:: cout<< "Enter size:";
                std:: cin >> size;
                std:: cout<< "Enter mode:";
                std:: cin >> mode;
                std:: cout<< "Enter Data:";
                std:: cin >> data;
                create_file(name,size,data,mode);
            break;
            case 3:printSuperBlock("filesystem.ext4");
            break;
            case 4:printSuperBlock("filesystem.ext4");
            break;
            case 5:std:: cout << "Enter FileName:";
                std:: cin >> name;
                getDataOfFile(name);
            break;
            case 6:
            break;
            case 7:list_files();
            break;
        }
    }

    
    
   
    
    return 0;
}