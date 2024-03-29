#include <kernel/kernel.h>

#define CHECK_FLAG(x, y) (x & (1<<y))

void mboot(uint32_t magic, multiboot_info_t* mbi){
    // printf ("flags = 0x%x\n", (unsigned) mbi->flags);
    
    // if (CHECK_FLAG (mbi->flags, 0))
    //     printf("mem_lower = %uKB, mem_upper = %ukb\n",
    //     (unsigned) mbi->mem_lower, (unsigned)mbi->mem_upper);

    // if (CHECK_FLAG(mbi->flags, 1))
    //     printf("boot_device = 0x%x\n", (unsigned) mbi->boot_device);
    
    // if (CHECK_FLAG(mbi->flags, 2))
    //     printf("cmdline = %s\n", (char *) mbi->cmdline);

    // if (CHECK_FLAG(mbi->flags, 3)){
    //     multiboot_module_t *mod;
    //     uint16_t i;
    //     printf ("mods_count = %d, mods_addr = 0x%x\n",
    //     (int) mbi->mods_count, (int) mbi->mods_addr);
    //     for (i = 0, mod = (multiboot_module_t *) mbi->mods_addr; i < mbi->mods_count; i++, mod++)
    //         printf( "mod_start = 0x%x, mod_end = 0x%x, cmdline = %s\n",
    //         (unsigned) mod->mod_start, (unsigned) mod->mod_end,(char *) mod->cmdline);
    // }

    // if (CHECK_FLAG (mbi->flags, 4)){
    //     multiboot_aout_symbol_table_t *multiboot_aout_sym = &(mbi->u.aout_sym);
    //     printf("multiboot_aout_symbol_table: tabsize = 0x%0x, strsize = 0x%x, addr = 0x%x\n",
    //     (unsigned) multiboot_aout_sym->tabsize, (unsigned) multiboot_aout_sym->strsize, 
    //     (unsigned) multiboot_aout_sym->addr);
    // }

    // if (CHECK_FLAG (mbi->flags, 5)){
    //     multiboot_elf_section_header_table_t *multiboot_elf_sec = &(mbi->u.elf_sec);

    //     printf ("multiboot_elf_sec: num = %u, size =0x%x, addr = 0x%x, shndx = 0x%x\n",
    //     (unsigned) multiboot_elf_sec->num, (unsigned) multiboot_elf_sec->size, 
    //     (unsigned) multiboot_elf_sec->addr, (unsigned) multiboot_elf_sec->shndx);
    // }

    // if (CHECK_FLAG (mbi->flags, 6)){
    //     multiboot_memory_map_t *mmap;

    //     printf ("mmap_addr = 0x%x, mmap_length = 0x%x\n", (unsigned) mbi->mmap_addr, 
    //     (unsigned) mbi->mmap_length);

    //     for (mmap = (multiboot_memory_map_t *) mbi->mmap_addr; 
    //     (unsigned long) mmap < mbi->mmap_addr + mbi->mmap_length;
    //     mmap = (multiboot_memory_map_t *) ((unsigned long) mmap + mmap->size + sizeof(mmap->size)))
    //         printf("size = 0x%x, base_addr = 0x%x%08x, length = 0x%x%08x, type = 0x%x\n",
    //         (unsigned) mmap->size, (unsigned) (mmap->addr >> 32), (unsigned) (mmap->addr & 0xFFFFFFFFUL), 
    //         (unsigned) (mmap->len >> 32), (unsigned) (mmap->len & 0xFFFFFFFFUL), (unsigned) mmap->type);
    // }

    // if (CHECK_FLAG (mbi->flags, 12)){
    //     multiboot_uint32_t color;
    //     unsigned i;
    //     void *fb = (void *) (unsigned long) mbi->framebuffer_addr;
    //     switch (mbi->framebuffer_type){
    //         case MULTIBOOT_FRAMEBUFFER_TYPE_INDEXED:{
    //             unsigned best_distance, distance;
    //             struct multiboot_color *palette;

    //             palette = (struct multiboot_color *) mbi->framebufferer_palette_addr;
    //             color = 0;
    //             best_distance = 4 * 256 * 256;
    //             for (i=0; i< mbi->framebufferer_palette_num_colors; i++){
    //                 distance = (0xFF - palette[i].blue) * (0xFF - palette[i].blue) + 
    //                 palette[i].red * palette[i].red + palette[i].green * palette[i].green;
    //                 if (distance < best_distance){
    //                     color = i;
    //                     best_distance = distance;
    //                 }
    //             }
    //         }
    //         break;

    //         case MULTIBOOT_FRAMEBUFFER_TYPE_RGB:
    //             color = ((1 << mbi->framebufferer_blue_mask_size) - 1) << 
    //             mbi->framebufferer_blue_field_position;
    //             break;
            
    //         case MULTIBOOT_FRAMEBUFFER_TYPE_EGA_TEXT:
    //             color = '\\' | 0x0100;
    //             break;

    //         default:
    //             color = 0xFFFFFFFF;
    //             break;
    //     }
    //     for (i = 0; i < mbi->framebuffer_width && i < mbi->framebuffer_height; i++){
    //         switch (mbi->framebuffer_bpp){
    //             case 8:{
    //                 multiboot_uint8_t *pixel = fb + mbi->framebuffer_pitch * i + i;
    //                 *pixel = color;
    //             }
    //             break;
    //             case 15:
    //             case 16:{
    //                 multiboot_uint16_t *pixel = fb + mbi->framebuffer_pitch * i + 2 * i;
    //                 *pixel = color;
    //             }
    //             break;
    //             case 24:{
    //                 multiboot_uint32_t *pixel = fb + mbi->framebuffer_pitch * i + 3 * i;
    //                 *pixel = (color & 0xFFFFFF) | (*pixel & 0xFF000000);
    //             }
    //             break;
    //             case 32:{
    //                 multiboot_uint32_t *pixel = fb + mbi->framebuffer_pitch * i + 4 +i;
    //                 *pixel = color;
    //             }
    //             break;
    //         }
    //     }
    // }
}

void kmain(void){
    __asm__ volatile("sti");
    puts("Kernel loaded!\n");
    while (1);
    puts("Loop ended!\n");
}