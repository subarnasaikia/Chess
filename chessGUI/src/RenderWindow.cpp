#include "RenderWindow.hpp"
#include "errorMessage.hpp"
#include "Constants.hpp"
using namespace chessGUI;

RenderWindow::RenderWindow(const char* w_title, int w_width, int w_height)
    :_window(NULL), _renderer(NULL)
{
    _window = SDL_CreateWindow(w_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w_width, w_height, SDL_WINDOW_RESIZABLE);

    if(_window == NULL)
        errorMessage("SDL Window failed to init.");
    
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

}

SDL_Texture* RenderWindow::loadImage(const char* p_filePath)
{
    SDL_Surface* loadedImage  = NULL;
    loadedImage = IMG_Load(p_filePath);
    if(loadedImage == NULL)
        errorMessage("Load Image has failed.");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, loadedImage);
    return texture;
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(_renderer, p_filePath);
    if(texture == NULL)
        errorMessage("Failed to load texture.");
    
    return texture;
}

void RenderWindow::renderBoard()
{

    for(int file = 1; file <= 8; file++)
    {
        for(int rank = 1; rank <= 8; rank++)
        {
            if( ((file&1) && (rank&1)) || ( !(file&1) && !(rank&1)))
            {
                //white color
                SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
            }else{
                //black color
                SDL_SetRenderDrawColor(_renderer, 155, 103, 60, 255);
            }
            SDL_Rect rect = {
                CENTER_X + (file -1)*CELL_PIXEL,
                CENTER_Y + (rank - 1)*CELL_PIXEL,
                CELL_PIXEL,
                CELL_PIXEL
            };
            SDL_RenderFillRect(_renderer, &rect);
        }
    }
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); //black border
    SDL_Rect border = {CENTER_X, CENTER_Y, BOARD_SIZE, BOARD_SIZE};
    SDL_RenderDrawRect(_renderer, &border);
}

void RenderWindow::render(SDL_Texture* p_tex, SDL_Rect* src, SDL_Rect* dst)
{
    if(p_tex == NULL)
        errorMessage("Texture is null , couldn't find it.");
    SDL_RenderCopy(_renderer, p_tex, src, dst);
}

void RenderWindow::clear()
{
    SDL_RenderClear(_renderer);
}

void RenderWindow::display()
{
    SDL_RenderPresent(_renderer);
    SDL_UpdateWindowSurface(_window);
}

RenderWindow::~RenderWindow()
{
    SDL_DestroyWindow(_window);
}