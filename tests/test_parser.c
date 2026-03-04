#include "unity.h"
#include "parser.h"
#include "get_next_line.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_malloc_lite.h"

void setUp(void) {}
void tearDown(void) {}

void TEST_fetch_texture_file(void)
{
	// Example: testcase[n] = { parameter1, parameter2, expected }
	char **testcase[] = {
		(char*[]){ "NO ./texture-file", "NO", "./texture-file" },
		(char*[]){ "NO\t\v\r ./texture-file", "NO", "./texture-file" },
		(char*[]){ "N ./texture-file", "NO", NULL },
		(char*[]){ "./texture-file", "NO", NULL },
		(char*[]){ "NO ./texture-file  ", "NO", "./texture-file" },
		(char*[]){ "NO ./texture-file  a", "NO", NULL },

		(char*[]){ "NO ./texture-file\n", "NO", "./texture-file" },
		(char*[]){ "NO\t\v\r ./texture-file\n", "NO", "./texture-file" },
		(char*[]){ "N ./texture-file\n", "NO", NULL },
		(char*[]){ "./texture-file\n", "NO", NULL },
		(char*[]){ "NO ./texture-file  \n", "NO", "./texture-file" },
		(char*[]){ "NO ./texture-file  a\n", "NO", NULL },
		NULL,
	};

	for (int i = 0; testcase[i]; i++) {
		char *s = fetch_texture_file(testcase[i][0], testcase[i][1]);
		printf("TEST %d: \"%s\"\n", i + 1, testcase[i][0]);
		printf("\texpected: %s$\n\tactual: %s$\n\n", testcase[i][2], s);
		TEST_ASSERT_EQUAL_STRING(testcase[i][2], s);
		free(s);
	}
}

void TEST_to_hex_color(void)
{
	typedef struct s_testcase {
		long r;
		long g;
		long b;
		int expected;
	} t_testcase;

	t_testcase testcase[] = {
		{ 255, 10, 5, 0xFF0A05 },
		{ -100, 10, 5, -1 },
		{ 0, 10, 256, -1 },
		{ 255, LONG_MAX, 5, -1 },
		{ 255, LONG_MIN, 5, -1 },
		{ 0, 0, 0, 0x000000 },
	};

	int num_testcase = sizeof(testcase) / sizeof(testcase[0]);
	for (int i = 0; i < num_testcase; i++) {
		int color = to_hex_color(testcase[i].r, testcase[i].g, testcase[i].b);
		printf("TEST %d: R = %d G = %ld B = %d\n", i + 1, testcase[i].r, testcase[i].g, testcase[i].b);
		printf("\texpected: 0x%x\n\tactual: 0x%x\n\n", testcase[i].expected, color);
		TEST_ASSERT_EQUAL_INT(testcase[i].expected, color);
	}
}

void TEST_fetch_color(void)
{
	// cases
	// F 11a, 1, 1
	// F 11a   ,1, 1
// F 11   a,1, 1
	// F 11,1,1a
	// F a, 1, 1
	typedef struct s_testcase {
		char *input_str;
		char *identifier;
		int expected;
	} t_testcase;

	t_testcase testcase[] = {
		{ "F 255,255,255", "F", 0xFFFFFF },
		{ "F     255  , 255, 255   ", "F", 0xFFFFFF },
		{ "F a,255,255", "F", -1 },
		{ "F 255a,255,255", "F", -1 },
		{ "F 255a   ,255,255", "F", -1 },
		{ "F 255   a,255,255", "F", -1 },
		{ "F 255,255,255a", "F", -1 },
		{ "F 255,255,255    a", "F", -1 },

		{ "F 255,255,255\n", "F", 0xFFFFFF },
		{ "F     255  , 255, 255   \n", "F", 0xFFFFFF },
		{ "F a,255,255\n", "F", -1 },
		{ "F 255a,255,255\n", "F", -1 },
		{ "F 255a   ,255,255\n", "F", -1 },
		{ "F 255   a,255,255\n", "F", -1 },
		{ "F 255,255,255a\n", "F", -1 },
		{ "F 255,255,255    a\n", "F", -1 },

		{ "F 255,-9223372036854775808,255\n", "F", -1 },
		{ "F 255,9223372036854775807,255\n", "F", -1 },
		{ "F 255,,255\n", "F", -1 },
		{ "F 255,255,255,255", "F", -1 },
	};

	int num_testcase = sizeof(testcase) / sizeof(testcase[0]);
	for (int i = 0; i < num_testcase; i++) {
		int color = fetch_color(testcase[i].input_str, testcase[i].identifier);
		printf("TEST %d: \"%s\"\n", i + 1, testcase[i].input_str);
		printf("\texpected: 0x%x\n\tactual: 0x%x\n\n", testcase[i].expected, color);
		TEST_ASSERT_EQUAL_INT(testcase[i].expected, color);
	}
}

void	TEST_map_validation(void)
{
	typedef struct s_testcase
	{
		char	*input;
		int		returnvalue;
		char	**expected;
	}			t_testcase;

	t_testcase testcase[] =
	{
		{
			"maps/debug/leaking-map1.cub", 0, (char *[]){
				"        1111111111110111111111111\n",
				"        1000000000110000000000001\n",
				"        1011000001110000000000001\n",
				"        1001000000000000000000001\n",
				"111111111011000001110000000000001\n",
				"100000000011000001110111110111111\n",
				"11110111111111011100000010001\n",
				"11110111111111011101010010001\n",
				"11000000110101011100000010001\n",
				"10000000000000001100000010001\n",
				"10000000000000001101010010001\n",
				"11000001110101011111011110N0111\n",
				"11110111 1110101 101111010001\n",
				"11111111 1111111 111111111111",
				NULL
			}
		},
		{
			"maps/debug/two-maps-with-spawn.cub", 0, (char *[]){
				"        1111111111111111111111111\n",
				"        1000000000110000000000001\n",
				"        1011000001110000000000001\n",
				"        1001000000000000N00000001\n",
				"111111111011000001110000000000001\n",
				"100000000011000001110111111111111\n",
				"111111111111111111\n",
				NULL
			}
		},
		{
			"maps/debug/two-maps.cub", 1, NULL
		},
		{
			"maps/debug/newline-between-map.cub", 1, NULL
		},
		{
			"maps/debug/missing-map.cub", 1, NULL
		}
	};

	typedef struct s_mapdata
	{
		char	*tex[4];
		int		floor_color;
		int		ceiling_color;
		char	**map;
	}	t_mapdata;


	t_mapdata	map = {0}; // [] for more testcases

	int	i = 0;
	int	fd = 0;

	int num_maps = sizeof(testcase) / sizeof(testcase[0]);

	while (i < num_maps) // loop through all testcases
	{
		map.map = NULL;
		fd = open(testcase[i].input, O_RDONLY);
		TEST_ASSERT_NOT_EQUAL_MESSAGE(-1, fd, "Could not open map file");
		for (int skip = 0; skip < 8; skip++)
		{
            char *line;
			line = get_next_line(fd);
            free(line);
        }
		TEST_ASSERT_EQUAL_INT(testcase[i].returnvalue, validate_map(fd, &map.map));
		int j = 0;
		if (testcase[i].returnvalue == 0 && map.map != NULL) {
			while (testcase[i].expected[j] != NULL && map.map[j] != NULL)
			{
				TEST_ASSERT_EQUAL_STRING(testcase[i].expected[j], map.map[j]);
				++j;
			}
			TEST_ASSERT_NULL(testcase[i].expected[j]);
			TEST_ASSERT_NULL(map.map[j]);
		}
		
		// Map needs to be freed to avoid leaky tests!
		if (map.map) {
			if (testcase[i].returnvalue == 0) { // Only NULL-terminated if successful
				for (int k = 0; map.map[k] != NULL; k++)
					free(map.map[k]);
			}
			ft_free(map.map);
		}

		close(fd);
		++i;
	}
}

// WARN: This test case doesn't work properly, whenever parser() closes an fd.
//		 get_next_line will keep reading the next line from fd = 3 even though,
//		 the open file has already changed!
//		 If parser() doesnt close the fds however, the testcases can be tested
//		 correctly with the caviat of having unclosed fds.
void TEST_parser(void)
{
	typedef struct s_testcase {
		int expected;
		char *file;
	} t_testcase;

	t_testcase testcase[] = {
		{ 0, "./maps/example.cub" },

		{ 1, "./maps/debug/non-existing-file.cub" },
		{ 1, "./maps/debug/is-directory" },
		{ 1, "./maps/debug/is-directory.cub/" },
		{ 1, "./maps/debug/no-file-extension" },
		{ 1, "./maps/debug/wrong-file-extension.ber" },
		{ 0, "./maps/debug/wrong-file-extension.cub.cub" }, //not sure how to handle
		{ 0, "./maps/debug/.cub" }, // not sure how to handle

		{ 1, "./maps/debug/invalid-order.cub" },
		{ 1, "./maps/debug/invalid-texture-order.cub" },
		{ 1, "./maps/debug/invalid-color-order.cub" },

		{ 1, "./maps/debug/leaking-map1.cub"},
		{ 1, "./maps/debug/leaking-map2.cub"},
		{ 1, "./maps/debug/leaking-map3.cub"},
		{ 1, "./maps/debug/leaking-map4.cub"},

		{ 0, "./maps/debug/random-newlines.cub" },
		{ 0, "./maps/debug/always-newlines.cub" },
		{ 0, "./maps/debug/no-newlines.cub" },

		{ 1, "./maps/debug/missing-texture1.cub" },
		{ 1, "./maps/debug/missing-texture2.cub" },
		{ 1, "./maps/debug/missing-texture3.cub" },
		{ 1, "./maps/debug/missing-texture4.cub" },
		{ 1, "./maps/debug/missing-color1.cub" },
		{ 1, "./maps/debug/missing-color2.cub" },
		// { 1, "./maps/debug/missing-map.cub" },

		// { 1, "./maps/debug/newline-between-map.cub" },
		// { 0, "./maps/debug/two-maps.cub" }, //not sure how to handle

		// { 1, "" }, //if main handles it, then this test is allowed to fail
		// { 1, NULL }, //if main handles it, then this test is allowed to fail
	};

	t_mapdata map = {
		.tex[0] = NULL,
		.tex[1] = NULL,
		.tex[2] = NULL,
		.tex[3] = NULL,
		.map = NULL,
	};

	int num_testcase = sizeof(testcase) / sizeof(testcase[0]);
	for (int i = 0; i < num_testcase; i++) {
		int ret = parser(&map, testcase[i].file);
		printf("TEST %d: \"%s\"\n", i + 1, testcase[i].file);
		printf("\texpected: %d\n\tactual: %d\n\n", testcase[i].expected, ret);
		TEST_ASSERT_EQUAL_INT(testcase[i].expected, ret);
		if (ret == 0) {
			printf("\t\tNORTH TEXTURE: %s\n", map.tex[0]);
			printf("\t\tSOUTH TEXTURE: %s\n", map.tex[1]);
			printf("\t\tWEST TEXTURE: %s\n", map.tex[2]);
			printf("\t\tEAST TEXTURE: %s\n", map.tex[3]);
			printf("\t\tFLOOR COLOR: 0x%x\n", map.floor_color);
			printf("\t\tCEILING COLOR: 0x%x\n", map.ceiling_color);
		}
		free(map.tex[0]);
		map.tex[0] = NULL;
		free(map.tex[1]);
		map.tex[1] = NULL;
		free(map.tex[2]);
		map.tex[2] = NULL;
		free(map.tex[3]);
		map.tex[3] = NULL;
		free(map.map); // WARN: use correct map free later!
		map.map = NULL;
	}
}

int main(void)
{
	UNITY_BEGIN();
	// RUN_TEST(TEST_fetch_texture_file);
	// RUN_TEST(TEST_to_hex_color);
	// RUN_TEST(TEST_fetch_color);
	RUN_TEST(TEST_map_validation);
	return UNITY_END();
}
