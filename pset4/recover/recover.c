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
    FILE *f = fopen(argv[1], "r"); //get the file pointer which is the memory address of the opened image.
    if (f == NULL)
    {
        printf("the file does not exist\n");
        return 1;
    }

    int *buffer = malloc(512);
    while (fread(buffer, 1, 512, f) == 512) //keep reading changes if it reaches the end.
    {
        // f is the card.raw file
        fread(buffer, 512, 1, f);
        int jpegcount = 0;

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)// if jpeg.
        {
            if (jpegcount == 0) //first jpeg
            {
                char *filename = malloc(8); //create a new filename
                sprintf(filename, "%03i.jpg", jpegcount);
                FILE *img = fopen(filename, "w"); //recover image
                do
                {
                    fwrite(buffer, 1, 512, img); //write to new image
                }
                while (buffer[0] != 0xff && buffer[1] != 0xd8 && buffer[2] != 0xff && (buffer[3] & 0xf0) == 0xe0)
                free(filename);
                jpegcount++;
            }
             else //we already have jpegs
            {
                continue;
            }
        }
    }
}