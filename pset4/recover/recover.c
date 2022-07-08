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

    while (feof(f) != 0)
    {
        int *buffer = malloc(512);
        fread(buffer, 512, 1, f); // f is the card.raw file when typed into the terminal
        int jpegcount = 0;

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpegcount = 0) //check for existing jpegs.
            {
                jpegcount++;
                char *filename = malloc(8); //create a new filename
                sprintf(filename, "%03i.jpg", jpegcount);
                FILE *img = fopen(filename, "w"); //open a new file with the new filename wrote permissions.
                fwrite(buffer, 512, 1, img); //write to the filepointer called img.
                free(filename); 
            }
             else //we already have jpegs
            {
                close(f);
                jpegcount++;
                char *filename = malloc(8); //create a new filename
                sprintf(filename, "%03i.jpg", jpegcount);
                FILE *img = fopen(filename, "w"); //open a new file with the new filename wrote permissions.
                fwrite(buffer, 512, 1, img); //write to the filepointer called img.
                free(filename);
            }
        }
        else
        {

        }
    }
}