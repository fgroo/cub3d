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

WARNING: `mlx_put_pixel()` and `mlx_resize_image` from the MLX42 library
are **forbidden** functions!
