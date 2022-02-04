clang++  -Wall -Wextra -Werror -std=c++98 ./Tester/duplicated.cpp -o dup
clang++  -Wall -Wextra -Werror -std=c++98 ./Tester/original.cpp -o origin
echo "duplicated:" ; time ./dup > duplicated
echo "\noriginal:" ; time ./origin > Original
diff Duplicated Original
rm -rf duplicated dup 
rm -rf original origin