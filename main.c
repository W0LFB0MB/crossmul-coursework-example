#include <stdio.h>
#include <stdint.h>

typedef struct BMPHeader {
    uint16_t identifier;
    uint32_t size;
    uint16_t unknown1;
    uint16_t unknown2;
    uint32_t offset;
    uint32_t dibsize;
    uint32_t width;
    uint32_t height;
    uint16_t num_planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t image_size;
    uint32_t horizontal_size;
    uint32_t vertical_size;
    uint32_t colours;
    uint32_t important_colours;
} BMPHeader;

typedef struct BMPFile {
    BMPHeader header;
    unsigned char *contents;
} BMPFile;

int main(void) {
    FILE *fptr;

    fptr = fopen("./input/sample1.bmp", "rb");

    if (fptr == NULL) {
        printf("fptr is NULL\n");
        return 1;
    }

    BMPFile filedata;

    fread(&filedata, sizeof(BMPFile), 1, fptr);

    if(filedata.header.identifier != 0x4D42) {
        printf("Incorrect file type.");
        return 1;
    }

    printf(":) %ix%i %i\n", filedata.header.height, filedata.header.width, filedata.header.identifier);
    return 0;
}