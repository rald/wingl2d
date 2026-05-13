game.exe: main.c gl2d.c
	gcc main.c gl2d.c -o game.exe -I. -L. -lglfw -lopengl32 -lgdi32 -lm

.PHONY: clean

clean:
	del game.exe
