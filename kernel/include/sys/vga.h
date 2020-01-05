#ifndef VGA_H
#define VGA_H 1

#define COLUMNS                 80
#define LINES                   24
#define ATTRIBUTE               15
#define VIDEO                   0xB8000

static int xpos;
static int ypos;
static volatile unsigned char *video;

#endif