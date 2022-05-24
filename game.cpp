#include "game.hpp"
#include "HUMania.hpp"
#include "drawing.hpp"
#include "Score.hpp"
#pragma once

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;

bool Game::init()
{
	//Initialization flag
	bool success = true;


	//Initialize SDL
	if( SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) < 0)
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Fruit Ninja", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
                {
                    printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
                    success = false;
                }
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;

	string bg_image;
	
	bg_image = "main_screen.png";
	Drawing::assets = loadTexture("assets.png");
    gTexture = loadTexture(bg_image);
	if(Drawing::assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	gMusic = Mix_LoadMUS("bg_music.mp3");
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	Mix_FreeMusic(gMusic);
    gMusic = NULL;
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void Game::run( )
{
	bool quit = false;
	string bg_select;

	SDL_Event e;
	Mix_PlayMusic(gMusic, -2);
	const int initialScore = 0;
	const int initialHealth = 3;
	Score totalScore(initialScore);
	Health health(initialHealth);

	HUMania board(Drawing::gRenderer, Drawing::assets, totalScore, health);

	while( !quit )
	{
		int MouseX, MouseY, X, Y;
		bool textureLoad = false;
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			if(screen == 0 & e.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&X, &Y);
				cout<<X<<" "<<Y<<endl;
				if((Y >= 20 && Y <= 78) && (X >= 335 && X <= 690)) {
					gTexture = loadTexture("bgSelector.png"); screen = 3;
				}

				else if ((Y >= 30 && Y <= 78) && (X >= 710 && X <= 959)) {
					gTexture = loadTexture("Instructions.png"); screen = 2;
				}

				else if ((Y >= 364 && Y <= 492) && (X >= 33 && X <= 229)) {
					gTexture = loadTexture("board.png"); screen = 1;
				}

			}

			if (screen == 2 & e.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&X, &Y);
				if (X >= 900 && X <= 1000 && Y >= 50 && Y <= 124)
                    {
                        gTexture = loadTexture("main_screen.png");
                        screen = 0;
                    }
			}

			if (screen == 3 & e.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&MouseX, &MouseY);
				//cout<<MouseX<<"  "<<MouseY<<endl;
				if ((MouseX >= 94 && MouseX <= 457) && (MouseY >= 207 && MouseY <= 449)) {
					gTexture = loadTexture("board2.png"); screen = 1;
				}

				if ((MouseX >= 527 && MouseX <= 914) && (MouseY >= 207 && MouseY <= 449)) {
					gTexture = loadTexture("board.png"); screen = 1;
				}
			}
			if(screen == 1 & e.type == SDL_MOUSEMOTION){

				SDL_GetMouseState(&MouseX, &MouseY);
                board.controlGameplay(MouseX, MouseY);
			}

		}
		if (screen == 1) {
		board.createObject();
		}
		
		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer
		//***********************draw the objects here********************
		if (screen == 1) {
		board.drawObjects();
		board.displayScore();
		board.displayHealth();
		if (board.if_health_left()) {
			screen = 4;
			gTexture = loadTexture("GameOver.png");
		}
		}
		
		

		//****************************************************************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}
