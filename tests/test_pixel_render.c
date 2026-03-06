#include "draw.h"

#include "unity.h"
#include "MLX42.h"
#include <stdio.h>

void setUp(void){}
void tearDown(void){}

void TEST_clamp_vertex_to_img(void)
{
	uint32_t width = 64;
	uint32_t height = 64;

	typedef struct s_testcase {
		t_vertex2i p;
		t_vertex2i expected;
	} t_testcase;

	t_testcase testcase[] = {
		{ (t_vertex2i){0,0}, (t_vertex2i){0,0} },
		{ (t_vertex2i){(int)width - 1, (int)height - 1}, (t_vertex2i){(int)width - 1, (int)height - 1} },

		{ (t_vertex2i){-10, 32}, (t_vertex2i){0, 32} },
		{ (t_vertex2i){10, -32}, (t_vertex2i){10,0} },
		{ (t_vertex2i){-10, -32}, (t_vertex2i){0,0} },
		{ (t_vertex2i){(int)width, (int)height}, (t_vertex2i){(int)width - 1, (int)height - 1} },
		{ (t_vertex2i){(int)width + 1, (int)height + 1}, (t_vertex2i){(int)width - 1, (int)height - 1} },

		{ (t_vertex2i){(int)width, 0}, (t_vertex2i){(int)width - 1, 0} },
		{ (t_vertex2i){(int)width + 1, 0}, (t_vertex2i){(int)width - 1, 0} },

		{ (t_vertex2i){0, (int)height}, (t_vertex2i){0, (int)height - 1} },
		{ (t_vertex2i){0, (int)height + 1}, (t_vertex2i){0, (int)height - 1} },
	};
	int num_testcase = sizeof(testcase) / sizeof(testcase[0]);
	for (int i = 0; i < num_testcase; i++) {
		t_vertex2i actual = clamp_vertex_to_img(testcase[i].p, width, height);
		printf("TEST %d: x = %d, y = %d\n", i + 1, testcase[i].p.x, testcase[i].p.y);
		printf("\texpected:\tx = %d, y = %d\n", testcase[i].expected.x, testcase[i].expected.y);
		printf("\tactual:\t\tx = %d, y = %d\n", actual.x, actual.y);
		TEST_ASSERT_EQUAL_INT(testcase[i].expected.x, actual.x);
		TEST_ASSERT_EQUAL_INT(testcase[i].expected.y, actual.y);
	}
}

int main(void)
{
	UNITY_BEGIN();
	// RUN_TEST(TEST_fetch_texture_file);
	// RUN_TEST(TEST_to_hex_color);
	// RUN_TEST(TEST_fetch_color);
	RUN_TEST(TEST_clamp_vertex_to_img);
	return UNITY_END();
}
