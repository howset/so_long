# So Long

- ~~Use the provided minilibx-linux from the intra project page.~~ done
- ~~The makefile will/must be changed to pull minilibx from git (possibly my own repo) to avoid norm errors given by the source files of the minilibx.~~ done
- ~~collect & process assets.~~
- ~~register keypresses.~~
- ~~put pixel to window.~~
- ~~put xpm to window.~~
- combine both in the same window.
- parse args. - just check # of args and file extension
- parse map.- use gnl?

to check:
- https://github.com/PandeoF1/42-so_long - funny so bad
- https://github.com/tnakajo42/so_long - maybe?
- https://github.com/liz753/so_long - useful checklist in readme
- https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx - useful blog
- https://pulgamecanica.herokuapp.com/posts/minilibx-tutorial - useful blog maybe, none of the tutorials work ootb
- https://reactive.so/post/42-a-comprehensive-guide-to-so_long
- https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html
- https://42-cursus.gitbook.io/guide/rank-02/so_long/building-the-thing
- https://github.com/D-Daria/so_long - try to make it work
- https://github.com/zanybeyondart/So_Long - read

# Mandatory

## Shortcuts

- 0 arg
```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long
```

- \>1 arg
```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long assets/maps/valids/map1.ber assets/maps/valids/map4.ber
```

- non-existent arg
```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long nonexistent_file.ber
```

- invalid extension
```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long assets/maps/test/map-invalid-extension
```

-------
- empty file
```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long assets/maps/test/map-empty.ber
```

- small map (row)
```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long assets/maps/test/map-smallrows.ber
```

- small map (col)
```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long assets/maps/test/map-smallcols.ber
```

-------
- everything else. Edit map file on the fly. 
	- Valid elements: 1 P, 1 E, >1 C, other chars.
	- Rectangle
	- Closed by walls
	- Valid path (flood fill)
```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./so_long assets/maps/test/map-valid-to_edit.ber
```

## Notes
- Destroy function to terminate is critical!! Otherwise there are always leaks or errors.
- Mandatory part can accept Enemy Patrol characters if the element is present on map though does not do anything about it.
- Prints movement already on screen instead of on terminal, because it requires only 2 lines of code.
- Exit tile is walkable, just because.
- Ninja adv pack (https://pixel-boy.itch.io/ninja-adventure-asset-pack)
- Sprite cutter (https://ezgif.com/sprite-cutter)
- Upscale pixelart (https://lospec.com/pixel-art-scaler/)
