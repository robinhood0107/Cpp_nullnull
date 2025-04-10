int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <expected_output_file>\n";
        return 1;
    }

    std::string input_filename = argv[1];
    std::string output_filename = argv[2];

    std::ifstream input_file(input_filename);
    std::ifstream output_file(output_filename);

    if (!input_file.is_open() || !output_file.is_open()) {
        std::cerr << "Error: Could not open input or expected output file.\n";
        return 1;
    }

    std::string input_content((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
    std::string expected_content((std::istreambuf_iterator<char>(output_file)), std::istreambuf_iterator<char>());

    input_file.close();
    output_file.close();

    std_newline(input_content);
    std_newline(expected_content);

    std::string diff_result = diff_output(expected_content, input_content);
    std::cout << diff_result;

    return 0;
}
