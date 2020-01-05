#include <stdio.h>

void printf(const char *format, ...){
    char **arg = (char **) &format;
    int c;
    char buf[20];
    arg++;
    while ((c = *format++) != 0){
        if (c!= '%')
            putc(c);
        else{
            char *p, *p2;
            int pad0 = 0, pad = 0;
            c = *format++;
            if (c == '0'){
                pad0 = 1;
                c = *format++;
            }

            if (c >= '0' && c <= '9'){
                pad = c - '0';
            }

            switch (c){
                case 'd':
                case 'u':
                case 'x':
                    itoa (buf, c, *((int *) arg++));
                    p=buf;
                    goto string;
                    break;
                
                case 's':
                    p = *arg++;
                    if (!p)
                        p = "(null)";
                
                string:
                    for (p2 = p; *p2; p2++);
                    for (; p2 < p + pad; p2++)
                        putc(pad0 ? '0' : ' ');
                    while (*p)
                        putc (*p++);
                    break;

                    default:
                        putc (*((int*) arg++));
                        break;
            }
        }
    }
}