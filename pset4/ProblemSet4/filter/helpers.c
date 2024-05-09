#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int z = 0 ; z < width ; z++)
    {
        for (int i = 0 ; i < height ; i++)
        {
            int r = image[i][z].rgbtRed;
            int g = image[i][z].rgbtGreen;
            int b = image[i][z].rgbtBlue;
            int f = r + g + b;
            if (f % 3  == 2)
            {
                f = f / 3 + 1; // ez average
            }
            else
            {
                f = f / 3;
            }
            image[i][z].rgbtRed = f;
            image[i][z].rgbtGreen = f;
            image[i][z].rgbtBlue = f;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0 ; i < height ; i++)
    {
        for (int z = 0 ; z < width ; z++)
        {
            temp[i][z].rgbtRed = image[i][width - z - 1].rgbtRed;
            temp[i][z].rgbtGreen = image[i][width - z - 1].rgbtGreen;
            temp[i][z].rgbtBlue = image[i][width - z - 1].rgbtBlue;
        }
        for (int z = 0 ; z < width ; z++) // for assigning new values to image from temp
        {
            image[i][z].rgbtRed = temp[i][z].rgbtRed;
            image[i][z].rgbtGreen = temp[i][z].rgbtGreen;
            image[i][z].rgbtBlue = temp[i][z].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int z = 0 ; z < width ; z++)
    {
        int maxwidth = 3; // width used to multiply with surrounding pixels...
        int numwidth = 0; // width used to denote +1 or -1 in pixels....
        if (z == 0) // first width vertically
        {
            numwidth = 1;
        }
        else if (z == width - 1) //last width vertically
        {
            maxwidth = 2;
        }
        for (int i = 0 ; i < height ; i++)
        {
            int maxheight = 3;
            int numheight = 0;
            if (i == height - 1) // last height horizantally
            {
                maxheight = 2;
            }
            else if (i == 0) // first height horizantally
            {
                numheight = 1;
            }
            int r = 0;
            int g = 0;
            int b = 0;
            int it = 0;
            for (int a = numwidth ; a < maxwidth ; a++)
            {
                for (int j = numheight ; j < maxheight; j++)
                {
                    RGBTRIPLE current = image[i + (j - 1)][z + (a - 1)]; // j-1 and a-1 show what opperation eg..(+1 or -1)
                    r += (current.rgbtRed);
                    g += (current.rgbtGreen);
                    b += (current.rgbtBlue);
                    it++; // avg finder
                }
            }
            temp[i][z].rgbtRed = round(r / (float) it);
            temp[i][z].rgbtGreen = round(g / (float) it);
            temp[i][z].rgbtBlue = round(b / (float) it);
        }
    }
    for (int z = 0 ; z < width ; z++)
    {
        for (int i = 0 ; i < height ; i++)
        {
            image[i][z].rgbtRed = temp[i][z].rgbtRed;
            image[i][z].rgbtGreen = temp[i][z].rgbtGreen;
            image[i][z].rgbtBlue = temp[i][z].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int z = 0 ; z < width ; z++)
    {
        int maxwidth = 3; // width used to multiply with surrounding pixels...
        int numwidth = 0; // width used to denote +1 or -1 in pixels....
        if (z == 0) // first width vertically
        {
            numwidth = 1;
        }
        else if (z == width - 1) //last width vertically
        {
            maxwidth = 2;
        }
        for (int i = 0 ; i < height ; i++)
        {
            int maxheight = 3;
            int numheight = 0;
            if (i == height - 1) // last height horizantally
            {
                maxheight = 2;
            }
            else if (i == 0) // first height horizantally
            {
                numheight = 1;
            }
            float r = 0;
            float g = 0;
            float b = 0;
            int ry = 0;
            int rx = 0;
            int gx = 0;
            int bx = 0;
            int gy = 0;
            int by = 0;
            int X[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}}; //array for Gx values
            int Y[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}}; // Array for Gy values
            for (int a = numwidth ; a < maxwidth ; a++) //for Gx
            {
                for (int j = numheight ; j < maxheight; j++)
                {
                    RGBTRIPLE current = image[i + (j - 1)][z + (a - 1)];    // j-1 and a-1 show what opperation eg..(+1 or -1)
                    rx += X[j][a] * (current.rgbtRed);
                    gx += X[j][a] * (current.rgbtGreen);
                    bx += X[j][a] * (current.rgbtBlue);
                }
            }
            for (int a = numwidth ; a < maxwidth ; a++) // for Gy
            {
                for (int j = numheight ; j < maxheight; j++)
                {
                    RGBTRIPLE current = image[i + (j - 1)][z + (a - 1)]; // j-1 and a-1 show what opperation eg..(+1 or -1)
                    ry += Y[j][a] * (current.rgbtRed);
                    gy += Y[j][a] * (current.rgbtGreen);
                    by += Y[j][a] * (current.rgbtBlue);
                }
            }
            r = sqrt((rx * rx) + (ry * ry));
            g = sqrt((gx * gx) + (gy * gy));
            b = sqrt((bx * bx) + (by * by));
            if (r > 255) // checking if the values are greater then 255
            {
                r = 255;
                temp[i][z].rgbtRed = r;
            }
            else
            {
                temp[i][z].rgbtRed = round(r);
            }
            if (g > 255)
            {
                g = 255;
                temp[i][z].rgbtGreen = g;
            }
            else
            {
                temp[i][z].rgbtGreen = round(g);
            }
            if (b > 255)
            {
                b = 255;
                temp[i][z].rgbtBlue = b;
            }
            else
            {
                temp[i][z].rgbtBlue = round(b);
            }
        }
    }
    for (int z = 0 ; z < width ; z++)
    {
        for (int i = 0 ; i < height ; i++)
        {
            image[i][z].rgbtRed = temp[i][z].rgbtRed;
            image[i][z].rgbtGreen = temp[i][z].rgbtGreen;
            image[i][z].rgbtBlue = temp[i][z].rgbtBlue;
        }
    }
    return;
}
