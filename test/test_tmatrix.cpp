#include "utmatrix.h"

#include "gtest.h"

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(3));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-3));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(3);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = 1;
		}
	}
	TMatrix<int> m2(m1);
	EXPECT_EQ(m2, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m1(3);


	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 3; j++)
			m1[i][j] = 1;
	}
	TMatrix<int> m2(m1);
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 3; j++)
			m2[i][j] = 2;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = i; j < 3; j++)
			EXPECT_NE(m1[i][j], m2[i][j]);
	}
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m1(3);

	EXPECT_EQ(3, m1.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(3);
	m[1][1] = 3;

	EXPECT_EQ(3, m[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(3);

	ASSERT_ANY_THROW(m[-1][1] = 0);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(3);

	ASSERT_ANY_THROW(m[4][4] = 0);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(3);
	m[1][2] = 3;
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m1(3);
	m1[1][2] = 3;
	TMatrix<int> m2(3);

	ASSERT_NO_THROW(m1 = m2);
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(3);
	m1[1][2] = 3;
	TMatrix<int> m2(6);

	m2 = m1;

	EXPECT_EQ(3, m2.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m1(3);
	m1[1][2] = 3;
	TMatrix<int> m2(6);

	ASSERT_NO_THROW(m2 = m1);
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(3);
	m1[1][2] = 3;
	TMatrix<int> m2(m1);
	m2[1][2] = 3;

	EXPECT_EQ(true, m2 == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m1(3);
	m1[1][2] = 3;

	EXPECT_EQ(true, m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(3);
	m1[1][2] = 3;
	TMatrix<int> m2(6);
	m2[1][2] = 3;

	EXPECT_EQ(false, m2 == m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	TMatrix<int> res(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = 3;
			m2[i][j] = 3;
			res[i][j] = 6;
		}
	}

	ASSERT_NO_THROW(m1 + m2);
	EXPECT_EQ(m1 + m2, res);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(6);

	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	TMatrix<int> res(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = 6;
			m2[i][j] = 3;
			res[i][j] = 3;
		}
	}

	ASSERT_NO_THROW(m1 - m2);
	EXPECT_EQ(m1 - m2, res);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(6);

	ASSERT_ANY_THROW(m1 - m2);
}