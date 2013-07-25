/* 
 * File:   SpriteSheetReader.cpp
 * Author: petrusd987
 * 
 * Created on July 24, 2013, 2:47 PM
 */

#include "SpriteSheetReader.h"

SDL_Surface** SpriteSheetReader::ReadSpriteSheet(SDL_Surface* sheet, int width, int height, int xSpacing, int ySpacing){
        int totalSprites = SpriteSheetReader::getNumberOfSprites(sheet, width, height,
                xSpacing, ySpacing);
        
    
        SDL_Surface** sprites = new SDL_Surface*[totalSprites];
        
        //Initialize the sprite array with blank canvases of the proper size.
        
        int c;
        
        for(c=0;c!=totalSprites;c++){
            sprites[c] = SDL_CreateRGBSurface(SDL_HWSURFACE,width,height,
                    sheet->format->BitsPerPixel,
                    sheet->format->Rmask, sheet->format->Gmask,
                    sheet->format->Bmask, sheet->format->Amask);
        }
        
        //Populate the array with ripped sprites
        
        SDL_Rect sourceRect;
        
        sourceRect.w = width;
        sourceRect.h = height;
        
        c = 0;
        
        int xStep,yStep,totalX,totalY;
        xStep = width+xSpacing;
        yStep = height+ySpacing;
        totalX = sheet->w / xStep;
        totalY = sheet->h / yStep;
        
        for(int y=0;y!=totalY;y++){
            for(int x=0;x!=totalX;x++){
                sourceRect.x = xStep*x;
                sourceRect.y = yStep*y;
                SDL_BlitSurface(sheet, &sourceRect, sprites[c],NULL);
                c++;
            }
        }
        
        return sprites;
        
}

int SpriteSheetReader::getNumberOfSprites(SDL_Surface* sheet, int width,
                    int height, int xSpacing, int ySpacing)
{
    int totalX = sheet->w / (width + xSpacing);
    int totalY = sheet->h / (height + ySpacing);
    
    return totalX * totalY;
}