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
        filesystem.ext4sb.s_inodes_count = 0x0;
        filesystem.ext4sb.s_blocks_count_lo = 0x0;
        filesystem.ext4sb.s_r_blocks_count_lo = 0x0;
        filesystem.ext4sb.s_free_blocks_count_lo = 0x0;
        filesystem.ext4sb.s_free_inodes_count = 0x0;
        filesystem.ext4sb.s_first_data_block = 0x0;
        filesystem.ext4sb.s_log_block_size = 0x0;
        filesystem.ext4sb.s_log_cluster_size = 0x0;
        filesystem.ext4sb.s_blocks_per_group = 0x0;
        filesystem.ext4sb.s_clusters_per_group = 0x0;
        filesystem.ext4sb.s_inodes_per_group = 0x0;
        filesystem.ext4sb.s_mtime = 0x0;
        filesystem.ext4sb.s_wtime = 0x0;
        filesystem.ext4sb.s_mnt_count = 0x0;
        filesystem.ext4sb.s_max_mnt_count = 0x0;
        filesystem.ext4sb.s_magic = 0x0;
        filesystem.ext4sb.s_state = 0x0;
        filesystem.ext4sb.s_errors = 0x0;
        filesystem.ext4sb.s_minor_rev_level = 0x0;
        filesystem.ext4sb.s_lastcheck = 0x0;
        filesystem.ext4sb.s_checkinterval = 0x0;
        filesystem.ext4sb.s_creator_os = 0x0;
        filesystem.ext4sb.s_rev_level = 0x0;
        filesystem.ext4sb.s_def_resuid = 0x0;
        filesystem.ext4sb.s_def_resgid = 0x0;
        filesystem.ext4sb.s_first_ino = 0x0;
        filesystem.ext4sb.s_inode_size = 0x0;
        filesystem.ext4sb.s_block_group_nr = 0x0;
        filesystem.ext4sb.s_feature_compat = 0x0;
        filesystem.ext4sb.s_feature_incompat = 0x0;
        filesystem.ext4sb.s_feature_ro_compat = 0x0;
        //s_uuid
        //s_volume_name
        //s_last_mounted
        filesystem.ext4sb.s_algorithm_usage_bitmap = 0x0;
        filesystem.ext4sb.s_prealloc_blocks = 0x0;
        filesystem.ext4sb.s_prealloc_dir_blocks = 0x0;
        filesystem.ext4sb.s_reserved_gdt_blocks = 0x0;
        //s_journal_uuid
        filesystem.ext4sb.s_journal_inum = 0x0;
        filesystem.ext4sb.s_journal_dev = 0x0;
        filesystem.ext4sb.s_last_orphan = 0x0;
        //s_hash_seed
        filesystem.ext4sb.s_def_hash_version = 0x0;
        filesystem.ext4sb.s_jnl_backup_type = 0x0;
        filesystem.ext4sb.s_desc_size = 0x0;
        filesystem.ext4sb.s_default_mount_opts = 0x0;
        filesystem.ext4sb.s_first_meta_bg = 0x0;
        filesystem.ext4sb.s_mkfs_time = 0x0;
        //s_jnl_blocks
        filesystem.ext4sb.s_blocks_count_hi = 0x0;
        filesystem.ext4sb.s_r_blocks_count_hi = 0x0;
        filesystem.ext4sb.s_free_blocks_count_hi = 0x0;
        filesystem.ext4sb.s_min_extra_isize = 0x0;
        filesystem.ext4sb.s_want_extra_isize = 0x0;
        filesystem.ext4sb.s_flags = 0x0;
        filesystem.ext4sb.s_raid_stride = 0x0;
        filesystem.ext4sb.s_mmp_update_interval = 0x0;
        filesystem.ext4sb.s_mmp_block = 0x0;
        filesystem.ext4sb.s_raid_stripe_width = 0x0;
        filesystem.ext4sb.s_log_groups_per_flex = 0x0;
        filesystem.ext4sb.s_checksum_type = 0x0;
        filesystem.ext4sb.s_encryption_level = 0x0;
        filesystem.ext4sb.s_reserved_pad = 0x0;
        filesystem.ext4sb.s_kbytes_written = 0x0;
        filesystem.ext4sb.s_snapshot_inum = 0x0;
        filesystem.ext4sb.s_snapshot_id = 0x0;
        filesystem.ext4sb.s_snapshot_r_blocks_count = 0x0;
        filesystem.ext4sb.s_snapshot_list = 0x0;
        filesystem.ext4sb.s_error_count = 0x0;
        filesystem.ext4sb.s_first_error_time = 0x0;
        filesystem.ext4sb.s_first_error_ino = 0x0;
        filesystem.ext4sb.s_first_error_block = 0x0;
        //s_first_error_func
        filesystem.ext4sb.s_first_error_line = 0x0;
        filesystem.ext4sb.s_last_error_time = 0x0;
        filesystem.ext4sb.s_last_error_ino = 0x0;
        filesystem.ext4sb.s_last_error_line = 0x0;
        filesystem.ext4sb.s_last_error_block = 0x0;
        //s_last_error_func
        //s_mount_opts
        filesystem.ext4sb.s_usr_quota_inum = 0x0;
        filesystem.ext4sb.s_grp_quota_inum = 0x0;
        filesystem.ext4sb.s_overhead_clusters = 0x0;
        //s_backup_bgs
        //s_encrypt_algos
        //s_encrypt_pw_salt
        filesystem.ext4sb.s_lpf_ino = 0x0;
        filesystem.ext4sb.s_prj_quota_inum = 0x0;
        filesystem.ext4sb.s_checksum_seed = 0x0;
        filesystem.ext4sb.s_wtime_hi = 0x0;
        filesystem.ext4sb.s_mtime_hi = 0x0;
        filesystem.ext4sb.s_mkfs_time_hi = 0x0;
        filesystem.ext4sb.s_lastcheck_hi = 0x0;
        filesystem.ext4sb.s_first_error_time_hi = 0x0;
        filesystem.ext4sb.s_last_error_time_hi = 0x0;
        //s_pad
        filesystem.ext4sb.s_encoding = 0x0;
        filesystem.ext4sb.s_encoding_flags = 0x0;
        //s_reserved
        filesystem.ext4sb.s_checksum = 0x0;
        
        filesystem.ext4gd.bg_block_bitmap_lo = 0x0;
        filesystem.ext4gd.bg_inode_bitmap_lo = 0x0;
        filesystem.ext4gd.bg_inode_table_lo = 0x0;
        filesystem.ext4gd.bg_free_blocks_count_lo = 0x0;
        filesystem.ext4gd.bg_free_inodes_count_lo = 0x0;
        filesystem.ext4gd.bg_used_dirs_count_lo = 0x0;
        filesystem.ext4gd.bg_flags = 0x0;
        filesystem.ext4gd.bg_exclude_bitmap_lo = 0x0;
        filesystem.ext4gd.bg_block_bitmap_csum_lo = 0x0;
        filesystem.ext4gd.bg_inode_bitmap_csum_lo = 0x0;
        filesystem.ext4gd.bg_itable_unused_lo = 0x0;
        filesystem.ext4gd.bg_checksum = 0x0;
        filesystem.ext4gd.bg_block_bitmap_hi = 0x0;
        filesystem.ext4gd.bg_inode_bitmap_hi = 0x0;
        filesystem.ext4gd.bg_inode_table_hi = 0x0;
        filesystem.ext4gd.bg_free_blocks_count_hi = 0x0;
        filesystem.ext4gd.bg_free_inodes_count_hi = 0x0;
        filesystem.ext4gd.bg_used_dirs_count_hi = 0x0;
        filesystem.ext4gd.bg_itable_unused_hi = 0x0;
        filesystem.ext4gd.bg_exclude_bitmap_hi = 0x0;
        filesystem.ext4gd.bg_block_bitmap_csum_hi = 0x0;
        filesystem.ext4gd.bg_inode_bitmap_csum_hi = 0x0;
        filesystem.ext4gd.bg_reserved = 0x0;
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