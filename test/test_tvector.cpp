#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<double> v(10);
	v[0] = 0; v[1] = 1; v[2] = 2; v[3] = 3; v[4] = 4; v[5] = 5; v[6] = 6.66; v[7] = 97.3; v[8] = 0.2; v[9] = 3.1416;
	TVector<double> v1(v);
	EXPECT_EQ(v, v1);
	//ADD_FAILURE();
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	//œ≈–≈ƒ≈À¿“‹, Õ”∆ÕŒ «¿Õ”À»“‹ ›À≈Ã≈Õ“ ¬ ŒƒÕŒÃ, ¿ ¬ ƒ–”√ŒÃ Œ—“¿¬»“‹, —–¿¬Õ»“‹ »’ » ŒÕ» ƒŒÀ∆Õ€ ¡€“‹ Õ≈ –¿¬Õ€, —À≈ƒŒ¬¿“≈À‹ÕŒ ”  ¿∆ƒŒ√Œ —¬Œﬂ œ¿Ãﬂ“‹
	TVector<double> v(1);
	v[0] = 20;
	TVector<double> v1(v);
	EXPECT_NE(&v1, &v);
  //ADD_FAILURE();
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[-1]);
  //ADD_FAILURE();
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[MAX_VECTOR_SIZE+1]);
  //ADD_FAILURE();
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);
	ASSERT_NO_THROW(v = v);
  //ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<double> v(3);
	v[0] = 0.3; v[1] = 2.3; v[2] = 4.3;
	TVector<double> vs(3);
	vs[0] = 30; v[1] = 20; v[2] = 25.5;
	v = vs;
	EXPECT_EQ(vs, v);
  //ADD_FAILURE();
}

TEST(TVector, assign_operator_change_vector_size)
{ //
	TVector<double> vs(3);
	vs[0] = 0.3; vs[1] = 2.3; vs[2] = 4.3;
	TVector<double> v(10);
	v[0] = 0; v[1] = 1; v[2] = 2; v[3] = 3; v[4] = 4; v[5] = 5; v[6] = 6.66; v[7] = 97.3; v[8] = 0.2; v[9] = 3.1416;
	vs = v;
	EXPECT_EQ(10, vs.GetSize());
  //ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<double> vs(3);
	vs[0] = 0.3; vs[1] = 2.3; vs[2] = 4.3;
	TVector<double> v(10);
	v[0] = 0; v[1] = 1; v[2] = 2; v[3] = 3; v[4] = 4; v[5] = 5; v[6] = 6.66; v[7] = 97.3; v[8] = 0.2; v[9] = 3.1416;
	vs = v;
	EXPECT_EQ(v, vs);
  //ADD_FAILURE();
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<double> v(3);
	v[0] = 0.3; v[1] = 2.3; v[2] = 4.3;
	TVector<double> vcopy(v);
	EXPECT_EQ(v, vcopy);
  //ADD_FAILURE();
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<double> v(3);
	v[0] = 0.3; v[1] = 2.3; v[2] = 4.3;
	EXPECT_EQ(1, v == v);
  //ADD_FAILURE();
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<double> v1(3);
	TVector<double> v2(4);
	EXPECT_EQ(0, v1 == v2);
  //ADD_FAILURE();
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<double> v(3);
	v[0] = 0.3; v[1] = 2.3; v[2] = 4.3;
	double alpha = 1;
	TVector<double> res(3);
	res[0] = 1.3; res[1] = 3.3; res[2] = 5.3;
	v = v + alpha;
	EXPECT_EQ(res, v);
  //ADD_FAILURE();
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	//œ–Œ¡À≈Ã€ — ¬≈Ÿ≈—“¬≈ÕÕ€Ã» (‚ÔÓ˜ÂÏ, ÌË˜Â„Ó ÌÓ‚Ó„Ó)
	TVector<int> v(3);
	v[0] = 1; v[1] = 2; v[2] = 4;
	int alpha = 1;
	TVector<int> res(3);
	res[0] = 0; res[1] = 1; res[2] = 3;
	v = v - alpha;
	EXPECT_EQ(res, v);
  //ADD_FAILURE();
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(3);
	v[0] = 1; v[1] = 2; v[2] = 4;
	int alpha = 4;
	TVector<int> res(3);
	res[0] = 4; res[1] = 8; res[2] = 16;
	v = v * alpha;
	EXPECT_EQ(res, v);
  //ADD_FAILURE();
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 4;
	TVector<int> v2(3);
	v2[0] = 4; v2[1] = 8; v2[2] = 16;
	TVector<int> res(3);
	res[0] = 5; res[1] = 10; res[2] = 20;
	EXPECT_EQ(res, v1 + v2);
  //ADD_FAILURE();
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 4;
	TVector<int> v2(4);
	v2[0] = 4; v2[1] = 8; v2[2] = 16; v2[3] = 0;
	ASSERT_ANY_THROW(v1 + v2);
  //ADD_FAILURE();
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 4;
	TVector<int> v2(3);
	v2[0] = 4; v2[1] = 8; v2[2] = 16;
	TVector<int> res(3);
	res[0] = -3; res[1] = -6; res[2] = -12;
	EXPECT_EQ(res, v1 - v2);
  //ADD_FAILURE();
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 4;
	TVector<int> v2(4);
	v2[0] = 4; v2[1] = 8; v2[2] = 16; v2[3] = 0;
	ASSERT_ANY_THROW(v1 - v2);
  //ADD_FAILURE();
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 4;
	TVector<int> v2(3);
	v2[0] = 4; v2[1] = 3; v2[2] = 2;
	int res = 18;
	EXPECT_EQ(res, v1 * v2);
  //ADD_FAILURE();
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(3);
	v1[0] = 1; v1[1] = 2; v1[2] = 4;
	TVector<int> v2(4);
	v2[0] = 4; v2[1] = 8; v2[2] = 16; v2[3] = 0;
	ASSERT_ANY_THROW(v1 * v2);
  //ADD_FAILURE();
}

