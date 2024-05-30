
#include "../funcs/Header.hpp"
#include <gtest/gtest.h>

TEST(TestCheckFile, not_find) 
{
	std::fstream f1("src/files/test.txt");
	EXPECT_THROW(checkFile(f1), std::ios_base::failure);
}

TEST(TestCheckFile, empty) 
{
	std::fstream f2("src/files/file.txt");
	EXPECT_THROW(checkFile(f2), std::ios_base::failure);
}


TEST(TestCheckNumbers, good) 
{
	std::string word1 = "32";
	EXPECT_EQ(checkNumbers(word1), true);
	std::string word2 = "0";
	EXPECT_EQ(checkNumbers(word2), true);
	std::string word3 = "32905459";
	EXPECT_EQ(checkNumbers(word3), true);
}

TEST(TestCheckNumbers, bad) 
{
	std::string word1 = "f";
	EXPECT_EQ(checkNumbers(word1), false);
	std::string word2 = "421gfd";
	EXPECT_EQ(checkNumbers(word2), false);
	std::string word3 = "3290.5459";
	EXPECT_EQ(checkNumbers(word3), false);
}

TEST(TestCheckSizeForNumbers, good) 
{
	std::string line1{ "vvnufs dn  3 2" };
	std::string delims{ " , '" };
	size_t size = 0;
	EXPECT_EQ(checkSizeForNumbers(line1, delims, size), 2);
}
TEST(TestCheckSizeForNumbers, bad) 
{
	std::string delims{ " , '" };
	size_t size1 = 0;
	std::string line2{ "sdv fsd vw sdd3 ds2v4" };
	EXPECT_THROW(checkSizeForNumbers(line2, delims, size1), std::exception);
}

TEST(TestCreateAllNumbers, good)
{
	std::string line{ "8 vrsni  fi 79" };
	std::string delims{ " ,.;',. " };
	int32_t* arr = new int32_t[10];
	createAllNumbers(line, delims, arr);
	EXPECT_EQ(arr[0] , 8);
	EXPECT_EQ(arr[1], 79);
}

TEST(TestCreateALLNumbersCopy, good)
{

	int32_t* arr = new int32_t[10];
	arr[0] = 3;
	arr[1] = 2;
	arr[2] = 4;
	size_t size = 3;
	int32_t* arrCopy = new int32_t[10];
	createAllNumbersCopy(arr, arrCopy, size);
	EXPECT_EQ(arrCopy[0], 2);
	EXPECT_EQ(arrCopy[1], 4);
	EXPECT_EQ(arrCopy[2], 3);
}

TEST(TestCheckSurname, good)
{
	std::string word{ "Brvfs" };
	EXPECT_EQ(checkSurname(word), true);
}

TEST(TestCheckSurname, bad) {
	std::string word{ "BBjsvdv" };
	std::string word2{ "sddb" };
	EXPECT_EQ(checkSurname(word), false);
	EXPECT_EQ(checkSurname(word2), false);
}

TEST(TestCheckWords, good) 
{
	std::string word1{ "fdbwrv" };
	std::string word2{ "HBJVFS" };
	std::string word3{ "BJsvkd" };
	EXPECT_EQ(checkWords(word1), true);
	EXPECT_EQ(checkWords(word2), true);
	EXPECT_EQ(checkWords(word3), true);
}

TEST(TestCheckWords, bad) 
{
	std::string word1{ "fdb,.rv" };
	std::string word2{ "HBJ4FS" };
	std::string word3{ "BJsvk32d" };
	EXPECT_EQ(checkWords(word1), false);
	EXPECT_EQ(checkWords(word2), false);
	EXPECT_EQ(checkWords(word3), false);
}

TEST(TestCheckSizeText, good) 
{
	std::string line{ "bfbf Gdfbv G43hjhk,." };
	std::string delims{ " ,./" };
	size_t size = 0;
	checkSizeText(line, delims, size);
	EXPECT_EQ(size, 1);
}

TEST(TestCheckSizeTex, bad) 
{
	std::string line1{ "sd sd sGJvbdfd GH,b" };
	std::string delims{ " ,./" };
	size_t size1 = 0;
	checkSizeText(line1, delims, size1);
	EXPECT_EQ(size1, 0);
}

TEST(TestCreateAllSurname, good) 
{
	std::string* allSurname = new std::string[10];
	std::string line{ "Gjfd fbvjdd GHHjfbv 87Ghfv Gh" };
	std::string delims{ " ,..' " };
	createAllSurname(line, delims, allSurname);
	EXPECT_EQ(allSurname[0], "Gjfd");
	EXPECT_EQ(allSurname[1], "Gh");
}

TEST(TestCreateAllSurname, bad) 
{
	std::string* allSurname = new std::string[10];
	std::string line{ "GSjfd fbvjdd GHHjfbv 87Ghfv GhV" };
	std::string delims{ " ,..' " };
	createAllSurname(line, delims, allSurname);
	EXPECT_EQ(allSurname[0], "");
}
TEST(TestInsertionSort, good) 
{
	std::string* arr = new std::string[10];
	arr[0] = "z";
	arr[1] = "d";
	arr[2] = "c";
	arr[3] = "b";
	arr[4] = "a";
	size_t size = 5;
	insertionSort(arr, size);
	EXPECT_EQ(arr[0],"a");
	EXPECT_EQ(arr[1], "b");
	EXPECT_EQ(arr[2], "c");
	EXPECT_EQ(arr[3], "d");
	EXPECT_EQ(arr[4], "z");
 }

TEST(TestInputEmployes, good)
{
	Employee* employes = new Employee[3];
	std::string* allSurname = new std::string[3];
	int32_t* arr = new int32_t[3];
	size_t size = 3;
	allSurname[0] = "Bgd";
	allSurname[1] = "Nds";
	allSurname[2] = "Jsa";
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	inputEmployees(employes, size, allSurname, arr, size);
	EXPECT_EQ(employes[0].surname, "Bgd");
	EXPECT_EQ(employes[0].children, 1);
	EXPECT_EQ(employes[1].surname, "Nds");
	EXPECT_EQ(employes[1].children, 2);
	EXPECT_EQ(employes[2].surname, "Jsa");
	EXPECT_EQ(employes[2].children, 3);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
