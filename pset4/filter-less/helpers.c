#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float R = image[i][j].rgbtRed;
            float G = image[i][j].rgbtGreen;
            float B = image[i][j].rgbtBlue;
            BYTE avrgcolour = round(((B + G + R) / 3.0 ));
            image[i][j].rgbtRed = avrgcolour;
            image[i][j].rgbtGreen = avrgcolour;
            image[i][j].rgbtBlue = avrgcolour;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepia_r = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            float sepia_g = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            float sepia_b = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;
            // store the pixel index of the colour that is over 8 bits, or 1 byte, or value 255.
            if (sepia_r > 255)
            {
                sepia_r = 255;
            }
            if (sepia_g > 255)
            {
                sepia_g = 255;
            }
            if (sepia_b > 255)
            {
                sepia_b = 255;
            }
            image[i][j].rgbtRed = round(sepia_r);
            image[i][j].rgbtGreen = round(sepia_g);
            image[i][j].rgbtBlue = round(sepia_b);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int start = 0; //start of column
        int end = width - 1;//end of column
        while (start < end)
        {
            RGBTRIPLE buffer = image[i][start];
            image[i][start] = image[i][end];
            image[i][end] = buffer;
            start++;
            end--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]; //make copy of the image bitmap.

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // setup a counter for red, green, blue, for 3 x 3 grid (9 lots of RGB)

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            colour[]
        }
    }
    return;
}