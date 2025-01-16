#include "PieceRender.hpp"
#include "Constants.hpp"
using namespace chessGUI;

PieceRender::PieceRender(RenderWindow& window, const char* filePath, ColorType colorType, PieceType pieceType)
    :_window(&window), _color(colorType), _pieceType(pieceType), 
    _src(NULL), _texture(NULL)
{
    _texture = _window->loadTexture(filePath);
}

SDL_Texture* PieceRender::getTexture()
{
    return _texture;
}

void PieceRender::render(int file, int rank)
{
    SDL_Rect dst = {
        CENTER_X + (file-1) * CELL_PIXEL,
        CENTER_Y + (rank -1) * CELL_PIXEL,
        CELL_PIXEL,
        CELL_PIXEL
    };
    _window->render(_texture, _src, &dst);
    _src = &dst;
}

PieceRender::~PieceRender()
{
    if(_texture)
        SDL_DestroyTexture(_texture);
}