// Modifies the volume of an audio file
#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r"); // open input.wav
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w"); // open output.wav
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer;
    bool keep_reading = true;
    do
    {
        fread(&buffer, sizeof(int16_t), 1, input);
        buffer *= factor; //increase everysingle sample by 2*
        if (feof(input) == true)//end of file stop reading.
        {
            keep_reading = false;
            return 0;
        }
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    while (keep_reading == true);

    // Close files
    fclose(input);
    fclose(output);
}
