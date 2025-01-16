#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "RenderWindow.hpp"
namespace chessGUI {
    enum ColorType {NO_COLOR = 0, WHITE, BLACK};
    enum PieceType {NO_PIECE = 0, QUEEN, KING, ROOK, BISHOP, KNIGHT, PAWN };


    class PieceRender {
        public:
            PieceRender(RenderWindow& window, const char* filePath, ColorType colorType, PieceType pieceType);
            void render( int file, int rank);
            SDL_Texture* getTexture();
            ~PieceRender();
        private:
            PieceType _pieceType;
            ColorType _color;
            SDL_Rect* _src;
            SDL_Texture* _texture;
            RenderWindow* _window;
    };
}