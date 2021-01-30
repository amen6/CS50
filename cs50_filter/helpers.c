#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i <height; i++){
        for(int j = 0; j <width; j++){
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtBlue +pixel.rgbtRed+pixel.rgbtGreen) / 3.00);
            image[i][j].rgbtBlue = image[i][j].rgbtRed =  image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i< height; i++){
        for(int j = 0; j< width; j++){
             RGBTRIPLE pixel = image[i][j];
            int red = round((.393 * image[i][j].rgbtRed)+( .769 * image[i][j].rgbtGreen)+( .189 * image[i][j].rgbtBlue));
            int green = round((.349 * image[i][j].rgbtRed)+(.686 * image[i][j].rgbtGreen)+(.168 * image[i][j].rgbtBlue));
            int blue = round((.272 * image[i][j].rgbtRed)+(.534 * image[i][j].rgbtGreen)+(.131 * image[i][j].rgbtBlue));

            if (red > 255){
                image[i][j].rgbtRed = 255;
            }
            else{
                image[i][j].rgbtRed = red;
            };

            if(green > 255){
                image[i][j].rgbtGreen = 255;
            }
            else{
                image[i][j].rgbtGreen = green;
            };
            if(blue > 255){
                image[i][j].rgbtBlue = 255;
            }
            else{
                image[i][j].rgbtBlue = blue;
            };
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

        for(int i = 0; i < height; i++){
            for(int j = 0; j < width/2; j++){

                int red =image[i][j].rgbtRed;
                int green =image[i][j].rgbtGreen;
                int blue =image[i][j].rgbtBlue;

                image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
                image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
                image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

                image[i][width - j - 1].rgbtRed = red;
                image[i][width - j - 1].rgbtGreen = green;
                image[i][width - j - 1].rgbtBlue =  blue;
            }
        }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

for( int i = 0;i <height; i++){
    for(int j = 0; j<width; j++){
        int sumRed = 0;
        int sumGreen = 0;
        int sumBlue = 0;
        int counter = 0;
        for (int h = -1; h<2; h++){
            for(int w = -1; w<2; w++){
                if(i + h <0 || i + h > height - 1 || j + w <0 || j + w > width - 1) {
                    continue;
                }
                sumRed += image[i+h][j+w].rgbtRed;
                sumGreen += image[i+h][j+w].rgbtGreen;
                sumBlue += image[i+h][j+w].rgbtBlue;
                counter ++;
            }
        }
        temp[i][j].rgbtRed = round(sumRed/counter);
        temp[i][j].rgbtGreen = round(sumGreen/counter);
        temp[i][j].rgbtBlue = round(sumBlue/counter);
    }
}
    for(int i = 0; i<height; i++){
        for(int j = 0; j<width; j++){
        image[i][j].rgbtRed = temp[i][j].rgbtRed;
        image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}























