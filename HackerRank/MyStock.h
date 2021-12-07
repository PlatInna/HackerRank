#pragma once
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<iterator>

class MyStock {
private:
	int m_threshold;
	std::set<std::pair<std::string, std::string>> m_pairs;
	std::map<std::string, float> m_stock;
public:
	MyStock(int threshold);
	void UpdatePrice(const std::string& stockName, float price);
	void RegPair(const std::string& stockOne, const std::string& stockTwo);
	void Print(std::set<std::pair<std::string, std::string>>::iterator i);
};

MyStock::MyStock(int threshold) : m_threshold(threshold) {

}

void MyStock::RegPair(const std::string& stockOne, const std::string& stockTwo) {
	if (stockOne != stockTwo) {
		m_pairs.insert({ stockOne, stockTwo });
		m_pairs.insert({ stockTwo, stockOne });
	}
}

void MyStock::UpdatePrice(const std::string& stockName, float price) {
	m_stock[stockName] = price;
	auto iter = find_if(m_pairs.begin(), m_pairs.end(), [stockName](auto el) {return el.first == stockName; });
	while (iter != m_pairs.end() && iter->first == stockName) {
		if (m_stock.count(iter->second) && std::abs(m_stock[iter->first] - m_stock[iter->second]) > m_threshold) {
			Print(iter);
		}
		iter++;
	}
}

void MyStock::Print(std::set<std::pair<std::string, std::string>>::iterator i) {
	std::cout << "Stock One: " << i->first << ", $" << m_stock[i->first] << '\t'
		      << "Stock Two: " << i->second << ", $" << m_stock[i->second] << '\t'
		      << "Threshold value exceeded by: " << std::abs(m_stock[i->first] - m_stock[i->second])
		      << std::endl;
}