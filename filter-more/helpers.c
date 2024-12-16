#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue;
            avg = round(avg / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int limit = width / 2;
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < limit; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r, g, b, count;
            r = g = b = count = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k < 0 || i + k >= height || j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    r += temp[i + k][j + l].rgbtRed;
                    g += temp[i + k][j + l].rgbtGreen;
                    b += temp[i + k][j + l].rgbtBlue;
                    count++;
                }
            }
            image[i][j].rgbtRed = round(r / (float) count);
            image[i][j].rgbtGreen = round(g / (float) count);
            image[i][j].rgbtBlue = round(b / (float) count);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int xr, xg, xb, yr, yg, yb, index;
    int fr, fg, fb;
    int gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            xr = xg = xb = yr = yg = yb = index = 0;
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (k < 0 || k == height || l < 0 || l == width)
                    {
                        index++;
                        continue;
                    }
                    xr += (temp[k][l].rgbtRed * gx[index]);
                    xg += (temp[k][l].rgbtGreen * gx[index]);
                    xb += (temp[k][l].rgbtBlue * gx[index]);
                    yr += (temp[k][l].rgbtRed * gy[index]);
                    yg += (temp[k][l].rgbtGreen * gy[index]);
                    yb += (temp[k][l].rgbtBlue * gy[index]);
                    index++;
                }
            }
            fr = round(sqrt(xr * xr + yr * yr));
            fg = round(sqrt(xg * xg + yg * yg));
            fb = round(sqrt(xb * xb + yb * yb));

            image[i][j].rgbtRed = (fr > 255) ? 255 : fr;
            image[i][j].rgbtGreen = (fg > 255) ? 255 : fg;
            image[i][j].rgbtBlue = (fb > 255) ? 255 : fb;
        }
    }
    return;
}
