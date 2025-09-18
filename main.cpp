/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timatias <timatias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 23:56:30 by timatias          #+#    #+#             */
/*   Updated: 2025/09/19 00:54:18 by timatias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

std::string ajudaDeus(std::string input)
{
    std::string resultado;

    for (char ch : input)
    {
        if (std::isalnum(static_cast<unsigned char> (ch)) ||  std::isspace(static_cast<unsigned>(ch)))
            resultado += std::tolower(static_cast<unsigned char>(ch));
    }
    return (resultado);
}

int main(int argc, char **argv)
{
    std::string text;
    if (argc < 2) {
        std::string oss;
        std::cout << "Digite o texto (finalize com Ctrl+D):\n";
        std::cin >> oss;
        text = oss;
    } else {
        std::ifstream file(argv[1]);
        if (file) {
            std::string oss;
            file >> oss;
            text = oss;
        } else {
            for (int i = 1; i < argc; ++i) {
                text += argv[i];
                if (i < argc - 1) text += " ";
            }
        }
    }
    text = ajudaDeus(text);
    std::istringstream iss(text);
    std::map<std::string, int> freq;
    std::string word;
    while (iss >> word) {
        ++freq[word];
    }
    std::vector<std::pair<std::string, int>> freq_vec(freq.begin(), freq.end());
    std::sort(freq_vec.begin(), freq_vec.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    for (const auto& p : freq_vec) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
    return 0;
}
