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