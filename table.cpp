#include "Table.hpp"
#include <random>

Table::Table(size_t width, size_t height, int val)
    : width_(width), height_(height) {
    table_.resize(height_, row_t(width_, val));
}


// WRITE THE DEFINITION FOR Table::PrintTable
void Table::PrintTable(std::ostream& out) const {
    for (const auto& row : table_) {
        for (int val : row) {
            out << val << ", ";
        }
        out << std::endl;
    }
}

// WRITE THE DEFINITION FOR Table::FillRandom
void Table::FillRandom(int low, int high, int seed) {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dist(low, high);

    for (auto& row : table_) {
        std::generate(row.begin(), row.end(), [&]() { return dist(gen); });
    }
}

// WRITE THE DEFINITION FOR Table::SetValue
bool Table::SetValue(size_t col, size_t row, int val) {
    if (row >= height_ || col >= width_) {
        return false;
    }
    table_[row][col] = val;
    return true;
}

// WRITE THE DEFINITION FOR Table::GetValue
int Table::GetValue(size_t col, size_t row) const {
    if (row >= height_ || col >= width_) {
        throw std::out_of_range("Index out of range");
    }
    return table_[row][col];
}
