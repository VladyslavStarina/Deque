#include "integer_deque.hpp"
#include "test.hpp"

void test1(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 2, 10);
	assert(IntegerDequeIsEmpty(_directory));

	IntegerDequeDirectoryDestroy(_directory);
}

void test2(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 6, 15);
	assert(IntegerDequeIsEmpty(_directory));
	assert(_directory.m_backBlockIndex == (_directory.m_directorySize / 2));
	assert(_directory.m_frontBlockIndex == (_directory.m_directorySize / 2) - 1);

	IntegerDequeDirectoryDestroy(_directory);
}

void test3(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 6, 15);
	assert(IntegerDequeIsEmpty(_directory));

	IntegerDequePushFront(_directory, 10);
	assert(!IntegerDequeIsEmpty(_directory));
	assert(IntegerDequeFront(_directory) == 10);
	assert(_directory.m_frontUsed == 1);

	IntegerDequeDirectoryDestroy(_directory);
}

void test4(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 6, 10);
	assert(IntegerDequeIsEmpty(_directory));

	for (int i = 0; i < 10; i++)
	{
		assert(_directory.m_frontUsed == i);
		IntegerDequePushFront(_directory, i);
		assert(IntegerDequeFront(_directory) == i);
		assert(!IntegerDequeIsEmpty(_directory));
	}

	IntegerDequeDirectoryDestroy(_directory);
}

void test5(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 4, 10);
	assert(IntegerDequeIsEmpty(_directory));
	assert(_directory.m_frontBlockIndex != 0);

	for (int i = 0; i < 15; i++)
	{
		IntegerDequePushFront(_directory, i);
		assert(IntegerDequeFront(_directory) == i);
		assert(!IntegerDequeIsEmpty(_directory));

	}
	assert(_directory.m_frontBlockIndex == 0);
	IntegerDequeDirectoryDestroy(_directory);
}

void test6(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 4, 10);
	assert(IntegerDequeIsEmpty(_directory));

	for (int i = 0; i < 50; i++)
	{
		IntegerDequePushFront(_directory, i);
		assert(IntegerDequeFront(_directory) == i);
		assert(!IntegerDequeIsEmpty(_directory));
	}
	assert(_directory.m_directorySize > 4);

	IntegerDequeDirectoryDestroy(_directory);
}

void test7(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 4, 10);
	assert(IntegerDequeIsEmpty(_directory));
	assert(_directory.m_frontBlockIndex != 0);


	for (int i = 0; i < 15; i++)
	{
		IntegerDequePushFront(_directory, i);
		assert(IntegerDequeFront(_directory) == i);
		assert(!IntegerDequeIsEmpty(_directory));
	}

	assert(_directory.m_frontBlockIndex == 0);

	for (int i = 0; i < 15; i++)
	{
		IntegerDequePopFront(_directory);
	}
	assert(IntegerDequeIsEmpty(_directory));
	assert(_directory.m_frontBlockIndex != 0);
	IntegerDequeDirectoryDestroy(_directory);
}

void test8(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 4, 10);
	assert(IntegerDequeIsEmpty(_directory));
	assert(_directory.m_frontBlockIndex != 0);


	for (int i = 0; i < 15; i++)
	{
		IntegerDequePushFront(_directory, i);
		assert(IntegerDequeFront(_directory) == i);
		assert(!IntegerDequeIsEmpty(_directory));
	}

	assert(_directory.m_frontBlockIndex == 0);
	
	IntegerDequeDirectoryClear(_directory);
	assert(IntegerDequeIsEmpty(_directory));
	assert(_directory.m_frontBlockIndex != 0);

	IntegerDequeDirectoryDestroy(_directory);
}

void test9(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 6, 15);
	assert(IntegerDequeIsEmpty(_directory));

	IntegerDequePushBack(_directory, 10);
	assert(!IntegerDequeIsEmpty(_directory));
	assert(IntegerDequeBack(_directory) == 10);
	assert(_directory.m_backUsed == 1);

	IntegerDequeDirectoryDestroy(_directory);
}

void test10(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 6, 10);
	assert(IntegerDequeIsEmpty(_directory));

	for (int i = 0; i < 10; i++)
	{
		assert(_directory.m_backUsed == i);
		IntegerDequePushBack(_directory, i);
		assert(IntegerDequeBack(_directory) == i);
		assert(!IntegerDequeIsEmpty(_directory));
	}

	IntegerDequeDirectoryDestroy(_directory);
}

void test11(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 4, 10);
	assert(IntegerDequeIsEmpty(_directory));
	assert(_directory.m_backBlockIndex != 0);

	for (int i = 0; i < 15; i++)
	{
		IntegerDequePushBack(_directory, i);
		assert(IntegerDequeBack(_directory) == i);
		assert(!IntegerDequeIsEmpty(_directory));
	}
	
	IntegerDequeDirectoryDestroy(_directory);
}

void test12(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 4, 10);
	assert(IntegerDequeIsEmpty(_directory));

	for (int i = 0; i < 50; i++)
	{
		IntegerDequePushBack(_directory, i);
		assert(IntegerDequeBack(_directory) == i);
		assert(!IntegerDequeIsEmpty(_directory));
	}
	assert(_directory.m_directorySize > 4);

	IntegerDequeDirectoryDestroy(_directory);
}

void test13(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 4, 10);
	assert(IntegerDequeIsEmpty(_directory));
	assert(_directory.m_backBlockIndex != 0);

	for (int i = 0; i < 15; i++)
	{
		IntegerDequePushBack(_directory, i);
		assert(IntegerDequeBack(_directory) == i);
		assert(!IntegerDequeIsEmpty(_directory));
	}

	for (int i = 0; i < 15; i++)
	{
		IntegerDequePopBack(_directory);
	}
	assert(IntegerDequeIsEmpty(_directory));
	assert(_directory.m_backBlockIndex != 0);

	IntegerDequeDirectoryDestroy(_directory);
}

void test14(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 4, 10);
	assert(IntegerDequeIsEmpty(_directory));
	assert(_directory.m_backBlockIndex != 0);

	for (int i = 0; i < 15; i++)
	{
		IntegerDequePushBack(_directory, i);
		assert(IntegerDequeBack(_directory) == i);
		assert(!IntegerDequeIsEmpty(_directory));
	}

	IntegerDequeDirectoryClear(_directory);
	assert(IntegerDequeIsEmpty(_directory));
	assert(_directory.m_backBlockIndex != 0);

	IntegerDequeDirectoryDestroy(_directory);
}

void test15(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 2, 10);
	assert(IntegerDequeIsEmpty(_directory));

	for (int i = 0; i < 15; i++)
	{
		IntegerDequePushBack(_directory, i);
		assert(IntegerDequeBack(_directory) == i);
		assert(!IntegerDequeIsEmpty(_directory));
	}

	for (int i = 0; i < 15; i++)
	{
		IntegerDequePopFront(_directory);
	}
	
	assert(IntegerDequeIsEmpty(_directory));

	IntegerDequeDirectoryDestroy(_directory);
}

void test16(IntegerDeque & _directory)
{
	IntegerDequeDirectoryCreate(_directory, 2, 10);
	assert(IntegerDequeIsEmpty(_directory));

	for (int i = 0; i < 15; i++)
	{
		IntegerDequePushFront(_directory, i);
		assert(IntegerDequeFront(_directory) == i);
		assert(!IntegerDequeIsEmpty(_directory));
	}

	for (int i = 0; i < 15; i++)
	{
		IntegerDequePopBack(_directory);
	}
	assert(IntegerDequeIsEmpty(_directory));

	IntegerDequeDirectoryDestroy(_directory);
}
