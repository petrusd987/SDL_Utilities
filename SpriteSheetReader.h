/* 
 * File:   SpriteSheetReader.h
 * Author: petrusd987
 *
 * Created on July 24, 2013, 2:47 PM
 */

#include <SDL/SDL.h>

#ifndef SPRITESHEETREADER_H
#define	SPRITESHEETREADER_H

class SpriteSheetReader {
        public:
            static SDL_Surface** ReadSpriteSheet(SDL_Surface* sheet, int width,
                    int height, int xSpacing, int ySpacing);
            static int getNumberOfSprites(SDL_Surface* sheet, int width,
                    int height, int xSpacing, int ySpacing);
        private:
};

#endif	/* SPRITESHEETREADER_H */

