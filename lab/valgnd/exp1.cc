int main() {
    [[maybe_unused]] char *x = new char[100];
    delete[] x; 
    return 0;
}
