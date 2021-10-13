clang++  duplicated.cpp -o dup
clang++  original.cpp -o origin
echo "duplicated:" ; time ./dup > duplicated
echo "\noriginal:" ; time ./origin > Original
diff Duplicated Original
rm -rf duplicated dup 
rm -rf original origin