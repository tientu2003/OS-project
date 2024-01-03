#Thư mục component để lưu trữ định nghĩa các superblock, Group Desciptor,Block and Inode bitmaps, InodeTable và các giá trị init 
ko cần init toàn bộ một phần cũng được 

ext4.h bây giờ sẽ tạo các API function để tạo và FILE SYSTEM OPERATION 
    Mục tiêu:
        + CREATE FILE SYSTEM
        -------------------------------------------
        +File System Mounting and Unmounting Mounting a file system makes it accessible to the operating system,
        allowing users to interact with it. 
        Unmounting detaches the file system, ensuring data integrity before disconnecting it from the system.
        --------------------------------------------
        + hàm in thông tin superblock, Group Desciptor,Block and Inode bitmaps, InodeTable
        ------------------------------------------------------
        +File Creation: Creating a new file within the file system. This involves allocating space,
         assigning metadata, and establishing a file entry.
        ------------------------------------------------------
        +Hàm In thông tin địa chỉ của file trên đĩa

        --------------------------------------------------------
        +File Opening and Closing: Opening an existing file to read from or write to it, 
        and closing it after the operation is complete.
        Opening a file typically involves locating the file's metadata and setting up access.
        -------------------------------------------------------
