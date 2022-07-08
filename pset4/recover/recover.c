#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("only accepts one command-line argument\n");
        printf("Correct usage: <name of forensic image> \n");
        return 1;
    }

    //open memory card.raw
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("the file does not exist\n");
        return 1;
    }
    
    //repeat until end of card
    int *buffer = malloc(512);
    while (fread(buffer, 1, 512, f) == 512)
    {
        // read card.raw 512 bytes into buffer
        fread(buffer, 512, 1, f);
        int jpegcount = 0;

        //start of new jpeg? yes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if first jpeg? yes
            if (jpegcount == 0)
            {
                //recover the file and name "###.jpg" and write.
                char *filename = malloc(8);
                sprintf(filename, "%03i.jpg", jpegcount);
                FILE *img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
                jpegcount++;
            }
            else //if first jpeg? no
            {
                fclose(img);
            }
        }

        //start of new jpeg? no keep reading


        //already found a jpeg? no

        //already found a jpeg? yes

    }

    //close remaining files
    fclose(f);
}