#include "htab.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_test_ctx
{
	int	total;
	int	failed;
	int	current_failed;
}	t_test_ctx;

static t_test_ctx	g_test;
static int			g_deleted;

static void	test_begin(const char *name)
{
	g_test.current_failed = 0;
	printf("\n[TEST] %s\n", name);
}

static void	test_end(void)
{
	if (!g_test.current_failed)
		printf("  OK\n");
}

static void	expect_true(int condition, const char *message)
{
	g_test.total++;
	if (condition)
		return ;
	g_test.failed++;
	g_test.current_failed++;
	printf("  FAIL: %s\n", message);
}

static int	*new_int(int value)
{
	int	*data;

	data = malloc(sizeof(int));
	if (!data)
		return (NULL);
	*data = value;
	return (data);
}

static void	delete_int(void *data)
{
	g_deleted++;
	free(data);
}

static void	test_new_case(void)
{
	t_htab	*htab;

	test_begin("htab_new");
	expect_true(htab_new(0) == NULL, "zero buckets fails");
	htab = htab_new(8);
	expect_true(htab != NULL, "returns allocated table");
	expect_true(htab_size(htab) == 0, "size initialized to 0");
	expect_true(htab_bucket_count(htab) == 8, "bucket count initialized");
	expect_true(htab_load_factor(htab) == 0.0, "load factor initialized");
	htab_clear(&htab, delete_int);
	expect_true(htab == NULL, "clear sets table to NULL");
	test_end();
}

static void	test_set_get_case(void)
{
	t_htab	*htab;

	test_begin("htab_set / htab_get");
	htab = htab_new(4);
	expect_true(htab_set(htab, "one", new_int(1), delete_int),
		"set first key succeeds");
	expect_true(htab_set(htab, "two", new_int(2), delete_int),
		"set second key succeeds");
	expect_true(*(int *)htab_get(htab, "one") == 1, "gets first value");
	expect_true(*(int *)htab_get(htab, "two") == 2, "gets second value");
	expect_true(htab_get(htab, "missing") == NULL, "missing key returns NULL");
	expect_true(htab_size(htab) == 2, "size counts entries");
	htab_clear(&htab, delete_int);
	test_end();
}

static void	test_update_case(void)
{
	t_htab	*htab;

	test_begin("htab_set update");
	g_deleted = 0;
	htab = htab_new(4);
	expect_true(htab_set(htab, "same", new_int(1), delete_int),
		"initial set succeeds");
	expect_true(htab_set(htab, "same", new_int(99), delete_int),
		"update succeeds");
	expect_true(htab_size(htab) == 1, "update keeps size stable");
	expect_true(*(int *)htab_get(htab, "same") == 99, "updated value returned");
	expect_true(g_deleted == 1, "old value deleted on update");
	htab_clear(&htab, delete_int);
	test_end();
}

static void	test_collision_case(void)
{
	t_htab	*htab;

	test_begin("collisions");
	htab = htab_new(1);
	expect_true(htab_set(htab, "a", new_int(10), delete_int),
		"set collision bucket first");
	expect_true(htab_set(htab, "b", new_int(20), delete_int),
		"set collision bucket second");
	expect_true(htab_set(htab, "c", new_int(30), delete_int),
		"set collision bucket third");
	expect_true(*(int *)htab_get(htab, "a") == 10, "gets first collision");
	expect_true(*(int *)htab_get(htab, "b") == 20, "gets second collision");
	expect_true(*(int *)htab_get(htab, "c") == 30, "gets third collision");
	expect_true(htab_size(htab) == 3, "size counts collisions");
	htab_clear(&htab, delete_int);
	test_end();
}

static void	test_delete_case(void)
{
	t_htab	*htab;

	test_begin("htab_del");
	g_deleted = 0;
	htab = htab_new(2);
	htab_set(htab, "a", new_int(10), delete_int);
	htab_set(htab, "b", new_int(20), delete_int);
	expect_true(htab_del(htab, "a", delete_int), "delete existing succeeds");
	expect_true(g_deleted == 1, "delete frees value");
	expect_true(htab_get(htab, "a") == NULL, "deleted key is gone");
	expect_true(*(int *)htab_get(htab, "b") == 20, "other key remains");
	expect_true(htab_size(htab) == 1, "size decremented");
	expect_true(!htab_del(htab, "a", delete_int), "delete missing fails");
	htab_clear(&htab, delete_int);
	test_end();
}

int	main(void)
{
	test_new_case();
	test_set_get_case();
	test_update_case();
	test_collision_case();
	test_delete_case();
	printf("\n%d tests, %d failed\n", g_test.total, g_test.failed);
	if (g_test.failed)
		return (1);
	return (0);
}
