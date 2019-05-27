//FileIO.h
#pragma once
#include "IOHandler.h"

class IOHandler;

class FileIO
{
public:
	//Read
	void readLastIdList(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, std::ifstream& file);
	void readUserList(List<User>& userList, std::ifstream& file);
	void readBookList(List<Book>& bookList, std::ifstream& file);
	void readLoanInfoList(List<LoanInfo>& loanInfoList, std::ifstream& file);

	//Create
	void createEmptyFile(const std::string fileDirectory);
	
	//Write
	void writeLastIdList(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, std::ofstream& file);

	template <typename dataType>
	void writeDataList(List<dataType>& dataList, std::ofstream& file);
};

template <typename dataType>
void FileIO::writeDataList(List<dataType>& dataList, std::ofstream& file)
{
	std::string listTitle, dataTypeName = typeid(dataType).name();

	if (dataTypeName == "class User")
		listTitle = "[UserList]";
	else if (dataTypeName == "class Book")
		listTitle = "[BookList]";
	else
		listTitle = "[LoanInfoList]";

	file << listTitle << "\n";
	for (int i = 0; i < dataList.getSize(); i++)
		file << dataList.getData(i)->to_string() << "\n";
	file << "\n";
}