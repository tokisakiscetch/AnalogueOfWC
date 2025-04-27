#include <iostream>
#include <vector>
#include <string>

int main()
{
	const std::string exceptions{ " +-!?.,;:_" };
	std::string text;
	std::vector<std::string> words;

	std::cout << "Enter text -> ";
	std::getline(std::cin, text);
	
	size_t start{ text.find_first_not_of(exceptions) };
	while (start != std::string::npos)
	{
		size_t end{ text.find_first_of(exceptions, start + 1) };
		if (end == std::string::npos)
		{
			end = text.length();
		}
		words.push_back(text.substr(start, end - start));
		start = text.find_first_not_of(exceptions, end + 1);
	}
	std::cout << "The text contains -> " << words.size() << " words (-v-)\n";
	for (const auto& word : words)
	{
		std::cout << "<" << word << ">" << std::endl;
	}
}