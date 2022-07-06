#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float B = image[i][j].rgbtBlue * 255;
            float G = image[i][j].rgbtGreen * 255;
            float R = image[i][j].rgbtRed * 255;
            BYTE avrgcolour =round(((B + G + R) / 3 ) / 255);
            image[i][j].rgbtBlue = avrgcolour;
            image[i][j].rgbtGreen = avrgcolour;
            image[i][j].rgbtRed = avrgcolour;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
