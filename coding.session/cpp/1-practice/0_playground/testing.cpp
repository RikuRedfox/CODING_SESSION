class Year_2023 {
private:
  int doCode;

public:
  Year_2023() {}
  Year_2023(int *&doCode) { this->doCode; }
};

int main() { Year_2023 *year2023 = new Year_2023; }