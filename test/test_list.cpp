#include "tlist.h"

#include <gtest.h>



//------ Positive Tests ----------- //

TEST(tlist, can_create_spisok_with_positive_length)
{
	ASSERT_NO_THROW(tlist<int>(5));
}

TEST(tlist, constructor_of_copy)
{
	tlist<int>spisok(5);
	ASSERT_NO_THROW(tlist<int> copy(spisok));
}

TEST(tlist, can_assign_list_with_eqaual_sizes) {
	tlist<int> spisok1(5, 2);
	tlist<int> spisok2(5, 2);
	ASSERT_NO_THROW(spisok2 = spisok1);

}

TEST(tlist, can_assign_other_list_with_dif_sizes) {
	tlist<int> spisok1(5, 2);
	tlist<int> spisok2(3, 2);
	ASSERT_NO_THROW(spisok2 = spisok1);

}

TEST(tlist, can_assign_to_itself) {
	tlist<int>spisok1(3);
	ASSERT_NO_THROW(spisok1 = spisok1);
}


TEST(tlist, can_get_size)
{
	tlist<int> spisok(5);
	EXPECT_EQ(5, spisok.sz());
}

TEST(tlist, can_get_val_from_index) {
	int chek = 8;
	tlist<int> spisok(5);
	spisok.insert_front(8);
	EXPECT_EQ(chek, spisok[0]);
}

TEST(tlist, can_create_list_with_same_values) {
	int chek = 0;
	int flag = 0;
	tlist<int> spisok(5, 4);
	for (int i = 0; i < 5; ++i) {
		if (spisok[i] != 4) flag = 1;
		
	}
	
	EXPECT_EQ(chek, flag);
}


TEST(tlist, equal_size_copy) {
	tlist<int>spisok(5);
	tlist<int> copy(spisok);
	EXPECT_EQ(5, copy.sz());
}


TEST(tlist, equal_values_copy) {
	tlist<int>spisok(5, 2);
	tlist<int>spisok2(spisok);
	bool chek = 1;
	for (int i = 0; i < 5; ++i) {
		if (spisok[i] != spisok2[i]) {
			chek = 0;
			break;
		}

	}
	EXPECT_EQ(1, chek);

}

TEST(tlist, size_after_insert_front) {
	tlist<int> spisok(5, 2);
	spisok.insert_front(4);
	EXPECT_EQ(6, spisok.sz());
}

TEST(tlist, can_insert_front) {
	tlist<int> spisok(5, 2);
	spisok.insert_front(4);
	EXPECT_EQ(4, spisok[0]);
}


TEST(tlist, equal_values_assign) {
	tlist<int> spisok1(5, 4);
	tlist<int> spisok2(3, 3);
	spisok2 = spisok1;
	bool chek = 1;
	for (int i = 0; i < 5; ++i) {
		if (spisok1[i] != spisok2[i]) {
			chek = 0;
			break;
		}
	}
	
	EXPECT_EQ(1, chek);
	

}
TEST(tlist, equal_sizes_after_assign) {
	tlist<int> spisok1(5, 4);
	tlist<int> spisok2(3, 3);
	spisok2 = spisok1;
	EXPECT_EQ(spisok1.sz(), spisok2.sz());

}

TEST(tlist, can_erase_front) {
	tlist<int>spisok(4, 3);
	spisok.insert_front(9);
	spisok.erase_front();
	EXPECT_EQ(3, spisok[0]);
}

TEST(tlist, size_after_erase_front) {
	tlist<int>spisok(4, 3);
	spisok.erase_front();
	EXPECT_EQ(3, spisok.sz());
}

TEST(tlist, find_incomig_value) {
	tlist<int>spisok(2, 3);
	EXPECT_NE(spisok.find(3), nullptr);
}

TEST(tlist, find_not_included_value) {
	tlist<int>spisok(2, 3);
	EXPECT_EQ(spisok.find(10), nullptr);

}

//------ Negative Tests ----------- //


TEST(tlist, throw_negative_length) {
	ASSERT_ANY_THROW(tlist<int>spisok(-65));
}

TEST(tlist, throw_negative_length_same_val) {
	ASSERT_ANY_THROW(tlist<int>spisok(-65, 2));
	
}
TEST(tlist, throw_negative_index) {
	tlist<int> spisok(4, 3);
	ASSERT_ANY_THROW(spisok[-1]);
}

TEST(tlist, throw_index_more_size) {
	tlist<int>spisok(4, 3);
	ASSERT_ANY_THROW(spisok[200]);
}




