
#include "gtest/gtest.h"
#include "gtest/internal/gtest-filepath.h"

#include <fstlib/fstcore/interface/fststore.h>
#include <fstlib/fstcore/interface/fstdefines.h>
#include <fstlib/fsttable.h>
#include <fstlib/IntegerMethods.h>

#include "testhelpers.h"
#include "ReadWriteTester.h"


#ifdef _OPENMP
#include <omp.h>
#endif

using namespace testing::internal;

class PreviousVersionTest : public ::testing::Test
{
protected:
	FilePath testDataDir;
	std::string filePath;

	virtual void SetUp()
	{
		filePath = GetFilePath("previousversion.fst");
	}
};


TEST_F(PreviousVersionTest, SmallVec)
{
	FstStore fstStore(filePath);

	ColumnFactory columnFactory;
	std::vector<int> keyIndex;
	StringArray selectedCols;
	FstTable tableRead;

	int result = 0;

	try
	{
		fstStore.fstRead(tableRead, nullptr, 1, -1, &columnFactory, keyIndex, &selectedCols);
	}
	catch (std::runtime_error& e)
	{
		int res = std::strcmp(e.what(), FSTERROR_NON_FST_FILE);

		EXPECT_EQ(res, 0);
	}
}

