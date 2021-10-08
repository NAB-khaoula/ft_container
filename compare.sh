clang++ -Wall -Wextra -Werror duplicated.cpp -o duplicated
clang++ -Wall -Wextra -Werror original.cpp -o original
echo ./duplicated > Duplicated
echo ./original > Original
diff Duplicated Original