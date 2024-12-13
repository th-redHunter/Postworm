# #include <cstdlib>

## ONLY RUN
const char* script = "touch nigga"; // Path to your script
int ret = system(script); // Executes the script
if (ret == 0) {
 std::cout << "Script executed successfully.\n";
} else {
 std::cerr << "Error executing script. Return code: " << ret << '\n';
}
return ret;
---

## RUN AND GET RESULTS
const char* script = "touch nigga; echo fuck-you >> nigga";
FILE* pipe = popen(script, "r"); // Open pipe to run the script
if (!pipe) {
 std::cerr << "Failed to run script.\n";
 return 1;
}

char buffer[128];
std::string result;
while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
 result += buffer;
}
pclose(pipe); // Close the pipe

std::cout << "Script output:\n" << result;
return 0;
---

## 