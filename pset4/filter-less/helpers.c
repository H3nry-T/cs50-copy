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
    // float count used for calculating the average, and then round() the final result.

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redtotal, greentotal, bluetotal;
            redtotal = greentotal = bluetotal = 0;
            float count = 0;

            // get the nearby pixels, i - 1, i, i + 1, 3 x 3 grid around the middle pixel.
            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    int gridscanindex_y = i + r;
                    int gridscanindex_x = j + c;
                    if (gridscanindex_y < 0 || gridscanindex_x < 0 || gridscanindex_x > width - 1 || gridscanindex_y > height - 1)
                    {
                        continue;
                    }
                    redtotal += image[gridscanindex_y][gridscanindex_x].rgbtRed;
                    greentotal += image[gridscanindex_y][gridscanindex_x].rgbtGreen;
                    bluetotal += image[gridscanindex_y][gridscanindex_x].rgbtBlue;
                    count++;
                }
            }
            BYTE blurpixelred = round(redtotal / count);
            BYTE blurpixelgreen = round(greentotal / count);
            BYTE blurpixelblue = round(bluetotal / count);
            copy[i][j].rgbtRed = blurpixelred;
            copy[i][j].rgbtGreen = blurpixelgreen;
            copy[i][j].rgbtBlue = blurpixelblue;
        }
    }
// copy everything from the blurred copy into the image file.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue =copy[i][j].rgbtBlue;
        }
    }
    return;
}