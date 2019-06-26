#ifndef _INTEGER_DEQUE_HPP_
#define _INTEGER_DEQUE_HPP_

#include <iostream>
#include <cassert>

struct IntegerDeque
{
	int m_directorySize;

	int m_blockSize;

	int ** m_pDirectory;

	int m_frontBlockIndex, m_backBlockIndex;

	int m_frontUsed, m_backUsed;
};

void IntegerDequeDirectoryCreate(IntegerDeque & _directory, int m_directorySize, int m_blockSize);
void IntegerDequeDirectoryDestroy(IntegerDeque & _directory);
void IntegerDequeDirectoryClear(IntegerDeque & _directory);
bool IntegerDequeIsEmpty(const IntegerDeque & _directory);
void IntegerDequePushFront(IntegerDeque & _directory, int _data);
void IntegerDequePopFront(IntegerDeque & _directory);
void IntegerDequePushBack(IntegerDeque & _directory, int _data);
void IntegerDequePopBack(IntegerDeque & _directory);
int IntegerDequeFront(const IntegerDeque & _directory);
int IntegerDequeBack(const IntegerDeque & _directory);

void GrowthDeque(IntegerDeque & _directory);
int frontIndex(const IntegerDeque & _directory);
int backIndex(const IntegerDeque & _directory);
void changeFrontBlockIndexByPush(IntegerDeque & _directory);
void changeBackBlockIndexByPush(IntegerDeque & _directory);
void changeFrontBlockIndexByPop(IntegerDeque & _directory);
void changeBackBlockIndexByPop(IntegerDeque & _directory);
void allocateMemoryByFrontBlock(IntegerDeque & _directory);
void allocateMemoryByBackBlock(IntegerDeque & _directory);
void IntegerDequePrint(IntegerDeque & _directory);

#endif
