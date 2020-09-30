for (auto x : v) {
    if (!first) {
      std::cout << ", ";
      }
    std::cout << x;
    first = false;
    }
  std::cout << "]";
  std::cout << std::endl;
}

int main() {
 //std::vector<std::string> v;

 //  v = {"emma", "dora", "ruth", "ziegellaub", "eichler"};
 // std::cout << "Case 1: ";
 // MergeSort(v);
 // print(v);

  std::vector<int> v {22,4,66,19,430,77};
  InsertionSort(v);
  std::cout<<v[0]<<'\n';
  std::cout << "Expected: [dora, eichler, emma, ruth, ziegellaub]" << std::endl;
} 