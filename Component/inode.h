#include <bits/stdc++.h>
// define new type 
typedef uint32_t __le32;
typedef uint16_t __le16;
typedef uint8_t __u8;
typedef uint64_t __le64;


/* data type for block offset of block group */
typedef int ext4_grpblk_t;

/* data type for filesystem-wide blocks number */
typedef unsigned long long ext4_fsblk_t;

/* data type for file logical block number */
typedef uint32_t ext4_lblk_t;

/* data type for block group number */
typedef unsigned int ext4_group_t;

#define EXT4_INODE_DIRECT_BLOCK_COUNT 12
#define EXT4_INODE_INDIRECT_BLOCK EXT4_INODE_DIRECT_BLOCK_COUNT
#define EXT4_INODE_DOUBLE_INDIRECT_BLOCK (EXT4_INODE_INDIRECT_BLOCK + 1)
#define EXT4_INODE_TRIPPLE_INDIRECT_BLOCK (EXT4_INODE_DOUBLE_INDIRECT_BLOCK + 1)
#define EXT4_INODE_BLOCKS (EXT4_INODE_TRIPPLE_INDIRECT_BLOCK + 1)
#define EXT4_INODE_INDIRECT_BLOCK_COUNT                                        \
	(EXT4_INODE_BLOCKS - EXT4_INODE_DIRECT_BLOCK_COUNT)

struct ext4_inode {
	uint16_t mode;		    /* File mode */
	uint16_t uid;		    /* Low 16 bits of owner uid */
	uint32_t size_lo;	   /* Size in bytes */
	uint32_t access_time;       /* Access time */
	uint32_t change_inode_time; /* I-node change time */
	uint32_t modification_time; /* Modification time */
	uint32_t deletion_time;     /* Deletion time */
	uint16_t gid;		    /* Low 16 bits of group id */
	uint16_t links_count;       /* Links count */
	uint32_t blocks_count_lo;   /* Blocks count */
	uint32_t flags;		    /* File flags */
	uint32_t unused_osd1;       /* OS dependent - not used in HelenOS */
	uint32_t blocks[EXT4_INODE_BLOCKS]; /* Pointers to blocks */
	uint32_t generation;		    /* File version (for NFS) */
	uint32_t file_acl_lo;		    /* File ACL */
	uint32_t size_hi;
	uint32_t obso_faddr; /* Obsoleted fragment address */

	union {
		struct {
			uint16_t blocks_high;
			uint16_t file_acl_high;
			uint16_t uid_high;
			uint16_t gid_high;
			uint16_t checksum_lo; /* crc32c(uuid+inum+inode) LE */
			uint16_t reserved2;
		} linux2;
		struct {
			uint16_t reserved1;
			uint16_t mode_high;
			uint16_t uid_high;
			uint16_t gid_high;
			uint32_t author;
		} hurd2;
	} osd2;

	uint16_t extra_isize;
	uint16_t checksum_hi;	/* crc32c(uuid+inum+inode) BE */
	uint32_t ctime_extra; /* Extra change time (nsec << 2 | epoch) */
	uint32_t mtime_extra; /* Extra Modification time (nsec << 2 | epoch) */
	uint32_t atime_extra; /* Extra Access time (nsec << 2 | epoch) */
	uint32_t crtime;      /* File creation time */
	uint32_t
	    crtime_extra;    /* Extra file creation time (nsec << 2 | epoch) */
	uint32_t version_hi; /* High 32 bits for 64-bit version */
};
