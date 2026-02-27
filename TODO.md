# **Test cases to implement in the [[unit tester]]:**
		- ### Parsing
			- > If any misconfiguration of any kind is encountered in the file, the program
			  must exit properly and **return "Error\\n" followed by an explicit error message
			  of your choice.**
			- [ ] program only takes `.cub` file as argument
			- [ ] file permissions of `.cub` file
			- [ ] opening the `.cub` file
			- [ ] invalid texture file
			- [ ] texture file not found
			- [ ] invalid format
				- _"make sure to have the exact identifiers (**NO, SO, WE, EA, F, C**) in the correct order"_
			- [ ] RGB format of values is invalid:
				- `F 220,100`
				- `F 220,100,0,1`
				- `F a,220,0`
				- `F 220, 100, 0`
			- [ ] RGB values of floor[**F**] and cealing[**C**] are invalid
				- `F -1,100,0`
				- `F 220,100,420`
			- [ ] map walls are not properly closed
			- [ ] invalid characters in map (spaces are allowed)
				- valid characters include: `" ", "0", "1", "N", "S", "E", "W"`
			- [ ] only one Player position(N, S, E, W) can exist in a given map

	- **Example `.cub` file:**
		- ```txt
		  NO ./path_to_the_north_texture
		  SO ./path_to_the_south_texture
		  WE ./path_to_the_west_texture
		  EA ./path_to_the_east_texture

		  F 220,100,0
		  C 225,30,0

		          1111111111111111111111111
		          1000000000110000000000001
		          1011000001110000000000001
		          1001000000000000000000001
		  111111111011000001110000000000001
		  100000000011000001110111111111111
		  11110111111111011100000010001
		  11110111111111011101010010001
		  11000000110101011100000010001
		  10000000000000001100000010001
		  10000000000000001101010010001
		  11000001110101011111011110N0111
		  11110111 1110101 101111010001
		  11111111 1111111 111111111111
		  ```
