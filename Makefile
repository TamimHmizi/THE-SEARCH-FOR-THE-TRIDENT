prog:enigmealeatoiresansfichier.o main.o
	gcc enigmealeatoiresansfichier.o main.o -o prog -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g 
enigmealeatoiresansfichier.o:enigmealeatoiresansfichier.c
	gcc -c enigmealeatoiresansfichier.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
