#include <stdio.h>
#include <stdlib.h>

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

    int *buffer = malloc(512);
    int jpegcount = 0;


    //repeat until end of card
    while (fread(buffer, 1, 512, f) == 512)
    {
        // read card.raw 512 bytes into buffer
        fread(buffer, 512, 1, f);

        //start of new jpeg? yes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if first jpeg? yes
            if (jpegcount == 0)
            {
                //recover the file and name "###.jpg" and write first 512 bytes.
                char *filename = malloc(8);
                sprintf(filename, "%03i.jpg", jpegcount);
                FILE *img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
                jpegcount++;
            }
            //else we find new jpeg?
            else
            {
                //close the file we've been writing to
                fclose(img);
            }
        }

        //else NOT start of new jpeg?
        else
        {
            //already found a jpeg? yes
            if (jpegcount != 0)
            {
                fwrite(buffer, 1, 512, img);
            }
        }



        //already found a jpeg? yes

    }

    //close remaining files
    fclose(f);
}