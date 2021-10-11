clang++  duplicated.cpp -o dup
clang++  original.cpp -o origin
time ./dup > duplicated
time ./origin > Original
diff Duplicated Original
rm -rf duplicated dup 
rm -rf original origin