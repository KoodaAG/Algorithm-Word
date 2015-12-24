#include <iostream>
#include <map>
#include <string>
#include <Windows.h>
#include <thread>

void setup(std::map<std::string, int>& searchedWords)
{
	searchedWords.insert({ "Der", 10 });
	searchedWords.insert({ "Die", 10 });
	searchedWords.insert({ "Das", 10 });
	searchedWords.insert({ "Auto", 1 });
	searchedWords.insert({ "Fisch", 1 });
}

// Suche nach passendem Wort und drucke dieses
// Standartmäßig sind die Artikel das gesuchte Wort
void printInfoWord(const std::string& word, std::map<std::string, int>& searchedWords)
{
	// speicher das wort und die wahrscheinlichkeit das dieses wort gemeint ist
	// 0 = unwahrscheinlich
	// 1 = wahrscheinlich
	static std::map<std::string, int> searchWord;
	for(auto c : word)
	{
		for (auto s : searchedWords)
			for (auto sc : s.first)
				if (sc == c)
					searchWord.insert({ s.first, +1 });
	}

	std::cout << "Eingegebenes Wort: " << word << std::endl;
	std::cout << "Meinen Sie: ";
	for (auto w : searchWord)
		std::cout << w.first << ";";

	std::cout << std::endl;
}

void addWordToList(const std::string& word, std::map<std::string, int>& searchedWords)
{
	searchedWords.insert({ word, +1 });
}

void removeLastWord(std::string& w)
{
	w.at(w.length() - 1) = '\0';
}

int main()
{
	std::map<std::string, int> searchedWords;
	setup(searchedWords);
	std::string word = "";	

	char c;
	while (true)
	{
		std::cout << "->";
		c = static_cast<char>(std::getchar());
		word += c;

		if (c == '\n') {
			addWordToList(word, searchedWords);
			word = "";
		}
		else if (c == '\b')
			removeLastWord(word);
			
		system("cls");
		printInfoWord(word, searchedWords);
		Sleep(200);
		
	}

	return 0;
}



