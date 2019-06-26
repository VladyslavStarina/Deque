#include "integer_deque.hpp"

void IntegerDequeDirectoryCreate(IntegerDeque & _directory,int m_directorySize, int m_blockSize)
{
	_directory.m_directorySize = m_directorySize;
	_directory.m_blockSize = m_blockSize;
	_directory.m_pDirectory = new int *[_directory.m_directorySize];

	for (int i = 0; i < _directory.m_directorySize; i++)
	{
		_directory.m_pDirectory[i] = new int[_directory.m_blockSize];
	}

	_directory.m_backBlockIndex = (_directory.m_directorySize / 2);
	_directory.m_frontBlockIndex = (_directory.m_directorySize/2) - 1;			
	_directory.m_backUsed = 0;
	_directory.m_frontUsed = 0;
}

bool IntegerDequeIsEmpty(const IntegerDeque & _directory)	
{
	return
		((_directory.m_backUsed == _directory.m_frontUsed)
			&& (_directory.m_frontUsed == 0)
			&& (_directory.m_backBlockIndex == _directory.m_frontBlockIndex + 1))
		|| ((_directory.m_backBlockIndex == _directory.m_frontBlockIndex)
			&& ((_directory.m_backUsed + _directory.m_frontUsed) == _directory.m_blockSize));
}

void IntegerDequePushFront(IntegerDeque & _directory, int _data)
{	
	changeFrontBlockIndexByPush(_directory);
	GrowthDeque(_directory);
	allocateMemoryByFrontBlock(_directory);

	_directory.m_frontUsed++;
	_directory.m_pDirectory[_directory.m_frontBlockIndex][frontIndex(_directory)] = _data;
}

void IntegerDequePushBack(IntegerDeque & _directory, int _data)
{
	changeBackBlockIndexByPush(_directory);
	GrowthDeque(_directory);
	allocateMemoryByBackBlock(_directory);

	_directory.m_backUsed++;
	_directory.m_pDirectory[_directory.m_backBlockIndex][backIndex(_directory)] = _data;
}

void IntegerDequePopFront(IntegerDeque & _directory)
{
	if(!IntegerDequeIsEmpty(_directory))
	{
		changeFrontBlockIndexByPop(_directory);
		_directory.m_frontUsed--;
	}
}

void IntegerDequePopBack(IntegerDeque & _directory)
{
	if (!IntegerDequeIsEmpty(_directory))
	{
		changeBackBlockIndexByPop(_directory);
		_directory.m_backUsed--;
	}
}

int IntegerDequeFront(const IntegerDeque & _directory)
{
	return _directory.m_pDirectory[_directory.m_frontBlockIndex][frontIndex(_directory)];
}

int IntegerDequeBack(const IntegerDeque & _directory)
{
	return _directory.m_pDirectory[_directory.m_backBlockIndex][backIndex(_directory)];
}

void IntegerDequeDirectoryClear(IntegerDeque & _directory)
{
	_directory.m_frontBlockIndex = (_directory.m_directorySize / 2) - 1;
	_directory.m_backBlockIndex = (_directory.m_directorySize / 2);
	_directory.m_backUsed = 0;
	_directory.m_frontUsed = 0;
}

void IntegerDequeDirectoryDestroy(IntegerDeque & _directory)
{
	for (int i = 0; i < _directory.m_directorySize; i++)
	{
		delete[] _directory.m_pDirectory[i];
	}
	delete[] _directory.m_pDirectory;
}

int frontIndex(const IntegerDeque & _directory)
{
	int index = _directory.m_blockSize;
	index -= _directory.m_frontUsed;

	return index;
}

int backIndex(const IntegerDeque & _directory)
{
	int index = 0;
	index += (_directory.m_backUsed - 1);

	return index;
}

void GrowthDeque(IntegerDeque & _directory)
{
	if (_directory.m_frontBlockIndex < 0 || _directory.m_backBlockIndex > _directory.m_directorySize - 1)
	{
		int m_directorySizeNew = _directory.m_directorySize * 2;
		int ** pNewData = new int*[m_directorySizeNew];

		for (int i = 0; i < _directory.m_directorySize; i++)
		{
			pNewData[i + _directory.m_directorySize / 2] = _directory.m_pDirectory[i];
		}

		for (int i = 0; i < (_directory.m_directorySize / 2); i++)
		{
			pNewData[i] = nullptr;
			pNewData[m_directorySizeNew - (_directory.m_directorySize / 2) + i] = nullptr;
		}
	
		delete[] _directory.m_pDirectory;

		_directory.m_backBlockIndex += (_directory.m_directorySize / 2);
		_directory.m_frontBlockIndex += (_directory.m_directorySize / 2);

		_directory.m_pDirectory = pNewData;
		_directory.m_directorySize = m_directorySizeNew;
	}
}

void changeFrontBlockIndexByPush(IntegerDeque & _directory)
{
	if (_directory.m_frontUsed == _directory.m_blockSize)
	{
		_directory.m_frontBlockIndex--;
		_directory.m_frontUsed = 0;
	}
}

void changeBackBlockIndexByPush(IntegerDeque & _directory)
{
	if (_directory.m_backUsed == _directory.m_blockSize)
	{
		_directory.m_backBlockIndex++;
		_directory.m_backUsed = 0;
	}
}

void changeFrontBlockIndexByPop(IntegerDeque & _directory)
{
	if (_directory.m_frontUsed == 0)
	{
		_directory.m_frontBlockIndex++;
		_directory.m_frontUsed = _directory.m_blockSize;
	}
}

void changeBackBlockIndexByPop(IntegerDeque & _directory)
{
	if (_directory.m_backUsed == 0)
	{
		_directory.m_backBlockIndex--;
		_directory.m_backUsed = _directory.m_blockSize;
	}
}

void allocateMemoryByFrontBlock(IntegerDeque & _directory)
{
	if (!_directory.m_pDirectory[_directory.m_frontBlockIndex])
	{
		_directory.m_pDirectory[_directory.m_frontBlockIndex] = new int[_directory.m_blockSize];
	}
}

void allocateMemoryByBackBlock(IntegerDeque & _directory)
{
	if (_directory.m_pDirectory[_directory.m_backBlockIndex] == nullptr)
	{
		_directory.m_pDirectory[_directory.m_backBlockIndex] = new int[_directory.m_blockSize];
	}
}

void IntegerDequePrint(IntegerDeque & _directory)
{
	std::cout << "\nOur Queue : ";

	for (int i = _directory.m_blockSize - 1; i >= _directory.m_blockSize - _directory.m_frontUsed; i--)
	{
		std::cout << _directory.m_pDirectory[_directory.m_frontBlockIndex][i] << "  ";
	}

	for (int i = _directory.m_frontBlockIndex + 1; i < _directory.m_backBlockIndex ; i++)
	{
		for (int j = 0; j < _directory.m_blockSize; j++)
		{
			std::cout << _directory.m_pDirectory[i][j] << "  ";
		}	
	}

	for (int i = 0; i < _directory.m_backUsed; i++)
	{
		std::cout << _directory.m_pDirectory[_directory.m_backBlockIndex][i] << "  ";
	}

	std::cout << "\n\n";
}

