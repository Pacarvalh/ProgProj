
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void InitEverything(int, int, TTF_Font**, SDL_Surface* [], SDL_Window** , SDL_Renderer** );
void InitSDL();
void InitFont();
SDL_Window* CreateWindow(int, int );
SDL_Renderer* CreateRenderer(int , int , SDL_Window *);
int RenderLogo(int, int, SDL_Surface *, SDL_Renderer **);


#define MAX(a,b)    (((a)>(b))?(a):(b))
#define M_PI 3.14159265
#define STRING_SIZE 100       // max size for some strings
#define TABLE_SIZE 1200       // main game space size
#define LEFT_BAR_SIZE 150     // left white bar size
#define WINDOW_POSX 200       // initial position of the window: x
#define WINDOW_POSY 200       // initial position of the window: y
#define SQUARE_SEPARATOR 8    // square separator in px
#define BOARD_SIZE_PER 0.7f   // board size in % wrt to table size
#define MAX_BOARD_POS 15      // maximum size of the board
#define MAX_COLORS 5
#define MARGIN 4



void main(int argc, char *argv[])
{
        int i=0, a, b, c, d;
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;
        TTF_Font *serif = NULL;
        SDL_Surface *imgs[1];
        SDL_Event event;
        int delay = 300;
        int quit = 0;
        int width = (TABLE_SIZE + LEFT_BAR_SIZE);
        int height = TABLE_SIZE;

        for(i=0;i<argc; i++)
        {
            if(strcmp(argv[i], "-f1")==0)
                a=i+1;

            if(strcmp(argv[i], "-f2")==0)
                b=i+1;

            if(strcmp(argv[i],"-t")==0)
                c=i;

            if (strcmp(argv[i], "-g")==0)
                d=1;

            if(c==1 && d==1)
            {
                printf("Não é possivel abrir o modo textual e gráfico ao mesmo tempo");
                exit(EXIT_FAILURE);
            }

        }

        if(d==1)
        {
            InitEverything(800, 400, &serif,&imgs, &window,&renderer);
            while( quit == 0 )
            {
                // while there's events to handle
                while( SDL_PollEvent( &event ) )
                {
                    if( event.type == SDL_QUIT )
                    {
                        quit = 1;
                    }
                    else if ( event.type == SDL_KEYDOWN )
                    {
                        switch ( event.key.keysym.sym )
                        {
                            case SDLK_n:
                                // todo
                            case SDLK_q:
                                quit=1;
                                // todo
                            case SDLK_u:
                                // todo
                            default:
                                break;
                        }
                    }
                    RenderLogo(100, 100, &imgs , &renderer);
                    // render in the screen all changes above
                    SDL_RenderPresent(renderer);
                    // add a delay
                    SDL_Delay( delay );
                    }
                }

        }

            TTF_CloseFont(serif);
            SDL_FreeSurface(imgs);

            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return EXIT_SUCCESS;

   

}
/**
 * InitEverything: Initializes the SDL2 library and all graphical components: font, window, renderer
 * \param width width in px of the window
 * \param height height in px of the window
 * \param _font font that will be used to render the text
 * \param _imgs[1] surface to be created with the table background and IST logo
 * \param _window represents the window of the application
 * \param _renderer renderer to handle all rendering in a window
 */
void InitEverything(int width, int height, TTF_Font **_font, SDL_Surface* _imgs[], SDL_Window **_window, SDL_Renderer** _renderer)
{
    InitSDL();
    InitFont();
    *_window = CreateWindow(width, height);
    *_renderer = CreateRenderer(width, height, *_window);

    // load the table texture
    _imgs[0] = IMG_Load("mundo.jpg");
    if (_imgs[0] == NULL)
    {
        printf("Unable to load image: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }


}

/**
 * InitSDL: Initializes the SDL2 graphic library
 */
void InitSDL()
{
    // init SDL library
    if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        printf(" Failed to initialize SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

/**
 * InitFont: Initializes the SDL2_ttf font library
 */
void InitFont()
{
    // Init font library
    if(TTF_Init()==-1)
    {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
}

/**
 * CreateWindow: Creates a window for the application
 * \param width width in px of the window
 * \param height height in px of the window
 * \return pointer to the window created
 */
SDL_Window* CreateWindow(int width, int height)
{
    SDL_Window *window;
    // init window
    window = SDL_CreateWindow( "warmingUp", WINDOW_POSX, WINDOW_POSY, width, height, 0 );
    // check for error !
    if ( window == NULL )
    {
        printf("Failed to create window : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return window;
}

/**
 * CreateRenderer: Creates a renderer for the application
 * \param width width in px of the window
 * \param height height in px of the window
 * \param _window represents the window for which the renderer is associated
 * \return pointer to the renderer created
 */
SDL_Renderer* CreateRenderer(int width, int height, SDL_Window *_window)
{
    SDL_Renderer *renderer;
    // init renderer
    renderer = SDL_CreateRenderer( _window, -1, 0 );

    if ( renderer == NULL )
    {
        printf("Failed to create renderer : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // set size of renderer to the same as window
    SDL_RenderSetLogicalSize( renderer, width, height );

    return renderer;
}


int RenderLogo(int x, int y, SDL_Surface *_logoIST, SDL_Renderer** _renderer)
{
    SDL_Texture *text_IST;
    SDL_Rect boardPos;

    // space occupied by the logo
    boardPos.x = x;
    boardPos.y = y;
    boardPos.w = _logoIST->w;
    boardPos.h = _logoIST->h;

    // render it
    text_IST = SDL_CreateTextureFromSurface(_renderer, _logoIST);
    SDL_RenderCopy(_renderer, text_IST, NULL, &boardPos);

    // destroy associated texture !
    SDL_DestroyTexture(text_IST);
    return _logoIST->h;
}
