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

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_fetch_texture_file_should_return_file_name);
	return UNITY_END();
}
