#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("only accepts one command-line argument\n");
        printf("Correct usage: ./recover <name of image>\n");
        return 1;
    }

    //open memory card.raw
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("the file does not exist\n");
        return 1;
    }

    BYTE buffer[512];
    int jpegcount = 0;
    FILE *img = NULL;
    char *filename = malloc(8);

    //repeat until end of card
    while (fread(buffer, 1, 512, f) == 512)
    {
        //start of new jpeg? yes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if first jpeg? yes
            if (jpegcount == 0)
            {
                //recover the file and name "###.jpg" and write first 512 bytes.
                sprintf(filename, "%03i.jpg", jpegcount);
                img = fopen(filename, "w");
                jpegcount++;
            }
            //else we find new jpeg?
            else
            {
                //close the file we've been writing to
                fclose(img);
                sprintf(filename, "%03i.jpg", jpegcount);
                img = fopen(filename, "w");
                jpegcount++;
            }
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    //close remaining files
    fclose(f);
    fclose(img);
    free(filename);
    return 0;
}