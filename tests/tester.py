import os
import subprocess
import glob

def run_tests():
    base_dir = os.path.dirname(os.path.abspath(__file__))
    testcases_dir = os.path.join(base_dir, "testcases")
    testcase_files_in = os.path.join(testcases_dir, "*.in")
    exe_path = os.path.join(base_dir, "../bin", "robot_draw.exe")

    # Get all the testcases
    list_of_files = glob.glob(testcase_files_in)
    # Sort the files so that they are in order, 1.in, 2.in, 3.in, ...
    list_of_files.sort(key=lambda x: int(os.path.basename(x).split(".")[0]))
    
    for in_file in list_of_files:
        out_file = in_file.replace(".in", ".out")
        print("Running test: " + in_file)
        
        # Run the program and get the output from stdout
        actual_output = subprocess.run([exe_path, in_file], stdout=subprocess.PIPE, text=True).stdout

        with open(out_file, "r") as f:
            expected_output = f.read()

        # Process output line-by-line to avoid whitespace issues
        expected_lines = [line.strip() for line in expected_output.strip().splitlines()]
        actual_lines = [line.strip() for line in actual_output.strip().splitlines()]
        
        # Compare the expected output with the actual output
        if expected_lines == actual_lines:
            print("Test passed")
        else:
            print("Test failed")

            print("Expected:")
            print(expected_output)
            print("Actual:")
            print(actual_output)

            # Show pos line, cell where the output differs
            # for i, (expected, actual) in enumerate(zip(expected_lines, actual_lines)):
            #     if expected != actual:
            #         for j, (exp_char, act_char) in enumerate(zip(expected, actual)):
            #             if exp_char != act_char:
            #                 print(f"Line {i+1}, char {j+1}: Expected '{exp_char}', got '{act_char}'")
        print()

        # break

if __name__ == "__main__":
    run_tests()
