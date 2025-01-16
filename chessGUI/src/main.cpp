#include <iostream>
#include <array>
#include <memory>
#include "RenderWindow.hpp"
#include "PieceRender.hpp"
#include "Constants.hpp"
#include "errorMessage.hpp"

int main()
{
    if(SDL_Init(SDL_INIT_EVERYTHING) > 0)
        errorMessage("SDL_Init has failed.");

    if( !(IMG_Init(IMG_INIT_PNG)))
        errorMessage("IMG_Init has failed.");

    chessGUI::RenderWindow window("Chess", SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Texture* whiteKing = NULL;
    bool gameRunning = true;

    std::array<std::array<std::unique_ptr<chessGUI::PieceRender> , 7>, 3> pieces;
    
    // For white
    pieces[chessGUI::ColorType::WHITE][chessGUI::PieceType::QUEEN] = std::make_unique<chessGUI::PieceRender>(window, chessGUI::WHITE_QUEEN_PNG, chessGUI::ColorType::WHITE, chessGUI::PieceType::QUEEN);
    pieces[chessGUI::ColorType::WHITE][chessGUI::PieceType::KING] = std::make_unique<chessGUI::PieceRender>(window, chessGUI::WHITE_KING_PNG, chessGUI::ColorType::WHITE, chessGUI::PieceType::KING);
    pieces[chessGUI::ColorType::WHITE][chessGUI::PieceType::ROOK] = std::make_unique<chessGUI::PieceRender>(window, chessGUI::WHITE_ROOK_PNG, chessGUI::ColorType::WHITE, chessGUI::PieceType::ROOK);
    pieces[chessGUI::ColorType::WHITE][chessGUI::PieceType::BISHOP] = std::make_unique<chessGUI::PieceRender>(window, chessGUI::WHITE_BISHOP_PNG, chessGUI::ColorType::WHITE, chessGUI::PieceType::BISHOP);
    pieces[chessGUI::ColorType::WHITE][chessGUI::PieceType::KNIGHT] = std::make_unique<chessGUI::PieceRender>(window, chessGUI::WHITE_KNIGHT_PNG, chessGUI::ColorType::WHITE, chessGUI::PieceType::KNIGHT);
    pieces[chessGUI::ColorType::WHITE][chessGUI::PieceType::PAWN] = std::make_unique<chessGUI::PieceRender>(window, chessGUI::WHITE_PAWN_PNG, chessGUI::ColorType::WHITE, chessGUI::PieceType::PAWN);
    
    // For Black
    pieces[chessGUI::ColorType::BLACK][chessGUI::PieceType::QUEEN] = std::make_unique<chessGUI::PieceRender>(window, chessGUI::BLACK_QUEEN_PNG, chessGUI::ColorType::BLACK, chessGUI::PieceType::QUEEN);
    pieces[chessGUI::ColorType::BLACK][chessGUI::PieceType::KING] = std::make_unique<chessGUI::PieceRender>(window, chessGUI::BLACK_KING_PNG, chessGUI::ColorType::BLACK, chessGUI::PieceType::KING);
    pieces[chessGUI::ColorType::BLACK][chessGUI::PieceType::ROOK] = std::make_unique<chessGUI::PieceRender>(window, chessGUI::BLACK_ROOK_PNG, chessGUI::ColorType::BLACK, chessGUI::PieceType::ROOK);
    pieces[chessGUI::ColorType::BLACK][chessGUI::PieceType::BISHOP] = std::make_unique<chessGUI::PieceRender>(window, chessGUI::BLACK_BISHOP_PNG, chessGUI::ColorType::BLACK, chessGUI::PieceType::BISHOP);
    pieces[chessGUI::ColorType::BLACK][chessGUI::PieceType::KNIGHT] = std::make_unique<chessGUI::PieceRender>(window, chessGUI::BLACK_KNIGHT_PNG, chessGUI::ColorType::BLACK, chessGUI::PieceType::KNIGHT);
    pieces[chessGUI::ColorType::BLACK][chessGUI::PieceType::PAWN] = std::make_unique<chessGUI::PieceRender>(window, chessGUI::BLACK_PAWN_PNG, chessGUI::ColorType::BLACK, chessGUI::PieceType::PAWN);

    SDL_Event event;
    SDL_Rect dst;
    window.clear();
    window.renderBoard();

    //Rendering black pieces
    //Rooks
    for(int file = 1; file<=8; file+=7)
    {
        SDL_Rect dst = {
            chessGUI::CENTER_X + (file-1)*chessGUI::CELL_PIXEL,
            chessGUI::CENTER_Y + (1-1)*chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL
        };
        window.render(pieces[chessGUI::ColorType::BLACK][chessGUI::PieceType::ROOK]->getTexture(), NULL, &dst);
    }

    // black bishops
    for(int file = 3; file<=6; file+=3)
    {
        SDL_Rect dst = {
            chessGUI::CENTER_X + (file-1)*chessGUI::CELL_PIXEL,
            chessGUI::CENTER_Y + (1-1)*chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL
        };
        window.render(pieces[chessGUI::ColorType::BLACK][chessGUI::PieceType::BISHOP]->getTexture(), NULL, &dst);
    }

    // black Knights
    for(int file = 2; file<=7; file+=5)
    {
        SDL_Rect dst = {
            chessGUI::CENTER_X + (file-1)*chessGUI::CELL_PIXEL,
            chessGUI::CENTER_Y + (1-1)*chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL
        };
        window.render(pieces[chessGUI::ColorType::BLACK][chessGUI::PieceType::KNIGHT]->getTexture(), NULL, &dst);
    }

    SDL_Rect dstQueen = {
        chessGUI::CENTER_X + (4-1)*chessGUI::CELL_PIXEL,
        chessGUI::CENTER_Y + (1-1)*chessGUI::CELL_PIXEL,
        chessGUI::CELL_PIXEL,
        chessGUI::CELL_PIXEL
    };
    window.render(pieces[chessGUI::ColorType::BLACK][chessGUI::PieceType::QUEEN]->getTexture(), NULL, &dstQueen);
    SDL_Rect dstKing = {
        chessGUI::CENTER_X + (5-1)*chessGUI::CELL_PIXEL,
        chessGUI::CENTER_Y + (1-1)*chessGUI::CELL_PIXEL,
        chessGUI::CELL_PIXEL,
        chessGUI::CELL_PIXEL
    };
    window.render(pieces[chessGUI::ColorType::BLACK][chessGUI::PieceType::KING]->getTexture(), NULL, &dstKing);

    // rendering black pawn
    for(int file = 1; file<=8; file++)
    {
        SDL_Rect dst = {
            chessGUI::CENTER_X + (file-1)*chessGUI::CELL_PIXEL,
            chessGUI::CENTER_Y + (2-1)*chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL
        };
        window.render(pieces[chessGUI::ColorType::BLACK][chessGUI::PieceType::PAWN]->getTexture(), NULL, &dst);
    }


    //Rendering White pieces
    //Rooks
    for(int file = 1; file<=8; file+=7)
    {
        SDL_Rect dst = {
            chessGUI::CENTER_X + (file-1)*chessGUI::CELL_PIXEL,
            chessGUI::CENTER_Y + (8-1)*chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL
        };
        window.render(pieces[chessGUI::ColorType::WHITE][chessGUI::PieceType::ROOK]->getTexture(), NULL, &dst);
    }

    // White bishops
    for(int file = 3; file<=6; file+=3)
    {
        SDL_Rect dst = {
            chessGUI::CENTER_X + (file-1)*chessGUI::CELL_PIXEL,
            chessGUI::CENTER_Y + (8-1)*chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL
        };
        window.render(pieces[chessGUI::ColorType::WHITE][chessGUI::PieceType::BISHOP]->getTexture(), NULL, &dst);
    }

    // white Knights
    for(int file = 2; file<=7; file+=5)
    {
        SDL_Rect dst = {
            chessGUI::CENTER_X + (file-1)*chessGUI::CELL_PIXEL,
            chessGUI::CENTER_Y + (8-1)*chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL
        };
        window.render(pieces[chessGUI::ColorType::WHITE][chessGUI::PieceType::KNIGHT]->getTexture(), NULL, &dst);
    }

    SDL_Rect dstQueenW = {
        chessGUI::CENTER_X + (4-1)*chessGUI::CELL_PIXEL,
        chessGUI::CENTER_Y + (8-1)*chessGUI::CELL_PIXEL,
        chessGUI::CELL_PIXEL,
        chessGUI::CELL_PIXEL
    };
    window.render(pieces[chessGUI::ColorType::WHITE][chessGUI::PieceType::QUEEN]->getTexture(), NULL, &dstQueenW);
    SDL_Rect dstKingW = {
        chessGUI::CENTER_X + (5-1)*chessGUI::CELL_PIXEL,
        chessGUI::CENTER_Y + (8-1)*chessGUI::CELL_PIXEL,
        chessGUI::CELL_PIXEL,
        chessGUI::CELL_PIXEL
    };
    window.render(pieces[chessGUI::ColorType::WHITE][chessGUI::PieceType::KING]->getTexture(), NULL, &dstKingW);

    // rendering white pawn
    for(int file = 1; file<=8; file++)
    {
        SDL_Rect dst = {
            chessGUI::CENTER_X + (file-1)*chessGUI::CELL_PIXEL,
            chessGUI::CENTER_Y + (7-1)*chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL,
            chessGUI::CELL_PIXEL
        };
        window.render(pieces[chessGUI::ColorType::WHITE][chessGUI::PieceType::PAWN]->getTexture(), NULL, &dst);
    }
    
    window.display();

    while(gameRunning)
    {
        while(SDL_WaitEvent((&event)))
        {
            if(event.type == SDL_QUIT)
            {
                gameRunning = false;
                break;
            }
        }
    }
    SDL_Quit();
    return 0;
}