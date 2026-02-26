#include "unity.h"
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>

void setUp(void) {}
void tearDown(void) {}

void test_fetch_texture_file_should_return_file_name(void)
{
	// Example: testcase[n] = { parameter1, parameter2, expected }
	char **testcase[] = {
		(char*[]){ "NO ./texture-file", "NO", "./texture-file" },
		(char*[]){ "NO\t\v\r ./texture-file", "NO", "./texture-file" },
		(char*[]){ "N ./texture-file", "NO", NULL },
		(char*[]){ "./texture-file", "NO", NULL },
		(char*[]){ "NO ./texture-file  ", "NO", "./texture-file" },
		(char*[]){ "NO ./texture-file  a", "NO", NULL },
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


void test_fetch_color(void)
{
	// cases
	// F 11a, 1, 1
	// F 11a   ,1, 1
	// F 11   a,1, 1
	// F 11,1,1a
	// F a, 1, 1
	char **testcase[] = {
		(char*[]){ "F 255,255,255", "F" },
		(char*[]){ "F     255  , 255, 255   ", "F" },
		(char*[]){ "F a,255,255", "F" },
		(char*[]){ "F 255a,255,255", "F" },
		(char*[]){ "F 255a   ,255,255", "F" },
		(char*[]){ "F 255   a,255,255", "F" },
		(char*[]){ "F 255,255,255a", "F" },
		(char*[]){ "F 255,255,255    a", "F" },
		NULL,
	};
	int solution[] = {
		0xFFFFFF,
		0xFFFFFF,
		-1,
		-1,
		-1,
		-1,
		-1,
		-1,
	};
	for (int i = 0; testcase[i]; i++) {
		int color = fetch_color(testcase[i][0], testcase[i][1]);
		printf("TEST %d: \"%s\"\n", i + 1, testcase[i][0]);
		printf("\texpected: 0x%x\n\tactual: 0x%x\n\n", solution[i], color);
		TEST_ASSERT_EQUAL_INT(solution[i], color);
	}
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_fetch_texture_file_should_return_file_name);
	RUN_TEST(test_fetch_color);
	return UNITY_END();
}
